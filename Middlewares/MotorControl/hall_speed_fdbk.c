/*
 * File:   hall_speed_fdbk.c
 * Author: gaol
 *
 * Created on 2026年7月23日, 下午3:54
 *
 * Hall 速度/位置反馈模块
 *
 * 职责（硬件单一 owner）：
 *   - 独占 hall_status 变量
 *   - 经 mc_services 注册 IC ISR 处理函数（去抖 + 事件上抛）
 *   - 接收 BSP 排空 FIFO 后的最新捕获值，在去抖接受的边沿上计算
 *     跨通道 60° 间隔 dt（相邻合法 Hall 跳变 = 60° 电角度），
 *     并对最近 6 个有效间隔做滑动平均
 *   - 通过观察者回调 HALL_RegisterOnEdge() 向上层(drive)通知 Hall 跳变
 *   - 由相邻 Hall 跳变判别实测方向（仅供监督/诊断）
 *   - 命令方向由控制层经 HALL_SetCmdDirection() 下发，决定 step 符号
 *   - 种子初始化，避免冷启动 hall_status=0
 *
 * 依赖方向：hall_speed_fdbk -> mc_services -> bsp_ICx
 * 反向控制：drive 层(six_step) 在 init 时注册回调，本模块不知道 drive 是谁（DIP）。
 */

#include "hall_speed_fdbk.h"
#include "mc_services.h"
#include "MC_Fault.h"
#include "../../user_manager.h"
#include <stdbool.h>
#include <stdlib.h>

/* ================= 调试：Hall ISR 耗时测量 =================
 * LED1 = RE13，低电平点亮。示波器探头接 MCU 的 RE13 引脚，
 * 下降沿触发，测低电平脉宽。
 *
 * 注意：LED_On/Off 是函数调用，开销会污染微秒级测量；这里直接写
 * LATEbit，只有一条位写指令。测量完成后把 HALL_TIMING_DEBUG 改为 0。
 */
#define HALL_TIMING_DEBUG             1

#if HALL_TIMING_DEBUG
#define HALL_TIMING_BEGIN()   (_LATE13 = 0)   /* LED1 亮，低脉冲起点 */
#define HALL_TIMING_END()     (_LATE13 = 1)   /* LED1 灭，低脉冲终点 */
#else
#define HALL_TIMING_BEGIN()   do {} while (0)
#define HALL_TIMING_END()     do {} while (0)
#endif

/* ---- 转子电角度表（brad16：0~65535 ⇔ 0~360°） ----
 * 表项含义：进入该 Hall 状态的瞬间，转子所处的电角度（扇区进入沿）。
 *
 * Hall 组合值 bit2=U(IC1) bit1=V(IC2) bit0=W(IC3)。
 * 正转: 5[210°] -> 4[270°] -> 6[330°] -> 2[30°] -> 3[90°] -> 1[150°]
 * 反转: 1[210°] -> 3[150°] -> 2[90°] -> 6[30°] -> 4[330°] -> 5[270°]

 * 0/7 为非法 Hall 态，填 HALL_ANGLE_INVALID。
 */
#define HALL_ANGLE_DEG(d)  ((uint16_t)(((uint32_t)(d) * 65536u + 180u) / 360u))
#define HALL_ANGLE_60      10923u   /* 60°(brad16)，相邻 Hall 扇区的角度差 */

static const uint16_t s_hall_angle_fwd[8] = {
    [0] = HALL_ANGLE_INVALID,
    [1] = HALL_ANGLE_DEG(150),
    [2] = HALL_ANGLE_DEG(30),
    [3] = HALL_ANGLE_DEG(90),
    [4] = HALL_ANGLE_DEG(270),
    [5] = HALL_ANGLE_DEG(210),
    [6] = HALL_ANGLE_DEG(330),
    [7] = HALL_ANGLE_INVALID,
};

