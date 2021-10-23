#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gen_heap.h"

void Swap(Heap* heap, int child_index, int parent_index) {
  void* temp = heap -> data[child_index];
  heap -> data[child_index] = heap -> data[parent_index];
  heap -> data[parent_index] = temp;
}

Heap* CreateHeap(void** data, int num_elems, int (*compare)(void*, void*)) {
  Heap *heap = (Heap*) malloc(sizeof(Heap));
  heap -> num_elems = num_elems;
  heap -> compare = compare;
  int i;
  for (i = 1; i <= num_elems; i++) {
    heap -> data[i] = data[i-1];
    if (i == 1) continue;
    int child = i;
    while (child != 1) {
      int parent = child/2;
      if (heap -> compare(heap -> data[child], heap -> data[parent]) < 0) {
        Swap(heap, child, parent);
      }
      child = parent;
    }
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


// int ParentIndex(int child_index) {
//   if (child_index == 1)
//     return(-1);
//   else
//     return((int) child_index/2);
// }

// int YoungChildIndex(int parent_index) {
//   return(2 * parent_index);
// }

void Insert(Heap* heap, void* new_data_val) {
  heap -> num_elems++;
  int spot = heap -> num_elems;
  heap -> data[spot] = new_data_val;
  BubbleUp(heap, spot);
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
  void* element = heap -> data[1];
  heap -> data[1] = heap -> data[heap -> num_elems];
  heap -> num_elems--;
  BubbleDown(heap, 1);
  return element;
}

void BubbleDown(Heap* heap, int index) {
  if (index == 0) return;

  int current_index = index;
  int left_index = index * 2;
  int right_index = index * 2 + 1;
  if (current_index > heap -> num_elems ||
  left_index > heap -> num_elems ||
  right_index > heap -> num_elems) {
    return;
  }
  void* current = heap -> data[current_index];
  void* left = heap -> data[left_index];
  void* right = heap -> data[right_index];

  void* min_child;
  int min_child_index;

  if (heap -> compare(left, right) < 0) {
    min_child = left;
    min_child_index = left_index;
  } else {
    min_child = right;
    min_child_index = right_index;
  }
  if (heap -> compare(min_child, current) < 0) {
    Swap(heap, current_index, min_child_index);
    BubbleDown(heap, min_child_index);
  } else {
    return;
  }
}


