/*
 * File:   motor_control.c
 * Author: gaol
 *
 * 电机层统一编排入口（对齐 ST MCSDK M1 任务接缝思想）：
 *   - Motor_Init    : 集中初始化 motor 层全部子模块（状态机/Ramp/驱动分发/SixStep|SPWM/Hall/Fault）
 *   - Motor_Tick    : 1ms 节拍推进状态机（Tier-2 控制层），由主循环调用
 *
 * 驱动模式母开关 MC_DRIVE_MODE（motor_control.h）编译期选择六步/SPWM，
 * 状态机经 Drive_Enable() 门面统一使能/失能。
 *
 * 命令模型（对齐 ST MCSDK DirectCommand）：
 *   应用层（按键/协议）经 Motor_SetCommand 下发一次性命令（START/STOP），
 *   状态机每拍快照后清零消费 —— 状态机不写回命令。
 *   重启须显式再次下发 START（故障清除 / 超时后自动 re-arm，无电平残留）。
 */

#include "motor_control.h"
#include "pwm_common.h"
#include "six_step.h"
#include "spwm.h"
#include "mc_ramp.h"
#include "mc_services.h"   /* 时基 + 旋钮指令（motor 层唯一平台接缝）*/
#include "MC_Fault.h"      /* MC_HasAnyFault / MC_Fault_Init */
#include "hall_speed_fdbk.h"

static Motor_State_e s_motor_state = MOTOR_STATE_STOPPED;
static uint16_t s_bootstrap_start_ms = 0;        /* 自举充电起始时间戳 */
static uint16_t s_ready_ms = 0;                  /* READY 态停留计时 */
static Motor_Cmd_e s_command = MOTOR_CMD_NONE;   /* 一次性命令锁存（应用层写，状态机消费清零）*/
static Motor_Handle_t s_motor_handle;            /* 统一句柄（快照聚合）*/

/* 输出门面（模式分发） */
static void Drive_Output(void);

#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
/* ============ 连续电气角估算（SPWM 用）============
 * 50µs ADC tick 对 HALL_GetThetaStep() 的 16.16 增量积分，
 * 每个 Hall 沿用 HALL_GetHallRotorPosition() 重同步。
 * 无有效 dt 或距上次 Hall 沿超过 ROTOR_ANGLE_TIMEOUT_MS 时冻结（step=0），
 * 避免停转后旧 step 继续把角度积分走。
 *
 * 并发：Hall 回调在 IC ISR 写 pending/anchor（16 位原子写），
 * 50µs 回调在 ADC ISR 消费；SPWM 模式 AD1 > IC，ADC 不会被 IC 打断。
 * HALL_UpdateStep 的 32 位 step 写入侧已加临界区，避免撕裂读。
 */

/* 32 位累加器与高 16 位整数角共享存储（dsPIC33E 小端）：
 *   part.frac  = 低 16 位（1/65536 brad16）
 *   part.whole = 高 16 位（整数 brad16），16 位原子读
 * 跨低位进位瞬间最多差 1 LSB（0.0055°），对角度/调试可忽略。 */
typedef union {
    volatile uint32_t u32;          /* 16.16 brad16 累加器 */
    struct {
        volatile uint16_t frac;     /* 低 16 位：小数 */
        volatile uint16_t whole;    /* 高 16 位：整数 brad16 */
    } part;
} RotorTheta_t;

typedef struct {
    RotorTheta_t      theta;        /* 电气角累加器/影子共用存储 */
    volatile uint16_t edge_anchor;  /* 本次 Hall 沿的绝对电角度 */
    volatile bool     edge_pending; /* Hall 沿待重同步 */
} RotorAngle_t;

static RotorAngle_t s_angle;

/* 30° brad16 = 65536/12，静止时用扇区中点作为初始角 */
#define ROTOR_ANGLE_SECTOR_HALF   5461u

/* 距上次 Hall 沿超过此时间视为停转，冻结角度 */
#define ROTOR_ANGLE_TIMEOUT_MS    200u

