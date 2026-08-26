/*
 * spwm.h
 *
 * 三相正弦（SPWM）电压生成模块（控制策略层，无硬件依赖）
 * 由 brad16 电角度 θ 经 SinCos16 查表生成互差 120° 的三相正弦波 Ua/Ub/Uc。
 *
 * 依赖方向：spwm ──▶ sincos（纯查表）；不触碰任何寄存器/外设。
 *
 * 定点约定：
 *   输出为 Q1.15 归一化电压（真实值 = 分量 / 32768，无量纲），
 *   后续由上层按调制度映射为 PWM 占空比（观众：本项目 PDC 寄存器）。
 *
 * 相序（正转，电角度超前序）：
 *   Ua = sin(θ)
 *   Ub = sin(θ + 120°)   ← brad16 偏移 0x5555 = 21845
 *   Uc = sin(θ + 240°)   ← brad16 偏移 0xAAAA = 43690
 *   任一角三相平衡：Ua + Ub + Uc ≡ 0。
 *   如需反序（反转），将 Ub/Uc 的偏移对调即可（0x5555 ↔ 0xAAAA）。
 *
 * brad16 特性（与 sincos 一致）：
 *   全周 360° 映射到 uint16 满量程 65536；
 *   uint16 加法溢出即自动 360° 回卷，负角度补码自动正确，零分支。
 */

#ifndef SPWM_H
#define SPWM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 120° / 240° 的 brad16 相位偏移（360° = 65536）：
 *   120° = 65536/3 = 21845.33 → 21845 (0x5555)
 *   240° = 2×120°              → 43690 (0xAAAA)
 * 三者与表步长 2.8125° 非整数数倍关系，经线性插值平滑过渡，误差有界（<~12 LSB）。
 * 导出宏供上层 / 测试引用（如相序对调反转）。 */
#define SPWM_PHASE_120          0x5555u
#define SPWM_PHASE_240          0xAAAAu

/* 三相归一化电压结果（Q1.15，真实电压 = 分量 / 32768）*/
typedef struct {
    int16_t ua;   /* U 相：sin(θ)            */
    int16_t ub;   /* V 相：sin(θ + 120°)      */
    int16_t uc;   /* W 相：sin(θ + 240°)      */
} SPWM_UabcQ15_t;

/**
   @Summary
     由电角度 theta16 计算三相正弦电压 Ua/Ub/Uc（Q1.15）。

   @Description
     三次调用 SinCos16 分别查表 θ、θ+120°、θ+240° 的正弦值。
     角度偏移经 uint16 加法溢出免费回卷，0~360°（含负角度补码）全部正确。
     返回结构含三相，调和恒为零（三相平衡），可直接打印/DAC/占空比映射。

   @Parameters
     theta16  电角度（brad16：0~65535 ⇔ 0°~360°）

   @Returns
     SPWM_UabcQ15_t：ua=sinθ, ub=sin(θ+120°), uc=sin(θ+240°)，各分量 Q1.15。
 */
SPWM_UabcQ15_t SPWM_ComputeQ15(uint16_t theta16);
SPWM_UabcQ15_t Get_Uabc_Q15(uint16_t theta16);
#ifdef __cplusplus
}
#endif

#endif /* SPWM_H */