static const uint16_t s_hall_angle_rev[8] = {
    [0] = HALL_ANGLE_INVALID,
    [1] = HALL_ANGLE_DEG(210),
    [2] = HALL_ANGLE_DEG(90),
    [3] = HALL_ANGLE_DEG(150),
    [4] = HALL_ANGLE_DEG(330),
    [5] = HALL_ANGLE_DEG(270),
    [6] = HALL_ANGLE_DEG(30),
    [7] = HALL_ANGLE_INVALID,
};

/* ---- 霍尔非法状态确认参数(对齐 ST bSpeedErrorNumber 连续确认模式) ----
 * 去抖通过后仍为 000/111 视为一次"非法事件",连续 N 次才报 HALL_INVALID 故障。
 * 抗换相瞬间霍尔线瞬态噪声产生的短促 0/7;任何合法(1~6)去抖读即重置计数。 */
#define HALL_INVALID_CONFIRM_N   3U

/*
 * hall_status bit 布局: bit2=U(IC1), bit1=V(IC2), bit0=W(IC3)
 */
static volatile uint8_t hall_status;

/* 实测方向：由 HALL_UpdateDirection 在每次合法 Hall 跳变后更新，仅用于监督/诊断。 */
static volatile HALL_Dir_e s_dir_meas = HALL_DIR_FWD;

/* 命令方向：控制层期望的旋转方向，决定 HALL_UpdateStep 的符号。
 * 默认 FWD；由 HALL_SetCmdDirection 设置。
 * 写方：主循环；读方：Hall ISR。单字写原子。 */
static volatile HALL_Dir_e s_dir_cmd = HALL_DIR_FWD;

/* s_prev_hall 仅 ISR 访问，用于计算相邻跳变在正转角度表上的差值。 */
static volatile uint8_t    s_prev_hall = 0u;

/* 最近一次合法 Hall 边沿的时间戳(ms)。供测速/堵转检测使用。
 * 写方: HALL_OnIsr(IC ISR 优先级7);读方: Tier-2 主循环(优先级0)。volatile uint16_t 原子。 */
static volatile uint16_t s_last_edge_tick_ms = 0;

/* ---- 跨通道 60° dt 状态 ----
 * 写方: HALL_OnIsr(IC ISR)；读方: Tier-2 主循环。
 * dt_ticks 为最近最多 6 个有效 60° 间隔的滑动平均（T3CLK tick），
 * 每个合法沿更新一次；满 6 个后固定为 6 样本平均。
 * 本次捕获溢出/积压/不合理时不更新窗口，保留旧值；
 * 消费方用 HALL_MsSinceLastEdge() 判新鲜度。
 * prev_cap/prev_hall/have_prev 描述"上一次合法边沿"，必须成组推进。
 */
typedef struct {
/* 滑动平均窗口：6 个相邻 60° 间隔 = 一个电周期(360°) */
#define HALL_DT_AVG_N           6u

    volatile uint16_t dt_ticks;   /* 最近 6 个有效 60° 间隔的滑动平均；0=尚未建立 */
    volatile HALL_StepQ16_t step; /* 每 PWM 增量 16.16（有符号）：正转正、反转负 */
    uint16_t prev_cap;            /* 上一次合法边沿的 ICxTMR 捕获值 */
    uint8_t  prev_hall;           /* 上一次合法边沿的 Hall 状态 */
    volatile bool have_prev;      /* prev_cap/prev_hall 是否有效 */

    /* 60° 间隔滑动平均窗口 */
    uint16_t hist[HALL_DT_AVG_N]; /* 最近最多 6 个有效间隔 */
    uint32_t hist_sum;            /* hist[] 元素之和 */
    uint8_t  hist_idx;            /* 写指针；满时指向最旧值 */
    bool     hist_full;           /* true = 窗口已满，此后一直满 */
} HALL_DtState_t;

static HALL_DtState_t s_dt;

/* K = (65536/6) * (Fcy / (256 * Fpwm))
 *   = 149333（dt=1 tick 时的 brad16 增量）
 * 依赖：_XTAL_FREQ、BSP_PWM_FREQUENCY_HZ、T3 TCKPS=1:256。
 * 改时钟/PWM 频率/T3 预分频时须同步 HALL_T3_PRESCALER。
 * 编译期 64 位常量折叠，无运行时开销。 */
