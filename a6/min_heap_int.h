#ifndef MIN_HEAP_INT_H
#define MIN_HEAP_INT_H

#define H_SIZE 40

typedef struct {
    int binary_tree[H_SIZE + 1];
    int num_elems;
} Heap;

Heap *CreateHeap(int *data, int num_elems);
void Insert(Heap *heap, int val);
int ExtractMin(Heap *heap);
int Delete(Heap *heap, int position);
void BubbleUp(Heap *heap, int index);
void BubbleDown(Heap *heap, int index);
void Swap(Heap *heap, int first_ind, int second_ind);
void DestroyHeap(Heap *heap);

#endif
