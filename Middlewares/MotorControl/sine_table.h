/*
 * sine_table.h
 *
 * 正弦查表模块（控制策略层，无硬件依赖）
 * 为未来 SPWM 控制提供 0~360° 离散正弦表（Q1.15 定点）。
 *
 * 定点化原理（MCU 无 FPU，全程整数运算）：
 *   1) sin 值定点化：真实值 ∈ [-1.0, +1.0]，用 Q1.15 表示
 *      Q15 = round(sin × 2^15) = round(sin × 32768)
 *      反算：sin = Q15 / 32768
 *      注：+1.0 理论值 32768 超出 int16_t 上限(0x7FFF)，裁剪为 32767；
 *          -1.0 恰为 0x8000 = -32768，可精确表示。
 *
 *   2) 角度定点化：一个完整正弦周期离散为 128 点，用整数索引 0~127
 *      替代带小数的度数（步长 = 360/128 = 2.8125°）。
 *      索引 i  ↔  角度 = i × 2.8125°
 *      关键索引： 0→0°, 32→90°, 64→180°, 96→270°, 127→357.1875°
 *
 *   3) angle16（16位二进制弧度 / brad16）：把整个圆周 360° 线性映射到
 *      uint16 满量程 65536，是 SPWM 相位累加器的标准表示。
 *      映射公式：angle16 = degree × 65536 / 360 = degree × 8192 / 45
 *      （65536/360 约分到最简 8192/45；8192 = 2^13, 45 = 360/8）
 *      关键刻度（均为 2 的幂分点，二进制边界精确对齐）：
 *        0°→0x0000, 90°→0x4000, 180°→0x8000, 270°→0xC000, 360°→回卷 0x0000
 *      三大免费特性：
 *        a) 回卷免费：uint16 加法溢出即 mod 65536 = mod 360°，无需取模运算
 *        b) 两范围统一：负角度（-180°~0°）经二进制补码自动等价于正角度
 *           （180°~360°），无需 if +360 分支。例 -90° → 0xC000 = 270° ✓
 *        c) 查表免费：>>9 即得 128 点表索引（16-7=9，取高 7 位）
 *
 *   4) 1/4 波形对称生成全表：Excel 给出 0°~90° 共 33 个基础值（idx 0~32），
 *      其余三象限由对称性推导：
 *        Q1 ( 0°~ 90°) idx 0~32 :  table[i] =  q[i]          (直接取)
 *        Q2 (90°~180°) idx 33~63:  table[i] =  q[64 - i]     (镜像)
 *        Q3 (180°~270°) idx 64~96: table[i] = -q[i - 64]     (取反)
 *        Q4 (270°~360°) idx 97~127:table[i] = -q[128 - i]    (取反镜像)
 *
 *   依赖方向：本模块无任何向下依赖（纯数据 + 查表函数）。
 */

#ifndef SINE_TABLE_H
#define SINE_TABLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- 表参数 ---- */
#define SINE_TABLE_SIZE       128u   /* 一个完整正弦周期的采样点数 */
#define SINE_INDEX_MASK       0x7Fu  /* 索引掩码：& 0x7F 自动 360° 回卷 */
#define SINE_Q15_FULL         32768  /* Q1.15 满量程 (= 1.0 << 15)，仅做比例换算用 */
#define SINE_Q15_POS_PEAK     32767  /* Q1.15 正峰值 (+1.0 裁剪，int16_t 上限) */
#define SINE_Q15_NEG_PEAK     (-32768) /* Q1.15 负峰值 (-1.0 精确，0x8000) */

/* ---- 角度 ↔ 索引 转换（纯整数运算，无浮点） ----
 * 反向换算关系：idx = angle × 128 / 360 = angle × 16 / 45
 * 正向换算关系：angle = idx × 360 / 128 = idx × 45 / 16
 *
 * SINE_DEG_TO_IDX(deg)        : 整数度数 → 索引（四舍五入）
 * SINE_IDX_TO_DEG_X10(idx)    : 索引 → 角度×10（保留 1 位小数，整数运算）
 */
#define SINE_DEG_TO_IDX(deg)      ((uint8_t)(((uint32_t)(deg) * 128u + 180u) / 360u))
#define SINE_IDX_TO_DEG_X10(idx)  ((uint16_t)(((uint32_t)(idx) * 3600u) / 128u))

