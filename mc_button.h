/*
 * mc_button.h
 *
 * 按键输入模块（应用层 UI 接口 → 电机控制）。
 * 非阻塞消抖，1ms 节拍调用。
 *
 * 按键分工（下发一次性命令，状态机消费即清零）：
 *   KEY0 (RC1)  短按/长按 → 正转启动命令（MOTOR_CMD_START_FWD）
 *   KEY1 (RC2)  短按/长按 → 反转启动命令（MOTOR_CMD_START_REV）
 *   KEY2 (RC11) 短按       → 停机命令（MOTOR_CMD_STOP，电机硬停）
 *   KEY2 (RC11) 长按≥2s    → 清故障（MC_ClearAllFaults）
 *
 * 换向规则：启动命令仅 STOPPED 态响应；运行中按 KEY0/KEY1 被忽略，
 * 必须先 KEY2 停机，再按 KEY0/KEY1 选择方向（转动过程不做反向）。
 * 若硬停后转子仍在原方向惰行，状态机会在 READY 自动等转子停稳
 * （Hall 边沿静默 REV_EDGE_QUIET_MS）后再锁存新方向并启动，无需重复按键。
 * 同拍多键时 STOP 优先（处理顺序 KEY0→KEY1→KEY2，末写胜）。
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
