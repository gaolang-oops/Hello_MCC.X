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
#ifndef USER_MANAGER_H
#define	USER_MANAGER_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

// TODO If C++ is being used, regular C code needs function names to have C 
// linkage so the functions can be used by the c code. 

#define CORE_SECTION            __attribute__ ((section(".core_section")))
#define MAIN_SECTION            CORE_SECTION
#define MOTOR_SECTION           CORE_SECTION
#define TEST_SECTION            CORE_SECTION

#define BSP_SECTION             __attribute__ ((section(".bsp_section")))
#define GPIO_SECTION            BSP_SECTION
#define ICAP_SECTION            BSP_SECTION
#define UART_SECTION            BSP_SECTION
#define TIMER_SECTION           BSP_SECTION
#define ADC_SECTION           	BSP_SECTION

#define COMP_SECTION            __attribute__ ((section(".components_section")))

/* Interrupt manager */
//CPU中断优先级为5，可以响应用户中断6 7
#define ENIE()      SET_CPU_IPL(5)
#define DISIE()     SET_CPU_IPL(7)

// 宏功能：获取对应外设的中断优先级（返回 0~7）
#define INT_PRIORITY_U2E		_U2EIP	   // UART2 Error
#define INT_PRIORITY_U2TX		_U2TXIP    // UART2 TX
#define INT_PRIORITY_U2RX		_U2RXIP    // UART2 RX
#define INT_PRIORITY_IC1		_IC1IP	   // Input Capture 1
#define INT_PRIORITY_IC2		_IC2IP	   // Input Capture 2
#define INT_PRIORITY_IC3		_IC3IP	   // Input Capture 3
#define INT_PRIORITY_T3 		_T3IP	   // Timer3
#define INT_PRIORITY_PWM1		_PWM1IP    // PWM1
#define INT_PRIORITY_AD1		_AD1IP	   // ADC1 Convert Done

/* 永久运行时自检：失败则软断点 + 死循环（不受 NDEBUG 影响）。
 * 调试器连接时 __builtin_software_breakpoint() 原地停住，可直查变量/调用栈；
 * 无调试器时退化为 while(1)（不静默跑飞，便于现场定位）。 */
#define VERIFY(cond)                         	 \
		do										 \
		{										 \
			if (!(cond))						 \
			{									 \
				__builtin_software_breakpoint(); \
				while (1)						 \
				{								 \
				}								 \
			}									 \
		} while (0)

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* USER_MANAGER_H */

