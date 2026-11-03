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

/* 电机旋转方向：由相邻两次合法 Hall 跳变自动判别。
 *   正转: Hall 5→4→6→2→3→1
 *   反转: Hall 1→3→2→6→4→5
 */
typedef enum {
    HALL_DIR_FWD = 0,   /* 正转 */
    HALL_DIR_REV = 1,   /* 反转 */
} HALL_Dir_e;

/* 当前方向。无有效跳变时保持上次/预置值。 */
HALL_Dir_e HALL_GetDirection(void);

/* 预置方向（静止/启动时用命令方向做种子，运行后由 Hall 沿自动校正）。
 * 并发：主循环与 Hall ISR 均可能写，单字写为原子操作。 */
void HALL_SetDirection(HALL_Dir_e dir);

/* 当前 Hall 状态对应的转子位置（brad16：0~65535 ⇔ 0~360°）。该 Hall 扇区瞬间的绝对位置（进入沿）。
 * 正/反转分别查表：
 *   正转 5[210°]→4[270°]→6[330°]→2[30°]→3[90°]→1[150°]
 *   反转 1[210°]→3[150°]→2[90°]→6[30°]→4[330°]→5[270°]
 * 返回 HALL_ANGLE_INVALID 表示当前 Hall 非法(0/7)。 */
uint16_t HALL_GetHallRotorPosition(void);

/* 速度反馈(速度环接缝,预留):
 * 返回电机转速 RPM,基于相邻两次合法 Hall 边沿的时间戳差换算。
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