/* Hall 沿回调（IC ISR）：只发布锚点，实际重同步在 50µs tick 内完成。 */
static void Motor_OnHallEdge(uint8_t hall) {
    (void)hall;
    /* 先写锚点，再置 pending；50µs tick 只在 pending=true 时读取。 */
    s_angle.edge_anchor  = HALL_GetHallRotorPosition();
    s_angle.edge_pending = true;
}

/* 50µs ADC tick：积分 + Hall 沿重同步 + 超时冻结。 */
static void Motor_Tick50us(void) {
    HALL_StepQ16_t step;
    uint16_t dt_ticks;

    if (s_angle.edge_pending) {
        s_angle.edge_pending = false;
        s_angle.theta.u32 = ((uint32_t)s_angle.edge_anchor) << 16;
    }

    step = HALL_GetThetaStep();
    dt_ticks = HALL_GetEdgeDtTicks();
    if (dt_ticks == 0u || HALL_MsSinceLastEdge() > ROTOR_ANGLE_TIMEOUT_MS) {
        step = 0;   /* 速度尚未建立或 Hall 长时间无沿：冻结角度 */
    }

    s_angle.theta.u32 += (uint32_t)step;

    /* 调制输出：θmod（θr ± 90°）与缓变幅值 → 三相占空，同一 50µs 节拍写 PDC。
     * 故障闸门在本层判断（过流回调先执行，避免把 PWM_AllOff 覆盖）；
     * 使能闸门由 SPWM_Output 内部自查。 */
    if (!MC_HasAnyFault()) {
        Drive_Output();
    }
}

/* 上电初始化：Hall 种子读取后调用，用当前扇区中点作为初始角。 */
static void Motor_RotorAngleInit(void) {
    uint16_t pos = HALL_GetHallRotorPosition();

    s_angle.edge_pending = false;
    s_angle.edge_anchor  = 0u;

    if (pos == HALL_ANGLE_INVALID) {
        s_angle.theta.u32 = 0u;
    } else {
        /* 静止时转子在扇区内位置未知，用扇区中点作为初值：
         * FWD 进入沿是下边界 -> +30°；REV 进入沿是上边界 -> -30°。 */
        uint16_t center = (HALL_GetCmdDirection() == HALL_DIR_REV)
                        ? (uint16_t)(pos - ROTOR_ANGLE_SECTOR_HALF)
                        : (uint16_t)(pos + ROTOR_ANGLE_SECTOR_HALF);
        s_angle.theta.u32 = ((uint32_t)center) << 16;
    }
}

/*
 * 转子角 θr → SPWM 调制角 θmod
 *   FWD: θmod = θr + 90°（电压矢量落 q 轴，最大转矩）
 *   REV: θmod = θr − 90°（角增量已按命令方向取负，超前同样取负）
 * brad16 域直接加减，uint16 溢出即 360° 回卷；只取整数部分，
 * 分辨率 0.0055°，对 20kHz 调制足够（低 16 位小数不参与本次合成）。
 * 并发：s_angle.theta.part.whole 为 16 位单字读，原子。
 */
uint16_t Motor_GetModAngle16(void) {
    int16_t lead = SPWM_ANGLE_LEAD_Q16;

    if (HALL_GetCmdDirection() == HALL_DIR_REV) {
        lead = (int16_t)(-lead);
    }
    return (uint16_t)(s_angle.theta.part.whole + (uint16_t)lead);
}
#else
/* 六步构建：无连续角，接口保持同一签名，返回 0。 */
uint16_t Motor_GetModAngle16(void) {
    return 0u;
}
#endif /* MC_DRIVE_MODE_SPWM */

void Motor_SetCommand(Motor_Cmd_e cmd) {
    s_command = cmd;   /* 末写胜；单一应用上下文（主循环 Tier-4），无竞态 */
}

/* ============ 驱动算法统一使能门面（模式分发）============
 * 状态机对"使能/失能驱动输出"的唯一入口，按 MC_DRIVE_MODE（motor_control.h）
 * 编译期分发到具体驱动模块，避免各状态分支散布模式判断：
 *   六步：SIXSTEP_Enable（Hall ISR 换相 + Override 寄存器）
 *   SPWM：SPWM_Enable（零矢量预置 + 交还互补自主控制，闸门在 spwm 模块）
 */
