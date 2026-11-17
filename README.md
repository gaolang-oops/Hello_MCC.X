# Hello_MCC.X

基于 **dsPIC33EP128MC506** 的三相电机控制工程，支持 **SPWM 正弦调制（当前默认）** 与 **六步换相（Six-Step）** 两种驱动模式。
采用 MPLAB X IDE + MCC 分层架构，包含完整的状态机编排、两级故障保护（μs 级过流 + ms 级慢故障）、SPWM 连续调制链与 UART/按键双命令通道。

> 当前为**开环**控制（旋钮 → 缓变 → 幅值/占空调制），速度环 PI 已预留接缝。
> SPWM 调制链已闭环：Hall 角度观测 + 50μs 三相 PDC 更新。

## 硬件平台

| 项 | 配置 |
|---|---|
| MCU | dsPIC33EP128MC506 |
| 系统时钟 | Fosc = 140 MHz / FCY = 70 MIPS |
| 编译器 | XC16 v2.10 |
| IDE | MPLAB X IDE v6.05 + MCC |
| PWM 载波 | 20 kHz（SPWM：中心对齐 CAM=1 / PHASE=3500；六步：边沿对齐 CAM=0 / PHASE=7000） |
| 驱动模式 | `MC_DRIVE_MODE`（motor_control.h）编译期选择：SPWM（默认）/ SIXSTEP |
| 电流采样 | 相电流 Ia/Ib/Ic（±3A 量程）+ Ibus 母线电流 |
| 反馈 | 3 路 Hall 信号（IC1/2/3；SPWM：AD1 > IC，六步：IC > AD1） |

## 功能特性

- **双驱动模式**：`MC_DRIVE_MODE` 编译期选择 SPWM / 六步，状态机经 `Drive_Enable / Drive_Output` 门面分发
- **SPWM 正弦调制**：SinCos16 单次查表 + 代数移相出三相；`θmod = θr ± 90°`；50μs 更新三相 PDC，幅值限幅约 84%
- **转子电角度观测**：Hall 沿重同步 + 16.16 积分 + 200ms 无沿冻结 + 启动种子（`rotor_angle.c`）
- **六步换相**：Hall 边沿中断驱动查表换相，ISR 内即时切换 PWM Override 寄存器（当前仅正转表，反转表 TODO）
- **两级故障保护**：
  - **L1 软件快保护**（50μs ADC ISR）：瞬时过流 → DriveOff 钩子 μs 级关断 PWM + 现场快照
  - **L2 状态机**（1ms）：过压/欠压/过载(IIR)/霍尔丢失，进入 FAULT 吸收态锁存
- **分层任务框架**（Tier-0~4）：按时间常数分层，ADC ISR 作系统时基源
- **状态机**：`FAULT → STOPPED → BOOTSTRAP → CHARGING → READY → STARTUP(SPWM) → RUNNING`
- **双命令通道**：按键 UI（KEY0 正转 / KEY1 反转启动，KEY2 停机、长按清故障；运行中禁止换向）+ UART 协议（查询/清除/故障推送）
- **故障可视化**：串口协议（推拉混合）+ LED3 编码闪烁（无串口现场）
- **自举电容预充**：进入运行前充电 50ms（六步=下管常通；SPWM=下桥 50% PWM 充电，风车态限流+交接占空预置），跨拍天然关断裕量

## 目录结构

```
Hello_MCC.X/
├── main.c                      应用层：初始化编排 + 分层主循环
├── mc_protocol.c/.h            UART 故障协议（查询/清除/边沿推送）
├── mc_fault_indicator.c/.h     故障 LED 编码闪烁
├── mc_button.c/.h              按键 UI（非阻塞消抖）
├── test.c/.h                   DAC/示波器台架测试（可选注册）
├── Docs/
│   ├── Architecture.md         完整架构文档（推荐先读）
│   └── SPWM正弦调制控制.drawio  SPWM 流程图
├── mcc_generated_files/        MCC 生成的外设驱动（勿手改）
├── Drivers/BSP/                板级支持包（工程单位换算在此完成）
│   ├── bsp_adc.c/.h            ADC ISR + raw→mA/mV/duty 换算
│   ├── bsp_freq.h              ★ PWM 频率母参数 + 编译期派生（纯头文件，自检内联 main.c）
│   ├── bsp_ICx.c/.h            Hall 输入捕捉 + IC ISR 桥
│   ├── bsp_timer.c/.h          基于 TMR3 的 10μs 时基
│   └── bsp_UartLframe.c/.h     UART 轻量帧协议
└── Middlewares/MotorControl/   电机控制策略层（零 BSP include）
    ├── motor_control.c/.h      状态机统一编排入口 + Drive 门面
    ├── mc_services.c/.h        ★ 平台接缝（motor 层唯一直达 BSP 的 .c）
    ├── six_step.c/.h           六步换相查表 + SIXSTEP_Output
    ├── spwm.c/.h               SPWM 三相正弦 + SPWM_Output
    ├── sincos.c/.h             128 点 Q1.15 正余弦查表（+ sincos_asm.s）
    ├── rotor_angle.c/.h        转子电角度观测（Hall 重同步 + 50µs 积分）
    ├── pwm_common.c/.h         PWM Override 寄存器唯一所有者
    ├── hall_speed_fdbk.c/.h    Hall 信号处理 + 边沿时戳 + 参考方向
    ├── mc_ramp.c/.h            占空比缓变参考（速度环接缝）
    └── MC_Fault.c/.h           两级故障管理
```

**分层规则**：应用层 → motor 层 →（仅经 `mc_services`）→ BSP → mcc_generated_files。
换板子/换采样链路只改 BSP 一份，motor 层阈值不动。

## 编译与烧录

1. 安装 MPLAB X IDE v6.05 与 XC16 v2.10
2. 用 MPLAB X 打开 `Hello_MCC.X` 工程
3. 选择目标配置（默认 `default`）
4. 编译生成 `.hex`，用 PICkit / ICD / RealICD 烧录
5. 切换驱动模式：修改 `motor_control.h` 的 `MC_DRIVE_MODE` 后，须同步 `bsp_freq.h` 的 `BSP_PWM_ALIGNMENT`、MCC PWM 对齐/TRGDIV 与中断优先级（见架构文档）。

## License

MIT
