/*
 * File:   pwm_common.c
 * Author: gaol
 *
 * Created on 2026年7月16日, 下午2:56
 */


#include "pwm_common.h"
#include "../../mcc_generated_files/pwm.h"

/* 
 * 三相同步写占空比到硬件（纯寄存器操作）
 */
void PWM_SetDutyCycle(uint16_t duty) {
    PWM_DutyCycleSet(PWM_GENERATOR_1, duty);
    PWM_DutyCycleSet(PWM_GENERATOR_2, duty);
    PWM_DutyCycleSet(PWM_GENERATOR_3, duty);
}

/* ---- PWMC 核心原语（PWM 寄存器唯一所有者）---- */

/*
 * 单相 Override 写入的唯一入口
 * 顺序：先写 OVRDAT，再切 OVREN，避免换相瞬间出现直通毛刺。
 * 所有上层（6-step 换相 / 自举充电 / 紧急下电）都必须经此函数访问 Override 寄存器。
 */
void PWM_SetPhaseMode(PWM_GENERATOR gen, PWM_PhaseMode_t mode) {
    switch (mode) {
        case PWM_HPWM_LOFF:
            /* 上桥 PWMxH 受 PWM 模块控制，下桥 PWMxL 强制关 */
            PWM_OverrideDataHighSet(gen, false); /* 占位，OVRENH=0 时无效 */
            PWM_OverrideDataLowSet (gen, false); /* OVRDATL = 0 */
            PWM_OverrideLowEnable  (gen);        /* OVRENL = 1 */
            PWM_OverrideHighDisable(gen);        /* OVRENH = 0 */
            break;

        case PWM_HOFF_LON:
            /* 上桥 PWMxH 强制关，下桥 PWMxL 强制常通 */
            PWM_OverrideDataHighSet(gen, false); /* OVRDATH = 0 */
            PWM_OverrideDataLowSet (gen, true);  /* OVRDATL = 1 */
            PWM_OverrideHighEnable (gen);        /* OVRENH = 1 */
            PWM_OverrideLowEnable  (gen);        /* OVRENL = 1 */
            break;

        case PWM_HOFF_LOFF:
        default:
            /* 上下桥均强制关 */
            PWM_OverrideDataHighSet(gen, false); /* OVRDATH = 0 */
            PWM_OverrideDataLowSet (gen, false); /* OVRDATL = 0 */
            PWM_OverrideHighEnable (gen);        /* OVRENH = 1 */
            PWM_OverrideLowEnable  (gen);        /* OVRENL = 1 */
            break;
    }
}

/* STOPPED 硬关: 三相 PWM_HOFF_LOFF (H=0,L=0 强制) */
void PWM_AllOff(void) {
    PWM_SetPhaseMode(PWM_GENERATOR_1, PWM_HOFF_LOFF);
    PWM_SetPhaseMode(PWM_GENERATOR_2, PWM_HOFF_LOFF);
    PWM_SetPhaseMode(PWM_GENERATOR_3, PWM_HOFF_LOFF);
}

/* BOOTSTRAP: 三相 PWM_HOFF_LON (H=0 强制关, L=1 强制常通)。
 */
void PWM_HighOffLowOn(void) {
    PWM_SetPhaseMode(PWM_GENERATOR_1, PWM_HOFF_LON);
    PWM_SetPhaseMode(PWM_GENERATOR_2, PWM_HOFF_LON);
    PWM_SetPhaseMode(PWM_GENERATOR_3, PWM_HOFF_LON);
}

void PWM_HighPwmLowOff(void) {
    PWM_SetPhaseMode(PWM_GENERATOR_1, PWM_HPWM_LOFF);
    PWM_SetPhaseMode(PWM_GENERATOR_2, PWM_HPWM_LOFF);
    PWM_SetPhaseMode(PWM_GENERATOR_3, PWM_HPWM_LOFF);
}