static void Drive_Enable(bool en) {
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
    SPWM_Enable(en);
#else
    SIXSTEP_Enable(en);
#endif
}

/* 驱动闸门快照（模式无关，供 Motor_GetHandle 诊断字段） */
static bool Drive_IsEnabled(void) {
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
    return SPWM_IsEnabled();
#else
    return SIXSTEP_IsEnabled();
#endif
}

/* MC_Fault 过流 ISR 的失能钩子：只做模式无关关断，保持 MC_Fault 不反向依赖本模块。
 * 注册在 Motor_Init（GlobalEnable 之前），ISR 内只读函数指针 + 写寄存器。 */
static void Motor_DriveOffHook(void) {
    Drive_Enable(false);
}

/* ============ 驱动算法统一输出门面（模式分发）============
 * 与 Drive_Enable 对称：mc_ramp 只维护 current_duty 参考，不碰硬件，
 * 由调用方在各自速率调用本函数落硬件：
 *   六步：Motor_Tick RUNNING（1ms）→ 三相同幅值直写 PDC；
 *   SPWM：Motor_Tick50us（50µs）→ θmod + 幅值 → 三相正弦独立写 PDC。
 */
static void Drive_Output(void) {
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
    SPWM_Output(Motor_GetModAngle16(), MC_Ramp_GetCurrentDuty());
#else
    SIXSTEP_Output(MC_Ramp_GetCurrentDuty());
#endif
}

/* BSP init 段之后、中断 GlobalEnable 之前完成Motor_Init */
void Motor_Init(void) {
    s_motor_state = MOTOR_STATE_STOPPED;
    s_command     = MOTOR_CMD_NONE;
    s_ready_ms    = 0;
    MC_Ramp_Init();

    /* 过流保护先注册，保证 50µs 回调里保护先于角度/调制 */
    MC_Fault_Init();

    /* Hall 观察者按模式注册（须先于 HALL_Init） */
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
    /* 本分支没有 SPWM_Init，与六步的 SIXSTEP_Init 不对称是刻意为之：
     *   - spwm 模块自身只有 s_enabled（静态初值 false），没有待初始化的硬件/状态；
     *   - "关驱动"由下方统一的 Drive_Enable(false) 完成，不需要模块级 init；
     *   - θr 重同步用的 Hall 观察者（Motor_OnHallEdge）属于本层职责，
     *     在此直接注册，不需要 spwm 模块知道它。
     * 六步的 SIXSTEP_Init 之所以存在，是因为它要封装 static 的换相观察者。
     * 等 spwm 出现自己的状态（幅值/偏置/自检等）时再补 SPWM_Init。 */
    HALL_RegisterOnEdge(Motor_OnHallEdge);
#else
    /* 六步：Hall 观察者用于换相（内含关驱动 + 注册换相观察者）。 */
    SIXSTEP_Init();
#endif

    /* 两模式共用：Hall 种子读取 + 注册 IC ISR → BSP */
    HALL_Init();

#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
    Motor_RotorAngleInit();          /* 须在 HALL_Init 种子读取后（读种子角） */
    MC_RegisterTick50us(Motor_Tick50us);
#endif

    /* 注入过流 ISR 的驱动失能钩子：MC_Fault 只持有回调，不认识本模块。
     * 须在 GlobalEnable 之前完成（main.c 在 Motor_Init 后才开全局中断）。 */
    MC_Fault_SetDriveOffHook(Motor_DriveOffHook);

    /* 显式以驱动关闭态进入：不依赖各子模块 init 的副作用/静态初值。
     * 六步/SPWM 均清软件闸门 + PWM_AllOff；MCC 上电配置本身也是
     * Override 全关(OVRENH/L=1, OVRDAT=00)，此处再兜一层。
     * 必须在 SYSTEM_Initialize()（PWM 已初始化）之后调用，main.c 顺序满足。 */
    Drive_Enable(false);

    /* 绑定统一句柄 */
    s_motor_handle.state            = MOTOR_STATE_STOPPED;
    s_motor_handle.drive_mode       = MC_DRIVE_MODE;
    s_motor_handle.ramp             = MC_Ramp_GetHandle();
    s_motor_handle.fault            = MC_FAULT_NONE;
    s_motor_handle.hall_status      = 0;
    s_motor_handle.drive_en         = false;
    s_motor_handle.target_duty      = 0;
    s_motor_handle.current_duty     = 0;
    s_motor_handle.last_edge_age_ms = 0;
}

