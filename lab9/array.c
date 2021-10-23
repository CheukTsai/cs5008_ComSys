#include <stdio.h>

int main(){
  int* myArray = (int*)malloc(sizeof(int)*400);
  myArray[0]=72;
  myArray[70]=56; 
  printf("myArray[0] = %d", myArray[0]);
  printf("myArray[72] = %d", myArray[72]);
  return 0;
}