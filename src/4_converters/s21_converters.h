#ifndef S21_CONVERTORS
#define S21_CONVERTORS

#include "../s21_decimal.h"
#define MAX_FLOAT_TO_DECIMAL 79228162514264337593543950335.0
#define MIN_FLOAT_TO_DECIMAL 1e-28

s21_decimal s21_simpleIntToDec(int num);
s21_decimal s21_simpleUIntToDec(unsigned int num);

int s21_isFitInDec(s21_expended *exp);
s21_decimal s21_fromExpToDec(s21_expended *exp);
int s21_bankRoundingExp(s21_expended *exp, s21_expended *remainder);

int s21_simpleRoundDec(s21_decimal *dec, s21_decimal *remainder);
// int s21_simpleRoundDecRev(s21_decimal* dec, s21_decimal *remainder);

int s21_cutFractionalPartDec(s21_decimal *value, s21_decimal *remainder);

s21_decimal s21_takeLastExpToDec(s21_expended num);
s21_expended s21_decToExp(s21_decimal num);

#endif
