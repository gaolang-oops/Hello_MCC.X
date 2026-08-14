/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef BSP_ADC_H
#define	BSP_ADC_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdbool.h>
#include "bsp_freq.h"   /* PWM 母参数 + 时基/占空比派生宏(BSP_TICKS_PER_MS / BSP_DUTY_* / BSP_MS_PER_500MS) */
typedef struct {
    uint16_t raw_ia; /* AN0 → CH1 → BUF1 */
    uint16_t raw_ib; /* AN1 → CH2 → BUF2 */
    uint16_t raw_ic; /* AN2 → CH3 → BUF3 */
    uint16_t raw_vbus; /* AN3 → CH0 → BUF0 (slot 0) */
    uint16_t raw_knob; /* AN4 → CH0 → BUF0 (slot 1) */
    uint16_t raw_ibus; /* AN6 → CH0 → BUF0 (slot 2) */
	uint16_t flt_vbus;   /* SMA 滤波后 */
    uint16_t flt_knob;   /* SMA 滤波后 */
} ADC_Data_t;
/* 时基源 = ADC ISR(与 PWM 同步触发,频率 = BSP_PWM_FREQUENCY_HZ,见 bsp_freq.h)。
 *   1ms  = BSP_TICKS_PER_MS 个 PWM 周期
 *   500ms = BSP_MS_PER_500MS 个 ms
 * 占空比刻度(满量程/上下限)同样派生自 BSP_PWM_PERIOD_TICKS,见 bsp_freq.h。 */

/* 标定常量为 ADC 采样链路的硬件属性 */

/* VBUS(AN3) ADC值 → 真实母线电压 转换参数
 * ADC 参考电压 (3300mV)
 * 10-bit ADC 满量程 (2^10=1024)
 * 分压比: Vbus = Vadc × 16 (24V→1.5V)
*/
#define VBUS_FACTOR      52800U      /*3300*16=52800*/

/* ============ 相电流/母线电流 采样链路标定 ============
 * 硬件链路：I(±3A) → Rsense(0.02Ω, ±60mV) → 运放(G=25.5, ±1.53V)
 *          → 加 1.65V 偏置 → ADC(0.12V~3.18V, 10-bit → raw 37~987)
 *
 * 标定推导：
 *   raw 单边满量程 = (3.18-1.65)/3.3×1024 ≈ 475 ↔ 实际 3000 mA
 *   即 1 raw ≈ 3000/475 ≈ 6.316 mA
 *   取整系数 K=3234, SHIFT=9：|mA| = |raw - 512| × 3234 >> 9
 *     验证：475×3234 = 1536150, >>9 = 2999.7 mA（误差 < 0.01%）
 */
#define ADC_CURRENT_MIDPOINT      512U      /* 1.65V 对应的 raw 中点 */
#define ADC_CURRENT_K             3234U     /* 标定系数（替代除法） */
#define ADC_CURRENT_SHIFT         9         /* 移位数（÷512） */

/* ============ Ibus 母线电流采样链路标定（单极性，GND 参考，无偏置） ============
 * 硬件链路：I → Rsense(0.02Ω) → 运放(G=50) → ADC，无 1.65V 偏置
 *   V_adc = I × 0.02 × 50 = I × 1.0 V/A ; 0A → V_adc=0V → raw≈0（单极性）
 *
 * 标定推导：
 *   raw = I × 1.0 × 1024 / 3.3 = I × 310.3   (I 单位 A)
 *   即 1 mA ↔ raw 0.3103 ; 1 raw ↔ 3.2226 mA
 *   mA = raw × 3.2226 ≈ raw × 1650 >> 9   (1650/512 = 3.2227，误差 < 0.01%)
 *
 * 与相电流链路的差异：
 *   - 相电流: G=25.5, +1.65V 偏置, 双向 → mA = (raw - 512) × K >> SHIFT
 *   - Ibus  : G=50,  无偏置,    单向 → mA = raw × K_IBUS >> SHIFT (不减中点)
 *   两者 SHIFT 相同(=9)，仅 K 与是否减中点不同。
 */
