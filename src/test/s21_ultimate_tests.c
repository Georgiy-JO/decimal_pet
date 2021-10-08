#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

START_TEST(s21_bank) {
  s21_decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 1.5;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_expended src1e = s21_decToExp(src1);
  s21_expended src2e = s21_decToExp(src2);
  s21_bankRoundingExp(&src1e, &src2e);
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  src1 = s21_takeLastExpToDec(src1e);
  ck_assert_int_eq(origin.bits[3], src1.bits[3]);
  ck_assert_int_eq(origin.bits[2], src1.bits[2]);
  ck_assert_int_eq(origin.bits[1], src1.bits[1]);
  ck_assert_int_eq(origin.bits[0], src1.bits[0]);
}
END_TEST

// elevator   bit_operations (test 1-2/-)
START_TEST(test_bit_operations_original) {
  printf(
      "TESTING: "
      "bit_operations/"
      "s21_bit_operations.c...................................................."
      ".............\n");

  s21_decimal number = {{0, 0, 0, 0}};
  int num_test = 0;
  int index = 64;

  //--------------------------------------------------------------------------------------

  // printf("#%d\n",num_test);
  s21_setBitGlobal(&number, 0, 1);
  ck_assert_uint_eq(s21_getBitGlobal(number, 0), 1);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000001\n");
  // printf("Result: ");
  // s21_printDecimalBin( number);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_setBit(&number.bits[0], 8, 1);
  ck_assert_uint_eq(s21_getBitGlobal(number, 8), 1);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000100000001\n");
  // printf("Result: ");
  // s21_printDecimalBin( number);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_setBitGlobal(&number, index, 1);
  ck_assert_uint_eq(s21_getBitGlobal(number, 64), 1);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000001|00000000000000000000000000000000|00000000000000000000000100000001\n");
  // printf("Result: ");
  // s21_printDecimalBin( number);
  // printf("\n\n");
  num_test++;

  s21_clearDecimal(&number);
  ck_assert_uint_eq(s21_getBitGlobal(number, 64), 0);

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("%d\n",0);
  // printf("Result: ");
  // printf("%d\n",s21_getBitGlobal(number,index));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_setBitGlobal(&number, index, 1);
  ck_assert_uint_eq(s21_getBitGlobal(number, index), 1);
  // printf("Meant:  ");
  // printf("%d\n",1);
  // printf("Result: ");
  // printf("%d\n",s21_getBitGlobal(number,index));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("%d\n",1);
  // printf("Result: ");
  // printf("%d\n",s21_getBit(number.bits[2],0));
  ck_assert_uint_eq(s21_getBitGlobal(number, 2), 0);
  // printf("\n\n");
  num_test++;

  //--------------------------------------------------------------------------------------

  s21_clearDecimal(&number);

  ck_assert_uint_eq(s21_getSign(number), 0);

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("%d\n",0);
  // printf("Result: ");
  // printf("%d\n",s21_getSign(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_setSign(&number, 1);
  ck_assert_uint_eq(s21_getSign(number), 1);
  // printf("Meant:  ");
  // printf("%d\n",1);
  // printf("Result: ");
  // printf("%d\n",s21_getSign(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_invertSign(&number);
  ck_assert_uint_eq(s21_getSign(number), 0);
  // printf("Meant:  ");
  // printf("%d\n",0);
  // printf("Result: ");
  // printf("%d\n",s21_getSign(number));
  // printf("\n\n");
  num_test++;

  ck_assert_uint_eq(s21_getScale(number), 0);
  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("%d\n",0);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_setScale(&number, 10);
  ck_assert_uint_eq(s21_getScale(number), 10);
  // printf("Meant:  ");
  // printf("%d\n",10);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_setScale(&number, 28);
  ck_assert_uint_eq(s21_getScale(number), 28);
  // printf("Meant:  ");
  // printf("%d\n",28);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_zeroScale(&number);
  ck_assert_uint_eq(s21_getScale(number), 0);
  // printf("Meant:  ");
  // printf("%d\n",0);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_increaseScale(&number);
  ck_assert_uint_eq(s21_getScale(number), 1);
  // printf("Meant:  ");
  // printf("%d\n",1);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_increaseScaleUlt(&number, 5);
  ck_assert_uint_eq(s21_getScale(number), 6);
  // printf("Meant:  ");
  // printf("%d\n",6);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_decreaseScale(&number);
  ck_assert_uint_eq(s21_getScale(number), 5);
  // printf("Meant:  ");
  // printf("%d\n",5);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_decreaseScaleUlt(&number, 3);
  ck_assert_uint_eq(s21_getScale(number), 2);
  // printf("Meant:  ");
  // printf("%d\n",2);
  // printf("Result: ");
  // printf("%u\n",s21_getScale(number));
  // printf("\n\n");
  num_test++;

  //--------------------------------------------------------------------------------------

  s21_clearDecimal(&number);

  // printf("#%d\n",num_test);
  s21_decimal number2 = {{132131231, 132132, 34414432, 0}};
  s21_setScale(&number2, 15);
  s21_setSign(&number2, 1);
  ck_assert_uint_eq(s21_getScale(number2), 15);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(number2.bits[0], 132131231);
  ck_assert_uint_eq(number2.bits[1], 132132);
  ck_assert_uint_eq(number2.bits[2], 34414432);
  // printf("Meant:  ");
  // printf("10000000000011110000000000000000|00000010000011010001111101100000|00000000000000100000010000100100|00000111111000000010100110011111\n");
  printf("Print test Decimal #1: \n");
  s21_printDecimalBin(number2);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("11111001100101000000011111100000|00100100001000000100000000000000|00000110111110001011000001000000|00000000000000001111000000000001\n");
  // printf("Result: ");
  printf("Print test Decimal #2: \n");
  s21_printDecimalBinRev(number2);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("00000111111000000010100110011111|00000000000000100000010000100100|00000010000011010001111101100000|10000000000011110000000000000000\n");
  // printf("Result: ");
  printf("Print test Decimal #3: \n");
  s21_printDecimalBinReal(number2);
  // printf("\n\n");
  num_test++;

  //--------------------------------------------------------------------------------------

  // printf("#%d\n",num_test);
  s21_setPartMantissa(&number2, 0, 17);
  ck_assert_uint_eq(s21_getScale(number2), 15);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(number2.bits[0], 17);
  ck_assert_uint_eq(number2.bits[1], 132132);
  ck_assert_uint_eq(number2.bits[2], 34414432);
  ck_assert_uint_eq(s21_getPartMantissa(&number2, 0), 17);
  // printf("Meant:  ");
  // printf("10000000000011110000000000000000|00000010000011010001111101100000|00000000000000100000010000100100|00000000000000000000000000010001\n");
  // printf("Result: ");
  // s21_printDecimalBin(number2);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("17\n");
  // printf("Result: ");
  // printf("%u\n",s21_getPartMantissa(&number2,0));
  // printf("\n\n");
  num_test++;

  //--------------------------------------------------------------------------------------

  // printf("#%d\n",num_test);
  s21_leftShift(&number2, 5);
  ck_assert_uint_eq(s21_getScale(number2), 15);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(number2.bits[0], 544);
  ck_assert_uint_eq(number2.bits[1], 4228224);
  ck_assert_uint_eq(number2.bits[2], 1101261824);

  // printf("Meant:  ");
  // printf("10000000000011110000000000000000|01000001101000111110110000000000|00000000010000001000010010000000|00000000000000000000001000100000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number2);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_leftShift(&number2, 10);
  ck_assert_uint_eq(s21_getScale(number2), 15);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(number2.bits[0], 557056);
  ck_assert_uint_eq(number2.bits[1], 34734080);
  ck_assert_uint_eq(number2.bits[2], 2410676225);

  // printf("Meant:  ");
  // printf("10000000000011110000000000000000|10001111101100000000000000000001|00000010000100100000000000000000|00000000000010001000000000000000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number2);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  s21_rightShift(&number2, 20);
  ck_assert_uint_eq(s21_getScale(number2), 15);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(number2.bits[0], 536870912);
  ck_assert_uint_eq(number2.bits[1], 4129);
  ck_assert_uint_eq(number2.bits[2], 2299);

  // printf("Meant:  ");
  // printf("10000000000011110000000000000000|00000000000000000000100011111011|00000000000000000001000000100001|00100000000000000000000000000000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number2);
  // printf("\n\n");
  num_test++;

  //--------------------------------------------------------------------------------------

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number);
  s21_clearDecimal(&number);
  ck_assert_uint_eq(s21_getScale(number), 0);
  ck_assert_uint_eq(s21_getSign(number), 0);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  s21_copyDecimal(number2, &number);
  ck_assert_uint_eq(s21_getScale(number), 15);
  ck_assert_uint_eq(s21_getSign(number), 1);
  ck_assert_uint_eq(number.bits[0], 536870912);
  ck_assert_uint_eq(number.bits[1], 4129);
  ck_assert_uint_eq(number.bits[2], 2299);
  s21_clearDecimal(&number2);
  ck_assert_uint_eq(s21_getScale(number2), 0);
  ck_assert_uint_eq(s21_getSign(number2), 0);
  ck_assert_uint_eq(number2.bits[0], 0);
  ck_assert_uint_eq(number2.bits[1], 0);
  ck_assert_uint_eq(number2.bits[2], 0);

  // printf("Meant:  ");
  // printf("10000000000011110000000000000000|00000000000000000000100011111011|00000000000000000001000000100001|00100000000000000000000000000000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number);
  // printf("\n\n");
  num_test++;

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number2);
  // printf("\n\n");
  num_test++;

  //--------------------------------------------------------------------------------------

  // printf("#%d\n",num_test);
  // printf("Meant:  ");
  // printf("%d\n", 76);
  // printf("Result: ");
  // printf("%d\n", s21_mantissaLength(number));
  // printf("\n\n");
  num_test++;
  ck_assert_uint_eq(s21_mantissaLength(number), 76);
  s21_setBitGlobal(&number, mantissa_three - 10, 1);
  ck_assert_uint_eq(s21_mantissaFirstBit(number), 86);
}
START_TEST(test_bit_operations_extra_shift_1) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  unsigned int a = 0;

  a = 27;
  number.bits[0] = a;
  number2.bits[0] = a;
  s21_leftShift(&number, 0);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);

  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  a = 44;
  number.bits[0] = a;
  number2.bits[0] = a;
  s21_rightShift(&number, 0);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);

  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  a = 44;
  number.bits[0] = a;
  number.bits[1] = 0;
  number2.bits[0] = 0;
  number2.bits[1] = a;
  s21_leftShift(&number, 32);
  ck_assert_uint_eq(number.bits[0], number2.bits[0]);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);

  s21_rightShift(&number2, 32);
  s21_leftShift(&number2, 64);
  s21_leftShift(&number, 32);
  ck_assert_uint_eq(number.bits[0], number2.bits[0]);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);
  ck_assert_uint_eq(number.bits[2], number2.bits[2]);

  s21_rightShift(&number, 64);
  s21_leftShift(&number, 96);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);

  ck_assert_uint_eq(s21_isZeroDec(number), 1);
  ck_assert_uint_eq(s21_isZeroDec(number2), 0);
}

// elevator   basic_comparison (test 3-5/-)
START_TEST(test_simple_comparison_bitsCompare) {
  printf(
      "TESTING: "
      "comparison/"
      "s21_basic_comparison.c.................................................."
      "...............\n");

  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  int bigger = 1, smaller = -1, equal = 0;
  s21_setPartMantissa(&number, 0, 17);
  s21_setPartMantissa(&number2, 0, 25);
  ck_assert_int_eq(s21_bitsCompare(number.bits[0], number2.bits[0]), smaller);
  ck_assert_int_eq(s21_bitsCompare(number2.bits[0], number.bits[0]), bigger);
  ck_assert_int_eq(s21_bitsCompare(number2.bits[0], number2.bits[0]), equal);
}
START_TEST(test_simple_comparison_decimalCompare) {
  s21_decimal number = {{0, 123, 0, 0}}, number2 = {{3, 12, 0, 0}};
  int bigger = 1, smaller = -1, equal = 0;
  ck_assert_int_eq(s21_decimalCompare(number, number2), bigger);
  ck_assert_int_eq(s21_decimalCompare(number2, number), smaller);
  ck_assert_int_eq(s21_decimalCompare(number2, number2), equal);

  s21_setPartMantissa(&number, 2, 17);
  s21_setPartMantissa(&number2, 2, 25);
  ck_assert_int_eq(s21_decimalCompare(number, number2), smaller);
  ck_assert_int_eq(s21_decimalCompare(number2, number), bigger);
  ck_assert_int_eq(s21_decimalCompare(number2, number2), equal);

  s21_copyDecimal(number, &number2);
  ck_assert_int_eq(s21_decimalCompare(number, number2), equal);
}
START_TEST(test_simple_comparison_expendedCompare) {
  s21_expended number = {{0, 0, 123, 0, 0, 5, 0}},
               number2 = {{0, 3, 12, 0, 0, 1000, 0}};
  int bigger = 1, smaller = -1, equal = 0;
  ck_assert_int_eq(s21_expendedCompare(number, number2), smaller);
  ck_assert_int_eq(s21_expendedCompare(number2, number), bigger);
  ck_assert_int_eq(s21_expendedCompare(number2, number2), equal);

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  number.bits[6] = 0;
  number2.bits[0] = 4;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  number2.bits[6] = 0;
  ck_assert_int_eq(s21_expendedCompare(number, number2), bigger);
  ck_assert_int_eq(s21_expendedCompare(number2, number), smaller);
  ck_assert_int_eq(s21_expendedCompare(number, number), equal);

  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  number.bits[6] = 0;
  number2.bits[0] = 0;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  number2.bits[6] = 1;
  ck_assert_int_eq(s21_expendedCompare(number, number2), smaller);

  s21_copyExpended(number, &number2);
  ck_assert_int_eq(s21_expendedCompare(number, number2), equal);
}

// elevator   simple_converters (test 6-8/-)
START_TEST(test_simple_converters_1) {
  printf(
      "TESTING: "
      "converters/"
      "s21_simple_converters.c................................................."
      "................\n");

  s21_decimal number = ZERO_DECIMAL;
  int number2 = 0;
  // #1
  number = s21_simpleIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #2
  number2 = 10;
  number = s21_simpleIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], 10);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #3
  number2 = 100;
  number = s21_simpleIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], 100);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #4
  number2 = -100;
  number = s21_simpleIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], 100);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #5
  number2 = -2147483647;
  number = s21_simpleIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], -number2);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #6
  number2 = 21474;
  number = s21_simpleIntToDec(number2);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000101001111100010\n");
  // printf("Result: ");
  // s21_printDecimalBin(number);
  // printf("\n");
}
START_TEST(test_simple_converters_2) {
  s21_decimal number = ZERO_DECIMAL;
  unsigned int number2 = 0;
  // #1
  number = s21_simpleUIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #2
  number2 = 10;
  number = s21_simpleUIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], number2);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #3
  number2 = 100;
  number = s21_simpleUIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], number2);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #4
  number2 = 4294967295;
  number = s21_simpleUIntToDec(number2);
  ck_assert_uint_eq(number.bits[0], number2);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  // #5
  number2 = 2147554;
  number = s21_simpleUIntToDec(number2);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000001000001100010011100010\n");
  // printf("Result: ");
  // s21_printDecimalBin(number);
  // printf("\n");
}
START_TEST(test_simple_converters_3) {
  s21_expended number = ZERO_EXPENDED;
  s21_decimal number2 = ZERO_DECIMAL;

  s21_setSign(&number2, 1);
  s21_setScale(&number2, 15);
  number2.bits[0] = 555;
  number2.bits[1] = 5554434;
  number2.bits[2] = 155443422;
  number = s21_decToExp(number2);
  ck_assert_uint_eq(number.bits[0], number2.bits[0]);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);
  ck_assert_uint_eq(number.bits[2], number2.bits[2]);
  ck_assert_uint_eq(number.bits[3], 0);
  ck_assert_uint_eq(number.bits[4], 0);
  ck_assert_uint_eq(number.bits[5], 0);
  ck_assert_uint_eq(s21_getBitGlobalExp(number, mantissa_six), 0);
  ck_assert_uint_eq(s21_getSignExp(number), 1);
  ck_assert_uint_eq(s21_getScaleExp(number), 15);

  s21_clearDecimal(&number2);
  s21_clearExpended(&number);

  s21_invertSignExp(&number);
  s21_setScaleExp(&number, 28);
  number.bits[0] = 123;
  number.bits[1] = 456789;
  number.bits[2] = 10111516;
  number.bits[3] = 171819;
  number.bits[4] = 20;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 1);
  number2 = s21_takeLastExpToDec(number);
  ck_assert_uint_eq(number.bits[0], number2.bits[0]);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);
  ck_assert_uint_eq(number.bits[2], number2.bits[2]);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScaleExp(number));
  // s21_printDecimalBin(number2);
  // s21_printExpendedBin(number);
}

// elevator   error_handler (test 9/-)
START_TEST(test_error_bit) {
  printf(
      "TESTING: "
      "service_functions/"
      "s21_error_handler.c....................................................."
      "............\n");

  s21_decimal number = ZERO_DECIMAL;
  char check_flag = 0;

  ck_assert_int_eq(s21_getErrorbits(number), check_flag);
  s21_setErrorbitsOne(&number);
  check_flag = 1;
  ck_assert_int_eq(s21_getErrorbits(number), check_flag);
  s21_resetErrorbits(&number);
  s21_setErrorbitsTwo(&number);
  check_flag = 2;
  ck_assert_int_eq(s21_getErrorbits(number), check_flag);
  s21_resetErrorbits(&number);
  s21_setErrorbitsThree(&number);
  check_flag = 3;
  ck_assert_int_eq(s21_getErrorbits(number), check_flag);
  // printf("Meant:  ");
  // printf("00000000000000000000000000000001|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000\n");
  // printf("Result: ");
  // s21_printDecimalBin(number);
  // printf("\n");
  s21_resetErrorbits(&number);
  check_flag = 0;
  ck_assert_int_eq(s21_getErrorbits(number), check_flag);
}

// elevator  massive_decimal  (test 10-12/-)
START_TEST(test_expended_bit) {
  printf(
      "TESTING: "
      "massive_decimal/"
      "s21_massive_decimal_bit.c..............................................."
      "..................\n");

  s21_expended number = ZERO_EXPENDED, number2 = ZERO_EXPENDED;
  unsigned int b0 = 0;

  b0 = 5;

  s21_setBitGlobalExp(&number, 0, 1);
  s21_setBitGlobalExp(&number, 2, 1);
  ck_assert_uint_eq(number.bits[0], b0);
  s21_setBitGlobalExp(&number, 105, 1);
  ck_assert_uint_eq(number.bits[3], 512);

  ck_assert_uint_eq(s21_getBitGlobalExp(number, 105), 1);
  ck_assert_uint_eq(s21_getBitGlobalExp(number, 106), 0);
  ck_assert_uint_eq(s21_getBitGlobalExp(number, 104), 0);

  s21_setSignExp(&number, 1);
  ck_assert_uint_eq(s21_getSignExp(number), 1);
  s21_setSignExp(&number, 0);
  ck_assert_uint_eq(s21_getSignExp(number), 0);
  s21_invertSignExp(&number);

  // printf("Meant:  ");
  // printf("10000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000001000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000101\n");
  printf("Print test Ex. Decimal #4: \n");
  s21_printExpendedBin(number);
  // printf("\n");

  // printf("Meant:  ");
  // printf("0|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000001000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000000101\n");
  printf("Print test Ex. Decimal #5: \n");
  s21_printExpendedMantissa(number);
  // printf("\n");

  s21_copyExpended(number, &number2);
  ck_assert_uint_eq(number2.bits[0], number.bits[0]);
  ck_assert_uint_eq(number2.bits[1], number.bits[1]);
  ck_assert_uint_eq(number2.bits[2], number.bits[2]);
  ck_assert_uint_eq(number2.bits[3], number.bits[3]);
  ck_assert_uint_eq(number2.bits[4], number.bits[4]);
  ck_assert_uint_eq(number2.bits[5], number.bits[5]);
  ck_assert_uint_eq(number2.bits[6], number.bits[6]);

  s21_clearExpended(&number);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  ck_assert_uint_eq(number.bits[4], 0);
  ck_assert_uint_eq(number.bits[5], 0);
  ck_assert_uint_eq(number.bits[6], 0);

  s21_clearExpended(&number);
  b0 = 155;
  s21_setBitGlobalExp(&number, b0, 1);
  ck_assert_uint_eq(s21_mantissaExpLength(number), b0 + 1);

  s21_setBitGlobalExp(&number, mantissa_six, 1);
  ck_assert_uint_eq(s21_mantissaExpFirstBit(number), mantissa_six);
}
START_TEST(test_expended_bit_shift) {
  s21_expended number = ZERO_EXPENDED;

  number.bits[0] = 3;
  s21_leftShiftExp(&number, 2);
  ck_assert_uint_eq(number.bits[0], 12);

  s21_leftShiftExp(&number, 34);
  ck_assert_uint_eq(number.bits[1], 48);
  ck_assert_uint_eq(number.bits[0], 0);

  s21_rightShiftExp(&number, 5);
  ck_assert_uint_eq(number.bits[1], 1);
  ck_assert_uint_eq(number.bits[0], 2147483648);

  s21_leftShiftExp(&number, mantissa_five);
  ck_assert_uint_eq(s21_getBitGlobalExp(number, mantissa_six), 1);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  ck_assert_uint_eq(number.bits[4], 0);
  ck_assert_uint_eq(number.bits[5], 2147483648);

  s21_leftShiftExp(&number, 0);
  ck_assert_uint_eq(s21_getBitGlobalExp(number, mantissa_six), 1);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  ck_assert_uint_eq(number.bits[4], 0);
  ck_assert_uint_eq(number.bits[5], 2147483648);

  s21_rightShiftExp(&number, mantissa_six);
  ck_assert_uint_eq(s21_getBitGlobalExp(number, mantissa_six), 0);
  ck_assert_uint_eq(number.bits[0], 1);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  ck_assert_uint_eq(number.bits[4], 0);
  ck_assert_uint_eq(number.bits[5], 0);

  s21_leftShiftExp(&number, mantissa_six + 1);
  ck_assert_uint_eq(number.bits[0], 0);
  ck_assert_uint_eq(number.bits[1], 0);
  ck_assert_uint_eq(number.bits[2], 0);
  ck_assert_uint_eq(number.bits[3], 0);
  ck_assert_uint_eq(number.bits[4], 0);
  ck_assert_uint_eq(number.bits[5], 0);
  ck_assert_uint_eq(number.bits[6], 0);
}
START_TEST(test_expended_bit_scale) {
  s21_expended number = ZERO_EXPENDED;

  number.bits[0] = 3;
  number.bits[1] = 154;
  number.bits[2] = 444;
  number.bits[3] = 22;
  number.bits[4] = 1;
  number.bits[5] = 0;
  s21_setSignExp(&number, 1);
  s21_setScaleExp(&number, 15);

  ck_assert_uint_eq(number.bits[0], 3);
  ck_assert_uint_eq(number.bits[1], 154);
  ck_assert_uint_eq(number.bits[2], 444);
  ck_assert_uint_eq(number.bits[3], 22);
  ck_assert_uint_eq(number.bits[4], 1);
  ck_assert_uint_eq(number.bits[5], 0);
  ck_assert_uint_eq(s21_getSignExp(number), 1);
  ck_assert_uint_eq(s21_getScaleExp(number), 15);

  s21_setScaleExp(&number, 28);
  ck_assert_uint_eq(s21_getScaleExp(number), 28);
  s21_setScaleExp(&number, 58);
  ck_assert_uint_eq(s21_getScaleExp(number), 58);
  s21_setScaleExp(&number, 0);
  ck_assert_uint_eq(s21_getScaleExp(number), 0);
  s21_setScaleExp(&number, 8);
  ck_assert_uint_eq(s21_getScaleExp(number), 8);
  s21_zeroScaleExp(&number);
  ck_assert_uint_eq(s21_getScaleExp(number), 0);
  s21_increaseScaleExp(&number);
  ck_assert_uint_eq(s21_getScaleExp(number), 1);
  s21_increaseScaleExpUlt(&number, 5);
  ck_assert_uint_eq(s21_getScaleExp(number), 6);
  s21_decreaseScaleExpUlt(&number, 4);
  ck_assert_uint_eq(s21_getScaleExp(number), 2);
  s21_decreaseScaleExp(&number);
  s21_decreaseScaleExp(&number);
  ck_assert_uint_eq(s21_getScaleExp(number), 0);

  s21_clearExpended(&number);
  ck_assert_uint_eq(s21_isZeroExp(number), 1);
  number.bits[6] = 1;
  ck_assert_uint_eq(s21_isZeroExp(number), 0);
  s21_clearExpended(&number);
  number.bits[0] = 1;
  ck_assert_uint_eq(s21_isZeroExp(number), 0);
}

