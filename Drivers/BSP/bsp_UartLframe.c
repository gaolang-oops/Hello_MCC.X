/*
 * File:   bsp_UartLframe.c
 * Author: gaol
 *
 * Created on 2026年5月22日, 上午9:41
 */
#include "bsp_UartLframe.h"
#include "../../user_manager.h"
#include "bsp_timer.h"
#include <stdlib.h>
/**
 * @brief 协议解析状态机枚举
 */
typedef enum {
    STATE_IDLE,     /* 空闲：等待帧头1 */
    STATE_HEAD1,    /* 已收帧头1，等待帧头2 */
    STATE_LEN,      /* 接收长度域 */
    STATE_DATA,     /* 接收数据域 */
    STATE_CHECKSUM, /* 接收校验域 */
} UartLframe_State_t;

/**
 * @brief 协议接收上下文：集中管理单实例全部状态
 */
typedef struct {
    UartLframe_State_t state;                   /* 解析状态机 */
    UartLframe_RxCallback_t rxCallback;         /* 接收回调 */
    uint8_t  rxBuffer[UARTLFRAME_FRAME_MAX];    /* 接收缓冲区 */
    uint8_t  rxIndex;                           /* 缓冲区索引 */
    uint8_t  dataLen;                           /* 当前帧数据长度 */
    uint8_t  rxSum;                             /* 当前帧累加和（含校验字节后应为0） */
    uint16_t lastByteMs;                        /* 上一字节时间戳（帧间超时用） */
} UartLframe_Ctx_t;

static UartLframe_Ctx_t s_ctx;

/**
 * @brief 协议初始化：复位状态机，默认不注册回调
 */
void UART_SECTION UartLframe_Init(void) {
    s_ctx.state      = STATE_IDLE;
    s_ctx.rxIndex    = 0;
    s_ctx.dataLen    = 0;
    s_ctx.rxSum      = 0;
    s_ctx.rxCallback = NULL;
    s_ctx.lastByteMs = BSP_Timer_NowMs();
}

/**
 * @brief 注册接收回调
 */
void UART_SECTION UartLframe_RegisterCallback(UartLframe_RxCallback_t cb) {
    s_ctx.rxCallback = cb;
}

/**
 * @brief 发送一帧
 *        帧: HEAD1 HEAD2 LEN DATA[LEN] CHECKSUM，校验 = ~(前置和)+1
 */
bool UART_SECTION UartLframe_Send(const uint8_t *data, uint8_t len)
{
    if (data == NULL)
        return false;
    if (len == 0U || len > UARTLFRAME_DATA_MAX)
        return false;

    uint8_t frame[UARTLFRAME_FRAME_MAX];
    /* 填充帧头+长度，并起步累加和 */
    uint8_t sum = UARTLFRAME_HEAD1 + UARTLFRAME_HEAD2 + len;
    frame[0] = UARTLFRAME_HEAD1;
    frame[1] = UARTLFRAME_HEAD2;
    frame[2] = len;
    /* 填充数据域，同步累加和（填充与求和） */
    for (uint8_t i = 0U; i < len; i++)
    {
        frame[3U + i] = data[i];
        sum += data[i];
    }
    uint8_t frameLen = 3U + len;                /* 头2+长度1+数据len */
    frame[frameLen] = (uint8_t)((~sum) + 1U);   /* 校验和：整帧求和应为0 */

    uint8_t total = frameLen + 1U;              /* 含校验字节 */
    for (uint8_t i = 0U; i < total; i++)
    {
        uint16_t start = BSP_Timer_NowMs();
        while (!UART2_IsTxReady())
        {
            if (BSP_Timer_ElapsedMs(start) >= UARTLFRAME_TX_TIMEOUT_MS)
                return false;                   /* TX 长时间未就绪，避免阻塞电机主循环 */
        }
        UART2_Write(frame[i]);
    }
    return true;
}

/**
 * @brief 单字节状态机解析
 * @param byte 接收到的字节
 */
