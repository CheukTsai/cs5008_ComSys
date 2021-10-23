#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gen_heap.h"

Heap* CreateHeap(void** data, int num_elems, int (*compare)(void*, void*)) {
  Heap *heap = (Heap*) malloc(sizeof(Heap));
  heap -> num_elems = 0;
  heap -> compare = compare;
  int i;
  for (i = 0; i < num_elems; i++) {
    Insert(heap, data[i]);
  }
  return heap;
}

void DestroyHeap(Heap* heap) {
  int i;
  for (i = 0; i < heap -> num_elems; i++) {
    free(heap -> data[i]);
  }
  // free(heap -> data);
  free(heap);
}


int ParentIndex(int child_index) {
  if (child_index == 1)
    return(-1);
  else
    return((int) child_index/2);
}

int YoungChildIndex(int parent_index) {
  return(2 * parent_index);
}

void Insert(Heap* heap, void* new_data_val) {
  heap -> num_elems++;
  int spot = heap -> num_elems;
  heap -> data[spot] = new_data_val;
  BubbleUp(heap, spot);
}


void Swap(Heap* heap, int child_index, int parent_index) {
  void* temp = heap -> data[child_index];
  heap -> data[child_index] = heap -> data[parent_index];
  heap -> data[parent_index] = temp;
}

void BubbleUp(Heap* heap, int index) {
  if (index == 1) return;

  int parent_index =(int) index / 2;
  void* self = heap -> data[index];
  void* parent = heap -> data[parent_index];

  if ((heap -> compare(parent, self)) > 0) {
    Swap(heap, parent_index, index);
    BubbleUp(heap, parent_index);
  }
}

void* ExtractMin(Heap* heap) {
  // if(heap -> num_elems == 1) return;

  void* element = heap -> data[1];
  Swap(heap, 1, heap -> num_elems);
  heap -> num_elems--;
  BubbleDown(heap, 1);
  return element;
}

void BubbleDown(Heap* heap, int index) {
  int min_index = index;
  int left_index =(int) index*2;
  int right_index =(int) index*2 + 1;

  void* min = heap -> data[min_index];
  void* left = heap -> data[left_index];
  void* right = heap -> data[right_index];

  if (left_index <= heap -> num_elems && (heap -> compare(left, min)) < 0) {
    min_index = left_index;
  }

  if (right_index <= heap -> num_elems && (heap -> compare(right, min)) < 0) {
    min_index = right_index;
  }

  if (min_index == index) {return;}
  Swap(heap, index, min_index);
  BubbleDown(heap, min_index);
}