#define HALL_T3_PRESCALER   256UL
#define HALL_STEP_K  ((uint32_t)((65536ULL * (_XTAL_FREQ / 2ULL)) / \
                                 (6ULL * HALL_T3_PRESCALER * BSP_PWM_FREQUENCY_HZ)))

/* 合理性窗口（T3CLK tick，当前 3.657us/tick）：
 *   MIN = 10 tick ≈ 36.6us -> 仅用于排除 dt=0/重复沿/明显毛刺，
 *        不当作真实转速上限（真实上限应由电机最高电频率另定）
 *   MAX = 60000 tick ≈ 219ms -> 接近 16 位 ICxTMR 回卷(239.7ms)，
 *        再大无法区分"很慢"与"跨通道乱序/回卷"
 * 低速时 dt 超出 MAX 属于正常（本方法测不到），此时不更新速度。 */
#define HALL_DT_MIN_TICKS       10u
#define HALL_DT_MAX_TICKS       60000u

/* 最高转速限幅：4000 rpm @ p=2。
 * dt_limit = 10*T3CLK/(rpm*p)
 *          = 2,734,375/(4000*2) = 341.8 -> 342 tick（向上取整）。
 * 342 tick ≈ 3997.6 rpm，保证钳位后不超过 4000 rpm。
 * 低于此值时把 dt_ticks 钳到 342，HALL_UpdateStep 的 step 也随之受限。 */
#define HALL_DT_MAX_SPEED_TICKS 342u

/* 观察者回调：Hall 跳变去抖成功后上抛给 drive 层（反向控制，DIP） */
static volatile HallEdgeCallback_t s_on_edge = NULL;

static bool HALL_UpdateInputState(void);
static void HALL_UpdateDirection(uint8_t hall);
static void HALL_ResetDt(void);
static void HALL_UpdateStep(uint16_t dt);
static void HALL_UpdateDt(uint16_t cap, uint8_t cur_hall, uint8_t ovf);
static void HALL_OnIsr(uint8_t ch, uint16_t cap, uint8_t ovf);

/*
 * HALL_UpdateInputState
 * 直接读取3路引脚电平
 * bit2 = IC1 (RG8) U
 * bit1 = IC2 (RG7) V
 * bit0 = IC3 (RG6) W
 * 返回: true = hall_status 发生变化并已更新；false = 本次未更新（去抖失败/非法/无变化）
 */
static bool HALL_UpdateInputState(void)
{
    /* 霍尔非法状态(000/111)连续确认计数器。仅本函数访问(运行期经 HALL_OnIsr(IC ISR
     * 优先级7)进入);volatile 保持与模块内 hall_status/s_last_edge_tick_ms 的 ISR 状态
     * 约定一致。
     * 000/111 非法态,ISR 内连续确认，达 N 置 HALL_INVALID 故障,合法读重置。 */
    static volatile uint8_t s_invalid_count = 0;

    /* L1: 连续 3 次读一致才接受（防御窄毛刺） */
    uint8_t s0 = 0, s1 = 0, s2 = 0;
    s0 = MC_Hall_ReadStatus();
    s1 = MC_Hall_ReadStatus();
    s2 = MC_Hall_ReadStatus();
    if (s0 != s1 || s1 != s2)
    {
        return false; /* 不稳定 -> 丢弃本次，保留上次值 */
    }
    /* L0: BLDC 合法状态只有 6 个 (1~6)，000/111 非法。
     * 去抖通过后仍为 0/7 说明三线确定卡死(供电丢失/断线),但换相瞬间
     * 霍尔线可能有亚微秒毛刺产生短促 0/7,故连续 N 次确认才报故障。 */
    if (s0 == 0x00 || s0 == 0x07)
    {
        /* 递增与触发在 count 达 N 的同一拍发生;
         * 不能用 if-else——互斥分支会把触发推迟到第 N+1 拍(off-by-one)。
         * 饱和后不再递增/重复置标志,避免 ISR 热路径冗余。 */
        if (s_invalid_count < HALL_INVALID_CONFIRM_N) {
            if (++s_invalid_count == HALL_INVALID_CONFIRM_N)
                MC_SetFault(MC_FAULT_HALL_INVALID);   /* ISR 内原子置标志,FAULT 态接管关断 */
        }
        return false; /* 非法 -> 丢弃，保持上次有效值 */
    }
    /* 合法(1~6)去抖读 -> 重置非法计数器(瞬态噪声自愈) */
    s_invalid_count = 0;
    /* L2: 值未变化 -> 虚假中断，丢弃 */
    if (s0 == hall_status)
        return false;
    hall_status = s0;
    return true;
}