// elevator  simple_arithmetic  (test 13-24/-)
START_TEST(test_simple_arithmetic_addition_1) {
  printf(
      "TESTING: "
      "simple_arithmetic/"
      "s21_simple_arithmetic.c................................................."
      "................\n");
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              result = ZERO_DECIMAL;
  unsigned int a = 0, b = 0, res = 0, zero = 0;

  // #1
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a + b;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #2
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 17;
  b = 28;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a + b;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #3
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 4294967295;
  b = 2;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = 1;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], res);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);
}
START_TEST(test_simple_arithmetic_addition_2) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              result = ZERO_DECIMAL;
  unsigned int a0 = 0, a1 = 0, a2 = 0, b0 = 0, b1 = 0, b2 = 0, res0 = 0,
               res1 = 0, res2 = 0, zero = 0;

  // #1
  // number =    4294967295555456464646         (11101000
  // 11010100101001010000111110011000 01111111001000111111011100000110) number2
  // = 429496729555545996464646 (0101101011110011
  // 00010000011110100001011110010001 10111110111010010001001000000110) result =
  // 433791696851101452929292 (0101101111011011 11100101000111110010011100101010
  // 00111110000011010000100100001100)
  a0 = 2133063430;
  a1 = 3567587224;
  a2 = 232;
  b0 = 3202945542;
  b1 = 276436881;
  b2 = 23283;
  res0 = 1041041676;
  res1 = 3844024106;
  res2 = 23515;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000101101111011011|11100101000111110010011100101010|00111110000011010000100100001100\n");
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  // #2
  // number =      9999999999999999999999             (001000011110
  // 00011001111000001100100110111010 10110010001111111111111111111111) number2
  // = 88888888888888888888888888 (010010011000011011110100
  // 01010010011110001110111011110100 01011000111000111000111000111000) result =
  // 88898888888888888888888887 (010010011000100100010010
  // 01101100010110011011100010101111 00001011001000111000111000110111)
  a0 = 2990538751;
  a1 = 434162106;
  a2 = 542;
  b0 = 1491308088;
  b1 = 1383657204;
  b2 = 4818676;
  res0 = 186879543;
  res1 = 1817819311;
  res2 = 4819218;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // #3
  // number =  151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // = 151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) result =
  // 302231454903657293676542 (0000011111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111110)
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 8191;
  b0 = 4294967295;
  b1 = 4294967295;
  b2 = 8191;
  res0 = 4294967294;
  res1 = 4294967295;
  res2 = 16383;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // #4
  // number =  79228162514264337593543950335 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // =                             5 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000101) result =
  // error
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 4294967295;
  b0 = 5;
  b1 = 0;
  b2 = 0;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleAddition(number, number2);
  ck_assert_uint_eq(s21_getErrorbits(result), 1);
}
START_TEST(test_simple_arithmetic_addition_expended) {
  s21_expended number = ZERO_EXPENDED, number2 = ZERO_EXPENDED,
               result = ZERO_EXPENDED, check = ZERO_EXPENDED;

  // #1
  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 4;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 9;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);

  result = s21_simpleAdditionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // #2
  // number = 4294967295555456464646
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000000000000000000000011101000 11010100101001010000111110011000
  //    01111111001000111111011100000110)
  // number2 = 429496729555545555996464646
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000001011000110100010101111000 01011100111011000001000011101011
  //    00110000011110110101011000000110)
  // result = 429501024522841111452929292
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000001011000110100011001100001 00110001100100010010000010000011
  //    10101111100111110100110100001100)
  number.bits[0] = 2133063430;
  number.bits[1] = 3567587224;
  number.bits[2] = 232;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 813389318;
  number2.bits[1] = 1558974699;
  number2.bits[2] = 23283064;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 2946452748;
  check.bits[1] = 831594627;
  check.bits[2] = 23283297;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);

  result = s21_simpleAdditionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // #3
  // number = 5555555555555555555555555555555555555555555555
  //(0 00000000000000000000000000000000 00000000111110010001111010100110
  // 01101101100101110010000110001011
  //    00100101110100000100010101000000 00111101110111001100111000111000
  //    11100011100011100011100011100011)
  // number2 = 99999999999999999999999999999999999
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000100110100001001100001
  //    01110010110001110100110110000010 00101011100001111000111111100111
  //    11111111111111111111111111111111)
  // result = 5555555555655555555555555555555555555555555554
  //(0 00000000000000000000000000000000 00000000111110010001111010100110
  // 01101101101010100110001111101100
  //    10011000100101111001001011000010 01101001011001000101111000100000
  //    11100011100011100011100011100010)
  number.bits[0] = 3817748707;
  number.bits[1] = 1037880888;
  number.bits[2] = 634406208;
  number.bits[3] = 1838621067;
  number.bits[4] = 16326310;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 730304487;
  number2.bits[2] = 1925664130;
  number2.bits[3] = 1262177;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 3817748706;
  check.bits[1] = 1768185376;
  check.bits[2] = 2560070338;
  check.bits[3] = 1839883244;
  check.bits[4] = 16326310;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);

  result = s21_simpleAdditionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // #4
  // number =  ...
  //(1 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111110
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  // number2 = 0
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  // result = number 1
  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 4294967294;
  number.bits[4] = 4294967295;
  number.bits[5] = 4294967295;
  s21_setBitGlobalExp(&number, mantissa_six, 1);
  number2.bits[0] = 0;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  s21_copyExpended(number, &check);

  result = s21_simpleAdditionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // #5
  // number =
  //(0 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111110
  //    11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  // number2 =
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  // result =
  //(1 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  number.bits[3] = 4294967294;
  number.bits[4] = 4294967295;
  number.bits[5] = 4294967295;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 1;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 1);

  result = s21_simpleAdditionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);
  // printf("!Result:");
  // s21_printExpendedBin(result);

  /*
    //number =
    //(0 00000000000000000000000000000000 00000000000000000000000000000000
    00000000000000000000000000000000
    //   00000000000000000000000000000000 00000000000000000000000000000000
    00000000000000000000000000000000)
    //number2 =
    //(0 00000000000000000000000000000000 00000000000000000000000000000000
    00000000000000000000000000000000
    //   00000000000000000000000000000000 00000000000000000000000000000000
    00000000000000000000000000000000)
    //result =
    //(0 00000000000000000000000000000000 00000000000000000000000000000000
    00000000000000000000000000000000
    //   00000000000000000000000000000000 00000000000000000000000000000000
    00000000000000000000000000000000)


    number.bits[0]=;
    number.bits[1]=;
    number.bits[2]=;
    number.bits[3]=;
    number.bits[4]=;
    number.bits[5]=;
    s21_setBitGlobalExp(&number,mantissa_six,);
    number2.bits[0]=;
    number2.bits[1]=;
    number2.bits[2]=;
    number2.bits[3]=;
    number2.bits[4]=;
    number2.bits[5]=;
    s21_setBitGlobalExp(&number2,mantissa_six,);
    check.bits[0]=;
    check.bits[1]=;
    check.bits[2]=;
    check.bits[3]=;
    check.bits[4]=;
    check.bits[5]=;
    s21_setBitGlobalExp(&check,mantissa_six,);

    result=s21_simpleAdditionExp(number,number2);
    ck_assert_uint_eq(result.bits[0],check.bits[0]);
    ck_assert_uint_eq(result.bits[1],check.bits[1]);
    ck_assert_uint_eq(result.bits[2],check.bits[2]);
    ck_assert_uint_eq(result.bits[3],check.bits[3]);
    ck_assert_uint_eq(result.bits[4],check.bits[4]);
    ck_assert_uint_eq(result.bits[5],check.bits[5]);
    ck_assert_uint_eq(result.bits[6],check.bits[6]);
  */
}

START_TEST(test_simple_arithmetic_subtraction_1) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              result = ZERO_DECIMAL;
  unsigned int a = 0, b = 0, res = 0, zero = 0;

  // #1
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a - b;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #5
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 555;
  b = 555;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a - b;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], zero);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #2
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 445;
  b = 259;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a - b;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #3
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 1;
  b = 2;
  number.bits[0] = a;
  number.bits[1] = a;
  number2.bits[0] = b;
  res = 4294967295;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #4
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 55;
  b = 555;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = b - a;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(s21_getSign(result), 1);
}
START_TEST(test_simple_arithmetic_subtraction_2) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              result = ZERO_DECIMAL;
  unsigned int a0 = 0, a1 = 0, a2 = 0, b0 = 0, b1 = 0, b2 = 0, res0 = 0,
               res1 = 0, res2 = 0, zero = 0;

  // #1
  // number =  429496729555545996464646  (0101101011110011
  // 00010000011110100001011110010001 10111110111010010001001000000110) number2
  // =   4294967295555456464646          (11101000
  // 11010100101001010000111110011000 01111111001000111111011100000110) result =
  // 425201762259990540000000 (0101101000001010 00111011110101010000011111111001
  // 00111111110001010001101100000000)
  b0 = 2133063430;
  b1 = 3567587224;
  b2 = 232;
  a0 = 3202945542;
  a1 = 276436881;
  a2 = 23283;
  res0 = 1069882112;
  res1 = 1003816953;
  res2 = 23050;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 0);

  // #2
  // number =       9999999999999999999999             (001000011110
  // 00011001111000001100100110111010 10110010001111111111111111111111) number2
  // =  88888888888888888888888888 (010010011000011011110100
  // 01010010011110001110111011110100 01011000111000111000111000111000) result =
  // -88878888888888888888888889 (010010011000010011010110
  // 00111000100110000010010100111001 10100110101000111000111000111001)
  a0 = 2990538751;
  a1 = 434162106;
  a2 = 542;
  b0 = 1491308088;
  b1 = 1383657204;
  b2 = 4818676;
  res0 = 2795736633;
  res1 = 949495097;
  res2 = 4818134;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_ne(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 1);

  // printf("Meant:  ");
  // printf("10000000000000000000000000000000|00000000010010011000010011010110|00111000100110000010010100111001|10100110101000111000111000111001\n");
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  // #3
  // number =  151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // = 151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) result =
  // 0 (0000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000)
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 8191;
  b0 = 4294967295;
  b1 = 4294967295;
  b2 = 8191;
  res0 = 0;
  res1 = 0;
  res2 = 0;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 0);

  // #4
  // number =  151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // = 151115727451828646838272 (0000010000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000) result =
  // -1 (0000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001)
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 8191;
  b0 = 0;
  b1 = 0;
  b2 = 8192;
  res0 = 1;
  res1 = 0;
  res2 = 0;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_ne(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 1);

  // #5
  // number =  151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // =                        1 (0000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000001) result =
  // 151115727451828646838270 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111110)
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 8191;
  b0 = 1;
  b1 = 0;
  b2 = 0;
  res0 = 4294967294;
  res1 = 4294967295;
  res2 = 8191;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 0);

  // #6
  // number =  79228162514264337593543950335 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // = 79228162514264337593543950334 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111110) result =
  // 1 (00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001)
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 4294967295;
  b0 = 4294967294;
  b1 = 4294967295;
  b2 = 4294967295;
  res0 = 1;
  res1 = 0;
  res2 = 0;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 0);

  // #8
  // number =  151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // =                        0 (0000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000) result =
  // 151115727451828646838271 (0000001111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111)
  a0 = 4294967295;
  a1 = 4294967295;
  a2 = 8191;
  b0 = 0;
  b1 = 0;
  b2 = 0;
  res0 = 4294967295;
  res1 = 4294967295;
  res2 = 8191;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 0);

  // #7
  // number =                               1 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000001) number2
  // =  39614081257132168796771975168 (10000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000) result =
  // -39614081257132168796771975167 (01111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111)
  a0 = 1;
  a1 = 0;
  a2 = 0;
  b0 = 0;
  b1 = 0;
  b2 = 2147483648;
  res0 = 4294967295;
  res1 = 4294967295;
  res2 = 2147483647;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_ne(result.bits[3], zero);
  ck_assert_uint_eq(s21_getSign(result), 1);

  // printf("number1:  ");
  // s21_printDecimalBin(number);
  // printf("number2:  ");
  // s21_printDecimalBin(number2);
  // printf("result:   ");
  // s21_printDecimalBin(result);
  // printf("\n");
}
START_TEST(test_simple_arithmetic_subtraction_extended) {
  s21_expended number = ZERO_EXPENDED, number2 = ZERO_EXPENDED,
               result = ZERO_EXPENDED, check = ZERO_EXPENDED;

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 4;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);

  result = s21_simpleSubtractionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 10;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 5;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);

  result = s21_simpleSubtractionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // number = 2345678908765432123456789
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000000000000011111000010110111 10000010001010010011111010101010
  //    00011000010101110111110100010101)
  // number2 = 23456789076543214567899999999999
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000100101000
  //    00010000111110010010100000101000 00011110110000001100111100010110
  //    10011101010011111001011111111111)
  // result = 23456786730864305802467876543210
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000100101000
  //    00010000111101110011011101110000 10011100100101111001000001101100
  //    10000100111110000001101011101010)

  number.bits[0] = 408386837;
  number.bits[1] = 2183741098;
  number.bits[2] = 127159;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  number2.bits[0] = 2639239167;
  number2.bits[1] = 515952406;
  number2.bits[2] = 284764200;
  number2.bits[3] = 296;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 2230852330;
  check.bits[1] = 2627178604;
  check.bits[2] = 284637040;
  check.bits[3] = 296;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);

  result = s21_simpleSubtractionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // number2 = 12554203470773361527671578846256876507176182213740981125120
  //(1 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111110
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  // number = 7777777777777777777777777777777777777
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000101110110011111001000001101
  //    00011000000110111000110001101111 11100100010011000010101001111100
  //    01110001110001110001110001110001)
  // result =  12554203470773361527663801068479098729398404435963203347343
  //(1 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111010001001100000110111110000
  //    11100111111001000111001110010000 00011011101100111101010110000011
  //    10001110001110001110001110001111)

  number2.bits[0] = 0;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 4294967294;
  number2.bits[4] = 4294967295;
  number2.bits[5] = 4294967295;
  s21_setBitGlobalExp(&number2, mantissa_six, 1);
  number.bits[0] = 1908874353;
  number.bits[1] = 3830196860;
  number.bits[2] = 404458607;
  number.bits[3] = 98169357;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 0);
  check.bits[0] = 2386092943;
  check.bits[1] = 464770435;
  check.bits[2] = 3890508688;
  check.bits[3] = 4196797936;
  check.bits[4] = 4294967295;
  check.bits[5] = 4294967295;
  s21_setBitGlobalExp(&check, mantissa_six, 1);
  s21_setSignExp(&check, 1);

  result = s21_simpleSubtractionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // number = 2^192
  //(1 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  // number2 = 1
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  // result = 2^192 - 1
  //(0 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111
  //    11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)

  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  s21_setBitGlobalExp(&number, mantissa_six, 1);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  check.bits[0] = 4294967295;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  check.bits[3] = 4294967295;
  check.bits[4] = 4294967295;
  check.bits[5] = 4294967295;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);

  result = s21_simpleSubtractionExp(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  /*
  //number =
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000
  //   00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //number2 =
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000
  //   00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //result =
  //(0 00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000
  //   00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)


  number.bits[0]=;
  number.bits[1]=;
  number.bits[2]=;
  number.bits[3]=;
  number.bits[4]=;
  number.bits[5]=;
  s21_setBitGlobalExp(&number,mantissa_six,);
  number2.bits[0]=;
  number2.bits[1]=;
  number2.bits[2]=;
  number2.bits[3]=;
  number2.bits[4]=;
  number2.bits[5]=;
  s21_setBitGlobalExp(&number2,mantissa_six,);
  check.bits[0]=;
  check.bits[1]=;
  check.bits[2]=;
  check.bits[3]=;
  check.bits[4]=;
  check.bits[5]=;
  s21_setBitGlobalExp(&check,mantissa_six,);
  s21_setSignExp(&check,);

  result=s21_simpleSubtractionExp(number,number2);
  ck_assert_uint_eq(result.bits[0],check.bits[0]);
  ck_assert_uint_eq(result.bits[1],check.bits[1]);
  ck_assert_uint_eq(result.bits[2],check.bits[2]);
  ck_assert_uint_eq(result.bits[3],check.bits[3]);
  ck_assert_uint_eq(result.bits[4],check.bits[4]);
  ck_assert_uint_eq(result.bits[5],check.bits[5]);
  ck_assert_uint_eq(result.bits[6],check.bits[6]);
*/
}

START_TEST(test_simple_arithmetic_multiplication_1) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              result = ZERO_DECIMAL;
  unsigned int a = 0, b = 0, res = 0, zero = 0;

  // #5
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 27;
  b = 27;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a * b;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #1
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a * b;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #8
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 3;
  b = 2;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a * b;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #2
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 445;
  b = 259;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a * b;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #3
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 155;
  b = 0;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a * b;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #6
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 0;
  b = 4444;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = a * b;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #4
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 4294967295;
  b = 1;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = b * a;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);

  // #7
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&result);
  a = 2;
  b = 2147483647;
  number.bits[0] = a;
  number2.bits[0] = b;
  res = b * a;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res);
  ck_assert_uint_eq(result.bits[1], zero);
  ck_assert_uint_eq(result.bits[2], zero);
  ck_assert_uint_eq(result.bits[3], zero);
}
START_TEST(test_simple_arithmetic_multiplication_2) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              result = ZERO_DECIMAL;
  unsigned int a0 = 0, a1 = 0, a2 = 0, b0 = 0, b1 = 0, b2 = 0, res0 = 0,
               res1 = 0, res2 = 0, zero = 0;

  // #1
  // number =            4294967295555 (001111100111
  // 11111111111111111111111001000011) number2 =              4294967295
  // (11111111111111111111111111111111) result =  18446744067503323873725
  // (001111100111 11111111111111111111101001011011
  // 00000000000000000000000110111101)
  a0 = 4294966851;
  a1 = 999;
  a2 = 0;
  b0 = 4294967295;
  b1 = 0;
  b2 = 0;
  res0 = 445;
  res1 = 4294965851;
  res2 = 999;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // printf("Meant:  ");
  // printf("00000000000000000000000000000000|00000000000000000000001111100111|11111111111111111111101001011011|00000000000000000000000110111101\n");
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  // #2
  // number =                8589934147 (1 11111111111111111111111001000011)
  // number2 =           55708296118771 (11001010101010
  // 10011001001100111000000111110011) result =  478530595101818580573337
  // (0110010101010101 00110010000011101111000101011001
  // 10110001011101110001110010011001)
  a0 = 4294966851;
  a1 = 1;
  a2 = 0;
  b0 = 2570289651;
  b1 = 12970;
  b2 = 0;
  res0 = 2977373337;
  res1 = 839840089;
  res2 = 25941;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // #3
  // number =               1 (1) number2 = 55708296118771 (11001010101010
  // 10011001001100111000000111110011) result =  55708296118771 (11001010101010
  // 10011001001100111000000111110011)
  a0 = 1;
  a1 = 0;
  a2 = 0;
  b0 = 2570289651;
  b1 = 12970;
  b2 = 0;
  res0 = b0;
  res1 = b1;
  res2 = b2;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // #4
  // number =               0 (0) number2 = 55708296118771 (11001010101010
  // 10011001001100111000000111110011) result =               0 (0)
  a0 = 0;
  a1 = 0;
  a2 = 0;
  b0 = 2570289651;
  b1 = 12970;
  b2 = 0;
  res0 = 0;
  res1 = 0;
  res2 = 0;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // #5
  // number =  15845632502852867518708790067 (00110011001100110011001100110011
  // 00110011001100110011001100110011 00110011001100110011001100110011) number2
  // =                             5 (101) result =
  // 79228162514264337593543950335 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111)
  a0 = 858993459;
  a1 = 858993459;  // 10 10000000000000000000000000000000
                   // 00000000000000000000000000000000
                   // 00000000000000000000000000000000
  a2 = 858993459;  //   10100000000000000000000000000000
                   //   00000000000000000000000000000000
                   //   00000000000000000000000000000000
  b0 = 5;
  b1 = 0;
  b2 = 0;
  res0 = 4294967295;
  res1 = 4294967295;
  res2 = 4294967295;
  number.bits[0] = a0;
  number.bits[1] = a1;
  number.bits[2] = a2;
  number2.bits[0] = b0;
  number2.bits[1] = b1;
  number2.bits[2] = b2;
  result = s21_simpleDecMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], res0);
  ck_assert_uint_eq(result.bits[1], res1);
  ck_assert_uint_eq(result.bits[2], res2);
  ck_assert_uint_eq(result.bits[3], zero);

  // printf("number1:  ");
  // s21_printDecimalBin(number);
  // printf("number2:  ");
  // s21_printDecimalBin(number2);
  // printf("result:   ");
  // s21_printDecimalBin(result);
  // printf("\n");

  s21_decimal check = ZERO_DECIMAL;
  s21_expended check_big = ZERO_EXPENDED, result_big = ZERO_EXPENDED;

  // number =  79228162514264337593543950335
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) number2 =   79228162514264337593543950335
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) result =   ...
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001) result_big =
  // 6277101735386680763835789423049210091073826769276946612225 (0
  // 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111110
  //    00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  number.bits[3] = 0;
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 4294967295;
  number2.bits[3] = 0;
  check.bits[0] = 1;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check_big.bits[0] = 1;
  check_big.bits[1] = 0;
  check_big.bits[2] = 0;
  check_big.bits[3] = 4294967294;
  check_big.bits[4] = 4294967295;
  check_big.bits[5] = 4294967295;
  s21_setBitGlobalExp(&check_big, mantissa_six, 0);

  result = s21_simpleDecMultiplication(number, number2);
  result_big = s21_simpleDecMultiplicationExpOut(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  ck_assert_uint_eq(result_big.bits[0], check_big.bits[0]);
  ck_assert_uint_eq(result_big.bits[1], check_big.bits[1]);
  ck_assert_uint_eq(result_big.bits[2], check_big.bits[2]);
  ck_assert_uint_eq(result_big.bits[3], check_big.bits[3]);
  ck_assert_uint_eq(result_big.bits[4], check_big.bits[4]);
  ck_assert_uint_eq(result_big.bits[5], check_big.bits[5]);
  ck_assert_uint_eq(result_big.bits[6], check_big.bits[6]);

  /*
  //number =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //number2 =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //result =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000) number.bits[0]=; number.bits[1]=;
  number.bits[2]=;
  number.bits[3]=0;
  number2.bits[0]=;
  number2.bits[1]=;
  number2.bits[2]=;
  number2.bits[3]=0;
  check.bits[0]=;
  check.bits[1]=;
  check.bits[2]=;
  check.bits[3]=0;

  result=s21_simpleDecMultiplication(number,number2);
  ck_assert_uint_eq(result.bits[0],check.bits[0]);
  ck_assert_uint_eq(result.bits[1],check.bits[1]);
  ck_assert_uint_eq(result.bits[2],check.bits[2]);
  ck_assert_uint_eq(result.bits[3],check.bits[3]);
*/
}
START_TEST(test_simple_arithmetic_multiplication_int) {
  s21_decimal number = ZERO_DECIMAL, result = ZERO_DECIMAL,
              check = ZERO_DECIMAL;
  int number2 = 0;

  // number = 18446744073709551615
  //(00000000000000000000000000000000 11111111111111111111111111111111
  // 11111111111111111111111111111111) number2 = 0 result =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000)
  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number2 = 0;
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleIntMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // number = 12297829382473034410
  //(00000000000000000000000000000000 10101010101010101010101010101010
  // 10101010101010101010101010101010) number2 = 10 result =
  // 122978293824730344100 (00000000000000000000000000000110
  // 10101010101010101010101010101010 10101010101010101010101010100100)
  number.bits[0] = 2863311530;
  number.bits[1] = 2863311530;
  number.bits[2] = 0;
  number.bits[3] = 0;
  number2 = 10;
  check.bits[0] = 2863311524;
  check.bits[1] = 2863311530;
  check.bits[2] = 6;
  check.bits[3] = 0;

  result = s21_simpleIntMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // number =  79228162514264337593543950335
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) number2 = 10 result = cut of
  // 792281625142643375935439503350 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111110110)
  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  number.bits[3] = 0;
  number2 = 10;
  check.bits[0] = 4294967286;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  check.bits[3] = 0;

  result = s21_simpleIntMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // number =  7922816251426433759354395033
  //(00011001100110011001100110011001 10011001100110011001100110011001
  // 10011001100110011001100110011001) number2 = 10 result =
  // 79228162514264337593543950330 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111010)
  number.bits[0] = 2576980377;
  number.bits[1] = 2576980377;
  number.bits[2] = 429496729;
  number.bits[3] = 0;
  number2 = 10;
  check.bits[0] = 4294967290;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  check.bits[3] = 0;

  result = s21_simpleIntMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");
  /*
   //number =
   //(00000000000000000000000000000000 00000000000000000000000000000000
   00000000000000000000000000000000)
   //number2 =
   //result =
   //(00000000000000000000000000000000 00000000000000000000000000000000
   00000000000000000000000000000000) number.bits[0]=; number.bits[1]=;
   number.bits[2]=;
   number.bits[3]=0;
   number2=;
   check.bits[0]=;
   check.bits[1]=;
   check.bits[2]=;
   check.bits[3]=0;

   result=s21_simpleIntMultiplication(number,number2);
   ck_assert_uint_eq(result.bits[0],check.bits[0]);
   ck_assert_uint_eq(result.bits[1],check.bits[1]);
   ck_assert_uint_eq(result.bits[2],check.bits[2]);
   ck_assert_uint_eq(result.bits[3],check.bits[3]);
 */
}

