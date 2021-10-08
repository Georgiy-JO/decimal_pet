#ifndef S21_SERVICE_FUNCTIONS
#define S21_SERVICE_FUNCTIONS

#include "../s21_decimal.h"
// #include "../bit_operations/s21_bit_operations.h"

#define error_out_of_range 5
#define error_wrong_value 6
#define error_scale_out_of_range 30
#define error_bit 32 * 3
#define error_bit_mask 0x00000003

char s21_getErrorbits(s21_decimal num);
void s21_setErrorbitsOne(s21_decimal* num);
void s21_setErrorbitsThree(s21_decimal* num);
void s21_setErrorbitsTwo(s21_decimal* num);
void s21_resetErrorbits(s21_decimal* num);

void s21_uninformativeZeroCutterExp(s21_expended* num);
void s21_decimalFillerExp(s21_expended* num);
void s21_uninformativeZeroCutter(s21_decimal* num);

#endif