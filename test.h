/*
 * File:   test.h
 * Author: gaol
 *
 * Created on August 22, 2026, 3:15 PM
 *
 * 测试模块（应用层）
 * 测试代码集中于此，main.c 只保留初始化与注册调用。
 */

#ifndef TEST_H
#define	TEST_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

void TEST_Init(void);

/*
 * TEST_ModuleRun
 * 上电一次性模块测试与基准（自 main.c 迁移）：
 *   1) 正弦查表正确性：C 版 SinCos16 vs 汇编版 SinCos16_Asm，串口打印对照表
 *   2) 速度基准：示波器测 LED1 三段脉宽（C / Asm / 空循环基线）
 * 需在全局中断使能、串口可用后调用（printf 依赖）。
 */
void TEST_ModuleRun(void);

void PWM_SPWM_DUTY_Check(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* TEST_H */
