/*
 * File:   mcp4922.c
 * Author: gaol
 *
 * Created on August 22, 2026, 3:18 PM
 *
 * MCP4922 器件驱动实现
 */

#include "mcp4922.h"
#include "../../user_manager.h"
#include "../../mcc_generated_files/pin_manager.h"   /* IO_SPI1_CS1/2 控制宏 */
#include "../../mcc_generated_files/spi1.h"           /* SPI1_Exchange16bit */


/* ---- 片选操作：按 dev 选宏（MCC 宏为单条 LAT 写，即 ~14ns） ---- */
static inline void COMP_SECTION CS_SetLow(MCP4922_Dev_t dev)
{
    if (dev == MCP4922_DAC1) {
        IO_SPI1_CS1_SetLow();
    } else {
        IO_SPI1_CS2_SetLow();
    }
}

static inline void COMP_SECTION CS_SetHigh(MCP4922_Dev_t dev)
{
    if (dev == MCP4922_DAC1) {
        IO_SPI1_CS1_SetHigh();
    } else {
        IO_SPI1_CS2_SetHigh();
    }
}

void COMP_SECTION MCP4922_Init(void)
{
    IO_SPI1_CS1_SetHigh();
    IO_SPI1_CS2_SetHigh();

    /* SPI1_Initialize 之后若曾发生过接收溢出会挂死 RX，清掉并读空缓冲 */
    SPI1STATbits.SPIROV = 0;
    (void)SPI1BUF;
}

/* 单帧写：CS↓ → 16bit 交换(阻塞至完成) → CS↑（LDAC 接地，上升沿即刻更新输出）
 * Exchange16bit 返回前已等 RX FIFO 非空 ⇒ 移位已结束，CS 拉高安全。 */
static void COMP_SECTION WriteOne(MCP4922_Dev_t dev, uint16_t cmd)
{
    CS_SetLow(dev);
    (void)SPI1_Exchange16bit(cmd);
    CS_SetHigh(dev);
}

void COMP_SECTION MCP4922_WriteAB(MCP4922_Dev_t dev, uint16_t cmdA, uint16_t cmdB)
{
    WriteOne(dev, cmdA);
	WriteOne(dev, cmdB);
}

void COMP_SECTION MCP4922_WriteQ15AB(MCP4922_Dev_t dev, int16_t q15A, int16_t q15B)
{
    MCP4922_WriteAB(dev,
                    MCP4922_MakeCmd(false, MCP4922_Q15To12(q15A)),
                    MCP4922_MakeCmd(true,  MCP4922_Q15To12(q15B)));
}
