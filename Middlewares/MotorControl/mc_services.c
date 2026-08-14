/*
 * mc_services.c
 *
 * Motor 层平台服务门面实现：转发 BSP 工程单位接口给 motor 层。
 *   - raw 换算、过流 raw 判定、标定常量 全部封装在 BSP 层（bsp_adc.c）；
 *   - 本文件仅做纯转发，motor 层只见物理量(mA/mV)与语义结果(bool)。
 *   其余 motor 模块经此获取时基 / 工程单位采样值 / 指令输入 / 精确延时。
 *
 * 单位换算（raw→mA/mV/duty）全部在 BSP 层完成，与 BSP_ADC_GetVbusMv 同构。
 * 换板子/换采样链路时，标定参数改 bsp_adc.h 一份即可。
 */

#include "mc_services.h"
#include "../../Drivers/BSP/bsp_adc.h"
#include "../../Drivers/BSP/bsp_timer.h"
#include "../../Drivers/BSP/bsp_ICx.h"

uint16_t MC_GetTickMs(void) {
    return BSP_Timer_NowMs();
}

uint16_t MC_GetTick50us(void) {
    return BSP_ADC_TimeBase_GetTick50us();
}

void MC_RegisterTick50us(void (*cb)(void)) {
    BSP_ADC_TimeBase_Register50us(cb);
}

void MC_Delay10us(uint16_t n) {
    BSP_Timer_Delay10us(n);
}

/* 纯转发：raw→mA 换算在 BSP 层（BSP_ADC_GetCurrentXMa）*/
int16_t MC_GetCurrentIamA(void)   { return BSP_ADC_GetCurrentIaMa(); }
int16_t MC_GetCurrentIbmA(void)   { return BSP_ADC_GetCurrentIbMa(); }
int16_t MC_GetCurrentIcmA(void)   { return BSP_ADC_GetCurrentIcMa(); }
int16_t MC_GetCurrentIbusmA(void) { return BSP_ADC_GetCurrentIbusMa(); }

/* 纯转发：过流判定封装在 BSP 层（raw 比较 + 标定预计算）*/
void MC_OC_Configure(uint16_t threshold_mA) { BSP_ADC_OC_Configure(threshold_mA); }
bool MC_OC_IsPhaseOver(void)                { return BSP_ADC_OC_IsPhaseOver(); }
bool MC_OC_IsIbusOver(void)                 { return BSP_ADC_OC_IsIbusOver(); }

uint16_t MC_GetVbusMv(void) {
    return BSP_ADC_GetVbusMv();
}

uint16_t MC_GetKnobDuty(void) {
    return BSP_ADC_KnobToDuty();
}

uint8_t MC_Hall_ReadStatus(void) {
    return BSP_ICx_ReadHall();
}

void MC_Hall_RegisterIsr(void (*handler)(void)) {
    BSP_ICx_RegisterIsrHandler(handler);
}

