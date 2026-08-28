/*
 * bsp_freq.c
 *
 * 启动期对齐检查:MCC 写入的 PHASE 寄存器 vs 母宏 BSP_PWM_PHASE_TICKS。
 *
 */

#include "bsp_freq.h"
#include <xc.h>                      /* PHASE1/TRGCON1 SFR */
#include "../../user_manager.h"      /* VERIFY */

/* BSP_FREQ_Verify —— 在 SYSTEM_Initialize() 后、开中断前调用。
 *
 * MCC 生成的 pwm.c 把 PHASE1/2/3 写死为字面量(无法宏化),
 * 本头 BSP_PWM_PHASE_TICKS 是另一份独立拷贝。
 * 两者漂移(改了 MCC GUI 忘了同步本头)时,这里死循环,
 * 调试器原地捕获,杜绝"占空比刻度/时基分频静默失准"的幽灵故障。
 *
 * 注 1:三相同步配置(PHASE1==PHASE2==PHASE3),只校验 PHASE1 即可;
 *      TRIG1(ADC 触发点)也等于 PHASE1,故无需重复校验。
 */
void BSP_SECTION BSP_FREQ_Verify(void)
{
    VERIFY(PHASE1 == BSP_PWM_PHASE_TICKS);     /* NDEBUG 发布版下 assert 被删,VERIFY 仍强制检查 */
}
