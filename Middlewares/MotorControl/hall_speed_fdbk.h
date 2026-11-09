/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef HALL_SPEED_FDBK_H
#define	HALL_SPEED_FDBK_H

#include <stdint.h>
#include <stdbool.h>

typedef void (*HallEdgeCallback_t)(uint8_t hall);
void     HALL_Init(void);                 /* 含种子读取 + 经 mc_services 注册 ISR */
uint8_t  HALL_GetHallStatus(void);
void     HALL_RegisterOnEdge(HallEdgeCallback_t cb);

/* ============ 方向 / Hall 转子位置（电角度） ============ */

/* Hall 非法态(000/111)对应的角度哨兵值 */
#define HALL_ANGLE_INVALID   0xFFFFu

/* 电机旋转方向。正转: Hall 5→4→6→2→3→1；反转: Hall 1→3→2→6→4→5。
 *
 * 本模块区分两个方向：
 *   - 命令方向(cmd)：控制层期望的旋转方向，决定 HALL_GetThetaStep() 的符号；
 *   - 实测方向(meas)：由相邻两次合法 Hall 跳变自动判别，仅供监督/诊断。
 * 两者暂不做一致性判定（换相/故障逻辑后续接入）。
 */
typedef enum {
    HALL_DIR_FWD = 0,   /* 正转 */
    HALL_DIR_REV = 1,   /* 反转 */
} HALL_Dir_e;

/* 实测方向：Hall 沿自动判别。无有效跳变时保持上次值。
 * 仅用于监督/诊断，不参与 HALL_GetThetaStep() 的符号。 */
HALL_Dir_e HALL_GetMeasuredDirection(void);

/* 命令方向：控制层期望的旋转方向，默认 HALL_DIR_FWD。
 * 决定 HALL_GetThetaStep() 的符号；由控制层（状态机/协议）设置。
 * 并发：主循环写、Hall ISR 读，单字写原子。 */
HALL_Dir_e HALL_GetCmdDirection(void);
void       HALL_SetCmdDirection(HALL_Dir_e dir);

/* 当前 Hall 状态对应的转子位置（brad16：0~65535 ⇔ 0~360°）。该 Hall 扇区瞬间的绝对位置（进入沿）。
 * 本接口按命令方向(cmd)选表：与 HALL_GetThetaStep() 的积分方向保持同一参考系，
 * 供每 Hall 沿重同步 theta 使用。
 *   正转 5[210°]→4[270°]→6[330°]→2[30°]→3[90°]→1[150°]
 *   反转 1[210°]→3[150°]→2[90°]→6[30°]→4[330°]→5[270°]
 * 返回 HALL_ANGLE_INVALID 表示当前 Hall 非法(0/7)。 */
uint16_t HALL_GetHallRotorPosition(void);

/* 最近最多 6 个有效跨通道 60° 间隔的滑动平均（T3CLK tick，当前 3657ns/tick）。
 *   每个合法 Hall 边沿更新一次；漏沿 120° 时先用 dt/2 归一到 60°；
 *   启动阶段为已收集样本的平均，满 6 个后固定为 6 样本平均。
 *   若本次捕获溢出/积压/间隔异常，保留上一次平均值不覆盖。
 *   结果按最高转速钳位：dt 不小于 HALL_DT_MAX_SPEED_TICKS（342 tick，
 *   对应 4000 rpm @ p=2），因此 HALL_GetThetaStep() 也不会超过该转速。
 *   0 = 尚未建立或已被 ResetEdgeTimer 清零。
 * 消费方须结合 HALL_MsSinceLastEdge() 判断数据是否新鲜（停机后旧值会保留）。 */
uint16_t HALL_GetEdgeDtTicks(void);

/* 每 PWM 周期电角度增量（16.16 定点，有符号）：
 *   高 16 位 = 整数 brad16/PWM，低 16 位 = 1/65536 brad16 小数。
 *   符号由命令方向(cmd)决定：FWD > 0，REV < 0（二进制补码）；
 *   实测方向(meas)不参与本符号，仅用于监督/诊断。
 *
 * 累加必须用无符号累加器：theta_u32 += (uint32_t)step;
 *   —— 有符号加法溢出是 C 的未定义行为；无符号加法则是模 2^32 的良定义回卷。
 *
 * 需要拆整数/小数时：whole = step >> 16; frac = step & 0xFFFFu;
 *   负数时 whole 是向下取整（floor），frac 恒为非负的小数部分，
 *   即 value = whole + frac/65536。
 */
typedef int32_t HALL_StepQ16_t;

/* 钳位后的滑动平均 60° dt 对应的每 PWM 角度增量（16.16，已按命令方向应用符号）。
 *   命令方向 FWD -> 正值，REV -> 负值（二进制补码）。
 *   消费方统一 theta_u32 += (uint32_t)step 即可。
 *   无效/溢出/超窗/尚未建立时保持上一次值。 */
HALL_StepQ16_t HALL_GetThetaStep(void);

/* 调试用：返回每 PWM 角度增量公式中的常数 K（brad16 每 T3 tick）。
 * 当前配置（Fcy=70MHz、Fpwm=20kHz、T3 1:256）下应为 149333。 */
uint32_t HALL_GetStepK(void);

/* 速度反馈(速度环接缝,预留):
 * 返回电机转速 RPM,基于 HALL_GetEdgeDtTicks() 换算。
 * 本次仅占位返回 0,实际测速算法待加速度环时实现。
 * 消费方: Tier-2(1ms) 调用,经 MC_Ramp_SetTargetProvider 注入速度 PI 输出。 */
uint16_t HALL_GetSpeedRpm(void);

/* 距上次合法 Hall 边沿经过的时间(ms)。供堵转检测/速度有效性判断。
 * 0 表示刚发生边沿;值越大说明电机越慢或停转。 */
uint16_t HALL_MsSinceLastEdge(void);

/* 重置"距上次边沿"计时基准为当前时刻。进入 RUNNING 态前调用,
 * 避免长时间停机后重启误报 HALL_TIMEOUT(详见 .c 实现注释)。 */
void HALL_ResetEdgeTimer(void);

/* TODO: 极对数 POLE_PAIR_NUM 须在实现 GetSpeedRpm 前定义 */


#endif	/* HALL_SPEED_FDBK_H */

