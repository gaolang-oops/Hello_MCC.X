/*
 * mc_button.c
 *
 * 按键输入模块实现。
 * 非阻塞消抖状态机，1ms 节拍由主循环 Tier-2 调用。
 *
 * 事件 → 命令映射（一次性命令，状态机消费即清零）：
 *   KEY0 短按/长按 → Motor_SetCommand(MOTOR_CMD_START)
 *   KEY1 短按/长按 → Motor_SetCommand(MOTOR_CMD_STOP)（硬停：立即关 PWM）
 *   KEY2 短按        → Motor_SetCommand(MOTOR_CMD_STOP)（硬停：立即关 PWM）
 *   KEY2 长按        → MC_ClearAllFaults()            （仅当存在故障时）
 */

#include "mc_button.h"
#include "Drivers/BSP/bsp_gpio.h"
#include "Middlewares/MotorControl/motor_control.h"
#include "Middlewares/MotorControl/MC_Fault.h"
#include "user_manager.h"

typedef enum {
    BTN_IDLE = 0,
    BTN_DEBOUNCE,
    BTN_HELD,
    BTN_REL_DEBOUNCE,
} BtnPhase_e;

typedef struct {
    BtnPhase_e phase;
    uint16_t   cnt_ms;    /* 按下/松开消抖计数 */
    uint16_t   hold_ms;   /* BTN_HELD 期间累计按住时长 */
} BtnDebounce_t;

/* 按键事件：松开时一次性判定，长按不会同时产生短按事件 */
typedef enum {
    BTN_EV_NONE = 0,
    BTN_EV_SHORT,
    BTN_EV_LONG,
} BtnEvent_e;

static BtnDebounce_t s_key0;
static BtnDebounce_t s_key1;
static BtnDebounce_t s_key2;

static void MOTOR_SECTION btn_reset(BtnDebounce_t *b) {
    b->phase   = BTN_IDLE;
    b->cnt_ms  = 0;
    b->hold_ms = 0;
}

/*
 * 统一短按/长按消抖（KEY0/KEY1/KEY2）。
 * 按下与松开均做 BTN_DEBOUNCE_MS 消抖，松开后一次性判定：
 *   hold <  BTN_LONG_PRESS_MS → BTN_EV_SHORT
 *   hold >= BTN_LONG_PRESS_MS → BTN_EV_LONG
 * 一次按住只产生一个事件（长按不会再额外产生短按）。
 * 调用方按需忽略不需要的事件类型即可。
 */
static BtnEvent_e MOTOR_SECTION btn_press_tick(BtnDebounce_t *b, KEY_Name_e key) {
    uint8_t pressed = (KEY_Get_State(key) == 0);

    switch (b->phase) {
        case BTN_IDLE:
            if (pressed) { b->cnt_ms = 1; b->hold_ms = 0; b->phase = BTN_DEBOUNCE; }
            break;
        case BTN_DEBOUNCE:
            if (pressed) {
                if (++b->cnt_ms >= BTN_DEBOUNCE_MS) {
                    b->hold_ms = 0;
                    b->phase   = BTN_HELD;
                }
            } else {
                btn_reset(b);
            }
            break;
        case BTN_HELD:
            if (pressed) {
                if (b->hold_ms < 0xFFFFu) b->hold_ms++;
            } else {
                b->cnt_ms = 1;
                b->phase  = BTN_REL_DEBOUNCE;
            }
            break;
        case BTN_REL_DEBOUNCE:
            if (!pressed) {
                if (++b->cnt_ms >= BTN_DEBOUNCE_MS) {
                    bool is_long = (b->hold_ms >= BTN_LONG_PRESS_MS);
                    btn_reset(b);
                    return is_long ? BTN_EV_LONG : BTN_EV_SHORT;
                }
            } else {
                b->cnt_ms = 0;   /* 松开途中抖动：回到按住态继续计时 */
                b->phase  = BTN_HELD;
            }
            break;
        default:
            btn_reset(b);
            break;
    }
    return BTN_EV_NONE;
}

void MOTOR_SECTION MCButton_Init(void) {
    btn_reset(&s_key0);
    btn_reset(&s_key1);
    btn_reset(&s_key2);
}

void MOTOR_SECTION MCButton_Tick1ms(void) {
    switch (btn_press_tick(&s_key0, KEY0)) {
        case BTN_EV_SHORT:
        case BTN_EV_LONG:
            Motor_SetCommand(MOTOR_CMD_START);
            break;
        default:
            break;
    }

    /* KEY1：短按/长按均停机（硬停） */
    switch (btn_press_tick(&s_key1, KEY1)) {
        case BTN_EV_SHORT:
        case BTN_EV_LONG:
            Motor_SetCommand(MOTOR_CMD_STOP);
            break;
        default:
            break;
    }

    /* KEY2：短按停机，长按清故障 */
    switch (btn_press_tick(&s_key2, KEY2)) {
        case BTN_EV_SHORT:
            Motor_SetCommand(MOTOR_CMD_STOP);
            break;
        case BTN_EV_LONG:
            /* 清故障：状态机 FAULT 态下拍检测 !MC_HasAnyFault() 自动转 STOPPED。
             * 无须下发停机命令 —— 故障态本就硬关，且命令模型无电平残留需清理。 */
            if (MC_HasAnyFault()) {
                MC_ClearAllFaults();
            }
            break;
        default:
            break;
    }
}
