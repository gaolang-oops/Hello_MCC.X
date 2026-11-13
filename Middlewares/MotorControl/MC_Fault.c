/*
 * MC_Fault.c
 *
 * 故障管理模块实现(motor 层)
 *
 * 分层归属:
 *   - MC_OverCurrentCheck -> Tier-1 (ADC ISR 回调)
 *   - MC_HasAnyFault      -> Tier-2 (1ms 主循环消费,Motor_Tick)
 *
 * 数据流:
 *   ia/ib/ic/ibus 采样(BSP)
 *     └─ mc_services 封装（OC_Is* / GetCurrentIbusmA，物理量接口）
 *        └─ MC_OverCurrentCheck 判定 ─→ s_fault_flags
 *           └─ state_machine STOPPED 清除
 *   raw 换算、过流阈值预计算全部封装在 BSP 层，本模块只处理"保护策略"
 *   （阈值 mA、blanking、过载 IIR），不感知 raw / 标定常量。
 *
 * Blanking 屏蔽期:
 *   换相后 MC_BLANKING_US(=150μs,物理时长)内跳过过流检测,
 *   避免六步换相的电流尖峰误触发。时戳源 = ADC 50us tick
 *   (与采样节拍对齐;Hall ISR 优先级 7 > ADC ISR 6,写不被打断)。
 *   BLANKING_TICKS 由 MC_US_TO_PWM_TICKS(MC_BLANKING_US) 编译期派生,
 *   改 PWM 频率时物理时长不变,tick 数自动重算。
 */

#include "MC_Fault.h"
#include "mc_services.h"    /* MC_OC_* 语义接口（封装 raw 换算）/ Ibus mA / 时基 */
#include <stdlib.h>

/* ---- 保护策略参数（占位，需台架实测后调整） ---- */
#define OC_THRESHOLD_MA      2500U     /* 过流阈值 2.5A；满量程 ±3A，留 0.5A 线性区裕量 */
#define MC_BLANKING_US       150U      /* 换相后过流屏蔽期(物理时长,与 PWM 频率解耦) */
#define BLANKING_TICKS       (MC_US_TO_PWM_TICKS(MC_BLANKING_US))   /* 自动派生:150μs/50μs = 3 */

/* VBUS 保护阈值（占位，24V 系统，需台架实测调整） */
#define OV_THRESHOLD_MV      32000U    /* 过压 32V：24V 系统 +33% 裕量（泵升/充电过高） */
#define UV_THRESHOLD_MV      18000U    /* 欠压 18V：24V 系统 -25% 裕量（电池放电过低） */

/* ---- Tier-2 持续过载保护参数（占位，需台架按电机额定标定） ----
 * 一阶 IIR 低通: out += (in - out) >> N, 等效时间常数 τ ≈ 2^N × T_sample
 *   T_sample = 1ms, N=7 -> τ ≈ 128ms（近似电机热时间常数的快分量）。
 * 阈值取低于瞬时 OC(2.5A) 的持续值，防堵转/长时过载发热烧 MOS。 */
#define OVERLOAD_THRESHOLD_MA   1500U   /* 持续过载阈值 1.5A（占位，按电机额定调） */
#define OVERLOAD_IIR_SHIFT      7U      /* τ ≈ 128ms */

/* ---- Tier-2 霍尔信号丢失保护参数（占位，需台架按电机最低工作转速标定） ----
 * 运行中距上次合法 Hall 边沿超过此时长 -> HALL_TIMEOUT。
 * 取值须 > 最低工作转速下的单边沿间隔(含裕量);过小会在强载低速爬行时误报。
 * 参考: ST MCSDK 由最小可靠转速动态派生(兜底 150ms);本项目开环调速暂用固定值。 */
#define HALL_TIMEOUT_MS         600U    /* 霍尔信号丢失阈值 600ms（占位，按最低转速调） */

/* ---- 模块状态 ---- */
static volatile uint16_t  s_fault_flags = 0;
static volatile uint16_t  s_last_commutate_tick = 0;
static uint16_t           s_blanking_ticks = 0;   /* 六步=BLANKING_TICKS；SPWM=0（无换相尖峰） */
static int32_t            s_ibus_filt = 0;   /* Ibus 一阶 IIR 低通输出(mA)；主循环读写，非 ISR */
/* 驱动失能钩子：Motor_Init 注入，过流 ISR 调用；未注入时为 NULL */
static volatile MC_Fault_DriveOffHook_t s_drive_off_hook = NULL;

/* ---- 过流现场快照（ISR 写、主循环取；pending 置位前先写完） ---- */
static volatile MC_Fault_Snapshot_t      s_oc_snapshot;
static volatile bool                     s_oc_snapshot_pending = false;


/* ---- 公共 API ---- */

