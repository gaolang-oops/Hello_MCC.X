/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.5
        Device            :  dsPIC33EP128MC506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
 */

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED, OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OF THE DAMAGES FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/clock.h"

#include "Drivers/BSP/bsp_gpio.h"
#include "Drivers/BSP/bsp_adc.h"
#include "Drivers/BSP/bsp_freq.h"
#include "Drivers/BSP/bsp_ICx.h"
#include "Drivers/BSP/bsp_timer.h"
#include "Drivers/BSP/bsp_UartLframe.h"
#include "Drivers/BSP/delay.h"

#include "Drivers/Components/mcp4922.h"

#include "Middlewares/MotorControl/motor_control.h"
#include "Middlewares/MotorControl/pwm_common.h"
#include "Middlewares/MotorControl/hall_speed_fdbk.h"
#include "Middlewares/MotorControl/MC_Fault.h"
#include "Middlewares/MotorControl/mc_services.h"

#include "mc_protocol.h"
#include "mc_fault_indicator.h"
#include "mc_button.h"
#include "test.h"
#include "user_manager.h"

#include <stdio.h>
#include <assert.h>

/*
 * Main application
 */

/*
 * SelfCheck_Report
 * 上电硬件/配置自检报告：时钟源、中断优先级、PWM 派生体系校验。
 * 须在中断全局使能后调用（printf 依赖串口收发）。
 */
static void MAIN_SECTION SelfCheck_Report(void) {
    /* 查看当前时钟源: 000=FRC, 011=PRI+PLL(外部晶振+PLL) */
    printf("Clock: COSC = %d%d%d\n",
            OSCCONbits.COSC2,
            OSCCONbits.COSC1,
            OSCCONbits.COSC0);
    printf("系统时钟 Fosc = %lu MHz\n", CLOCK_SystemFrequencyGet() / 1000000);
    printf("指令时钟 FCY = %lu MHz\n", CLOCK_InstructionFrequencyGet() / 1000000);

#if 1 /* 中断优先级自检报告(读实际 IPCx 寄存器值) */
    printf("[IRQ] AD1=%u  T3=%u\n",
            INT_PRIORITY_AD1, INT_PRIORITY_T3);
    printf("[IRQ] IC1=%u  IC2=%u  IC3=%u\n",
            INT_PRIORITY_IC1, INT_PRIORITY_IC2, INT_PRIORITY_IC3);
    printf("[IRQ] U2TX=%u  U2RX=%u	U2E=%u\n",
            INT_PRIORITY_U2TX, INT_PRIORITY_U2RX, INT_PRIORITY_U2E);
#endif

#if 1 /* PWM 配置自检报告:BSP 层派生体系(经 BSP_FREQ_Verify 后到此处,PHASE1 必与派生值一致) */
    {
        uint16_t phase1_reg = PHASE1;   /* 实读 SFR(若与派生值不等,根本到不了这里) */
        printf("[PWM] PHASE1 reg = %u  derived = %u  (match: %s)\n",
                phase1_reg, BSP_PWM_PERIOD_TICKS,
                (phase1_reg == BSP_PWM_PERIOD_TICKS) ? "YES" : "NO");
        printf("[PWM] freq = %lu Hz    period = %u ticks (%lu us)\n",
                BSP_PWM_FREQUENCY_HZ, BSP_PWM_PERIOD_TICKS,
                (uint32_t)1000000UL / BSP_PWM_FREQUENCY_HZ);
        printf("[PWM] duty fullscale = %u   min = %u (%u%%)   max = %u (%u%%)\n",
                BSP_DUTY_FULLSCALE, BSP_DUTY_MIN, BSP_DUTY_MIN_PCT,
                BSP_DUTY_MAX, BSP_DUTY_MAX_PCT);
    }
    assert(PHASE1 == BSP_PWM_PERIOD_TICKS);   /* 失败时 __assert_fail 打印 文件:行号:表达式。然后重启 */
#endif
}