START_TEST(test_simple_arithmetic_multiplication_expended) {
  s21_expended number = ZERO_EXPENDED, number2 = ZERO_EXPENDED,
               result = ZERO_EXPENDED, check = ZERO_EXPENDED;
  int number3 = 0;

  // number =  79228162514264337593543950335
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number2
  // =
  // 79228162514264337593543950335 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) result =
  // 6277101735386680763835789423049210091073826769276946612225
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111110) (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000001)
  s21_clearExpended(&number2);
  s21_clearExpended(&number);
  s21_clearExpended(&result);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  number.bits[6] = 0;

  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 4294967295;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  number2.bits[6] = 0;

  check.bits[0] = 1;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 4294967294;
  check.bits[4] = 4294967295;
  check.bits[5] = 4294967295;
  check.bits[6] = 0;

  result = s21_simpleExpMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);

  // printf("New_Result_1:\n");
  // s21_printExpendedBin(result);

  // number =  79228162514264337593543950335
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) number3
  // =
  // 10 (00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000001010) result =
  // 792281625142643375935439503350 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000001001)
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111110110)
  s21_clearExpended(&number2);
  s21_clearExpended(&number);
  s21_clearExpended(&result);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  number.bits[3] = 0;
  number.bits[4] = 0;
  number.bits[5] = 0;
  number.bits[6] = 0;

  number3 = 10;

  check.bits[0] = 4294967286;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  check.bits[3] = 9;
  check.bits[4] = 0;
  check.bits[5] = 0;
  check.bits[6] = 0;

  result = s21_simpleExpIntMultiplication(number, number3);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(result.bits[6], check.bits[6]);
}
START_TEST(test_simple_arithmetic_division_expended) {
  s21_expended dividen = ZERO_EXPENDED, divider = ZERO_EXPENDED,
               result = ZERO_EXPENDED, remainder = ZERO_EXPENDED,
               result_check = ZERO_EXPENDED, remainder_check = ZERO_DECIMAL;

  // dividen =  340282366920938463463374607431768211455
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111111) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) divider
  // =
  // 4294967295 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111111) result =   79228162532711081671548469249
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001) (00000000000000000000000000000001
  // 00000000000000000000000000000001 00000000000000000000000000000001)
  // remainder
  // =   0 (00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  s21_clearExpended(&divider);
  s21_clearExpended(&dividen);
  s21_clearExpended(&result);
  s21_clearExpended(&remainder);
  s21_clearExpended(&result_check);
  s21_clearExpended(&remainder_check);

  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 4294967295;
  dividen.bits[4] = 0;
  dividen.bits[5] = 0;
  dividen.bits[6] = 0;

  divider.bits[0] = 4294967295;
  divider.bits[1] = 0;
  divider.bits[2] = 0;
  divider.bits[3] = 0;
  divider.bits[4] = 0;
  divider.bits[5] = 0;
  divider.bits[6] = 0;

  result_check.bits[0] = 1;
  result_check.bits[1] = 1;
  result_check.bits[2] = 1;
  result_check.bits[3] = 1;
  result_check.bits[4] = 0;
  result_check.bits[5] = 0;
  result_check.bits[6] = 0;

  remainder_check.bits[0] = 0;
  remainder_check.bits[1] = 0;
  remainder_check.bits[2] = 0;
  remainder_check.bits[3] = 0;
  remainder_check.bits[4] = 0;
  remainder_check.bits[5] = 0;
  remainder_check.bits[6] = 0;

  result = s21_simpleExpIntegerDivisionRemainder(dividen, divider, &remainder);
  ck_assert_uint_eq(remainder.bits[0], remainder_check.bits[0]);
  ck_assert_uint_eq(remainder.bits[1], remainder_check.bits[1]);
  ck_assert_uint_eq(remainder.bits[2], remainder_check.bits[2]);
  ck_assert_uint_eq(remainder.bits[3], remainder_check.bits[3]);
  ck_assert_uint_eq(remainder.bits[4], remainder_check.bits[4]);
  ck_assert_uint_eq(remainder.bits[5], remainder_check.bits[5]);
  ck_assert_uint_eq(remainder.bits[6], remainder_check.bits[6]);
  ck_assert_uint_eq(result.bits[0], result_check.bits[0]);
  ck_assert_uint_eq(result.bits[1], result_check.bits[1]);
  ck_assert_uint_eq(result.bits[2], result_check.bits[2]);
  ck_assert_uint_eq(result.bits[3], result_check.bits[3]);
  ck_assert_uint_eq(result.bits[4], result_check.bits[4]);
  ck_assert_uint_eq(result.bits[5], result_check.bits[5]);
  ck_assert_uint_eq(result.bits[6], result_check.bits[6]);

  // printf("New_Result_2:\n");
  // s21_printExpendedBin(result);
  // printf("\n");

  // dividen =  340282366920938463463374607431768211455
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111111) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) divider
  // =
  // 0 (00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000) result =
  // 79228162532711081671548469249 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000001)
  //(00000000000000000000000000000001 00000000000000000000000000000001
  // 00000000000000000000000000000001) remainder =   0
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  s21_clearExpended(&divider);
  s21_clearExpended(&dividen);
  s21_clearExpended(&result);
  s21_clearExpended(&remainder);
  s21_clearExpended(&result_check);
  s21_clearExpended(&remainder_check);

  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 4294967295;
  dividen.bits[4] = 0;
  dividen.bits[5] = 0;
  dividen.bits[6] = 0;

  divider.bits[0] = 0;
  divider.bits[1] = 0;
  divider.bits[2] = 0;
  divider.bits[3] = 0;
  divider.bits[4] = 0;
  divider.bits[5] = 0;
  divider.bits[6] = 0;

  result_check.bits[0] = 0;
  result_check.bits[1] = 0;
  result_check.bits[2] = 0;
  result_check.bits[3] = 0;
  result_check.bits[4] = 0;
  result_check.bits[5] = 0;
  result_check.bits[6] = 0;

  remainder_check.bits[0] = 0;
  remainder_check.bits[1] = 0;
  remainder_check.bits[2] = 0;
  remainder_check.bits[3] = 0;
  remainder_check.bits[4] = 0;
  remainder_check.bits[5] = 0;
  remainder_check.bits[6] = 0;

  result = s21_simpleExpIntegerDivisionRemainder(dividen, divider, &remainder);
  ck_assert_uint_eq(remainder.bits[0], remainder_check.bits[0]);
  ck_assert_uint_eq(remainder.bits[1], remainder_check.bits[1]);
  ck_assert_uint_eq(remainder.bits[2], remainder_check.bits[2]);
  ck_assert_uint_eq(remainder.bits[3], remainder_check.bits[3]);
  ck_assert_uint_eq(remainder.bits[4], remainder_check.bits[4]);
  ck_assert_uint_eq(remainder.bits[5], remainder_check.bits[5]);
  ck_assert_uint_eq(remainder.bits[6], remainder_check.bits[6]);
  ck_assert_uint_eq(result.bits[0], result_check.bits[0]);
  ck_assert_uint_eq(result.bits[1], result_check.bits[1]);
  ck_assert_uint_eq(result.bits[2], result_check.bits[2]);
  ck_assert_uint_eq(result.bits[3], result_check.bits[3]);
  ck_assert_uint_eq(result.bits[4], result_check.bits[4]);
  ck_assert_uint_eq(result.bits[5], result_check.bits[5]);
  ck_assert_uint_eq(result.bits[6], result_check.bits[6]);

  // dividen =  340282366920938463463374607431768211455
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111111) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) divider
  // =
  // 4294967294 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111110) result =   79228162551157825758142922760
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001) (00000000000000000000000000000010
  // 00000000000000000000000000000100 00000000000000000000000000001000)
  // remainder
  // =   15 (00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  s21_clearExpended(&divider);
  s21_clearExpended(&dividen);
  s21_clearExpended(&result);
  s21_clearExpended(&remainder);
  s21_clearExpended(&result_check);
  s21_clearExpended(&remainder_check);

  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 4294967295;
  dividen.bits[4] = 0;
  dividen.bits[5] = 0;
  dividen.bits[6] = 0;

  divider.bits[0] = 4294967294;
  divider.bits[1] = 0;
  divider.bits[2] = 0;
  divider.bits[3] = 0;
  divider.bits[4] = 0;
  divider.bits[5] = 0;
  divider.bits[6] = 0;

  result_check.bits[0] = 8;
  result_check.bits[1] = 4;
  result_check.bits[2] = 2;
  result_check.bits[3] = 1;
  result_check.bits[4] = 0;
  result_check.bits[5] = 0;
  result_check.bits[6] = 0;

  remainder_check.bits[0] = 15;
  remainder_check.bits[1] = 0;
  remainder_check.bits[2] = 0;
  remainder_check.bits[3] = 0;
  remainder_check.bits[4] = 0;
  remainder_check.bits[5] = 0;
  remainder_check.bits[6] = 0;

  result = s21_simpleExpIntegerDivisionRemainder(dividen, divider, &remainder);
  ck_assert_uint_eq(remainder.bits[0], remainder_check.bits[0]);
  ck_assert_uint_eq(remainder.bits[1], remainder_check.bits[1]);
  ck_assert_uint_eq(remainder.bits[2], remainder_check.bits[2]);
  ck_assert_uint_eq(remainder.bits[3], remainder_check.bits[3]);
  ck_assert_uint_eq(remainder.bits[4], remainder_check.bits[4]);
  ck_assert_uint_eq(remainder.bits[5], remainder_check.bits[5]);
  ck_assert_uint_eq(remainder.bits[6], remainder_check.bits[6]);
  ck_assert_uint_eq(result.bits[0], result_check.bits[0]);
  ck_assert_uint_eq(result.bits[1], result_check.bits[1]);
  ck_assert_uint_eq(result.bits[2], result_check.bits[2]);
  ck_assert_uint_eq(result.bits[3], result_check.bits[3]);
  ck_assert_uint_eq(result.bits[4], result_check.bits[4]);
  ck_assert_uint_eq(result.bits[5], result_check.bits[5]);
  ck_assert_uint_eq(result.bits[6], result_check.bits[6]);

  // dividen =  340282366920938463463374607431768211455
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111111) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) divider
  // =
  // 4294967292 (00000000000000000000000000000000
  // 00000000000000000000000000000000 00000000000000000000000000000000)
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111100) result =   79228162588051313957101633600
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001) (00000000000000000000000000000100
  // 00000000000000000000000000010000 00000000000000000000000001000000)

  s21_clearExpended(&divider);
  s21_clearExpended(&dividen);
  s21_clearExpended(&result);
  s21_clearExpended(&result_check);

  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 4294967295;
  dividen.bits[4] = 0;
  dividen.bits[5] = 0;
  dividen.bits[6] = 0;

  divider.bits[0] = 4294967292;
  divider.bits[1] = 0;
  divider.bits[2] = 0;
  divider.bits[3] = 0;
  divider.bits[4] = 0;
  divider.bits[5] = 0;
  divider.bits[6] = 0;

  result_check.bits[0] = 64;
  result_check.bits[1] = 16;
  result_check.bits[2] = 4;
  result_check.bits[3] = 1;
  result_check.bits[4] = 0;
  result_check.bits[5] = 0;
  result_check.bits[6] = 0;

  result = s21_simpleExpIntegerDivision(dividen, divider);
  ck_assert_uint_eq(result.bits[0], result_check.bits[0]);
  ck_assert_uint_eq(result.bits[1], result_check.bits[1]);
  ck_assert_uint_eq(result.bits[2], result_check.bits[2]);
  ck_assert_uint_eq(result.bits[3], result_check.bits[3]);
  ck_assert_uint_eq(result.bits[4], result_check.bits[4]);
  ck_assert_uint_eq(result.bits[5], result_check.bits[5]);
  ck_assert_uint_eq(result.bits[6], result_check.bits[6]);

  // dividen =  340282366920938463463374607431768211455
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 11111111111111111111111111111111) (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111) divider
  // =
  // 10 result =   34028236692093846346337460743176821145
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00011001100110011001100110011001) (10011001100110011001100110011001
  // 10011001100110011001100110011001 10011001100110011001100110011001)

  int divider_int = 0;
  s21_clearExpended(&dividen);
  s21_clearExpended(&result);
  s21_clearExpended(&result_check);

  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 4294967295;
  dividen.bits[4] = 0;
  dividen.bits[5] = 0;
  dividen.bits[6] = 0;

  divider_int = 10;

  result_check.bits[0] = 2576980377;
  result_check.bits[1] = 2576980377;
  result_check.bits[2] = 2576980377;
  result_check.bits[3] = 429496729;
  result_check.bits[4] = 0;
  result_check.bits[5] = 0;
  result_check.bits[6] = 0;

  result = s21_simpleIntIntegerDivisionExp(dividen, divider_int);
  ck_assert_uint_eq(result.bits[0], result_check.bits[0]);
  ck_assert_uint_eq(result.bits[1], result_check.bits[1]);
  ck_assert_uint_eq(result.bits[2], result_check.bits[2]);
  ck_assert_uint_eq(result.bits[3], result_check.bits[3]);
  ck_assert_uint_eq(result.bits[4], result_check.bits[4]);
  ck_assert_uint_eq(result.bits[5], result_check.bits[5]);
  ck_assert_uint_eq(result.bits[6], result_check.bits[6]);
}

START_TEST(test_simple_arithmetic_division) {
  s21_decimal dividen = ZERO_DECIMAL, devider = ZERO_DECIMAL,
              result = ZERO_DECIMAL, check = ZERO_DECIMAL,
              remainder = ZERO_DECIMAL, check_remainder = ZERO_DECIMAL;

  // dividen =  9
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000001001) devider =  4
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000100) result =   2
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000010) remainder =   1
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000001)
  dividen.bits[0] = 9;
  dividen.bits[1] = 0;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  devider.bits[0] = 4;
  devider.bits[1] = 0;
  devider.bits[2] = 0;
  devider.bits[3] = 0;
  check.bits[0] = 2;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;

  check_remainder.bits[0] = 1;
  check_remainder.bits[1] = 0;
  check_remainder.bits[2] = 0;
  check_remainder.bits[3] = 0;
  result = s21_simpleDecIntegerDivisionRemainder(dividen, devider, &remainder);
  ck_assert_uint_eq(remainder.bits[0], check_remainder.bits[0]);
  ck_assert_uint_eq(remainder.bits[1], check_remainder.bits[1]);
  ck_assert_uint_eq(remainder.bits[2], check_remainder.bits[2]);
  ck_assert_uint_eq(remainder.bits[3], check_remainder.bits[3]);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // dividen =  18446744069414584320
  //(00000000000000000000000000000000 11111111111111111111111111111111
  // 00000000000000000000000000000000) devider =   534
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000001000010110) result =  34544464549465513
  //(00000000000000000000000000000000 00000000011110101011101000000001
  // 11101010011011010100110110101001)
  dividen.bits[0] = 0;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  devider.bits[0] = 534;
  devider.bits[1] = 0;
  devider.bits[2] = 0;
  devider.bits[3] = 0;
  check.bits[0] = 3933031849;
  check.bits[1] = 8043009;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleDecIntegerDivision(dividen, devider);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  // dividen =  18446744069414584320
  //(00000000000000000000000000000000 11111111111111111111111111111111
  // 00000000000000000000000000000000) devider =   0
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000) result =
  // (00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000)
  dividen.bits[0] = 0;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  devider.bits[0] = 0;
  devider.bits[1] = 0;
  devider.bits[2] = 0;
  devider.bits[3] = 0;
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleDecIntegerDivision(dividen, devider);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_ne(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getErrorbits(result), 3);

  // dividen =  79228162514264337593543950335
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) devider =   10
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000001010) result =   7922816251426433759354395033
  //(00011001100110011001100110011001 10011001100110011001100110011001
  // 10011001100110011001100110011001)
  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 0;
  devider.bits[0] = 10;
  devider.bits[1] = 0;
  devider.bits[2] = 0;
  devider.bits[3] = 0;
  check.bits[0] = 2576980377;
  check.bits[1] = 2576980377;
  check.bits[2] = 429496729;
  check.bits[3] = 0;

  result = s21_simpleDecIntegerDivision(dividen, devider);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // dividen =  06175
  //(00000000000000001111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) devider =   100000
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000011000011010100000) result =   12089258196146291747
  //(00000000000000000000000000000000 10100111110001011010110001000111
  // 00011011010001111000010000100011)
  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 65535;
  dividen.bits[3] = 0;
  devider.bits[0] = 100000;
  devider.bits[1] = 0;
  devider.bits[2] = 0;
  devider.bits[3] = 0;
  check.bits[0] = 457671715;
  check.bits[1] = 2814749767;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleDecIntegerDivision(dividen, devider);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  int deviderr = 0;

  // dividen =  12089258196146291747
  //(00000000000000000000000000000000 10100111110001011010110001000111
  // 00011011010001111000010000100011) devider =   100000
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000011000011010100000) result =   120892581961462
  //(00000000000000000000000000000000 00000000000000000110110111110011
  // 01111111011001110101111011110110) remainder =   91747
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000010110011001100011)
  dividen.bits[0] = 457671715;
  dividen.bits[1] = 2814749767;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  devider.bits[0] = 100000;
  devider.bits[1] = 0;
  devider.bits[2] = 0;
  devider.bits[3] = 0;
  check.bits[0] = 2137480950;
  check.bits[1] = 28147;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check_remainder.bits[0] = 91747;
  check_remainder.bits[1] = 0;
  check_remainder.bits[2] = 0;
  check_remainder.bits[3] = 0;

  result = s21_simpleDecIntegerDivisionRemainder(dividen, devider, &remainder);
  ck_assert_uint_eq(remainder.bits[0], check_remainder.bits[0]);
  ck_assert_uint_eq(remainder.bits[1], check_remainder.bits[1]);
  ck_assert_uint_eq(remainder.bits[2], check_remainder.bits[2]);
  ck_assert_uint_eq(remainder.bits[3], check_remainder.bits[3]);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // dividen =  12089258196146291747
  //(00000000000000000000000000000000 10100111110001011010110001000111
  // 00011011010001111000010000100011) devider = 10000001 result = 1208925698722
  //(00000000000000000000000000000000 00000000000000000000000100011001
  // 01111001100101100011101010100010)
  dividen.bits[0] = 457671715;
  dividen.bits[1] = 2814749767;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  deviderr = 10000001;
  check.bits[0] = 2039888546;
  check.bits[1] = 281;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleIntIntegerDivision(dividen, deviderr);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  // dividen = 1208925698722
  //(00000000000000000000000000000000 00000000000000000000000100011001
  // 01111001100101100011101010100010) devider =   10000000 result =   120892
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000011101100000111100)
  dividen.bits[0] = 2039888546;
  dividen.bits[1] = 281;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  deviderr = 10000000;
  check.bits[0] = 120892;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleIntIntegerDivision(dividen, deviderr);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // dividen = 120892
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000011101100000111100) devider =   10000000 result =   0
  //(00000000000000000000000000000000 00000000000000000000000000000000
  // 00000000000000000000000000000000)
  dividen.bits[0] = 120892;
  dividen.bits[1] = 0;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  deviderr = 10000000;
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleIntIntegerDivision(dividen, deviderr);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  // dividen =  79228162514264337593543950335
  //(11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111) devider =   1 result =
  // 79228162514264337593543950335 (11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111)
  dividen.bits[0] = 4294967295;
  dividen.bits[1] = 4294967295;
  dividen.bits[2] = 4294967295;
  dividen.bits[3] = 0;
  deviderr = 1;
  check.bits[0] = 4294967295;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  check.bits[3] = 0;

  result = s21_simpleIntIntegerDivision(dividen, deviderr);

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  dividen.bits[0] = 2;
  dividen.bits[1] = 0;
  dividen.bits[2] = 0;
  dividen.bits[3] = 0;
  deviderr = 2;
  check.bits[0] = 1;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;

  result = s21_simpleIntIntegerDivision(dividen, deviderr);

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);

  /*
  //4294967295 ==  11111111111111111111111111111111


  //dividen =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //devider =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //result =
  //(00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000) dividen.bits[0]=; dividen.bits[1]=;
  dividen.bits[2]=;
  dividen.bits[3]=0;
  devider.bits[0]=;
  devider.bits[1]=;
  devider.bits[2]=;
  devider.bits[3]=0;
  check.bits[0]=;
  check.bits[1]=;
  check.bits[2]=;
  check.bits[3]=0;

  result=s21_simpleDecIntegerDivision(dividen,devider);
  ck_assert_uint_eq(result.bits[0],check.bits[0]);
  ck_assert_uint_eq(result.bits[1],check.bits[1]);
  ck_assert_uint_eq(result.bits[2],check.bits[2]);
  ck_assert_uint_eq(result.bits[3],check.bits[3]);

  check_remainder.bits[0]=;
  check_remainder.bits[1]=;
  check_remainder.bits[2]=;
  check_remainder.bits[3]=0;
  result=s21_simpleDecIntegerDivisionRemainder(dividen,devider,&remainder);
  ck_assert_uint_eq(remainder.bits[0],check_remainder.bits[0]);
  ck_assert_uint_eq(remainder.bits[1],check_remainder.bits[1]);
  ck_assert_uint_eq(remainder.bits[2],check_remainder.bits[2]);
  ck_assert_uint_eq(remainder.bits[3],check_remainder.bits[3]);

*/
}

// elevator  arithmetic  (test 25-31/-)
START_TEST(test_scaling_and_co_1) {
  printf(
      "TESTING: "
      "arithmetic/"
      "s21_scaling.c..........................................................."
      "......\n");
  s21_decimal number = ZERO_DECIMAL;

  // number 54665423445665674
  //(00000000000000000000000000000000 00000000110000100011010111101001
  // 10111001111110011010011110001010)
  s21_clearDecimal(&number);
  number.bits[0] = 3120146314;
  number.bits[1] = 12727785;
  ck_assert_uint_eq(s21_rankOfNumber(number), 17);

  s21_clearDecimal(&number);
  number.bits[0] = 1;
  number.bits[1] = 0;
  ck_assert_uint_eq(s21_rankOfNumber(number), 1);

  s21_clearDecimal(&number);
  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  ck_assert_uint_eq(s21_rankOfNumber(number), 29);

  s21_clearDecimal(&number);
  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  ck_assert_uint_eq(s21_rankOfNumber(number), 29);

  s21_clearDecimal(&number);
  number.bits[0] = 0;
  number.bits[1] = 0;
  ck_assert_uint_eq(s21_rankOfNumber(number), 0);
}
START_TEST(test_scaling_and_co_2) {
  s21_decimal number = ZERO_DECIMAL, result = ZERO_DECIMAL,
              check = ZERO_DECIMAL;
  int delta = 0;

  // number 18446744073709551615             -- 15
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check 1844674407370955161500000         -- 20
  //  (00000000000000011000011010011111 11111111111111111111111111111111
  //  11111111111111100111100101100000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 15);
  check.bits[0] = 4294867296;
  check.bits[1] = 4294967295;
  check.bits[2] = 99999;
  s21_setSign(&check, 1);
  s21_setScale(&check, 20);
  delta = 5;

  result = s21_simpleSingleScaleAdd(number, delta);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  // number 18446744073709551615             -- 15
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check  184467440737095                  -- 10
  //  (00000000000000000000000000000000 00000000000000001010011111000101
  //  10101100010001110001101101000111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 15);
  check.bits[0] = 2890341191;
  check.bits[1] = 42949;
  check.bits[2] = 0;
  s21_setSign(&check, 0);
  s21_setScale(&check, 10);
  delta = -5;

  result = s21_simpleSingleScaleAdd(number, delta);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));

  // number 18446744073709551615             -- 15
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check  18446744073709551615             -- 15
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 15);
  check.bits[0] = 4294967295;
  check.bits[1] = 4294967295;
  check.bits[2] = 0;
  s21_setSign(&check, 0);
  s21_setScale(&check, 15);
  delta = 0;

  result = s21_simpleSingleScaleAdd(number, delta);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));

  // number   7922816251426433759354395033             --
  //  (00011001100110011001100110011001 10011001100110011001100110011001
  //  10011001100110011001100110011001)
  // check   79228162514264337593543950330            --
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111010)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 2576980377;
  number.bits[1] = 2576980377;
  number.bits[2] = 429496729;
  s21_setSign(&number, 1);
  s21_setScale(&number, 27);
  check.bits[0] = 4294967290;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  s21_setSign(&check, 1);
  s21_setScale(&check, 28);
  delta = 1;

  result = s21_simpleSingleScaleAdd(number, delta);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));

  // number   10             -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000001010)
  // check   1000000000000000000000            -- 25
  //  (00000000000000000000000000110110 00110101110010011010110111000101
  //  11011110101000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 10;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 3735027712;
  check.bits[1] = 902409669;
  check.bits[2] = 54;
  s21_setSign(&check, 1);
  s21_setScale(&check, 25);
  delta = 20;

  result = s21_simpleSingleScaleAdd(number, delta);

  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));

  // number   5             --
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check    50000000000000000000000000           --  25
  //  (00000000001010010101101111101001 01101110011001000000011001101001
  //  01110010000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 1912602624;
  check.bits[1] = 1852049001;
  check.bits[2] = 2710505;
  s21_setSign(&check, 1);
  s21_setScale(&check, 25);
  delta = 25;

  result = s21_simpleSingleScale(number, delta);

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(result);
  // printf("\n");

  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));

  // number   5             --
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check    50000000000000000000000000           --  25
  //  (00000000001010010101101111101001 01101110011001000000011001101001
  //  01110010000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&result);
  s21_clearDecimal(&check);

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 5;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 5);
  delta = -5;

  result = s21_simpleSingleScale(number, delta);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(s21_getScale(result), s21_getScale(check));
  ck_assert_uint_eq(s21_getErrorbits(result), 1);

  /*
    //11111111111111111111111111111111 == 4294967295
    79228162514264337593543950335

    //number                --
    // (00000000000000000000000000000000 00000000000000000000000000000000
   00000000000000000000000000000000)
    //check               --
    // (00000000000000000000000000000000 00000000000000000000000000000000
   00000000000000000000000000000000) s21_clearDecimal(&number);
    s21_clearDecimal(&result);
    s21_clearDecimal(&check);

    number.bits[0]=;
    number.bits[1]=;
    number.bits[2]=;
    s21_setSign(&number,);
    s21_setScale(&number,);
    check.bits[0]=;
    check.bits[1]=;
    check.bits[2]=;
    s21_setSign(&check,);
    s21_setScale(&check,);
    delta=;

   result=s21_simpleSingleScaleAdd(number,delta);
    ck_assert_uint_eq(result.bits[0],check.bits[0]);
    ck_assert_uint_eq(result.bits[1],check.bits[1]);
    ck_assert_uint_eq(result.bits[2],check.bits[2]);
    ck_assert_uint_eq(result.bits[3],check.bits[3]);
    ck_assert_uint_eq(s21_getScale(result),s21_getScale(check));

    //printf("Meant:  ");
    //s21_printDecimalBin(check);
    //printf("Result: ");
    //s21_printDecimalBin(result);
    //printf("\n");
  */
}
START_TEST(test_scaling_and_co_3) {
  s21_decimal number = ZERO_DECIMAL, check = ZERO_DECIMAL;
  int delta = 0, scale = 0, delta_check = 0;

  // number      5          -- 2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     5000000          -- 8
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 2);
  check.bits[0] = 5000000;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 8);
  scale = 6;
  delta_check = 0;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    18446744073709551615            -- 10
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check       18446744073709551615       -- 10
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  check.bits[0] = 4294967295;
  check.bits[1] = 4294967295;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 10);
  scale = 0;
  delta_check = 0;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    79228162514264337593543950            -- 5
  //  (00000000010000011000100100110111 01001011110001101010011111101111
  //  10011101101100100010110100001110)
  // check     79228162514264337593543950000            -- 8
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111010110000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 2645699854;
  number.bits[1] = 1271310319;
  number.bits[2] = 4294967;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 4294966960;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  s21_setSign(&check, 1);
  s21_setScale(&check, 8);
  scale = 3;
  delta_check = 0;

  delta = s21_singleScaleChange(&number, scale);

  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    79228162514264337593543950            -- 5
  //  (00000000010000011000100100110111 01001011110001101010011111101111
  //  10011101101100100010110100001110)
  // check     79228162514264337593543950000            -- 8 ==> +1
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111010110000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 2645699854;
  number.bits[1] = 1271310319;
  number.bits[2] = 4294967;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 4294966960;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  s21_setSign(&check, 1);
  s21_setScale(&check, 8);
  scale = 4;
  delta_check = 1;

  delta = s21_singleScaleChange(&number, scale);

  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number      5          -- 20
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     500000000         -- 28 ===+2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00011101110011010110010100000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 20);
  check.bits[0] = 500000000;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 28);
  scale = 10;
  delta_check = 2;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    79228162514264337593543950            -- 25
  //  (00000000010000011000100100110111 01001011110001101010011111101111
  //  10011101101100100010110100001110)
  // check     79228162514264337593543950000            -- 28 ==> +1
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111010110000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 2645699854;
  number.bits[1] = 1271310319;
  number.bits[2] = 4294967;
  s21_setSign(&number, 1);
  s21_setScale(&number, 25);
  check.bits[0] = 4294966960;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  s21_setSign(&check, 1);
  s21_setScale(&check, 28);
  scale = 4;
  delta_check = 1;

  delta = s21_singleScaleChange(&number, scale);

  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    79228162514264337593543950               -- 20
  //  (00000000010000011000100100110111 01001011110001101010011111101111
  //  10011101101100100010110100001110)
  // check     79228162514264337593543950000            -- 28 ==> +6
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111010110000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 2645699854;
  number.bits[1] = 1271310319;
  number.bits[2] = 4294967;
  s21_setSign(&number, 1);
  s21_setScale(&number, 20);
  check.bits[0] = 4294966960;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  s21_setSign(&check, 1);
  s21_setScale(&check, 23);
  scale = 9;
  delta_check = 6;

  delta = s21_singleScaleChange(&number, scale);

  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    7922816251426433759354395               -- 26
  //  (00000000000001101000110110111000 10111010110001110001000011001011
  //  00101001010111101001111000011011)
  // check     792281625142643375935439500            -- 28 ==> +7
  //  (00000010100011110101110000101000 11110101110000101000111101011100
  //  00101000111101011100001010001100)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;
  number.bits[0] = 694066715;
  number.bits[1] = 3133608139;
  number.bits[2] = 429496;
  s21_setSign(&number, 1);
  s21_setScale(&number, 26);
  check.bits[0] = 687194764;
  check.bits[1] = 4123168604;
  check.bits[2] = 42949672;
  s21_setSign(&check, 1);
  s21_setScale(&check, 28);
  scale = 9;
  delta_check = 7;

  delta = s21_singleScaleChange(&number, scale);
  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(number);
  // printf("\n");

  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    18446744073709551615            -- 10
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check       1844674407       -- 0
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  01101101111100110111111101100111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  check.bits[0] = 1844674407;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);
  scale = -10;
  delta_check = 0;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_int_eq(delta, delta_check);

  // number    18446744073709551615            -- 10
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check       18446744073       -- 1
  //  (00000000000000000000000000000000 00000000000000000000000000000100
  //  01001011100000101111101000001001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  check.bits[0] = 1266874889;
  check.bits[1] = 4;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 1);
  scale = -9;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));

  // number   18446744073709551615             -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check        1844674407370         -- 0
  //  (00000000000000000000000000000000 00000000000000000000000110101101
  //  01111111001010011010101111001010)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;
  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 2133437386;
  check.bits[1] = 429;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);
  scale = -7;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));

  // number   4294967295             -- 20
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // check        4      -- 11
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000100)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 20);
  check.bits[0] = 4;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 11);
  scale = -9;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));

  // number   4294967295             -- 20
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // check       0       -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 20);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 10);
  scale = -10;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));

  // number         18446744073709551615       -- 28
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check       0       -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 28);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 5);
  scale = -23;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));

  // number     4294967295           -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // check      0        -- 0
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta = 0;
  scale = 0;
  delta_check = 0;

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);
  scale = -11;

  delta = s21_singleScaleChange(&number, scale);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));

  // printf("Meant:  ");
  // s21_printDecimalBin(check);
  // printf("Result: ");
  // s21_printDecimalBin(number);
  // printf("\n");

  /*
  //11111111111111111111111111111111 == 4294967295
  //79228162514264337593543950335

  //number                --
  // (00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //check              --
  // (00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000) s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  delta=0;
  scale=0;
  delta_check=0;

  number.bits[0]=;
  number.bits[1]=;
  number.bits[2]=;
  s21_setSign(&number,);
  s21_setScale(&number,);
  check.bits[0]=;
  check.bits[1]=;
  check.bits[2]=;
  s21_setSign(&check,);
  s21_setScale(&check,);
  scale=;
  delta_check=;

  delta=s21_singleScaleChange(&number,scale);
  ck_assert_uint_eq(number.bits[0],check.bits[0]);
  ck_assert_uint_eq(number.bits[1],check.bits[1]);
  ck_assert_uint_eq(number.bits[2],check.bits[2]);
  ck_assert_uint_eq(number.bits[3],check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number),s21_getScale(check));
  ck_assert_int_eq(delta,delta_check);

  //printf("Meant:  ");
  //s21_printDecimalBin(check);
  //printf("Result: ");
  //s21_printDecimalBin(number);
  //printf("\n");


  */
}
START_TEST(test_scaling_and_co_4) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL,
              check = ZERO_DECIMAL, check2 = ZERO_DECIMAL;

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 10
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check      429496729500000        -- 10
  //  (00000000000000000000000000000000 00000000000000011000011010011111
  //  11111111111111100111100101100000)
  // check2      18446744073709551615        -- 10
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 10);
  check.bits[0] = 4294867296;
  check.bits[1] = 99999;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 10);
  check2.bits[0] = 4294967295;
  check2.bits[1] = 4294967295;
  check2.bits[2] = 0;
  s21_setSign(&check2, 0);
  s21_setScale(&check2, 10);

  s21_scaling(&number, &number2);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check2));

  // printf("Meant.num1:  ");
  // s21_printDecimalBin(check);
  // printf("Result.num1: ");
  // s21_printDecimalBin(number);
  // printf("Meant.num2:  ");
  // s21_printDecimalBin(check2);
  // printf("Result.num2: ");
  // s21_printDecimalBin(number2);
  // printf("\n");

  // number    618970019642690137449562112            -- 6
  //  (00000010000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  // number2       2147483648         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  10000000000000000000000000000000)
  // check     61897001964269013744956211200          -- 8
  //  (11001000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  // check2     21474836         -- 8
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000001010001111010111000010100)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 33554432;
  s21_setSign(&number, 0);
  s21_setScale(&number, 6);
  number2.bits[0] = 2147483648;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 10);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 3355443200;
  s21_setSign(&check, 0);
  s21_setScale(&check, 8);
  check2.bits[0] = 21474836;
  check2.bits[1] = 0;
  check2.bits[2] = 0;
  s21_setSign(&check2, 1);
  s21_setScale(&check2, 8);

  s21_scaling(&number, &number2);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check2));

  // printf("Meant.num1:  ");
  // s21_printDecimalBin(check);
  // printf("Result.num1: ");
  // s21_printDecimalBin(number);
  // printf("Meant.num2:  ");
  // s21_printDecimalBin(check2);
  // printf("Result.num2: ");
  // s21_printDecimalBin(number2);
  // printf("\n");

  // number   2             -- 15
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000010)
  // number2     1237940039285380274899124224           -- 5
  //  (00000100000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  // check     0         -- 6
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  // check2     12379400392853802748991242240         -- 6
  //  (00101000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0] = 2;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 15);
  number2.bits[0] = 0;
  number2.bits[1] = 0;
  number2.bits[2] = 67108864;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 6);
  check2.bits[0] = 0;
  check2.bits[1] = 0;
  check2.bits[2] = 671088640;
  s21_setSign(&check2, 1);
  s21_setScale(&check2, 6);

  s21_scaling(&number, &number2);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check2));

  // printf("Meant.num1:  ");
  // s21_printDecimalBin(check);
  // printf("Result.num1: ");
  // s21_printDecimalBin(number);
  // printf("Meant.num2:  ");
  // s21_printDecimalBin(check2);
  // printf("Result.num2: ");
  // s21_printDecimalBin(number2);
  // printf("\n");

  // number       16         -- 8
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000010000)
  // number2       4         -- 6
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000100)
  // check        16      -- 8
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  // check2       400       -- 8
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0] = 16;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 8);
  number2.bits[0] = 4;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 6);
  check.bits[0] = 16;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 0);
  s21_setScale(&check, 8);
  check2.bits[0] = 400;
  check2.bits[1] = 0;
  check2.bits[2] = 0;
  s21_setSign(&check2, 0);
  s21_setScale(&check2, 8);

  s21_scaling(&number, &number2);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check2));

  // number 5000000000               -- 1
  //  (00000000000000000000000000000000 00000000000000000000000000000001
  //  00101010000001011111001000000000)
  // number2     5000000000           -- 25
  //  (00000000000000000000000000000000 00000000000000000000000000000001
  //  00101010000001011111001000000000)
  // check   50000000000000000000000000000           -- 20
  //  (10100001100011110000011111010111 00110110101110010000101111100101
  //  01010000000000000000000000000000)
  // check2      50000        -- 20
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000001100001101010000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0] = 705032704;
  number.bits[1] = 1;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 1);
  number2.bits[0] = 705032704;
  number2.bits[1] = 1;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 25);
  check.bits[0] = 1342177280;
  check.bits[1] = 918096869;
  check.bits[2] = 2710505431;
  s21_setSign(&check, 0);
  s21_setScale(&check, 20);
  check2.bits[0] = 50000;
  check2.bits[1] = 0;
  check2.bits[2] = 0;
  s21_setSign(&check2, 1);
  s21_setScale(&check2, 20);

  // printf("Was.num1: ");
  // s21_printDecimalBin(number);
  // printf("Was.num2: ");
  // s21_printDecimalBin(number2);

  s21_scaling(&number, &number2);

  // printf("Now.num1: ");
  // s21_printDecimalBin(number);
  // printf("Now.num2: ");
  // s21_printDecimalBin(number2);
  // printf("\n");

  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check2));

  // number  2              -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000010)
  // number2  5              -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     2         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000010)
  // check2   5           -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0] = 2;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 10);
  check.bits[0] = 2;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 10);
  check2.bits[0] = 5;
  check2.bits[1] = 0;
  check2.bits[2] = 0;
  s21_setSign(&check2, 0);
  s21_setScale(&check2, 10);

  s21_scaling(&number, &number2);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(number.bits[3], check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check2));

  /*
  //11111111111111111111111111111111 == 4294967295
  //79228162514264337593543950335

  //number                --
  // (00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //number2                --
  // (00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //check              --
  // (00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000)
  //check2              --
  // (00000000000000000000000000000000 00000000000000000000000000000000
  00000000000000000000000000000000) s21_clearDecimal(&number);
  s21_clearDecimal(&check);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check2);

  number.bits[0]=;
  number.bits[1]=;
  number.bits[2]=;
  s21_setSign(&number,);
  s21_setScale(&number,);
  number2.bits[0]=;
  number2.bits[1]=;
  number2.bits[2]=;
  s21_setSign(&number2,);
  s21_setScale(&number2,);
  check.bits[0]=;
  check.bits[1]=;
  check.bits[2]=;
  s21_setSign(&check,);
  s21_setScale(&check,);
  check2.bits[0]=;
  check2.bits[1]=;
  check2.bits[2]=;
  s21_setSign(&check2,);
  s21_setScale(&check2,);

  s21_scaling(&number,&number2);
  ck_assert_uint_eq(number.bits[0],check.bits[0]);
  ck_assert_uint_eq(number.bits[1],check.bits[1]);
  ck_assert_uint_eq(number.bits[2],check.bits[2]);
  ck_assert_uint_eq(number.bits[3],check.bits[3]);
  ck_assert_uint_eq(s21_getScale(number),s21_getScale(check));
  ck_assert_uint_eq(number2.bits[0],check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1],check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2],check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3],check2.bits[3]);
  ck_assert_uint_eq(s21_getScale(number2),s21_getScale(check2));

  //printf("Meant.num1:  ");
  //s21_printDecimalBin(check);
  //printf("Result.num1: ");
  //s21_printDecimalBin(number);
  //printf("Meant.num2:  ");
  //s21_printDecimalBin(check2);
  //printf("Result.num2: ");
  //s21_printDecimalBin(number2);
  //printf("\n");

  */
}

