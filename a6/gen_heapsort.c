#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gen_heapsort.h"
#include "gen_heap.h"

void HeapSort(void** data, int num_elems, int (*Compare)(void*, void*)) {
    Heap* heap = CreateHeap(data, num_elems, Compare);
    int i;
    for (i = 1; i <= num_elems; i++) {
      data[i-1] = ExtractMin(heap);
    }
    DestroyHeap(heap);
}
