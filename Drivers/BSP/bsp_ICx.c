/*
 * File:   bsp_ICx.c
 * Author: gaol
 *
 * Created on 2026年5月21日, 下午7:53
 *
 * 纯硬件适配层：仅 IC 寄存器配置(GPIO/PPS/ICxCON/IEC) + 调试 LED 显示。
 * Hall 解码、hall_status、ISR 回调逻辑已迁至 hall_speed_fdbk.c（单一 owner）。
 * 本文件零 Middlewares 依赖。
 */

#include "bsp_ICx.h"
#include "ic1.h"
#include "ic2.h"
#include "ic3.h"
#include "../../user_manager.h"
#include <stdbool.h>
#include <stdio.h>

/*
 * IC捕捉模块是边沿触发，既只能知道是否发生了边沿跳变事件，
 * 具体是上升沿还是下降沿，需要读取引脚。
 * 输入捕捉对应引脚电平
 * IC1 -> RG8 (Hall U)
 * IC2 -> RG7 (Hall V)
 * IC3 -> RG6 (Hall W)
 */
#define IC1_BIT     _RG8 /*PORTGbits.RG8*/
#define IC2_BIT     _RG7
#define IC3_BIT     _RG6

// 输入捕捉 通道枚举
typedef enum {
    IC1_IDX = 0,
    IC2_IDX = 1,
    IC3_IDX = 2,
    IC_COUNT
} IC_IDX_e;

/* ISR 桥：上层注册的统一处理函数（NULL = 未注册，no-op） */
static volatile BSP_ICx_IsrHandler_t s_isr = NULL;


// 输入捕捉 硬件资源结构体
typedef struct {
    IC_IDX_e idx; // 通道编号
    const char *pin_name; // 引脚名
    volatile uint16_t *tris; // TRIS 寄存器指针
    volatile uint16_t *port; // PORT 寄存器指针
    uint8_t bit_pos; // 引脚位位置
    uint16_t rp_num; // RP/RPI 重映射编号
} IC_ConfigTypeDef;

static const IC_ConfigTypeDef g_IC_Cfg[IC_COUNT] = {
    // IC1：RG8 / RP120
    [IC1_IDX] =
    { .idx = IC1_IDX, .pin_name = "RG8", .tris = &TRISG, .port = &PORTG, .bit_pos = 8, .rp_num = 120,},

    // IC2：RG7 / RPI119
    [IC2_IDX] =
    { .idx = IC2_IDX, .pin_name = "RG7", .tris = &TRISG, .port = &PORTG, .bit_pos = 7, .rp_num = 119,},

    // IC3：RG6 / RP118
    [IC3_IDX] =
    { .idx = IC3_IDX, .pin_name = "RG6", .tris = &TRISG, .port = &PORTG, .bit_pos = 6, .rp_num = 118,}
};

/*
 * 函数：IC_GPIO_ReMap_Init
 * 功能：独立配置输入捕捉引脚 GPIO + 重映射
 * 硬件映射：
 * IC1 <- RP120/RG8
 * IC2 <- RPI119/RG7
 * IC3 <- RP118/RG6
 */
static void ICAP_SECTION IC_GPIO_ReMap_Init(void) {
    uint8_t i;
    const IC_ConfigTypeDef *cfg;

    // 遍历所有通道，统一初始化GPIO
    for (i = 0; i < IC_COUNT; i++) {
        cfg = &g_IC_Cfg[i];

        // 设置为输入模式
        *(cfg->tris) |= (1U << cfg->bit_pos);
    }

    // 解锁重映射寄存器
    __builtin_write_OSCCONL(OSCCON & ~(1 << _OSCCON_IOLOCK_POSITION));

    // 重映射：ICx -> RPn
    RPINR7bits.IC1R = g_IC_Cfg[IC1_IDX].rp_num;
    RPINR7bits.IC2R = g_IC_Cfg[IC2_IDX].rp_num;
    RPINR8bits.IC3R = g_IC_Cfg[IC3_IDX].rp_num;

    // 重映射上锁
    __builtin_write_OSCCONL(OSCCON | (1 << _OSCCON_IOLOCK_POSITION));
}
/*
 * 函数：BSP_ICx_HW_Init
 * 功能：输入捕捉模块硬件初始化（纯寄存器配置）
 * 时基：Timer3
 * 模式：双边沿触发(仅用于中断触发)
 * 作用：电平发生跳变时进入中断(回调逻辑在 hall_speed_fdbk.c)
 */
