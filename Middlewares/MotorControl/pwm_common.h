/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PWM_COMMON_H
#define	PWM_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "../../mcc_generated_files/pwm.h"  /* PWM_GENERATOR 类型（PWMC 原语签名需要）*/

/*
 * 每相工作模式（H-PWM / L-ON 方案）
 */
typedef enum {
    PWM_HOFF_LOFF = 0,  /* 上下桥均强制关                           (OVRENH=1, OVRDATH=0, OVRENL=1, OVRDATL=0) */
    PWM_HPWM_LOFF = 1,  /* 上桥 PWMxH 受 PWM 控制，下桥 PWMxL 强制关 (OVRENH=0,               OVRENL=1, OVRDATL=0) */
    PWM_HOFF_LON  = 2,  /* 上桥强制关，下桥强制常通                 (OVRENH=1, OVRDATH=0, OVRENL=1, OVRDATL=1) */
    PWM_HPWM_LPWM = 3,  /* 上下桥均交还 PWM 互补自主控制(SPWM 用)    (OVRENH=0,               OVRENL=0)        */
} PWM_PhaseMode_t;

/* 三相同步写占空比到硬件（纯寄存器操作，不维护软件影子） */
void PWM_SetDutyCycle(uint16_t duty);

/* 单相写占空比（SPWM 每相独立调制用）。duty 满量程 = BSP_DUTY_FULLSCALE(PHASE=3500)。 */
void PWM_SetDutyPhase(PWM_GENERATOR gen, uint16_t duty);

/* 三相同步写占空比（SPWM 调制节拍用）。
 * PDCx 双缓冲且 IUE=0，同一 ISR 内连续三写 -> 三相同一周期边界同步生效。 
 */
void PWM_SetDuty_UVW(uint16_t du, uint16_t dv, uint16_t dw);

/* ---- PWMC 核心原语（本层为 PWM 寄存器唯一所有者，单一职责：只碰寄存器）---- */
void PWM_SetPhaseMode(PWM_GENERATOR gen, PWM_PhaseMode_t mode); /* 单相 Override 唯一入口 */
void PWM_AllOff(void);             /* 三相强制关 6 管          */
void PWM_HighOffLowOn(void);        /* 三相下管常通(自举充电)    */
void PWM_HighPwmLowOff(void);
void PWM_HandOffToPwm(void);        /* 三相交还 PWM 互补自主控制(SPWM 运行态入口) */

#endif	/* PWM_COMMON_H */

