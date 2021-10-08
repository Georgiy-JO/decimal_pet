#ifndef S21_MASSIVE_DECIMAL
#define S21_MASSIVE_DECIMAL

// Expended decimal (mantissa x2+1 + sign)
typedef struct s21_expended_decimal {
  unsigned int bits[7];
} s21_expended;

//		    bits[0](mantissa_1)
// bits[1](mantissa_2) [00000000 00000000 00000000 00000000]	[00000000
// 00000000 00000000 00000000] 			bits[2](mantissa_3)
// bits[3](mantissa_4) [00000000 00000000 00000000 00000000]	[00000000
// 00000000 00000000 00000000] 			bits[4](mantissa_5)
// bits[5](mantissa_6) [00000000 00000000 00000000 00000000]	[00000000
// 00000000 00000000 00000000] 			bits[6](mantissa_7 + sign)
// [s0000000 00000000 00000000 0000000m]
// s - sign symbol m - last mantissa symbol

#include "../s21_decimal.h"

#define mantissa_four int_length * 4
#define mantissa_five int_length * 5
#define mantissa_six int_length * 6
#define mantissa_seven int_length * 7
#define ZERO_EXPENDED       \
  {                         \
    { 0, 0, 0, 0, 0, 0, 0 } \
  }
#define SCALE_MAX_EXP 58

void s21_copyExpended(s21_expended src, s21_expended* dest);
void s21_clearExpended(s21_expended* expended);
char s21_setBitGlobalExp(s21_expended* number, int index, char val);
char s21_getBitGlobalExp(s21_expended number, int index);
void s21_printExpendedMantissa(s21_expended dec);
void s21_printExpendedBin(s21_expended dec);
char s21_getSignExp(s21_expended number);
char s21_setSignExp(s21_expended* number, char val);
void s21_invertSignExp(s21_expended* number);
void s21_leftShiftExp32(s21_expended* num, int shift);
void s21_leftShiftExp(s21_expended* num, int shift);
void s21_rightShiftExp32(s21_expended* num, int shift);
void s21_rightShiftExp(s21_expended* num, int shift);
int s21_mantissaExpLength(s21_expended num);
int s21_mantissaExpFirstBit(s21_expended num);
char s21_setScaleExp(s21_expended* number, int scale);
void s21_zeroScaleExp(s21_expended* number);
int s21_getScaleExp(s21_expended number);
char s21_increaseScaleExpUlt(s21_expended* number, int value);
char s21_increaseScaleExp(s21_expended* number);
char s21_decreaseScaleExpUlt(s21_expended* number, int value);
char s21_decreaseScaleExp(s21_expended* number);
char s21_isZeroExp(s21_expended number);

#endif