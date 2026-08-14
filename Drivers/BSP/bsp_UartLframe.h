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
 * BEEN ADVISED OF THE POSSIBILITY OF THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   bsp_UartLframe.h
 * Author: gaol
 * Comments: UART 轻量链路层帧协议（变长帧）
 * Revision history: 
 */

#ifndef BSP_UARTLFRAME_H
#define BSP_UARTLFRAME_H

#include <stdint.h>
#include <stdbool.h>
#include "uart2.h"

/**
 * @brief 协议帧定义
 *   帧格式: HEAD1 HEAD2 LEN DATA[LEN] CHECKSUM
 *   LEN     : 数据域字节数，取值 1 .. UARTLFRAME_DATA_MAX
 *   CHECKSUM: ~(HEAD1+HEAD2+LEN+DATA) + 1，整帧求和(含校验) == 0
 */
#define UARTLFRAME_HEAD1                    0xAA    /* 帧头第1字节 */
#define UARTLFRAME_HEAD2                    0x55    /* 帧头第2字节 */
#define UARTLFRAME_DATA_MAX                 32      /* 数据域最大字节数 */
#define UARTLFRAME_FRAME_MAX                (2 + 1 + UARTLFRAME_DATA_MAX + 1) /* 头2+长度1+数据+校验1 */

#define UARTLFRAME_INTERBYTE_TIMEOUT_MS     20U     /* 帧内字节间超时：超时复位状态机 */
#define UARTLFRAME_TX_TIMEOUT_MS            50U     /* 发送：等待 TX 就绪的单字节超时 */
#define UARTLFRAME_PROCESS_BATCH            16U     /* Process 单轮最多处理字节数 */

/**
 * @brief 协议帧结构体
 */
typedef struct {
    uint8_t head1;                          /* 帧头1 */
    uint8_t head2;                          /* 帧头2 */
    uint8_t len;                            /* 数据长度域 */
    uint8_t data[UARTLFRAME_DATA_MAX];      /* 数据域 */
    uint8_t checksum;                       /* 校验和 */
} UartLFrame_t;

/**
 * @brief 接收成功回调函数类型
 * @param frame 解析完成的协议帧指针；数据有效范围为 frame->data[0 .. frame->len-1]
 */
typedef void (*UartLframe_RxCallback_t)(const UartLFrame_t* frame);

/**
 * @brief 协议初始化（默认不注册回调，由应用经 UartLframe_RegisterCallback 注册）
 */
void UartLframe_Init(void);

/**
 * @brief 注册接收回调
 * @param cb 回调函数指针，传 NULL 取消注册
 */
void UartLframe_RegisterCallback(UartLframe_RxCallback_t cb);

/**
 * @brief 发送一帧协议数据
 * @param data 待发送数据指针
 * @param len  数据字节数，取值 1 .. UARTLFRAME_DATA_MAX
 * @return 成功返回 true；参数非法或 TX 长时间未就绪返回 false
 */
bool UartLframe_Send(const uint8_t *data, uint8_t len);

/**
 * @brief 协议接收处理（轮询调用）
 * @note 从 UART2 环形缓冲读取数据并解析；单轮处理字节数有上限，避免阻塞主循环
 */
void UartLframe_Process(void);


#endif  // BSP_UARTLFRAME_H
