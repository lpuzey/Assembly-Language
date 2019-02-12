/* 
 * CS:APP Data Lab 
 * 
 * <Linda Puzey lpuzey>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
 int byte = 0x55; //this is a hexadecimal mask with the odd digits as one
 int word = byte | byte<<8; //the left shift is to make the bit size bigger. The OR is to set the rest of the digits to alternating ones
 return word | word<<16; //the left shift on work will increase the size to 32 bits. The OR will correctly set everything so the even-numbered bits are set to 1

}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
 int i = x+1; //to check if the number inputed is Tmax, if it is, it will become the min
 x=~(x+i); //add to i so you can get all ones
 i=!i; //bang will produce a boolean
 x=!(x+i);//if x is all ones, then it will become zero
 return x;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
 int left = (~x&y);//inverse order of AND
 int right = (x&~y);  //inverse order of AND
 return ~(~left & ~right);//this is based on the property we discussed in lab
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  return z^(((!x)+~0)&(y^z));//masking out z and y
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
 x=x|x>>1;
 x=x|x>>2;
 x=x|x>>4;
 x=x|x>>8;
 x=x|x>>16;//shifting to 32 bits
 x=x&((~x>>1)^(1<<31));  //strips all the other numbers by inverting and shifting
 return x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
 int isn = x>> 31; //accounts for significant bit
 int a = ((isn & 1)<< n) + isn;  
 return (x+a)>>n; //adds 1 if x was negative and 0 if x was positive
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
 int sign = x>> 31;//sifting for the signifcant bit
 return (!(sign));//produces a boolean, if the signifcant bit is 1, it returns 0, otherwise it returns 1

}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
 int sm = x >> 31;
 int s = sm & 1;
 int m2 = x + x;
 int m2s = (m2 >> 31) & 1;
 int m3 = m2 + x;
 int m3s = (m3 >> 31) & 1;//gets x inbetween 
 int o = (s ^ m2s) | (m2s ^ m3s); //checks for overflow
 int om = (o << 31) >> 31;
 int oc = (~sm) ^ (0x01 << 31);
 int z = (om & oc) | ((~om) & m3); //checks for overflow
return z;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
 int value = !((x + ~y) >> 31); // tests if x is larger and returns 0 or 1 accordingly
 x = x >> 31;//shifting to get a boolean value of x
 y = y >> 31;//shifting to get a boolean value of x
 int z = ((!x) & y) | (value & ((!x) |y));//returns 0 when x is greater
 return z;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
 int sign = 1 << 31; //shifting for significant bit
 int upperBound = ~(sign | 0x39); //if x is greater than it goes negative
 int lowerBound = ~0x30;//if x is less than then it is negative
 upperBound = sign & (upperBound + x) >> 31;//checks the sign bit
 lowerBound = sign & (lowerBound + 1 + x) >> 31;
 int z = !(upperBound | lowerBound); //check for negative and desired range
return z;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x){
 int sign = (x >> 31) & 1; //shifting for significant bit 
 int bss = sign << 3;//divide by eight
 int bs = ~sign + 1;
 int fbd = ((x & (0xFF << 24)) + bss + bs) >> 3;
 int rb = (x & ~(0xFF << 24));    
 int z = (fbd << 2)+ fbd + ((((rb << 2) + rb) + bss + bs) >> 3); //multiplying by five and combining
return z;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
 int r = 0;
r = (!!(x >> 16)) << 4;//converting to 32 bit and changing to producing 1 or 0
r = r + ((!!(x >> (r + 8))) << 3);//changing based on previous result
r = r + ((!!(x >> (r + 4))) << 2);
r = r + ((!!(x >> (r + 2))) << 1);
r = r + (!!(x >> (r + 1)));  
return r;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 int nanCheck = 0x0000000FF << 23; //making all the 8 exponent bits all ones
 int mantissa = 0x7FFFFF & uf;//contains fraction value
 if ((nanCheck & uf) == nanCheck && mantissa) //return if exp bits are all one 
 return uf;
 return uf ^ (1 << 31); //flip the sign bit
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
 int e = 158;
 int mask = 1<<31;
 int sign = x&mask;
 int frac;
 if(x == mask)
	return mask | (158<<23);
 if(!x)
	return 0;
 if(sign)
	x = ~x + 1;
 while(!(x&mask)){ //checking the mask
	x=x<<1;
	e=e - 1;
}
 frac = (x &(~mask)) >> 8;
 if(x&0x80 && ((x& 0x7F) > 0 || frac & 1)) //rounding
	frac = frac + 1;
 return sign + (e << 23) + frac; //putting x into 23 3bits
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
unsigned expn = (uf >> 23) & 0xFF;
unsigned sign = uf & 0x80000000;
unsigned frac = uf & 0x007FFFFF;
 if(expn == 255 || (expn == 0 && frac == 0)) // case for the function
  return uf;
 if (expn){ //checks nan
  expn++;
}else if (frac == 0x7FFFFF){//checks nonzero
 frac--;
 expn++;
}else {
 frac <<= 1;
}
return (sign) | (expn << 23) | (frac); 
}