void Motor_Tick(void) {
    /* 故障优先于一切：任意运行态 + fault → 立即进入 FAULT 吸收态。
     * 全锁存策略：FAULT 态不清零 fault 标志。
     * 清除途径：MC_Fault_Init（冷启动）或外部命令（MC_ClearAllFaults）/ 按键。
     * 清除后 FAULT → STOPPED（下拍再判启动），避免清故障瞬间高压启动。 */

    /* L2 慢保护：VBUS 过/欠压检查（1ms 节拍，ms 级响应）。
     * 过流走 Tier-1 ISR（50us 回调），不在此处。 */
    MC_Fault_CheckVoltage();

    /* L2 慢保护：持续过载/堵转检查（1ms 节拍）。
     * 对 Ibus 做一阶 IIR 低通(τ≈128ms)，超过持续阈值置 OVERLOAD。
     * 与瞬时过流(短路)互补：堵转电流可能不超瞬时阈值却持续发热。 */
    MC_Fault_CheckOverload();

    /* L2 慢保护：霍尔信号丢失检查（1ms 节拍，仅 RUNNING 态生效）。
     * 运行中距上次合法 Hall 边沿超 HALL_TIMEOUT_MS 置 HALL_TIMEOUT。
     * hall_age 经 HALL_MsSinceLastEdge() 传入,避免 MC_Fault 反向依赖 hall 模块[fault读hall模块]。 */
    MC_Fault_CheckHall(HALL_MsSinceLastEdge(), s_motor_state == MOTOR_STATE_RUNNING);

    /* 一次性命令快照：本拍消费后清零（状态机不写回，重启须显式 START）。 */
    Motor_Cmd_e cmd = s_command;
    s_command = MOTOR_CMD_NONE;

    /* 故障优先分流：任意 fault → FAULT 态。 */
    if (MC_HasAnyFault()) {
        s_motor_state = MOTOR_STATE_FAULT;
    } else if (cmd == MOTOR_CMD_STOP) {
		/* 
	     * 仅运行/启动途中的态响应；CMD_STOP 硬停--STOPPED
	     * 集中于此预分流，避免 switch 各 case 重复处理 STOP。 */
        s_motor_state = MOTOR_STATE_STOPPED;
    }
    
    switch (s_motor_state) {
        case MOTOR_STATE_FAULT:
            /* 故障吸收态：硬关 6 管 + 清占空比，与 STOPPED 动作一致。
             * 区别在于：此处拒绝任何启动路径，仅响应"清故障"事件。
             * fault 已由上文前置分流，本 case 进入时 fault 必为 true；
             * 当外部清故障后，下一拍 fault=false，本分支转出 → STOPPED。 */
            Drive_Enable(false);
            if (MC_Ramp_GetCurrentDuty() != 0) MC_Ramp_ForceZero();
            if (!MC_HasAnyFault()) {
                s_motor_state = MOTOR_STATE_STOPPED;
            }
            break;

        case MOTOR_STATE_STOPPED:
            /* 停机：关驱动输出（模式分发）+ 清占空比。
             * 启动条件：CMD_START → 进入预充电瞬态。 */
            Drive_Enable(false);
            if (MC_Ramp_GetCurrentDuty() != 0) MC_Ramp_ForceZero();
            if (cmd == MOTOR_CMD_START) {
                s_motor_state = MOTOR_STATE_BOOTSTRAP;
            }
            break;

        case MOTOR_STATE_BOOTSTRAP:
            /* 瞬态：自举充电。六步=下桥常通(HOFF_LON)；SPWM=下桥 50% PWM 充电
             * (HOFF_LPWM：风车态限流 + PDC 预置 50% 中点便于交接，先置 PDC 再切 Override)。 */
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
            PWM_SetDuty_UVW(BOOTSTRAP_CHARGE_DUTY, BOOTSTRAP_CHARGE_DUTY, BOOTSTRAP_CHARGE_DUTY);
            PWM_HighOffLowPwm();
#else
            PWM_HighOffLowOn();
#endif
            s_bootstrap_start_ms = MC_GetTickMs();
            s_motor_state = MOTOR_STATE_CHARGING;
            break;

        case MOTOR_STATE_CHARGING:
            /* 稳态：等待 50ms 自举电容充电完成。 */
            if ((MC_GetTickMs() - s_bootstrap_start_ms) >= BOOTSTRAP_CHARGE_MS) {
				/*本拍只负责关断所有mos，以结束自举电容充电
				 *下一拍才可能需要控制mos让电机换相
				 *所以关闭所有Mos后，(6-step 算法控制)前，有一拍的关断裕量，不会误直通
			     */
				PWM_AllOff();
				//关断裕量：为一拍
                s_ready_ms = 0;
                s_motor_state = MOTOR_STATE_READY;
            }
            break;

        case MOTOR_STATE_READY:
            /* 就绪：PWM 使能，自举已充，等旋钮指令。
             * 旋钮>0 → RUNNING
             * 超时30s且旋钮=0 → STOPPED */
            if (MC_GetKnobSpeed() > 0) {
            	/* 重置霍尔边沿计时基准:把 HALL_TIMEOUT 窗口从"进入运行"起算,
                 * 防长时间停机后重启时旧时戳导致首个 RUNNING 拍误报 HALL_TIMEOUT。 */
            	HALL_ResetEdgeTimer();
            	/* 驱动使能（模式分发）：各模式在自身 Enable(true) 内完成安全预置——
                 * 六步先置 PDC=0 再恢复上桥 PWM + 用当前 Hall 建立换相初态；
                 * SPWM 先预置 50% 零矢量再交还互补自主控制。 */
                Drive_Enable(true);
                s_motor_state = MOTOR_STATE_RUNNING;
            } else if (++s_ready_ms >= READY_TIMEOUT_MS) {
                s_motor_state = MOTOR_STATE_STOPPED;
            }
            break;

        case MOTOR_STATE_RUNNING:
            /* CMD_STOP 已在顶部预分流硬停 → STOPPED（立即关 PWM）。
             * 旋钮归零缓停 → READY 待速（区别于 KEY1 的硬停彻底停）。 */
			MC_Ramp_Step();
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SIXSTEP)
            /* 六步：1ms 节拍把幅值三相同幅值写 PDC；
             * SPWM 不走这里，由 50µs Motor_Tick50us 的 Drive_Output 输出。 */
            Drive_Output();
#endif
			if (MC_GetKnobSpeed() == 0 && MC_Ramp_GetCurrentDuty() == 0) {
				/* 缓停完毕：回到ready */
                s_ready_ms = 0;
                s_motor_state = MOTOR_STATE_READY;
            }
            break;
    }
}

