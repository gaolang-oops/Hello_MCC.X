/*
 * mc_ramp.c
 *
 * 占空比缓变模块实现
 * 职责：纯软件缓变策略，不碰寄存器。
 *      目标值来自 mc_services（旋钮），硬件写入经 pwm_common。
 */

#include "mc_ramp.h"
#include "mc_services.h"
#include "pwm_common.h"
#include <stdlib.h>   /* abs */

static Ramp_Handle_t s_ramp = {
    .step_big       = RAMP_STEP_BIG,
    .step_small     = RAMP_STEP_SMALL,
    .threshold      = RAMP_THRESHOLD,
    .ramp_period_ms = RAMP_PERIOD_MS,
};

/* 目标占空比来源（速度环接缝）：默认旋钮直驱，可经 SetTargetProvider 切换 */
static Ramp_TargetProvider_t s_target_provider = MC_GetKnobDuty;

void MC_Ramp_Init(void)
{
    s_ramp.target_duty  = 0;
    s_ramp.current_duty = 0;
    s_ramp.last_tick_ms = MC_GetTickMs();
    s_target_provider   = MC_GetKnobDuty;   /* 复位为默认旋钮直驱 */
    PWM_SetDutyCycle(0);   /* 同步硬件 */
}

void MC_Ramp_SetTargetProvider(Ramp_TargetProvider_t provider)
{
    if (provider) {
        s_target_provider = provider;
    }
}

uint16_t MC_Ramp_GetCurrentDuty(void)
{
    return s_ramp.current_duty;
}

void MC_Ramp_ForceZero(void)
{
    s_ramp.target_duty  = 0;
    s_ramp.current_duty = 0;
    PWM_SetDutyCycle(0);
}

/*
 * 一步缓变：
 *   - 每个主循环调用，内部按 ramp_period_ms 判节拍
 *   - 差距 > threshold 用大步进，否则小步进
 *   - 最后一步 clamp 防过冲
 */
void MC_Ramp_Step(void)
{
    s_ramp.target_duty = s_target_provider();   /* 经 provider：旋钮直驱 / 速度环输出 */

    uint16_t now = MC_GetTickMs();
    if ((now - s_ramp.last_tick_ms) < s_ramp.ramp_period_ms)
        return;   /* 未到节拍，不动 last_tick，等下个主循环再判 */
    s_ramp.last_tick_ms = now;

    int16_t gap = (int16_t)s_ramp.target_duty - (int16_t)s_ramp.current_duty;
    if (gap == 0) return;

    uint16_t abs_gap = (uint16_t)abs(gap);
    uint16_t step = (abs_gap > s_ramp.threshold) ? s_ramp.step_big : s_ramp.step_small;

    if (step > abs_gap) step = abs_gap; /* 防过冲 */

    uint16_t next = (gap > 0) ?
        (uint16_t)(s_ramp.current_duty + step) :
        (uint16_t)(s_ramp.current_duty - step);

    PWM_SetDutyCycle(next);
    s_ramp.current_duty = next;
}

Ramp_Handle_t* MC_Ramp_GetHandle(void)
{
    return &s_ramp;
}
