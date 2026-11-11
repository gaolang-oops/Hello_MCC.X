/*
 * mc_ramp.c
 *
 * 占空比缓变模块实现
 * 职责：纯软件缓变策略，不碰寄存器。
 *      目标速度来自 mc_services（旋钮/速度环），换算为占空比域缓变；
 *
 * 本模块只维护 target_duty / current_duty 参考，不写任何硬件。
 * 输出由调用方按驱动模式在各自速率执行（motor_control 的 Drive_Output）：
 *   六步：1ms tick 把 current_duty 三相同幅值写 PDC；
 *   SPWM：50µs tick 用 current_duty 作幅值合成三相正弦后写 PDC。
 * 硬关断（FAULT/STOPPED）仍由状态机 Drive_Enable(false) → PWM_AllOff 保证。
 */

#include "mc_ramp.h"
#include "mc_services.h"
#include <stdlib.h>   /* abs */

static Ramp_Handle_t s_ramp = {
    .step_big       = RAMP_STEP_BIG,
    .step_small     = RAMP_STEP_SMALL,
    .threshold      = RAMP_THRESHOLD,
    .ramp_period_ms = RAMP_PERIOD_MS,
};

/* 目标占空比来源（速度环接缝）：默认旋钮直驱，可经 SetTargetProvider 切换 */
static Ramp_TargetProvider_t s_target_provider = MC_GetKnobSpeed;

/* 缓停请求：置位后忽略 target provider，把 current_duty 缓降到 0 */
static bool s_stop_request = false;

void MC_Ramp_Init(void)
{
    s_ramp.target_duty  = 0;
    s_ramp.current_duty = 0;
    s_ramp.last_tick_ms = MC_GetTickMs();
    s_target_provider   = MC_GetKnobSpeed;   /* 复位为默认旋钮直驱 */
    s_stop_request      = false;
}

void MC_Ramp_RequestStop(void)
{
    s_stop_request = true;   /* 可重复调用；到 0 后由 MC_Ramp_Step 自动清除 */
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
    s_stop_request      = false;
}

/*
 * 一步缓变：
 *   - 每个主循环调用，内部按 ramp_period_ms 判节拍
 *   - 差距 > threshold 用大步进，否则小步进
 *   - 最后一步 clamp 防过冲
 */
void MC_Ramp_Step(void)
{
	/* 缓停请求优先：忽略 provider，目标固定 0 */
	uint16_t speed_uq16 = s_stop_request ? 0u : s_target_provider();

	/* 目标速度->目标占空比
	 * 反归一化 —— /65536 × PWM周期 */
	s_ramp.target_duty = __builtin_muluu(speed_uq16, MC_DUTY_FULLSCALE) >> 16;

    /* 已经到 0：清停止请求，避免下次启动仍被压成 0 */
    if (s_stop_request && s_ramp.current_duty == 0u) {
        s_stop_request = false;
    }

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
    s_ramp.current_duty = next;   /* 仅更新参考，硬件由 Drive_Output 按模式/速率写 */

    /* 缓停刚到达 0：清请求 */
    if (s_stop_request && next == 0u) {
        s_stop_request = false;
    }
}

Ramp_Handle_t* MC_Ramp_GetHandle(void)
{
    return &s_ramp;
}