/*
 * 获取电机统一句柄（快照聚合）
 * 每次调用刷新全部动态字段（state/mode/fault/hall/en/duty/age/angle）。
 * ramp 指针为绑定关系，初始化后不变。
 *
 * 仅允许在主循环（Tier-2/Tier-3）上下文调用；严禁 ISR 内调用
 * （多字段非原子快照，存在读撕裂风险）。
 */
Motor_Handle_t* Motor_GetHandle(void) {
    s_motor_handle.state            = s_motor_state;
    s_motor_handle.drive_mode       = MC_DRIVE_MODE;
    s_motor_handle.fault            = MC_GetFault();
    s_motor_handle.hall_status      = HALL_GetHallStatus();
    s_motor_handle.drive_en         = Drive_IsEnabled();
    s_motor_handle.target_duty      = s_motor_handle.ramp->target_duty;
    s_motor_handle.current_duty     = MC_Ramp_GetCurrentDuty();
    s_motor_handle.last_edge_age_ms = HALL_MsSinceLastEdge();
#if (MC_DRIVE_MODE == MC_DRIVE_MODE_SPWM)
    s_motor_handle.rotor_angle16    = s_angle.theta.part.whole;
    s_motor_handle.mod_angle16      = Motor_GetModAngle16();
#else
    s_motor_handle.rotor_angle16    = 0u;
    s_motor_handle.mod_angle16      = 0u;
#endif
    return &s_motor_handle;
}
