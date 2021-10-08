
# String.h

![The String](misc/images/dec.jpg?raw=true "String")

## Information

| ENG | RUS |
|------|------|
| The Decimal value type represents decimal numbers ranging from positive 79,228,162,514,264,337,593,543,950,335 to negative 79,228,162,514,264,337,593,543,950,335. The default value of a Decimal is 0. | Тип Decimal представляет десятичные числа в диапазоне от положительных 79,228,162,514,264,337,593,543,950,335 до отрицательных 79,228,162,514,264,337,593,543,950,335. Значение Decimal по умолчанию равно 0. |
| When the result of the division and multiplication is passed to the Round method, the result suffers no loss of precision. | Когда результат деления и умножения передается методу округления, результат не страдает от потери точности. |
| A decimal number is a floating point value that consists of a sign, a numerical value where each digit in the value ranges from 0 to 9, and a scaling factor that indicates the position of a floating decimal point that separates the integral and fractional parts of the numerical value. | Decimal число - это значение с плавающей точкой, состоящее из знака, числового значения, где каждая цифра находится в диапазоне от 0 до 9, и коэффициента масштабирования, который указывает положение десятичной точки, разделяющей целые и дробные части числового значения. |
| The scaling factor also can preserve any trailing zeros in a Decimal number. Trailing zeros do not affect the value of a Decimal number in arithmetic or comparison operations. | Коэффициент масштабирования также может сохранять любые конечные нули в Decimal. Эти конечные нули не влияют на значение в арифметических операциях или операциях сравнения. |
| Note that the bit representation differentiates between negative and positive zero. These values can be treated as being equal in all operations. | Обрати внимание, что битовое представление различает отрицательные и положительные нули. Эти значения могут считаться эквивалентными во всех операциях. |
| The binary representation of a Decimal value consists of a 1-bit sign, a 96-bit integer number, and a scaling factor used to divide the 96-bit integer and specify what portion of it is a decimal fraction. The scaling factor is implicitly the number 10, raised to an exponent ranging from 0 to 28. Therefore, the binary representation of a Decimal value the form, ((-2^96 to 2^96) / 10^(0 to 28)), where -(2^96-1) is equal to MinValue, and 2^96-1 is equal to MaxValue. | Двоичное представление Decimal состоит из 1-разрядного знака, 96-разрядного целого числа и коэффициента масштабирования, используемого для деления 96-разрядного целого числа и указания того, какая его часть является десятичной дробью. Коэффициент масштабирования неявно равен числу 10, возведенному в степень в диапазоне от 0 до 28. Следовательно, двоичное представление Decimal имеет вид ((от -2^96 до 2^96) / 10^(от 0 до 28)), где -(2^96-1) равно минимальному значению, а 2^96-1 равно максимальному значению. |
| Decimal number can be implemented as a four-element array of 32-bit signed integers (`int bits[4];`). <br> `bits[0]`, `bits[1]`, and `bits[2]` contain the low, middle, and high 32 bits of the 96-bit integer number accordingly. <br>`bits[3]` contains the scale factor and sign, and consists of following parts: <br>- Bits 0 to 15, the lower word, are unused and must be zero. <br> - Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the power of 10 to divide the integer number. <br>- Bits 24 to 30 are unused and must be zero. <br> - Bit 31 contains the sign; 0 meaning positive, and 1 meaning negative. | Decimal число может быть реализовано в виде четырехэлементного массива 32-разрядных целых чисел со знаком (`int bits[4];`). <br> `bits[0]`, `bits[1]`, и `bits[2]` содержат младшие, средние и старшие 32 бита 96-разрядного целого числа соответственно.<br> `bits[3]` содержит коэффициент масштабирования и знак, и состоит из следующих частей:<br> - Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю;<br> - Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который указывает степень 10 для разделения целого числа; <br> - Биты с 24 по 30 не используются и должны быть равны нулю;<br> - Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный. |

### Structures:

#### Main:
```c
typedef struct 
{
    unsigned int bits[4];
} s21_decimal;
```


|bits[0](mantissa_1)|bits[1](mantissa_2)|bits[2](mantissa_3)|bits[3](significant)|
|---|---|---|---|
|[00000000 00000000 00000000 00000000]|[00000000 00000000 00000000 00000000]|[00000000 00000000 00000000 00000000]|[s0000000 cccccccc 00000000 000000ee]|

