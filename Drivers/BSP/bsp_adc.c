/*
 * File:   bsp_adc.c
 * Author: gaol
 *
 * Created on June 1, 2026, 3:57 PM
 */

#include "bsp_adc.h"
#include "bsp_gpio.h"
#include "adc1.h"

#include "../../user_manager.h"

#include <stdlib.h>   /* abs() */
/*CH0 轮询3个通道，需依据硬件修改 */
#define ADC_CH0_SLOT_COUNT 	3
static const uint8_t s_ch0AnMap[ADC_CH0_SLOT_COUNT] = {3, 4, 6};
static uint8_t s_ch0Slot = 0;
//adc采集的数据
static volatile ADC_Data_t s_adcData = {0};

//时基变量
static volatile uint16_t s_tick50us = 0;   /* 自由运行 50us 滴答 */
static volatile uint16_t s_tickMs   = 0;   /* 自由运行 ms 滴答 */

static volatile bool s_flag50us  = false;
static volatile bool s_flag1ms   = false;
static volatile bool s_flag500ms = false;

static uint16_t s_s50usCounter = 0;   /* 50us -> 1ms 累加 */
static uint16_t s_msCounter    = 0;   /* 1ms -> 500ms 累加 */

/* 多槽回调表：允许多模块共存注册，按注册顺序在 ISR 内执行。
 * 仅限初始化期(中断使能前)注册，无并发保护；槽满 VERIFY 停机暴露配置错误。 */
static ADC_TimeBase_Callback_t s_cb50us[BSP_ADC_CB50US_MAX];
static ADC_TimeBase_Callback_t s_cb1ms[BSP_ADC_CB1MS_MAX];
static uint8_t s_cb50usCnt = 0;
static uint8_t s_cb1msCnt  = 0;

/*
 * 系统时基源 = ADC 中断（PWM 同步触发 @ 20kHz -> 50us 周期）。
 * ADC 中断每 50us 调用 BSP_ADC_TimeBase_Tick()，
 * 内部分频产生 50us / 1ms / 500ms 节拍。
 * 消费方可选：
 *   1) 标志位 + 自由运行 tick 计数器（主循环轮询/差值比较）
 *   2) 回调注册（多槽共存，在 ISR 内按注册顺序直接调用，须短小）
 */
void ADC_SECTION BSP_ADC_TimeBase_Tick(void) {
	uint8_t i;

	/* ---- 50us 时基（每个 ISR） ---- */
	s_tick50us++;
	s_flag50us = true;
	for (i = 0; i < s_cb50usCnt; i++) {
		s_cb50us[i]();
	}

	/* ---- 1ms 时基：每 20 个 50us ---- */
	if (++s_s50usCounter >= BSP_TICKS_PER_MS) {
		s_s50usCounter = 0;
		s_tickMs++;
		s_flag1ms = true;
		for (i = 0; i < s_cb1msCnt; i++) {
			s_cb1ms[i]();
		}

		/* ---- 500ms 慢节拍 ---- */
		if (++s_msCounter >= BSP_MS_PER_500MS) {
			s_msCounter = 0;
			s_flag500ms = true;
		}
	}

}

//50us
bool ADC_SECTION BSP_ADC_TimeBase_Is50usFlag(void)
{
	return s_flag50us;
}

void ADC_SECTION BSP_ADC_TimeBase_Clear50usFlag(void)
{
	s_flag50us = false;
}

uint16_t ADC_SECTION BSP_ADC_TimeBase_GetTick50us(void)
{
	return s_tick50us;
}

//1ms
bool ADC_SECTION BSP_ADC_TimeBase_Is1msFlag(void)
{
	return s_flag1ms;
}

void ADC_SECTION BSP_ADC_TimeBase_Clear1msFlag(void)
{
	s_flag1ms = false;
}

uint16_t ADC_SECTION BSP_ADC_TimeBase_GetTickMs(void)
{
	return s_tickMs;
}

//500ms
bool ADC_SECTION BSP_ADC_TimeBase_Is500msFlag(void)
{
	return s_flag500ms;
}

void ADC_SECTION BSP_ADC_TimeBase_Clear500msFlag(void)
{
	s_flag500ms	= false;
}

//callback
/* 多槽注册：找空槽写入。仅限初始化期(中断使能前)调用，无并发保护 */
void ADC_SECTION BSP_ADC_TimeBase_Register50us(ADC_TimeBase_Callback_t cb)
{
	VERIFY(s_cb50usCnt < BSP_ADC_CB50US_MAX);
	s_cb50us[s_cb50usCnt++] = cb;
}

