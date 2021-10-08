#include "s21_arithmetic.h"

s21_expended s21_theAddition(s21_decimal number1, s21_decimal number2) {
  s21_expended result = ZERO_EXPENDED, num1 = s21_decToExp(number1),
               num2 = s21_decToExp(number2);
  int sign1 = s21_getSignExp(num1), sign2 = s21_getSignExp(num2), scale = 0;
  // if(s21_scalingExp(&num1,&num2))
  //     return result;
  s21_scalingExp(&num1, &num2);
  scale = s21_getScaleExp(num1);
  if (sign1 && sign2) {
    result = s21_simpleAdditionExp(num1, num2);
    s21_setSignExp(&result, 1);
  } else if (sign1 && !sign2)
    result = s21_simpleSubtractionExp(num2, num1);
  else if (!sign1 && sign2)
    result = s21_simpleSubtractionExp(num1, num2);
  else  //(!sign1 && !sign2)
    result = s21_simpleAdditionExp(num1, num2);
  s21_setScaleExp(&result, scale);
  return result;
}

s21_expended s21_theSubtraction(s21_decimal number1, s21_decimal number2) {
  s21_expended result = ZERO_EXPENDED, num1 = s21_decToExp(number1),
               num2 = s21_decToExp(number2);
  int sign1 = s21_getSignExp(num1), sign2 = s21_getSignExp(num2), scale = 0;
  // if(s21_scalingExp(&num1,&num2))
  //     return result;
  s21_scalingExp(&num1, &num2);
  scale = s21_getScaleExp(num1);
  if (sign1 && sign2)
    result = s21_simpleSubtractionExp(num2, num1);
  else if (sign1 && !sign2) {
    result = s21_simpleAdditionExp(num1, num2);
    s21_invertSignExp(&result);
  } else if (!sign1 && sign2)
    result = s21_simpleAdditionExp(num1, num2);
  else  //(!sign1 && !sign2)
    result = s21_simpleSubtractionExp(num1, num2);

  s21_setScaleExp(&result, scale);
  return result;
}

s21_expended s21_theMultiplication(s21_decimal number1, s21_decimal number2) {
  s21_expended result = ZERO_EXPENDED, num1 = s21_decToExp(number1),
               num2 = s21_decToExp(number2);
  int sign1 = s21_getSignExp(num1), sign2 = s21_getSignExp(num2);

  result = s21_simpleExpMultiplication(num1, num2);
  //(sign1&&sign2 || !sign1&&!sign2){
  if ((sign1 && !sign2) || (!sign1 && sign2)) s21_invertSignExp(&result);
  s21_setScaleExp(&result, s21_getScaleExp(num1) + s21_getScaleExp(num2));
  return result;
}

s21_expended s21_theDivision(
    s21_decimal number1, s21_decimal number2) {  // more tests probably required
  s21_expended result = ZERO_EXPENDED, dividen = s21_decToExp(number1),
               divider = s21_decToExp(number2), remainderr = ZERO_EXPENDED;
  int sign1 = s21_getSignExp(dividen), sign2 = s21_getSignExp(divider);
  int scale = s21_getScaleExp(dividen) - s21_getScaleExp(divider);
  for (;;) {
    result = s21_simpleAdditionExp(
        result,
        s21_simpleExpIntegerDivisionRemainder(dividen, divider, &remainderr));
    scale++;
    if (s21_isZeroExp(remainderr) || result.bits[DIVISION_RANK] != 0 ||
        scale > DIVISION_SCALE)
      break;
    s21_copyExpended(remainderr, &dividen);
    dividen = s21_simpleExpIntMultiplication(dividen, TEN);
    s21_clearExpended(&remainderr);
    result = s21_simpleExpIntMultiplication(result, TEN);
  }
  scale--;
  if ((sign1 && !sign2) || (!sign1 && sign2)) s21_invertSignExp(&result);
  if (scale >= 0)
    s21_setScaleExp(&result, scale);
  else {
    scale = s21_singleScaleExpChange(&result, -scale);
    s21_zeroScaleExp(&result);
  }
  return result;
}

int s21_add(s21_decimal value1, s21_decimal value2, s21_decimal* result) {
  s21_expended local = s21_theAddition(value1, value2);
  // s21_uninformativeZeroCutterExp(&local);
  *result = s21_fromExpToDec(&local);
  return s21_getErrorbits(*result);
}
int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal* result) {
  s21_expended local = s21_theSubtraction(value1, value2);
  // s21_uninformativeZeroCutterExp(&local);
  *result = s21_fromExpToDec(&local);
  return s21_getErrorbits(*result);
}
int s21_mul(s21_decimal value1, s21_decimal value2, s21_decimal* result) {
  s21_expended local = s21_theMultiplication(value1, value2);
  // s21_uninformativeZeroCutterExp(&local);
  *result = s21_fromExpToDec(&local);
  return s21_getErrorbits(*result);
}
int s21_div(s21_decimal value1, s21_decimal value2, s21_decimal* result) {
  if (s21_isZeroDec(value2)) return 3;
  s21_expended local = s21_theDivision(value1, value2);
  s21_uninformativeZeroCutterExp(&local);
  *result = s21_fromExpToDec(&local);
  return s21_getErrorbits(*result);
}

// error codes of 4 functions above:
// 0 - OK
// 1 - the number is too large or equal to  infinity
// 2 - the number is too small or equal to negative infinity
// 3 - division by on zero