/* 清空 dt 状态：初始化与重启（HALL_ResetEdgeTimer）共用。
 * 清 base 后首个合法沿只重建基准，不产生 dt；滑动平均窗口同时清空。 */
static void HALL_ResetDt(void) {
    uint16_t ipl_saved;

    SET_AND_SAVE_CPU_IPL(ipl_saved, 7);
    s_dt.dt_ticks  = 0u;
    s_dt.step      = 0;
    s_dt.prev_cap  = 0u;
    s_dt.prev_hall = 0u;
    s_dt.have_prev = false;

    s_dt.hist_sum  = 0u;
    s_dt.hist_idx  = 0u;
    s_dt.hist_full = false;
    RESTORE_CPU_IPL(ipl_saved);
}

void HALL_Init(void) {
    /* 种子初始化：上电后主动读一次 Hall。
     * 若电机静止则无 Hall 跳变沿 -> 无中断 -> hall_status 恒为 0(非法)，
     * 会导致启动时换相走全关态而无法启动。
     * 此处全局中断尚未开启，HALL_UpdateInputState 为纯轮询读，安全。 */
    HALL_UpdateInputState();

    /* 建立判向基准：首个合法跳变即可由 prev->cur 角度差判方向 */
    s_prev_hall = hall_status;

    /* 建立 dt 基准：首个合法跳变只记录 cap，不产生 dt（无上一次边沿） */
    HALL_ResetDt();

    /* 注册 IC ISR 处理函数：边沿中断经 BSP 桥 -> mc_services -> 本函数 */
    MC_Hall_RegisterIsr(HALL_OnIsr);
}

uint8_t HALL_GetHallStatus(void) {
    return hall_status;   /* volatile uint8_t 读取原子 */
}

void HALL_RegisterOnEdge(HallEdgeCallback_t cb) {
    s_on_edge = cb;
}

HALL_Dir_e HALL_GetMeasuredDirection(void) {
    return s_dir_meas;   /* volatile 单字读取原子 */
}

HALL_Dir_e HALL_GetCmdDirection(void) {
    return s_dir_cmd;    /* volatile 单字读取原子 */
}

void HALL_SetCmdDirection(HALL_Dir_e dir) {
    /* 命令方向由控制层设置；Hall 沿只更新 s_dir_meas。
     * 与 Hall ISR 并发：单字写，原子。 */
    s_dir_cmd = dir;
}

uint16_t HALL_GetHallRotorPosition(void) {
	/* 控制参考系：与 step 同用命令方向，避免沿口重同步与积分参考系不一致。 */
    uint8_t hall = hall_status;
    const uint16_t *table;

    if (hall > 7u) {
        return HALL_ANGLE_INVALID;   /* 防御性钳位 */
    }
    table = (s_dir_cmd == HALL_DIR_REV) ? s_hall_angle_rev : s_hall_angle_fwd;
    return table[hall];   /* 0/7 表项为 HALL_ANGLE_INVALID */
}


uint16_t HALL_GetEdgeDtTicks(void) {
    return s_dt.dt_ticks;   /* volatile uint16_t 单字读取原子 */
}

HALL_StepQ16_t HALL_GetThetaStep(void) {
    /* 32 位快照非原子；调试/主循环读取时可能被 Hall ISR 打断。
     * 正式消费方若要求一致性，应加临界区或序号保护。 */
    return s_dt.step;
}

uint32_t HALL_GetStepK(void) {
    return HALL_STEP_K;
}

