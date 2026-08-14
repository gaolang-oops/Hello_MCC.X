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
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdint.h>
#include <stdbool.h>
#include "mc_ramp.h"
#include "MC_Fault.h"   /* Motor_Handle_t.fault 字段类型 */

/* 自举电容预充电时长（计时职责归状态机，故宏定义于此）*/
#define BOOTSTRAP_CHARGE_MS         50U

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
    MOTOR_STATE_STOPPED = 0,   // 停机：硬关 6 管(PWM_AllOff)，等待 KEY0 允许
    MOTOR_STATE_FAULT,         // 故障吸收态：任意态+fault 进入；仅外部清故障可转出→STOPPED
    MOTOR_STATE_BOOTSTRAP,     // 瞬态：PWM_HighOffLowOn 三相下管常通，立即迁移到 CHARGING
    MOTOR_STATE_CHARGING,      // 稳态：等待自举电容充电 50ms 完成
    MOTOR_STATE_READY,         // 就绪：充电完成，PWM 使能，等旋钮指令；超时回 STOPPED
    MOTOR_STATE_RUNNING,       // 运行：按指令占空比输出
} Motor_State_e;

#define READY_TIMEOUT_MS    30000U

/* 应用层 → 状态机 的一次性命令（对齐 ST MCSDK DirectCommand 思想）。
 * 应用层（按键/协议）写，状态机每拍快照后清零消费 —— 状态机不写回，
 * 重启须显式再次下发 START（故障清除 / 超时后自动 re-arm，无电平残留）。 */
typedef enum {
    MOTOR_CMD_NONE  = 0,   /* 空命令 */
    MOTOR_CMD_START,       /* 请求启动（KEY0 短按）→ 仅 STOPPED 态响应 */
    MOTOR_CMD_STOP,        /* 请求停机（KEY1 短按）→ 立即硬关 PWM + 清占空比 → STOPPED */
} Motor_Cmd_e;

/*
 * 电机统一句柄（聚合各子模块状态入口）
 * 静态模块（static 变量）通过指针/快照方式挂入此处。
 *
 * 约束：
 *   - 本结构是【只读诊断视图】，真值仍由各子模块的 static 变量持有。
 *   - 严禁通过本结构写真值；任何状态变更必须经各子模块 API。
 *   - Motor_GetHandle() 仅允许在主循环（Tier-2/Tier-3）上下文调用，
 *     禁止在 ISR 内调用（多字段非原子快照，存在读撕裂风险）。
 */
typedef struct {
    /* —— 状态机层 —— */
    Motor_State_e  state;          /* 状态机当前状态 */
    /* —— 子模块指针（视图，不拥有） —— */
    Ramp_Handle_t *ramp;           /* 占空比缓变句柄指针 */
    /* —— 子模块快照（GetHandle 时刷新） —— */
    MC_Fault_e     fault;          /* 故障位图（全锁存，只读视图） */
    uint8_t        hall_status;    /* 当前 Hall 状态 */
    bool           six_step_en;    /* 六步换相闸门 */
    uint16_t       target_duty;    /* 目标占空比（旋钮/速度PI 输出） */
    uint16_t       current_duty;   /* 实际占空比（缓变后） */
    uint16_t       last_edge_age_ms; /* 距上次 Hall 边沿 ms（堵转观测） */
} Motor_Handle_t;

void Motor_Init(void);                 // 单一入口，内部包装全部 motor 层子模块初始化
void Motor_Tick(void);                 // 1ms 节拍推进状态机（Tier-2 控制层，由主循环调用）
void Motor_SetCommand(Motor_Cmd_e cmd);// 应用层下发一次性命令（START/STOP），状态机消费即清零

/* 获取电机统一句柄（快照方式，调试/监控用）*/
Motor_Handle_t* Motor_GetHandle(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MOTOR_CONTROL_H */


