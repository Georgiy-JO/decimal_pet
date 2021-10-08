#include "s21_bit_operations.h"

// bit operations
// -------------------------------------------------------------------------------------------------------
char s21_getBit(unsigned int bit, int index) {
  int loc = 1;
  loc <<= index;
  if (bit & loc)
    return 1;
  else
    return 0;
}
char s21_getBitGlobal(s21_decimal number, int index) {
  if (index < int_length)
    return (s21_getBit(number.bits[0], index));
  else if (index < mantissa_two)
    return (s21_getBit(number.bits[1], index - int_length));
  else if (index < mantissa_three)
    return (s21_getBit(number.bits[2], index - mantissa_two));
  else
    return error_out_of_range;
}
void s21_setBit(unsigned int* bit, int index, char val) {
  int loc = 1;
  loc <<= index;
  if (val)
    (*bit) |= loc;
  else
    (*bit) &= ~loc;
}
char s21_setBitGlobal(s21_decimal* number, int index, char val) {
  if (val != 1 && val != 0)
    return error_wrong_value;
  else if (index < int_length)
    (s21_setBit(number->bits, index, val));
  else if (index < mantissa_two)
    (s21_setBit(number->bits + 1, index - int_length, val));
  else if (index < mantissa_three)
    (s21_setBit(number->bits + 2, index - mantissa_two, val));
  else
    return error_out_of_range;
  return 0;
}

// sign operations
// -------------------------------------------------------------------------------------------------------
char s21_getSign(s21_decimal number) {
  if (number.bits[3] & SIGN_MASK)
    return 1;
  else
    return 0;
}
char s21_setSign(s21_decimal* number, char val) {
  if (val != 1 && val != 0)
    return error_wrong_value;
  else
    s21_setBit(number->bits + 3, SIGN_SHIFT, val);
  return 0;
}
void s21_invertSign(s21_decimal* number) {
  if (s21_getSign(*number))
    s21_setSign(number, 0);
  else
    s21_setSign(number, 1);
}

// scale operations
// -------------------------------------------------------------------------------------------------------
char s21_setScale(s21_decimal* number, int scale) {
  if (scale > SCALE_MAX || scale < 0)
    return error_scale_out_of_range;
  else {
    s21_zeroScale(number);
    number->bits[3] |= (scale << SCALE_SHIFT);
  }
  return 0;
}
void s21_zeroScale(s21_decimal* number) { number->bits[3] &= ~(SCALE_MASK); }
int s21_getScale(s21_decimal number) {
  return (number.bits[3] & SCALE_MASK) >> SCALE_SHIFT;
}
char s21_increaseScaleUlt(s21_decimal* number, int value) {
  for (; 0 < value && !s21_increaseScale(number); value--)
    ;
  return value;
}
char s21_increaseScale(s21_decimal* number) {
  int scale_tmp = s21_getScale(*number);
  if (scale_tmp == SCALE_MAX)
    return error_scale_out_of_range;
  else
    s21_setScale(number, scale_tmp + 1);
  return 0;
}
char s21_decreaseScaleUlt(s21_decimal* number, int value) {
  for (; 0 < value && !s21_decreaseScale(number); value--)
    ;
  return value;
}
char s21_decreaseScale(s21_decimal* number) {
  int scale_tmp = s21_getScale(*number);
  if (scale_tmp == ZERO)
    return error_scale_out_of_range;
  else
    s21_setScale(number, scale_tmp - 1);
  return 0;
}

// part of mantissa operations
// ------------------------------------------------------------------------------------------------
int s21_setPartMantissa(s21_decimal* decimal, int bit_index, int bit_value) {
  decimal->bits[bit_index] = bit_value;
  return 0;
}
unsigned int s21_getPartMantissa(s21_decimal* decimal, int bit_index) {
  return decimal->bits[bit_index];
}

// decimal operations
// -----------------------------------------------------------------------------------------------------
int s21_clearDecimal(s21_decimal* decimal) {
  s21_decimal localdecimal = *decimal;
  localdecimal.bits[0] = 0;
  localdecimal.bits[1] = 0;
  localdecimal.bits[2] = 0;
  localdecimal.bits[3] = 0;
  *decimal = localdecimal;
  return 0;
}
int s21_copyDecimal(s21_decimal src, s21_decimal* dest) {
  dest->bits[0] = src.bits[0];
  dest->bits[1] = src.bits[1];
  dest->bits[2] = src.bits[2];
  dest->bits[3] = src.bits[3];
  return 0;
}

