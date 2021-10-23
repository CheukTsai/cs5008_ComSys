#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.h"
#include <sys/time.h>
#include <unistd.h>  
#include <string.h>

extern int optind,opterr,optopt;
extern char *optargi;

void PrintArray(int* array, int num_elems) {
  int i;
  printf("[");
  for (i = 0; i < num_elems; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

int CheckArray(int* array, int num_elems) {
  int i;
  for (i = 1; i < num_elems; i++) {
    if (array[i] < array[i - 1]) {
      printf("NOT SORTED!!!\n");
      return 0;
    }
  }
  printf("SORTED!!\n");
  return 1;
}

void AlgA(){
  printf("Alg A:\t\t");
  struct timeval begin, end;
  int num_elems1 = 16;
  int* integers1 = (int*)malloc(sizeof(int) * num_elems1);
  int i;
  for (i = 0; i < num_elems1; i++) {
    integers1[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  long seconds = (end.tv_sec - begin.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems2 = 64;
  int* integers2 = (int*)malloc(sizeof(int) * num_elems2);
  for (i = 0; i < num_elems2; i++) {
    integers2[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  

  int num_elems3 = 128;
  int* integers3 = (int*)malloc(sizeof(int) * num_elems3);
  for (i = 0; i < num_elems3; i++) {
    integers3[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems4 = 256;
  int* integers4 = (int*)malloc(sizeof(int) * num_elems4);
  for (i = 0; i < num_elems4; i++) {
    integers4[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems5 = 512;
  int* integers5 = (int*)malloc(sizeof(int) * num_elems5);
  for (i = 0; i < num_elems5; i++) {
    integers5[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  int num_elems6 = 1024;
  int* integers6 = (int*)malloc(sizeof(int) * num_elems6);
  for (i = 0; i < num_elems6; i++) {
    integers6[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems7 = 2048;
  int* integers7 = (int*)malloc(sizeof(int) * num_elems7);
  for (i = 0; i < num_elems7; i++) {
    integers7[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Quicksort(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  printf("\n\nAlg A (sorted):\t");
  
  
  gettimeofday(&begin, NULL);
  Quicksort(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Quicksort(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  Quicksort(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  Quicksort(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Quicksort(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Quicksort(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Quicksort(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);  
  
  free(integers1);
  free(integers2);
  free(integers3);
  free(integers4);
  free(integers5);
  free(integers6);
  free(integers7);
  
  printf("\n\n");
}

void AlgB(){
  printf("Alg B:\t\t");
  struct timeval begin, end;
  int num_elems1 = 16;
  int* integers1 = (int*)malloc(sizeof(int) * num_elems1);
  int i;
  for (i = 0; i < num_elems1; i++) {
    integers1[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  long seconds = (end.tv_sec - begin.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems2 = 64;
  int* integers2 = (int*)malloc(sizeof(int) * num_elems2);
  for (i = 0; i < num_elems2; i++) {
    integers2[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  

  int num_elems3 = 128;
  int* integers3 = (int*)malloc(sizeof(int) * num_elems3);
  for (i = 0; i < num_elems3; i++) {
    integers3[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems4 = 256;
  int* integers4 = (int*)malloc(sizeof(int) * num_elems4);
  for (i = 0; i < num_elems4; i++) {
    integers4[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems5 = 512;
  int* integers5 = (int*)malloc(sizeof(int) * num_elems5);
  for (i = 0; i < num_elems5; i++) {
    integers5[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  int num_elems6 = 1024;
  int* integers6 = (int*)malloc(sizeof(int) * num_elems6);
  for (i = 0; i < num_elems6; i++) {
    integers6[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems7 = 2048;
  int* integers7 = (int*)malloc(sizeof(int) * num_elems7);
  for (i = 0; i < num_elems7; i++) {
    integers7[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  printf("\n\nAlg B (sorted):\t");
  
  
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  QuicksortRandom(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  QuicksortRandom(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  QuicksortRandom(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);  
  
  free(integers1);
  free(integers2);
  free(integers3);
  free(integers4);
  free(integers5);
  free(integers6);
  free(integers7);
  
  printf("\n\n");
}

void AlgC(){
  printf("Alg C:\t\t");
  struct timeval begin, end;
  int num_elems1 = 16;
  int* integers1 = (int*)malloc(sizeof(int) * num_elems1);
  int i;
  for (i = 0; i < num_elems1; i++) {
    integers1[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  long seconds = (end.tv_sec - begin.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems2 = 64;
  int* integers2 = (int*)malloc(sizeof(int) * num_elems2);
  for (i = 0; i < num_elems2; i++) {
    integers2[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  

  int num_elems3 = 128;
  int* integers3 = (int*)malloc(sizeof(int) * num_elems3);
  for (i = 0; i < num_elems3; i++) {
    integers3[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems4 = 256;
  int* integers4 = (int*)malloc(sizeof(int) * num_elems4);
  for (i = 0; i < num_elems4; i++) {
    integers4[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems5 = 512;
  int* integers5 = (int*)malloc(sizeof(int) * num_elems5);
  for (i = 0; i < num_elems5; i++) {
    integers5[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  int num_elems6 = 1024;
  int* integers6 = (int*)malloc(sizeof(int) * num_elems6);
  for (i = 0; i < num_elems6; i++) {
    integers6[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems7 = 2048;
  int* integers7 = (int*)malloc(sizeof(int) * num_elems7);
  for (i = 0; i < num_elems7; i++) {
    integers7[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  Median(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  printf("\n\nAlg C (sorted):\t");
  
  
  gettimeofday(&begin, NULL);
  Median(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Median(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  Median(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  Median(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Median(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Median(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  Median(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);  
  
  free(integers1);
  free(integers2);
  free(integers3);
  free(integers4);
  free(integers5);
  free(integers6);
  free(integers7);
  
  printf("\n\n");
}

void AlgD(){
  printf("Alg D:\t\t");
  struct timeval begin, end;
  int num_elems1 = 16;
  int* integers1 = (int*)malloc(sizeof(int) * num_elems1);
  int i;
  for (i = 0; i < num_elems1; i++) {
    integers1[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  long seconds = (end.tv_sec - begin.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems2 = 64;
  int* integers2 = (int*)malloc(sizeof(int) * num_elems2);
  for (i = 0; i < num_elems2; i++) {
    integers2[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  

  int num_elems3 = 128;
  int* integers3 = (int*)malloc(sizeof(int) * num_elems3);
  for (i = 0; i < num_elems3; i++) {
    integers3[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems4 = 256;
  int* integers4 = (int*)malloc(sizeof(int) * num_elems4);
  for (i = 0; i < num_elems4; i++) {
    integers4[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  
  int num_elems5 = 512;
  int* integers5 = (int*)malloc(sizeof(int) * num_elems5);
  for (i = 0; i < num_elems5; i++) {
    integers5[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  int num_elems6 = 1024;
  int* integers6 = (int*)malloc(sizeof(int) * num_elems6);
  for (i = 0; i < num_elems6; i++) {
    integers6[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  int num_elems7 = 2048;
  int* integers7 = (int*)malloc(sizeof(int) * num_elems7);
  for (i = 0; i < num_elems7; i++) {
    integers7[i] = (rand() % 90) + 10;
  }
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  printf("\n\nAlg D (sorted):\t");
  
  
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers1, 0, num_elems1 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers2, 0, num_elems2 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  HybridQuicksort(integers3, 0, num_elems3 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);

  gettimeofday(&begin, NULL);
  HybridQuicksort(integers4, 0, num_elems4 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers5, 0, num_elems5 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers6, 0, num_elems6 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);
  
  gettimeofday(&begin, NULL);
  HybridQuicksort(integers7, 0, num_elems7 - 1);
  gettimeofday(&end, NULL);
  seconds = (end.tv_sec - begin.tv_sec);
  micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
  printf("%d\t", micros);  
  
  free(integers1);
  free(integers2);
  free(integers3);
  free(integers4);
  free(integers5);
  free(integers6);
  free(integers7);
  
  printf("\n\n");
}


int main(int argc,char** argv) {
  printf("\t\t16\t64\t128\t256\t512\t1024\t2048\n");
  printf("-----------------------------------------------------------\n");
    int i;
    if(argc == 1){
    return 0;
    }
    if(argv[1][1] == 'a' && argv[1][2] == 'l' && argv[1][3] == 'l'){
      AlgA();
      AlgB();
      AlgC();
      AlgD();
      return 0;
    }
    for(i = 1; i<sizeof(argv[1]); i++){

    if(argv[1][i] == 'a'){
      AlgA();
    }
    else if(argv[1][i] == 'b'){
      AlgB();
    }
    else if(argv[1][i] == 'c'){
      AlgC();
    }
    else if(argv[1][i] == 'd'){
      AlgD();
    }
  }
  return 0;
}

