#ifndef S21_ARITHMETICS
#define S21_ARITHMETICS

#include "../s21_decimal.h"
// #include "../simple_arithmetics/s21_simple_arithmetics.h"

#define TEN 10
#define MAXRANK 29
#define MAXRANKEXP 59
#define INTMAXRANK 9

#define DIVISION_SCALE 40
#define DIVISION_RANK 4

int s21_rankOfNumber(s21_decimal num);
int s21_singleScaleChange(s21_decimal *num, int add_scale);
s21_decimal s21_simpleSingleScale(s21_decimal num, int new_scale);
s21_decimal s21_simpleSingleScaleAdd(s21_decimal num, int add_scale);
void s21_scaling(s21_decimal *num1, s21_decimal *num2);
int s21_singleScaleChangeIncr(s21_decimal *num, int add_scale);
int s21_singleScaleChangeDecr(s21_decimal *num, int add_scale);

int s21_scalingExp(s21_expended *num1, s21_expended *num2);
s21_expended s21_simpleSingleScaleExpAdd(s21_expended num, int add_scale);
int s21_singleScaleChangeExpIncr(s21_expended *num, int add_scale);
int s21_singleScaleChangeExpDecr(s21_expended *num, int add_scale);
int s21_rankOfNumberExp(s21_expended num);
int s21_singleScaleExpChange(s21_expended *num, int add_scale);

s21_expended s21_theAddition(s21_decimal numer1, s21_decimal numer2);
s21_expended s21_theSubtraction(s21_decimal number1, s21_decimal number2);
s21_expended s21_theMultiplication(s21_decimal number1, s21_decimal number2);
s21_expended s21_theDivision(s21_decimal number1, s21_decimal number2);

#endif