/*
 * mc_button.c
 *
 * 按键输入模块实现。
 * 非阻塞消抖状态机，1ms 节拍由主循环 Tier-2 调用。
 *
 * 事件 → 命令映射（一次性命令，状态机消费即清零）：
 *   KEY0 短按 → Motor_SetCommand(MOTOR_CMD_START)
 *   KEY1 短按 → Motor_SetCommand(MOTOR_CMD_STOP)   （硬停：立即关 PWM）
 *   KEY2 长按 → MC_ClearAllFaults()                 （仅当存在故障时）
 */

#include "mc_button.h"
#include "Drivers/BSP/bsp_gpio.h"
#include "Middlewares/MotorControl/motor_control.h"
#include "Middlewares/MotorControl/MC_Fault.h"

typedef enum {
    BTN_IDLE = 0,
    BTN_DEBOUNCE,
    BTN_HELD,
    BTN_REL_DEBOUNCE,
} BtnPhase_e;

typedef struct {
    BtnPhase_e phase;
    uint16_t   cnt_ms;
} BtnDebounce_t;

static BtnDebounce_t s_key0;
static BtnDebounce_t s_key1;
static BtnDebounce_t s_key2;

static void btn_reset(BtnDebounce_t *b) {
    b->phase  = BTN_IDLE;
    b->cnt_ms = 0;
}

/*
 * 通用短按消抖（KEY0/KEY1）。
 * 返回 true = 一次有效"按下并松开"事件。
 */
static bool btn_short_tick(BtnDebounce_t *b, KEY_Name_e key) {
    uint8_t pressed = (KEY_Get_State(key) == 0);

    switch (b->phase) {
        case BTN_IDLE:
            if (pressed) { b->cnt_ms = 1; b->phase = BTN_DEBOUNCE; }
            break;
        case BTN_DEBOUNCE:
            if (pressed) {
                if (++b->cnt_ms >= BTN_DEBOUNCE_MS) b->phase = BTN_HELD;
            } else {
                btn_reset(b);
            }
            break;
        case BTN_HELD:
            if (!pressed) { b->cnt_ms = 1; b->phase = BTN_REL_DEBOUNCE; }
            break;
        case BTN_REL_DEBOUNCE:
            if (!pressed) {
                if (++b->cnt_ms >= BTN_DEBOUNCE_MS) { btn_reset(b); return true; }
            } else {
                b->cnt_ms = 0; b->phase = BTN_HELD;
            }
            break;
    }
    return false;
}

/*
 * 长按消抖（KEY2）。
 * 持续按下计时，松手时若 hold >= BTN_LONG_PRESS_MS 则触发。
 * 返回 true = 一次有效长按事件。
 */
static bool btn_long_tick(BtnDebounce_t *b, KEY_Name_e key) {
    uint8_t pressed = (KEY_Get_State(key) == 0);

    switch (b->phase) {
        case BTN_IDLE:
            if (pressed) { b->cnt_ms = 1; b->phase = BTN_DEBOUNCE; }
            break;
        case BTN_DEBOUNCE:
            if (pressed) {
                if (++b->cnt_ms >= BTN_DEBOUNCE_MS) {
                    b->cnt_ms = 0;
                    b->phase  = BTN_HELD;
                }
            } else {
                btn_reset(b);
            }
            break;
        case BTN_HELD:
            if (pressed) {
                b->cnt_ms++;
            } else {
                bool long_enough = (b->cnt_ms >= BTN_LONG_PRESS_MS);
                btn_reset(b);
                return long_enough;
            }
            break;
        default:
            btn_reset(b);
            break;
    }
    return false;
}

void MCButton_Init(void) {
    btn_reset(&s_key0);
    btn_reset(&s_key1);
    btn_reset(&s_key2);
}

void MCButton_Tick1ms(void) {
    if (btn_short_tick(&s_key0, KEY0)) {
        Motor_SetCommand(MOTOR_CMD_START);
    }

    if (btn_short_tick(&s_key1, KEY1)) {
        Motor_SetCommand(MOTOR_CMD_STOP);
    }

    if (btn_long_tick(&s_key2, KEY2)) {
        /* 清故障：状态机 FAULT 态下拍检测 !MC_HasAnyFault() 自动转 STOPPED。
         * 无须下发停机命令 —— 故障态本就硬关，且命令模型无电平残留需清理。 */
        if (MC_HasAnyFault()) {
            MC_ClearAllFaults();
        }
    }
}