/* ---- angle16：16位二进制弧度（360° = 2^16 = 65536） ----
 * 既是归一化结果（把 0~360° 与 -180°~180° 统一），又是 SPWM 相位累加器载体。
 * uint16 天然回卷（溢出 = mod 360°）、负角度补码自动等价（无需 if +360）。
 *
 * 比例 65536/360 约分到最简 8192/45（45 为奇数 → 余数永不为 0.5，无 tie 歧义）。
 * 中间值用 int32_t：deg×8192 最大可达 360×8192≈2.95M，超 int16 范围。
 * 负角度在 int32 中算出负值，赋给 uint16 时编译器取低 16 位 = 补码 = 自动 +65536。
 *
 * +22 是四舍五入偏移 = floor(45/2)：把 C 默认的截断除法转为 round-to-nearest，
 * 消除正角度系统性负偏置；45 为奇数故无精确 0.5 余数，+22 实现无歧义。
 * 注：最终 sin 查表经 >>9，±1 LSB 误差被完全抹平，故 +22 vs 截断在查表结果等价。
 */
#define SINE_ANGLE16_FULL         65536u          /* 360° 对应满量程 */
#define SINE_ANGLE16_90DEG        16384u          /*  90° = 0x4000 = 2^14 */
#define SINE_ANGLE16_180DEG       32768u          /* 180° = 0x8000 = 2^15 */
#define SINE_ANGLE16_270DEG       49152u          /* 270° = 0xC000 */
#define SINE_ANGLE16_MASK         0xFFFFu         /* uint16 天然回卷掩码 */

/* 度 → angle16（四舍五入；负角度经补码自动归一化为 [0,360°)）
 * 例：SINE_DEG_TO_ANGLE16(-90) → 0xC000 = 270°（sin(−90°)=sin(270°)=−1）*/
#define SINE_DEG_TO_ANGLE16(deg)  ((uint16_t)(((int32_t)(deg) * 8192 + 22) / 45))

/* angle16 → 128点表索引（右移 9 位 = 取高 7 位；floor，SPWM 标准用法）*/
#define SINE_ANGLE16_TO_IDX(a16)  ((uint8_t)((a16) >> 9))

/* ---- 角度 → angle16 反向换算（仅工程显示用，非热路径） ----
 * 截断实现（不加偏移）：反向换算只用于调试打印，不追求四舍五入精度。
 * 返回 ×100 整数（如 angle16=0x4000 → 9000 表示 90.00°），避免浮点。
 */
#define SINE_ANGLE16_TO_DEG_X100(a16)  ((uint16_t)(((uint32_t)(a16) * 36000u) / 65536u))

/**
   @Summary
     按索引查 Q1.15 正弦值。

   @Description
     index 自动按 SINE_INDEX_MASK 回卷（0~127 合法，越界自动取模 128）。
     返回 int16_t 定点值，范围 [-32768, +32767]，对应真实值 [-1.0, +1.0)。
     供未来 SPWM 调制查表（如相位累加器高位做索引）。

   @Parameters
     index  采样点索引（0~127 对应 0°~357.1875°；超出自动回卷）

   @Returns
     Q1.15 定点正弦值（真实值 = 返回值 / 32768）
 */
int16_t SINE_Lookup(uint8_t index);

/**
   @Summary
     按整数角度（0~359）查 Q1.15 正弦值。

   @Description
     内部先经 SINE_DEG_TO_IDX 把角度转索引，再查表。
     精度 = 表分辨率 2.8125°（四舍五入到最近采样点）。

   @Parameters
     degree  整数角度（0~359；超出行为未定义，调用方自行限幅）

   @Returns
     Q1.15 定点正弦值（真实值 = 返回值 / 32768）
 */
int16_t SINE_LookupByDegree(uint16_t degree);

/**
   @Summary
     按 angle16（16位二进制弧度）查 Q1.15 正弦值。

   @Description
     SPWM 相位累加器的标准查表入口。angle16 高 7 位（>>9）即 128 点表索引，
     uint16 天然回卷，负角度补码自动正确（无需分支）。
     是 SINE_Lookup 的语义包装（内部仅做 >>9 + 查表）。

   @Parameters
     angle16  16位二进制弧度（0~65535 对应 0°~360°；uint16 溢出自动回卷）

   @Returns
     Q1.15 定点正弦值（真实值 = 返回值 / 32768）
 */
int16_t Sine16(uint16_t angle16);

/* 汇编版（sine_table_asm.s），逻辑等价于 Sine16：mul.uu ×N>>16 + TBLRD 查表 */
int16_t Sine16_Asm(uint16_t angle16);

#ifdef __cplusplus
}
#endif

#endif /* SINE_TABLE_H */
