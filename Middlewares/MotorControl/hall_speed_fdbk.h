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

