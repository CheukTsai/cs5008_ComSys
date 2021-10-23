/**
 *  CS 5008: Spr 2021
 *  Northeastern University, Seattle
 *  Lab 6: Testing with Google
 *
 *  Author: Adrienne H. Slaughter (02/25/2021)
 *  Modified for CS 5008 Summer 2021 (06/14/2021)
 */

#include <stdio.h>
#include <string.h>

#include "example1.h"
#include "Assert007.h"


// Given a non-zero integer, returns the squared value of that numbers.:
int SquareNumber(int num) {
  Assert007(num != 0);
  return (num * num);
}

// Given two non-zero integers, returns an int representing their sum.
int SumTwoNumbers(int first, int second) {
  Assert007(first != 0);
  Assert007(second != 0);
  return (first + second);
}

// Given two non-zero integers, returns an int representing their product.
int MultiplyTwoNumbers(int first, int second) {
  Assert007(first != 0);
  Assert007(second != 0);
  return (first * second);
}

// STEP 4: Implement your additional function here.
// Add a helpful Assert007 call that would set a breakpoint
// in your code (e.g. if your function takes a char* type,
// then check that this is not NULL)
char FindMidCharInString(const char *str) {
  Assert007(str != NULL);
  int mid = strlen(str)/2;
  Assert007(mid != 0);
  return *(str+mid);
}
