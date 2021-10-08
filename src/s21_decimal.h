#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <math.h>
#include <stdlib.h>

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

//				bits[0](mantissa_1)
// bits[1](mantissa_2) bits[2](mantissa_3)
// bits[3](significant) [00000000 00000000 00000000 00000000]	[00000000
// 00000000 00000000 00000000]	[00000000 00000000 00000000 00000000]
//[s0000000 cccccccc 00000000 000000ee]
// s - sign symbol c - scale number  e - error bits
// 0x80000000 == 0b10000000000000000000000000000000

#include "1_bit_operations/s21_bit_operations.h"
#include "2_massive_decimal/s21_massive_decimal.h"
#include "3_service_functions/s21_service_functions.h"
#include "4_converters/s21_converters.h"
#include "5_comparison/s21_comparison.h"
#include "6_simple_arithmetic/s21_simple_arithmetic.h"
#include "7_arithmetic/s21_arithmetic.h"

// comparison operation
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

// another function
int s21_negate(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);

// arithmetic operation
int s21_add(s21_decimal value1, s21_decimal value2, s21_decimal* result);
int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal* result);
int s21_mul(s21_decimal value1, s21_decimal value2, s21_decimal* result);
int s21_div(s21_decimal value1, s21_decimal value2, s21_decimal* result);

// convert and parsers
int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

#endif