START_TEST(test_scaling_and_co_5) {
  s21_expended number1 = ZERO_EXPENDED, check1 = ZERO_EXPENDED;
  int new_scale = 0;

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      429496729500000        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000011000011010011111 11111111111111100111100101100000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  new_scale = 5;

  check1.bits[0] = 4294867296;
  check1.bits[1] = 99999;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 10);

  number1 = s21_simpleSingleScaleExpAdd(number1, new_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      4294967295       -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  new_scale = 0;

  check1.bits[0] = 4294967295;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 5);

  number1 = s21_simpleSingleScaleExpAdd(number1, new_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check1      42949       -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000001010011111000101)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  new_scale = -5;

  check1.bits[0] = 42949;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 0);

  number1 = s21_simpleSingleScaleExpAdd(number1, new_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       79228162514264337593543950335         -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  // check1      792281625142643375935439503350000000000000000000000000000 -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);

  new_scale = 28;

  check1.bits[0] = 4026531840;
  check1.bits[1] = 3252354462;
  check1.bits[2] = 3752866209;
  check1.bits[3] = 268435455;
  check1.bits[4] = 1042612833;
  check1.bits[5] = 542101086;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 28);

  number1 = s21_simpleSingleScaleExpAdd(number1, new_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check1      0       -- -28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);

  new_scale = -28;

  check1.bits[0] = 0;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, -28);

  number1 = s21_simpleSingleScaleExpAdd(number1, new_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  s21_clearExpended(&number1);
  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);
  ck_assert_uint_eq(s21_rankOfNumberExp(number1), 10);

  // number1       12554203470773361527671578846256876507176182213740981125120
  // -- 20
  //  (1 11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111110)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearExpended(&number1);
  number1.bits[0] = 0;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 4294967294;
  number1.bits[4] = 4294967295;
  number1.bits[5] = 4294967295;
  s21_setBitGlobalExp(&number1, mantissa_six, 1);
  s21_setSignExp(&number1, 0);
  s21_setScaleExp(&number1, 20);
  ck_assert_uint_eq(s21_rankOfNumberExp(number1), 59);

  // number1       79228162514264337593543950335         -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  s21_clearExpended(&number1);
  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 10);
  ck_assert_uint_eq(s21_rankOfNumberExp(number1), 29);

  // number1       0        -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearExpended(&number1);
  number1.bits[0] = 0;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 0);
  s21_setScaleExp(&number1, 0);
  ck_assert_uint_eq(s21_rankOfNumberExp(number1), 0);
}
START_TEST(test_scaling_and_co_6) {
  s21_expended number1 = ZERO_EXPENDED, check1 = ZERO_EXPENDED;
  int add_scale = 0, output = 0;

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      429496729500000        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000011000011010011111 11111111111111100111100101100000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);
  output = 0;

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  add_scale = 5;

  check1.bits[0] = 4294867296;
  check1.bits[1] = 99999;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 10);

  output = s21_singleScaleExpChange(&number1, add_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(output, 0);

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      4294967295       -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  add_scale = 0;

  check1.bits[0] = 4294967295;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 5);

  output = s21_singleScaleExpChange(&number1, add_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(output, 0);

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check1      42949       -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000001010011111000101)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  add_scale = -5;

  check1.bits[0] = 42949;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 0);

  output = s21_singleScaleExpChange(&number1, add_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(output, 0);

  // number1       79228162514264337593543950335         -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  // check1      792281625142643375935439503350000000000000000000000000000 -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);

  add_scale = 28;

  check1.bits[0] = 4026531840;
  check1.bits[1] = 3252354462;
  check1.bits[2] = 3752866209;
  check1.bits[3] = 268435455;
  check1.bits[4] = 1042612833;
  check1.bits[5] = 542101086;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 28);

  output = s21_singleScaleExpChange(&number1, add_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(output, 0);

  // number1       4294967295         -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check1      0       -- -28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);

  add_scale = -28;

  check1.bits[0] = 0;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 0);

  output = s21_singleScaleExpChange(&number1, add_scale);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(output, -28);
}
START_TEST(test_scaling_and_co_7) {
  s21_expended number1 = ZERO_EXPENDED, check1 = ZERO_EXPENDED,
               number2 = ZERO_EXPENDED, check2 = ZERO_EXPENDED;
  int output = 0;

  // number1       79228162514264337593543950335         -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  // number2       1         -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  // check1      792281625142643375935439503350000000000000000000000000000 -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000000)
  // check2     1        -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);
  s21_clearExpended(&number2);
  s21_clearExpended(&check2);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);

  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  s21_setSignExp(&number2, 0);
  s21_setScaleExp(&number2, 28);

  check1.bits[0] = 4026531840;
  check1.bits[1] = 3252354462;
  check1.bits[2] = 3752866209;
  check1.bits[3] = 268435455;
  check1.bits[4] = 1042612833;
  check1.bits[5] = 542101086;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 28);

  check2.bits[0] = 1;
  check2.bits[1] = 0;
  check2.bits[2] = 0;
  check2.bits[3] = 0;
  check2.bits[4] = 0;
  check2.bits[5] = 0;
  s21_setBitGlobalExp(&check2, mantissa_six, 0);
  s21_setSignExp(&check2, 0);
  s21_setScaleExp(&check2, 28);

  output = s21_scalingExp(&number1, &number2);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(number2.bits[4], check2.bits[4]);
  ck_assert_uint_eq(number2.bits[5], check2.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number2), s21_getScaleExp(check2));
  ck_assert_uint_eq(s21_getSignExp(number2), s21_getSignExp(check2));
  ck_assert_uint_eq(output, 0);

  // printf("Meant.num1:  ");
  // s21_printExpendedBin(check1);
  // printf("Result.num1: ");
  // s21_printExpendedBin(number1);
  // printf("Meant.num2:  ");
  // s21_printExpendedBin(check2);
  // printf("Result.num2: ");
  // s21_printExpendedBin(number2);
  // printf("\n");

  // number1       4294967295         -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // number2       5        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000101)
  // check1      4294967295        -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check2     50000000000        -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000001011
  //    10100100001110110111010000000000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);
  s21_clearExpended(&number2);
  s21_clearExpended(&check2);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 15);

  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  s21_setSignExp(&number2, 0);
  s21_setScaleExp(&number2, 5);

  check1.bits[0] = 4294967295;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 15);

  check2.bits[0] = 2755359744;
  check2.bits[1] = 11;
  check2.bits[2] = 0;
  check2.bits[3] = 0;
  check2.bits[4] = 0;
  check2.bits[5] = 0;
  s21_setBitGlobalExp(&check2, mantissa_six, 0);
  s21_setSignExp(&check2, 0);
  s21_setScaleExp(&check2, 15);

  output = s21_scalingExp(&number1, &number2);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(number2.bits[4], check2.bits[4]);
  ck_assert_uint_eq(number2.bits[5], check2.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number2), s21_getScaleExp(check2));
  ck_assert_uint_eq(s21_getSignExp(number2), s21_getSignExp(check2));
  ck_assert_uint_eq(output, 0);

  // number1       4294967295         -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // number2       5        -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000101)
  // check1      4294967295        -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check2     5       -- 15
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000101)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);
  s21_clearExpended(&number2);
  s21_clearExpended(&check2);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 15);

  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 0;
  number2.bits[4] = 0;
  number2.bits[5] = 0;
  s21_setBitGlobalExp(&number2, mantissa_six, 0);
  s21_setSignExp(&number2, 0);
  s21_setScaleExp(&number2, 15);

  check1.bits[0] = 4294967295;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 15);

  check2.bits[0] = 5;
  check2.bits[1] = 0;
  check2.bits[2] = 0;
  check2.bits[3] = 0;
  check2.bits[4] = 0;
  check2.bits[5] = 0;
  s21_setBitGlobalExp(&check2, mantissa_six, 0);
  s21_setSignExp(&check2, 0);
  s21_setScaleExp(&check2, 15);

  output = s21_scalingExp(&number1, &number2);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
  ck_assert_uint_eq(number2.bits[0], check2.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check2.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check2.bits[2]);
  ck_assert_uint_eq(number2.bits[3], check2.bits[3]);
  ck_assert_uint_eq(number2.bits[4], check2.bits[4]);
  ck_assert_uint_eq(number2.bits[5], check2.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number2), s21_getScaleExp(check2));
  ck_assert_uint_eq(s21_getSignExp(number2), s21_getSignExp(check2));
  ck_assert_uint_eq(output, 0);
}

// elevator   extra_functions  (test 32/-)
START_TEST(test_extra_functions_1) {
  // printf("TESTING: extra_functions/s21_extra_functions.c
  // ................\n");

  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  int output = 0;
  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)

  s21_clearDecimal(&number);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);

  output = s21_negate(number, &number2);
  ck_assert_uint_eq(number.bits[0], number2.bits[0]);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);
  ck_assert_uint_eq(number.bits[2], number2.bits[2]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(number2));
  ck_assert_uint_eq(s21_getSign(number), 1);
  ck_assert_uint_eq(s21_getSign(number2), 0);
  ck_assert_uint_eq(output, 0);
  output = s21_negate(number2, &number2);
  ck_assert_uint_eq(number.bits[0], number2.bits[0]);
  ck_assert_uint_eq(number.bits[1], number2.bits[1]);
  ck_assert_uint_eq(number.bits[2], number2.bits[2]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(number2));
  ck_assert_uint_eq(s21_getSign(number), 1);
  ck_assert_uint_eq(s21_getSign(number2), 1);
  ck_assert_uint_eq(output, 0);
  s21_decimal *number3 = NULL;

  output = s21_negate(number2, number3);
  ck_assert_uint_eq(output, 1);

  s21_decimal check;
  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)

  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 42949;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);

  output = s21_truncate(number, &number2);
  ck_assert_uint_eq(number2.bits[0], check.bits[0]);
  ck_assert_uint_eq(number2.bits[1], check.bits[1]);
  ck_assert_uint_eq(number2.bits[2], check.bits[2]);
  ck_assert_uint_eq(s21_getScale(number2), s21_getScale(check));
  ck_assert_uint_eq(s21_getSign(number2), s21_getSign(check));
  ck_assert_uint_eq(output, 0);

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)

  s21_clearDecimal(&number);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  check.bits[0] = 42949;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);

  output = s21_truncate(number, &number);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(s21_getSign(number), s21_getSign(check));
  ck_assert_uint_eq(output, 0);

  // number       4294967295         -- 0
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)

  s21_clearDecimal(&number);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 0);
  check.bits[0] = 4294967295;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);

  output = s21_truncate(number, &number);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(s21_getSign(number), s21_getSign(check));
  ck_assert_uint_eq(output, 0);

  // number       4294967295         -- 9
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)

  s21_clearDecimal(&number);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 9);
  check.bits[0] = 4;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);

  output = s21_truncate(number, &number);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(s21_getSign(number), s21_getSign(check));
  ck_assert_uint_eq(output, 0);

  // number       4294967295         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)

  s21_clearDecimal(&number);
  s21_clearDecimal(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  s21_setSign(&check, 1);
  s21_setScale(&check, 0);

  output = s21_truncate(number, &number);
  ck_assert_uint_eq(number.bits[0], check.bits[0]);
  ck_assert_uint_eq(number.bits[1], check.bits[1]);
  ck_assert_uint_eq(number.bits[2], check.bits[2]);
  ck_assert_uint_eq(s21_getScale(number), s21_getScale(check));
  ck_assert_uint_eq(s21_getSign(number), s21_getSign(check));
  ck_assert_uint_eq(output, 0);

  output = s21_truncate(number, number3);
  ck_assert_uint_eq(output, 1);
}

// elevator  main_comparison  (test 33-34/-)
START_TEST(test_main_comparison_1) {
  printf(
      "TESTING: "
      "comparison/"
      "s21_main_comparison.c..................................................."
      "..............\n");
  s21_decimal number1 = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  int result = 0;

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, 0);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  result = 5;

  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 0);

  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, 1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  result = 5;

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 0);

  number2.bits[0] = 1;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, -1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  result = 5;

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 9);

  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, -1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  result = 5;

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 9);

  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 0);

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, 1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  result = 5;

  number1.bits[0] = 4294967290;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 1);
  s21_setScale(&number1, 0);

  number2.bits[0] = 4294967294;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, -1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  result = 5;

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 1);
  s21_setScale(&number1, 0);

  number2.bits[0] = 4294967294;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 0);

  result = s21_main_compare(number1, number2);
  ck_assert_int_eq(result, -1);
}
START_TEST(test_main_comparison_2) {
  s21_decimal number1 = ZERO_DECIMAL, number2 = ZERO_DECIMAL;

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 0);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);
  ck_assert_int_eq(s21_is_less(number1, number2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_greater(number1, number2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_not_equal(number1, number2), 1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 9);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);
  ck_assert_int_eq(s21_is_less(number1, number2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_greater(number1, number2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_not_equal(number1, number2), 1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 0);
  s21_setScale(&number1, 9);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 0);
  ck_assert_int_eq(s21_is_less(number1, number2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_greater(number1, number2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_not_equal(number1, number2), 1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  number1.bits[0] = 5;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 1);
  s21_setScale(&number1, 9);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 9);
  ck_assert_int_eq(s21_is_less(number1, number2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_greater(number1, number2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_not_equal(number1, number2), 0);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  number1.bits[0] = 5;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 1);
  s21_setScale(&number1, 9);
  number2.bits[0] = 4;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 9);
  ck_assert_int_eq(s21_is_less(number1, number2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_greater(number1, number2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_equal(number1, number2), 0);
  ck_assert_int_eq(s21_is_not_equal(number1, number2), 1);

  s21_clearDecimal(&number1);
  s21_clearDecimal(&number2);
  number1.bits[0] = 500000;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  s21_setSign(&number1, 1);
  s21_setScale(&number1, 5);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 0);
  ck_assert_int_eq(s21_is_less(number1, number2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_greater(number1, number2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_equal(number1, number2), 1);
  ck_assert_int_eq(s21_is_not_equal(number1, number2), 0);
}

// elevator  service_functions  (test 35/-)
START_TEST(test_service_functions) {
  printf(
      "TESTING: "
      "service_functions/"
      "s21_service_functions.c................................................."
      "................\n");
  s21_expended number1 = ZERO_EXPENDED, check1 = ZERO_EXPENDED;

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      4294967295       -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  check1.bits[0] = 4294967295;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 5);

  s21_uninformativeZeroCutterExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967000         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      4294967       -- 2
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967000;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  check1.bits[0] = 4294967;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 2);

  s21_uninformativeZeroCutterExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       6277101735386680763835789423200000000000000000000000000000 --
  // 28
  //  (0 11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  //    (11100111001110100111110100111110 01010101000110010110010000100111
  //    00000000000000000000000000000000)
  // check1      627710173538668076383578942320       -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000111)
  //    (11101100001111011010111110010100 00011000000001100101000001101100
  //    01011110010101001110101101110000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 0;
  number1.bits[1] = 1427727399;
  number1.bits[2] = 3879370046;
  number1.bits[3] = 4294967295;
  number1.bits[4] = 4294967295;
  number1.bits[5] = 4294967295;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 28);

  check1.bits[0] = 1582623600;
  check1.bits[1] = 403066988;
  check1.bits[2] = 3963465620;
  check1.bits[3] = 7;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 0);

  s21_uninformativeZeroCutterExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       6277101735386680763835789423200000000000000000000000000000 --
  // 0
  //  (0 11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  //    (11100111001110100111110100111110 01010101000110010110010000100111
  //    00000000000000000000000000000000)
  // check1      6277101735386680763835789423200000000000000000000000000000 -- 0
  //  (0 11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  //    (11100111001110100111110100111110 01010101000110010110010000100111
  //    00000000000000000000000000000000)
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 0;
  number1.bits[1] = 1427727399;
  number1.bits[2] = 3879370046;
  number1.bits[3] = 4294967295;
  number1.bits[4] = 4294967295;
  number1.bits[5] = 4294967295;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 0);

  check1.bits[0] = 0;
  check1.bits[1] = 1427727399;
  check1.bits[2] = 3879370046;
  check1.bits[3] = 4294967295;
  check1.bits[4] = 4294967295;
  check1.bits[5] = 4294967295;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 0);

  s21_uninformativeZeroCutterExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (00000000000000000000000000000000
  //  00000000000000000000000000000000 11111111111111111111111111111111)
  // check1      42949672950000000000000000000       -- 24
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000) (10001010110001110010001100000011
  //  11111111001000001101110011111011 01110110000110000000000000000000)
  //   79228162514264337593543950335
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  check1.bits[0] = 1981284352;
  check1.bits[1] = 4280343803;
  check1.bits[2] = 2328306435;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 24);

  s21_decimalFillerExp(&number1);
  // s21_printExpendedBin(number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 27
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check1      42949672950       -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000001001
  //    11111111111111111111111111110110)
  //   79228162514264337593543950335
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 0);
  s21_setScaleExp(&number1, 27);

  check1.bits[0] = 4294967286;
  check1.bits[1] = 9;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 0);
  s21_setScaleExp(&check1, 28);

  s21_decimalFillerExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       4294967295         -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  // check1      4294967295      -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    11111111111111111111111111111111)
  //   79228162514264337593543950335
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 0);
  s21_setScaleExp(&number1, 28);

  check1.bits[0] = 4294967295;
  check1.bits[1] = 0;
  check1.bits[2] = 0;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 0);
  s21_setScaleExp(&check1, 28);

  s21_decimalFillerExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       7922816251426433759354395033         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00011001100110011001100110011001 10011001100110011001100110011001
  //    10011001100110011001100110011001)
  // check1      79228162514264337593543950330      -- 6
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111010)
  //   79228162514264337593543950335
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 2576980377;
  number1.bits[1] = 2576980377;
  number1.bits[2] = 429496729;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 0);
  s21_setScaleExp(&number1, 5);

  check1.bits[0] = 4294967290;
  check1.bits[1] = 4294967295;
  check1.bits[2] = 4294967295;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 0);
  s21_setScaleExp(&check1, 6);

  s21_decimalFillerExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));

  // number1       79228162514264337593543950335         -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  // check1      79228162514264337593543950335      -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111111 11111111111111111111111111111111
  //    11111111111111111111111111111111)
  //   79228162514264337593543950335
  s21_clearExpended(&number1);
  s21_clearExpended(&check1);

  number1.bits[0] = 4294967295;
  number1.bits[1] = 4294967295;
  number1.bits[2] = 4294967295;
  number1.bits[3] = 0;
  number1.bits[4] = 0;
  number1.bits[5] = 0;
  s21_setBitGlobalExp(&number1, mantissa_six, 0);
  s21_setSignExp(&number1, 1);
  s21_setScaleExp(&number1, 5);

  check1.bits[0] = 4294967295;
  check1.bits[1] = 4294967295;
  check1.bits[2] = 4294967295;
  check1.bits[3] = 0;
  check1.bits[4] = 0;
  check1.bits[5] = 0;
  s21_setBitGlobalExp(&check1, mantissa_six, 0);
  s21_setSignExp(&check1, 1);
  s21_setScaleExp(&check1, 5);

  s21_decimalFillerExp(&number1);
  ck_assert_uint_eq(number1.bits[0], check1.bits[0]);
  ck_assert_uint_eq(number1.bits[1], check1.bits[1]);
  ck_assert_uint_eq(number1.bits[2], check1.bits[2]);
  ck_assert_uint_eq(number1.bits[3], check1.bits[3]);
  ck_assert_uint_eq(number1.bits[4], check1.bits[4]);
  ck_assert_uint_eq(number1.bits[5], check1.bits[5]);
  ck_assert_uint_eq(s21_getScaleExp(number1), s21_getScaleExp(check1));
  ck_assert_uint_eq(s21_getSignExp(number1), s21_getSignExp(check1));
}

