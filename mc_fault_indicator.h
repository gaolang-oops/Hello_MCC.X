/*
 * mc_fault_indicator.h
 *
 * 故障 LED 指示模块
 *
 * 背景:"现场操作员(无串口)"场景,补充视觉指示通道。
 *
 * LED 职责划分:
 *   - LED1:主循环存活心跳(主循环 500ms 翻转,卡死时冻住=告警)
 *   - LED3:专用故障闪烁(本模块,主循环 1ms 驱动)
 *
 * 指示策略(LED3):
 *   - 无故障:(心跳职责 LED0)
 *   - 有故障:编码闪烁轮播,每种故障对应闪烁次数:
 *       1 次 = OVER_CURRENT   2 次 = OVER_VOLTAGE   3 次 = UNDER_VOLTAGE
 *       4 次 = OVERLOAD       5 次 = HALL_INVALID   6 次 = HALL_TIMEOUT
 *       7 次 = OVER_TEMP
 *     规则:闪 N 次 = bit(N-1),可由位号直接推出。
 *     节奏: [N x (200ms亮 + 200ms灭)] + 1200ms 沉降,循环;
 *     多重故障按位序低 -> 高轮播,现场可逐项诊断。
 *
 * 实现约束:
 *   - 非阻塞:1ms 软件计时器驱动状态机,严禁 Delay_ms
 *   - 仅在主循环 1ms 分支调用 Tick1ms;模块 static 变量无 ISR 竞态
 *   - 读 MC_GetFault()(volatile uint16_t 原子)
 */

#ifndef MC_FAULT_INDICATOR_H
#define MC_FAULT_INDICATOR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 初始化:熄灭 LED3,状态机归零。
 * 须在 GPIO_Configure_LEDS 之后调用。 */
void MCFaultIndicator_Init(void);

/* 1ms 节拍驱动:故障闪烁状态机。
 * 由主循环 1ms 分支调用,非阻塞。
 * 无故障 -> LED3 灭;有故障 -> 编码闪烁轮播。 */
void MCFaultIndicator_Tick1ms(void);

#ifdef __cplusplus
}
#endif

#endif /* MC_FAULT_INDICATOR_H */
