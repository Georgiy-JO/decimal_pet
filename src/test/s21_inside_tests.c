#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

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
  s21_decimal* number3 = NULL;

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

// elevator     test calls
Suite* my_string_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("My_String");
  tc_core = tcase_create("Core");

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

  suite_add_tcase(s, tc_core);
  return s;
}
// elevator     end
int main(void) {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = my_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