void MC_Fault_Init(void)
{
    s_fault_flags = 0;
    s_last_commutate_tick = 0;
    s_ibus_filt = 0;
    s_oc_snapshot_pending = false;

    /* 换相 blanking 只属于六步：SPWM 连续调制，没有换相尖峰。
     * 若 SPWM 也保留 BLANKING_TICKS，s_last_commutate_tick 不被 MC_NotifyCommutation
     * 更新（恒 0），会在 50µs tick 每 3.2768s 回卷时产生约 150µs 的意外盲区。
     * 用满量程区分模式：SPWM 3500 -> 0；六步 7000 -> BLANKING_TICKS。 */
    s_blanking_ticks = (MC_DUTY_FULLSCALE < 4000u)
                     ? 0u
                     : (uint16_t)BLANKING_TICKS;
    /* 把过流阈值(mA)下发给 BSP，由其预计算 raw 比较值（含一次除法，仅启动期）。
     * 之后 ISR 热路径 MC_OC_Is* 仅做字面量比较，无运行时换算。 */
    MC_OC_Configure(OC_THRESHOLD_MA);
    /* 经接缝自注册到 50us tick */
    MC_RegisterTick50us(MC_OverCurrentCheck);
}

void MC_Fault_SetDriveOffHook(MC_Fault_DriveOffHook_t hook)
{
    s_drive_off_hook = hook;   /* 单字写原子；须在 GlobalEnable 前注入 */
}

bool MC_Fault_SnapshotTake(MC_Fault_Snapshot_t *out)
{
    uint16_t ipl_saved;
    bool pending;

    /* 与 ADC ISR 内的快照写入互斥：短临界区只做一次结构体拷贝 */
    SET_AND_SAVE_CPU_IPL(ipl_saved, 7);
	/* ADC 50us ISR中会进行过流检测，如果过流会填充s_oc_snapshot，并置位 pending */
    pending = s_oc_snapshot_pending;
    if (pending) {
        *out = s_oc_snapshot;
        s_oc_snapshot_pending = false;
    }
    RESTORE_CPU_IPL(ipl_saved);

    return pending;
}

void MC_SetFault(MC_Fault_e f)
{
    uint16_t ipl_saved;
    SET_AND_SAVE_CPU_IPL(ipl_saved, 7);
    s_fault_flags |= (uint16_t)f;
    RESTORE_CPU_IPL(ipl_saved);
}

void MC_ClearFault(MC_Fault_e f)
{
    uint16_t ipl_saved;
    SET_AND_SAVE_CPU_IPL(ipl_saved, 7);
    s_fault_flags &= (uint16_t)~(uint16_t)f;
    RESTORE_CPU_IPL(ipl_saved);
}

void MC_ClearAllFaults(void)
{
    s_fault_flags = 0;
}

bool MC_HasAnyFault(void)
{
    return (s_fault_flags != 0u);
}

MC_Fault_e MC_GetFault(void)
{
    return (MC_Fault_e)s_fault_flags;
}
/*此函数由换相函数调用*/
void MC_NotifyCommutation(void)
{
    /* uint16_t 写原子;Hall ISR(7) > ADC ISR(6),不被过流回调打断 */
    s_last_commutate_tick = MC_GetTick50us();
}

void MC_OverCurrentCheck(void)
{
    /* 1) Blanking:六步换相尖峰屏蔽期内跳过（SPWM 下 s_blanking_ticks=0，不屏蔽） */
    if ((uint16_t)(MC_GetTick50us() - s_last_commutate_tick) < s_blanking_ticks) {
        return;
    }

    /* 2) 过流判定（语义接口，raw 换算/阈值比较封装在 BSP 层）。
     *    阈值 OC_THRESHOLD_MA 已在 Init 时经 MC_OC_Configure 下发预计算。
     *    相电流双向判定(Ia/Ib/Ic)，Ibus 单向上限判定。 */
    if (MC_OC_IsPhaseOver() || MC_OC_IsIbusOver()) {
        int16_t ia, ib, ic, ibus;

        /* ---- 过流现场快照：仅在本次 OVER_CURRENT 上升沿捕获 ----
         * 必须发生在驱动失能钩子与 MC_SetFault 之前：
         *   - 取到的是跳闸前的 state/duty/角度/电流；
         *   - 锁存后每 50us 仍会重新判定，用上升沿条件避免反复覆盖。
         * 阈值掩码从同一组 mA 值计算，只有跳闸时才做，热路径不变。 */
        if ((s_fault_flags & (uint16_t)MC_FAULT_OVER_CURRENT) == 0u) {
            MC_Fault_Snapshot_t snap;
            uint16_t mask = 0u;

            ia   = MC_GetCurrentIamA();
            ib   = MC_GetCurrentIbmA();
            ic   = MC_GetCurrentIcmA();
            ibus = MC_GetCurrentIbusmA();

            if (abs((int)ia)   > (int)OC_THRESHOLD_MA) mask |= 0x01u;
            if (abs((int)ib)   > (int)OC_THRESHOLD_MA) mask |= 0x02u;
            if (abs((int)ic)   > (int)OC_THRESHOLD_MA) mask |= 0x04u;
            if (abs((int)ibus) > (int)OC_THRESHOLD_MA) mask |= 0x08u;

            snap.tick_ms     = MC_GetTickMs();
            snap.over_mask   = mask;
            MC_GetCurrentRawSnapshot(&snap.raw_ia, &snap.raw_ib,
                                     &snap.raw_ic, &snap.raw_ibus);
            snap.ma_ia   = ia;
            snap.ma_ib   = ib;
            snap.ma_ic   = ic;
            snap.ma_ibus = ibus;

            s_oc_snapshot         = snap;
            s_oc_snapshot_pending = true;
        }

        /* L1 快保护：ADC ISR 内立即处置（执行MC_OverCurrentCheck）。
         * 过流场景下 MOS 电流可达几十~上百 A，1ms 足以烧穿，必须 μs 级响应。
         *
         * ① 驱动失能钩子：由 Motor_Init 注入（内部即 Drive_Enable(false)），
         *    模式无关（六步清换相闸门 / SPWM 清调制闸门），内部 PWM_AllOff 硬关 6 管。
         *    - 闸门清零阻止下个 Hall 沿(六步)或下一个 50µs 调制拍(SPWM)再开输出
         *    - 与 Hall/ADC ISR 并发安全：最坏竞争写 Override 寄存器，
         *      PWM_AllOff 是安全态，"最后写入者胜"对结果无影响（终态都是关断）。
         * ② MC_SetFault：置标志，让状态机 FAULT 态接管后续（锁存/拒绝重启）。 */
        if (s_drive_off_hook) {
            s_drive_off_hook();
        }
        MC_SetFault(MC_FAULT_OVER_CURRENT);
    }
}

