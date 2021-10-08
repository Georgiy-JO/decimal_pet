#ifndef S21_COMPARISON
#define S21_COMPARISON

#include "../s21_decimal.h"

// s21_basic_comparison.c
int s21_decimalCompare(s21_decimal num1, s21_decimal num2);
int s21_bitsCompare(unsigned int num1, unsigned int num2);
int s21_expendedCompare(s21_expended num1, s21_expended num2);

// s21_main_comparison.c
int s21_main_compare(s21_decimal num1, s21_decimal num2);
int s21_compareConverner(s21_decimal num1, s21_decimal num2);

#endif