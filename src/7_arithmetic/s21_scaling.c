#include "s21_arithmetic.h"

//     123/1000        56/100000
// Usual
// scaling---------------------------------------------------------------------------------------------------------------------------
//  (ﾉ◕ヮ◕)ﾉ    (I'm the main scaling function! I make 2 decimals have same
//  scale.)
void s21_scaling(s21_decimal *num1, s21_decimal *num2) {
  int scale_1 = s21_getScale(*num1), scale_2 = s21_getScale(*num2);
  if (scale_1 > scale_2) {
    scale_2 = s21_singleScaleChange(num2, scale_1 - scale_2);
    if (scale_2 != 0) scale_1 = s21_singleScaleChange(num1, -scale_2);
  } else if (scale_1 < scale_2) {
    scale_1 = s21_singleScaleChange(num1, scale_2 - scale_1);
    if (scale_1 != 0) scale_2 = s21_singleScaleChange(num2, -scale_1);
  }
}

//  (ﾉ◕ヮ◕)ﾉ    (I can re-scale a decimal by ADDing scale, but only if the
//  adding scale is right (no overflow). If add_scale is negative I will just
//  cat the number)
s21_decimal s21_simpleSingleScaleAdd(s21_decimal num, int add_scale) {
  s21_decimal result = ZERO_DECIMAL;
  int new_scale = s21_getScale(num) + add_scale;
  s21_copyDecimal(num, &result);
  if (add_scale < 0) {
    add_scale *= (-1);
    for (; add_scale > INTMAXRANK; add_scale -= INTMAXRANK) {
      result = s21_simpleIntIntegerDivision(result, pow(10, INTMAXRANK));
    }
    result = s21_simpleIntIntegerDivision(result, pow(10, add_scale));
  } else {
    for (; add_scale > INTMAXRANK; add_scale -= INTMAXRANK) {
      result = s21_simpleIntMultiplication(result, pow(10, INTMAXRANK));
    }
    result = s21_simpleIntMultiplication(result, pow(10, add_scale));
  }
  s21_setScale(&result, new_scale);
  s21_setSign(&result, s21_getSign(num));
  return result;
}

//  (ﾉ◕ヮ◕)ﾉ    (I can scale a decimal (give it a NEW scale), but only if the
//  new scale is right (not overflow))
s21_decimal s21_simpleSingleScale(s21_decimal num, int new_scale) {
  if (new_scale < 0) {
    s21_setErrorbitsOne(&num);
    return num;
  } else {
    s21_zeroScale(&num);
    return s21_simpleSingleScaleAdd(num, new_scale);
  }
}

//  (ﾉ◕ヮ◕)ﾉ    (I can change the scale of a decimal if the adding scale is
//  positive. I return the delta of input scale and possible scale)
int s21_singleScaleChangeIncr(s21_decimal *num, int add_scale) {
  int delta_scale = 0, num_rank = s21_rankOfNumber(*num), pos_delta_scale = 0,
      present_scale = s21_getScale(*num);
  pos_delta_scale = SCALE_MAX - present_scale;
  delta_scale = MAXRANK - num_rank;
  if (add_scale <= pos_delta_scale) {
    pos_delta_scale = 0;
  } else {  // add_scale>pos_delta_scale
    pos_delta_scale = add_scale - pos_delta_scale;
    add_scale -= pos_delta_scale;
  }

  if (add_scale <= delta_scale) {
    *num = s21_simpleSingleScaleAdd(*num, add_scale);
    delta_scale = 0;
  } else {
    *num = s21_simpleSingleScaleAdd(*num, delta_scale);
    delta_scale = add_scale - delta_scale;
  }

  return delta_scale + pos_delta_scale;
}

//  (ﾉ◕ヮ◕)ﾉ    (I can change the scale of a decimal if the adding scale is
//  negative. If the scale is too big, I will dismantle the number.)
int s21_singleScaleChangeDecr(s21_decimal *num, int add_scale) {
  int num_rank = s21_rankOfNumber(*num), present_scale = s21_getScale(*num);

  if (-add_scale > present_scale) {
    s21_setScale(num, -add_scale);
  }
  /*
  //if one abowe get replaces with this - won't let you dismentle the number
  totally part (was not tested) if(-add_scale<=present_scale){
      pos_delta_scale=0;
  }
  else{  // |add_scale| > present_scale
      pos_delta_scale=add_scale+present_scale;
      add_scale=-pos_delta_scale;
  }
  */

  if (-add_scale <= num_rank) {
    *num = s21_simpleSingleScaleAdd(*num, add_scale);
  } else {  // |add_scale| > num_rank
    *num = s21_simpleSingleScaleAdd(*num, -num_rank);
    if (-add_scale > present_scale)
      s21_setScale(num, 0);
    else
      s21_setScale(num, present_scale + add_scale);
  }
  add_scale += present_scale;
  /*
  //if one abowe get replaces with this - won't let you dismentle the number
  totall part (was not tested) if(-add_scale<num_rank){
      *num=s21_simpleSingleScaleAdd(*num,add_scale);
      delta_scale=0;
  }
  else{   // |add_scale| >= num_ranky
      *num=s21_simpleSingleScaleAdd(*num,num_rank-1);
      delta_scale=add_scale+num_rank-1;
  }
  */
  return add_scale;
}

