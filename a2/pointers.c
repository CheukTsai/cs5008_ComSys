#include <stdio.h>

void PointerTest(){
  int a = 1;
  int b = 2;
  int c = 3;
  int* p;
  int* q;

  p = &a;
  printf("a = %d\n", a);
  printf("after p = &a,\np = %d\n", p);
  printf("*p = %d\n\n", *p);

  q = &b;
  printf("b = %d\n", b);
  printf("after q = &b,\nq = %d\n", q);
  printf("*q = %d\n\n", *q);

}

int main(){
  PointerTest();
  return 0;
}