uint16_t HALL_GetSpeedRpm(void) {
    /* TODO: 速度计算待加速度环时实现。
     * 算法: 基于相邻两次合法 Hall 边沿的 ms 时戳差 + 极对数 POLE_PAIR_NUM 换算 RPM。
     * 注意低速场景(边沿间隔 > 测量窗)需回退为 0 或保持上次值,避免除零。 */
    return 0;
}

uint16_t HALL_MsSinceLastEdge(void) {
    return (uint16_t)(MC_GetTickMs() - s_last_edge_tick_ms);
}

/* 重置"距上次边沿"计时基准为当前时刻。
 * 调用时机: 进入 RUNNING 态前(自举充电完成、SIXSTEP_Enable(true) 之前)。
 * 目的: 把 HALL_TIMEOUT 检测窗口从"进入运行那一刻"起算,避免长时间停机后
 *       重启时 s_last_edge_tick_ms 仍是上次运行的旧时戳 -> 首个 RUNNING 拍
 *       age 已超阈值而误报 HALL_TIMEOUT。
 * 并发: 主循环(pri 0)与 HALL_OnIsr(pri 7)均写当前时戳,最坏差亚毫秒,可忽略。 */
void HALL_ResetEdgeTimer(void) {
    s_last_edge_tick_ms = MC_GetTickMs();

    /* 同时丢弃旧的速度基准：重启后首个 60° 间隔必须重新建立，
     * 防止上次运行的 dt 被当成当前速度。 */
    HALL_ResetDt();
}

/*
 * HALL_UpdateDirection
 * 直接查正转角度表：相邻合法 Hall 状态的角度差为 +60°（正转）或
 * -60°（反转）。差值 ±120° 表示漏掉一个 Hall 沿，仍可判向。
 *
 * 例：正转 1[150°] -> 5[210°]，delta = fwd[5]-fwd[1] = +60°；
 *     反转 5[210°] -> 1[150°]（查正转表），delta = -60°。
 *
 * 只更新实测方向 s_dir_meas，仅供监督/诊断；
 * 不修改命令方向 s_dir_cmd，因此不会影响 HALL_GetThetaStep() 的符号。
 * 仅在 ISR 内、HALL_UpdateInputState 返回 true 后调用。
 */
static void HALL_UpdateDirection(uint8_t hall) {
    uint8_t  prev = s_prev_hall;
    uint16_t ang_prev;
    uint16_t ang_cur;
    int16_t  delta;

    s_prev_hall = hall;
    if (hall == prev) {
        return;
    }

    ang_prev = s_hall_angle_fwd[prev];
    ang_cur  = s_hall_angle_fwd[hall];
    if (ang_prev == HALL_ANGLE_INVALID || ang_cur == HALL_ANGLE_INVALID) {
        return;   /* 基准非法（尚未建立种子）或当前非法，无法判向 */
    }

    delta = (int16_t)(uint16_t)(ang_cur - ang_prev);

    if (delta > 0 && delta <= (int16_t)(2u * HALL_ANGLE_60)) {
        s_dir_meas = HALL_DIR_FWD;   /* +60° 或 +120°（漏一个沿） */
    } else if (delta < 0 && delta >= -(int16_t)(2u * HALL_ANGLE_60)) {
        s_dir_meas = HALL_DIR_REV;   /* -60° 或 -120°（漏一个沿） */
    }
    /* 其余（接近 180° 或更大跳变）：方向不确定，保持上次方向 */
}

/*
 * HALL_SectorCount
 * 由两个合法 Hall 状态在正转角度表上的差值，判断实际跨过几个 60° 扇区。
 *   1 = 正常相邻跳变（60°）
 *   2 = 漏掉一个 Hall 沿（120°）
 *   0 = 非法状态/跳变 ≥180°，dt 不可用
 * 角度表与方向无关：反转时差值取绝对值后扇区数相同。
 * 仅在 ISR 内调用。
 */
