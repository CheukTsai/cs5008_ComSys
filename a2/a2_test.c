#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"

Name name1;
Name name2;
Name name3;
Name name4;
Name name5;

void Init() {
  srand(time(NULL));

  name1.first = "Alyssa";
  name1.middle = "Mary";
  name1.last = "Antle";
  name1.age = 18;

  name2.first = "BeN";
  name2.middle = "ivan";
  name2.last = "bitDiDdle";
  name2.age = 32;

  name3.first = "Cassie";
  name3.middle = "Maria";
  name3.last = "Charstrup";
  name3.age = 64;

  name4.first = "Daniel";
  name4.last = "Diamond";
  name4.age = 42;

  name5.first = "AnyA";
  name5.last = "DOE";
  name5.age = 18;
}


void StartTest(const char *test) {
  static int count = 1;
  printf("Test #%d: %s\n\n", count++, test);
}

void EndTest() {
  printf("\n--------------------------------\n\n");
}


void TestBig() {
  StartTest("Print Big");
  char dest[50] = {};

  Big(&name1, dest);
  printf("%s\n", dest);
  Big(&name2, dest);
  printf("%s\n", dest);
  Big(&name4, dest);
  printf("%s\n", dest);

  EndTest();
}

void TestLast() {
  StartTest("Print Last");
  char dest[100] = {}; 

  Last(&name2, dest);
  printf("%s\n", dest);
  Last(&name4, dest);
  printf("%s\n", dest);

  EndTest();
}

void TestReg() {
  StartTest("Print Reg");
  char dest[100] = {}; 

  Reg(&name3, dest);
  printf("%s\n", dest);
  Reg(&name4, dest);
  printf("%s\n", dest);

  EndTest();
}

void TestMid() {
  StartTest("Print Mid");
  char dest[100] = {}; 

  Mid(&name4, dest);
  printf("%s\n", dest);
  Mid(&name1, dest);
  printf("%s\n", dest);

  EndTest();
}

void TestSmall() {
  StartTest("Print Small");
  char dest[100] = {}; 

  Small(&name4, dest);
  printf("%s\n", dest);
  Small(&name2, dest);
  printf("%s\n", dest);

  EndTest();
}

void TestFormatName() {
  StartTest("Print FormatName");
  char dest[100] = {}; 

  FormatName(&name1, 'B');
  printf("\n");
  FormatName(&name1, 'L');
  printf("\n");
  FormatName(&name1, 'r');
  printf("\n");
  FormatName(&name1, 'M');
  printf("\n");
  FormatName(&name1, 'S');
  printf("\n");

  FormatName(&name4, 'B');
  printf("\n");
  FormatName(&name4, 'l');
  printf("\n");
  FormatName(&name4, 'R');
  printf("\n");
  FormatName(&name4, 'm');
  printf("\n");
  FormatName(&name4, 'S');
  printf("\n");

  EndTest();
}

void TestFillName() {
  StartTest("Print FillName");

  char dest[100] = {0};
  FillName(&name1, 'b', dest);
  printf("%s\n", dest);
  
  char dest1[100] = {0};
  FillName(&name1, 'l', dest1);
  printf("%s\n", dest1);

  char dest2[100] = {0};
  FillName(&name2, 'm', dest2);
  printf("%s\n", dest2);
 
  char dest3[100] = {0};
  FillName(&name5, 's', dest3);
  printf("%s\n", dest3);

  char dest4[100] = {0};
  FillName(&name5, 'w', dest4);
  printf("%s\n", dest4);
 
  EndTest();
}


int main(void) {
  Init();

  TestBig();
  TestLast();
  TestReg();
  TestMid();
  TestSmall();
  TestFormatName();
  TestFillName();
  
  printf("feel free to add your own!\n");

  return EXIT_SUCCESS;
}