static void UART_SECTION UartLframe_ParseByte(uint8_t byte) {
    s_ctx.lastByteMs = BSP_Timer_NowMs();

    switch (s_ctx.state)
    {
    /* 空闲：等待帧头1 */
    case STATE_IDLE:
        if (byte == UARTLFRAME_HEAD1)
        {
            s_ctx.rxBuffer[0] = byte;
            s_ctx.rxIndex     = 1;
            s_ctx.dataLen     = 0;
            s_ctx.rxSum       = byte;           /* 新帧累加和起步 */
            s_ctx.state       = STATE_HEAD1;
        }
        break;

    /* 已收帧头1，等待帧头2 */
    case STATE_HEAD1:
        if (byte == UARTLFRAME_HEAD2)
        {
            s_ctx.rxBuffer[1] = byte;
            s_ctx.rxIndex     = 2;
            s_ctx.rxSum      += byte;
            s_ctx.state       = STATE_LEN;
        }
        else if (byte == UARTLFRAME_HEAD1)
        {
            /* 重同步：连续 0xAA，当前状态（buffer[0]=0xAA / index=1 / sum=0xAA）仍有效，
             * 把本次视作新帧头1，维持 HEAD1 等待 HEAD2 即可，无需改动 */
            break;
        }
        else
        {
            s_ctx.state = STATE_IDLE;
        }
        break;

    /* 接收长度域 */
    case STATE_LEN:
        s_ctx.rxBuffer[2] = byte;
        s_ctx.dataLen     = byte;
        s_ctx.rxIndex     = 3;
        s_ctx.rxSum      += byte;
        if (s_ctx.dataLen >= 1U && s_ctx.dataLen <= UARTLFRAME_DATA_MAX)
        {
            s_ctx.state = STATE_DATA;
        }
        else
        {
            s_ctx.state = STATE_IDLE;           /* 非法长度 */
        }
        break;

    /* 接收数据域 */
    case STATE_DATA:
        s_ctx.rxBuffer[s_ctx.rxIndex++] = byte;
        s_ctx.rxSum                    += byte;
        if (s_ctx.rxIndex >= (uint8_t)(3U + s_ctx.dataLen))
        {
            s_ctx.state = STATE_CHECKSUM;
        }
        else if (s_ctx.rxIndex >= (UARTLFRAME_FRAME_MAX - 1U))
        {
            /* 防御性上界：FRAME_MAX[36]-1 为校验字节槽位，DATA 不得占用；
             * 理论上 LEN 已校验(<=32)，3+LEN<=35 不会触达 */
            s_ctx.state = STATE_IDLE;
        }
        break;

    /* 接收校验域 */
    case STATE_CHECKSUM:
    {
        s_ctx.rxBuffer[s_ctx.rxIndex] = byte;
        s_ctx.rxSum                  += byte;
        if (s_ctx.rxSum == 0U)                   /* 整帧求和(含校验)应为0 */
        {
            if (s_ctx.rxCallback != NULL)
            {
                s_ctx.rxCallback((const UartLFrame_t *)s_ctx.rxBuffer);
            }
        }
        s_ctx.state = STATE_IDLE;                /* 无论成功失败都复位 */
        break;
    }

    default:
        s_ctx.state = STATE_IDLE;
        break;
    }
}

/**
 * @brief 协议轮询处理函数
 */
void UART_SECTION UartLframe_Process(void) {
    /* 帧间超时：状态机停留中且超过阈值未收到下一字节则复位 */
    if (s_ctx.state != STATE_IDLE &&
        BSP_Timer_ElapsedMs(s_ctx.lastByteMs) >= UARTLFRAME_INTERBYTE_TIMEOUT_MS)
    {
        s_ctx.state = STATE_IDLE;
    }

    /* 单轮限流：保护 Motor_Tick 时序，避免一次性抽干长突发 */
    uint8_t budget = UARTLFRAME_PROCESS_BATCH;
    while (budget-- > 0U && UART2_IsRxReady())
    {
        uint8_t byte = UART2_Read();
        UartLframe_ParseByte(byte);
    }
}
