/*
 * File:   six_step.h
 * Author: gaol
 *
 * Created on 2026年7月22日, 下午3:47
 *
 * 六步换相模块
 * 仅正转单表；换相在 Hall ISR 内调用 SIXSTEP_Communicate() 执行。
 */

#ifndef SIX_STEP_H
#define	SIX_STEP_H

#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/**
  @Summary
    六步换相模块初始化。

  @Description
    复位使能标志为 false（不换相），并内部调 PWM_AllOff 保证 PWM 初始全关。
    mc_ramp 只维护占空比参考，不再写硬件，故初始关断不依赖它。
 */
void SIXSTEP_Init(void);

/**
  @Summary
    使能/失能六步换相。

  @Description
    en=true  时，先把三相 PDC 置 0（消除上次运行残留占空比），再恢复上桥 PWM，
    并用当前 Hall 建立换相初态；此后 SIXSTEP_Communicate() 才真正驱动 Override。
    en=false 时，立即将三相全部强制为 OFF（安全态），并使后续 Communicate 成为空操作。
    进入 MOTOR_STATE_RUNNING 前置 true，离开（停机/故障）置 false。
    使能统一从 0 占空起步，RUNNING 里由 Drive_Output 按缓变参考逐级提升。
 */
void SIXSTEP_Enable(bool en);

/**
  @Summary
    查询换相是否已使能。
 */
bool SIXSTEP_IsEnabled(void);

/**
  @Summary
    依据 Hall 状态执行一次换相（查表 → 写 Override 寄存器）。

  @Description
    在 Hall 跳变 ISR 中调用，延迟最小。
    hall 取值 1~6 对应 6 个导通步序；0/7 视为非法，落入三相全关安全态。
    若 SIXSTEP_IsEnabled()==false，本函数为空操作。
    相序：PWM_GENERATOR_1=U, PWM_GENERATOR_2=V, PWM_GENERATOR_3=W。
    模式：PWM_HPWM_LOFF=上桥PWM/下桥关, PWM_HOFF_LON=上桥关/下桥常通, PWM_HOFF_LOFF=上下桥均关。
 */
void SIXSTEP_Communicate(uint8_t hall);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SIX_STEP_H */
