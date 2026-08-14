/*
 * File:   bsp_timer.c
 * Author: gaol
 *
 * Created on July 20, 2026, 5:22 PM
 */


#include "bsp_timer.h"
#include "tmr3.h"
#include "../../user_manager.h"

static volatile uint16_t s_tick_10us = 0;
static volatile uint16_t s_tick_ms   = 0;
static uint16_t s_10us_div = 0;       /* 100 -> 1ms */

static void TIMER_SECTION bsp_tmr3_isr(void) {
    s_tick_10us++;
    if (++s_10us_div >= 100U) { s_10us_div = 0U; s_tick_ms++; }
}

void TIMER_SECTION BSP_Timer_Init(void) {
    TMR3_SetInterruptHandler(&bsp_tmr3_isr);
}

void TIMER_SECTION BSP_Timer_Delay10us(uint16_t n) {
    uint16_t start = s_tick_10us;
    while ((s_tick_10us - start) < n) {
    }
}

void TIMER_SECTION BSP_Timer_DelayMs(uint16_t ms) {
    uint16_t start = s_tick_ms;
    while ((s_tick_ms - start) < ms) {
    }
}

uint16_t TIMER_SECTION BSP_Timer_NowUs(void)     { return s_tick_10us; }
uint16_t TIMER_SECTION BSP_Timer_NowMs(void)     { return s_tick_ms; }
uint16_t TIMER_SECTION BSP_Timer_ElapsedMs(uint16_t start) {
    return (s_tick_ms - start);
}