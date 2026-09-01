/*
 * mc_ramp.c
 *
 * 占空比缓变模块实现
 * 职责：纯软件缓变策略，不碰寄存器。
 *      目标速度来自 mc_services（旋钮/速度环），换算为占空比域缓变；
 *
 * TODO(SPWM): 输出汇点注入（spwm 模块调制链接入时改造）
 *   当前 MC_Ramp_Step/MC_Ramp_ForceZero 直写三相同一 PDC（PWM_SetDutyCycle），
 *   只适配六步方波（三相共幅值）。SPWM 模式下三相占空按正弦各自独立，
 *   缓变输出是"调幅幅值"而非 PDC —— 不得直写 PDC（会每 1ms 同相打满三路、
 *   破坏 50us 调制节拍的正弦对称性）。
 *   改造方案（模式对称于 MC_Ramp_SetTargetProvider 的目标注入思想）：
 *     预留 MC_Ramp_SetOutputSink(void (*sink)(uint16_t duty))，
 *     默认 sink = PWM_SetDutyCycle（六步，现状零改动）；
 *     SPWM 构建下由 Motor_Init 注入 sink = SPWM_SetAmplitude
 *     （幅值经 volatile 变量交 50us 调制 tick 消费）。
 *     MC_Ramp_Init / MC_Ramp_ForceZero 的 PWM_SetDutyCycle(0) 同样改走汇点
 *     （SPWM 下幅值 0 = 三相恒 50% 共模零差压；硬关断仍由状态机 PWM_AllOff 保证）。
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
static Ramp_TargetProvider_t s_target_provider = MC_GetKnobSpeed;

void MC_Ramp_Init(void)
{
    s_ramp.target_duty  = 0;
    s_ramp.current_duty = 0;
    s_ramp.last_tick_ms = MC_GetTickMs();
    s_target_provider   = MC_GetKnobSpeed;   /* 复位为默认旋钮直驱 */
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
    PWM_SetDutyCycle(0);   /* TODO(SPWM): 见文件头"输出汇点注入"——SPWM 构建下改走幅值汇点 */
}

/*
 * 一步缓变：
 *   - 每个主循环调用，内部按 ramp_period_ms 判节拍
 *   - 差距 > threshold 用大步进，否则小步进
 *   - 最后一步 clamp 防过冲
 */
void MC_Ramp_Step(void)
{
	uint16_t speed_uq16 = s_target_provider();   /* 经 provider：旋钮直驱 / 速度环输出 */

	/* 目标速度->目标占空比
	 * 反归一化 —— /65536 × PWM周期 */
	s_ramp.target_duty = __builtin_muluu(speed_uq16, MC_DUTY_FULLSCALE) >> 16;

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
    PWM_SetDutyCycle(next);   /* TODO(SPWM): 见文件头"输出汇点注入"——SPWM 构建下改走幅值汇点 */
    s_ramp.current_duty = next;
}

Ramp_Handle_t* MC_Ramp_GetHandle(void)
{
    return &s_ramp;
}
