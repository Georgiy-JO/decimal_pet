#include "s21_simple_arithmetic.h"

// does not work with signs and scale and overflow
s21_decimal s21_simpleAddition(s21_decimal num1, s21_decimal num2) {
  s21_decimal result = ZERO_DECIMAL;
  char overflow = 0, val = 0;

  for (int i = 0; i < mantissa_three; i++) {
    val = s21_getBitGlobal(num1, i) ^ s21_getBitGlobal(num2, i) ^ overflow;
    s21_setBitGlobal(&result, i, val);
    if (s21_getBitGlobal(num1, i) + s21_getBitGlobal(num2, i) + overflow >= 2)
      overflow = 1;
    else
      overflow = 0;
  }
  if (overflow == 1) s21_setErrorbitsOne(&result);
  return result;
}

// does not work with signs and scale
s21_expended s21_simpleAdditionExp(s21_expended num1, s21_expended num2) {
  s21_expended result = ZERO_EXPENDED;
  char overflow = 0, val = 0;
  int length = s21_mantissaExpFirstBit(num1) + 1,
      length2 = s21_mantissaExpFirstBit(num2) + 1;
  if (length2 > length) length = length2;
  if (mantissa_six < length) length = mantissa_six;

  for (int i = 0; i <= length; i++) {
    val =
        s21_getBitGlobalExp(num1, i) ^ s21_getBitGlobalExp(num2, i) ^ overflow;
    s21_setBitGlobalExp(&result, i, val);
    if (s21_getBitGlobalExp(num1, i) + s21_getBitGlobalExp(num2, i) +
            overflow >=
        2)
      overflow = 1;
    else
      overflow = 0;
  }
  return result;
}

// does not work with signs and scale (but can a-b if a<b)
s21_decimal s21_simpleSubtraction(s21_decimal num1, s21_decimal num2) {
  s21_decimal result = ZERO_DECIMAL;
  int flag = s21_decimalCompare(num1, num2);
  if (flag != 0) {
    char borrow = 0, val = 0;
    if (flag < 0) {
      s21_copyDecimal(num1, &result);
      s21_copyDecimal(num2, &num1);
      s21_copyDecimal(result, &num2);
      s21_clearDecimal(&result);
      s21_invertSign(&result);
    }
    for (int i = 0; i < mantissa_three; i++) {
      val = s21_getBitGlobal(num1, i) ^ s21_getBitGlobal(num2, i) ^ borrow;
      s21_setBitGlobal(&result, i, val);
      if (s21_getBitGlobal(num2, i) + borrow > s21_getBitGlobal(num1, i))
        borrow = 1;
      else
        borrow = 0;
    }
  }
  return result;
}

// does not work with signs and scale (but can a-b if a<b)
s21_expended s21_simpleSubtractionExp(s21_expended num1, s21_expended num2) {
  s21_expended result = ZERO_EXPENDED;

  int flag = s21_expendedCompare(num1, num2);
  if (flag != 0) {
    char borrow = 0, val = 0;
    if (flag < 0) {
      s21_copyExpended(num1, &result);
      s21_copyExpended(num2, &num1);
      s21_copyExpended(result, &num2);
      s21_clearExpended(&result);
      s21_invertSignExp(&result);
    }
    int length = s21_mantissaExpFirstBit(num1) + 1;
    if (mantissa_six < length) length = mantissa_six;
    for (int i = 0; i <= length; i++) {
      val =
          s21_getBitGlobalExp(num1, i) ^ s21_getBitGlobalExp(num2, i) ^ borrow;
      s21_setBitGlobalExp(&result, i, val);
      if (s21_getBitGlobalExp(num2, i) + borrow > s21_getBitGlobalExp(num1, i))
        borrow = 1;
      else
        borrow = 0;
    }
  }
  return result;
}

// does not work with signs and scale and overflow (won't tell if overflow)
s21_decimal s21_simpleDecMultiplication(s21_decimal num1, s21_decimal num2) {
  return s21_takeLastExpToDec(s21_simpleDecMultiplicationExpOut(num1, num2));
}