void ICAP_SECTION BSP_ICx_HW_Init(void) {
    IC_GPIO_ReMap_Init();
    /*  寄存器14-1： ICxCON1：输入捕捉x 控制寄存器1
     * bit 15-14 未实现：读为0
     * bit 13 ICSIDL: 0 = 在CPU 空闲模式下输入捕捉将继续工作
     * bit 12-10 ICTSEL<2:0>：000 = T3CLK 是ICx 的时钟源（默认）
     * bit 9-7 未实现：读为0
     * bit 6-5 ICI<1:0>：00 = 每次捕捉事件产生一次中断
     * bit 4 ICOV:（只读）0 = 未发生输入捕捉缓冲区溢出
     * bit 3 ICBNE:（只读）0 = 输入捕捉缓冲区为空
     * bit 2-0 ICM<2:0>：001 = 捕捉模式，每个边沿（上升沿和下降沿）捕捉一次（边沿检测模式，在该模式下不使用ICI<1:0>）
     */
    /* ICxCON2：输入捕捉x 控制寄存器2
     * bit 15-9 未实现：读为0
     * bit 8 IC32：0 = 禁止级联模块操作
     * bit 7 ICTRIG(unused)：0 = 输入源用于将输入捕捉定时器与另一个模块的定时器同步（同步模式）
     * bit 6 TRIGSTAT(unused)：0 = ICxTMR 未触发并保持清零
     * bit 5 未实现：读为0
     * bit 4-0 SYNCSEL<4:0>：00000 = ICx 无同步或触发源
     */
    /* IC1 配置：ICSIDL disabled; ICM Edge Detect Capture; ICTSEL TMR3; ICI Every;  */
    IC1CON1bits.ICTSEL = 0;
    IC1CON1bits.ICM = 1;
    // SYNCSEL TMR3; TRIGSTAT disabled; IC32 disabled; ICTRIG Sync disabled;
    IC1CON2bits.SYNCSEL = 0;

    /* IC2 配置：双边沿触发 + Timer3时基 */
    IC2CON1bits.ICTSEL = 0;
    IC2CON1bits.ICM = 1;
    IC2CON2bits.SYNCSEL = 0;

    /* IC3 配置：双边沿触发 + Timer3时基 */
    IC3CON1bits.ICTSEL = 0;
    IC3CON1bits.ICM = 1;
    IC3CON2bits.SYNCSEL = 0;

    /* IC1 中断初始化 */
    /* Clear interrupt flag bit */
    _IC1IF = false;
    /* Configure interrupt priority */
    //_IC1IP
    /* Enable interrupt */
    _IC1IE = true;
    /* IC2 中断初始化 */
    _IC2IF = false;
    //_IC2IP
    _IC2IE = true;
    /* IC3 中断初始化 */
    _IC3IF = false;
    //_IC3IP
    _IC3IE = true;
}

/*
 * BSP_ICx_ReadHall
 * 读 3 路 Hall 引脚电平并打包。
 * bit2 = IC1 (RG8) U
 * bit1 = IC2 (RG7) V
 * bit0 = IC3 (RG6) W
 */
uint8_t ICAP_SECTION BSP_ICx_ReadHall(void) {
    return (uint8_t)((IC1_BIT << 2) | (IC2_BIT << 1) | (IC3_BIT << 0));
}

/*
 * BSP_ICx_RegisterIsrHandler
 * 上层（经 mc_services）注册 IC ISR 统一处理函数。
 */
void ICAP_SECTION BSP_ICx_RegisterIsrHandler(BSP_ICx_IsrHandler_t handler) {
    s_isr = handler;
}

/* ================= 捕获 FIFO 调试打印 =================
 * 方案 B：不建软件环形缓冲，只保留“最新一次捕获”快照。
 *
 * dt = 本次捕获值与上一次任意通道捕获值的差值，
 *      对应相邻两个 Hall 跳变，也就是 60° 电角度的时间差。
 *
 * ISR 更新快照并递增 s_seq；主循环发现 s_seq 变化后打印最新值。
 * 主循环来不及打印时，只显示最后一次捕获，不保留历史。
 */
#define BSP_ICX_CAPTURE_DEBUG   1

