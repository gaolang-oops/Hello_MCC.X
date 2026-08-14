/*
 * mc_button.h
 *
 * 按键输入模块（应用层 UI 接口 → 电机控制）。
 * 非阻塞消抖，1ms 节拍调用。
 *
 * 按键分工（下发一次性命令，状态机消费即清零）：
 *   KEY0 (RC1)  短按 → 启动命令（MOTOR_CMD_START）
 *   KEY1 (RC2)  短按 → 停机命令（MOTOR_CMD_STOP，电机硬停）
 *   KEY2 (RC11) 长按≥2s → 清故障（MC_ClearAllFaults）
 *
 * 依赖方向(向下):
 *   mc_button -> bsp_gpio（KEY_Get_State）
 *   mc_button -> motor_control（Motor_SetCommand）
 *   mc_button -> MC_Fault（MC_ClearAllFaults）
 */

#ifndef MC_BUTTON_H
#define MC_BUTTON_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BTN_DEBOUNCE_MS     20U
#define BTN_LONG_PRESS_MS   2000U

void MCButton_Init(void);
void MCButton_Tick1ms(void);

#ifdef __cplusplus
}
#endif

#endif /* MC_BUTTON_H */
