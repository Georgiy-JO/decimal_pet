#include "s21_massive_decimal.h"

// bit operations
// -------------------------------------------------------------------------------------------------------
char s21_getBitGlobalExp(s21_expended number, int index) {
  if (index < int_length)
    return (s21_getBit(number.bits[0], index));
  else if (index < mantissa_two)
    return (s21_getBit(number.bits[1], index - int_length));
  else if (index < mantissa_three)
    return (s21_getBit(number.bits[2], index - mantissa_two));
  else if (index < mantissa_four)
    return (s21_getBit(number.bits[3], index - mantissa_three));
  else if (index < mantissa_five)
    return (s21_getBit(number.bits[4], index - mantissa_four));
  else if (index < mantissa_six)
    return (s21_getBit(number.bits[5], index - mantissa_five));
  else if (index == mantissa_six)
    return (s21_getBit(number.bits[6], mantissa_six));
  else
    return error_out_of_range;
}
char s21_setBitGlobalExp(s21_expended* number, int index, char val) {
  if (val != 1 && val != 0)
    return error_wrong_value;
  else if (index < int_length)
    (s21_setBit(number->bits, index, val));
  else if (index < mantissa_two)
    (s21_setBit(number->bits + 1, index - int_length, val));
  else if (index < mantissa_three)
    (s21_setBit(number->bits + 2, index - mantissa_two, val));
  else if (index < mantissa_four)
    (s21_setBit(number->bits + 3, index - mantissa_three, val));
  else if (index < mantissa_five)
    (s21_setBit(number->bits + 4, index - mantissa_four, val));
  else if (index < mantissa_six)
    (s21_setBit(number->bits + 5, index - mantissa_five, val));
  else if (index == mantissa_six)
    (s21_setBit(number->bits + 6, mantissa_six, val));
  else
    return error_out_of_range;
  return 0;
}
// sign operations
// -------------------------------------------------------------------------------------------------------
char s21_getSignExp(s21_expended number) {
  if (number.bits[6] & SIGN_MASK)
    return 1;
  else
    return 0;
}
char s21_setSignExp(s21_expended* number, char val) {
  if (val != 1 && val != 0)
    return error_wrong_value;
  else
    s21_setBit(number->bits + 6, SIGN_SHIFT, val);
  return 0;
}
void s21_invertSignExp(s21_expended* number) {
  if (s21_getSignExp(*number))
    s21_setSignExp(number, 0);
  else
    s21_setSignExp(number, 1);
}

// full expended operations
// -----------------------------------------------------------------------------------------------------
void s21_clearExpended(s21_expended* expended) {
  expended->bits[0] = 0;
  expended->bits[1] = 0;
  expended->bits[2] = 0;
  expended->bits[3] = 0;
  expended->bits[4] = 0;
  expended->bits[5] = 0;
  expended->bits[6] = 0;
}
void s21_copyExpended(s21_expended src, s21_expended* dest) {
  dest->bits[0] = src.bits[0];
  dest->bits[1] = src.bits[1];
  dest->bits[2] = src.bits[2];
  dest->bits[3] = src.bits[3];
  dest->bits[4] = src.bits[4];
  dest->bits[5] = src.bits[5];
  dest->bits[6] = src.bits[6];
}

// printer operations
// -----------------------------------------------------------------------------------------------------
void s21_printExpendedMantissa(s21_expended num) {
  for (int i = mantissa_six; i >= 0; i--) {
    if (i == mantissa_three - 1 || i == mantissa_two - 1 ||
        i == int_length - 1 || i == mantissa_four - 1 ||
        i == mantissa_five - 1 || i == mantissa_six - 1)
      printf("|");
    printf("%u", s21_getBitGlobalExp(num, i));
  }
  printf("\n");
}
void s21_printExpendedBin(s21_expended num) {
  for (int i = mantissa_seven - 1; i > mantissa_six; i--) {
    printf("%u", s21_getBit(num.bits[6], i - mantissa_six));
  }
  s21_printExpendedMantissa(num);
}