static uint8_t HALL_SectorCount(uint8_t prev, uint8_t cur) {
    uint16_t ang_prev;
    uint16_t ang_cur;
    uint16_t d;
    uint16_t mag;

    if (prev > 7u || cur > 7u || prev == cur) {
        return 0u;
    }
    ang_prev = s_hall_angle_fwd[prev];
    ang_cur  = s_hall_angle_fwd[cur];
    if (ang_prev == HALL_ANGLE_INVALID || ang_cur == HALL_ANGLE_INVALID) {
        return 0u;
    }

    d   = (uint16_t)(ang_cur - ang_prev);
    mag = (d <= 32768u) ? d : (uint16_t)(65536u - d);

    /* 表项量化后 60° 差值为 10922/10923，120° 为 21844~21846，
     * 直接按 1×/2× 判档即可，无需 1.5×/2.5× 的中间带。 */
    if (mag <= HALL_ANGLE_60) {
        return 1u;                       /* 正常相邻跳变：60° */
    }
    if (mag <= (2u * HALL_ANGLE_60)) {
        return 2u;                       /* 漏一个沿：120° */
    }
    return 0u;                           /* ≥180°：dt 不可用 */
}

/*
 * HALL_UpdateStep
 * dt 有效时计算每 PWM 周期的角度增量，发布成真正的 16.16：
 *   q    = K / dt                  （整数 brad16/PWM）
 *   rem  = K % dt
 *   frac = (rem << 16) / dt        （低 16 位，1/65536 brad16）
 * 第一次用 __builtin_divmodud 拿商和余数；第二次用 __builtin_divud
 * 把余数换算成 16 位小数。两者都是 native 32/16 除法。
 * 约束：商必须能放进 16 位；dt >= HALL_DT_MIN_TICKS=10 时
 *       q <= 149333/10 = 14933，满足。
 * 命令方向符号在此应用：FWD -> 正值，REV -> 负值（二进制补码）。
 * 实测方向 s_dir_meas 不参与本符号，仅用于监督/诊断。
 * 消费方统一 theta_u32 += (uint32_t)s_dt.step 即可。
 */
static void HALL_UpdateStep(uint16_t dt) {
    uint16_t rem;
    uint16_t q;
    uint16_t frac;
    int32_t  step;
    uint16_t ipl_saved;

    if (dt == 0u) {
        step = 0;
    } else {
        // 如果除数为零，会导致mcu复位
        q    = __builtin_divmodud(HALL_STEP_K, dt, &rem);
        frac = __builtin_divud((uint32_t)rem << 16, dt);

        /* 先拼成正的 16.16 幅值，再按命令方向取负（补码）。
         * 幅值上界：dt >= HALL_DT_MIN_TICKS=10 -> q <= 14933，
         * 故 step < 0x3A560000，转 int32_t 绝不会溢出。 */
        step = (int32_t)(((uint32_t)q << 16) | frac);
        if (s_dir_cmd == HALL_DIR_REV) {
            step = -step;
        }
    }

    /* 32 位写非原子：SPWM 模式下 ADC ISR(50us tick) 优先级高于 IC ISR，
     * 可能在两次 16 位写之间打断并读到撕裂值；短临界区保护。 */
    SET_AND_SAVE_CPU_IPL(ipl_saved, 7);
    s_dt.step = step;
    RESTORE_CPU_IPL(ipl_saved);
}

/*
 * HALL_UpdateDt
 * 只有去抖接受的边沿才会调用。
 *   - ovf=1：cap 与当前 Hall 状态不保证对应同一边沿，丢弃基准，
 *            下一沿只重建、再下一沿恢复 dt；窗口与平均值保持不变；
 *   - 正常：dt = cap - 上一次 cap；扇区差 120°（漏一个沿）时 dt/2
 *            归一到 60°，再压入 6 元素窗口，运行和更新；
 *            均值用 __builtin_divud 求商，避免 / 运算符/库函数；
 *   - sectors=0 / 超窗 / 回卷 / 毛刺：不更新窗口，保留上一次平均值，
 *            不覆盖；step 也保持上一次值。
 */
