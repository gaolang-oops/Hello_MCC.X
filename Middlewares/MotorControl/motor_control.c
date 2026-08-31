/*
 * File:   motor_control.c
 * Author: gaol
 *
 * 电机层统一编排入口（对齐 ST MCSDK M1 任务接缝思想）：
 *   - Motor_Init    : 集中初始化 motor 层全部子模块（状态机/Ramp/六步/Hall/Fault）
 *   - Motor_Tick    : 1ms 节拍推进状态机（Tier-2 控制层），由主循环调用
 *
 * 命令模型（对齐 ST MCSDK DirectCommand）：
 *   应用层（按键/协议）经 Motor_SetCommand 下发一次性命令（START/STOP），
 *   状态机每拍快照后清零消费 —— 状态机不写回命令。
 *   重启须显式再次下发 START（故障清除 / 超时后自动 re-arm，无电平残留）。
 *
 * 初始化顺序约束：
 *   SIXSTEP_Init（注册 s_on_edge 到 hall）  → 须先于 HALL_Init
 *   HALL_Init（注册 IC ISR 到 BSP）         → 须先于 GlobalEnable
 *   MC_Fault_Init（注册过流回调到 50us tick）→ 须先于 GlobalEnable
 *   全部在 main.c 的 BSP init 段之后、GlobalEnable 之前完成。
 */

#include "motor_control.h"
#include "pwm_common.h"
#include "six_step.h"
#include "mc_ramp.h"
#include "mc_services.h"   /* 时基 + 旋钮指令（motor 层唯一平台接缝）*/
#include "MC_Fault.h"      /* MC_HasAnyFault / MC_Fault_Init */
#include "hall_speed_fdbk.h"

static Motor_State_e s_motor_state = MOTOR_STATE_STOPPED;
static uint16_t s_bootstrap_start_ms = 0;        /* 自举充电起始时间戳 */
static uint16_t s_ready_ms = 0;                  /* READY 态停留计时 */
static Motor_Cmd_e s_command = MOTOR_CMD_NONE;   /* 一次性命令锁存（应用层写，状态机消费清零）*/
static Motor_Handle_t s_motor_handle;            /* 统一句柄（快照聚合）*/

void Motor_SetCommand(Motor_Cmd_e cmd) {
    s_command = cmd;   /* 末写胜；单一应用上下文（主循环 Tier-4），无竞态 */
}

void Motor_Init(void) {
    s_motor_state = MOTOR_STATE_STOPPED;
    s_command     = MOTOR_CMD_NONE;
    s_ready_ms    = 0;
    MC_Ramp_Init();
    SIXSTEP_Init();    /* 注册 s_on_edge → hall，须先于 HALL_Init */
    HALL_Init();       /* 种子读取 + 注册 IC ISR → BSP */
    MC_Fault_Init();   /* 清故障标志 + 注册 50us 过流回调 */
    /* 绑定统一句柄 */
    s_motor_handle.state            = MOTOR_STATE_STOPPED;
    s_motor_handle.ramp             = MC_Ramp_GetHandle();
    s_motor_handle.fault            = MC_FAULT_NONE;
    s_motor_handle.hall_status      = 0;
    s_motor_handle.six_step_en      = false;
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
            SIXSTEP_Enable(false);
            if (MC_Ramp_GetCurrentDuty() != 0) MC_Ramp_ForceZero();
            if (!MC_HasAnyFault()) {
                s_motor_state = MOTOR_STATE_STOPPED;
            }
            break;

        case MOTOR_STATE_STOPPED:
            /* 停机：关换相闸门 + 清占空比。
             * 启动条件：CMD_START → 进入预充电瞬态。 */
            SIXSTEP_Enable(false);
            if (MC_Ramp_GetCurrentDuty() != 0) MC_Ramp_ForceZero();
            if (cmd == MOTOR_CMD_START) {
                s_motor_state = MOTOR_STATE_BOOTSTRAP;
            }
            break;

        case MOTOR_STATE_BOOTSTRAP:
            /* 瞬态：三相下管常通，启动自举充电计时 */
            PWM_HighOffLowOn();
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
            	//释放上桥 override 交还 PWM
            	//内部会OVRENH=0(上桥受PWM控制), OVRENL=1 保持(下桥由 6-step 每次换相维护)
				//使能换相，用当前 Hall 立即建立初态
                SIXSTEP_Enable(true);
                s_motor_state = MOTOR_STATE_RUNNING;
            } else if (++s_ready_ms >= READY_TIMEOUT_MS) {
                s_motor_state = MOTOR_STATE_STOPPED;
            }
            break;

        case MOTOR_STATE_RUNNING:
            /* CMD_STOP 已在顶部预分流硬停 → STOPPED（立即关 PWM）。
             * 旋钮归零缓停 → READY 待速（区别于 KEY1 的硬停彻底停）。 */
			MC_Ramp_Step();
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
 * 每次调用刷新全部动态字段（state/fault/hall/six_step/duty/age）。
 * ramp 指针为绑定关系，初始化后不变。
 *
 * 仅允许在主循环（Tier-2/Tier-3）上下文调用；严禁 ISR 内调用
 * （多字段非原子快照，存在读撕裂风险）。
 */
Motor_Handle_t* Motor_GetHandle(void) {
    s_motor_handle.state            = s_motor_state;
    s_motor_handle.fault            = MC_GetFault();
    s_motor_handle.hall_status      = HALL_GetHallStatus();
    s_motor_handle.six_step_en      = SIXSTEP_IsEnabled();
    s_motor_handle.target_duty      = s_motor_handle.ramp->target_duty;
    s_motor_handle.current_duty     = MC_Ramp_GetCurrentDuty();
    s_motor_handle.last_edge_age_ms = HALL_MsSinceLastEdge();
    return &s_motor_handle;
}
