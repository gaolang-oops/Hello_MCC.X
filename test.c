/*
 * File:   test.c
 * Author: gaol
 *
 * Created on August 22, 2026, 3:15 PM
 *
 * 测试模块实现：DAC 正余弦波形验证
 */

#include "test.h"

#include "user_manager.h"
#include "mcc_generated_files/interrupt_manager.h"

#include "Drivers/BSP/bsp_gpio.h"
#include "Drivers/BSP/bsp_adc.h"
#include "Drivers/BSP/delay.h"

#include "Drivers/Components/mcp4922.h"

#include "Middlewares/MotorControl/sincos.h"
#include "Middlewares/MotorControl/spwm.h"

#include <stdio.h>

#define DAC_TEST_FREQ_HZ        50u
#define DAC_TEST_PHASE_STEP     164u


/* ==================== SPWM 三相正弦 DAC 波形验证（50us 时基，ISR 上下文） ====================
 *
 * SPWM_ComputeQ15 输出三相正弦 → SPI → MCP4922 → 示波器手动观察 120° 关系。
 *
 * 数据通路（每 50us 一次，20kHz 更新率）：
 *   相位累加 → SPWM_ComputeQ15 → 4 路 DAC：
 *     DAC1(CS=RA9)：通道A=Ua  通道B=Ub
 *     DAC2(CS=RD8)：通道A=Uc  通道B=cos(θ)（相位锚点，便于观察超前/滞后）
 *
 * 幅值映射：MCP4922_WriteQ15AB 处理 Q1.15(-32768~32767) → 12bit 偏置二进制(0~4095)，
 *   0 → 2048(VREF/2)，正负半周以 VREF/2 为零点（DAC 无法输出负电压）。
 *
 * 50Hz：每 50us 相位步进 = 65536×50/20000 = 163.84 → 164
 * 实际频率 = 20000×164/65536 = 50.05Hz（偏差 0.1%，示波器观察无影响） */

static void TEST_SECTION DAC_SPWM_Tick50us(void)
{
    static uint16_t s_phase = 0;             /* 相位累加器(UQ0.16)，uint16 溢出即 360° 回卷 */
    SPWM_UabcQ15_t u;
    SinCos16_Result_t anchor;

    s_phase += DAC_TEST_PHASE_STEP;

    u = SPWM_ComputeUabcQ15(s_phase);            /* Ua=cosθ Ub=cos(θ-120°) Uc=cos(θ+120°) */
	anchor.u32 = SinCos16(s_phase);          /* 相位锚点：cos(θ) 仅供示波器对照 */

    /* 通道A/B 各一帧：DAC1=Ua/Ub，DAC2=Uc/cos */
    MCP4922_WriteQ15AB(MCP4922_DAC1, u.ua, u.ub);
    MCP4922_WriteQ15AB(MCP4922_DAC2, u.uc, anchor.sc.cos);
}

void TEST_SECTION TEST_Init(void)
{
    // BSP_ADC_TimeBase_Register50us(DAC_SinCos_Tick50us);
    BSP_ADC_TimeBase_Register50us(DAC_SPWM_Tick50us);
}

