#ifndef S21_BIT_OPERATIONS
#define S21_BIT_OPERATIONS

#include <stdio.h>

#include "../s21_decimal.h"
// #include "../service_functions/s21_service_functions.h"

#define SCALE_MASK 0x00ff0000  // 00000000 11111111 0000000 00000000
#define SIGN_MASK 0x80000000   // 10000000 00000000 00000000 00000000
#define SCALE_SHIFT 16
#define SCALE_MAX 28
#define SIGN_SHIFT 31
#define int_length 32
#define mantissa_two int_length * 2
#define mantissa_three int_length * 3
#define ZERO 0
#define ZERO_DECIMAL \
  {                  \
    { 0, 0, 0, 0 }   \
  }

// typedef struct s21_decimal s21_decimal;

// bit operations
// --------------------------------------------------------------------------------------------------------
char s21_getBit(unsigned int bit, int index);
char s21_getBitGlobal(s21_decimal number, int index);
void s21_setBit(unsigned int* bit, int index, char val);
char s21_setBitGlobal(s21_decimal* number, int index, char val);
// sign operations
// --------------------------------------------------------------------------------------------------------
char s21_getSign(s21_decimal number);
char s21_setSign(s21_decimal* number, char val);
void s21_invertSign(s21_decimal* number);
// scale operations
// -------------------------------------------------------------------------------------------------------
char s21_setScale(s21_decimal* number, int scale);
void s21_zeroScale(s21_decimal* number);
int s21_getScale(s21_decimal number);
char s21_increaseScaleUlt(s21_decimal* number, int value);
char s21_increaseScale(s21_decimal* number);
char s21_decreaseScale(s21_decimal* number);
char s21_decreaseScaleUlt(s21_decimal* number, int value);
// part of mantissa operations
// --------------------------------------------------------------------------------------------
int s21_setPartMantissa(s21_decimal* decimal, int bit_index, int bit_value);
unsigned int s21_getPartMantissa(s21_decimal* decimal, int bit_index);
// decimal operations
// -----------------------------------------------------------------------------------------------------
int s21_clearDecimal(s21_decimal* decimal);
int s21_copyDecimal(s21_decimal src, s21_decimal* dest);
// shift operations
// -------------------------------------------------------------------------------------------------------
int s21_leftShift32(s21_decimal* dec, int shift);
int s21_leftShift(s21_decimal* dec, int shift);
int s21_rightShift32(s21_decimal* dec, int shift);
int s21_rightShift(s21_decimal* dec, int shift);
// printer operations
// -----------------------------------------------------------------------------------------------------
//  print decimal number from left to right (why?)
int s21_printDecimalBinRev(s21_decimal dec);
// print decimal number from right to left (like they pleased in memory and how
// they logically look)
int s21_printDecimalBin(s21_decimal dec);
// print decimal number how it placed in massive
void s21_printDecimalBinReal(s21_decimal num);
// bit counting
// -----------------------------------------------------------------------------------------------------
int s21_mantissaLength(s21_decimal num);
int s21_mantissaFirstBit(s21_decimal num);
// checker
// -------------------------------------------------------------------------------------------------------
char s21_isZeroDec(s21_decimal number);
#endif