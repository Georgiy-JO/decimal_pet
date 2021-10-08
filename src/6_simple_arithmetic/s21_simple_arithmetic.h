#ifndef S21_SIMPLE_ARITHMETICS
#define S21_SIMPLE_ARITHMETICS

#include "../s21_decimal.h"
// #include "../bit_operations/s21_bit_operations.h"
// #include "../service_functions/s21_service_functions.h"
// #include "../comparison/s21_comparison.h"
// #include "../convertors/s21_convertors.h"

s21_decimal s21_simpleAddition(s21_decimal num1, s21_decimal num2);
s21_expended s21_simpleAdditionExp(s21_expended num1, s21_expended num2);

s21_decimal s21_simpleSubtraction(s21_decimal num1, s21_decimal num2);
s21_expended s21_simpleSubtractionExp(s21_expended num1, s21_expended num2);

s21_expended s21_simpleDecMultiplicationExpOut(s21_decimal number1,
                                               s21_decimal number2);
s21_decimal s21_simpleDecMultiplication(s21_decimal num1, s21_decimal num2);
s21_decimal s21_simpleIntMultiplication(s21_decimal num1, int num2);
s21_expended s21_simpleExpMultiplication(s21_expended num1, s21_expended num2);
s21_expended s21_simpleExpIntMultiplication(s21_expended num1, int num2);

s21_decimal s21_simpleDecIntegerDivision(s21_decimal dividend,
                                         s21_decimal divider);
s21_decimal s21_simpleDecIntegerDivisionRemainder(s21_decimal dividend,
                                                  s21_decimal divider,
                                                  s21_decimal* remainderr);
s21_decimal s21_simpleIntIntegerDivision(s21_decimal dividend, int divider);
s21_expended s21_simpleExpIntegerDivisionRemainder(s21_expended dividend,
                                                   s21_expended divider,
                                                   s21_expended* remainderr);
s21_expended s21_simpleExpIntegerDivision(s21_expended dividend,
                                          s21_expended divider);
s21_expended s21_simpleIntIntegerDivisionExp(s21_expended dividend,
                                             int divider);

#endif