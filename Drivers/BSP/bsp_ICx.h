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

/* 捕获通道编号（与 Hall U/V/W 对应） */
#define BSP_ICX_CH_U    0u  /* IC1 / Hall U */
#define BSP_ICX_CH_V    1u  /* IC2 / Hall V */
#define BSP_ICX_CH_W    2u  /* IC3 / Hall W */


/* IC 硬件初始化：GPIO/PPS/ICxCON/IEC */
void BSP_ICx_HW_Init(void);

/*
 * Hall 引脚电平读取（去抖 / 合法态判断等 motor 域逻辑不在 BSP）。
 * 返回值位布局：bit2 = IC1 (RG8, Hall U)
 *               bit1 = IC2 (RG7, Hall V)
 *               bit0 = IC3 (RG6, Hall W)
 */
uint8_t BSP_ICx_ReadHall(void);

/*
 * IC ISR 桥：BSP 拥有 IC1/2/3_CallBack 强覆盖（压制 MCC 弱符号），
 * 上层经此注册统一处理函数。
 *
 * 每次进入某个 ICx 中断时，BSP 先排空该通道 FIFO，再把本次捕获信息交给 handler：
 *   ch  = BSP_ICX_CH_U / V / W（IC1/IC2/IC3）
 *   cap = 该通道 FIFO 中最新一次捕获值（ICxTMR，当前 T3CLK=1:256，3657ns/tick）
 *   ovf = 1：FIFO 溢出，或本次排空出多个待处理值（边沿丢失/积压），cap 与当前
 *         Hall 引脚状态不再一一对应；0：只有本次一个捕获，cap 可信
 *
 * handler 在 IC 中断上下文执行，必须短小。注册应在全局中断使能前完成。
 * 注册前若偶发 Hall 沿，handler 为 NULL 时只排空 FIFO，不做其他事。
 */
typedef void (*BSP_ICx_IsrHandler_t)(uint8_t ch, uint16_t cap, uint8_t ovf);
void    BSP_ICx_RegisterIsrHandler(BSP_ICx_IsrHandler_t handler);


#ifdef	__cplusplus
}
#endif

#endif	/* BSP_ICX_H */

