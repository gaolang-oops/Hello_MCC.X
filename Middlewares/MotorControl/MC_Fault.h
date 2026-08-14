/*
 * MC_Fault.h
 *
 * 故障管理模块(motor 层)
 *
 * 职责:
 *   - 集中管理所有故障标志(过流/过压/欠压/过温)
 *   - Tier-1 过流检测:50us ADC ISR 回调,工程单位(mA)判定
 *   - 换相 blanking 屏蔽期:避免六步换相电流尖峰误触发
 *
 * 依赖方向: MC_Fault -> mc_services -> BSP
 *   经 mc_services 读 ADC 数据
 *   过流回调由 MC_Fault_Init 经 mc_services 自注册到 50us tick
 *
 * 故障标志单向流(避免竞态):
 *   - ISR (Hall/ADC) 只写 (MC_SetFault / MC_NotifyCommutation)
 *   - 主循环 Tier-2 只读 (MC_HasAnyFault)
 *   - 全锁存策略:不清零不停机;清除途径见 MC_Fault_Init / MC_ClearAllFaults 说明
 *
 * 单位约定:
 *   - s16A = int16_t, 单位 mA(安培×1000),范围 ±32767 mA
 *   - 阈值用 mA 表达,便于台架标定(阈值 = 安培 × 1000)
 */

#ifndef MC_FAULT_H
#define MC_FAULT_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 故障类型位图（按位独立，可 OR 组合查询多重故障）
 * 数值取 2 的幂：便于 (flags & FAULT_X) 位测试与多故障并发记录。
 */
typedef enum {
    MC_FAULT_NONE          = 0,
    MC_FAULT_OVER_CURRENT  = (1u << 0),   /* bit0 过流：瞬时短路/堵转 */
    MC_FAULT_OVER_VOLTAGE  = (1u << 1),   /* bit1 过压：母线电压超限 */
    MC_FAULT_UNDER_VOLTAGE = (1u << 2),   /* bit2 欠压：母线电压过低 */
    MC_FAULT_OVERLOAD      = (1u << 3),   /* bit3 持续过载/堵转：电流长时间超额定 */
    MC_FAULT_HALL_INVALID  = (1u << 4),   /* bit4 霍尔非法状态(000/111)：三线卡死/供电丢失 */
    MC_FAULT_HALL_TIMEOUT  = (1u << 5),   /* bit5 霍尔信号丢失：运行中长时间无合法跳变 */
    MC_FAULT_OVER_TEMP     = (1u << 6),   /* bit6 过温：MOS/环境温度超限 */
    
} MC_Fault_e;

/* 模块初始化：清标志（冷启动干净态）+ 经 mc_services 注册 50us 过流回调。
 * 调用时机：由 Motor_Init 统一编排（顺序：BSP_ADC_Int_Register 之后、GlobalEnable 之前）。
 *           "之后"是推荐而非硬性，因为 s_cb50us 静态初始化为 NULL，任何时刻注册都安全。 */
void MC_Fault_Init(void);

/* ---- 标志位管理（全锁存策略） ----
 * 置位：ISR（MC_OverCurrentCheck / MC_NotifyCommutation）写。
 * 读取：Motor_Tick（1ms 主循环）调 MC_HasAnyFault。
 * 清除：仅 MC_Fault_Init（冷启动）或外部命令（如 UART 协议"清故障"帧）。
 *       状态机 STOPPED 不再自动清零 —— 避免持续短路时的反复重启打嗝烧 MOS。
 * MC_SetFault/MC_ClearFault 含读-改-写，已用 SET_AND_SAVE_CPU_IPL(7) 关中断
 * 临界区保护（主循环/ADC ISR/Hall ISR 上下文均安全）；
 * MC_ClearAllFaults/HasAnyFault/GetFault 为纯 store/load，16 位原子无需保护。 */
void       MC_SetFault(MC_Fault_e f);
void       MC_ClearFault(MC_Fault_e f);
void       MC_ClearAllFaults(void);
bool       MC_HasAnyFault(void);
MC_Fault_e MC_GetFault(void);

/* 换相通知:Hall 换相时调用,启动 blanking 屏蔽期。
 * 调用上下文: Hall ISR(优先级 7) 或 主循环(SIXSTEP_Enable)
 * 读方: ADC ISR(优先级 6);优先级差保证无竞态。 */
void MC_NotifyCommutation(void);

/* Tier-1 过流检测回调(50us ADC ISR 内执行)。
 * 由 MC_Fault_Init 自注册,不应被其它代码直接调用。
 * 逻辑: blanking 内跳过;否则四路电流双向偏差判定,超限则:
 *   ① SIXSTEP_Enable(false)         ISR 内立即硬关 PWM + 失能换相闸门(响应 ≤50us)
 *   ② MC_SetFault(OVER_CURRENT)     置标志,状态机 FAULT 态接管后续(锁存/拒绝重启)
 * 响应延迟要求 μs 级(过流 1ms 足以烧 MOS),故不等 1ms 状态机。
 * 与 Hall ISR 并发安全:s_enabled 单字节原子;Override 终态都是关断。 */
void MC_OverCurrentCheck(void);

/* L2 慢保护:母线电压检查(1ms 状态机层调用,非 ISR)。
 * 判定: flt_vbus > OV_THRESHOLD_MV -> OVER_VOLTAGE;
 *       flt_vbus < UV_THRESHOLD_MV -> UNDER_VOLTAGE。
 * 动作: 仅 MC_SetFault;关断交状态机 FAULT 态(本拍置标志,下拍关 PWM,延迟 <1ms)。
 *       母线电容钳位,电压变化 10ms+,ms 级响应足够,不需 ISR 抢 μs 级。 */
void MC_Fault_CheckVoltage(void);

/* L2 慢保护:持续过载/堵转检查(1ms 状态机层调用,非 ISR)。
 * 判定: Ibus 经一阶 IIR 低通(τ≈128ms)后 > OVERLOAD_THRESHOLD_MA -> OVERLOAD。
 * 动作: 仅 MC_SetFault;交状态机 FAULT 态接管(ms 级响应,发热是慢过程)。
 * 与 Tier-1 过流(瞬时短路,μs 级)互补:堵转时电流可能始终不超瞬时阈值,却持续发热烧 MOS
 */
void MC_Fault_CheckOverload(void);

/* L2 慢保护:霍尔信号有效性检查(1ms 状态机层调用,非 ISR)。
 * 判定: motor_running 且 hall_age_ms > HALL_TIMEOUT_MS -> HALL_TIMEOUT。
 * hall_age_ms 由调用方经 HALL_MsSinceLastEdge() 获取后传入,
 * 避免 MC_Fault 反向依赖 hall_speed_fdbk(保持 MC_Fault -> mc_services -> BSP 单向依赖)。
 * 动作: 仅 MC_SetFault;交状态机 FAULT 态接管(ms 级响应,信号丢失是慢过程)。
 * 与 HALL_INVALID(霍尔非法状态 000/111,ISR 内检测)互补:
 *   HALL_INVALID 捕获三线卡死;HALL_TIMEOUT 捕获运行中信号丢失/堵转。 */
void MC_Fault_CheckHall(uint16_t hall_age_ms, bool motor_running);

#ifdef __cplusplus
}
#endif

#endif /* MC_FAULT_H */
