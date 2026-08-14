/*
 * mc_ramp.h
 *
 * 占空比缓变模块（控制策略层，纯软件，无硬件依赖）
 * 从 pwm_common 拆分而来：pwm_common 只管硬件寄存器，ramp 只管缓变策略。
 *
 * 依赖方向：mc_ramp → mc_services（时基/目标值） + pwm_common（写硬件）
 */

#ifndef MC_RAMP_H
#define MC_RAMP_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 缓变参数 -- 编译期默认值，运行时由结构体字段承载（可调） */
#define RAMP_STEP_BIG        400U    /* 差距>阈值 时的大步进 */
#define RAMP_STEP_SMALL       50U    /* 差距≤阈值 时的小步进 */
#define RAMP_THRESHOLD       400U    /* 大/小步进分界 */
#define RAMP_PERIOD_MS        50U    /* 缓变节拍周期(ms) */

/* 目标占空比的来源回调。返回 0~BSP_DUTY_MAX 的占空比指令。
 * - 默认实现: MC_GetKnobDuty()（旋钮直驱，开环）
 * - 速度环接入时: 替换为速度 PI 调节器输出，无需改 MC_Ramp_Step
 * 注入点 = MC_Ramp_SetTargetProvider，状态机之外可热切换 */
typedef uint16_t (*Ramp_TargetProvider_t)(void);

typedef struct {
    uint16_t target_duty;      /* 目标占空比（旋钮请求） */
    uint16_t current_duty;     /* 当前占空比（软件影子，权威值） */
    uint16_t step_big;
    uint16_t step_small;
    uint16_t threshold;
    uint16_t ramp_period_ms;
    uint16_t last_tick_ms;     /* 上次缓变时间戳 */
} Ramp_Handle_t;

/* 初始化：占空比清零，时基种子同步 */
void MC_Ramp_Init(void);

/* 一步缓变：差距>阈值用大步进，否则小步进，防过冲 clamp
 * 每个主循环调用一次，内部自行判节拍是否到点 */
void MC_Ramp_Step(void);

/* 获取当前占空比（软件影子，权威值） */
uint16_t MC_Ramp_GetCurrentDuty(void);

/* 强制清零占空比（停机用，直接写硬件 + 清影子） */
void MC_Ramp_ForceZero(void);

/* 获取缓变句柄指针（供 Motor_Handle_t 聚合） */
Ramp_Handle_t* MC_Ramp_GetHandle(void);

/* 设置目标占空比来源（速度环接缝）。
 * provider=NULL 视为非法，忽略不切换。
 * 默认指向 MC_GetKnobDuty（旋钮直驱）。 */
void MC_Ramp_SetTargetProvider(Ramp_TargetProvider_t provider);

#ifdef __cplusplus
}
#endif

#endif /* MC_RAMP_H */