//  (ﾉ◕ヮ◕)ﾉ    (I can change the scale of a decimal. If the adding scale is
//  positive I return the delta of scale and possible scale)
int s21_singleScaleChange(s21_decimal *num, int add_scale) {
  if (add_scale >= 0)
    return s21_singleScaleChangeIncr(num, add_scale);
  else
    return s21_singleScaleChangeDecr(num, add_scale);
}

//  (ﾉ◕ヮ◕)ﾉ    ( I  can tell you how big the number is in a terms of ranks )
int s21_rankOfNumber(s21_decimal num) {
  int res = 0;
  s21_decimal sample = ZERO_DECIMAL;
  s21_setBitGlobal(&sample, 0, 1);
  for (; s21_decimalCompare(num, sample) >= 0 && res < MAXRANK; res++) {
    sample = s21_simpleIntMultiplication(sample, TEN);
  }
  return res;
}

// 10 000 000 000 000 000 000 000 000 000
// 79 228 162 514 264 337 593 543 950 335

// More accurate scaling for different
// approach----------------------------------------------------------------------------------
//   (ﾉ◕ヮ◕)ﾉ    (I'm the main scaling function #2! I make 2 expendeds have same
//   scale.)
int s21_scalingExp(s21_expended *num1, s21_expended *num2) {
  int scale_1 = s21_getScaleExp(*num1), scale_2 = s21_getScaleExp(*num2);
  if (scale_1 > scale_2) {
    scale_1 = s21_singleScaleExpChange(num2, scale_1 - scale_2);
  } else if (scale_1 < scale_2) {
    scale_1 = s21_singleScaleExpChange(num1, scale_2 - scale_1);
  } else
    scale_1 = 0;
  return scale_1;
}

//  (ﾉ◕ヮ◕)ﾉ    (I can re-scale a expended by ADDing scale, but only if the
//  adding scale is right (no overflow). If add_scale is negative I will just
//  cat the number.)
s21_expended s21_simpleSingleScaleExpAdd(s21_expended num, int add_scale) {
  s21_expended result = ZERO_EXPENDED;
  int new_scale = s21_getScaleExp(num) + add_scale;
  s21_copyExpended(num, &result);
  if (add_scale < 0) {
    add_scale *= (-1);
    for (; add_scale > INTMAXRANK; add_scale -= INTMAXRANK) {
      result = s21_simpleIntIntegerDivisionExp(result, pow(TEN, INTMAXRANK));
    }
    result = s21_simpleIntIntegerDivisionExp(result, pow(TEN, add_scale));
  } else {
    for (; add_scale > INTMAXRANK; add_scale -= INTMAXRANK) {
      result = s21_simpleExpIntMultiplication(result, pow(TEN, INTMAXRANK));
    }
    result = s21_simpleExpIntMultiplication(result, pow(TEN, add_scale));
  }
  s21_setScaleExp(&result, new_scale);
  s21_setSignExp(&result, s21_getSignExp(num));
  return result;
}

//  (ﾉ◕ヮ◕)ﾉ    (I can change the scale of a expended by adding scale. I return
//  the delta of input scale and possible scale.)
int s21_singleScaleChangeExpIncr(s21_expended *num,
                                 int add_scale) {  // not checked independently
  int delta_scale = 0, num_rank = s21_rankOfNumberExp(*num);
  delta_scale = MAXRANKEXP - num_rank;
  if (add_scale <= delta_scale) {
    *num = s21_simpleSingleScaleExpAdd(*num, add_scale);
    delta_scale = 0;
  } else {
    *num = s21_simpleSingleScaleExpAdd(*num, delta_scale);
    delta_scale = add_scale - delta_scale;
  }

  return delta_scale;
}

//  (ﾉ◕ヮ◕)ﾉ    (I can change the scale of a expended if the adding scale is
//  negative. If the scale is too big, I will dismantle the number.)
int s21_singleScaleChangeExpDecr(s21_expended *num,
                                 int add_scale) {  // not checked independently
  int num_rank = s21_rankOfNumberExp(*num),
      present_scale = s21_getScaleExp(*num);

  if (-add_scale > present_scale) {
    s21_setScaleExp(num, -add_scale);
  }

  if (-add_scale <= num_rank) {
    *num = s21_simpleSingleScaleExpAdd(*num, add_scale);
  } else {  // |add_scale| > num_rank
    *num = s21_simpleSingleScaleExpAdd(*num, -num_rank);
    if (-add_scale > present_scale)
      s21_setScaleExp(num, 0);
    else
      s21_setScaleExp(num, present_scale + add_scale);
  }
  add_scale += present_scale;

  return add_scale;
}

//  (ﾉ◕ヮ◕)ﾉ    ( I  can tell you how big the expended number is in a terms of
//  ranks.)
int s21_rankOfNumberExp(s21_expended num) {
  int res = 0;
  s21_expended sample = ZERO_EXPENDED;
  s21_setBitGlobalExp(&sample, 0, 1);
  for (; s21_expendedCompare(num, sample) >= 0 && res < MAXRANKEXP; res++) {
    sample = s21_simpleExpIntMultiplication(sample, TEN);
  }
  return res;
}

//  (ﾉ◕ヮ◕)ﾉ    (I know what function to ask for changing the scale of the
//  expected, depends of if adding scale is positive or negative.)
int s21_singleScaleExpChange(s21_expended *num, int add_scale) {
  if (add_scale >= 0)
    return s21_singleScaleChangeExpIncr(num, add_scale);
  else
    return s21_singleScaleChangeExpDecr(num, add_scale);
}