* s - sign symbol, c - scale number,  e - error bits.


#### Technical:
```c
//Expended decimal (mantissa x2+1 + sign + scale)
typedef struct s21_expended_decimal {
	unsigned int bits[7];
} s21_expended;
```
|  |   |
|---|---|
|bits[0](mantissa_1)|[00000000 00000000 00000000 00000000]|
|bits[1](mantissa_2)|[00000000 00000000 00000000 00000000]|
|bits[2](mantissa_3)|[00000000 00000000 00000000 00000000]|
|bits[3](mantissa_4)|[00000000 00000000 00000000 00000000]|
|bits[4](mantissa_5)|[00000000 00000000 00000000 00000000]|
|bits[5](mantissa_6)|[00000000 00000000 00000000 00000000]|
|bits[6](mantissa_7+sign+scale)|[s0000000 cccccccc 00000000 0000000m] |

* s - sign symbol, m - last mantissa symbol, c - scale number.


<br/>

### Errors 

#### Error codes
| Code | Name | Meaning | 
| ----- | ----- |-------|
| 5 | error_out_of_range | got out of range while trying to set or get a bit |
| 6 | error_wrong_value | trying to set wrong value to a bit (st but **1** or **0**) |
| 30 | error_scale_out_of_range | got from the scale range while setting scale (below **0** or over **28**) |

#### Error bits and codes

bits[3](significant) : [s0000000 cccccccc 00000000 000000ee] --  e - error bit
| Code | Binary |Meaning | 
| -----  |-------|-------|
| 0 |00|OK|
| 1 |01|the number is too large or equal to infinity|
| 2 |10|the number is too small or equal to negative infinity|
| 3 |11|division by 0|


### Service functions

| Done | Checked | Function | Function group |
| ----- | ----- |------------------------------------------------------------------------------------|----| 
| ✔ | ✔ | char s21_getbit (unsigned int bit, int index) | bit operations |
| ✔ | ✔ | char s21_getbitglobal (s21_decimal number, int index)|bit operations|
| ✔ | ✔ | void s21_setbit (unsigned int* bit, int index, char val) |bit operations|
| ✔ | ✔ | char s21_setbitglobal(s21_decimal* number, int index, char val) |bit operations|
| ✔ | ✔ | char s21_getsign(s21_decimal number) |sign operations|
| ✔ | ✔ | char s21_setsign(s21_decimal* number, char val) |sign operations|
| ✔ | ✔ | void s21_invertsign(s21_decimal* number) |sign operations|
| ✔ | ✔ | char s21_setscale(s21_decimal* number, int scale) |scale operations|
| ✔ | ✔ | void s21_zeroscale(s21_decimal* number) |scale operations|
| ✔ | ✔ | int s21_getscale(s21_decimal number) |scale operations|
| ✔ | ✔ |char s21_increseScaleUlt(s21_decimal* number, int value)|scale operations|
| ✔ | ✔ |char s21_increseScale(s21_decimal* number)|scale operations|
| ✔ | ✔ |char s21_decreseScale(s21_decimal* number)|scale operations|
| ✔ | ✔ |char s21_decreseScaleUlt(s21_decimal* number, int value)|scale operations|
| ✔ | ✔ |int s21_setPartMantissa(s21_decimal* decimal, int bit_index, int bit_value)|part of mantissa operations|
| ✔ | ✔ |unsigned int s21_getPartMantissa(s21_decimal* decimal, int bit_index)|part of mantissa operations|
| ✔ | ✔ |int s21_clearDecimal(s21_decimal* decimal)|decimal operations|
| ✔ | ✔ |int s21_copyDecimal(s21_decimal src, s21_decimal* dest)|decimal operations|
| ✔ | ✔ |int s21_leftShift32(s21_decimal* dec, int shift)|shift operations|
| ✔ | ✔ |int s21_leftShift(s21_decimal* dec, int shift)|shift operations|
| ✔ | ✔ |int s21_rightShift32(s21_decimal* dec, int shift)|shift operations|
| ✔ | ✔ |int s21_rightShift(s21_decimal* dec, int shift)|shift operations|
| ✔ | ✔ |int s21_printDecimalBinRev(s21_decimal dec)|printer operations|
| ✔ | ✔ |int s21_printDecimalBin(s21_decimal dec)|printer operations|
| ✔ | ✔ |functions from [Scaling_Commit: VI](../commits_list/Scaling_Commit.txt)|several|
| ✔ | ✔ |functions from [Comparison+_Commit: II:C-F](../commits_list/Compaison+_Commit.txt)|several|
| ✔ | ✔ |functions from [Arithmetic_Commit_1: II:A-B](../commits_list/Arithmetic_Commit_1.txt)|several|
| ✔ | ✔ |functions from [Arithmetic_Commit_2: I:A-B](../commits_list/Arithmetic_Commit_2.txt)|several|
| ✔ | ✔ |functions from [Arithmetic_Commit_3: I:B-C](../commits_list/Arithmetic_Commit_3.txt)|several|


