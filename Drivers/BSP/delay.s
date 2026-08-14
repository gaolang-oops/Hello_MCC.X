.include    "p33EP128MC506.inc"
.section    .delay_section,code
.global	_Delay_ms

;===========================================================
; 函数名：void Delay_ms(uint16_t ms);
; 功能：毫秒级延时
; 时钟：FCY = 70MHz
; 入口：W0 = 延时毫秒数 (1~65535)
;===========================================================

_Delay_ms:
    ; 入口参数 W0 = 毫秒数
    cp0     W0              ; 如果 ms=0 直接返回
    bra     Z, Delay_ms_End

Delay_ms_Loop:
    ; ===== 进入 1ms 精准延时循环 =====
    mov     #14000, W1  ; W1 = 1ms 循环计数(70MHz 下精准 1ms 循环值=14000)

Delay_1ms:
    dec     W1, W1          ; 1 cycle
    bra     NZ, Delay_1ms   ; 4 cycles
    ; 1次循环 = 5 cycles
    ; 5 * 14000 = 70000 cycles = 1ms @70MHz

    ; ===== 1ms 完成，减毫秒计数 =====
    dec     W0, W0
    bra     NZ, Delay_ms_Loop

Delay_ms_End:
    return
.end
