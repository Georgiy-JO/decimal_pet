#include "s21_converters.h"

// does not work with scale and sign
s21_decimal s21_simpleIntToDec(int num) {
  unsigned int new_num = (num >= 0) ? num : -num;
  return s21_simpleUIntToDec(new_num);
}
// does not work with scale and sign
s21_decimal s21_simpleUIntToDec(unsigned int num) {
  s21_decimal result = ZERO_DECIMAL;
  result.bits[0] = num;
  return result;
}

// check that *exp* uses only 3 first bytes, as in s21_decimal
int s21_isFitInDec(s21_expended *exp) {
  if (exp->bits[3] == 0 && exp->bits[4] == 0 && exp->bits[5] == 0 &&
      s21_getBitGlobalExp(*exp, mantissa_six) == 0 &&
      s21_getScaleExp(*exp) <= 28)
    return 1;
  return 0;
}

// smart convert a s21_expended to s21_decimal using a bank rounding
s21_decimal s21_fromExpToDec(s21_expended *exp) {
  char sign = s21_getSignExp(*exp);
  int isZero = 0;
  if (s21_isZeroExp(*exp)) {
    isZero = 1;
  }
  s21_decimal res = ZERO_DECIMAL;
  int scale = 0;
  if (s21_isFitInDec(exp)) {
    res = s21_takeLastExpToDec(*exp);
  } else {
    scale = s21_getScaleExp(*exp);
    s21_expended remainder = ZERO_EXPENDED;
    s21_expended exp_ten = s21_decToExp(s21_simpleIntToDec(10));
    int curScale = 0;
    for (curScale = scale - 1;
         (curScale >= 0 && !s21_isFitInDec(exp)) || curScale >= 28;
         curScale--) {
      *exp = s21_simpleExpIntegerDivisionRemainder(*exp, exp_ten, &remainder);
      s21_setScaleExp(exp, curScale);
    }
    if (!isZero && s21_isZeroExp(*exp)) {
      s21_setErrorbitsTwo(&res);  // to small, so it became a zero
    } else {
      if (s21_isFitInDec(exp)) {
        scale = s21_getScaleExp(*exp);
        s21_bankRoundingExp(exp, &remainder);
        s21_setScaleExp(exp, scale);
        res = s21_takeLastExpToDec(*exp);
      } else {
        s21_setErrorbitsOne(&res);  // to big
      }
    }
  }
  s21_setSign(&res, sign);
  return res;
}

int s21_bankRoundingExp(s21_expended *exp, s21_expended *remainder) {
  int status = 1;
  s21_expended copy = ZERO_EXPENDED;
  s21_expended localRemainder = ZERO_EXPENDED;
  s21_copyExpended(*exp, &copy);
  s21_expended exp_two = s21_decToExp(s21_simpleIntToDec(2));
  copy = s21_simpleExpIntegerDivisionRemainder(copy, exp_two, &localRemainder);
  s21_expended one = s21_decToExp(s21_simpleIntToDec(1));

  if (remainder->bits[0] < 5) {
    status = 0;
  } else if (remainder->bits[0] > 5) {
    *exp = s21_simpleAdditionExp(*exp, one);
  } else {
    if (localRemainder.bits[0] == 0) {
      status = 0;
    } else {
      *exp = s21_simpleAdditionExp(*exp, one);
    }
  }
  return status;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  *dst = s21_simpleIntToDec(src);
  if (src < 0) s21_setSign(dst, 1);
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int sign = s21_getSign(src);
  s21_truncate(src, &src);
  if (s21_getPartMantissa(&src, 1) != 0 || s21_getPartMantissa(&src, 2) != 0) {
    return 1;  // convertation error
  }
  *dst = s21_getPartMantissa(&src, 0);
  if (sign == 1) *dst *= -1;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  if (dst == NULL)
    status = 1;
  else {
    s21_clearDecimal(dst);
    if (!isnan(src) && src != INFINITY && src != -INFINITY &&
        !(fabsf(src) > 0 && fabs(src) < MIN_FLOAT_TO_DECIMAL) &&
        !(fabsf(src) >= MAX_FLOAT_TO_DECIMAL)) {
      int sign = 0;
      if (src < 0) {
        sign = 1;
        src = -(src);
      }
      long int new = (long int)src;
      long int exp = 0;
      while (src - ((float)new / (long int)(pow(10, exp))) != 0) {
        exp++;
        new = src *(long int)(pow(10, exp));
      }
      s21_from_int_to_decimal(new, dst);
      if (sign) {
        s21_setSign(dst, 1);
      }
      dst->bits[3] += exp << 16;
    } else {
      status = 1;
    }
  }
  return status;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;
  double tmp = 0;
  int scale = 0;
  for (int i = 0; i < mantissa_three; i++) {
    if (s21_getBitGlobal(src, i)) tmp += pow(2, i);
  }
  scale = s21_getScale(src);
  if (scale > 0) {
    for (int i = scale; i > 0; i--) {
      tmp /= 10.0;
    }
  }
  *dst = (float)tmp;
  if (s21_getSign(src)) {
    *dst *= -1;
  } else {
    *dst *= 1;
  }
  return 0;
}