// shift operations
// --------------------------------------------------------------------------------------------------------
int s21_leftShift32(s21_decimal* dec, int shift) {  // not checked independently
  dec->bits[2] <<= shift;
  if (shift == int_length) dec->bits[2] = 0;

  unsigned int val = 0;
  unsigned int leftval = 0;

  val = dec->bits[1];
  leftval = val;
  val <<= shift;
  if (shift == int_length) val = 0;
  leftval = leftval >> (int_length - shift);
  dec->bits[1] = val;
  dec->bits[2] |= leftval;

  val = dec->bits[0];
  leftval = val;
  val <<= shift;
  if (shift == int_length) val = 0;
  leftval = leftval >> (int_length - shift);
  dec->bits[0] = val;
  dec->bits[1] |= leftval;
  return 0;
}
int s21_leftShift(s21_decimal* dec, int shift) {
  if (shift == 0) {
    return 0;
  } else if (shift <= int_length) {
    s21_leftShift32(dec, shift);
  } else {
    for (int i = 1; i <= (shift / int_length); i++) {
      s21_leftShift32(dec, int_length);
    }
    int j = (int)(shift % int_length);
    if (j != 0) s21_leftShift32(dec, j);
  }
  return 0;
}
int s21_rightShift32(s21_decimal* dec, int shift) {  // not checked
                                                     // independently
  dec->bits[0] >>= shift;
  if (shift == int_length) dec->bits[0] = 0;

  unsigned int val = 0;
  unsigned int rightval = 0;

  val = dec->bits[1];
  rightval = val;
  val >>= shift;
  if (shift == int_length) val = 0;
  rightval = rightval << (int_length - shift);
  dec->bits[1] = val;
  dec->bits[0] |= rightval;

  val = dec->bits[2];
  rightval = val;
  val >>= shift;
  if (shift == int_length) val = 0;
  rightval = rightval << (int_length - shift);
  dec->bits[2] = val;
  dec->bits[1] |= rightval;

  return 0;
}
int s21_rightShift(s21_decimal* dec, int shift) {
  if (shift == 0) {
    return 0;
  } else if (shift <= int_length) {
    s21_rightShift32(dec, shift);
  } else {
    for (int i = 1; i <= (shift / int_length); i++) {
      s21_rightShift32(dec, int_length);
    }
    int j = (int)(shift % int_length);
    if (j != 0) s21_rightShift32(dec, j);
  }
  return 0;
}

// printer operations
// -----------------------------------------------------------------------------------------------------
int s21_printDecimalBinRev(s21_decimal dec) {
  int bit = 0;
  for (int i = 0; i < mantissa_three; i++) {
    bit = s21_getBitGlobal(dec, i);
    if (i % int_length == 0 && i != 0) printf("|");
    printf("%u", bit);
  }
  printf("|");
  for (int i = 0; i < int_length; i++) {
    bit = s21_getBit(dec.bits[3], i);
    printf("%u", bit);
  }
  printf("\n");
  return 0;
}
int s21_printDecimalBin(s21_decimal dec) {
  int bit = 0;
  for (int i = int_length - 1; i >= 0; i--) {
    bit = s21_getBit(dec.bits[3], i);
    printf("%u", bit);
  }
  for (int i = mantissa_three - 1; i >= 0; i--) {
    bit = s21_getBitGlobal(dec, i);
    if (i == mantissa_three - 1 || i == mantissa_two - 1 || i == int_length - 1)
      printf("|");
    printf("%u", bit);
  }
  printf("\n");
  return 0;
}
void s21_printDecimalBinReal(s21_decimal num) {
  for (int i = 0; i < 4; i++) {
    for (int j = 31; j >= 0; j--) {
      printf("%u", s21_getBit(num.bits[i], j));
    }
    if (i != 3) printf("|");
  }
  printf("\n");
}

// bit counting
// -----------------------------------------------------------------------------------------------------
int s21_mantissaLength(s21_decimal num) {
  int res = mantissa_three - 1;
  for (; res >= 0 && !s21_getBitGlobal(num, res); res--)
    ;
  return res + 1;
}
int s21_mantissaFirstBit(s21_decimal num) {
  return s21_mantissaLength(num) - 1;
}
// checker
// -------------------------------------------------------------------------------------------------------
char s21_isZeroDec(s21_decimal number) {
  return (number.bits[0] == 0 && number.bits[1] == 0 && number.bits[2] == 0)
             ? 1
             : 0;
}