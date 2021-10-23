#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "min_heap_int.h"

Heap *CreateHeap(int *data, int num_elems) {
  Heap *heap = (Heap*) malloc(sizeof(Heap));
  heap -> num_elems = 0;
  int i;
  for (i = 0; i < num_elems; i++) {
    heap -> binary_tree[i] = 0;
  }
  for (i = 0; i < num_elems; i++) {
    Insert(heap, data[i]);
  }
  return heap;
}

void Insert(Heap *heap, int val) {
  heap -> num_elems++;
  int spot = heap -> num_elems;
  heap -> binary_tree[spot] = val;
  BubbleUp(heap, heap -> num_elems);
}

void BubbleUp(Heap *heap, int index) {
  if (index == 1) return;

  int parent_index =(int) index / 2;
  int self = heap -> binary_tree[index];
  int parent = heap -> binary_tree[parent_index];

  if (parent > self) {
    Swap(heap, parent_index, index);
    BubbleUp(heap, parent_index);
  }
}

void BubbleDown(Heap *heap, int index) {
  int min_index = index;
  int left_index = index*2;
  int right_index = index*2 + 1;

  int min = heap -> binary_tree[min_index];
  int left = heap -> binary_tree[left_index];
  int right = heap -> binary_tree[right_index];

  if (left_index <= heap -> num_elems && left < min) {
    min_index = left_index;
  }

  if (right_index <= heap -> num_elems && right < min) {
    min_index = right_index;
  }
  if (min_index == index) {return;}
    Swap(heap, index, min_index);
    BubbleDown(heap, min_index);
}

void Swap(Heap *heap, int first_ind, int second_ind) {
  int temp = heap -> binary_tree[first_ind];
  heap -> binary_tree[first_ind] = heap -> binary_tree[second_ind];
  heap -> binary_tree[second_ind] = temp;
}

void DestroyHeap(Heap *heap) {
  free(heap);
}