#if BSP_ICX_CAPTURE_DEBUG

static volatile uint8_t  s_last_ch;
static volatile uint8_t  s_last_first;
static volatile uint8_t  s_last_ovf;
static volatile uint16_t s_last_val;
static volatile uint16_t s_last_dt;
static volatile uint16_t s_seq;

static uint16_t s_prev_val = 0u;
static bool     s_have_prev = false;

static void ICAP_SECTION IC_CaptureStore(uint8_t ch, uint16_t val, bool ovf)
{
    s_last_ch  = ch;
    s_last_val = val;
    s_last_ovf = ovf ? 1u : s_last_ovf;

    if (s_have_prev) {
        s_last_first = 0u;
        s_last_dt = (uint16_t)(val - s_prev_val);
    } else {
        s_last_first = 1u;
        s_last_dt = 0u;
    }

    s_prev_val = val;
    s_have_prev = true;
    s_seq++;
}

static void ICAP_SECTION IC_CaptureDrain(uint8_t idx)
{
    bool ovf;
    uint16_t v;

    switch (idx) {
        case IC1_IDX:
            ovf = IC1_HasCaptureBufferOverflowed();
            while (!IC1_IsCaptureBufferEmpty()) {
                v = IC1_CaptureDataRead();
                IC_CaptureStore(IC1_IDX, v, ovf);
                ovf = false;
            }
            break;

        case IC2_IDX:
            ovf = IC2_HasCaptureBufferOverflowed();
            while (!IC2_IsCaptureBufferEmpty()) {
                v = IC2_CaptureDataRead();
                IC_CaptureStore(IC2_IDX, v, ovf);
                ovf = false;
            }
            break;

        case IC3_IDX:
            ovf = IC3_HasCaptureBufferOverflowed();
            while (!IC3_IsCaptureBufferEmpty()) {
                v = IC3_CaptureDataRead();
                IC_CaptureStore(IC3_IDX, v, ovf);
                ovf = false;
            }
            break;

        default:
            break;
    }
}

#endif /* BSP_ICX_CAPTURE_DEBUG */

/*
 * BSP_ICx_DebugPoll
 * 主循环调用：发现新捕获就打印最新一次快照。
 * 方案 B 不保留历史，主循环来不及打印时只显示最后一次。
 */
void ICAP_SECTION BSP_ICx_DebugPoll(void)
{
#if BSP_ICX_CAPTURE_DEBUG
    static uint16_t s_seen_seq = 0u;
    uint16_t seq = s_seq;
    uint8_t ch;
    uint8_t first;
    uint8_t ovf;
    uint16_t val;
    uint16_t dt;

    if (seq == s_seen_seq) {
        return;
    }
    s_seen_seq = seq;

    ch    = s_last_ch;
    first = s_last_first;
    ovf   = s_last_ovf;
    val   = s_last_val;
    dt    = s_last_dt;
    s_last_ovf = 0u;

    if (first) {
        printf("IC%u v=%u FIRST\r\n",
               (unsigned)(ch + 1u), (unsigned)val);
    } else {
        uint32_t us = ((uint32_t)dt * 3657UL) / 1000UL;
        printf("IC%u v=%u dt=%u us=%lu%s\r\n",
               (unsigned)(ch + 1u), (unsigned)val,
               (unsigned)dt, (unsigned long)us,
               ovf ? " OVF" : "");
    }
#endif
}

/*
 * IC ISR 强覆盖（压制 MCC ic1/2/3.c 中的弱符号）。
 * 三路中断触发同一 handler；未注册时 no-op。
 * 调试开启时，Hall 逻辑后顺手排空对应通道 FIFO。
 */
void ICAP_SECTION IC1_CallBack(void) {
    if (s_isr) s_isr();
#if BSP_ICX_CAPTURE_DEBUG
    IC_CaptureDrain(IC1_IDX);
#endif
}

void ICAP_SECTION IC2_CallBack(void) {
    if (s_isr) s_isr();
#if BSP_ICX_CAPTURE_DEBUG
    IC_CaptureDrain(IC2_IDX);
#endif
}

void ICAP_SECTION IC3_CallBack(void) {
    if (s_isr) s_isr();
#if BSP_ICX_CAPTURE_DEBUG
    IC_CaptureDrain(IC3_IDX);
#endif
}

