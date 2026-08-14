#ifndef BSP_TIMER_H
#define BSP_TIMER_H
#include <stdint.h>

/* 初始化：注册 TMR3 中断回调，启动 10μs 软件 tick。
 * 前置条件：SYSTEM_Initialize() 已执行。
 */
void BSP_Timer_Init(void);

/* 阻塞延时（10μs 单位）。基于 TMR3 10μs 中断软件 tick。
 * 前置条件：INTERRUPT_GlobalEnable() 已执行（否则 tick 不推进 -> 死等）。
 * 参数 n：10μs 的倍数
 * 调用示例：BSP_Timer_Delay10us(50) = 500μs
 */
void BSP_Timer_Delay10us(uint16_t n);

/* 阻塞延时（ms 级）。基于 s_tick_ms（10μs tick 100 分频）。
 * 前置条件：同 Delay10us。
 * 参数 ms
 */
void BSP_Timer_DelayMs(uint16_t ms);

/* 时间戳工具*/
uint16_t BSP_Timer_NowUs(void);               /* 10μs 单位 */
uint16_t BSP_Timer_NowMs(void);               /* 1ms 单位 */
uint16_t BSP_Timer_ElapsedMs(uint16_t start);
#endif