// shift operations
// --------------------------------------------------------------------------------------------------------
void s21_leftShiftExp32(s21_expended* num,
                        int shift) {  // not checked independently
  unsigned int buffer = 0;
  s21_setBitGlobalExp(num, mantissa_six,
                      s21_getBitGlobalExp(*num, mantissa_six - shift));
  for (int i = 5; i >= 0; i--) {
    num->bits[i] <<= shift;
    if (shift == int_length) num->bits[i] = 0;
    if (i > 0) {
      buffer = num->bits[i - 1] >> (int_length - shift);
      num->bits[i] = num->bits[i] + buffer;
    }
  }
}
void s21_leftShiftExp(s21_expended* num, int shift) {
  if (shift < 0)
    s21_rightShiftExp(num, -shift);
  else if (shift > 0) {
    if (shift <= int_length)
      s21_leftShiftExp32(num, shift);
    else {
      for (int i = 1; i <= (shift / int_length); i++) {
        s21_leftShiftExp32(num, int_length);
      }
      int tmp = shift % int_length;
      if (tmp != 0) s21_leftShiftExp32(num, tmp);
    }
  }
}

void s21_rightShiftExp32(s21_expended* num,
                         int shift) {  // not checked independently
  for (int i = 0; i <= 5; i++) {
    num->bits[i] >>= shift;
    if (shift == int_length) num->bits[i] = 0;
    if (i < 5)
      num->bits[i] = num->bits[i] + (num->bits[i + 1] << (int_length - shift));
  }
  s21_setBitGlobalExp(num, mantissa_six - shift,
                      s21_getBitGlobalExp(*num, mantissa_six));
  s21_setBitGlobalExp(num, mantissa_six, 0);
}
void s21_rightShiftExp(s21_expended* num, int shift) {
  if (shift < 0)
    s21_leftShiftExp(num, -shift);
  else if (shift > 0) {
    if (shift <= int_length)
      s21_rightShiftExp32(num, shift);
    else {
      for (int i = 1; i <= (shift / int_length); i++) {
        s21_rightShiftExp32(num, int_length);
      }
      int tmp = shift % int_length;
      if (tmp != 0) s21_rightShiftExp32(num, tmp);
    }
  }
}

// bit counting
// -----------------------------------------------------------------------------------------------------
int s21_mantissaExpLength(s21_expended num) {
  int res = mantissa_six;
  for (; res >= 0 && !s21_getBitGlobalExp(num, res); res--)
    ;
  return res + 1;
}
int s21_mantissaExpFirstBit(s21_expended num) {
  return s21_mantissaExpLength(num) - 1;
}

// scale operations
// -------------------------------------------------------------------------------------------------------
char s21_setScaleExp(s21_expended* number, int scale) {
  if (scale > SCALE_MAX_EXP)
    return error_scale_out_of_range;
  else {
    s21_zeroScaleExp(number);
    number->bits[6] |= (scale << SCALE_SHIFT);
  }
  return 0;
}
void s21_zeroScaleExp(s21_expended* number) {
  number->bits[6] &= ~(SCALE_MASK);
}
int s21_getScaleExp(s21_expended number) {
  return (number.bits[6] & SCALE_MASK) >> SCALE_SHIFT;
}
char s21_increaseScaleExpUlt(s21_expended* number, int value) {
  for (; 0 < value && !s21_increaseScaleExp(number); value--)
    ;
  return value;
}
char s21_increaseScaleExp(s21_expended* number) {
  int scale_tmp = s21_getScaleExp(*number);
  if (scale_tmp == SCALE_MAX_EXP)
    return error_scale_out_of_range;
  else
    s21_setScaleExp(number, scale_tmp + 1);
  return 0;
}
char s21_decreaseScaleExpUlt(s21_expended* number, int value) {
  for (; 0 < value && !s21_decreaseScaleExp(number); value--)
    ;
  return value;
}
char s21_decreaseScaleExp(s21_expended* number) {
  int scale_tmp = s21_getScaleExp(*number);
  if (scale_tmp == ZERO)
    return error_scale_out_of_range;
  else
    s21_setScaleExp(number, scale_tmp - 1);
  return 0;
}

// checker
// -------------------------------------------------------------------------------------------------------
char s21_isZeroExp(s21_expended number) {
  return (number.bits[0] == 0 && number.bits[1] == 0 && number.bits[2] == 0 &&
          number.bits[3] == 0 && number.bits[4] == 0 && number.bits[5] == 0 &&
          s21_getBitGlobalExp(number, mantissa_six) == 0)
             ? 1
             : 0;
}