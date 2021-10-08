#include "s21_comparison.h"

int s21_main_compare(s21_decimal num1, s21_decimal num2) {
  int sign1 = s21_getSign(num1), sign2 = s21_getSign(num2), result = 0;
  if (s21_isZeroDec(num1) && s21_isZeroDec(num2))
    result = 0;
  else if (sign1 && sign2) {
    result = -s21_compareConverner(num1, num2);
    // result*=-1;
  } else if (sign1 && !sign2)
    result = -1;
  else if (!sign1 && sign2)
    result = 1;
  else  //(!sign1 && ! sign2)
    result = s21_compareConverner(num1, num2);
  return result;
}

int s21_compareConverner(s21_decimal num1,
                         s21_decimal num2) {  // was not checked independently
  s21_expended numer1 = s21_decToExp(num1), numer2 = s21_decToExp(num2);
  s21_scalingExp(&numer1, &numer2);
  return s21_expendedCompare(numer1, numer2);
}

// I would recommend more checking for the following 6 functions
int s21_is_less(s21_decimal num1, s21_decimal num2) {
  return (s21_main_compare(num1, num2) < 0) ? 1 : 0;
}
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_main_compare(num1, num2) <= 0) ? 1 : 0;
}
int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  return (s21_main_compare(num1, num2) > 0) ? 1 : 0;
}
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_main_compare(num1, num2) >= 0) ? 1 : 0;
}
int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_main_compare(num1, num2) == 0) ? 1 : 0;
}
int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_main_compare(num1, num2) != 0) ? 1 : 0;
}
