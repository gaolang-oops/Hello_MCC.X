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
 *   - 通过观察者回调 HALL_RegisterOnEdge() 向上层(drive)通知 Hall 跳变
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

/* ---- 霍尔非法状态确认参数(对齐 ST bSpeedErrorNumber 连续确认模式) ----
 * 去抖通过后仍为 000/111 视为一次"非法事件",连续 N 次才报 HALL_INVALID 故障。
 * 抗换相瞬间霍尔线瞬态噪声产生的短促 0/7;任何合法(1~6)去抖读即重置计数。 */
#define HALL_INVALID_CONFIRM_N   3U

/*
 * hall_status bit 布局: bit2=U(IC1), bit1=V(IC2), bit0=W(IC3)
 */
static volatile uint8_t hall_status;

/* 最近一次合法 Hall 边沿的时间戳(ms)。供测速/堵转检测使用。
 * 写方: HALL_OnIsr(IC ISR 优先级7);读方: Tier-2 主循环(优先级0)。volatile uint16_t 原子。 */
static volatile uint16_t s_last_edge_tick_ms = 0;

/* 观察者回调：Hall 跳变去抖成功后上抛给 drive 层（反向控制，DIP） */
static volatile HallEdgeCallback_t s_on_edge = NULL;

static bool HALL_UpdateInputState(void);
static void HALL_OnIsr(void);

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

void HALL_Init(void) {
    /* 种子初始化：上电后主动读一次 Hall。
     * 若电机静止则无 Hall 跳变沿 -> 无中断 -> hall_status 恒为 0(非法)，
     * 会导致启动时换相走全关态而无法启动。
     * 此处全局中断尚未开启，HALL_UpdateInputState 为纯轮询读，安全。 */
    HALL_UpdateInputState();

    /* 注册 IC ISR 处理函数：边沿中断经 BSP 桥 -> mc_services -> 本函数 */
    MC_Hall_RegisterIsr(HALL_OnIsr);
}

uint8_t HALL_GetHallStatus(void) {
    return hall_status;   /* volatile uint8_t 读取原子 */
}

void HALL_RegisterOnEdge(HallEdgeCallback_t cb) {
    s_on_edge = cb;
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
}

/*
 * HALL_OnIsr
 * IC 边沿中断统一入口（经 BSP ICx 桥转发）：去抖成功 -> 上抛事件给 drive。
 */
static void HALL_OnIsr(void) {
    if (HALL_UpdateInputState()) {
        s_last_edge_tick_ms = MC_GetTickMs();   /* 记时戳,供测速/堵转检测 */
        if (s_on_edge) s_on_edge(hall_status);
    }
}

/* TODO: 实现 HALL_GetSpeedRpm 时需定义极对数 POLE_PAIR_NUM */
