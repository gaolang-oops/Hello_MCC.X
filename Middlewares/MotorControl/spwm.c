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
 * 本文件仅含"归一化电压计算"，不含硬件写入（占空比映射/PDC 归上层）。
 */

#include "spwm.h"
#include "sincos.h"

SPWM_UabcQ15_t SPWM_ComputeQ15(uint16_t theta16) {
    SPWM_UabcQ15_t u;
    SinCos16_Result_t r;

    /* Ua = sin(θ)：theta16 低 9 位为插值 frac，直接作为基准相位 */
    r.u32 = SinCos16(theta16);
    u.ua = r.sc.sin;

    /* Ub = sin(θ + 120°)：+0x5555 溢出即回卷，无需 mask */
    r.u32 = SinCos16((uint16_t)(theta16 + SPWM_PHASE_120));
    u.ub = r.sc.sin;

    /* Uc = sin(θ + 240°)：+0xAAAA 与 -0x5555 等价（补码回卷），即滞后 120° */
    r.u32 = SinCos16((uint16_t)(theta16 + SPWM_PHASE_240));
    u.uc = r.sc.sin;

    return u;
}

#define SPWM_SQRT3DIV2_Q16   56756u   /* √3/2 × 2^16 = 56755.5 → 56756 */
/*
 * 三相相位相差120度正弦波产生
 * Ua = Cos（θ）
 * Ub = Cos（θ - 120）= -1/2 Cosθ + sqrt(3)/2 Sinθ
 * Uc = Cos（θ + 120）= -1/2 Cosθ - sqrt(3)/2 Sinθ
 */
SPWM_UabcQ15_t Get_Uabc_Q15(uint16_t theta16) {
    SPWM_UabcQ15_t u;
    SinCos16_Result_t r;
    int16_t temp;

    r.u32 = SinCos16(theta16);
    u.ua  = r.sc.cos;                       /* Ua = cos(θ) */
	// sin为有符号数，SQRT3DIV2为无符号数
    temp  = (int16_t)(__builtin_mulus(SPWM_SQRT3DIV2_Q16, r.sc.sin) >> 16); /* (√3/2)·sinθ */
    u.ub  = -(r.sc.cos >> 1) + temp;  /* cos(θ−120°) */
    u.uc  = -(r.sc.cos >> 1) - temp;  /* cos(θ+120°) */
    return u;
}
