#include "s21_comparison.h"

// don't work with signes and scales
int s21_decimalCompare(s21_decimal num1, s21_decimal num2) {
  int result = 0;
  for (int i = 2; i >= 0 && result == 0; i--) {
    result = s21_bitsCompare(num1.bits[i], num2.bits[i]);
  }
  return result;
}

int s21_bitsCompare(unsigned int num1, unsigned int num2) {
  if (num1 < num2)
    return -1;
  else if (num1 == num2)
    return 0;
  else
    return 1;
}

// don't work with signes and scales
int s21_expendedCompare(s21_expended num1, s21_expended num2) {
  int result = 0;
  if (s21_getBitGlobalExp(num1, mantissa_six) >
      s21_getBitGlobalExp(num2, mantissa_six))
    result = 1;
  else if (s21_getBitGlobalExp(num1, mantissa_six) <
           s21_getBitGlobalExp(num2, mantissa_six))
    result = -1;
  else {
    for (int i = 5; i >= 0 && result == 0; i--) {
      result = s21_bitsCompare(num1.bits[i], num2.bits[i]);
    }
  }
  return result;
}