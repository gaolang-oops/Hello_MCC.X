/*
 * File:   bsp_gpio.c
 * Author: gaol
 *
 * Created on 2026年5月21日, 下午3:41
 */


#include "bsp_gpio.h"
#include <stdio.h>
#include "../../user_manager.h"
#include "delay.h"

// LED 配置数组
const GPIO_Config_t LED_Config[LED_CNT] = {
    [LED0] =
    {.idx = LED0, .pin_name = "RE12", .tris = &TRISE, .port = &PORTE, .lat = &LATE, .ansel = &ANSELE, .bit_pos = 12, .active_level = 0},
    [LED1] =
    {.idx = LED1, .pin_name = "RE13", .tris = &TRISE, .port = &PORTE, .lat = &LATE, .ansel = &ANSELE, .bit_pos = 13, .active_level = 0},
    [LED2] =
    {.idx = LED2, .pin_name = "RE14", .tris = &TRISE, .port = &PORTE, .lat = &LATE, .ansel = &ANSELE, .bit_pos = 14, .active_level = 0},
    [LED3] =
    {.idx = LED3, .pin_name = "RE15", .tris = &TRISE, .port = &PORTE, .lat = &LATE, .ansel = &ANSELE, .bit_pos = 15, .active_level = 0},
};

// 按键配置
// KEY0 -> RC1
// KEY1 -> RC2
// KEY2 -> RC11
// 按下 = 低电平 active_level = 0
const GPIO_Config_t KEY_Config[KEY_CNT] = {
    [KEY0] =
    {.idx = KEY0, .pin_name = "RC1", .tris = &TRISC, .port = &PORTC, .lat = &LATC, .ansel = &ANSELC, .bit_pos = 1, .active_level = 0},
    [KEY1] =
    {.idx = KEY1, .pin_name = "RC2", .tris = &TRISC, .port = &PORTC, .lat = &LATC, .ansel = &ANSELC, .bit_pos = 2, .active_level = 0},
    [KEY2] =
    {.idx = KEY2, .pin_name = "RC11", .tris = &TRISC, .port = &PORTC, .lat = &LATC, .ansel = &ANSELC, .bit_pos = 11, .active_level = 0},
};

// 单个 LED 初始化

static void GPIO_SECTION LED_Init(LED_Name_e led) {
    if (led >= LED_CNT) return;
    const GPIO_Config_t *pCfg = &LED_Config[led];
    // 配置为输出
    *pCfg->tris &= ~(1U << pCfg->bit_pos);
    //printf("LED%d [%s]: tris = 0x%04X (Output Mode)\n", pCfg->idx, pCfg->pin_name, *pCfg->tris);

    // 配置为数字功能
    *pCfg->ansel &= ~(1U << pCfg->bit_pos);
    //printf("LED%d [%s]: ansel = 0x%04X (Digital Mode)\n", pCfg->idx, pCfg->pin_name, *pCfg->ansel);

    // 默认熄灭
    if (pCfg->active_level == 0)
        *pCfg->lat |= (1U << pCfg->bit_pos);
    else
        *pCfg->lat &= ~(1U << pCfg->bit_pos);
    //printf("LED%d [%s]: lat = 0x%04X (Default OFF)\n\n", pCfg->idx, pCfg->pin_name, *pCfg->lat);
}

// 全部初始化

void GPIO_SECTION GPIO_Configure_LEDS(void) {
    //printf("=== LED Initialization Start ===\n");
    //printf("Before Init - tris=0x%04X, ansel=0x%04X, lat=0x%04X\n", TRISE, ANSELE, LATE);

    for (uint8_t i = 0; i < LED_CNT; i++) {
        LED_Init(i);
    }
    //printf("After Init - tris=0x%04X, ansel=0x%04X, lat=0x%04X\n", TRISE, ANSELE, LATE);
    //printf("=== LED Initialization Complete ===\n");

}
// 点亮单个 LED

void GPIO_SECTION LED_On(LED_Name_e led) {
    if (led >= LED_CNT) return;
    const GPIO_Config_t *pCfg = &LED_Config[led];
    if (pCfg->active_level == 0)
        *pCfg->lat &= ~(1U << pCfg->bit_pos);
    else
        *pCfg->lat |= (1U << pCfg->bit_pos);
}

// 熄灭单个 LED

void GPIO_SECTION LED_Off(LED_Name_e led) {
    if (led >= LED_CNT) return;
    const GPIO_Config_t *pCfg = &LED_Config[led];
    if (pCfg->active_level == 0)
        *pCfg->lat |= (1U << pCfg->bit_pos);
    else
        *pCfg->lat &= ~(1U << pCfg->bit_pos);
}

// 翻转 LED

void GPIO_SECTION LED_Toggle(LED_Name_e led) {
    if (led >= LED_CNT) return;
    const GPIO_Config_t *pCfg = &LED_Config[led];
    *pCfg->lat ^= (1U << pCfg->bit_pos);
}

// 全亮

void GPIO_SECTION LED_On_All(void) {
    for (uint8_t i = 0; i < LED_CNT; i++) LED_On(i);
}

// 全灭

void GPIO_SECTION LED_Off_All(void) {
    for (uint8_t i = 0; i < LED_CNT; i++) LED_Off(i);
}

// 获取引脚名

const char* GPIO_SECTION LED_Get_PinName(LED_Name_e led) {
    if (led >= LED_CNT) return "ERROR";
    return LED_Config[led].pin_name;
}


// 单个按键初始化

static void GPIO_SECTION KEY_Init(KEY_Name_e key) {
    if (key >= KEY_CNT) return;
    const GPIO_Config_t *pCfg = &KEY_Config[key];

    *pCfg->tris |= (1U << pCfg->bit_pos); // 输入模式
    *pCfg->ansel &= ~(1U << pCfg->bit_pos); // 数字模式
}

// 全部初始化

void GPIO_SECTION GPIO_Configure_KEYS(void) {
    for (uint8_t i = 0; i < KEY_CNT; i++) {
        KEY_Init(i);
    }
}

// 获取按键状态（根据 active_level 判断是否按下）

uint8_t GPIO_SECTION KEY_Get_State(KEY_Name_e key) {
    if (key >= KEY_CNT) return 1;
    const GPIO_Config_t *pCfg = &KEY_Config[key];
    uint8_t now_state = (((*pCfg->port) >> pCfg->bit_pos) & 0x01);

    // 与有效电平相同 = 按下
    return (now_state == pCfg->active_level) ? 0 : 1;
}

// 带消抖扫描所有按键
// 返回值：KEY0 / KEY1 / KEY2  表示按下对应按键
// 返回：-1  无按键按下

int8_t GPIO_SECTION KEY_Scan_All(void) {
    for (uint8_t i = 0; i < KEY_CNT; i++) {
        // 检测到按下
        if (KEY_Get_State(i) == 0) {
            Delay_ms(20); // 消抖延时

            // 再次确认按下
            if (KEY_Get_State(i) == 0) {
                // 等待松手
                while (KEY_Get_State(i) == 0);
                Delay_ms(20);
                return i; // 返回按键序号
            }
        }
    }
    return -1;
}
