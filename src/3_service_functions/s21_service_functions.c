#include "s21_service_functions.h"

void s21_uninformativeZeroCutterExp(s21_expended* num) {
  int scale = s21_getScaleExp(*num);
  s21_expended sample = ZERO_EXPENDED, reminder = ZERO_EXPENDED,
               ten = s21_decToExp(s21_simpleIntToDec(10));
  s21_copyExpended(*num, &sample);
  for (; scale > 0 && reminder.bits[0] == 0; scale--) {
    sample = s21_simpleExpIntegerDivisionRemainder(sample, ten, &reminder);
  }
  if (reminder.bits[0] != 0) scale++;
  s21_singleScaleExpChange(num, scale - s21_getScaleExp(*num));
}

void s21_decimalFillerExp(s21_expended* num) {
  int scale = s21_getScaleExp(*num);
  s21_expended sample = ZERO_EXPENDED;
  s21_copyExpended(*num, &sample);
  for (; scale < SCALE_MAX && sample.bits[3] == 0 && sample.bits[4] == 0 &&
         sample.bits[5] == 0;
       scale++) {
    sample = s21_simpleExpIntMultiplication(sample, TEN);
  }
  if ((sample.bits[3] != 0 || sample.bits[4] != 0 || sample.bits[5] != 0) &&
      scale != s21_getScaleExp(*num))
    scale--;
  s21_singleScaleExpChange(num, scale - s21_getScaleExp(*num));
}

void s21_uninformativeZeroCutter(s21_decimal* num) {
  int scale = s21_getScale(*num);
  s21_decimal sample = ZERO_DECIMAL, reminder = ZERO_DECIMAL,
              ten = s21_simpleIntToDec(10);
  s21_copyDecimal(*num, &sample);
  for (; scale > 0 && reminder.bits[0] == 0; scale--) {
    sample = s21_simpleDecIntegerDivisionRemainder(sample, ten, &reminder);
  }

  if (reminder.bits[0] != 0) scale++;

  s21_singleScaleChange(num, scale - s21_getScale(*num));
}
