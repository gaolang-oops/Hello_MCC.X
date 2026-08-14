/*
 * mc_protocol.h
 *
 * 电机控制协议模块(Motor Control Protocol)
 *
 * 在 UART 帧协议(UartLFrame)之上分发故障查询/清故障命令,
 *
 * 帧格式继承 UartLFrame: HEAD1 HEAD2 LEN DATA[LEN] CHECKSUM
 *   DATA[0] = 命令字节(CMD),DATA[1..] = 命令载荷。
 *
 * 命令表:
 *   下行(主机 -> 设备):
 *     MC_CMD_QUERY_FAULT (0x01)  查询当前故障/状态  -> 回 FAULT_RESP
 *     MC_CMD_CLEAR_FAULT (0x81)  清除全部故障        -> 回 CLEAR_ACK
 *     其它                        -> 原样回显(向后兼容旧的回环测试)
 *   上行(设备 -> 主机):
 *     MC_CMD_FAULT_NOTIFY(0xF1)  故障变化时主动推送(边沿触发,非每拍)
 *     MC_CMD_FAULT_RESP  (0xF2)  查询响应
 *     MC_CMD_CLEAR_ACK   (0x82)  清故障响应
 *
 * 故障帧载荷(FAULT_NOTIFY / FAULT_RESP / CLEAR_ACK):
 *   DATA = [CMD, fault_hi, fault_lo, state]
 *     fault_hi/lo : MC_Fault_e 位图大端两字节(高位在前,便于串口工具直读)
 *     state       : Motor_State_e 当前状态机状态
 *
 * 调用约束:
 *   - MCProtocol_Init      由 main 初始化段调用(UartLframe_Init 之后)
 *   - MCProtocol_PollFault 由主循环 Tier-4 调用(非 1ms 关键路径)
 *     UartLframe_Send 最坏阻塞 50ms(TX 超时),严禁进 Motor_Tick(1ms 控制环)。
 */

#ifndef MC_PROTOCOL_H
#define MC_PROTOCOL_H

#include <stdint.h>

/* ---- 命令字节定义 ---- */
#define MC_CMD_QUERY_FAULT      0x01u   /* 下行:查询故障 */
#define MC_CMD_CLEAR_FAULT      0x81u   /* 下行:清故障 */
#define MC_CMD_FAULT_NOTIFY     0xF1u   /* 上行:故障变化推送 */
#define MC_CMD_FAULT_RESP       0xF2u   /* 上行:查询响应 */
#define MC_CMD_CLEAR_ACK        0x82u   /* 上行:清故障响应 */

/* 故障帧载荷长度: CMD + fault_lo + fault_hi + state */
#define MC_FAULT_PAYLOAD_LEN    4u

#ifdef __cplusplus
extern "C" {
#endif

/* 初始化:同步故障快照 + 注册 RX 回调(替代 main.c 的回声回调)。
 * 须在 UartLframe_Init 之后、GlobalEnable 之前调用。 */
void MCProtocol_Init(void);

/* 故障轮询:边沿检测 MC_GetFault() 变化,变化时主动推送 FAULT_NOTIFY。
 * 由主循环 Tier-4 调用(每轮),非 1ms 节拍。
 * 与 RX 回调的查询响应互补:推(边沿)+ 拉(查询)混合模型。 */
void MCProtocol_PollFault(void);

#ifdef __cplusplus
}
#endif

#endif /* MC_PROTOCOL_H */