void ADC_SECTION BSP_ADC_TimeBase_Register1ms(ADC_TimeBase_Callback_t cb)
{
	VERIFY(s_cb1msCnt < BSP_ADC_CB1MS_MAX);
	s_cb1ms[s_cb1msCnt++] = cb;
}

static void ADC_SECTION ADC_InterruptHandler(void) {
#define VBUS_SMA_N				64
#define VBUS_SMA_SHIFT			6
#define KNOB_SMA_N				8
#define KNOB_SMA_SHIFT			3
	
	static uint32_t s_vbusSum = 0;
	static uint8_t	s_vbusIdx = 0;
	static bool 	s_vbusInited = false;
	
	static uint32_t s_knobSum = 0;
	static uint8_t	s_knobIdx = 0;
	static bool 	s_knobInited = false;
	/* ISR 观测点:LED1 低电平有效,Off=引脚拉高(灭)——进入中断,执行窗起点 */
	// LED_Off(LED1);   
    /* CH1/CH2/CH3 始终有效 */
    s_adcData.raw_ia = ADC1BUF1;
    s_adcData.raw_ib = ADC1BUF2;
    s_adcData.raw_ic = ADC1BUF3;
	
    /* CH0 根据 slot 读取，需依据硬件修改 */
	/* 批平均：每 N 个样本输出一次均值，期间 flt 冻结。适用于低频检查（≥10ms）的保护场景。 */
    switch (s_ch0Slot) {
        case 0:
            s_adcData.raw_vbus = ADC1BUF0;
			if(s_vbusInited) {
				s_vbusSum += s_adcData.raw_vbus;
				s_vbusIdx ++;
				if(s_vbusIdx >= VBUS_SMA_N) {
					s_adcData.flt_vbus = s_vbusSum >> VBUS_SMA_SHIFT;
					s_vbusSum = 0;
					s_vbusIdx = 0;
				}
			}
			else {
				s_adcData.flt_vbus = s_adcData.raw_vbus;
				s_vbusInited = true;
			}
			
            break;
        case 1:
            s_adcData.raw_knob = ADC1BUF0;
			if(s_knobInited) {
				s_knobSum += s_adcData.raw_knob;
				s_knobIdx ++;
				if(s_knobIdx >= KNOB_SMA_N) {
					s_adcData.flt_knob = s_knobSum >> KNOB_SMA_SHIFT;
					s_knobSum = 0;
					s_knobIdx = 0;
				}
			}
			else {
				s_adcData.flt_knob = s_adcData.raw_knob;
				s_knobInited = true;
			}
            break;
        case 2:
            s_adcData.raw_ibus = ADC1BUF0;
            break;
        default:
            break;
    }
    /* 切换到下一个 slot，配置下次 CH0 采样通道 */
    if (++s_ch0Slot >= ADC_CH0_SLOT_COUNT) {
        s_ch0Slot = 0;
    }
    AD1CHS0 = s_ch0AnMap[s_ch0Slot];
	//时基
	BSP_ADC_TimeBase_Tick();
	/* 退出中断点灯:引脚拉低(亮)。高电平宽=ISR 执行时长,
	 * 整周期=ISR 周期(50us -> ADC=20kHz)
	 */
	//LED_On(LED1);    
}
//ADC interrupt function registration
void ADC_SECTION BSP_ADC_Int_Register(void)
{
	/*设定CH0轮询的初始通道*/
    s_ch0Slot = 0;
    AD1CHS0 = s_ch0AnMap[0];
    ADC1_SetInterruptHandler(&ADC_InterruptHandler);
}

const volatile ADC_Data_t * ADC_SECTION BSP_ADC_GetData(void)
{
    return &s_adcData;
}

uint16_t ADC_SECTION BSP_ADC_KnobToDuty(void)
{
    /* 步骤1: 归一化为 UQ0.16 —— 16位无符号定点, 表示 [0, 1) 比例
     *        flt_knob<<6 == flt_knob/1024 × 65536, 把ADC读数映射到 [0,1) */
    uint16_t norm_uq0_16 = s_adcData.flt_knob << 6;
    /* 步骤2: 反归一化 —— norm/65536 × PWM周期 */
	uint16_t duty = __builtin_muluu(norm_uq0_16, BSP_DUTY_FULLSCALE) >> 16;
    /* 步骤3: 限幅 [BSP_DUTY_MIN, BSP_DUTY_MAX] */
    if (duty < BSP_DUTY_MIN) duty = 0;
    if (duty > BSP_DUTY_MAX) duty = BSP_DUTY_MAX;
    return duty;
}

