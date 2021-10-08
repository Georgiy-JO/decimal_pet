#include "s21_service_functions.h"

// check if error bits
char s21_getErrorbits(s21_decimal num) {
  return (num.bits[3] & error_bit_mask);
}

void s21_setErrorbitsOne(s21_decimal* num) {
  s21_setBit(&(num->bits[3]), 1, 0);
  s21_setBit(&(num->bits[3]), 0, 1);
}
void s21_setErrorbitsTwo(s21_decimal* num) {
  s21_setBit(&(num->bits[3]), 1, 1);
  s21_setBit(&(num->bits[3]), 0, 0);
}
void s21_setErrorbitsThree(s21_decimal* num) {
  s21_setBit(&(num->bits[3]), 1, 1);
  s21_setBit(&(num->bits[3]), 0, 1);
}

void s21_resetErrorbits(s21_decimal* num) {
  s21_setBit(&(num->bits[3]), 1, 0);
  s21_setBit(&(num->bits[3]), 0, 0);
}
