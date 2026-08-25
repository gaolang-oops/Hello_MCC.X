/*
 * File:   test.h
 * Author: gaol
 *
 * Created on August 22, 2026, 3:15 PM
 *
 * 测试模块（应用层）：模块功能测试/基准 + DAC 正余弦波形验证。
 * 测试代码集中于此，main.c 只保留初始化与注册调用。
 */

#ifndef TEST_H
#define	TEST_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * TEST_Init
 * 注册 DAC 波形测试到 ADC 中断 50us 时基（20kHz，与 PWM 同步）。
 * 前置：SYSTEM_Initialize() 与 MCP4922_Init() 已执行。
 * 每次中断：相位累加 → C 版/汇编版查表 → SPI 送双 MCP4922（详见 test.c）。
 */
void TEST_Init(void);

/*
 * TEST_ModuleRun
 * 上电一次性模块测试与基准（自 main.c 迁移）：
 *   1) 正弦查表正确性：C 版 SinCos16 vs 汇编版 SinCos16_Asm，串口打印对照表
 *   2) 速度基准：示波器测 LED1 三段脉宽（C / Asm / 空循环基线）
 * 需在全局中断使能、串口可用后调用（printf 依赖）。
 */
void TEST_ModuleRun(void);


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* TEST_H */
