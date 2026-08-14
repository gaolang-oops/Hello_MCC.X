/*
 * File:   six_step.c
 * 六步换相
 *
 * 硬件映射：
 *   PWM_GENERATOR_1 -> U 相
 *   PWM_GENERATOR_2 -> V 相
 *   PWM_GENERATOR_3 -> W 相
 *
 * 每相三种工作模式（H-PWM / L-ON 方案，定义于 pwm_common.h 的 PWM_PhaseMode_t）：
 *   PWM_HPWM_LOFF : 上桥臂 PWMxH 承载 PWM，下桥臂 PWMxL 强制关  (OVRENH=0, OVRENL=1, OVRDATL=0)
 *   PWM_HOFF_LON  : 上桥臂 PWMxH 强制关，下桥臂 PWMxL 强制常通  (OVRENH=1, OVRDATH=0, OVRENL=1, OVRDATL=1)
 *   PWM_HOFF_LOFF : 上下桥臂均强制关                            (OVRENH=1, OVRDATH=0, OVRENL=1, OVRDATL=0)
 *
 * 注意：本模块不直接访问 Override 寄存器，所有写入经 PWM_SetPhaseMode（pwm_common 唯一入口）。
 *
 * 正转换相表（依据实测 CW 序列 5→4→6→2→3→1 校准）：
 *   注：若电机转向/相序不同，调换 s_fwd_table 中 {U,V,W} 的成员即可校准。
 */

#include "six_step.h"
#include "pwm_common.h"   /* PWM 寄存器唯一抽象边界（PWM_SetPhaseMode / PWM_PhaseMode_t）*/
#include "MC_Fault.h"     /* MC_NotifyCommutation：换相后启动 blanking 屏蔽期 */
#include "hall_speed_fdbk.h"

/* 单步换相描述：三相各自的模式（模式枚举复用 pwm_common 的 PWM_PhaseMode_t）*/
typedef struct {
    PWM_PhaseMode_t u;
    PWM_PhaseMode_t v;
    PWM_PhaseMode_t w;
} CommutationStep_t;

/*
 * 正转换相表，以 Hall 组合值(1~6)为索引。
 * hall bit 布局: bit2=U(IC1 RG8), bit1=V(IC2 RG7), bit0=W(IC3 RG6)。
 * 电流方向（实测）:
 * "X正"=该相 PWM_HPWM_LOFF(上桥PWM), "X负"=该相 PWM_HOFF_LON(下桥常通), 第三相 PWM_HOFF_LOFF。
 */
static const CommutationStep_t s_fwd_table[8] = {
    [0] = {.u = PWM_HOFF_LOFF, .v = PWM_HOFF_LOFF, .w = PWM_HOFF_LOFF}, /* illegal */
    [1] = {.u = PWM_HOFF_LOFF, .v = PWM_HOFF_LON,  .w = PWM_HPWM_LOFF}, /* W->V */
    [2] = {.u = PWM_HOFF_LON,  .v = PWM_HPWM_LOFF, .w = PWM_HOFF_LOFF}, /* V->U */
    [3] = {.u = PWM_HOFF_LON,  .v = PWM_HOFF_LOFF, .w = PWM_HPWM_LOFF}, /* W->U */
    [4] = {.u = PWM_HPWM_LOFF, .v = PWM_HOFF_LOFF, .w = PWM_HOFF_LON},  /* U->W */
    [5] = {.u = PWM_HPWM_LOFF, .v = PWM_HOFF_LON,  .w = PWM_HOFF_LOFF}, /* U->V */
    [6] = {.u = PWM_HOFF_LOFF, .v = PWM_HPWM_LOFF, .w = PWM_HOFF_LON},  /* V->W */
    [7] = {.u = PWM_HOFF_LOFF, .v = PWM_HOFF_LOFF, .w = PWM_HOFF_LOFF}, /* illegal */
};

static volatile bool s_enabled = false;

/*
 * Hall 跳变事件回调（由 hall_speed_fdbk 在 ISR 内通过 s_on_edge 上抛）。
 * 反向控制：本函数指针在 SIXSTEP_Init 注册，feedback 模块不直接知道 six_step。
 */
static void SIXSTEP_OnHallEdge(uint8_t hall) {
    SIXSTEP_Communicate(hall);
}

void SIXSTEP_Enable(bool en) {
    s_enabled = en;
    if (en) {
		/* 
		 * PWMxH 失效【强制控制】，恢复由 PWM 模块的自主控制，以输出 PWM 波 
      	 * 注意，6-step 逻辑中，PWMxL 一直是强制控制，不能失效，否则 PWMxL 会输出互补的 PWM 波
		 * （下桥模式由 PWM_SetPhaseMode 在每次换相时维护，OVRENL 保持 1）
		 */
		PWM_HighPwmLowOff();

        /* 使能后立即用当前 Hall 建立初态，防止三相悬空。
         * 正常冷启动时电机静止、无 Hall 跳变、无 ISR，此处为首个换相点；
         * hall_status 在 HALL_Init() 已种子初始化，此处必为 1~6。
         * 先置 s_enabled=true 再 Communicate，语义自洽（使能即开始换相）。 */
        SIXSTEP_Communicate(HALL_GetHallStatus());
    } else {
        /* 失能即下电：清软件闸门 + 防御性硬关三相（即便上层漏调 PWM_AllOff 也安全）。
         * PWM_AllOff 经 PWM_SetPhaseMode 写 Override，寄存器所有权仍归 pwm_common。 */
        PWM_AllOff();
    }
}

bool SIXSTEP_IsEnabled(void) {
    return s_enabled;
}

void SIXSTEP_Init(void) {
	SIXSTEP_Enable(false); //自举电容充电完成后才能开始换相
    /* 订阅 Hall 跳变事件：feedback 去抖成功后回调本模块换相 */
    HALL_RegisterOnEdge(SIXSTEP_OnHallEdge);
}

void SIXSTEP_Communicate(uint8_t hall) {
    if (!s_enabled) {
        return;
    }
    if (hall > 7) {
        hall = 0; /* 防御性钳位 */
    }
    /* hall=0/7 落入 s_fwd_table 的全关安全态 */
    const CommutationStep_t *step = &s_fwd_table[hall];
    PWM_SetPhaseMode(PWM_GENERATOR_1, step->u); /* U */
    PWM_SetPhaseMode(PWM_GENERATOR_2, step->v); /* V */
    PWM_SetPhaseMode(PWM_GENERATOR_3, step->w); /* W */
    /* 通知 fault 模块:本次换相发生,启动过流 blanking 屏蔽期,
     * 避免换相电流尖峰在 ADC ISR 内误触发 OVER_CURRENT。
     * 调用上下文:Hall ISR(优先级7,本函数主路径)或状态机中(SIXSTEP_Enable 初态建立)。
     * Hall ISR > ADC ISR(6),时戳写入不被过流回调打断,无竞态。 */
    MC_NotifyCommutation();
}

/* TODO: 极对数 POLE_PAIR_NUM、速度反馈 hall_speed_fdbk（后续扩展） */