#if 0
void TEST_ModuleRun(void) {
#if 1 /* 正弦/余弦查表+线性插值验证: C 版 SinCos16 vs 汇编版 SinCos16_Asm(均一次返回 sin+cos)
          * angle16(UQ0.16) → idx = a16>>9, frac = a16&0x1FF → t[idx] 与 t[idx+1] 两点插值(Q1.15)
          * cos(θ)=sin(θ+90°): 90°=0x4000 恰为 2 的幂分点 → 索引精确+32(&0x7F 回卷),
          *                      且 +0x4000 不改变低 9 位 → sin/cos 共享同一 frac
          * 表上点(frac=0)期望=表值; 非表上点 0x0100/0x0300(frac=256,半步)与
          * 0xFFFF(frac=511)专测插值+回卷路径, 期望值由宿主端全角度验证脚本给出 */
    {
        /* 采样点: 0°/0.5步/1步/1.5步/45°/90°/180°/270°/359.99°(含 idx127→0 回卷) */
        uint16_t angles[]  = {0x0000, 0x0100, 0x0200, 0x0300, 0x2000, 0x4000, 0x8000, 0xC000, 0xFFFF};
        int16_t  sin_exp[] = {     0,    804,   1608,   2410,  23170,  32767,      0, -32768,    -4};
        int16_t  cos_exp[] = { 32767,  32748,  32729,  32669,  23170,      0, -32768,      0, 32766};
        uint8_t i;
        uint8_t n = (uint8_t)(sizeof(angles)/sizeof(angles[0]));
        printf("[SIN] angle16  idx     C_sin     C_cos   Asm_sin   Asm_cos  expect_sin expect_cos  cmp\n");
        for (i = 0; i < n; i++) {
            uint16_t a16 = angles[i];
            SinCos16_Result_t c_res;               /* C 版: sin+cos 一次取回 */
            SinCos16_Result_t a_res;               /* 汇编版: sin+cos 一次取回 */
            c_res.u32 = SinCos16(a16);
            a_res.u32 = SinCos16_Asm(a16);
            printf("      0x%04X  %3u  %8d  %8d  %8d  %8d  %10d  %10d   %s\n",
                    a16, (uint16_t)(a16 >> 9), c_res.sc.sin, c_res.sc.cos,
                    a_res.sc.sin, a_res.sc.cos,
                    sin_exp[i], cos_exp[i],
                    (c_res.u32 == a_res.u32 && c_res.sc.sin == sin_exp[i]
                     && c_res.sc.cos == cos_exp[i]) ? "OK" : "FAIL");
        }
    }
#endif

#if 1 /* 速度对比: 用 LED1 脉宽测量 N 次调用总耗时
        * 示波器探头接 LED1, 单次触发, 会看到三段高电平脉冲:
        *   第1段 = C 版。第2段 = 汇编版。   第3段 = 空循环(基线)
        * 单次净耗时 = (脉宽 - 基线脉宽) / N */
    {
        uint32_t N = 100000u;
        volatile uint32_t bench_sink;  /* 汇编版返回 uint32(sin|cos<<16)，原样接住 */
        uint32_t i;

        INTERRUPT_GlobalDisable();   /* 关中断, 避免中断拉长脉宽 */

        LED_On(LED1);                /* --- C 版 --- */
        for (i = 0; i < N; i++) bench_sink = SinCos16(0x0300);
        LED_Off(LED1);

        Delay_ms(5);                 /* 间隔, 便于示波器分段 */

        LED_On(LED1);                /* --- 汇编版(同样 sin+cos 一体) --- */
        for (i = 0; i < N; i++) bench_sink = SinCos16_Asm(0x0300);
        LED_Off(LED1);

        Delay_ms(5);

        LED_On(LED1);                /* --- 空循环基线 --- */
        for (i = 0; i < N; i++) bench_sink = 0;
        LED_Off(LED1);

        INTERRUPT_GlobalEnable();
        printf("[BENCH] 示波器测 LED1 三段脉宽(N=%lu/段): C / Asm / empty\n", N);
        printf("[BENCH] 单次净耗时 = (该段脉宽 - empty脉宽) / %lu\n", N);
    }
#endif
}

/* 调试:50Hz 正弦波经 UART2 送 VOFA+ 显示(FireWater 文本协议)。
 * 启用方法:
 * 在 main.c 1ms 节拍处调用本函数。 
 */
void VofaWave_SendSine(void) {
    static uint16_t s_phase = 0;         /* 相位累加器(UQ0.16) */
    SinCos16_Result_t r;

    s_phase += 3277u;
    r.u32 = SinCos16(s_phase);
    printf("%d\n", r.sc.sin);
}

/*
 * Hall_DebugPrint
 * 应用层调试：打印当前 Hall 状态。
 * bit2=U, bit1=V, bit0=W
 */
void Hall_DebugPrint(void) {
    uint8_t h = HALL_GetHallStatus();
    printf("%d:[%d, %d, %d]\n", h, (h >> 2) & 1, (h >> 1) & 1, h & 1);
}

/*  DAC 正余弦波形验证（50us 时基，ISR 上下文）
 *
 * 查表函数输出经 SPI→MCP4922 变成模拟量，示波器直观验证算法与驱动。
 *
 * 数据通路（每 50us 一次，20kHz 更新率）：
 *   相位累加 → C 版 SinCos16     → DAC1(CS=RA9)：通道A=正弦 通道B=余弦
 *            → 汇编版 SinCos16_Asm → DAC2(CS=RD8)：通道A=正弦 通道B=余弦
 *
 * 幅值映射：Q1.15(-32768~32767) → 12bit 偏置二进制(0~4095)，
 *   0 → 2048(VREF/2)，正负半周以 VREF/2 为零点（DAC 无法输出负电压）。
 */
/* 测试 50Hz 正余弦波
 * ADC中断 @ 20kHz 更新率 50us周期
 * 正余弦波每周期 20000us/50us=400 点，相位步进 = 65536/400 = 163.84 → 164
 * 实际频率 = 20000×164/65536 = 50.049Hz（偏差 0.1%，示波器观察无影响） */

static void TEST_SECTION DAC_SinCos_Tick50us(void)
{
    static uint16_t s_phase = 0;         /* 相位累加器(UQ0.16)，uint16 溢出即 360° 回卷 */
    SinCos16_Result_t c_res;             /* C 版: sin+cos 一次取回 */
    SinCos16_Result_t a_res;             /* 汇编版: sin+cos 一次取回 */

    s_phase += DAC_TEST_PHASE_STEP;

    /* 同一相位分别用两个版本查表，双 DAC 各验一个 */
    c_res.u32 = SinCos16(s_phase);       /* C 版   → DAC1 */
    a_res.u32 = SinCos16_Asm(s_phase);   /* 汇编版 → DAC2 */

    /* 通道A=正弦，通道B=余弦 */
    MCP4922_WriteQ15AB(MCP4922_DAC1, c_res.sc.sin, c_res.sc.cos);
    MCP4922_WriteQ15AB(MCP4922_DAC2, a_res.sc.sin, a_res.sc.cos);
}

#endif

