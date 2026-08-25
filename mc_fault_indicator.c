/*
 * mc_fault_indicator.c
 *
 * 故障 LED 指示模块实现。详见 mc_fault_indicator.h 架构说明。
 *
 * 依赖方向(向下):
 *   mc_fault_indicator -> MC_Fault(MC_GetFault)
 *   mc_fault_indicator -> BSP(LED_On/Off)
 *
 * 状态机(故障模式):
 *   FLASH_ON --200ms--> FLASH_OFF --(未够 N 次)--> FLASH_ON
 *                       FLASH_OFF --(够 N 次)----> SETTLE
 *   SETTLE   --1200ms-> 推进到下一置位故障位(末位回绕) -> FLASH_ON
 *   故障集变化 -> 从最低位重扫 -> FLASH_ON
 *
 * 心跳职责：LED0(main.c 500ms 翻转),本模块无故障时保持 LED3 熄灭。
 */

#include "mc_fault_indicator.h"
#include "Middlewares/MotorControl/MC_Fault.h"        /* MC_GetFault / MC_Fault_e */
#include "Drivers/BSP/bsp_gpio.h"                     /* LED_On/Off */
#include "user_manager.h"

/* ---- 闪烁时序参数(物理时长,与 PWM 频率无关) ---- */
#define IND_FLASH_ON_MS      200u    /* 单次闪烁亮时长 */
#define IND_FLASH_OFF_MS     200u    /* 单次闪烁灭时长 */
#define IND_SETTLE_MS        1200u   /* 同一故障组之间的沉降间隔 */

/* ---- 状态机相位 ---- */
typedef enum {
    IND_FLASH_ON,     /* 闪烁亮 */
    IND_FLASH_OFF,    /* 闪烁灭(组内) */
    IND_SETTLE,       /* 故障组之间沉降 */
} IndState_t;

/* ---- 模块状态(仅主循环 1ms 分支访问,无 ISR 竞态) ---- */
typedef struct {
    bool        was_fault;      /* 上拍是否处于故障态(故障->无故障切换时灭灯) */
    uint16_t    last_fault;     /* 上次快照,用于检测故障集变化 */
    uint16_t    current_bit;    /* 当前正在显示的单 bit 故障 */
    uint8_t     flash_count;    /* 当前故障总闪烁次数 */
    uint8_t     flash_done;     /* 当前故障已完成闪烁次数 */
    uint16_t    phase_ms;       /* 当前相位计时 */
    IndState_t  state;          /* 状态机当前状态 */
} FaultInd_t;

static FaultInd_t s_ctx = {.state = IND_FLASH_ON,};

/* 单 bit 故障 -> 闪烁次数 = 位号 + 1。
 * 规则:闪 N 次 = bit(N-1),工人可直觉推断,无需背表。
 * 从 single_bit(2的幂)右移数位号,最多 6 次循环(bit6 = OVER_TEMP -> 7 次)。 */
//比如0b0010，bit1=1,count=2。以此类推bit2=1,count=3
static uint8_t MOTOR_SECTION fault_to_flash_count(uint16_t single_bit)
{
    uint8_t count = 1u;   /* bit0 -> 1 次;single_bit=0 也兜底为 1 次(理论上不发生) */
    while (single_bit > 1u) {
        single_bit >>= 1;
        count++;
    }
    return count;
}

/* 取 mask 最低置位 bit(单 bit);mask=0 返回 0 */
//比如0b0110, & 0b1001+1 = 0b0110&0b1010=0b0010
static uint16_t MOTOR_SECTION lowest_set_bit(uint16_t mask)
{
    if (mask == 0u) {
        return 0u;
    }
    return (uint16_t)(mask & (~mask + 1u));
}

/* 取 after_bit 之上的下一个置位 bit(不含 after_bit 及其以下);无则 0 
 * 比如mask[fault]=0b0110，after_bit[s_ctx.current_bit]=0b0010
 * lowclear=0b0010 | 0b0001=0b0011 可以看出,bit1及其以下全置1了
 * mask & (~lowclear)=0b0110&0b1100=0b0100 表示bit1及其以下已经处理了，全部清零
 * lowest_set_bit后，就是没有处理的位:bit2。
 */