int MAIN_SECTION main(void) {
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalDisable();

    /*1_1_BSP初始化*/
    //中断关闭期间，禁用printf，否则会陷入串口阻塞
    GPIO_Configure_LEDS();
    GPIO_Configure_KEYS();
    BSP_Timer_Init();
    BSP_ICx_HW_Init(); /* IC 硬件: GPIO/PPS/ICxCON/IEC */
    BSP_ADC_Int_Register();

	/*1_2_器件初始化*/
    /* MCP4922 DAC 初始化 + 正余弦波形验证测试（查表在 ADC 中断 50us 时基内执行，
     * C 版查表→DAC1(CS=RA9)，汇编版查表→DAC2(CS=RD8)，通道A=sin 通道B=cos） */
    MCP4922_Init();

	/*1_3_测试模块*/
    /* PWM 频率母宏 vs MCC 写入的 PHASE1 寄存器对齐校验。
     * 若 MCC GUI 改了频率却忘了同步 bsp_freq.h,此处 VERIFY 死循环,
     * 调试器原地捕获,杜绝"占空比刻度/时基分频静默失准"的幽灵故障。 */
    BSP_FREQ_Verify();
	TEST_Init();

    /*2_app init*/
    UartLframe_Init();
    MCProtocol_Init();   /* UART 帧协议回调由 mc_protocol 模块注册。负责上传故障 */
    MCButton_Init();     /* 按键消抖初始化 */
    Motor_Init();   /* 统一编排 motor 层 init：状态机/Ramp/SIXSTEP/HALL/MC_Fault */
    MCFaultIndicator_Init();  /* LED 指示初始化(须在 GPIO_Configure_LEDS 之后) */

    /*3_中断使能*/
    INTERRUPT_GlobalEnable();

    SelfCheck_Report();   /* 硬件/配置自检报告 */

    //上电初始化，延时500ms。等待模拟信号稳定
    //接下来做电压保护，就不会出现误报故障的情况
    Delay_ms(500);

    while (1) {
        /* ===== Tier-4 事件驱动(无固定节拍,每轮跑) =====
         * UART 帧解析,收到上位机信息触发回调处理[无任务时迅速空转回到 Tier-2 检查] */
        UartLframe_Process();
        MCProtocol_PollFault();   /* 故障边沿,设备主动推送到上位机(须在 UartLframe_Process 之后) */

        /* ===== Tier-2 控制层(1ms,与 PWM/ADC 同步) =====
         * 状态机 + 缓变 + 故障裁决。ADC ISR 置 flag,主循环消费。
         * 节拍稳定不随 UART 抖动,自举 50ms 计时精度有保障。 */
        if (BSP_ADC_TimeBase_Is1msFlag()) {
            BSP_ADC_TimeBase_Clear1msFlag();
            MCButton_Tick1ms();
            Motor_Tick();
            MCFaultIndicator_Tick1ms();   /* LED 心跳/故障闪烁 */
        }

        /* ===== Tier-3 监控层(500ms 慢节拍) =====
         * 主循环存活心跳(LED0):卡死时冻住=告警 */
        if (BSP_ADC_TimeBase_Is500msFlag()) {
            BSP_ADC_TimeBase_Clear500msFlag();
            LED_Toggle(LED0);
#if 0 /* 调试块:打印采样/状态,节拍已固定 500ms */
            {
                Motor_Handle_t *m = Motor_GetHandle();
                /* 采样数据保持直接调用(不纳入 motor handle) */
                printf("Vbus=%lu mV  Ia=%d  Ib=%d  Ic=%d  Ibus=%d mA\n",
                        (uint32_t)BSP_ADC_GetVbusMv(),
                        MC_GetCurrentIamA(), MC_GetCurrentIbmA(),
                        MC_GetCurrentIcmA(), MC_GetCurrentIbusmA());
                /* 电机状态经统一句柄读取 */
                printf("state=%d fault=0x%X hall=%d 6step=%d duty=%u/%u age=%lums\n",
                        m->state, (uint16_t)m->fault, m->hall_status,
                        (uint16_t)m->six_step_en, m->target_duty, m->current_duty,
                        (unsigned long)m->last_edge_age_ms);
            }
#endif
        }
    }

    return 1;
}
/**
 End of File
 */