// does not work with signs and scale
// not checked independently
s21_expended s21_simpleDecMultiplicationExpOut(s21_decimal number1,
                                               s21_decimal number2) {
  s21_expended num1 = s21_decToExp(number1), num2 = s21_decToExp(number2);
  return s21_simpleExpMultiplication(num1, num2);
  /*
  s21_expended result=ZERO_EXPENDED, local=ZERO_EXPENDED;
  int beg=0;
  for (int i=mantissa_three-1;i>=0;i--){
      if(s21_getBitGlobalExp(num2,i) && beg==0)
          beg=i+1;
      if(beg!=0 && (i==0 || !s21_getBitGlobalExp(num2,i-1))){
          s21_copyExpended(num1,&local);
          s21_leftShiftExp(&local,beg);
          result=s21_simpleAdditionExp(result,local);
          s21_copyExpended(num1,&local);
          s21_leftShiftExp(&local,i);
          result=s21_simpleSubtractionExp(result,local);
          beg=0;
      }
  }
  return result;
  */
}

// does not work with signs and scale and overflow (won't tell if overflow)
s21_decimal s21_simpleIntMultiplication(s21_decimal num1, int num2) {
  s21_decimal dec_num2 = s21_simpleIntToDec(num2);
  return s21_simpleDecMultiplication(num1, dec_num2);
}

// does not work with signs and scale (+ return errorcode if devided by zero)
// a/b  ==>>   b*2^q<=a
// devide only the Integer part, write remainder into input parameter (9/4 = 2
// (rem.: 1)). more tests might be required
s21_decimal s21_simpleDecIntegerDivisionRemainder(s21_decimal dividend,
                                                  s21_decimal divider,
                                                  s21_decimal* remainderr) {
  s21_decimal result = ZERO_DECIMAL;
  if (!s21_decimalCompare(divider, result))
    s21_setErrorbitsThree(&result);
  else {
    s21_expended div_nd = s21_decToExp(dividend),
                 div_er = s21_decToExp(divider),
                 rem_er = s21_decToExp(*remainderr);
    result = s21_takeLastExpToDec(
        s21_simpleExpIntegerDivisionRemainder(div_nd, div_er, &rem_er));
    *remainderr = s21_takeLastExpToDec(rem_er);
  }
  return result;

  /*
  s21_decimal result=ZERO_DECIMAL, local=ZERO_DECIMAL;
  s21_expended dividend_big=ZERO_EXPENDED, local_big=ZERO_EXPENDED;
  if(!s21_decimalCompare(divider,local))
      s21_setErrorbitsThree(&result);
  else{
      int degree=0;
      while(s21_decimalCompare(dividend,divider)>0){
          //s21_copyDecimal(divider,&local);
          local_big=s21_decToExp(divider);
          dividend_big=s21_decToExp(dividend);
          while(s21_expendedCompare(dividend_big,local_big)>0){
              s21_leftShiftExp(&local_big,1);
              degree++;
          }
          s21_rightShiftExp(&local_big,1);
          local=s21_takeLastExpToDec(local_big);
          dividend=s21_simpleSubtraction(dividend,local);
          s21_clearDecimal(&local);
          s21_setBitGlobal(&local,degree-1,1);
          //s21_printDecimalBin(dividend);
          //s21_printDecimalBin(local);
          result=s21_simpleAddition(result,local);
          degree=0;
      }
      if(s21_decimalCompare(dividend,divider)==0){
          s21_clearDecimal(&local);
          s21_setBitGlobal(&local,0,1);
          result=s21_simpleAddition(result,local);
          s21_clearDecimal(remainderr);
      }
      else
          s21_copyDecimal(dividend,remainderr);
  }
  return result;
  */
}

// does not work with signs and scale
// devide only the Integer part(9/4 = 2).
s21_decimal s21_simpleDecIntegerDivision(s21_decimal dividend,
                                         s21_decimal divider) {
  s21_decimal remainderr = ZERO_DECIMAL;
  return s21_simpleDecIntegerDivisionRemainder(dividend, divider, &remainderr);
}