s21_decimal s21_takeLastExpToDec(s21_expended num) {
  s21_decimal result = ZERO_DECIMAL;
  result.bits[0] = num.bits[0];
  result.bits[1] = num.bits[1];
  result.bits[2] = num.bits[2];
  s21_setScale(&result, s21_getScaleExp(num));
  s21_setSign(&result, s21_getSignExp(num));
  return result;
}
s21_expended s21_decToExp(s21_decimal num) {
  s21_expended result = ZERO_EXPENDED;
  result.bits[0] = num.bits[0];
  result.bits[1] = num.bits[1];
  result.bits[2] = num.bits[2];
  s21_setScaleExp(&result, s21_getScale(num));
  s21_setSignExp(&result, s21_getSign(num));
  return result;
}

// cut fractional part (123.456789) of the *value* and remember last digit into
// *remainder*
//                          |_____| in this example digit is 4
//                             ^
//                            this
int s21_cutFractionalPartDec(s21_decimal *value, s21_decimal *remainder) {
  int scale = 0;
  scale = s21_getScale(*value);
  s21_decimal ten = s21_simpleIntToDec(10);
  int curScale = 0;
  for (curScale = scale - 1; curScale >= 0; curScale--) {
    *value = s21_simpleDecIntegerDivisionRemainder(*value, ten, remainder);
    s21_setScale(value, curScale);
  }
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal remainder = ZERO_DECIMAL;
  int sign = s21_getSign(value);
  s21_setSign(&value, 0);
  s21_cutFractionalPartDec(&value, &remainder);
  s21_simpleRoundDec(&value, &remainder);
  s21_setSign(&value, sign);
  s21_copyDecimal(value, result);
  return 0;
}

int s21_simpleRoundDec(s21_decimal *dec, s21_decimal *remainder) {
  if (remainder->bits[0] < 5) {
    return 0;
  } else {
    *dec = s21_simpleAddition(*dec, s21_simpleIntToDec(1));
  }
  return 1;
}
/*
int s21_simpleRoundDecRev(s21_decimal* dec, s21_decimal *remainder){
        if (remainder->bits[0] >= 5){
                return 0;
        } else {
                *dec = s21_simpleAddition(*dec, s21_simpleIntToDec(1));
        }
        return 1;
}
*/
int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_uninformativeZeroCutter(&value);
  int scale = s21_getScale(value);
  if (s21_getSign(value) == 0) {
    s21_truncate(value, result);
  } else {
    s21_truncate(value, result);
    if (scale != 0)
      *result = s21_simpleAddition(*result, s21_simpleIntToDec(1));
    s21_setSign(result, 1);
  }
  return 0;
}
