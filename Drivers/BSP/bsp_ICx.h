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
#ifndef BSP_ICX_H
#define	BSP_ICX_H

#include "xc.h"

#ifdef	__cplusplus
extern "C" {
#endif

/* IC 硬件初始化：GPIO/PPS/ICxCON/IEC */
void BSP_ICx_HW_Init(void);

/*
 * Hall 引脚电平读取（去抖 / 合法态判断等 motor 域逻辑不在 BSP）。
 * 返回值位布局： bit2 = IC1 (RG8, Hall U)
 *               bit1 = IC2 (RG7, Hall V)
 *               bit0 = IC3 (RG6, Hall W)
 */
uint8_t BSP_ICx_ReadHall(void);

/*
 * IC ISR 桥：BSP 拥有 IC1/2/3_CallBack 强覆盖（压制 MCC 弱符号），
 * 上层经此注册统一处理函数；三路 IC 中断触发同一 handler（无 idx 区分）。
 * 注册前若偶发 Hall 沿，handler 为 NULL 时 no-op。
 */
typedef void (*BSP_ICx_IsrHandler_t)(void);
void    BSP_ICx_RegisterIsrHandler(BSP_ICx_IsrHandler_t handler);


#ifdef	__cplusplus
}
#endif

#endif	/* BSP_ICX_H */

