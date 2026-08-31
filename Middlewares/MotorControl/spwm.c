/*
 * spwm.c
 *
 * 三相正弦（SPWM）电压生成模块实现
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
 * 本文件仅含计算（归一化电压 + 占空比映射），不含寄存器写入
 * （占空比结果由调用方写 PDC）。
 */

#include "spwm.h"
#include "sincos.h"
#include "mc_services.h"

#define SPWM_SQRT3DIV2_UQ16   56756u   /* √3/2 × 2^16 = 56755.5 → 56756 */

/* 占空调制中点：满量程一半
 */
#define HALF_OF_DUTY_FULLSCALE   (MC_DUTY_FULLSCALE >> 1)
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

