/*
 * mc_protocol.c
 *
 * 电机控制协议模块实现。详见 mc_protocol.h 架构说明。
 *
 * 依赖方向(向下,合法):
 *   mc_protocol -> motor_control(Motor_GetHandle/状态)
 *   mc_protocol -> MC_Fault(MC_GetFault/MC_ClearAllFaults)
 *   mc_protocol -> BSP(UartLFrame 收发)
 * 调用上下文:全部在主循环 Tier-4(UartLframe_Process / PollFault),
 *             非 ISR;Motor_GetHandle 多字段快照在主循环读安全。
 */

#include "mc_protocol.h"
#include "Middlewares/MotorControl/MC_Fault.h"  /* MC_GetFault / MC_ClearAllFaults */
#include "Middlewares/MotorControl/motor_control.h"  /* Motor_GetHandle / Motor_State_e */
#include "Drivers/BSP/bsp_UartLframe.h"  /* UartLframe_Send / RegisterCallback */
#include <stdlib.h>
#include "user_manager.h"

/* 上次上报的故障快照,用于 PollFault 边沿检测。
 * 初值 0 = 与 MC_Fault_Init 后的干净态一致,冷启动不误推。 */
static uint16_t s_last_reported_fault = 0u;

/* 发送故障帧:载荷 = [cmd, fault_hi, fault_lo, state]。
 * 故障字节序为大端(高位在前),便于串口工具直读:
 *   例 OVER_VOLTAGE(0x0002) -> [cmd, 0x00, 0x02, state]
 * 故障位图与状态机状态一帧打包,主机无需二次查询。 */
static void MOTOR_SECTION send_fault_frame(uint8_t cmd)
{
    uint16_t fault = (uint16_t)MC_GetFault();
    Motor_Handle_t *m = Motor_GetHandle();
    uint8_t payload[MC_FAULT_PAYLOAD_LEN];

    payload[0] = cmd;
    payload[1] = (uint8_t)(fault >> 8);
    payload[2] = (uint8_t)(fault & 0xFFu);
    payload[3] = (uint8_t)m->state;
    UartLframe_Send(payload, MC_FAULT_PAYLOAD_LEN);
}

/* RX 回调:按 DATA[0] 命令字节分发。
 * 由 UartLframe_Process 在主循环 Tier-4 调用(非 ISR)。 */
static void MOTOR_SECTION on_rx_frame(const UartLFrame_t *frame)
{
    if (frame == NULL || frame->len < 1u) {
        return;
    }

    uint8_t cmd = frame->data[0];
	//按 DATA[0] 分发故障查询/清故障命令; 
    switch (cmd) {
        case MC_CMD_QUERY_FAULT:
            /* 查询:回当前故障/状态快照 */
            send_fault_frame(MC_CMD_FAULT_RESP);
            break;

        case MC_CMD_CLEAR_FAULT:
            /* 清故障:调唯一运行期全清点,回 ACK(载荷含清后状态) */
            MC_ClearAllFaults();
            send_fault_frame(MC_CMD_CLEAR_ACK);
            /* 同步快照,避免下拍 PollFault 重复推一条 FAULT_NOTIFY */
            s_last_reported_fault = 0u;
            break;

        default:
            /* 向后兼容:未知命令原样回显(保留旧回环测试可用) */
            UartLframe_Send(frame->data, frame->len);
            break;
    }
}

void MOTOR_SECTION MCProtocol_Init(void)
{
    s_last_reported_fault = 0u;
    UartLframe_RegisterCallback(on_rx_frame);
}

void MOTOR_SECTION MCProtocol_PollFault(void)
{
    uint16_t cur = (uint16_t)MC_GetFault();
    if (cur != s_last_reported_fault) {
        s_last_reported_fault = cur;
        send_fault_frame(MC_CMD_FAULT_NOTIFY);
    }
}
