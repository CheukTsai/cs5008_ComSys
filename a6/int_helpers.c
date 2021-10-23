#include <stdio.h>

#include "int_helpers.h"

void PrintInt(void* val) {
  printf("%d ", *((int*)val));
}

// Returns 0 if equal
// Neg val if first is smaller than second
// Pos val if first is bigger than second
int CompareInt(void* first, void* second) {
  // printf("%p vs %p\n", first, second);
  int one = *(int*)first; 
  int two = *(int*)second;
  return one - two; 
}
