#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal* result) {
  if (result == NULL) return 1;
  s21_invertSign(&value);
  s21_copyDecimal(value, result);
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  if (result == NULL) return 1;
  s21_singleScaleChange(&value, -s21_getScale(value));
  s21_copyDecimal(value, result);
  return 0;
}