// elevator  arithmetic  (test 36-39/-)
START_TEST(test_arithmetic_the_addition) {
  printf(
      "TESTING: "
      "arithmetic/"
      "s21_arithmetic.c........................................................"
      ".........\n");
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  s21_expended result = ZERO_EXPENDED, check = ZERO_EXPENDED;

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000001 00000000000000000000000000000000
  //    11111111111111111111111111111110)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 4294967294;
  check.bits[1] = 0;
  check.bits[2] = 1;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 5);

  result = s21_theAddition(number, number2);
  // s21_printExpendedBin(result);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 11111111111111111111111111111111
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 0;
  check.bits[1] = 4294967295;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 5);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 11111111111111111111111111111111
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 0;
  check.bits[1] = 4294967295;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 5);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000001 00000000000000000000000000000000
  //    11111111111111111111111111111110)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 4294967294;
  check.bits[1] = 0;
  check.bits[2] = 1;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 5);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       21474836480         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000101
  //  00000000000000000000000000000000)
  // number2  5              -- 1
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     28525163520        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000110
  //    10100100001110110111010000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 0;
  number.bits[1] = 5;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);
  check.bits[0] = 2755359744;
  check.bits[1] = 6;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 10);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       21474836480         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000101
  //  00000000000000000000000000000000)
  // number2  5              -- 1
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     28525163520        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000110
  //    00101010000001011111001000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 0;
  number.bits[1] = 5;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 1);
  check.bits[0] = 705032704;
  check.bits[1] = 6;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 10);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 0
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  1              -- 28
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000001)
  // check             -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000001)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  s21_setScale(&number, 28);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 28);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 1;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 28);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 0
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  79228162514264337593543950335              -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check             -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00010000000000000000000000000000)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11101111111111111111111111111111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 0);
  s21_setScale(&number, 0);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 4294967295;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 28);
  check.bits[0] = 4026531839;
  check.bits[1] = 3252354462;
  check.bits[2] = 3752866209;
  check.bits[3] = 268435456;
  check.bits[4] = 1042612833;
  check.bits[5] = 542101086;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 28);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 0
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  1              -- 28
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000001)
  // check      792281625142643375935439503350000000000000000000000000001 -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  s21_setScale(&number, 0);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 28);
  check.bits[0] = 4026531841;
  check.bits[1] = 3252354462;
  check.bits[2] = 3752866209;
  check.bits[3] = 268435455;
  check.bits[4] = 1042612833;
  check.bits[5] = 542101086;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 28);

  result = s21_theAddition(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));
}
START_TEST(test_arithmetic_the_subtraction) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  s21_expended result = ZERO_EXPENDED, check = ZERO_EXPENDED;

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000001 00000000000000000000000000000000
  //    11111111111111111111111111111110)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 4294967294;
  check.bits[1] = 0;
  check.bits[2] = 1;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 5);

  result = s21_theSubtraction(number, number2);
  // s21_printExpendedBin(result);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 11111111111111111111111111111111
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 0;
  check.bits[1] = 4294967295;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 5);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 11111111111111111111111111111111
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 0;
  check.bits[1] = 4294967295;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 5);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     18446744078004518910        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000001 00000000000000000000000000000000
  //    11111111111111111111111111111110)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 4294967294;
  check.bits[1] = 0;
  check.bits[2] = 1;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 5);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       21474836480         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000101
  //  00000000000000000000000000000000)
  // number2  5              -- 1
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     28525163520        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000110
  //    10100100001110110111010000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 0;
  number.bits[1] = 5;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 10);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);
  check.bits[0] = 2755359744;
  check.bits[1] = 6;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 10);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       21474836480         -- 10
  //  (00000000000000000000000000000000 00000000000000000000000000000101
  //  00000000000000000000000000000000)
  // number2  5              -- 1
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     28525163520        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000110
  //    00101010000001011111001000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 0;
  number.bits[1] = 5;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 10);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 1);
  check.bits[0] = 705032704;
  check.bits[1] = 6;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 10);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  1              -- 28
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000001)
  // check             -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000001)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 0);
  s21_setScale(&number, 28);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 28);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 1;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 28);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 0
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  79228162514264337593543950335              -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check             -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00010000000000000000000000000000)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11101111111111111111111111111111)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 0);
  s21_setScale(&number, 0);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 4294967295;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 28);
  check.bits[0] = 4026531839;
  check.bits[1] = 3252354462;
  check.bits[2] = 3752866209;
  check.bits[3] = 268435456;
  check.bits[4] = 1042612833;
  check.bits[5] = 542101086;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 28);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 0
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  1              -- 28
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000001)
  // check      792281625142643375935439503350000000000000000000000000001 -- 28
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  s21_setScale(&number, 0);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 28);
  check.bits[0] = 4026531841;
  check.bits[1] = 3252354462;
  check.bits[2] = 3752866209;
  check.bits[3] = 268435455;
  check.bits[4] = 1042612833;
  check.bits[5] = 542101086;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 28);

  result = s21_theSubtraction(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));
}
START_TEST(test_arithmetic_the_multiplication) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  s21_expended result = ZERO_EXPENDED, check = ZERO_EXPENDED;

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     79228162495817593515539431425        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111110 11111111111111111111111111111111
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 1;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967294;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 10);

  result = s21_theMultiplication(number, number2);
  // s21_printExpendedBin(result);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     79228162495817593515539431425        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111110 11111111111111111111111111111111
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);
  check.bits[0] = 1;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967294;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 5);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     79228162495817593515539431425        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111110 11111111111111111111111111111111
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 1;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967294;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 10);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 5
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     79228162495817593515539431425        -- 10
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111110 11111111111111111111111111111111
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 5);
  check.bits[0] = 1;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967294;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 10);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  18446744073709551615              -- 0
  //  (00000000000000000000000000000000 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     79228162495817593515539431425        -- 5
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (11111111111111111111111111111110 11111111111111111111111111111111
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 0);
  check.bits[0] = 1;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967294;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 5);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2      79228162514264337593543950335         -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     6277101732463677488833701220196270937245025404012277530625 -- 56
  //  (0 11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111110)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  s21_setScale(&number, 28);
  number2.bits[0] = 4294967295;
  number2.bits[1] = 4294967295;
  number2.bits[2] = 4294967295;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 28);
  check.bits[0] = 1;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 4294967294;
  check.bits[4] = 4294967295;
  check.bits[5] = 4294967295;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 56);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2      0         -- 28
  //  (0 0 0)
  // check     0        -- 56
  //  (0 0 0 0)
  //    (0 0 0)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  s21_setScale(&number, 28);
  number2.bits[0] = 0;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 28);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 56);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2      79228162514264337593543950335         -- 28
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // check     6277101732463677488833701220196270937245025404012277530625 -- 56
  //  (0 11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111110)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000001)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 1);
  s21_setScale(&number, 28);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 28);
  check.bits[0] = 4294967295;
  check.bits[1] = 4294967295;
  check.bits[2] = 4294967295;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 56);

  result = s21_theMultiplication(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));
}
START_TEST(test_arithmetic_the_division) {
  s21_decimal number = ZERO_DECIMAL, number2 = ZERO_DECIMAL;
  s21_expended result = ZERO_EXPENDED, check = ZERO_EXPENDED;

  // number       4294967295         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  5              -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     858993459        -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00110011001100110011001100110011)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 858993459;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 0);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       4294967295         -- 2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  33              -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000100001)
  // check     130150524 0909090909090909090909090909090        -- 28
  //  (0 00000000000000000000000000000000 00000000000000000000000000000011
  //  11010011001001001100101010100111)
  //    (11100101000111011010101111111000 01011011001000100110001010010010
  //    00111010001011101000101110100010)
  //  79228162514264337593543950335 340282366920938463463374607431768211455
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 2);
  number2.bits[0] = 33;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 976128930;
  check.bits[1] = 1528980114;
  check.bits[2] = 3843927032;
  check.bits[3] = 3542403751;
  check.bits[4] = 3;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 28);

  result = s21_theDivision(number, number2);
  // s21_printExpendedBin(result);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       1         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000 1)
  // number2  3              -- 2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000011)
  // check     3333333333333333333333333333333333333        -- 39
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000010100000011111101000000101)
  //    (10011100100111100001011110011101 10101010111111000001001000110101
  //    01010101010101010101010101010101)
  //  79228162514264337593543950335 340282366920938463463374607431768211455
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 1;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 3;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 2);
  check.bits[0] = 1431655765;
  check.bits[1] = 2868646453;
  check.bits[2] = 2627606429;
  check.bits[3] = 42072581;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 40);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       1         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000 1)
  // number2  3              -- 2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000011)
  // check     3333333333333333333333333333333333333        -- 39
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000010100000011111101000000101)
  //    (10011100100111100001011110011101 10101010111111000001001000110101
  //    01010101010101010101010101010101)
  //  79228162514264337593543950335 340282366920938463463374607431768211455
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 1;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 3;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 2);
  check.bits[0] = 1431655765;
  check.bits[1] = 2868646453;
  check.bits[2] = 2627606429;
  check.bits[3] = 42072581;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 40);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       1         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000 1)
  // number2  3              -- 2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000011)
  // check     3333333333333333333333333333333333333        -- 39
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000010100000011111101000000101)
  //    (10011100100111100001011110011101 10101010111111000001001000110101
  //    01010101010101010101010101010101)
  //  79228162514264337593543950335 340282366920938463463374607431768211455
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 1;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 5);
  number2.bits[0] = 3;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 2);
  check.bits[0] = 1431655765;
  check.bits[1] = 2868646453;
  check.bits[2] = 2627606429;
  check.bits[3] = 42072581;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 40);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       1         -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000 1)
  // number2  3              -- 2
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000011)
  // check     3333333333333333333333333333333333333        -- 39
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000010100000011111101000000101)
  //    (10011100100111100001011110011101 10101010111111000001001000110101
  //    01010101010101010101010101010101)
  //  79228162514264337593543950335 340282366920938463463374607431768211455
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 1;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 5);
  number2.bits[0] = 3;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 1);
  s21_setScale(&number2, 2);
  check.bits[0] = 1431655765;
  check.bits[1] = 2868646453;
  check.bits[2] = 2627606429;
  check.bits[3] = 42072581;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 40);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       5         -- 0
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  11111111111111111111111111111111)
  // number2  5              -- 5
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     100000        -- 0
  //  (0 00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000000)
  //    (00000000000000000000000000000000 00000000000000000000000000000000
  //    00000000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 5;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 1);
  s21_setScale(&number, 0);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 5);
  check.bits[0] = 100000;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 1);
  s21_setScaleExp(&check, 0);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       79228162514264337593543950335         -- 0
  //  (11111111111111111111111111111111 11111111111111111111111111111111
  //  11111111111111111111111111111111)
  // number2  1              -- 28
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     792281625142643375935439503350000000000000000000000000000 -- 0
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 4294967295;
  number.bits[1] = 4294967295;
  number.bits[2] = 4294967295;
  s21_setSign(&number, 0);
  s21_setScale(&number, 0);
  number2.bits[0] = 1;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 28);
  check.bits[0] = 4026531840;
  check.bits[1] = 3252354462;
  check.bits[2] = 3752866209;
  check.bits[3] = 268435455;
  check.bits[4] = 1042612833;
  check.bits[5] = 542101086;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 0);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));

  // number       0         -- 0
  //  (0 0 0)
  // number2  1              -- 28
  //  (00000000000000000000000000000000 00000000000000000000000000000000
  //  00000000000000000000000000000101)
  // check     792281625142643375935439503350000000000000000000000000000 -- 0
  //  (0 00100000010011111100111001011110 00111110001001010000001001100001
  //  00001111111111111111111111111111)
  //    (11011111101100000011000110100001 11000001110110101111110110011110
  //    11110000000000000000000000000000)
  s21_clearDecimal(&number);
  s21_clearDecimal(&number2);
  s21_clearExpended(&result);
  s21_clearExpended(&check);

  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_setSign(&number, 0);
  s21_setScale(&number, 0);
  number2.bits[0] = 5;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  s21_setSign(&number2, 0);
  s21_setScale(&number2, 15);
  check.bits[0] = 0;
  check.bits[1] = 0;
  check.bits[2] = 0;
  check.bits[3] = 0;
  check.bits[4] = 0;
  check.bits[5] = 0;
  s21_setBitGlobalExp(&check, mantissa_six, 0);
  s21_setSignExp(&check, 0);
  s21_setScaleExp(&check, 0);

  result = s21_theDivision(number, number2);
  ck_assert_uint_eq(result.bits[0], check.bits[0]);
  ck_assert_uint_eq(result.bits[1], check.bits[1]);
  ck_assert_uint_eq(result.bits[2], check.bits[2]);
  ck_assert_uint_eq(result.bits[3], check.bits[3]);
  ck_assert_uint_eq(result.bits[4], check.bits[4]);
  ck_assert_uint_eq(result.bits[5], check.bits[5]);
  ck_assert_uint_eq(s21_getBitGlobalExp(result, mantissa_six),
                    s21_getBitGlobalExp(check, mantissa_six));
  ck_assert_uint_eq(s21_getSignExp(result), s21_getSignExp(check));
  ck_assert_uint_eq(s21_getScaleExp(result), s21_getScaleExp(check));
}

// elevator  main_converters    (test 40-51/-)
START_TEST(test_convert_int) {
  int int1 = INT32_MAX;
  s21_decimal dec1 = ZERO_DECIMAL;
  int error = 0;
  error = s21_from_int_to_decimal(int1, &dec1);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(dec1.bits[0], int1);
  ck_assert_uint_eq(dec1.bits[1], 0);
  ck_assert_uint_eq(dec1.bits[2], 0);
  ck_assert_uint_eq(dec1.bits[3], 0);

  int int2 = 0;
  s21_decimal dec2 = ZERO_DECIMAL;
  error = s21_from_int_to_decimal(int2, &dec2);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(dec2.bits[0], int2);
  ck_assert_uint_eq(dec2.bits[1], 0);
  ck_assert_uint_eq(dec2.bits[2], 0);
  ck_assert_uint_eq(dec2.bits[3], 0);

  int int3 = -123;
  s21_decimal dec3 = ZERO_DECIMAL;
  error = s21_from_int_to_decimal(int3, &dec3);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(dec3.bits[0], -int3);
  ck_assert_uint_eq(dec3.bits[1], 0);
  ck_assert_uint_eq(dec3.bits[2], 0);
  ck_assert_uint_eq(s21_getSign(dec3), 1);

  int int4 = 0;
  error = s21_from_decimal_to_int(dec1, &int4);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(int4, int1);

  int int5 = 0;
  error = s21_from_decimal_to_int(dec2, &int5);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(int5, int2);

  int int6 = 0;
  error = s21_from_decimal_to_int(dec3, &int6);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(int6, int3);

  int int7 = 0;
  s21_decimal dec4 = {{123, 123, 123, 0}};
  error = s21_from_decimal_to_int(dec4, &int7);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(int7, 0);

  int int8 = 0;
  s21_decimal dec5 = {{123, 0, 123, 0}};
  error = s21_from_decimal_to_int(dec5, &int8);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(int8, 0);

  int int9 = 0;
  s21_decimal dec6 = {{123, 123, 0, 0}};
  error = s21_from_decimal_to_int(dec6, &int9);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(int9, 0);
}
START_TEST(fl_to_dc_1) {
  float number = 1.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(0, s21_getScale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_2) {
  float number = 0.1;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(1, s21_getScale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_3) {
  float number = -0.1;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(1, s21_getSign(decimal_check));
  ck_assert_uint_eq(1, s21_getScale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_4) {
  float number = 1e-29;
  int check_return = 0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  check_return = s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(0, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(0, s21_getScale(decimal_check));
  ck_assert_int_eq(1, check_return);
}
END_TEST
/*
START_TEST(test_convert_float){
        float fltmaxerr = FLT_MAX;
        s21_decimal decmaxerr = ZERO_DECIMAL;
        int error = 0;
        error = s21_from_float_to_decimal(fltmaxerr, &decmaxerr);
        ck_assert_uint_eq(error, 1);

        float fltmin = MIN_FLOAT_TO_DECIMAL;
        s21_decimal decmin = ZERO_DECIMAL;
        error = 0;
        error = s21_from_float_to_decimal(fltmin, &decmin);
        ck_assert_uint_eq(error, 0);
        //error = s21_from_decimal_to_float(decmin, &fltmin2);
        ck_assert_uint_eq(error, 0);
        //ck_assert_float_eq(fltmin, fltmin2);

        float fltminerr = 1e-29;
        s21_decimal decminerr = ZERO_DECIMAL;
        error = 0;
        error = s21_from_float_to_decimal(fltminerr, &decminerr);
        ck_assert_uint_eq(error, 1);

        float flt1 = 123.123;
        s21_decimal dec1 = ZERO_DECIMAL;
        error = s21_from_float_to_decimal(flt1, &dec1);
        s21_printDecimalBinReal(dec1);
        //error = s21_from_decimal_to_float(dec1, &flt12);
        //ck_assert_float_eq(flt1, flt12);

        float fltmax = MAX_FLOAT_TO_DECIMAL;
        float fltmax2 = 0;
        s21_decimal decmax = ZERO_DECIMAL;
        error = 0;
        error = s21_from_float_to_decimal(fltmax, &decmax);

        printf("\n----\n");
        s21_printDecimalBinReal(decmax);
        printf("\n----\n");

        ck_assert_uint_eq(error, 0);
        //error = s21_from_decimal_to_float(decmax, &fltmax2);
        ck_assert_uint_eq(error, 0);

        s21_printDecimalBinReal(decmax);
        printf("%.30f\n%.30f\n", fltmax, fltmax2);

        //ck_assert_float_eq(fltmax, fltmax2);
}


START_TEST(fl_to_dc_5) {
  float number = -0.0000123456789;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1234568, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(1, s21_getSign(decimal_check));
  ck_assert_uint_eq(11, s21_getScale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_6) {
  float number = 0.0000123456789;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1234568, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(11, s21_getScale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_8) {
  float number = 1234567890.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1234568000, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(0, s21_getScale(decimal_check));
}
END_TEST
*/
START_TEST(fl_to_dc_7) {
  float number = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(0, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(0, s21_getScale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_9) {
  float number = INFINITY;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(0, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, s21_getSign(decimal_check));
  ck_assert_uint_eq(0, s21_getScale(decimal_check));
}
START_TEST(dc_to_fl_1) {
  float number = 1.0;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(dc_to_fl_2) {
  float number = 0.1;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-1);
}
END_TEST
START_TEST(dc_to_fl_3) {
  float number = -0.1;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-1);
}
END_TEST
START_TEST(dc_to_fl_4) {
  float number = 0.0;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(dc_to_fl_5) {
  float number = 0.0123456789;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(the_most_important_tests) {
  s21_expended number = ZERO_EXPENDED;
  s21_setBitGlobalExp(&number, mantissa_six, 1);
  s21_singleScaleChangeExpIncr(&number, 25);
  s21_setScaleExp(&number, 15);
  s21_singleScaleChangeExpDecr(&number, -5);
  s21_decimal number2 = ZERO_DECIMAL;
  s21_getBitGlobal(number2, 100);
  s21_setBitGlobal(&number2, 1, 5);
  s21_setBitGlobal(&number2, 100, 1);
  s21_setSign(&number2, 5);
  s21_setScale(&number2, -5);
  s21_setScale(&number2, 55);
  s21_setScale(&number2, 28);
  s21_increaseScale(&number2);
  s21_setScale(&number2, 0);
  s21_decreaseScale(&number2);
  s21_getBitGlobalExp(number, mantissa_six + 1);
  s21_setBitGlobalExp(&number, 5, 5);
  s21_setBitGlobalExp(&number, 1000, 1);
  s21_setSignExp(&number, 5);
  s21_setSignExp(&number, 1);
  s21_invertSignExp(&number);
  s21_leftShiftExp(&number, -5);
  s21_rightShiftExp(&number, -5);
  s21_setScaleExp(&number, SCALE_MAX_EXP);
  s21_increaseScaleExp(&number);
  s21_setScaleExp(&number, 0);
  s21_decreaseScaleExp(&number);
  float a = 0;
  s21_from_float_to_decimal(a, NULL);
}
END_TEST
START_TEST(s21_add_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_5) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000011110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;

  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000010011101100000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000101110100011001110100011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000011111010011101111100100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110010;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001100110100101000000111001000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111010000000000000000000;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00111111011101000111010111001010;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000001010;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110001001010101101101011101101;
  origin.bits[1] = 0b00101110001111001110000111111000;
  origin.bits[2] = 0b10110000001111101110111101101101;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -545454512454545.35265454545645; 545454512454550.70530909091290 src2
  // = -5.352654545456454545645464;
  src1.bits[0] =
      0b10000010111000100101101011101101;  // 545454512454550.70530909091290
                                           // 4545645464
  src1.bits[1] =
      0b11111001111010000010010110101101;  // 79228162514264337593543950335
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;  // 13
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;  // 24
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10110110001010011011010111011010;
  origin.bits[1] = 0b11111001111010100000110001111111;
  origin.bits[2] = 0b10110000001111101111000010010100;
  origin.bits[3] = 0b10000000000011100000000000000000;  // 14
  // s21_printDecimalBin(result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_18) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_19) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b00000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_20) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10010010000001100111100010100101;
  origin.bits[1] = 0b10001011011010100100100011011111;
  origin.bits[2] = 0b00011100010100011001001100010001;
  origin.bits[3] = 0b00000000000100010000000000000000;

  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_21) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10010010000001100111100010100101;
  origin.bits[1] = 0b10001011011010100100100011011111;
  origin.bits[2] = 0b00011100010100011001001100010001;
  origin.bits[3] = 0b10000000000100010000000000000000;

  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_22) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b10000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_27) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01100010111100011011000010101001;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00110111111111010001010100111010;
  origin.bits[1] = 0b00000000000111110100000111110010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_29) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10011010010111001101001011101010;
  origin.bits[1] = 0b10111110010100100100110100010011;
  origin.bits[2] = 0b00000000000010101001000111100111;
  origin.bits[3] = 0b00000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010101111011100000000010001100;
  origin.bits[1] = 0b01111000000001011001100110101101;
  origin.bits[2] = 0b00011111101010011000001000100010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_31) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110000110111010100000010001101;
  origin.bits[1] = 0b01011010100111011110001100001010;
  origin.bits[2] = 0b00100111111010111100110001011010;
  origin.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_32) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;
  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10101111000101110100011110110111;
  origin.bits[1] = 0b01100110100011011000001100010111;
  origin.bits[2] = 0b00011100011001100111011011000001;
  origin.bits[3] = 0b00000000000010000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_33) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_34) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10000110010000000000000011011011;
  origin.bits[1] = 0b00110010000100100110010100111000;
  origin.bits[2] = 0b01101000011100010101100000100011;
  origin.bits[3] = 0b00000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_36) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_38) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_44) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 546378;
  // src2 = 0;
  src1.bits[0] = 0b00000000000010000101011001001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000101011001001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_45) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8976545415646545.5746845454;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11011101111000010000101100001110;
  src2.bits[1] = 0b00000101010000010110101000000010;
  src2.bits[2] = 0b00000000010010100100000010010011;
  src2.bits[3] = 0b00000000000010100000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11011101111000010000101100001110;
  origin.bits[1] = 0b00000101010000010110101000000010;
  origin.bits[2] = 0b00000000010010100100000010010011;
  origin.bits[3] = 0b00000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_49) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0;
  // src2 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_50) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_add_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_less_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST
START_TEST(s21_less_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST
START_TEST(s21_less_3_zero) {
  s21_decimal first = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST
START_TEST(s21_less_4_zero) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST
START_TEST(s21_less_5_len_int_part) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST
START_TEST(s21_less_6_len_int_part_positive) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000011000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000101000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST
START_TEST(s21_less_8_value_int_part_positive) {
  s21_decimal first = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST
START_TEST(s21_less_9_value_fract_part_positive) {
  s21_decimal first = {{4412, 5775, 1254, 0b00000000000010000000000000000000}};
  s21_decimal second = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST
START_TEST(s21_less_10_max_int_positive) {
  s21_decimal first = {
      {2147483646, 2147483647, 2147483647, 0b00000000000001110000000000000000}};
  s21_decimal second = {
      {2147483647, 2147483647, 2147483647, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST
START_TEST(s21_less_11_max_int_negative) {
  s21_decimal first = {
      {2147483647, 2147483647, 2147483647, 0b10000000000001110000000000000000}};
  s21_decimal second = {
      {2147483646, 2147483647, 2147483647, 0b10000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST
START_TEST(s21_less_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_41) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_42) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_43) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_44) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_45) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_46) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_47) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_48) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_49) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_50) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST
START_TEST(s21_equal_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST
START_TEST(s21_equal_3_fraction) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST
START_TEST(s21_equal_4_sign) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_5_sign) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_6) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_7) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_8) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_9_ss) {
  s21_decimal first = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST
START_TEST(s21_equal_10) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_11_zero) {
  s21_decimal first = {{0, 0, 0, 0b11110100000000000010000111111110}};
  s21_decimal second = {{0, 0, 0, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST
START_TEST(s21_equal_12_value) {
  s21_decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_13_value) {
  s21_decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_14_value) {
  s21_decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST
START_TEST(s21_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_41) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_43) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_44) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_45) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_46) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_47) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_48) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_49) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_50) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_51) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_52) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_53) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_equal_54) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_1_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST
START_TEST(s21_not_equal_2_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST
START_TEST(s21_not_equal_3_fraction_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST
START_TEST(s21_not_equal_4_sign_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_5_sign_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_6_1) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_7_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_8_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_9_ss_1) {
  s21_decimal first = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST
START_TEST(s21_not_equal_10_1) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_11_zero_1) {
  s21_decimal first = {{0, 0, 0, 0b11110100000000000010000111111110}};
  s21_decimal second = {{0, 0, 0, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST
START_TEST(s21_not_equal_12_value_1) {
  s21_decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_13_value_1) {
  s21_decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_14_value_1) {
  s21_decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST
START_TEST(s21_not_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_not_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_less_or_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 434345343551615.00000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -796214545.3526545454564545456;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7961327845421.843434341378545;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 145752736456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b10001101100101011101000110000101;
  src2.bits[1] = 0b11000001100101010111000111101011;
  src2.bits[2] = 0b00000100101101011010001101101100;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -776890.75455454213415678965898;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -732123534337593543950335.12;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 123523543453453453.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 31231232456315.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 78987543557678337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754567488438.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514475768684753643;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.745754741;
  // src2 = 3.222212;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 434345343551615.00000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -796214545.3526545454564545456;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7961327845421.843434341378545;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 145752736456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b10001101100101011101000110000101;
  src2.bits[1] = 0b11000001100101010111000111101011;
  src2.bits[2] = 0b00000100101101011010001101101100;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -776890.75455454213415678965898;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -732123534337593543950335.12;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 123523543453453453.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 31231232456315.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 78987543557678337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_greater_or_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754567488438.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST
START_TEST(s21_div_1) {
  s21_decimal src1, src2, result, origin;
  // 30064771176
  // 3
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01010101010101010101010101111000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST
START_TEST(s21_div_2) {
  s21_decimal src1, src2, result, origin;
  // 32768
  // -2
  // -16384
  src1.bits[0] = 0b00000000000000001000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  origin.bits[0] = 0b00000000000000000100000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST
START_TEST(s21_div_3) {
  s21_decimal src1, src2, result, origin;
  // 32768
  // 2
  // 16384
  src1.bits[0] = 0b00000000000000001000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b00000000000000000100000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST
START_TEST(s21_div_4) {
  s21_decimal src1, src2, result, origin;
  // -30064771176
  // 2
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b10000000000000000000000000110100;
  origin.bits[1] = 0b00000000000000000000000000000011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST
START_TEST(s21_div_5) {
  s21_decimal src1, src2, result, origin;
  // 0
  // 0.015
  // 0
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST
START_TEST(s21_mul_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00011100110011110011101011000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010111010001100111010001101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010011100100010101101110010110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110001;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11100110011101111000010101001111;
  origin.bits[1] = 0b00000000000000000000000000000110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000110011101000101101010011110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00111001100010111010010101100001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00110000111000101100110101010110;
  origin.bits[1] = 0b11011110111001111111001101111011;
  origin.bits[2] = 0b01100000001010101111111001001101;
  origin.bits[3] = 0b10000000000001100000000000000000;

  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110001110011111110010111001111;
  origin.bits[1] = 0b01000100010011101101011110011001;
  origin.bits[2] = 0b01011110010101101001110000011100;
  origin.bits[3] = 0b00000000000011010000000000000000;

  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_18) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  // ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_19) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653; //1082152051625666456.1283338477
  // 825345668179233410365789938
  src1.bits[0] =
      0b10010001000010101111010011001010;  // 79228162514264337593543950335
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;  // 21
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;  // 16
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001010010011001000011101110;
  origin.bits[1] = 0b10101010100001010100111110001111;
  origin.bits[2] = 0b00100010111101110101101000011010;
  origin.bits[3] = 0b00000000000010100000000000000000;  // 10
  ck_assert_int_eq(value_type_result, value_type_origin);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
}
END_TEST
START_TEST(s21_mul_20) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001010010011001000011101110;
  origin.bits[1] = 0b10101010100001010100111110001111;
  origin.bits[2] = 0b00100010111101110101101000011010;
  origin.bits[3] = 0b10000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_21) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001010010011001000011101110;
  origin.bits[1] = 0b10101010100001010100111110001111;
  origin.bits[2] = 0b00100010111101110101101000011010;
  origin.bits[3] = 0b10000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_22) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001010010011001000011101110;
  origin.bits[1] = 0b10101010100001010100111110001111;
  origin.bits[2] = 0b00100010111101110101101000011010;
  origin.bits[3] = 0b00000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_27) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011111001100010111011110111010;
  origin.bits[1] = 0b01000100111111001101101110110001;
  origin.bits[2] = 0b00000001101011100011011100011110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000100010110100111001000111001;
  origin.bits[1] = 0b01100100100011011110110011010011;
  origin.bits[2] = 0b00000000000001001101011111010011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_29) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10000010010010011010001110000110;
  origin.bits[1] = 0b00001010000101010010010001010111;
  origin.bits[2] = 0b01011010001111101011111001101000;
  origin.bits[3] = 0b00000000000110110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10100010001001111101100000001001;
  origin.bits[1] = 0b01100011000100011111011101101010;
  origin.bits[2] = 0b01000100010010101001011110101001;
  origin.bits[3] = 0b00000000000000110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_31) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;       //28
  // src2 = 0.68985125146545154;                  //17
  src1.bits[0] =
      0b00001011000011110111000010001101;  // 0.37641495299438636300394218906
                                           // 035023250100969
  src1.bits[1] =
      0b10010110101100000101100101010001;  //  79228162514264337593543950335
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] =
      0b00000000000111000000000000000000;  //    37641495299438636300394218906
                                           //    29
  src2.bits[0] =
      0b00010111001001010100110000000010;  //    0.3764149529943863630039421891
                                           //    28
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00101101101011010001001111000011;
  origin.bits[1] = 0b11100101011100100000101001000011;
  origin.bits[2] = 0b00001100001010011010000110101010;
  origin.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(value_type_result, value_type_origin);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
}
END_TEST
START_TEST(s21_mul_32) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;
  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00101100010001000110001011111110;
  origin.bits[1] = 0b10001111111010010000010001010010;
  origin.bits[2] = 0b11011100001110110011010101110011;
  origin.bits[3] = 0b10000000000010010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_33) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_mul_49) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0000 0000 0000 0000 0000 00000 001;
  // src2 = 0.01;
  src1.bits[0] =
      0b00000000000000000000000000000001;  // 0.000000000000000000000000000001
                                           // //30
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000010;  // 28

  ck_assert_int_eq(value_type_result, value_type_origin);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
}
END_TEST
START_TEST(s21_mul_50) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.00000000000000000005;
  // src2 = 0.0000000000345;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101000000000000000000;
  src2.bits[0] = 0b00000000000000000000000101011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000011010000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000010;
  ck_assert_int_eq(value_type_result, value_type_origin);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST
