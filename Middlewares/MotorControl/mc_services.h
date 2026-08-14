/*
 * mc_services.h
 *
 * Motor 层的平台服务门面（平台接缝）。
 * motor 层所有需要"时间 / 外设输入 / 延时"的模块，只 include 本头，
 * 不直接触碰 Drivers/BSP 或 mcc_generated_files。
 *
 *   state_machine       ──┐
 *   pwm_common          ──┤
 *   hall_speed_fdbk     ──┤
 *   MC_Fault            ──┼──→ mc_services ──→ BSP / mcc
 *   mc_ramp             ──┘
 *
 * 收敛于此的好处：
 *   - motor 层可整体移植 / 单元测试（mock mc_services 即可）
 *   - 单位换算与 raw 判定（raw→mA、过流 raw 比较）全部封装在 BSP 层，
 *     本头只做纯转发；motor 层只见到物理量(mA/mV)与语义结果(bool)，
 *     不感知 raw / 标定常量（偏置点、增益、换算系数）的存在
 *   - 硬件标定参数定义于 bsp_adc.h，换板子改 BSP 一份即可
 */

#ifndef MC_SERVICES_H
#define MC_SERVICES_H

#include <stdint.h>
#include <stdbool.h>
#include "../../Drivers/BSP/bsp_freq.h"   /* PWM 母参数派生的数值宏(BSP_TICKS_PER_MS / BSP_US_TO_PWM_TICKS 等)。
                                           * 本头仅含数值宏,无 BSP 类型,不破坏"不暴露 BSP 类型"原则。
                                           * motor 层经此接缝获取,不直接 include Drivers/BSP。 */
#ifdef __cplusplus
extern "C" {
#endif

/* ============ 时基 ============ */

/* tmr3 1ms 自由运行时基（自举充电计时 / 缓变节拍）。16-bit 回卷，消费方须用差值判断 */
uint16_t MC_GetTickMs(void);

/* ADC 50us 快时基（与 PWM/ADC 同步，供 blanking 等快保护判定）。16-bit 回卷，用差值 */
uint16_t MC_GetTick50us(void);

/* 注册 50us ADC ISR 回调（Tier-1 快保护入口，如过流检测）。
 * 回调在 ISR 内执行，须短小。注册动作应在全局中断使能前完成。 */
void MC_RegisterTick50us(void (*cb)(void));

/* 阻塞精确延时（10μs 单位，用于 MOSFET 关断裕量等硬件时序）。
 * 前置条件：全局中断已使能（实现基于 BSP 定时器 tick）*/
void MC_Delay10us(uint16_t n);

/* 微秒 → 快时基 tick 数(与 MC_GetTick50us 同源,1 tick = 1 个 PWM 周期)。
 * 供 blanking/采样窗等"物理时长 → tick"换算。
 * !! 仅限编译期常量入参 —— 否则 /1000000 会引入运行时除法。
 *    编译期入参时整个表达式常量折叠,零运行时开销(详见 bsp_freq.h)。 */
#define MC_US_TO_PWM_TICKS(us)   BSP_US_TO_PWM_TICKS(us)

/* ============ 工程单位采样值 ============
 * int16_t，单位 mA（安培×1000），已减 1.65V 偏置，0 = 无电流。
 * raw→mA 换算（含标定常量）在 bsp_adc.c 实现，本层仅转发，
 */
int16_t  MC_GetCurrentIamA(void);
int16_t  MC_GetCurrentIbmA(void);
int16_t  MC_GetCurrentIcmA(void);
int16_t  MC_GetCurrentIbusmA(void);

/* ============ 过流保护（OCP）语义接口 ============
 * 对 motor 层只暴露物理量(mA)与判定结果(bool)，raw 换算/比较封装在 BSP 层。
 *   Configure —— 初始化时调用一次，传入过流阈值(mA)；内部预计算 raw 比较值。
 *   IsPhaseOver / IsIbusOver —— 过流判定；可在 ISR 热路径调用，零运行时换算。
 * 相电流双向判定（Ia/Ib/Ic 任一越限），Ibus 单向判定（仅上限）。 */
void MC_OC_Configure(uint16_t threshold_mA);
bool MC_OC_IsPhaseOver(void);
bool MC_OC_IsIbusOver(void);

/* 母线电压（mV）。供慢保护（过压/欠压）判定 */
uint16_t MC_GetVbusMv(void);

/* ============ 指令输入 ============ */

/* 读旋钮请求值并映射为占空比指令（电机启停/缓变的目标值来源）*/
uint16_t MC_GetKnobDuty(void);

/* ============ Hall ============ */

/* 读 3 路 Hall 引脚电平（bit2=U bit1=V bit0=W）。去抖 / 合法态判断由消费方负责 */
uint8_t MC_Hall_ReadStatus(void);

/* 注册 IC ISR 统一处理函数（三路 IC 中断触发同一 handler） */
void MC_Hall_RegisterIsr(void (*handler)(void));

#ifdef __cplusplus
}
#endif

#endif /* MC_SERVICES_H */