// does not work with signs and scale
s21_decimal s21_simpleIntIntegerDivision(s21_decimal dividend, int divider) {
  s21_decimal dec_divider = s21_simpleIntToDec(divider);
  return s21_simpleDecIntegerDivision(dividend, dec_divider);
}

// does not work with signs and scale and overflow (won't tell if overflow)
// length of result <= length of num1 + length of num2   (111*11=10101 == 3+2=5
// ||  100*10=1000  == 3+2>4)     --  important for overflow more tests might be
// required
s21_expended s21_simpleExpMultiplication(s21_expended num1, s21_expended num2) {
  s21_expended result = ZERO_EXPENDED, local = ZERO_EXPENDED;
  int beg = 0;
  int length = s21_mantissaExpFirstBit(num2);
  length = (length > mantissa_six) ? mantissa_six : length;
  for (int i = mantissa_six; i >= 0; i--) {
    if (s21_getBitGlobalExp(num2, i) && beg == 0) beg = i + 1;
    if (beg != 0 && (i == 0 || !s21_getBitGlobalExp(num2, i - 1))) {
      s21_copyExpended(num1, &local);
      s21_leftShiftExp(&local, beg);
      result = s21_simpleAdditionExp(result, local);
      s21_copyExpended(num1, &local);
      s21_leftShiftExp(&local, i);
      result = s21_simpleSubtractionExp(result, local);
      beg = 0;
    }
  }
  return result;
}

// does not work with signs and scale and overflow (won't tell if overflow)
// more tests might be required
s21_expended s21_simpleExpIntMultiplication(s21_expended num1, int num2) {
  s21_expended exp_num2 = s21_decToExp(s21_simpleIntToDec(num2));
  return s21_simpleExpMultiplication(num1, exp_num2);
}

// does not work with signs and scale (does not return error when dividing by
// zero) a/b  ==>>   b*2^q<=a devide only the Integer part, write remainder into
// input parameter (9/4 = 2  (rem.: 1)). more tests might be required
s21_expended s21_simpleExpIntegerDivisionRemainder(s21_expended dividend,
                                                   s21_expended divider,
                                                   s21_expended* remainderr) {
  s21_expended result = ZERO_DECIMAL, local = ZERO_DECIMAL;
  if (s21_expendedCompare(divider, local)) {
    int degree = 0;
    while (s21_expendedCompare(dividend, divider) > 0) {
      s21_copyExpended(divider, &local);
      while (s21_expendedCompare(dividend, local) > 0) {
        s21_leftShiftExp(&local, 1);
        degree++;
      }
      s21_rightShiftExp(&local, 1);
      dividend = s21_simpleSubtractionExp(dividend, local);
      s21_clearExpended(&local);
      s21_setBitGlobalExp(&local, degree - 1, 1);
      result = s21_simpleAdditionExp(result, local);
      degree = 0;
    }
    if (s21_expendedCompare(dividend, divider) == 0) {
      s21_clearExpended(&local);
      s21_setBitGlobalExp(&local, 0, 1);
      result = s21_simpleAdditionExp(result, local);
      s21_clearExpended(remainderr);
    } else
      s21_copyExpended(dividend, remainderr);
  }
  return result;
}

// does not work with signs and scale and dividing by zero
// devide only the Integer part(9/4 = 2).
s21_expended s21_simpleExpIntegerDivision(s21_expended dividend,
                                          s21_expended divider) {
  s21_expended remainderr = ZERO_DECIMAL;
  return s21_simpleExpIntegerDivisionRemainder(dividend, divider, &remainderr);
}

// does not work with signs and scale and dividing by zero
s21_expended s21_simpleIntIntegerDivisionExp(s21_expended dividend,
                                             int divider) {
  s21_expended exp_divider = s21_decToExp(s21_simpleIntToDec(divider));
  return s21_simpleExpIntegerDivision(dividend, exp_divider);
}
