/*
 * File:   mcp4922.h
 * Author: gaol
 *
 * Created on August 22, 2026, 3:18 PM
 *
 * MCP4922 双通道 12bit SPI DAC 器件驱动（Components 层，只依赖 MCC SPI1 + GPIO）
 *
 * 硬件连接（dsPIC33EP128MC506）：
 *   SDO1 = RA4（专用脚，无需 PPS）   SCK1 = RC3（专用脚，无需 PPS）
 *   CS1  = RA9（IO_SPI1_CS1，MCC 配置为输出、上电高电平）→ DAC1
 *   CS2  = RD8（IO_SPI1_CS2，MCC 配置为输出、上电高电平）→ DAC2
 *   LDAC = GND（数据在 CS 上升沿即刻更新到输出，无需软件锁存脉冲）
 *
 * SPI1 配置（MCC 生成，spi1.c）：
 *   16bit 帧 / 主模式 / CKP=1,CKE=0（Mode3，MCP4922 支持）/ SCK=14MHz（<20MHz 上限）
 *
 * 16bit 命令字格式（写命令，非连续访问）：
 *   bit15   !A/B  ：0=通道A  1=通道B
 *   bit14   BUF   ：0=输入不缓冲（VREF 直接进电阻梯）→ 此处 VREF 源阻抗低，选 0
 *   bit13   !GA   ：1=1x 增益（输出 = VREF × code/4096）
 *   bit12   !SHDN ：1=正常工作（0=关断，输出挂 1kΩ 到 GND）
 *   bit11~0 数据  ：12bit 无符号
 *
 * 写时序（每通道独立一帧）：
 *   CS↓ → SPI 发 16bit → CS↑（LDAC 接地，上升沿数据进 DAC 寄存器并更新输出）
 *   帧间 CS 高电平最短几十 ns，70MIPS 下 GPIO 翻转+函数调用开销天然满足
 */

#ifndef MCP4922_H
#define	MCP4922_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* ---- 片选映射到哪片 DAC ---- */
typedef enum {
    MCP4922_DAC1 = 0,   /* CS = RA9 (IO_SPI1_CS1) */
    MCP4922_DAC2,       /* CS = RD8 (IO_SPI1_CS2) */
    MCP4922_DEV_COUNT
} MCP4922_Dev_t;

/* 通道命令字高 4 位配置基值：BUF=0(不缓冲) GA=1(1x增益) SHDN=1(工作) */
#define MCP4922_CMD_CHA_BASE    0x3000u   /* !A/B=0 通道A */
#define MCP4922_CMD_CHB_BASE    0xB000u   /* !A/B=1 通道B */

/*
 * MCP4922_Init
 * DAC 驱动初始化：CS 幂等置高（MCC 已配方向/初始电平，此处兜底），
 * 清 SPI 接收溢出标志，读空 RX 缓冲。
 * 前置：SYSTEM_Initialize() 已执行（SPI1_Initialize + 引脚配置）。
 */
void MCP4922_Init(void);

/*
 * MCP4922_WriteAB
 * 向指定芯片写两个通道：A 一帧、B 一帧，各自 CS 上升沿更新输出。
 * cmdA/cmdB 为完整 16bit 命令字（用 MCP4922_MakeCmd 生成）。
 * 阻塞式（每帧 16 SCK @14MHz ≈ 1.14us，两帧共 ≈2.5us 含开销），可在 ISR 内调用。
 */
void MCP4922_WriteAB(MCP4922_Dev_t dev, uint16_t cmdA, uint16_t cmdB);

/*
 * MCP4922_WriteQ15AB
 * 便捷入口：Q1.15 有符号值(-32768~32767) → 偏置二进制 12bit(0~4095)。
 * 0 → 2048（输出 VREF/2），-32768 → 0（0V），+32767 → 4095（≈VREF）。
 * 即输出 = VREF/2 + VREF/2 × (q15/32768)，解决 DAC 无法输出负电压的问题。
 */
void MCP4922_WriteQ15AB(MCP4922_Dev_t dev, int16_t q15A, int16_t q15B);

/*
 * MCP4922_MakeCmd
 * 拼装 16bit 命令字：chB=false→通道A，true→通道B；code12 仅低 12 位有效。
 */
static inline uint16_t MCP4922_MakeCmd(bool chB, uint16_t code12)
{
    return (chB ? MCP4922_CMD_CHB_BASE : MCP4922_CMD_CHA_BASE)
           | (code12 & 0x0FFFu);
}

/*
 * MCP4922_Q15To12
 * Q1.15 → 12bit 偏置二进制：
 *   异或 0x8000 把符号位翻进数值域（等价 +32768 偏置），再 >>4 取高 12 位。
 * 无分支、单调、无溢出：-32768→0，0→2048，+32767→4095。
 */
static inline uint16_t MCP4922_Q15To12(int16_t q15)
{
    return (uint16_t)(((uint16_t)q15 ^ 0x8000u) >> 4);
}

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MCP4922_H */
