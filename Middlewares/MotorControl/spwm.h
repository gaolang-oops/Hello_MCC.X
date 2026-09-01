/*
 * spwm.h
 *
 * 三相正弦（SPWM）模块：
 *   1) 正弦计算（纯函数）：由 brad16 电角度 θ 经 SinCos16 查表生成互差 120° 的
 *      三相正弦波 Ua/Ub/Uc，及"幅值指令 + 电角度 → 三相占空比"映射；
 *   2) 使能闸门 SPWM_Enable：对称于 six_step 的 SIXSTEP_Enable，
 *      en=true 预置零矢量后交还 PWM 互补自主控制，en=false 硬关 6 管。
 *
 * 依赖方向：spwm ──▶ sincos（纯查表）；
 *           使能闸门 spwm ──▶ pwm_common（寄存器唯一所有者，本模块不直接触碰寄存器）。
 *
 * 定点约定：
 *   计算输出为 Q1.15 归一化电压（真实值 = 分量 / 32768，无量纲），
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
#include <stdbool.h>

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

/* 三相 SPWM 占空比（调用方可直接写 PDC） */
typedef struct {
    uint16_t u;   /* U 相占空比 */
    uint16_t v;   /* V 相占空比 */
    uint16_t w;   /* W 相占空比 */
} SPWM_DutyUVW_t;
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
SPWM_UabcQ15_t SPWM_ComputeUabcQ15(uint16_t theta16);

/**
   @Summary
     target_duty + 电角度 → 三相 SPWM 占空比（纯映射，无时基/硬件依赖）。

   @Description
     bipolar SPWM：duty = 满量程/2 + (target_duty × 相正弦) >> 16。
     调制中点为死值（MC_DUTY_FULLSCALE 的一半，50% 占空），不随 target_duty 变化：
       相正弦=0  → 三相恒 50% 共模，零差压零输出
       相正弦=±1 → 中点 ± target_duty/2（占空幅值 = target_duty/2）
     输出经 MC_DUTY_CLAMP 饱和到 [MC_DUTY_MIN, MC_DUTY_MAX]，
     调制深度 > 84% 后正弦峰触界削顶；负半周由互补桥 L 管自动承载。
     	死区280，故满量程最大：3500-280=3220; 3220/3500=92%
     	波形中心在 50%[1750]，所以波峰爬到天花板只需再涨 3220-1750=1470 个点 → 调制范围就是1470*2=2940
     	2940/3500=84%  即84%就开始削顶。MIN 侧同理（(1750−280)/1750 = 84%，上下对称）。

   @Parameters
     theta16      电角度（brad16：0~65535 ⇔ 0°~360°）
     target_duty  幅值指令（PWM ticks ≤ MC_DUTY_FULLSCALE，  0 = 恒 50% 共模零输出）

   @Returns
     SPWM_DutyUVW_t：三相占空比。
 */
SPWM_DutyUVW_t SPWM_Duty_UVW(uint16_t theta16, uint16_t target_duty);

/**
  @Summary
    使能/失能 SPWM 输出（对称于 SIXSTEP_Enable 的驱动闸门）。

  @Description
    en=true 时：防御性重置三相 PDC=50% 中点（SPWM 零矢量，三相差压=0，
    交接瞬间输出从"强制 00"跳到互补 50/50，无转矩冲击/无直通窗口），
    再经 PWM_HandOffToPwm() 交还 PWM 互补自主控制。
    en=false 时：立即硬关 6 管（PWM_AllOff，强制 H=0/L=0，优先级高于自主控制）。
    进入 MOTOR_STATE_RUNNING 前置 true，离开（停机/故障）置 false。
    寄存器写入全部经 pwm_common 原语，所有权仍归 pwm_common。
 */
void SPWM_Enable(bool en);

/**
  @Summary
    查询 SPWM 输出是否已使能。
 */
bool SPWM_IsEnabled(void);

#ifdef __cplusplus
}
#endif

#endif /* SPWM_H */