static uint16_t MOTOR_SECTION next_set_bit(uint16_t mask, uint16_t after_bit)
{
    uint16_t lowclear = (uint16_t)(after_bit | (after_bit - 1u)); /* after_bit 及其以下全置1 */
    return lowest_set_bit((uint16_t)(mask & (uint16_t)(~lowclear)));
}

void MOTOR_SECTION MCFaultIndicator_Init(void)
{
    LED_Off(LED3);
    s_ctx = (FaultInd_t){ .state = IND_FLASH_ON };
}

void MOTOR_SECTION MCFaultIndicator_Tick1ms(void)
{
    uint16_t fault = (uint16_t)MC_GetFault();

    /* ===== 无故障:LED3 熄灭 =====
     * 仅在 故障->无故障 跳变沿灭一次,避免每拍重复写 LAT。 */
    if (fault == 0u) {
        if (s_ctx.was_fault) {
            s_ctx.was_fault = false;
			s_ctx.last_fault = 0u;   
			/* 如果不执行s_ctx.last_fault = 0u;
			 * 下次相同故障重新触发 不会进入re-init，则s_ctx.was_fault依旧为false,
			 * 清理故障后，发现s_ctx.was_fault为 false，则不会执行LED_Off(LED3); */
            LED_Off(LED3);
        }
        return;
    }

    /* ===== 故障模式:故障集变化 -> 从最低位重扫 ===== */
    if (fault != s_ctx.last_fault) {
        s_ctx.was_fault   = true;
        s_ctx.last_fault  = fault;
		//lowest_set_bit:比如0b0110, & 0b1001+1 = 0b0110&0b1010=0b0010
        s_ctx.current_bit = lowest_set_bit(fault);
		//比如0b0010，bit1=1,count=2。以此类推bit2=1,count=3
        s_ctx.flash_count = fault_to_flash_count(s_ctx.current_bit);
        s_ctx.flash_done  = 0;
        s_ctx.phase_ms    = 0;
        s_ctx.state       = IND_FLASH_ON;
        LED_On(LED3);
        return;   /* 本拍只切换,下拍起计时 */
    }

    /* ===== 驱动闪烁状态机 ===== */
    s_ctx.phase_ms++;
    switch (s_ctx.state) {
        case IND_FLASH_ON:
            if (s_ctx.phase_ms >= IND_FLASH_ON_MS) {
                s_ctx.phase_ms = 0;
                LED_Off(LED3);
                s_ctx.state = IND_FLASH_OFF;
            }
            break;

        case IND_FLASH_OFF:
            if (s_ctx.phase_ms >= IND_FLASH_OFF_MS) {
                s_ctx.phase_ms = 0;
                s_ctx.flash_done++;
                if (s_ctx.flash_done >= s_ctx.flash_count) {
                    s_ctx.state = IND_SETTLE;   /* 本故障闪烁完毕,进沉降 */
                } else {
                    LED_On(LED3);
                    s_ctx.state = IND_FLASH_ON; /* 组内下一次闪烁 */
                }
            }
            break;

        case IND_SETTLE:
            if (s_ctx.phase_ms >= IND_SETTLE_MS) {
                s_ctx.phase_ms = 0;
                /* 推进到下一置位故障位;末位则回绕到最低位 */
                uint16_t nxt = next_set_bit(s_ctx.last_fault, s_ctx.current_bit);
				//如果nxt等于0，就重新开始
                s_ctx.current_bit = (nxt != 0u) ? nxt : lowest_set_bit(s_ctx.last_fault);
                s_ctx.flash_count = fault_to_flash_count(s_ctx.current_bit);
                s_ctx.flash_done  = 0;
                LED_On(LED3);
                s_ctx.state = IND_FLASH_ON;
            }
            break;

        default:
            s_ctx.state = IND_FLASH_ON;
            break;
    }
}