uint16_t ADC_SECTION BSP_ADC_GetVbusMv(void)
{
    /* Vbus(mV) = flt_vbus × 3300 × 16 / 1024 */
    /* Vbus(mV) = flt_vbus × 52,800 / 1024 */
	return __builtin_muluu(s_adcData.flt_vbus, VBUS_FACTOR) >> 10;
}

/* raw → mA：减 1.65V 偏置 → abs 取幅值 → __builtin_muluu 单周期乘法 → 移位 → 恢复符号
 * 例：raw=987(满量) → diff=+475 → mA=475×3234>>9=3000 → +3000
 *     raw=37 (反向满量)→ diff=-475 → mA=3000 → -3000
 * abs 返回 int(XC16 16-bit)，diff 范围 [-512, +511]，无溢出风险。 */
static int16_t ADC_SECTION RawToMa(uint16_t raw)
{
    int16_t  diff = (int16_t)raw - (int16_t)ADC_CURRENT_MIDPOINT;
    uint16_t mag  = (uint16_t)abs(diff);
    uint16_t mA   = (uint16_t)(__builtin_muluu(mag, ADC_CURRENT_K) >> ADC_CURRENT_SHIFT);
    return (diff < 0) ? -(int16_t)mA : (int16_t)mA;
}

int16_t ADC_SECTION BSP_ADC_GetCurrentIaMa(void)   { return RawToMa(s_adcData.raw_ia); }
int16_t ADC_SECTION BSP_ADC_GetCurrentIbMa(void)   { return RawToMa(s_adcData.raw_ib); }
int16_t ADC_SECTION BSP_ADC_GetCurrentIcMa(void)   { return RawToMa(s_adcData.raw_ic); }

/* Ibus 单极性换算：GND 参考无偏置，0A → raw=0，故不减中点、不取符号翻转。
 * 例：raw=0   → mA=0    （静止）
 *     raw=310 → mA=999  （约 1A）
 *     raw=931 → mA=3000 （满量 3A） */
static int16_t ADC_SECTION RawToMaIbus(uint16_t raw)
{
    return (int16_t)(__builtin_muluu(raw, ADC_CURRENT_K_IBUS) >> ADC_CURRENT_SHIFT);
}
int16_t ADC_SECTION BSP_ADC_GetCurrentIbusMa(void) { return RawToMaIbus(s_adcData.raw_ibus); }

/* ============ "标定预计算" 过流保护（OCP）封装 ============
 * 设计：mA 阈值在 Configure 时一次性换算为 raw 比较值（含除法，仅启动期），
 *       ISR 热路径 Is* 仅做 raw 与常量的字面量比较，零运行时换算。
 *       保护层无需知晓 raw/标定细节。 */
static uint16_t s_oc_phase_hi = 0xFFFFu;   /* 相电流 raw 上限（默认安全态：永不越限）*/
static uint16_t s_oc_phase_lo = 0x0000u;   /* 相电流 raw 下限 */
static uint16_t s_oc_ibus_hi  = 0xFFFFu;   /* Ibus raw 上限 */

void ADC_SECTION BSP_ADC_OC_Configure(uint16_t threshold_mA)
{
    uint16_t delta = ADC_MA_TO_PHASE_RAWDELTA(threshold_mA);
    s_oc_phase_hi = ADC_CURRENT_MIDPOINT + delta;
    s_oc_phase_lo = ADC_CURRENT_MIDPOINT - delta;
    s_oc_ibus_hi  = ADC_MA_TO_IBUS_RAW(threshold_mA);
}

bool ADC_SECTION BSP_ADC_OC_IsPhaseOver(void)
{
    /* 相电流双向偏置：越限 = raw > HI 或 raw < LO（关于中点对称）*/
    uint16_t ia = s_adcData.raw_ia;
    uint16_t ib = s_adcData.raw_ib;
    uint16_t ic = s_adcData.raw_ic;
    return (ia > s_oc_phase_hi || ia < s_oc_phase_lo ||
            ib > s_oc_phase_hi || ib < s_oc_phase_lo ||
            ic > s_oc_phase_hi || ic < s_oc_phase_lo);
}

bool ADC_SECTION BSP_ADC_OC_IsIbusOver(void)
{
    /* Ibus 单极性无偏置：越限 = raw > HI（仅上限）*/
    return (s_adcData.raw_ibus > s_oc_ibus_hi);
}


