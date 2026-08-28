/*
 * bsp_freq.h
 *
 * PWM 频率母参数与派生常量集中管理(BSP 层)。
 *
 * 设计思想("单一母宏 + 编译期派生链"):
 *   全工程只有 BSP_PWM_FREQUENCY_HZ 一个真正的"自由度",
 *   其余(PHASE 半周期计数、PWM 周期计数、1ms 分频系数、占空比满量程、
 *   tick 换算)都是它的函数,全部用 #define 在编译期求值,零运行时开销。
 *
 * 与 mcc_generated_files/pwm.c 的关系:
 *   MCC 生成的 PHASE1/2/3 寄存器值无法宏化(重生成会覆盖手改),
 *   故本头派生值与 PHASE1 是两条独立计算路径。
 *   BSP_FREQ_Verify() 在启动期断言二者一致——若 MCC GUI 改了频率/PLL/预分频
 *   却忘了同步本头,启动期原地卡死(VERIFY 死循环),调试器可立即捕获。
 *
 * 分层归属:
 *   - BSP 层(bsp_adc.c / bsp_freq.c)直接 include 本头
 *   - motor 层经 mc_services.h 间接获取
 *   - 应用层(main.c)直接 include,用于调用 BSP_FREQ_Verify()
 */

#ifndef BSP_FREQ_H
#define BSP_FREQ_H

#include <stdint.h>
#include "clock.h"   /* _XTAL_FREQ(MCC 提供,Fosc)——周期值派生自它 */

#ifdef __cplusplus
extern "C" {
#endif

/* ============ 母参数(唯一真值源) ============
 * 全工程只有 BSP_PWM_FREQUENCY_HZ 一个真正的"自由度",
 * 周期计数由它 + _XTAL_FREQ(MCC) 编译期派生,其余量再从周期派生。
 *
 * BSP_PWM_FREQUENCY_HZ    PWM 开关频率(Hz),与 MCC PWM 配置一致
 *
 * !! 同步规则 !!
 *   在 MCC GUI 改 PWM 频率/PLL/PCLKDIV 并重新生成后,必须同步本宏,
 *   否则 BSP_FREQ_Verify() 会令启动期死循环。
 */
#define BSP_PWM_FREQUENCY_HZ        20000UL   /* 20 kHz,与 MCC PWM 配置一致 */

/* ============ PHASE 寄存器值(中心对齐半周期) ============
 * 中心对齐模式(公式 14-2): PHASE = Fosc / (Fpwm x 预分频 x 2)。
 * 140MHz/20kHz/2 = 3500,即 PHASE1/2/3 寄存器值(MCC 写入 0xDAC)。
 */
#define BSP_PWM_PHASE_TICKS         ((uint16_t)((_XTAL_FREQ) / (2UL * BSP_PWM_FREQUENCY_HZ)))

/* ============ PWM 物理周期计数(派生) ============
 * 中心对齐实际周期 = 2 x PHASE,50us @ 20kHz。
 * 仅供时长显示/换算,不是寄存器值;寄存器校验用 BSP_PWM_PHASE_TICKS。
 */
#define BSP_PWM_PERIOD_TICKS        ((uint16_t)(2UL * BSP_PWM_PHASE_TICKS))

/* ============ 时基派生(ADC ISR 频率 == PWM 频率) ============
 * ADC 由 PWM1 TRIG1 硬件触发,每 PWM 周期采样一次。
 * 此时 ADC ISR 频率 == PWM 频率,是整个系统的主节拍源。
 */
#define BSP_TICKS_PER_MS            (BSP_PWM_FREQUENCY_HZ / 1000UL)     /* 20: 1ms 含多少 PWM 周期 */
#define BSP_MS_PER_500MS            500UL                               /* 500ms 含多少 ms */

/* ============ 占空比刻度派生(满量程 = PHASE 寄存器值) ============
 * 中心对齐下占空比 = PDCx / PHASEx,3500 = 100%。
 * MIN/MAX 留电机启动死区(下限)与死区时间余量(上限)。
 *
 * !! 16 位溢出防护 !!
 *   XC16 的 int/unsigned 都是 16 位。BSP_DUTY_FULLSCALE × BSP_DUTY_MAX_PCT
 *   = 3500 × 95 = 332500 > 65535,直接乘会溢出。
 *   必须先 (uint32_t) 提升到 32 位再乘,最后 cast 回 uint16_t。
 *   编译期常量折叠,无运行时开销。
 */
#define BSP_DUTY_FULLSCALE          (BSP_PWM_PHASE_TICKS)               /* 3500: 100%*/
#define BSP_DUTY_MIN_PCT            5U                                  /* 占空下限百分比 */
#define BSP_DUTY_MAX_PCT            95U                                 /* 占空上限百分比 */
#define BSP_DUTY_MIN                ((uint16_t)(((uint32_t)BSP_DUTY_FULLSCALE * BSP_DUTY_MIN_PCT) / 100U))
#define BSP_DUTY_MAX                ((uint16_t)(((uint32_t)BSP_DUTY_FULLSCALE * BSP_DUTY_MAX_PCT) / 100U))

/* ============ 死区(MCC 侧配置) ============
 * 中心对齐互补模式下死区仅由 ALTDTRx 插入,DTRx 不参与(MCC 写 0)。
 * 死区分辨率 = TOSC = 1/Fosc;MCC 配置 ALTDTR = 280 -> 280/140MHz = 2.0us。
 */

/* ============ 物理时长 → PWM tick 换算 ============
 * 供上层声明"我需要 X μs"的快保护/时序常量。
 * 入参为编译期常量时,整个表达式在编译期求值,无运行时除法。
 */
#define BSP_US_TO_PWM_TICKS(us)     ((uint16_t)(((uint32_t)(us) * BSP_PWM_FREQUENCY_HZ) / 1000000UL))

/* ============ 启动期对齐检查 ============
 * 在 SYSTEM_Initialize() 之后、INTERRUPT_GlobalEnable() 之前调用一次。
 * 若 MCC 写入的 PHASE1 与母宏 BSP_PWM_PHASE_TICKS 不一致,VERIFY 死循环;
 */
void BSP_FREQ_Verify(void);

#ifdef __cplusplus
}
#endif

#endif /* BSP_FREQ_H */