### Arithmetic Operators

| Done | Checked | Operator name | Operators  | Function | 
| ----- | ----- | ------ | ------ |------------------------------------------------------------------------------------|
| ✔ | ✔ | Addition | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| ✔ | ✔ | Subtraction | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| ✔ | ✔ | Multiplication | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| ✔ | ✔ | Division | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

| ENG | RUS |
| ----- | ----- |
| The functions return the error code: <br> - 0 - OK <br> - 1 - the number is too large or equal to infinity <br>- 2 - the number is too small or equal to negative infinity <br>- 3 - division by 0 | Функции возвращают код ошибки:  <br> - 0 - OK  <br>- 1 - число слишком велико или равно бесконечности<br>- 2 - число слишком мало или равно отрицательной бесконечности<br>- 3 - деление на 0 |
| - *When getting numbers that do not fit into the mantissa during arithmetic operations, use bank rounding (for example, 79,228,162,514,264,337,593,543,950,335 - 0.6 = 79,228,162,514,264,337,593,543,950,334)* | - *При получении чисел, не вмещающихся в мантиссу при арифметических операциях, использовать банковское округление (например, 79,228,162,514,264,337,593,543,950,335 - 0.6 = 79,228,162,514,264,337,593,543,950,334)* |

### Comparison Operators

| Done | Checked | Operator name | Operators  | Function | 
| ----- | ----- | ------ | ------ | ------ |
| ✔ | ✔ | Less than | < | int s21_is_less(s21_decimal, s21_decimal) |
| ✔ | ✔ | Less than or equal to | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| ✔ | ✔ | Greater than | > |  int s21_is_greater(s21_decimal, s21_decimal) |
| ✔ | ✔ | Greater than or equal to | >= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| ✔ | ✔ | Equal to | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| ✔ | ✔ | Not equal to | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Return value:
- 0 - FALSE
- 1 - TRUE

### Convertors and parsers

| Done | Checked | Convertor/parser | Function | 
| ----- | ----- | ------ | ------ |
| ✔ | ✔ | From int  | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| ✔ | ✔ | From float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| ✔ | ✔ | To int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| ✔ | ✔ | To float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Return value - code error:
- 0 - OK
- 1 - convertation error (ошибка конвертации)

