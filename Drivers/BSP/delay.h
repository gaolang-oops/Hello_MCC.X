#ifndef DELAY_H
#define DELAY_H
#include <stdint.h>
/* 汇编忙等延时（基于指令周期，不依赖中断）。
 */
void Delay_ms(uint16_t ms);
#endif