static void HALL_UpdateDt(uint16_t cap, uint8_t cur_hall, uint8_t ovf) {
    uint16_t dt;
    uint8_t  sectors;
    uint8_t  n;

    if (ovf) {
        s_dt.have_prev = false;   /* 保留窗口和上一次平均值/step */
        return;
    }

    if (s_dt.have_prev) {
        dt      = (uint16_t)(cap - s_dt.prev_cap);
        sectors = HALL_SectorCount(s_dt.prev_hall, cur_hall);

        if (sectors != 0u &&
            dt >= HALL_DT_MIN_TICKS && dt <= HALL_DT_MAX_TICKS) {

            /* 漏一个沿时 dt 覆盖 120°，右移 1 位归一到 60° 再入窗 */
            if (sectors == 2u) {
                dt >>= 1;
            }

            /* 运行和：满窗时先减去将被覆盖的最旧值 */
            if (s_dt.hist_full) {
                s_dt.hist_sum -= s_dt.hist[s_dt.hist_idx];
            }
            s_dt.hist[s_dt.hist_idx] = dt;
            s_dt.hist_sum += dt;

            s_dt.hist_idx++;
            if (s_dt.hist_idx >= HALL_DT_AVG_N) {
                s_dt.hist_idx  = 0u;
                s_dt.hist_full = true;   /* 此后一直满 */
            }

            n = s_dt.hist_full ? HALL_DT_AVG_N : s_dt.hist_idx;
            s_dt.dt_ticks = (uint16_t)__builtin_divud(s_dt.hist_sum, n);

            /* 最高转速钳位：dt 不小于 342 tick（4000 rpm @ p=2） */
            if (s_dt.dt_ticks < HALL_DT_MAX_SPEED_TICKS) {
                s_dt.dt_ticks = HALL_DT_MAX_SPEED_TICKS;
            }

            HALL_UpdateStep(s_dt.dt_ticks);
        }
        /* else: sectors=0 或 dt 异常，不更新窗口/平均值，沿用上一次 */
    }

    /* 基准推进到本次已接受边沿：cap 与 hall 指向同一观测 */
    s_dt.prev_cap  = cap;
    s_dt.prev_hall = cur_hall;
    s_dt.have_prev = true;
}

/*
 * HALL_OnIsr
 * IC 边沿中断统一入口（经 BSP ICx 桥转发）。
 *
 * BSP 已先把该通道 FIFO 排空，并把最新捕获值 cap 交进来；本函数用当前
 * 引脚去抖结果判断这个 cap 是否对应一次真正被接受的 Hall 跳变：
 *   - 去抖拒绝：丢弃 cap，不推进 dt 基准；
 *   - 去抖接受：更新方向/时戳，并计算"上一次合法边沿 -> 本次"的 60° dt。
 *
 * 跨通道：三个 IC 的 FIFO 独立，但都在同一 ISR 优先级下按中断顺序处理；
 * 正常运行时相邻边沿间隔远大于 ISR 延迟，cap 差值即相邻 Hall 跳变的
 * 60° 时间。ovf=1（FIFO 溢出/积压）说明 cap 与引脚状态可能不同步，此时
 * 丢弃 dt 基准，下一沿只重建基准、再下一沿才恢复 dt。
 */
static void HALL_OnIsr(uint8_t ch, uint16_t cap, uint8_t ovf) {
    uint8_t cur_hall;

    (void)ch;   /* 跨通道 dt 不区分通道；参数保留给后续按通道诊断/校准 */

    HALL_TIMING_BEGIN();

    if (!HALL_UpdateInputState()) {
        HALL_TIMING_END();
        return;   /* 去抖拒绝：本次捕获不是合法 Hall 跳变 */
    }

    cur_hall = hall_status;

    /* 更新实测方向 */
    HALL_UpdateDirection(cur_hall);
    s_last_edge_tick_ms = MC_GetTickMs();   /* 记时戳,供测速/堵转检测 */

    HALL_UpdateDt(cap, cur_hall, ovf);

	HALL_TIMING_END();

    if (s_on_edge) s_on_edge(cur_hall);
}

/* TODO: 实现 HALL_GetSpeedRpm 时需定义极对数 POLE_PAIR_NUM */