| *Note on the conversion of a float type number:* | *Уточнение про преобразование числа типа float:* |
| --- | --- |
| - *If the numbers are too small (0 < &#124;x&#124; < 1e-28), return an error and value equal to 0* <br> - *If the numbers are too large (&#124;x&#124; > 79,228,162,514,264,337,593,543,950,335) or are equal to infinity, return an error* <br> - *When processing a number with the float type, convert all the significant decimal digits contained in it. If there are more than 7 such digits, the number is rounded to the closest one that does not have more than 7 significant decimal digits.* | - *Если числа слишком малы (0 < &#124;x&#124; < 1e-28), вернуть ошибку и значение, равное 0* <br> - *Если числа слишком велики (&#124;x&#124; > 79,228,162,514,264,337,593,543,950,335) или равны бесконечности, вернуть ошибку* <br> - *При обработке числа с типом float преобразовывать все содержащиеся в нём значимые десятичные цифры. Если таких цифр больше 7, то значение числа округляется к ближайшему, у которого не больше 7 значимых цифр.* |

<br/>

| *Note on the conversion from decimal type to int:* | *Уточнение про преобразование из числа типа decimal в тип int:* |
| --- | --- |
| - *If there is a fractional part in a decimal number, it should be discarded (for example, 0.9 is converted to 0)* | - *Если в числе типа decimal есть дробная часть, то её следует отбросить (например, 0.9 преобразуется 0)* |


### Another functions

| Done | Check | Function | Description | Описание |
| --- | --- | ---------- | ---------- | ---------- |
| ✔ | ✔ | int s21_floor(s21_decimal value, s21_decimal *result) |	 Rounds a specified Decimal number to the closest integer toward negative infinity. | Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности. |
| ✔ | ✔ | int s21_round(s21_decimal value, s21_decimal *result) |  Rounds a decimal value to the nearest integer. | Округляет Decimal до ближайшего целого числа. |
| ✔ | ✔ | int s21_truncate(s21_decimal value, s21_decimal *result) | Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes. | Возвращает целые цифры указанного Decimal числа; любые дробные цифры отбрасываются, включая конечные нули. |
| ✔ | ✔ | int s21_negate(s21_decimal value, s21_decimal *result) | Returns the result of multiplying the specified Decimal value by negative one. | Возвращает результат умножения указанного Decimal на -1. |

Return value - code error:
- 0 - OK
- 1 - calculation error

## Chapter III

## Part 1. Implementation of the decimal.h library functions

| Done | The functions of the decimal.h library described [above](#information) must be implemented: | Тебе необходимо реализовать описанные [выше](#information) функции библиотеки: |
| --- | ---------- | ---------- |
| ✔ |- The library must be developed in C language of C11 standard using gcc compiler; | - Библиотека должна быть разработана на языке С стандарта C11 с использованием компиятора gcc; |
| ✔ |- The library code must be located in the src folder on the develop branch;    | - Код библиотеки должен находиться в папке src в ветке develop; |
| ✔ |- Do not use outdated and legacy language constructions and library functions. Pay attention to the legacy and obsolete marks in the official documentation on the language and the libraries used. Use the POSIX.1-2017 standard; | - Не используй устаревшие и выведенные из употребления конструкции языка и библиотечные функции. Обрати внимания на пометки legacy и obsolete в официальной документации по языку и используемым библиотекам. Ориентируйся на стандарт POSIX.1-2017; |
| ✔ |- When writing code it is necessary to follow the Google style; | - При написании кода необходимо придерживаться Google Style; |
| ✔ |- Make it as a static library named *s21_decimal* (with the s21_decimal.h header file); | - Оформи решение как статическую библиотеку с названием *s21_decimal.a* (с заголовочным файлом s21_decimal.h); |
| ✔ |- The library must be developed according to the principles of structured programming; | - Библиотека должна быть разработана в соответствии с принципами структурного программирования; |
| ✔ |- Use prefix s21_ before each function; | - Перед каждой функцией используй префикс s21_; |
| ✔ |- Prepare full coverage of library functions code with unit-tests using the Check library; | - Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check;  |
| ✔ |- Unit tests must cover at least 80% of each function (checked using gcov);   | - Unit-тесты должны покрывать не менее 80% каждой функции; |
| ✔ |- Provide a Makefile for building the library and tests (with targets all, clean, test, s21_decimal.a, gcov_report); | - Предусмотри Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_decimal.a, gcov_report); |
| ✔ |- The gcov_report target should generate a gcov report in the form of an html page. Unit tests must be run with gcov flags to do this; | - В цели gcov_report должен формироваться отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov;   |
| ✔ |- When implementing decimal, stick to [the binary representation](#binary-representation) with the integer `bits` array as specified in the [example above](#example). Observe the position of the digits of a number in the `bits` array; | - При реализации decimal ориентируйся на [двоичное представление](#двоичное-представление) с целочисленным массивом `bits`, как указано в [примере выше](#пример). Соблюдай положение разрядов числа в массиве `bits`; |
| ✔ |- It is forbidden to use the __int128 type; | - Запрещено использование типа __int128; |
| ✔ |- Trailing zeros can be as preserved as deleted (except for the `s21_truncate` function); | - Конечные нули можно как оставлять, так и удалять (за исключением функции `s21_truncate`); |
| ✔ |- The defined type must support numbers from -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335. | - Определяемый тип должен поддерживать числа от -79,228,162,514,264,337,593,543,950,335 до +79,228,162,514,264,337,593,543,950,335. |
