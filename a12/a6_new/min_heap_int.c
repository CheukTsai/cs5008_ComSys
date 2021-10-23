#include <stdio.h>
#include <stdlib.h>
#include "min_heap_int.h"

Heap *CreateHeap(int *data, int num_elems) {
  Heap *heap = (Heap*) malloc(sizeof(Heap));
  heap -> num_elems = num_elems;
  int i;
  for (i = 1; i <= num_elems; i++) {
    heap -> tree[i] = data[i - 1];
    if (i == 1) continue;
    int child = i;
    while (child != 1) {
      int parent = child / 2;
    // printf("parent = %d\n", heap -> tree[parent]);
      if (heap -> tree[child] < heap -> tree[parent]) {
        Swap(heap, child, parent);
      // printf("After change: \n");
      // printf("child = %d\n", heap -> tree[child]);
      // printf("parent = %d\n", heap -> tree[parent]);
      }
      child = parent;
    }
    // printf("child = %d\n", heap -> tree[child]);
  }
  return heap;
}

void Insert(Heap *heap, int val) {
  heap -> num_elems++;
  int spot = heap -> num_elems;
  heap -> tree[spot] = val;
  BubbleUp(heap, heap -> num_elems);
}

int ExtractMin(Heap* heap) {
  int min = heap -> tree[1];
  heap -> tree[1] = heap -> tree[heap -> num_elems];
  heap -> num_elems--;
  BubbleDown(heap, 1);
  return min;
}

void BubbleUp(Heap *heap, int index) {
  if (index == 0) return;

  int parent_index =(int) index / 2;
  int self = heap -> tree[index];
  int parent = heap -> tree[parent_index];
  if (parent > self) {
    Swap(heap, parent_index, index);
    BubbleUp(heap, parent_index);
  }
}

void BubbleDown(Heap *heap, int index) {
  if (index == 0) return;

  int current_index = index;
  int left_index = index*2;
  int right_index = index*2 + 1;
  if (current_index > heap -> num_elems ||
  left_index > heap -> num_elems ||
  right_index > heap -> num_elems) {
    return;
  }

  int current = heap -> tree[current_index];
  int left = heap -> tree[left_index];
  int right = heap -> tree[right_index];

  int min_child;
  int min_child_index;

  if (left < right) {
    min_child = left;
    min_child_index = left_index;
  } else {
    min_child = right;
    min_child_index = right_index;
  }

  if (min_child < current) {
    Swap(heap, current_index, min_child_index);
    BubbleDown(heap, min_child_index);
  } else {
    return;
  }
}

void Swap(Heap *heap, int first_ind, int second_ind) {
  int temp = heap -> tree[first_ind];
  heap -> tree[first_ind] = heap -> tree[second_ind];
  heap -> tree[second_ind] = temp;
}

void DestroyHeap(Heap *heap) {
  free(heap);
}

void Heapsort(int* data, int num_elems) {
  Heap* heap = CreateHeap(data, num_elems);
  int i;
  for (i = 1; i <= num_elems; i++) {
    data[i-1] = ExtractMin(heap);
  }
  DestroyHeap(heap);
}

void PrintArray(int* data, int num_elems) {
  int i = 0;
  printf("[");
  for (i = 0; i < num_elems; i++) {
    printf("%d ", data[i]);
  }
  printf("]\n");
}

void DoIntHeapsort(int num_elems) {
  // malloc an array to store random ints
  int* integers = (int*)malloc(sizeof(int) * num_elems);

  // Put random numbers in that array
  int i;
  for (i = 0; i < num_elems; i++) {
      integers[i] = rand() % 50;
  }

  // Create an array of pointers to those ints
  int* vals = malloc(sizeof(int) * num_elems);
  for (i = 0; i < num_elems; i++) {
    vals[i] = integers[i];
  }

  PrintArray(vals, num_elems);
  Heapsort(vals, num_elems);
  PrintArray(vals, num_elems);

  free(vals);
  free(integers);
}

int main() {
  // Set up some stuff
  int num_elems = 16;
  time_t t;
  srand(23);  // (unsigned) time(&t));
  DoIntHeapsort(num_elems);
}