/*
 * L2 慢保护：母线电压检查（1ms 状态机层）。
 * 时间常数：母线大电容（几百~几千 μF）钳位，电压不能突变，变化 10ms+，
 *           1ms 状态机响应足够。不需像过流那样在 ISR 抢 μs 级。
 * 数据源：flt_vbus（SMA 64 点滤波，3.2ms 滞后，抗干扰）。
 *        滤波延迟对慢保护无影响；上电时 main.c 已 Delay_ms(500)，
 *        远超滤波建立时间，故直接启用不会误报。
 * 动作：仅 MC_SetFault。本拍置标志，Motor_Tick 紧随其后的
 *       fault 前置分流会当拍进 FAULT 态，下拍关 PWM（最坏延迟 <1ms）。
 *       不在 ISR 内立即关断——电压保护不需要 μs 级响应。
 */
void MC_Fault_CheckVoltage(void)
{
    uint16_t vbus = MC_GetVbusMv();
    if (vbus > OV_THRESHOLD_MV) {
        MC_SetFault(MC_FAULT_OVER_VOLTAGE);
    } else if (vbus < UV_THRESHOLD_MV) {
        MC_SetFault(MC_FAULT_UNDER_VOLTAGE);
    }
}

/*
 * L2 慢保护：持续过载/堵转检查（1ms 状态机层）。
 * 与 Tier-1 瞬时过流(短路,μs 级)互补：堵转时电流可能始终不超瞬时阈值(2.5A)，
 * 却持续发热烧 MOS。本检查对 Ibus 做一阶 IIR 低通(τ≈128ms)，逼近热累积效应，
 * 超过持续过载阈值(1.5A，占位)则置 OVERLOAD。
 *
 * 数据源：MC_GetCurrentIbusmA（已修正的 Ibus mA，无偏置链路）。
 * 停机时 Ibus≈0，IIR 自然衰减到 0，无误报；冷启动 Init 已清零。
 * 动作：仅 MC_SetFault，交状态机 FAULT 态（ms 级响应，发热是慢过程）。
 */
void MC_Fault_CheckOverload(void)
{
    int32_t iabs = (int32_t)abs((int)MC_GetCurrentIbusmA());
    /* 一阶 IIR: out += (in - out) >> N ；τ ≈ 2^N × T = 128 × 1ms = 128ms */
    s_ibus_filt += (iabs - s_ibus_filt) >> OVERLOAD_IIR_SHIFT;
    if (s_ibus_filt > (int32_t)OVERLOAD_THRESHOLD_MA) {
        MC_SetFault(MC_FAULT_OVERLOAD);
    }
}

/*
 * L2 慢保护：霍尔信号丢失检查（1ms 状态机层）。
 * 判定：motor_running 且 hall_age_ms > HALL_TIMEOUT_MS -> HALL_TIMEOUT。
 * 数据源：hall_age_ms 由调用方(Motor_Tick)经 HALL_MsSinceLastEdge() 传入,
 *        这样的话，本模块就不用关心hall的情况，即不直接hall_speed_fdbk(保持 MC_Fault -> mc_services -> BSP 单向)。
 * 仅 RUNNING 态生效：BOOTSTRAP/CHARGING 电机尚未换相、STOPPED 无输出,
 *        这些态下hall无边沿属正常。(形参motor_running 由调用方按状态机判定)。
 * 动作：仅 MC_SetFault;交状态机 FAULT 态接管(ms 级响应,信号丢失是慢过程)。
 */
void MC_Fault_CheckHall(uint16_t hall_age_ms, bool motor_running)
{
    if (motor_running && hall_age_ms > HALL_TIMEOUT_MS) {
        MC_SetFault(MC_FAULT_HALL_TIMEOUT);
    }
}
