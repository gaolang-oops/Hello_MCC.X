/*
 * rotor_angle.c
 *
 * 转子电角度观测实现。
 * 50µs ADC tick 对 HALL_GetThetaStep() 的 16.16 增量积分，
 * 每个 Hall 沿用 HALL_GetHallRotorPosition() 重同步。
 * 无有效 dt 或距上次 Hall 沿超过 ROTOR_ANGLE_TIMEOUT_MS 时冻结（step=0），
 * 避免停转后旧 step 继续把角度积分走。
 *
 * 本模块只维护角度，不碰驱动/PWM，也不判断故障。
 */

#include "rotor_angle.h"
#include "hall_speed_fdbk.h"
#include <stdbool.h>

/* 32 位累加器与高 16 位整数角共享存储（dsPIC33E 小端）：
 *   part.frac  = 低 16 位（1/65536 brad16）
 *   part.whole = 高 16 位（整数 brad16），16 位原子读
 * 跨低位进位瞬间最多差 1 LSB（0.0055°），对角度/调试可忽略。 */
typedef union {
    volatile uint32_t u32;          /* 16.16 brad16 累加器 */
    struct {
        volatile uint16_t frac;     /* 低 16 位：小数 */
        volatile uint16_t whole;    /* 高 16 位：整数 brad16 */
    } part;
} RotorTheta_t;

typedef struct {
    RotorTheta_t      theta;        /* 电气角累加器/影子共用存储 */
    volatile uint16_t edge_anchor;  /* 本次 Hall 沿的绝对电角度 */
    volatile bool     edge_pending; /* Hall 沿待重同步 */
} RotorAngle_t;

static RotorAngle_t s_angle;

/* 30° brad16 = 65536/12，静止时用扇区中点作为初始角 */
#define ROTOR_ANGLE_SECTOR_HALF   5461u

/* 距上次 Hall 沿超过此时间视为停转，冻结角度 */
#define ROTOR_ANGLE_TIMEOUT_MS    200u

/* 上电初始化：Hall 种子读取后调用，用当前扇区中点作为初始角。 */
void RotorAngle_Init(void) {
    uint16_t pos = HALL_GetHallRotorPosition();

    s_angle.edge_pending = false;
    s_angle.edge_anchor  = 0u;

    if (pos == HALL_ANGLE_INVALID) {
        s_angle.theta.u32 = 0u;
    } else {
        /* 静止时转子在扇区内位置未知，用扇区中点作为初值：
         * FWD 进入沿是下边界 -> +30°；REV 进入沿是上边界 -> -30°。 */
        uint16_t center = (HALL_GetCmdDirection() == HALL_DIR_REV)
                        ? (uint16_t)(pos - ROTOR_ANGLE_SECTOR_HALF)
                        : (uint16_t)(pos + ROTOR_ANGLE_SECTOR_HALF);
        s_angle.theta.u32 = ((uint32_t)center) << 16;
    }
}

/* Hall 沿回调（IC ISR）：只发布锚点，实际重同步在 50µs tick 内完成。 */
void RotorAngle_OnHallEdge(uint8_t hall) {
    (void)hall;
    /* 先写锚点，再置 pending；50µs tick 只在 pending=true 时读取。 */
    s_angle.edge_anchor  = HALL_GetHallRotorPosition();
    s_angle.edge_pending = true;
}

/* 50µs ADC tick：积分 + Hall 沿重同步 + 超时冻结。 */
void RotorAngle_Tick50us(void) {
    HALL_StepQ16_t step;
    uint16_t dt_ticks;

    if (s_angle.edge_pending) {
        s_angle.edge_pending = false;
        s_angle.theta.u32 = ((uint32_t)s_angle.edge_anchor) << 16;
    }

    step = HALL_GetThetaStep();
    dt_ticks = HALL_GetEdgeDtTicks();
    if (dt_ticks == 0u || HALL_MsSinceLastEdge() > ROTOR_ANGLE_TIMEOUT_MS) {
        step = 0;   /* 速度尚未建立或 Hall 长时间无沿：冻结角度 */
    }

    s_angle.theta.u32 += (uint32_t)step;
}

uint16_t RotorAngle_GetRotor16(void) {
    return s_angle.theta.part.whole;   /* 16 位单字读，原子 */
}