START_TEST(s21_mul_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0000000000000000000000001567;
  // src2 = 0.000800090769;
  src1.bits[0] = 0b00000000000000000000011000011111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00101111101100000110101010010001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000011000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
START_TEST(s21_mul_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 =
  // src2 =
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 1;

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000001;
  ck_assert_int_eq(value_type_result, value_type_origin);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}

END_TEST
START_TEST(s21_round_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_5) {
  s21_decimal src, origin, result;
  // src = -0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_6) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_9) {
  s21_decimal src, origin, result;
  // src = 65658654.59;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 65658655;
  origin.bits[0] = 0b00000011111010011101111100011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_10) {
  s21_decimal src, origin, result;
  // src = -364748.110;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -364748;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_11) {
  s21_decimal src, origin, result;
  // src = 1.9874565432111;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_12) {
  s21_decimal src, origin, result;
  // src = -98.78798789312;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -99;
  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_13) {
  s21_decimal src, origin, result;
  // src = 999999999999999999911.3;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 999999999999999999911;
  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_14) {
  s21_decimal src, origin, result;
  // src = -545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_15) {
  s21_decimal src, origin, result;
  // src = 545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_16) {
  s21_decimal src, origin, result;
  // src = 7961327845421.879754123131254;
  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 7961327845422;
  origin.bits[0] = 0b10100100000111100100000000101110;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_17) {
  s21_decimal src, origin, result;
  // src = 12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_18) {
  s21_decimal src, origin, result;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_19) {
  s21_decimal src, origin, result;
  // src = 87654323456.9876545678987653;
  src.bits[0] = 0b00010001110011011101000110000101;
  src.bits[1] = 0b11110101101111000110111111000000;
  src.bits[2] = 0b00000010110101010000111100111111;
  src.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 87654323457;
  origin.bits[0] = 0b01101000100110101101010100000001;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_20) {
  s21_decimal src, origin, result;
  // src = 336565445454313.859865545;
  src.bits[0] = 0b00111110111111000101101111001001;
  src.bits[1] = 0b00111111110101011110000010001011;
  src.bits[2] = 0b00000000000000000100011101000101;
  src.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 336565445454314;
  origin.bits[0] = 0b10111111110100011110100111101010;
  origin.bits[1] = 0b00000000000000010011001000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_21) {
  s21_decimal src, origin, result;
  // src = -15456451234534;
  src.bits[0] = 0b10111100010010010000101011100110;
  src.bits[1] = 0b00000000000000000000111000001110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -15456451234534;
  origin.bits[0] = 0b10111100010010010000101011100110;
  origin.bits[1] = 0b00000000000000000000111000001110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_22) {
  s21_decimal src, origin, result;
  // src = -0.42354543545;
  src.bits[0] = 0b11011100100001110000101110111001;
  src.bits[1] = 0b00000000000000000000000000001001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_23) {
  s21_decimal src, origin, result;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_round_24) {
  s21_decimal src, origin, result;
  // src = 2.7986531268974139743;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_5) {
  s21_decimal src, origin, result;
  // src = -0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_6) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 4;
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_9) {
  s21_decimal src, origin, result;
  // src = 65658654.59;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 65658654;
  origin.bits[0] = 0b00000011111010011101111100011110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_10) {
  s21_decimal src, origin, result;
  // src = -364748.110;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -364749;
  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_11) {
  s21_decimal src, origin, result;
  // src = 1.9874565432111;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_12) {
  s21_decimal src, origin, result;
  // src = -98.78798789312;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -99;
  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_13) {
  s21_decimal src, origin, result;
  // src = 999999999999999999911.3;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 999999999999999999911;
  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_14) {
  s21_decimal src, origin, result;
  // src = -545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -545454512454546;
  origin.bits[0] = 0b10000110011101001011101110010010;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_15) {
  s21_decimal src, origin, result;
  // src = 545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_16) {
  s21_decimal src, origin, result;
  // src = 7961327845421.879754123131254;
  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 7961327845421;
  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_17) {
  s21_decimal src, origin, result;
  // src = 12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_18) {
  s21_decimal src, origin, result;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_19) {
  s21_decimal src, origin, result;
  // src = 87654323456.9876545678987653;
  src.bits[0] = 0b00010001110011011101000110000101;
  src.bits[1] = 0b11110101101111000110111111000000;
  src.bits[2] = 0b00000010110101010000111100111111;
  src.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 87654323456;
  origin.bits[0] = 0b01101000100110101101010100000000;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_20) {
  s21_decimal src, origin, result;
  // src = 336565445454313.859865545;
  src.bits[0] = 0b00111110111111000101101111001001;
  src.bits[1] = 0b00111111110101011110000010001011;
  src.bits[2] = 0b00000000000000000100011101000101;
  src.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 336565445454313;
  origin.bits[0] = 0b10111111110100011110100111101001;
  origin.bits[1] = 0b00000000000000010011001000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_21) {
  s21_decimal src, origin, result;
  // src = -15456451234534;
  src.bits[0] = 0b10111100010010010000101011100110;
  src.bits[1] = 0b00000000000000000000111000001110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -15456451234534;
  origin.bits[0] = 0b10111100010010010000101011100110;
  origin.bits[1] = 0b00000000000000000000111000001110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_22) {
  s21_decimal src, origin, result;
  // src = -0.42354543545;
  src.bits[0] = 0b11011100100001110000101110111001;
  src.bits[1] = 0b00000000000000000000000000001001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_23) {
  s21_decimal src, origin, result;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_floor_24) {
  s21_decimal src, origin, result;
  // src = 2.7986531268974139743;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_sub_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 5;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 6;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_5) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0;
  // src2 = 5;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000110010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 787891;
  // src2 = 238471;
  src1.bits[0] = 0b00000000000011000000010110110011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000111010001110000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000110001000101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9;
  // src2 = 18571145;
  src1.bits[0] = 0b00000000000000000000000000001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000110110101111110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000110110101111110000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1849687;
  // src2 = 6;
  src1.bits[0] = 0b00000000000111000011100101010111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000111000011100101010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -3187878;
  // src2 = 1;
  src1.bits[0] = 0b00000000001100001010010010100110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000001100001010010010100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 18768768;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000111100110001110000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000111100110001101111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -2168564564;
  // src2 = -9;
  src1.bits[0] = 0b10000001010000011010101101010100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10000001010000011010101101001011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111110;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 3556877454;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11010100000000011010010010001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10110111111011111001001001101010;
  origin.bits[1] = 0b11111111111111111111111111110111;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -54896651557845.352654545456455;
  // src2 = 21465;
  src1.bits[0] = 0b01110001100100011000110101000111;
  src1.bits[1] = 0b00001111010011100000001101011111;
  src1.bits[2] = 0b10110001011000010111001000100100;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000101001111011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01111001010101000000110101000111;
  origin.bits[1] = 0b00111001001100010000001100100101;
  origin.bits[2] = 0b10110001011000010111001000100101;
  origin.bits[3] = 0b10000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_19) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b10000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_20) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b00000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_21) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10010010000001100111100010100101;
  origin.bits[1] = 0b10001011011010100100100011011111;
  origin.bits[2] = 0b00011100010100011001001100010001;
  origin.bits[3] = 0b00000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_22) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  // ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  // ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  // ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_27) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11101000101010001011011101111000;
  origin.bits[1] = 0b00000000000111110100000111110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_29) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010010100100100111101010001100;
  origin.bits[1] = 0b10011110100111100111000100000100;
  origin.bits[2] = 0b00011111101010011000000100111000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_32) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -1;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_33) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00001110100111001011111100100101;
  origin.bits[1] = 0b11011111010111101000100010100000;
  origin.bits[2] = 0b01101000011100010101100000011011;
  origin.bits[3] = 0b00000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_34) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -784515454.7989898652154545652;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b10110001001110110100010111110100;
  src1.bits[1] = 0b00111000100000111010110010000001;
  src1.bits[2] = 0b00011001010110010101110000011000;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00101100010111011001101101001111;
  origin.bits[1] = 0b11111000000111110000000110111111;
  origin.bits[2] = 0b10111011010111111101000100011001;
  origin.bits[3] = 0b00000000000010110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_35) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b00000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_39) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  // ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_48) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0;
  // src2 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  // ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_49) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_50) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(s21_sub_53) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  //  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST
