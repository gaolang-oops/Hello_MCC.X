/*
 * rotor_angle.h
 *
 * 转子电角度观测（Hall 沿重同步 + 50µs 16.16 积分）。
 *
 * 职责：
 *   - Hall 跳变时发布绝对角锚点（IC ISR 上下文）
 *   - 50µs tick 消费锚点做重同步，并按 HALL_GetThetaStep() 积分
 *   - 无有效 dt 或长时间无 Hall 沿时冻结，避免停转后角度继续走
 *
 * 依赖方向：rotor_angle → hall_speed_fdbk → mc_services → BSP
 * 不依赖 six_step / spwm / MC_Fault。
 *
 * 并发：
 *   Hall 回调在 IC ISR 写 anchor/pending（16 位原子写），
 *   50µs 回调在 ADC ISR 消费；SPWM 构建下 AD1 > IC，ADC 不会被 IC 打断。
 *   HALL_UpdateStep 的 32 位 step 写入侧已有临界区，避免撕裂读。
 */

#ifndef ROTOR_ANGLE_H
#define ROTOR_ANGLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 初始化：须在 HALL_Init()（种子读取）之后调用。
 * 用当前 Hall 扇区中点作为静止时的初始角：
 *   FWD 进入沿 +30°，REV 进入沿 −30°。 */
void RotorAngle_Init(void);

/* Hall 沿回调（注册到 HALL_RegisterOnEdge，IC ISR 内执行）：
 * 只发布绝对角锚点，实际重同步在 RotorAngle_Tick50us() 内完成。 */
void RotorAngle_OnHallEdge(uint8_t hall);

/* 50µs ADC tick：Hall 沿重同步 + 16.16 角度积分 + 超时冻结。
 * 须在 ADC 50µs 回调中调用。 */
void RotorAngle_Tick50us(void);

/* 当前转子电角度（整数 brad16，0~65535 ⇔ 0~360°）。
 * 高 16 位单字读，原子。 */
uint16_t RotorAngle_GetRotor16(void);

#ifdef __cplusplus
}
#endif

#endif /* ROTOR_ANGLE_H */
