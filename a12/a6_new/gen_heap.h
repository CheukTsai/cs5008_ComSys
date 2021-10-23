#ifndef GEN_HEAP_H

#define GEN_HEAP_H

#define PQ_SIZE 64

typedef struct {
  void* data[PQ_SIZE+1];
  int num_elems;
  int (*compare)(void*, void*);
} Heap;


void PrintArray(void** data, int num_elems, void (*print)(void*));

void BubbleDown(Heap* heap, int p);

void* ExtractMin(Heap* heap);

Heap* CreateHeap(void** data, int num_elems, int (*compare)(void*, void*));

void DestroyHeap(Heap *heap);

void Insert(Heap* heap, void* new_data_val);

void BubbleUp(Heap* heap, int p);

#endif  // GEN_HEAP_H
