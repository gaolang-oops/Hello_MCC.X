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
#ifndef BSP_GPIO_H
#define	BSP_GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.  
#ifdef __cplusplus
extern "C" {
#endif

    // TODO Insert declarations

    typedef enum {
        LED0 = 0,
        LED1,
        LED2,
        LED3,
        LED_CNT
    } LED_Name_e;

    typedef enum {
        KEY0 = 0,
        KEY1,
        KEY2,
        KEY_CNT
    } KEY_Name_e;

    // GPIO 配置结构体

    typedef struct {
        uint8_t idx; // 序号
        const char *pin_name; // 引脚名称
        volatile uint16_t *tris; // 方向寄存器
        volatile uint16_t *port; // 输入寄存器
        volatile uint16_t *lat; // 输出锁存寄存器
        volatile uint16_t *ansel; // 模拟功能寄存器
        uint8_t bit_pos; // 引脚BIT位
        uint8_t active_level; // 有效电平
    } GPIO_Config_t;


    // 外部配置数组声明
    extern const GPIO_Config_t LED_Config[LED_CNT];
    extern const GPIO_Config_t KEY_Config[KEY_CNT];
    // 函数声明
    void GPIO_Configure_LEDS(void);
    void LED_On(LED_Name_e led);
    void LED_Off(LED_Name_e led);
    void LED_Toggle(LED_Name_e led);
    void LED_On_All(void);
    void LED_Off_All(void);
    const char* LED_Get_PinName(LED_Name_e led);

    void GPIO_Configure_KEYS(void);
    uint8_t KEY_Get_State(KEY_Name_e key);
    int8_t KEY_Scan_All(void); // 扫描所有按键，返回状态
#ifdef __cplusplus
}
#endif
#endif	/* BSP_GPIO_H */

