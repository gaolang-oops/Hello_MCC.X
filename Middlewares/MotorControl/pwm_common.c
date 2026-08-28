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

/* 单相写占空比（SPWM 每相独立调制）。满量程 = BSP_DUTY_FULLSCALE = PHASE(3500) = 100%。 */
void PWM_SetDutyPhase(PWM_GENERATOR gen, uint16_t duty) {
    PWM_DutyCycleSet(gen, duty);
}

/* 三相同步写占空比：PDCx 双缓冲、IUE=0，同一 ISR 内三写
 * 在同一 PWM 周期边界同步生效，天然保持三相 SPWM 对称性。 */
void PWM_SetDuty_UVW(uint16_t du, uint16_t dv, uint16_t dw) {
    PWM_DutyCycleSet(PWM_GENERATOR_1, du);
    PWM_DutyCycleSet(PWM_GENERATOR_2, dv);
    PWM_DutyCycleSet(PWM_GENERATOR_3, dw);
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

        case PWM_HPWM_LPWM:
            /* 双桥均交还 PWM 互补自主控制(SPWM 运行态)。
             * OVRDAT 保持 00(此前 HOFF_LOFF 状态已写)，直接全关 OVREN。
             * 交接瞬间输出从"H=0/L=0"跳到互补波形(PDC=0 时为 H=0/L=通)，
             * 调用方应先置好 PDC 再调用(见 PWM_HandOffToPwm)。 */
            PWM_OverrideHighDisable(gen);        /* OVRENH = 0 */
            PWM_OverrideLowDisable(gen);         /* OVRENL = 0 */
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

/* SPWM 运行态入口：三相从"上电强制全关"(MCC 配置 IOCON=0xC300)
 * 交还 PWM 模块互补自主控制。
 * 调用约定：
 *   1) 先经 PWM_SetDutyPhase/PWM_SetDuty_UVW 置好各相 PDC(默认 0=占空 0%, 交接后为 H 断/L 通)；
 *   2) 本函数仅切 Override，不碰 PDC/死区/触发；
 *   3) 故障/停机仍走 PWM_AllOff(强制关，优先级高于自主控制)。 */
void PWM_HandOffToPwm(void) {
    PWM_SetPhaseMode(PWM_GENERATOR_1, PWM_HPWM_LPWM);
    PWM_SetPhaseMode(PWM_GENERATOR_2, PWM_HPWM_LPWM);
    PWM_SetPhaseMode(PWM_GENERATOR_3, PWM_HPWM_LPWM);
}