START_TEST(int_to_dec_1) {
  // printf("int_to_dec_1\n");
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_2) {
  // printf("int_to_dec_2\n");
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_3) {
  // printf("int_to_dec_3\n");
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_4) {
  // printf("int_to_dec_4\n");
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_5) {
  // printf("int_to_dec_5\n");
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_6) {
  // printf("int_to_dec_6\n");
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_7) {
  // printf("int_to_dec_7\n");
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_8) {
  // printf("int_to_dec_8\n");
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_9) {
  // printf("int_to_dec_9\n");
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_10) {
  // printf("int_to_dec_10\n");
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_11) {
  // printf("int_to_dec_11\n");
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_12) {
  // printf("int_to_dec_12\n");
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_13) {
  // printf("int_to_dec_13\n");
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_14) {
  // printf("int_to_dec_14\n");
  s21_decimal result, origin;
  int src = -127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_15) {
  // printf("int_to_dec_15\n");
  s21_decimal result, origin;
  int src = 34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_16) {
  // printf("int_to_dec_16\n");
  s21_decimal result, origin;
  int src = -34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_17) {
  // printf("int_to_dec_17\n");
  s21_decimal result, origin;
  int src = 999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_18) {
  // printf("int_to_dec_18\n");
  s21_decimal result, origin;
  int src = -999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_19) {
  // printf("int_to_dec_19\n");
  s21_decimal result, origin;
  int src = -3254754;
  origin.bits[0] = 0b00000000001100011010100111100010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_20) {
  // printf("int_to_dec_20\n");
  s21_decimal result, origin;
  int src = 3436425;
  origin.bits[0] = 0b00000000001101000110111110001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(int_to_dec_21) {
  // printf("int_to_dec_21\n");
  s21_decimal result, origin;
  int src = 222222222;
  origin.bits[0] = 0b00001101001111101101011110001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_int_1) {
  // printf("dec_to_int_1\n");
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 5;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_2) {
  // printf("dec_to_int_2\n");
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 3;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_3) {
  // printf("dec_to_int_3\n");
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_4) {
  // printf("dec_to_int_4\n");
  s21_decimal src;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int result = 0;
  int origin = -2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_5) {
  // printf("dec_to_int_5\n");
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_7) {
  // printf("dec_to_int_7\n");
  s21_decimal src;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int result = 0;
  int origin = 652;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_8) {
  // printf("dec_to_int_8\n");
  s21_decimal src;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int result = 0;
  int origin = 4;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_9) {
  // printf("dec_to_int_9\n");
  s21_decimal src;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int origin = 65658654;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_10) {
  // printf("dec_to_int_10\n");
  s21_decimal src;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int result = 0;
  int origin = -364748;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_11) {
  // printf("dec_to_int_11\n");
  s21_decimal src;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int result = 0;
  int origin = 1;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_12) {
  // printf("dec_to_int_12\n");
  s21_decimal src;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int result = 0;
  int origin = -98;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_13) {
  // printf("dec_to_int_13\n");
  s21_decimal src;
  src.bits[0] = 0b00111011100110101100100111111001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 99999999;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_14) {
  // printf("dec_to_int_14\n");
  s21_decimal src;
  src.bits[0] = 0b11001010011010010001110011000010;
  src.bits[1] = 0b10011001110101001010110100100110;
  src.bits[2] = 0b10110000001111100010111010011101;
  src.bits[3] = 0b10000000000101110000000000000000;
  int result = 0;
  int origin = -545445;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_15) {
  // printf("dec_to_int_15\n");
  s21_decimal src;
  src.bits[0] = 0b11101010011100001110100101000111;
  src.bits[1] = 0b10100010011001110000111100001010;
  src.bits[2] = 0b10110000001111101111000100010000;
  src.bits[3] = 0b00000000000101100000000000000000;
  int result = 0;
  int origin = 5454545;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_16) {
  // printf("dec_to_int_16\n");
  s21_decimal src;
  src.bits[0] = 0b11101010001011100110110001010100;
  src.bits[1] = 0b00100111000110111110101011111001;
  src.bits[2] = 0b00011001101111000001110101101001;
  src.bits[3] = 0b00000000000101000000000000000000;
  int result = 0;
  int origin = 79645421;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_17) {
  // printf("dec_to_int_17\n");
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int result = 0;
  int origin = 12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_18) {
  // printf("dec_to_int_18\n");
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int result = 0;
  int origin = -12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_19) {
  // printf("dec_to_int_19\n");
  s21_decimal src;
  src.bits[0] = 0b10011100101100011101000110000101;
  src.bits[1] = 0b01100001100101011101011101110110;
  src.bits[2] = 0b00000000000000000000000011101010;
  src.bits[3] = 0b00000000000100000000000000000000;
  int result = 0;
  int origin = 432356;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_20) {
  // printf("dec_to_int_20\n");
  s21_decimal src;
  src.bits[0] = 0b01100001011111010111001111001001;
  src.bits[1] = 0b00000000100111100100000111010001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010010000000000000000;
  int result = 0;
  int origin = 44545413;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_21) {
  // printf("dec_to_int_21\n");
  s21_decimal src;
  src.bits[0] = 0b01011100000110001011011001101010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int result = 0;
  int origin = -1545123434;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_23) {
  // printf("dec_to_int_23\n");
  s21_decimal src;
  src.bits[0] = 0b10101001101110110110011111111111;
  src.bits[1] = 0b00001010111111101100000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011000000000000000000;
  int result = 0;
  int origin = 792281;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_int_24) {
  // printf("dec_to_int_24\n");
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int result = 0;
  int origin = 2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST
START_TEST(dec_to_float_1) {
  // printf("dec_to_float_1\n");
  s21_decimal number;
  // decimal: 2.0
  // float: 2
  // int: 1073741824
  number.bits[0] = 0b00000000000000000000000000010100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000010000000000000000;
  int result_int = 1073741824;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_2) {
  // printf("dec_to_float_2\n");
  s21_decimal number;
  // decimal: -0.8
  // float: -0.8
  // int: -1085485875
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -1085485875;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_3) {
  // printf("dec_to_float_3\n");
  s21_decimal number;
  // decimal: 0
  // float: 0
  // int: 0
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_4) {
  // printf("dec_to_float_4\n");
  s21_decimal number;
  // decimal: 1
  // float: 1
  // int: 1065353216
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1065353216;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_5) {
  // printf("dec_to_float_5\n");
  s21_decimal number;
  // decimal: 0.0
  // float: 0
  // int: -2147483648
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_6) {
  // printf("dec_to_float_6\n");
  s21_decimal number;
  // decimal: -1.75
  // float: -1.75
  // int: -1075838976
  number.bits[0] = 0b00000000000000000000000010101111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000100000000000000000;
  int result_int = -1075838976;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_7) {
  // printf("dec_to_float_7\n");
  s21_decimal number;
  // decimal: 6521
  // float: 6521
  // int: 1170982912
  number.bits[0] = 0b00000000000000000001100101111001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1170982912;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_8) {
  // printf("dec_to_float_8\n");
  s21_decimal number;
  // decimal: 4
  // float: 4
  // int: 1082130432
  number.bits[0] = 0b00000000000000000000000000000100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1082130432;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_9) {
  // printf("dec_to_float_9\n");
  s21_decimal number;
  // decimal: 65658654
  // float: 6.565866E+07
  // int: 1283094472
  number.bits[0] = 0b00000011111010011101111100011110;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1283094472;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_10) {
  // printf("dec_to_float_10\n");
  s21_decimal number;
  // decimal: -364748
  // float: -364748
  // int: -927852160
  number.bits[0] = 0b00000000000001011001000011001100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -927852160;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_11) {
  // printf("dec_to_float_11\n");
  s21_decimal number;
  // decimal: 0.003
  // float: 0.003
  // int: 994352038
  number.bits[0] = 0b00000000000000000000000000000011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000110000000000000000;
  int result_int = 994352038;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_12) {
  // printf("dec_to_float_12\n");
  s21_decimal number;
  // decimal: -9878798789
  // float: -9.878798E+09
  // int: -804047712
  number.bits[0] = 0b01001100110100101000000111000101;
  number.bits[1] = 0b00000000000000000000000000000010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -804047712;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_13) {
  // printf("dec_to_float_13\n");
  s21_decimal number;
  // decimal: 9959999999999999999
  // float: 9.96E+18
  // int: 1594505479
  number.bits[0] = 0b11001010111000111111111111111111;
  number.bits[1] = 0b10001010001110010000011100111010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1594505479;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_14) {
  // printf("dec_to_float_14\n");
  s21_decimal number;
  // decimal: 18446744073709551615
  // float: 1.844674E+19
  // int: 1602224128
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1602224128;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_17) {
  // printf("dec_to_float_17\n");
  s21_decimal number;
  // decimal: -5454545545352456454545645464
  // float: -5.454546E+27
  // int: -309526744
  number.bits[0] = 0b10001000100000001001111110011000;
  number.bits[1] = 0b10000010011101100000001010011001;
  number.bits[2] = 0b00010001100111111110010011110010;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -309526744;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_18) {
  // printf("dec_to_float_18\n");
  s21_decimal number;
  // decimal: 79228162514264337593543950335
  // float: 7.922816E+28
  // int: 1870659584
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1870659584;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_19) {
  // printf("dec_to_float_19\n");
  s21_decimal number;
  // decimal: 1234.5677987654345678987654346
  // float: 1234.568
  // int: 1150964267
  number.bits[0] = 0b10010001000010101111010011001010;
  number.bits[1] = 0b11000000010001011101010111110010;
  number.bits[2] = 0b00100111111001000001101100000000;
  number.bits[3] = 0b00000000000110010000000000000000;
  int result_int = 1150964267;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_20) {
  // printf("dec_to_float_20\n");
  s21_decimal number;
  // decimal: -123458677.98765434567898765435
  // float: -1.234587E+08
  // int: -856982897
  number.bits[0] = 0b10111001000000010001100001111011;
  number.bits[1] = 0b01101110100110001001011011101100;
  number.bits[2] = 0b00100111111001000100001100110010;
  number.bits[3] = 0b10000000000101000000000000000000;
  int result_int = -856982897;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_21) {
  // printf("dec_to_float_21\n");
  s21_decimal number;
  // decimal: 123445677.98765434567898765435
  // float: 1.234457E+08
  // int: 1290499126
  number.bits[0] = 0b00110100100000010001100001111011;
  number.bits[1] = 0b01001010011100100010011000011110;
  number.bits[2] = 0b00100111111000110010111111101001;
  number.bits[3] = 0b00000000000101000000000000000000;
  int result_int = 1290499126;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_22) {
  // printf("dec_to_float_22\n");
  s21_decimal number;
  // decimal: -12345677.987654533456789876543
  // float: -1.234568E+07
  // int: -885235378
  number.bits[0] = 0b11111110001111011010111100111111;
  number.bits[1] = 0b11000000010001101000000010111010;
  number.bits[2] = 0b00100111111001000001101100000000;
  number.bits[3] = 0b10000000000101010000000000000000;
  int result_int = -885235378;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_23) {
  // printf("dec_to_float_23\n");
  s21_decimal number;
  // decimal: 0.0000000000000000001
  // float: 1E-19
  // int: 535567946
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000100110000000000000000;
  int result_int = 535567946;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_24) {
  // printf("dec_to_float_24\n");
  s21_decimal number;
  // decimal: 0.0000000000000000000000000001
  // float: 1E-28
  // int: 285050806
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000111000000000000000000;
  int result_int = 285050806;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_25) {
  // printf("dec_to_float_25\n");
  s21_decimal number;
  // decimal: 0.0000000000000000000000000000
  // float: 0
  // int: -2147483648
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000111000000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_26) {
  // printf("dec_to_float_26\n");
  s21_decimal number;
  // decimal: -79228162514264337593543950335
  // float: -7.922816E+28
  // int: -276824064
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_27) {
  // printf("dec_to_float_27\n");
  s21_decimal number;
  // decimal: -792.28162514264337593543950335
  // float: -792.2816
  // int: -1002040826
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000110100000000000000000;
  int result_int = -1002040826;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_28) {
  // printf("dec_to_float_28\n");
  s21_decimal number;
  // decimal: -79228162514264337593543950335
  // float: -7.922816E+28
  // int: -276824064
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_29) {
  // printf("dec_to_float_29\n");
  s21_decimal number;
  // decimal: 2.7986531268974139743
  // float: 2.798653
  // int: 1077091618
  number.bits[0] = 0b11111110100100001101100101011111;
  number.bits[1] = 0b10000100011001000010000111101000;
  number.bits[2] = 0b00000000000000000000000000000001;
  number.bits[3] = 0b00000000000100110000000000000000;
  int result_int = 1077091618;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_31) {
  // printf("dec_to_float_31\n");
  s21_decimal number;
  // decimal: 5.4564654654864768465454654846
  // float: 5.456465
  // int: 1085184861
  number.bits[0] = 0b01101110100110100110010101111110;
  number.bits[1] = 0b11100010111000110111110100101010;
  number.bits[2] = 0b10110000010011101101001100001111;
  number.bits[3] = 0b00000000000111000000000000000000;
  int result_int = 1085184861;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_33) {
  // printf("dec_to_float_33\n");
  s21_decimal number;
  // decimal: -79228162514264337593543950330
  // float: -7.922816E+28
  // int: -276824064
  number.bits[0] = 0b11111111111111111111111111111010;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_34) {
  // printf("dec_to_float_34\n");
  s21_decimal number;
  // decimal: 32323465785678987654
  // float: 3.232346E+19
  // int: 1608534530
  number.bits[0] = 0b00000000111000111000000110000110;
  number.bits[1] = 0b11000000100101000000010011100000;
  number.bits[2] = 0b00000000000000000000000000000001;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1608534530;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_35) {
  // printf("dec_to_float_35\n");
  s21_decimal number;
  // decimal: -784510454.7989898652154545652
  // float: -7.845105E+08
  // int: -834991432
  number.bits[0] = 0b00110101111110110100010111110100;
  number.bits[1] = 0b10110111000111111011101111011100;
  number.bits[2] = 0b00011001010110010101000110000001;
  number.bits[3] = 0b10000000000100110000000000000000;
  int result_int = -834991432;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(dec_to_float_36) {
  // printf("dec_to_float_36\n");
  s21_decimal number;
  // decimal: 0.324524
  // float: 0.324524
  // int: 1051076610
  number.bits[0] = 0b00000000000001001111001110101100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000001100000000000000000;
  int result_int = 1051076610;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST
START_TEST(s21_from_float_to_decimal_4) {
  // printf("s21_from_float_to_decimal_4\n");
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST
// START_TEST(s21_from_float_to_decimal_6) {
////printf("s21_from_float_to_decimal_6\n");
// s21_decimal val;
// float a = NAN;
// int err_check = s21_from_float_to_decimal(a, &val);
// ck_assert_int_eq(err_check, 1);
// ck_assert_int_eq(val.bits[0], 0);
// ck_assert_int_eq(val.bits[1], 0);
// ck_assert_int_eq(val.bits[2], 0);
// ck_assert_int_eq(val.bits[3], 0);
//}
// END_TEST
START_TEST(s21_from_float_to_decimal_7) {
  // printf("s21_from_float_to_decimal_7\n");
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST
START_TEST(s21_negate_1) {
  // printf("s21_negate_1\n");
  s21_decimal src1, origin, result;
  // src1 = 2.1234;
  src1.bits[0] = 0b00000000000000000101001011110010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001000000000000000000;
  // origin = -2.1234;
  origin.bits[0] = 0b00000000000000000101001011110010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_2) {
  // printf("s21_negate_2\n");
  s21_decimal src1, origin, result;
  // src1 = 457.000001;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = -457.000001;
  origin.bits[0] = 0b00011011001111010100010001000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_3) {
  // printf("s21_negate_3\n");
  s21_decimal src1, origin, result;
  // src1 = 2.000;
  src1.bits[0] = 0b00000000000000000000011111010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  // origin = -2.000;
  origin.bits[0] = 0b00000000000000000000011111010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_4) {
  // printf("s21_negate_4\n");
  s21_decimal src1, origin, result;
  // src1 = 0.000000000000000000000000000;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  // origin = 0.000000000000000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000110110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_5) {
  // printf("s21_negate_5\n");
  s21_decimal src1, origin, result;
  // src1 = -3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_6) {
  // printf("s21_negate_6\n");
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = -2.222212;
  origin.bits[0] = 0b00000000001000011110100010000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_7) {
  // printf("s21_negate_7\n");
  s21_decimal src1, origin, result;
  // src1 = 2.22221200000001000;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = -2.22221200000001000;
  origin.bits[0] = 0b00000111100011111010001111101000;
  origin.bits[1] = 0b00000011000101010111110100000001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000100010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_8) {
  // printf("s21_negate_8\n");
  s21_decimal src1, origin, result;
  // src1 = 3.745754741;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  // origin = -3.745754741;
  origin.bits[0] = 0b11011111010000111010111001110101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000010010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_9) {
  // printf("s21_negate_9\n");
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = -2.222212;
  origin.bits[0] = 0b00000000001000011110100010000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_10) {
  // printf("s21_negate_10\n");
  s21_decimal src1, origin, result;
  // src1 = -364748;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = 364748;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_11) {
  // printf("s21_negate_11\n");
  s21_decimal src1, origin, result;
  // src1 = 987456543210.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -987456543210.0;
  origin.bits[0] = 0b00011001111101110000001100100100;
  origin.bits[1] = 0b00000000000000000000100011111011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_12) {
  // printf("s21_negate_12\n");
  s21_decimal src1, origin, result;
  // src1 = -9878798789.5867800;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = 9878798789.5867800;
  origin.bits[0] = 0b11001110100110111101100110011000;
  origin.bits[1] = 0b00000001010111101111011100100110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_13) {
  // printf("s21_negate_13\n");
  s21_decimal src1, origin, result;
  // src1 = 9999999999999999999;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -9999999999999999999;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_14) {
  // printf("s21_negate_14\n");
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -18446744073709551615;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_15) {
  // printf("s21_negate_15\n");
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615.0;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -18446744073709551615.0;
  origin.bits[0] = 0b11111111111111111111111111110110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_16) {
  // printf("s21_negate_16\n");
  s21_decimal src1, origin, result;
  // src1 = -796214545.3526545454564545456;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  // origin = 796214545.3526545454564545456;
  origin.bits[0] = 0b10111111111111101001001110110000;
  origin.bits[1] = 0b11101010111111101111100111101000;
  origin.bits[2] = 0b00011001101110100010000111100001;
  origin.bits[3] = 0b00000000000100110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_17) {
  // printf("s21_negate_17\n");
  s21_decimal src1, origin, result;
  // src1 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  // origin = 545454512454545.35265454545645;
  origin.bits[0] = 0b10000010111000100101101011101101;
  origin.bits[1] = 0b11111001111010000010010110101101;
  origin.bits[2] = 0b10110000001111101111000010010100;
  origin.bits[3] = 0b00000000000011100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_18) {
  // printf("s21_negate_18\n");
  s21_decimal src1, origin, result;
  // src1 = -7961327845421.843434341378545;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  // origin = 7961327845421.843434341378545;
  origin.bits[0] = 0b11110011001100111010100111110001;
  origin.bits[1] = 0b01001011001101011000000011010000;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_19) {
  // printf("s21_negate_19\n");
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = -12345677.987654345678987654346;
  origin.bits[0] = 0b10010001000010101111010011001010;
  origin.bits[1] = 0b11000000010001011101010111110010;
  origin.bits[2] = 0b00100111111001000001101100000000;
  origin.bits[3] = 0b10000000000101010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_20) {
  // printf("s21_negate_20\n");
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = -12345677.987654345678987654346;
  origin.bits[0] = 0b10010001000010101111010011001010;
  origin.bits[1] = 0b11000000010001011101010111110010;
  origin.bits[2] = 0b00100111111001000001101100000000;
  origin.bits[3] = 0b10000000000101010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_21) {
  // printf("s21_negate_21\n");
  s21_decimal src1, origin, result;
  // src1 = 87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = -87654323456.98765456789876530;
  origin.bits[0] = 0b10110010000010100010111100110010;
  origin.bits[1] = 0b10011001010111000101110110000000;
  origin.bits[2] = 0b00011100010100101001100001111111;
  origin.bits[3] = 0b10000000000100010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_22) {
  // printf("s21_negate_22\n");
  s21_decimal src1, origin, result;
  // src1 = -854764561465456456.9876545679;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  // origin = 854764561465456456.9876545679;
  origin.bits[0] = 0b11000100000001000100000010001111;
  origin.bits[1] = 0b01000000100100100110001100010101;
  origin.bits[2] = 0b00011011100111100111001001011101;
  origin.bits[3] = 0b00000000000010100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_23) {
  // printf("s21_negate_23\n");
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_24) {
  // printf("s21_negate_24\n");
  s21_decimal src1, origin, result;
  // src1 = -69.1234567;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = 69.1234567;
  origin.bits[0] = 0b00101001001100110110011100000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_25) {
  // printf("s21_negate_25\n");
  s21_decimal src1, origin, result;
  // src1 = 13436577854.000000000000;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  // origin = -13436577854.000000000000;
  origin.bits[0] = 0b00100110011110011110000000000000;
  origin.bits[1] = 0b01100101111110011111000000101100;
  origin.bits[2] = 0b00000000000000000000001011011000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_26) {
  // printf("s21_negate_26\n");
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_27) {
  // printf("s21_negate_27\n");
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_28) {
  // printf("s21_negate_28\n");
  s21_decimal src1, origin, result;
  // src1 = 665464545;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -665464545;
  origin.bits[0] = 0b00100111101010100010111011100001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_29) {
  // printf("s21_negate_29\n");
  s21_decimal src1, origin, result;
  // src1 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  // origin = -2.7986531268974139743;
  origin.bits[0] = 0b11111110100100001101100101011111;
  origin.bits[1] = 0b10000100011001000010000111101000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b10000000000100110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_30) {
  // printf("s21_negate_30\n");
  s21_decimal src1, origin, result;
  // src1 = -2156878451.8547640000000000;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  // origin = 2156878451.8547640000000000;
  origin.bits[0] = 0b10010011100100010011000000000000;
  origin.bits[1] = 0b00100110110100100010010100001001;
  origin.bits[2] = 0b00000000000100011101011101011110;
  origin.bits[3] = 0b00000000000100000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_31) {
  // printf("s21_negate_31\n");
  s21_decimal src1, origin, result;
  // src1 = 0.5456465465486476846545465485;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  // origin = -0.5456465465486476846545465485;
  origin.bits[0] = 0b00001011000011110111000010001101;
  origin.bits[1] = 0b10010110101100000101100101010001;
  origin.bits[2] = 0b00010001101000010111101110000001;
  origin.bits[3] = 0b10000000000111000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_32) {
  // printf("s21_negate_32\n");
  s21_decimal src1, origin, result;
  // src1 = -776890.75455454213415678965898;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  // origin = 776890.75455454213415678965898;
  origin.bits[0] = 0b11000010010111101111100010001010;
  origin.bits[1] = 0b01011100000101000111000011011000;
  origin.bits[2] = 0b11111011000001101110010110100011;
  origin.bits[3] = 0b00000000000101110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_33) {
  // printf("s21_negate_33\n");
  s21_decimal src1, origin, result;
  // src1 = -732123534337593543950335.12;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  // origin = 732123534337593543950335.12;
  origin.bits[0] = 0b11000011000110111111111110101000;
  origin.bits[1] = 0b10100001110111010100101100101110;
  origin.bits[2] = 0b00000000001111001000111101010001;
  origin.bits[3] = 0b00000000000000100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_34) {
  // printf("s21_negate_34\n");
  s21_decimal src1, origin, result;
  // src1 = 675432788976.5424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  // origin = -675432788976.5424354657687;
  origin.bits[0] = 0b10111110000100011000010110010111;
  origin.bits[1] = 0b11011001001111010001001011000110;
  origin.bits[2] = 0b00000000000001011001011001001000;
  origin.bits[3] = 0b10000000000011010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_35) {
  // printf("s21_negate_35\n");
  s21_decimal src1, origin, result;
  // src1 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  // origin = 579895323215489956.67897455465;
  origin.bits[0] = 0b11100110001001011001001101101001;
  origin.bits[1] = 0b00111000110110101110001010110100;
  origin.bits[2] = 0b10111011010111111101000100011110;
  origin.bits[3] = 0b00000000000010110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_36) {
  // printf("s21_negate_36\n");
  s21_decimal src1, origin, result;
  // src1 = 123523543453453453.0;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -123523543453453453.0;
  origin.bits[0] = 0b01001001011001111111110110000010;
  origin.bits[1] = 0b00010001001001000111000000010101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_37) {
  // printf("s21_negate_37\n");
  s21_decimal src1, origin, result;
  // src1 = 31231232456315.0;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -31231232456315.0;
  origin.bits[0] = 0b11100001001010100010000011001110;
  origin.bits[1] = 0b00000000000000010001110000001011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_38) {
  // printf("s21_negate_38\n");
  s21_decimal src1, origin, result;
  // src1 = 78987543557678337.5935439503;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  // origin = -78987543557678337.5935439503;
  origin.bits[0] = 0b00111011110001111000001010001111;
  origin.bits[1] = 0b00101001100010100010010001100011;
  origin.bits[2] = 0b00000010100011010101111010100001;
  origin.bits[3] = 0b10000000000010100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_39) {
  // printf("s21_negate_39\n");
  s21_decimal src1, origin, result;
  // src1 = -754567488438.97816770;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  // origin = 754567488438.97816770;
  origin.bits[0] = 0b01011010011001011000011011000010;
  origin.bits[1] = 0b00010111001011000011100101001001;
  origin.bits[2] = 0b00000000000000000000000000000100;
  origin.bits[3] = 0b00000000000010000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_40) {
  // printf("s21_negate_40\n");
  s21_decimal src1, origin, result;
  // src1 = -2.514475768684753643;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  // origin = 2.514475768684753643;
  origin.bits[0] = 0b10101100110010000011001011101011;
  origin.bits[1] = 0b00100010111001010011011001100011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000100100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_41) {
  // printf("s21_negate_41\n");
  s21_decimal src1, origin, result;
  // src1 = -0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  // origin = 0.0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_negate_42) {
  // printf("s21_negate_42\n");
  s21_decimal src1, origin, result;
  // src1 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -0.0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_1) {
  // printf("s21_truncate_1\n");
  s21_decimal src1, origin, result;
  // src1 = 2.1234;
  src1.bits[0] = 0b00000000000000000101001011110010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001000000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_2) {
  // printf("s21_truncate_2\n");
  s21_decimal src1, origin, result;
  // src1 = 457.000001;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 457;
  origin.bits[0] = 0b00000000000000000000000111001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_3) {
  // printf("s21_truncate_3\n");
  s21_decimal src1, origin, result;
  // src1 = 2.000;
  src1.bits[0] = 0b00000000000000000000011111010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_4) {
  // printf("s21_truncate_4\n");
  s21_decimal src1, origin, result;
  // src1 = 0.000000000000000000000000000;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_5) {
  // printf("s21_truncate_5\n");
  s21_decimal src1, origin, result;
  // src1 = -3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_6) {
  // printf("s21_truncate_6\n");
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_7) {
  // printf("s21_truncate_7\n");
  s21_decimal src1, origin, result;
  // src1 = 2.22221200000001000;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_8) {
  // printf("s21_truncate_8\n");
  s21_decimal src1, origin, result;
  // src1 = 3.745754741;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_9) {
  // printf("s21_truncate_9\n");
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_10) {
  // printf("s21_truncate_10\n");
  s21_decimal src1, origin, result;
  // src1 = -364748;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = -364748;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_11) {
  // printf("s21_truncate_11\n");
  s21_decimal src1, origin, result;
  // src1 = 987456543210.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 987456543210;
  origin.bits[0] = 0b11101000111111110001100111101010;
  origin.bits[1] = 0b00000000000000000000000011100101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_12) {
  // printf("s21_truncate_12\n");
  s21_decimal src1, origin, result;
  // src1 = -9878798789.5867800;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = -9878798789;
  origin.bits[0] = 0b01001100110100101000000111000101;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_13) {
  // printf("s21_truncate_13\n");
  s21_decimal src1, origin, result;
  // src1 = 9999999999999999999;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 9999999999999999999;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_14) {
  // printf("s21_truncate_14\n");
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 18446744073709551615;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_15) {
  // printf("s21_truncate_15\n");
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615.0;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 18446744073709551615;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_16) {
  // printf("s21_truncate_16\n");
  s21_decimal src1, origin, result;
  // src1 = -796214545.3526545454564545456;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  // origin = -796214545;
  origin.bits[0] = 0b00101111011101010100010100010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_17) {
  // printf("s21_truncate_17\n");
  s21_decimal src1, origin, result;
  // src1 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  // origin = -545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_18) {
  // printf("s21_truncate_18\n");
  s21_decimal src1, origin, result;
  // src1 = -7961327845421.843434341378545;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  // origin = -7961327845421;
  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_19) {
  // printf("s21_truncate_19\n");
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_20) {
  // printf("s21_truncate_20\n");
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_21) {
  // printf("s21_truncate_21\n");
  s21_decimal src1, origin, result;
  // src1 = 87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = 87654323456;
  origin.bits[0] = 0b01101000100110101101010100000000;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_22) {
  // printf("s21_truncate_22\n");
  s21_decimal src1, origin, result;
  // src1 = -854764561465456456.9876545679;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  // origin = -854764561465456456;
  origin.bits[0] = 0b00000100101111011011011101001000;
  origin.bits[1] = 0b00001011110111001011101111010111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_23) {
  // printf("s21_truncate_23\n");
  s21_decimal src1, origin, result;
  // src1 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_24) {
  // printf("s21_truncate_24\n");
  s21_decimal src1, origin, result;
  // src1 = -69.1234567;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = -69;
  origin.bits[0] = 0b00000000000000000000000001000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_25) {
  // printf("s21_truncate_25\n");
  s21_decimal src1, origin, result;
  // src1 = 13436577854.000000000000;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  // origin = 13436577854;
  origin.bits[0] = 0b00100000111000011110100000111110;
  origin.bits[1] = 0b00000000000000000000000000000011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_26) {
  // printf("s21_truncate_26\n");
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_27) {
  // printf("s21_truncate_27\n");
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_28) {
  // printf("s21_truncate_28\n");
  s21_decimal src1, origin, result;
  // src1 = 665464545;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 665464545;
  origin.bits[0] = 0b00100111101010100010111011100001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_29) {
  // printf("s21_truncate_29\n");
  s21_decimal src1, origin, result;
  // src1 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_30) {
  // printf("s21_truncate_30\n");
  s21_decimal src1, origin, result;
  // src1 = -2156878451.8547640000000000;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  // origin = -2156878451;
  origin.bits[0] = 0b10000000100011110101101001110011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_31) {
  // printf("s21_truncate_31\n");
  s21_decimal src1, origin, result;
  // src1 = 0.5456465465486476846545465485;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_32) {
  // printf("s21_truncate_32\n");
  s21_decimal src1, origin, result;
  // src1 = -776890.75455454213415678965898;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  // origin = -776890;
  origin.bits[0] = 0b00000000000010111101101010111010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_33) {
  // printf("s21_truncate_33\n");
  s21_decimal src1, origin, result;
  // src1 = -732123534337593543950335.12;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  // origin = -732123534337593543950335;
  origin.bits[0] = 0b11010011110111101111111111111111;
  origin.bits[1] = 0b01111111000011110000001101001111;
  origin.bits[2] = 0b00000000000000001001101100001000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_34) {
  // printf("s21_truncate_34\n");
  s21_decimal src1, origin, result;
  // src1 = 675432788976.5424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  // origin = 675432788976;
  origin.bits[0] = 0b01000010111011100111001111110000;
  origin.bits[1] = 0b00000000000000000000000010011101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_35) {
  // printf("s21_truncate_35\n");
  s21_decimal src1, origin, result;
  // src1 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  // origin = -579895323215489956;
  origin.bits[0] = 0b01011011001010110110101110100100;
  origin.bits[1] = 0b00001000000011000011001110111001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_36) {
  // printf("s21_truncate_36\n");
  s21_decimal src1, origin, result;
  // src1 = 123523543453453453.0;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 123523543453453453;
  origin.bits[0] = 0b00100000111100001100110010001101;
  origin.bits[1] = 0b00000001101101101101100000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_37) {
  // printf("s21_truncate_37\n");
  s21_decimal src1, origin, result;
  // src1 = 31231232456315.0;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 31231232456315;
  origin.bits[0] = 0b10010110100001000011011001111011;
  origin.bits[1] = 0b00000000000000000001110001100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_38) {
  // printf("s21_truncate_38\n");
  s21_decimal src1, origin, result;
  // src1 = 78987543557678337.5935439503;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  // origin = 78987543557678337;
  origin.bits[0] = 0b10011011011011111010010100000001;
  origin.bits[1] = 0b00000001000110001001111011000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_39) {
  // printf("s21_truncate_39\n");
  s21_decimal src1, origin, result;
  // src1 = -754567488438.97816770;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  // origin = -754567488438;
  origin.bits[0] = 0b10101111101110100010001110110110;
  origin.bits[1] = 0b00000000000000000000000010101111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_40) {
  // printf("s21_truncate_40\n");
  s21_decimal src1, origin, result;
  // src1 = -2.514475768684753643;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  // origin = -2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_41) {
  // printf("s21_truncate_41\n");
  s21_decimal src1, origin, result;
  // src1 = -0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  // origin = -0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
START_TEST(s21_truncate_42) {
  // printf("s21_truncate_42\n");
  s21_decimal src1, origin, result;
  // src1 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST
void srunner_add_comparsion_tests(SRunner *sr) {
  Suite *s1 = suite_create("Compare");
  TCase *tc1_1 = tcase_create("Compare");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_equal_1);
  tcase_add_test(tc1_1, s21_equal_2);
  tcase_add_test(tc1_1, s21_equal_3_fraction);
  tcase_add_test(tc1_1, s21_equal_4_sign);
  tcase_add_test(tc1_1, s21_equal_5_sign);
  tcase_add_test(tc1_1, s21_equal_6);
  tcase_add_test(tc1_1, s21_equal_7);
  tcase_add_test(tc1_1, s21_equal_8);
  tcase_add_test(tc1_1, s21_equal_9_ss);
  tcase_add_test(tc1_1, s21_equal_10);
  tcase_add_test(tc1_1, s21_equal_11_zero);
  tcase_add_test(tc1_1, s21_equal_12_value);
  tcase_add_test(tc1_1, s21_equal_13_value);
  tcase_add_test(tc1_1, s21_equal_14_value);
  tcase_add_test(tc1_1, s21_equal_15);
  tcase_add_test(tc1_1, s21_equal_16);
  tcase_add_test(tc1_1, s21_equal_18);
  tcase_add_test(tc1_1, s21_equal_20);
  tcase_add_test(tc1_1, s21_equal_21);
  tcase_add_test(tc1_1, s21_equal_26);
  tcase_add_test(tc1_1, s21_equal_28);
  tcase_add_test(tc1_1, s21_equal_29);
  tcase_add_test(tc1_1, s21_equal_30);
  tcase_add_test(tc1_1, s21_equal_31);
  tcase_add_test(tc1_1, s21_equal_32);
  tcase_add_test(tc1_1, s21_equal_33);
  tcase_add_test(tc1_1, s21_equal_34);
  tcase_add_test(tc1_1, s21_equal_35);
  tcase_add_test(tc1_1, s21_equal_36);
  tcase_add_test(tc1_1, s21_equal_38);
  tcase_add_test(tc1_1, s21_equal_39);
  tcase_add_test(tc1_1, s21_equal_40);
  tcase_add_test(tc1_1, s21_equal_41);
  tcase_add_test(tc1_1, s21_equal_43);
  tcase_add_test(tc1_1, s21_equal_44);
  tcase_add_test(tc1_1, s21_equal_45);
  tcase_add_test(tc1_1, s21_equal_46);
  tcase_add_test(tc1_1, s21_equal_47);
  tcase_add_test(tc1_1, s21_equal_48);
  tcase_add_test(tc1_1, s21_equal_49);
  tcase_add_test(tc1_1, s21_equal_50);
  tcase_add_test(tc1_1, s21_equal_51);
  tcase_add_test(tc1_1, s21_equal_52);
  tcase_add_test(tc1_1, s21_equal_53);
  tcase_add_test(tc1_1, s21_equal_54);
  tcase_add_test(tc1_1, s21_not_equal_1_1);
  tcase_add_test(tc1_1, s21_not_equal_2_1);
  tcase_add_test(tc1_1, s21_not_equal_3_fraction_1);
  tcase_add_test(tc1_1, s21_not_equal_4_sign_1);
  tcase_add_test(tc1_1, s21_not_equal_5_sign_1);
  tcase_add_test(tc1_1, s21_not_equal_6_1);
  tcase_add_test(tc1_1, s21_not_equal_7_1);
  tcase_add_test(tc1_1, s21_not_equal_8_1);
  tcase_add_test(tc1_1, s21_not_equal_9_ss_1);
  tcase_add_test(tc1_1, s21_not_equal_10_1);
  tcase_add_test(tc1_1, s21_not_equal_11_zero_1);
  tcase_add_test(tc1_1, s21_not_equal_12_value_1);
  tcase_add_test(tc1_1, s21_not_equal_13_value_1);
  tcase_add_test(tc1_1, s21_not_equal_14_value_1);
  tcase_add_test(tc1_1, s21_not_equal_1);
  tcase_add_test(tc1_1, s21_not_equal_2);
  tcase_add_test(tc1_1, s21_not_equal_4);
  tcase_add_test(tc1_1, s21_not_equal_6);
  tcase_add_test(tc1_1, s21_not_equal_7);
  tcase_add_test(tc1_1, s21_not_equal_12);
  tcase_add_test(tc1_1, s21_not_equal_14);
  tcase_add_test(tc1_1, s21_not_equal_15);
  tcase_add_test(tc1_1, s21_not_equal_16);
  tcase_add_test(tc1_1, s21_not_equal_17);
  tcase_add_test(tc1_1, s21_not_equal_18);
  tcase_add_test(tc1_1, s21_not_equal_19);
  tcase_add_test(tc1_1, s21_not_equal_20);
  tcase_add_test(tc1_1, s21_not_equal_21);
  tcase_add_test(tc1_1, s21_not_equal_22);
  tcase_add_test(tc1_1, s21_not_equal_24);
  tcase_add_test(tc1_1, s21_not_equal_25);
  tcase_add_test(tc1_1, s21_not_equal_26);
  tcase_add_test(tc1_1, s21_not_equal_27);
  tcase_add_test(tc1_1, s21_not_equal_29);
  tcase_add_test(tc1_1, s21_not_equal_30);
  tcase_add_test(tc1_1, s21_not_equal_31);
  tcase_add_test(tc1_1, s21_not_equal_32);
  tcase_add_test(tc1_1, s21_not_equal_33);
  tcase_add_test(tc1_1, s21_not_equal_34);
  tcase_add_test(tc1_1, s21_not_equal_35);
  tcase_add_test(tc1_1, s21_not_equal_36);
  tcase_add_test(tc1_1, s21_not_equal_37);
  tcase_add_test(tc1_1, s21_not_equal_38);
  tcase_add_test(tc1_1, s21_not_equal_39);
  tcase_add_test(tc1_1, s21_not_equal_40);
  tcase_add_test(tc1_1, s21_less_1);
  tcase_add_test(tc1_1, s21_less_2);
  tcase_add_test(tc1_1, s21_less_3_zero);
  tcase_add_test(tc1_1, s21_less_4_zero);
  tcase_add_test(tc1_1, s21_less_5_len_int_part);
  tcase_add_test(tc1_1, s21_less_6_len_int_part_positive);
  tcase_add_test(tc1_1, s21_less_8_value_int_part_positive);
  tcase_add_test(tc1_1, s21_less_9_value_fract_part_positive);
  tcase_add_test(tc1_1, s21_less_10_max_int_positive);
  tcase_add_test(tc1_1, s21_less_11_max_int_negative);
  tcase_add_test(tc1_1, s21_less_12);
  tcase_add_test(tc1_1, s21_less_13);
  tcase_add_test(tc1_1, s21_less_15);
  tcase_add_test(tc1_1, s21_less_17);
  tcase_add_test(tc1_1, s21_less_18);
  tcase_add_test(tc1_1, s21_less_19);
  tcase_add_test(tc1_1, s21_less_20);
  tcase_add_test(tc1_1, s21_less_22);
  tcase_add_test(tc1_1, s21_less_23);
  tcase_add_test(tc1_1, s21_less_24);
  tcase_add_test(tc1_1, s21_less_25);
  tcase_add_test(tc1_1, s21_less_26);
  tcase_add_test(tc1_1, s21_less_27);
  tcase_add_test(tc1_1, s21_less_28);
  tcase_add_test(tc1_1, s21_less_29);
  tcase_add_test(tc1_1, s21_less_30);
  tcase_add_test(tc1_1, s21_less_31);
  tcase_add_test(tc1_1, s21_less_32);
  tcase_add_test(tc1_1, s21_less_33);
  tcase_add_test(tc1_1, s21_less_35);
  tcase_add_test(tc1_1, s21_less_36);
  tcase_add_test(tc1_1, s21_less_37);
  tcase_add_test(tc1_1, s21_less_38);
  tcase_add_test(tc1_1, s21_less_40);
  tcase_add_test(tc1_1, s21_less_41);
  tcase_add_test(tc1_1, s21_less_42);
  tcase_add_test(tc1_1, s21_less_43);
  tcase_add_test(tc1_1, s21_less_44);
  tcase_add_test(tc1_1, s21_less_45);
  tcase_add_test(tc1_1, s21_less_46);
  tcase_add_test(tc1_1, s21_less_47);
  tcase_add_test(tc1_1, s21_less_48);
  tcase_add_test(tc1_1, s21_less_49);
  tcase_add_test(tc1_1, s21_less_50);
  tcase_add_test(tc1_1, s21_less_or_equal_1);
  tcase_add_test(tc1_1, s21_less_or_equal_2);
  tcase_add_test(tc1_1, s21_less_or_equal_3);
  tcase_add_test(tc1_1, s21_less_or_equal_4);
  tcase_add_test(tc1_1, s21_less_or_equal_5);
  tcase_add_test(tc1_1, s21_less_or_equal_6);
  tcase_add_test(tc1_1, s21_less_or_equal_10);
  tcase_add_test(tc1_1, s21_less_or_equal_14);
  tcase_add_test(tc1_1, s21_less_or_equal_15);
  tcase_add_test(tc1_1, s21_less_or_equal_16);
  tcase_add_test(tc1_1, s21_less_or_equal_17);
  tcase_add_test(tc1_1, s21_less_or_equal_18);
  tcase_add_test(tc1_1, s21_less_or_equal_19);
  tcase_add_test(tc1_1, s21_less_or_equal_20);
  tcase_add_test(tc1_1, s21_less_or_equal_21);
  tcase_add_test(tc1_1, s21_less_or_equal_22);
  tcase_add_test(tc1_1, s21_less_or_equal_23);
  tcase_add_test(tc1_1, s21_less_or_equal_24);
  tcase_add_test(tc1_1, s21_less_or_equal_25);
  tcase_add_test(tc1_1, s21_less_or_equal_26);
  tcase_add_test(tc1_1, s21_less_or_equal_27);
  tcase_add_test(tc1_1, s21_less_or_equal_28);
  tcase_add_test(tc1_1, s21_less_or_equal_29);
  tcase_add_test(tc1_1, s21_less_or_equal_30);
  tcase_add_test(tc1_1, s21_less_or_equal_31);
  tcase_add_test(tc1_1, s21_less_or_equal_32);
  tcase_add_test(tc1_1, s21_less_or_equal_33);
  tcase_add_test(tc1_1, s21_less_or_equal_34);
  tcase_add_test(tc1_1, s21_less_or_equal_35);
  tcase_add_test(tc1_1, s21_less_or_equal_36);
  tcase_add_test(tc1_1, s21_less_or_equal_37);
  tcase_add_test(tc1_1, s21_less_or_equal_38);
  tcase_add_test(tc1_1, s21_less_or_equal_39);
  tcase_add_test(tc1_1, s21_less_or_equal_40);
  tcase_add_test(tc1_1, s21_greater_1);
  tcase_add_test(tc1_1, s21_greater_3);
  tcase_add_test(tc1_1, s21_greater_4);
  tcase_add_test(tc1_1, s21_greater_5);
  tcase_add_test(tc1_1, s21_greater_6);
  tcase_add_test(tc1_1, s21_greater_10);
  tcase_add_test(tc1_1, s21_greater_12);
  tcase_add_test(tc1_1, s21_greater_14);
  tcase_add_test(tc1_1, s21_greater_15);
  tcase_add_test(tc1_1, s21_greater_16);
  tcase_add_test(tc1_1, s21_greater_17);
  tcase_add_test(tc1_1, s21_greater_18);
  tcase_add_test(tc1_1, s21_greater_19);
  tcase_add_test(tc1_1, s21_greater_20);
  tcase_add_test(tc1_1, s21_greater_21);
  tcase_add_test(tc1_1, s21_greater_22);
  tcase_add_test(tc1_1, s21_greater_23);
  tcase_add_test(tc1_1, s21_greater_24);
  tcase_add_test(tc1_1, s21_greater_25);
  tcase_add_test(tc1_1, s21_greater_26);
  tcase_add_test(tc1_1, s21_greater_27);
  tcase_add_test(tc1_1, s21_greater_28);
  tcase_add_test(tc1_1, s21_greater_29);
  tcase_add_test(tc1_1, s21_greater_30);
  tcase_add_test(tc1_1, s21_greater_31);
  tcase_add_test(tc1_1, s21_greater_32);
  tcase_add_test(tc1_1, s21_greater_33);
  tcase_add_test(tc1_1, s21_greater_34);
  tcase_add_test(tc1_1, s21_greater_35);
  tcase_add_test(tc1_1, s21_greater_36);
  tcase_add_test(tc1_1, s21_greater_37);
  tcase_add_test(tc1_1, s21_greater_38);
  tcase_add_test(tc1_1, s21_greater_39);
  tcase_add_test(tc1_1, s21_greater_40);
  tcase_add_test(tc1_1, s21_greater_or_equal_1);
  tcase_add_test(tc1_1, s21_greater_or_equal_2);
  tcase_add_test(tc1_1, s21_greater_or_equal_4);
  tcase_add_test(tc1_1, s21_greater_or_equal_6);
  tcase_add_test(tc1_1, s21_greater_or_equal_7);
  tcase_add_test(tc1_1, s21_greater_or_equal_8);
  tcase_add_test(tc1_1, s21_greater_or_equal_9);
  tcase_add_test(tc1_1, s21_greater_or_equal_11);
  tcase_add_test(tc1_1, s21_greater_or_equal_12);
  tcase_add_test(tc1_1, s21_greater_or_equal_13);
  tcase_add_test(tc1_1, s21_greater_or_equal_14);
  tcase_add_test(tc1_1, s21_greater_or_equal_15);
  tcase_add_test(tc1_1, s21_greater_or_equal_16);
  tcase_add_test(tc1_1, s21_greater_or_equal_17);
  tcase_add_test(tc1_1, s21_greater_or_equal_18);
  tcase_add_test(tc1_1, s21_greater_or_equal_19);
  tcase_add_test(tc1_1, s21_greater_or_equal_20);
  tcase_add_test(tc1_1, s21_greater_or_equal_21);
  tcase_add_test(tc1_1, s21_greater_or_equal_22);
  tcase_add_test(tc1_1, s21_greater_or_equal_24);
  tcase_add_test(tc1_1, s21_greater_or_equal_25);
  tcase_add_test(tc1_1, s21_greater_or_equal_26);
  tcase_add_test(tc1_1, s21_greater_or_equal_27);
  tcase_add_test(tc1_1, s21_greater_or_equal_29);
  tcase_add_test(tc1_1, s21_greater_or_equal_30);
  tcase_add_test(tc1_1, s21_greater_or_equal_31);
  tcase_add_test(tc1_1, s21_greater_or_equal_32);
  tcase_add_test(tc1_1, s21_greater_or_equal_33);
  tcase_add_test(tc1_1, s21_greater_or_equal_34);
  tcase_add_test(tc1_1, s21_greater_or_equal_35);
  tcase_add_test(tc1_1, s21_greater_or_equal_36);
  tcase_add_test(tc1_1, s21_greater_or_equal_37);
  tcase_add_test(tc1_1, s21_greater_or_equal_38);
  tcase_add_test(tc1_1, s21_greater_or_equal_39);
  srunner_add_suite(sr, s1);
}

void srunner_add_arithmetic_and_another_tests(SRunner *sr) {
  Suite *s1 = suite_create("Arithmetics and another");
  TCase *tc1_1 = tcase_create("Arithmetics and another");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_bank);
  tcase_add_test(tc1_1, s21_add_1);
  tcase_add_test(tc1_1, s21_add_2);
  tcase_add_test(tc1_1, s21_add_3);
  tcase_add_test(tc1_1, s21_add_4);
  tcase_add_test(tc1_1, s21_add_5);
  tcase_add_test(tc1_1, s21_add_6);
  tcase_add_test(tc1_1, s21_add_7);
  tcase_add_test(tc1_1, s21_add_8);
  tcase_add_test(tc1_1, s21_add_9);
  tcase_add_test(tc1_1, s21_add_10);
  tcase_add_test(tc1_1, s21_add_11);
  tcase_add_test(tc1_1, s21_add_12);
  tcase_add_test(tc1_1, s21_add_13);
  tcase_add_test(tc1_1, s21_add_14);
  tcase_add_test(tc1_1, s21_add_15);
  tcase_add_test(tc1_1, s21_add_16);
  tcase_add_test(tc1_1, s21_add_17);
  tcase_add_test(tc1_1, s21_add_18);
  tcase_add_test(tc1_1, s21_add_19);
  tcase_add_test(tc1_1, s21_add_20);
  tcase_add_test(tc1_1, s21_add_21);
  tcase_add_test(tc1_1, s21_add_22);
  tcase_add_test(tc1_1, s21_add_23);
  tcase_add_test(tc1_1, s21_add_24);
  tcase_add_test(tc1_1, s21_add_25);
  tcase_add_test(tc1_1, s21_add_26);
  tcase_add_test(tc1_1, s21_add_27);
  tcase_add_test(tc1_1, s21_add_28);
  tcase_add_test(tc1_1, s21_add_29);
  tcase_add_test(tc1_1, s21_add_30);
  tcase_add_test(tc1_1, s21_add_31);
  tcase_add_test(tc1_1, s21_add_32);
  tcase_add_test(tc1_1, s21_add_33);
  tcase_add_test(tc1_1, s21_add_34);
  tcase_add_test(tc1_1, s21_add_36);
  tcase_add_test(tc1_1, s21_add_38);
  tcase_add_test(tc1_1, s21_add_44);
  tcase_add_test(tc1_1, s21_add_45);
  tcase_add_test(tc1_1, s21_add_49);
  tcase_add_test(tc1_1, s21_add_50);
  tcase_add_test(tc1_1, s21_add_51);
  tcase_add_test(tc1_1, s21_add_52);
  tcase_add_test(tc1_1, s21_div_1);
  tcase_add_test(tc1_1, s21_div_2);
  tcase_add_test(tc1_1, s21_div_3);
  tcase_add_test(tc1_1, s21_div_4);
  tcase_add_test(tc1_1, s21_div_5);
  tcase_add_test(tc1_1, s21_mul_1);
  tcase_add_test(tc1_1, s21_mul_2);
  tcase_add_test(tc1_1, s21_mul_3);
  tcase_add_test(tc1_1, s21_mul_4);
  tcase_add_test(tc1_1, s21_mul_6);
  tcase_add_test(tc1_1, s21_mul_7);
  tcase_add_test(tc1_1, s21_mul_8);
  tcase_add_test(tc1_1, s21_mul_9);
  tcase_add_test(tc1_1, s21_mul_10);
  tcase_add_test(tc1_1, s21_mul_11);
  tcase_add_test(tc1_1, s21_mul_12);
  tcase_add_test(tc1_1, s21_mul_13);
  tcase_add_test(tc1_1, s21_mul_14);
  tcase_add_test(tc1_1, s21_mul_15);
  tcase_add_test(tc1_1, s21_mul_16);
  tcase_add_test(tc1_1, s21_mul_17);
  tcase_add_test(tc1_1, s21_mul_18);
  tcase_add_test(tc1_1, s21_mul_19);
  tcase_add_test(tc1_1, s21_mul_20);
  tcase_add_test(tc1_1, s21_mul_21);
  tcase_add_test(tc1_1, s21_mul_22);
  tcase_add_test(tc1_1, s21_mul_23);
  tcase_add_test(tc1_1, s21_mul_24);
  tcase_add_test(tc1_1, s21_mul_25);
  tcase_add_test(tc1_1, s21_mul_26);
  tcase_add_test(tc1_1, s21_mul_27);
  tcase_add_test(tc1_1, s21_mul_28);
  tcase_add_test(tc1_1, s21_mul_29);
  tcase_add_test(tc1_1, s21_mul_30);
  tcase_add_test(tc1_1, s21_mul_31);
  tcase_add_test(tc1_1, s21_mul_32);
  tcase_add_test(tc1_1, s21_mul_33);
  tcase_add_test(tc1_1, s21_mul_49);
  tcase_add_test(tc1_1, s21_mul_50);
  tcase_add_test(tc1_1, s21_mul_51);
  tcase_add_test(tc1_1, s21_mul_52);
  tcase_add_test(tc1_1, s21_round_1);
  tcase_add_test(tc1_1, s21_round_2);
  tcase_add_test(tc1_1, s21_round_3);
  tcase_add_test(tc1_1, s21_round_4);
  tcase_add_test(tc1_1, s21_round_5);
  tcase_add_test(tc1_1, s21_round_6);
  tcase_add_test(tc1_1, s21_round_7);
  tcase_add_test(tc1_1, s21_round_8);
  tcase_add_test(tc1_1, s21_round_9);
  tcase_add_test(tc1_1, s21_round_10);
  tcase_add_test(tc1_1, s21_round_11);
  tcase_add_test(tc1_1, s21_round_12);
  tcase_add_test(tc1_1, s21_round_13);
  tcase_add_test(tc1_1, s21_round_14);
  tcase_add_test(tc1_1, s21_round_15);
  tcase_add_test(tc1_1, s21_round_16);
  tcase_add_test(tc1_1, s21_round_17);
  tcase_add_test(tc1_1, s21_round_18);
  tcase_add_test(tc1_1, s21_round_19);
  tcase_add_test(tc1_1, s21_round_20);
  tcase_add_test(tc1_1, s21_round_21);
  tcase_add_test(tc1_1, s21_round_22);
  tcase_add_test(tc1_1, s21_round_23);
  tcase_add_test(tc1_1, s21_round_24);
  tcase_add_test(tc1_1, s21_floor_1);
  tcase_add_test(tc1_1, s21_floor_2);
  tcase_add_test(tc1_1, s21_floor_3);
  tcase_add_test(tc1_1, s21_floor_4);
  tcase_add_test(tc1_1, s21_floor_5);
  tcase_add_test(tc1_1, s21_floor_6);
  tcase_add_test(tc1_1, s21_floor_7);
  tcase_add_test(tc1_1, s21_floor_8);
  tcase_add_test(tc1_1, s21_floor_9);
  tcase_add_test(tc1_1, s21_floor_10);
  tcase_add_test(tc1_1, s21_floor_11);
  tcase_add_test(tc1_1, s21_floor_12);
  tcase_add_test(tc1_1, s21_floor_13);
  tcase_add_test(tc1_1, s21_floor_14);
  tcase_add_test(tc1_1, s21_floor_15);
  tcase_add_test(tc1_1, s21_floor_16);
  tcase_add_test(tc1_1, s21_floor_17);
  tcase_add_test(tc1_1, s21_floor_18);
  tcase_add_test(tc1_1, s21_floor_19);
  tcase_add_test(tc1_1, s21_floor_20);
  tcase_add_test(tc1_1, s21_floor_21);
  tcase_add_test(tc1_1, s21_floor_22);
  tcase_add_test(tc1_1, s21_floor_23);
  tcase_add_test(tc1_1, s21_floor_24);
  tcase_add_test(tc1_1, s21_sub_1);
  tcase_add_test(tc1_1, s21_sub_2);
  tcase_add_test(tc1_1, s21_sub_3);
  tcase_add_test(tc1_1, s21_sub_4);
  tcase_add_test(tc1_1, s21_sub_5);
  tcase_add_test(tc1_1, s21_sub_6);
  tcase_add_test(tc1_1, s21_sub_7);
  tcase_add_test(tc1_1, s21_sub_8);
  tcase_add_test(tc1_1, s21_sub_9);
  tcase_add_test(tc1_1, s21_sub_10);
  tcase_add_test(tc1_1, s21_sub_11);
  tcase_add_test(tc1_1, s21_sub_12);
  tcase_add_test(tc1_1, s21_sub_13);
  tcase_add_test(tc1_1, s21_sub_14);
  tcase_add_test(tc1_1, s21_sub_15);
  tcase_add_test(tc1_1, s21_sub_16);
  tcase_add_test(tc1_1, s21_sub_17);
  tcase_add_test(tc1_1, s21_sub_19);
  tcase_add_test(tc1_1, s21_sub_20);
  tcase_add_test(tc1_1, s21_sub_21);
  tcase_add_test(tc1_1, s21_sub_22);
  tcase_add_test(tc1_1, s21_sub_23);
  tcase_add_test(tc1_1, s21_sub_24);
  tcase_add_test(tc1_1, s21_sub_25);
  tcase_add_test(tc1_1, s21_sub_26);
  tcase_add_test(tc1_1, s21_sub_27);
  tcase_add_test(tc1_1, s21_sub_28);
  tcase_add_test(tc1_1, s21_sub_29);
  tcase_add_test(tc1_1, s21_sub_30);
  tcase_add_test(tc1_1, s21_sub_32);
  tcase_add_test(tc1_1, s21_sub_33);
  tcase_add_test(tc1_1, s21_sub_34);
  tcase_add_test(tc1_1, s21_sub_35);
  tcase_add_test(tc1_1, s21_sub_39);
  tcase_add_test(tc1_1, s21_sub_48);
  tcase_add_test(tc1_1, s21_sub_49);
  tcase_add_test(tc1_1, s21_sub_50);
  tcase_add_test(tc1_1, s21_sub_51);
  tcase_add_test(tc1_1, s21_sub_52);
  tcase_add_test(tc1_1, s21_sub_53);
  tcase_add_test(tc1_1, s21_negate_1);
  tcase_add_test(tc1_1, s21_negate_2);
  tcase_add_test(tc1_1, s21_negate_3);
  tcase_add_test(tc1_1, s21_negate_4);
  tcase_add_test(tc1_1, s21_negate_5);
  tcase_add_test(tc1_1, s21_negate_6);
  tcase_add_test(tc1_1, s21_negate_7);
  tcase_add_test(tc1_1, s21_negate_8);
  tcase_add_test(tc1_1, s21_negate_9);
  tcase_add_test(tc1_1, s21_negate_10);
  tcase_add_test(tc1_1, s21_negate_11);
  tcase_add_test(tc1_1, s21_negate_12);
  tcase_add_test(tc1_1, s21_negate_13);
  tcase_add_test(tc1_1, s21_negate_14);
  tcase_add_test(tc1_1, s21_negate_15);
  tcase_add_test(tc1_1, s21_negate_16);
  tcase_add_test(tc1_1, s21_negate_17);
  tcase_add_test(tc1_1, s21_negate_18);
  tcase_add_test(tc1_1, s21_negate_19);
  tcase_add_test(tc1_1, s21_negate_20);
  tcase_add_test(tc1_1, s21_negate_21);
  tcase_add_test(tc1_1, s21_negate_22);
  tcase_add_test(tc1_1, s21_negate_23);
  tcase_add_test(tc1_1, s21_negate_24);
  tcase_add_test(tc1_1, s21_negate_25);
  tcase_add_test(tc1_1, s21_negate_26);
  tcase_add_test(tc1_1, s21_negate_27);
  tcase_add_test(tc1_1, s21_negate_28);
  tcase_add_test(tc1_1, s21_negate_29);
  tcase_add_test(tc1_1, s21_negate_30);
  tcase_add_test(tc1_1, s21_negate_31);
  tcase_add_test(tc1_1, s21_negate_32);
  tcase_add_test(tc1_1, s21_negate_33);
  tcase_add_test(tc1_1, s21_negate_34);
  tcase_add_test(tc1_1, s21_negate_35);
  tcase_add_test(tc1_1, s21_negate_36);
  tcase_add_test(tc1_1, s21_negate_37);
  tcase_add_test(tc1_1, s21_negate_38);
  tcase_add_test(tc1_1, s21_negate_39);
  tcase_add_test(tc1_1, s21_negate_40);
  tcase_add_test(tc1_1, s21_negate_41);
  tcase_add_test(tc1_1, s21_negate_42);
  tcase_add_test(tc1_1, s21_truncate_1);
  tcase_add_test(tc1_1, s21_truncate_2);
  tcase_add_test(tc1_1, s21_truncate_3);
  tcase_add_test(tc1_1, s21_truncate_4);
  tcase_add_test(tc1_1, s21_truncate_5);
  tcase_add_test(tc1_1, s21_truncate_6);
  tcase_add_test(tc1_1, s21_truncate_7);
  tcase_add_test(tc1_1, s21_truncate_8);
  tcase_add_test(tc1_1, s21_truncate_9);
  tcase_add_test(tc1_1, s21_truncate_10);
  tcase_add_test(tc1_1, s21_truncate_11);
  tcase_add_test(tc1_1, s21_truncate_12);
  tcase_add_test(tc1_1, s21_truncate_13);
  tcase_add_test(tc1_1, s21_truncate_14);
  tcase_add_test(tc1_1, s21_truncate_15);
  tcase_add_test(tc1_1, s21_truncate_16);
  tcase_add_test(tc1_1, s21_truncate_17);
  tcase_add_test(tc1_1, s21_truncate_18);
  tcase_add_test(tc1_1, s21_truncate_19);
  tcase_add_test(tc1_1, s21_truncate_20);
  tcase_add_test(tc1_1, s21_truncate_21);
  tcase_add_test(tc1_1, s21_truncate_22);
  tcase_add_test(tc1_1, s21_truncate_23);
  tcase_add_test(tc1_1, s21_truncate_24);
  tcase_add_test(tc1_1, s21_truncate_25);
  tcase_add_test(tc1_1, s21_truncate_26);
  tcase_add_test(tc1_1, s21_truncate_27);
  tcase_add_test(tc1_1, s21_truncate_28);
  tcase_add_test(tc1_1, s21_truncate_29);
  tcase_add_test(tc1_1, s21_truncate_30);
  tcase_add_test(tc1_1, s21_truncate_31);
  tcase_add_test(tc1_1, s21_truncate_32);
  tcase_add_test(tc1_1, s21_truncate_33);
  tcase_add_test(tc1_1, s21_truncate_34);
  tcase_add_test(tc1_1, s21_truncate_35);
  tcase_add_test(tc1_1, s21_truncate_36);
  tcase_add_test(tc1_1, s21_truncate_37);
  tcase_add_test(tc1_1, s21_truncate_38);
  tcase_add_test(tc1_1, s21_truncate_39);
  tcase_add_test(tc1_1, s21_truncate_40);
  tcase_add_test(tc1_1, s21_truncate_41);
  tcase_add_test(tc1_1, s21_truncate_42);
  srunner_add_suite(sr, s1);
}

void srunner_add_converters_tests(SRunner *sr) {
  Suite *s1 = suite_create("Converters");
  TCase *tc1_1 = tcase_create("Converters");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, int_to_dec_1);
  tcase_add_test(tc1_1, int_to_dec_2);
  tcase_add_test(tc1_1, int_to_dec_3);
  tcase_add_test(tc1_1, int_to_dec_4);
  tcase_add_test(tc1_1, int_to_dec_5);
  tcase_add_test(tc1_1, int_to_dec_6);
  tcase_add_test(tc1_1, int_to_dec_7);
  tcase_add_test(tc1_1, int_to_dec_8);
  tcase_add_test(tc1_1, int_to_dec_9);
  tcase_add_test(tc1_1, int_to_dec_10);
  tcase_add_test(tc1_1, int_to_dec_11);
  tcase_add_test(tc1_1, int_to_dec_12);
  tcase_add_test(tc1_1, int_to_dec_13);
  tcase_add_test(tc1_1, int_to_dec_14);
  tcase_add_test(tc1_1, int_to_dec_15);
  tcase_add_test(tc1_1, int_to_dec_16);
  tcase_add_test(tc1_1, int_to_dec_17);
  tcase_add_test(tc1_1, int_to_dec_18);
  tcase_add_test(tc1_1, int_to_dec_19);
  tcase_add_test(tc1_1, int_to_dec_20);
  tcase_add_test(tc1_1, int_to_dec_21);
  tcase_add_test(tc1_1, dec_to_int_1);
  tcase_add_test(tc1_1, dec_to_int_2);
  tcase_add_test(tc1_1, dec_to_int_3);
  tcase_add_test(tc1_1, dec_to_int_4);
  tcase_add_test(tc1_1, dec_to_int_5);
  tcase_add_test(tc1_1, dec_to_int_7);
  tcase_add_test(tc1_1, dec_to_int_8);
  tcase_add_test(tc1_1, dec_to_int_9);
  tcase_add_test(tc1_1, dec_to_int_10);
  tcase_add_test(tc1_1, dec_to_int_11);
  tcase_add_test(tc1_1, dec_to_int_12);
  tcase_add_test(tc1_1, dec_to_int_13);
  tcase_add_test(tc1_1, dec_to_int_14);
  tcase_add_test(tc1_1, dec_to_int_15);
  tcase_add_test(tc1_1, dec_to_int_16);
  tcase_add_test(tc1_1, dec_to_int_17);
  tcase_add_test(tc1_1, dec_to_int_18);
  tcase_add_test(tc1_1, dec_to_int_19);
  tcase_add_test(tc1_1, dec_to_int_20);
  tcase_add_test(tc1_1, dec_to_int_21);
  tcase_add_test(tc1_1, dec_to_int_23);
  tcase_add_test(tc1_1, dec_to_int_24);
  tcase_add_test(tc1_1, dec_to_float_1);
  tcase_add_test(tc1_1, dec_to_float_2);
  tcase_add_test(tc1_1, dec_to_float_3);
  tcase_add_test(tc1_1, dec_to_float_4);
  tcase_add_test(tc1_1, dec_to_float_5);
  tcase_add_test(tc1_1, dec_to_float_6);
  tcase_add_test(tc1_1, dec_to_float_7);
  tcase_add_test(tc1_1, dec_to_float_8);
  tcase_add_test(tc1_1, dec_to_float_9);
  tcase_add_test(tc1_1, dec_to_float_10);
  tcase_add_test(tc1_1, dec_to_float_11);
  tcase_add_test(tc1_1, dec_to_float_12);
  tcase_add_test(tc1_1, dec_to_float_13);
  tcase_add_test(tc1_1, dec_to_float_14);
  tcase_add_test(tc1_1, dec_to_float_17);
  tcase_add_test(tc1_1, dec_to_float_18);
  tcase_add_test(tc1_1, dec_to_float_19);
  tcase_add_test(tc1_1, dec_to_float_20);
  tcase_add_test(tc1_1, dec_to_float_21);
  tcase_add_test(tc1_1, dec_to_float_22);
  tcase_add_test(tc1_1, dec_to_float_23);
  tcase_add_test(tc1_1, dec_to_float_24);
  tcase_add_test(tc1_1, dec_to_float_25);
  tcase_add_test(tc1_1, dec_to_float_26);
  tcase_add_test(tc1_1, dec_to_float_27);
  tcase_add_test(tc1_1, dec_to_float_28);
  tcase_add_test(tc1_1, dec_to_float_29);
  tcase_add_test(tc1_1, dec_to_float_31);
  tcase_add_test(tc1_1, dec_to_float_33);
  tcase_add_test(tc1_1, dec_to_float_34);
  tcase_add_test(tc1_1, dec_to_float_35);
  tcase_add_test(tc1_1, dec_to_float_36);
  tcase_add_test(tc1_1, s21_from_float_to_decimal_4);
  // tcase_add_test(tc1_1, s21_from_float_to_decimal_6);
  tcase_add_test(tc1_1, s21_from_float_to_decimal_7);
  srunner_add_suite(sr, s1);
}
// elevator     test calls
void decimal_inside_tests(SRunner *sr) {
  Suite *s = suite_create("Decimal_basics");
  ;
  TCase *tc_core = tcase_create("Core");
  suite_add_tcase(s, tc_core);
  tcase_add_test(tc_core, test_bit_operations_original);
  tcase_add_test(tc_core, test_bit_operations_extra_shift_1);

  tcase_add_test(tc_core, test_simple_comparison_bitsCompare);
  tcase_add_test(tc_core, test_simple_comparison_decimalCompare);
  tcase_add_test(tc_core, test_simple_comparison_expendedCompare);

  tcase_add_test(tc_core, test_simple_converters_1);
  tcase_add_test(tc_core, test_simple_converters_2);
  tcase_add_test(tc_core, test_simple_converters_3);

  tcase_add_test(tc_core, test_error_bit);

  tcase_add_test(tc_core, test_expended_bit);
  tcase_add_test(tc_core, test_expended_bit_shift);
  tcase_add_test(tc_core, test_expended_bit_scale);

  tcase_add_test(tc_core, test_simple_arithmetic_addition_1);
  tcase_add_test(tc_core, test_simple_arithmetic_addition_2);
  tcase_add_test(tc_core, test_simple_arithmetic_addition_expended);
  tcase_add_test(tc_core, test_simple_arithmetic_subtraction_1);
  tcase_add_test(tc_core, test_simple_arithmetic_subtraction_2);
  tcase_add_test(tc_core, test_simple_arithmetic_subtraction_extended);
  tcase_add_test(tc_core, test_simple_arithmetic_multiplication_1);
  tcase_add_test(tc_core, test_simple_arithmetic_multiplication_2);
  tcase_add_test(tc_core, test_simple_arithmetic_multiplication_int);
  tcase_add_test(tc_core, test_simple_arithmetic_division);
  tcase_add_test(tc_core, test_simple_arithmetic_multiplication_expended);
  tcase_add_test(tc_core, test_simple_arithmetic_division_expended);

  tcase_add_test(tc_core, test_scaling_and_co_1);
  tcase_add_test(tc_core, test_scaling_and_co_2);
  tcase_add_test(tc_core, test_scaling_and_co_3);
  tcase_add_test(tc_core, test_scaling_and_co_4);
  tcase_add_test(tc_core, test_scaling_and_co_5);
  tcase_add_test(tc_core, test_scaling_and_co_6);
  tcase_add_test(tc_core, test_scaling_and_co_7);

  tcase_add_test(tc_core, test_extra_functions_1);

  tcase_add_test(tc_core, test_main_comparison_1);
  tcase_add_test(tc_core, test_main_comparison_2);

  tcase_add_test(tc_core, test_service_functions);

  tcase_add_test(tc_core, test_arithmetic_the_addition);
  tcase_add_test(tc_core, test_arithmetic_the_subtraction);
  tcase_add_test(tc_core, test_arithmetic_the_multiplication);
  tcase_add_test(tc_core, test_arithmetic_the_division);

  tcase_add_test(tc_core, test_convert_int);
  // tcase_add_test(tc_core,test_convert_float);
  tcase_add_test(tc_core, fl_to_dc_1);
  tcase_add_test(tc_core, fl_to_dc_2);
  tcase_add_test(tc_core, fl_to_dc_3);
  tcase_add_test(tc_core, fl_to_dc_4);
  // tcase_add_test(tc_core,fl_to_dc_5);
  // tcase_add_test(tc_core,fl_to_dc_6);
  tcase_add_test(tc_core, fl_to_dc_7);
  // tcase_add_test(tc_core,fl_to_dc_8);
  tcase_add_test(tc_core, fl_to_dc_9);
  tcase_add_test(tc_core, dc_to_fl_1);
  tcase_add_test(tc_core, dc_to_fl_2);
  tcase_add_test(tc_core, dc_to_fl_3);
  tcase_add_test(tc_core, dc_to_fl_4);
  tcase_add_test(tc_core, dc_to_fl_5);

  tcase_add_test(tc_core, the_most_important_tests);

  srunner_add_suite(sr, s);
}
// elevator     end

int main(void) {
  int number_failed;
  Suite *s = suite_create("Decimal tests");
  SRunner *sr = srunner_create(s);

  decimal_inside_tests(sr);
  srunner_add_comparsion_tests(sr);
  srunner_add_arithmetic_and_another_tests(sr);
  srunner_add_converters_tests(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

// int main(void) {
//   Suite *s = suite_create("Decimal tests");
//   SRunner *sr = srunner_create(s);
//   int nf;

//   srunner_run_all(sr, CK_ENV);

//   return nf == 0 ? 0 : 1;
// }