#define ADC_CURRENT_K_IBUS        1650U     /* Ibus 标定系数（无偏置链路） */

/* mA → raw 反算：raw = mA × 2^SHIFT / K。
 * !! 仅限编译期常量入参；变量入参会引入运行时除法 !!
 * BSP 内部使用（过流阈值预计算）；motor 层不应直接引用。 */
#define ADC_MA_TO_PHASE_RAWDELTA(mA)  ((uint16_t)(((uint32_t)(mA) << ADC_CURRENT_SHIFT) / ADC_CURRENT_K))
#define ADC_MA_TO_IBUS_RAW(mA)        ((uint16_t)(((uint32_t)(mA) << ADC_CURRENT_SHIFT) / ADC_CURRENT_K_IBUS))

typedef void (*ADC_TimeBase_Callback_t)(void);


void BSP_ADC_Int_Register(void);
const volatile ADC_Data_t *BSP_ADC_GetData(void);

/* ---- 标志位 + 自由运行 tick ---- */
/* 50us 节拍：每个 ISR 置位，消费方需手动清零 */
bool     BSP_ADC_TimeBase_Is50usFlag(void);
void     BSP_ADC_TimeBase_Clear50usFlag(void);
uint16_t BSP_ADC_TimeBase_GetTick50us(void);

/* 1ms 节拍：每 20 个 ISR 置位，消费方需手动清零 */
bool     BSP_ADC_TimeBase_Is1msFlag(void);
void     BSP_ADC_TimeBase_Clear1msFlag(void);
uint16_t BSP_ADC_TimeBase_GetTickMs(void);

/* 500ms 慢节拍（从 1ms 派生） */
bool     BSP_ADC_TimeBase_Is500msFlag(void);
void     BSP_ADC_TimeBase_Clear500msFlag(void);

/* ---- 回调注册（在 ISR 内调用，须短小） ---- */
void BSP_ADC_TimeBase_Register50us(ADC_TimeBase_Callback_t cb);
void BSP_ADC_TimeBase_Register1ms(ADC_TimeBase_Callback_t cb);


uint16_t BSP_ADC_KnobToDuty(void); 
uint16_t BSP_ADC_GetVbusMv(void);

/* 相电流/母线电流（mA，有符号）。
 * 已减 1.65V 偏置、已按 ADC_CURRENT_K/SHIFT 换算为工程单位。
 * 返回 int16_t，0 = 无电流，正值/负值对应电流方向。
 * 对齐 BSP_ADC_GetVbusMv 的工程单位交付模式。 */
int16_t  BSP_ADC_GetCurrentIaMa(void);
int16_t  BSP_ADC_GetCurrentIbMa(void);
int16_t  BSP_ADC_GetCurrentIcMa(void);
int16_t  BSP_ADC_GetCurrentIbusMa(void);

/* ============ 过流保护（OCP）查询接口 ============
 * 封装 raw 换算与判定逻辑，对上层只暴露物理量(mA)/bool：
 *   Configure —— 初始化时调用一次，把 mA 阈值预计算为 raw 比较值（含一次除法，
 *                仅启动期开销）；相电流与 Ibus 共用同一阈值。
 *   Is*       —— ISR 热路径调用，仅做 raw 与预计算常量的字面量比较，
 *                无运行时除法/乘法/换算，响应 ≤50us。
 * 相电流为双向偏置（中点对称判定），Ibus 为单极性无偏置（仅上限判定）。
 * 默认未配置时为安全态（永不越限），须 Configure 后再使能过流检测。 */
void BSP_ADC_OC_Configure(uint16_t threshold_mA);
bool  BSP_ADC_OC_IsPhaseOver(void);
bool  BSP_ADC_OC_IsIbusOver(void);

#endif	/* BSP_ADC_H */

