/*
 * spwm.c
 *
 * 三相正弦（SPWM）模块实现
 *   1) 正弦计算：
 *   Ua = sin(θ)
 *   Ub = sin(θ + 120°)   = SinCos16(θ + 0x5555).sin
 *   Uc = sin(θ + 240°)   = SinCos16(θ + 0xAAAA).sin
 *
 * 角度偏移均为 2 的幂无关量，靠 uint16 加法溢出实现 360° 回卷：
 *   θ+0x5555 与 θ+0xAAAA 在 16 位加法域内恒 ∈ [0, 65536)，无需任何分支/取模。
 *
 * 三相平衡：对任意 θ，Ua+Ub+Uc ≡ 0（sin 在 120° 网格上调和恒为零；
 * 查表插值引入的量化残差 < ~35 LSB，全角可忽略）。
 *
 * 计算部分仅含计算（归一化电压 + 占空比映射），不含寄存器写入
 * （占空比结果由调用方写 PDC）。
 *
 *   2) 使能闸门 SPWM_Enable（对称于 six_step 的 SIXSTEP_Enable）：
 *   寄存器写入全部经 pwm_common 原语，本模块不直接触碰 Override 寄存器。
 */

#include "spwm.h"
#include "sincos.h"
#include "mc_services.h"
#include "pwm_common.h"   /* PWM 寄存器唯一抽象边界（SPWM_Enable 闸门用） */

#define SPWM_SQRT3DIV2_UQ16   56756u   /* √3/2 × 2^16 = 56755.5 → 56756 */

/* 占空调制中点：满量程一半（50% 共模零矢量）
 * 与状态机层 SPWM_DUTY_MID（motor_control.h）同值同源 MC_DUTY_FULLSCALE：
 * 自举充电占空、使能交接零矢量、SPWM_Duty_UVW 调制基线共用此值 */
#define HALF_OF_DUTY_FULLSCALE   (MC_DUTY_FULLSCALE >> 1)

/* SPWM 使能闸门（软件互锁；对称于 six_step.c 的 s_enabled） */
static volatile bool s_enabled = false;
/*
 * 三相相位相差120度正弦波产生
 * Ua = Cos（θ）
 * Ub = Cos（θ - 120）= -1/2 Cosθ + sqrt(3)/2 Sinθ
 * Uc = Cos（θ + 120）= -1/2 Cosθ - sqrt(3)/2 Sinθ
 */
SPWM_UabcQ15_t SPWM_ComputeUabcQ15(uint16_t theta16) {
    SPWM_UabcQ15_t u;
    SinCos16_Result_t r;
    int16_t temp;

    r.u32 = SinCos16(theta16);
    u.ua  = r.sc.cos;                       /* Ua = cos(θ) */
	// sin为有符号数，SQRT3DIV2为无符号数
    temp  = (int16_t)(__builtin_mulus(SPWM_SQRT3DIV2_UQ16, r.sc.sin) >> 16); /* (√3/2)·sinθ */
    u.ub  = -(r.sc.cos >> 1) + temp;  /* cos(θ−120°) */
    u.uc  = -(r.sc.cos >> 1) - temp;  /* cos(θ+120°) */
    return u;
}

/*
 * 目标占空比配合电角度 → 三相 SPWM 占空比
 *   duty_temp = 满量程/2 + ((target_duty × cosθ) >> 16)
 *   - mulus(无符号 * 有符号) 16×16→32 单周期，算术右移 16 取积
 *   - 前置：target_duty ≤ MC_DUTY_FULLSCALE(3500)，规格内中间值 ∈ [0, 3499]，
 */
SPWM_DutyUVW_t SPWM_Duty_UVW(uint16_t theta16, uint16_t target_duty) {
    SPWM_DutyUVW_t duty_out;
    SPWM_UabcQ15_t u;
	uint16_t duty_temp;

    u = SPWM_ComputeUabcQ15(theta16);

	duty_temp = HALF_OF_DUTY_FULLSCALE + (__builtin_mulus(target_duty, u.ua) >> 16);
    duty_out.u = MC_DUTY_CLAMP(duty_temp);

	duty_temp = HALF_OF_DUTY_FULLSCALE + (__builtin_mulus(target_duty, u.ub) >> 16);
    duty_out.v = MC_DUTY_CLAMP(duty_temp);

	duty_temp = HALF_OF_DUTY_FULLSCALE + (__builtin_mulus(target_duty, u.uc) >> 16);
    duty_out.w = MC_DUTY_CLAMP(duty_temp);

    return duty_out;
}

void SPWM_Enable(bool en) {
    s_enabled = en;
    if (en) {
        /* 交接约定(PWM_HandOffToPwm)：先预置 PDC=50% 中点(SPWM 零矢量，三相差压=0，
         * 交接瞬间输出从"强制 00"跳到互补 50/50，无转矩冲击/无直通窗口)，再交还。
         * 防御性重置：CHARGING 末拍 PWM_AllOff 后 PDC 可能已被 ramp 写走。
         * TODO(SPWM): 调制链仍空缺(mc_ramp 幅值汇点 + 50us tick θ 积分 -> SPWM_Duty_UVW)，
         *             接入前 RUNNING 态仅零矢量静默输出，电机不旋转。 */
        PWM_SetDuty_UVW(HALF_OF_DUTY_FULLSCALE, HALF_OF_DUTY_FULLSCALE, HALF_OF_DUTY_FULLSCALE);
        PWM_HandOffToPwm();
    } else {
        /* 失能即下电：清软件闸门 + 防御性硬关三相（即便上层漏调 PWM_AllOff 也安全）。
         * PWM_AllOff 经 PWM_SetPhaseMode 写 Override，寄存器所有权仍归 pwm_common。 */
        PWM_AllOff();
    }
}

bool SPWM_IsEnabled(void) {
    return s_enabled;
}

