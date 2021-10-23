#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT 3

void CalculateAverageMark() {
  float marks[STUDENT], sum = 0;
  int i;

  printf("Collecting student marks...\n");
  for (i = 0; i < STUDENT; i++) {
    printf("Enter marks for %d student: ", i+1);
    scanf("%f", &marks[i]);
  }

  // calculate sum
  for (i = 0; i < STUDENT; i++) {
    sum += marks[i];
  }

  printf("\nAverage marks = %.2f\n\n", sum/STUDENT);
}

void CalculateAverageMark2() {
  float *p, sum = 0;
  int i, n;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  // allocate memory to store n variables of type float
  p = (float*)malloc(n * sizeof(float));

  // if dynamic allocation failed exit the program
  if (p == NULL) {
    printf("Memory allocation failed");
    exit(1); // exit the program
  }

  printf("Collecting student marks...\n");
  // ask the student to enter marks
  for (i = 0; i < n; i++) {
    printf("Enter marks for %d student: ", i+1);
    scanf("%f", p+i);
  }

  // calculate sum
  for (i = 0; i < n; i++) {
    sum += *(p+i);
  }
  // free(p);
  printf("\nAverage marks = %.2f\n\n", sum/n);
}

int main() {
  CalculateAverageMark();
  CalculateAverageMark2();

 return 0;
}
