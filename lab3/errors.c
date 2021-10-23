#include <stdio.h>
#include <stdlib.h>

int main() {

  int stringLength = 7;
  // char* stringOnHeap = (char*)malloc((*stringOnHeap * stringLength) + 1);
  // char* stringOnHeap = (char*)malloc(*stringOnHeap * (stringLength + 1));
  char* stringOnHeap = (char*)malloc(sizeof(char) * (stringLength + 1));

  printf("*stringOnHeap size: %d\n", sizeof(*stringOnHeap));
  printf("char size         : %d\n", sizeof(char));

  // check the malloc status
  if (stringOnHeap == NULL) {
    printf("ERROR: cannot malloc the string\n");
    exit(EXIT_FAILURE);
  } else {
    printf("SUCCESS: malloc the string\n");
  }

  stringOnHeap[0] = 'e';
  stringOnHeap[1] = 'x';
  stringOnHeap[2] = 'a';
  stringOnHeap[3] = 'm';
  stringOnHeap[4] = 'p';
  stringOnHeap[5] = 'l';
  stringOnHeap[6] = 'e';
  stringOnHeap[7] = '\0';

  printf("%s\n", stringOnHeap);
  free(stringOnHeap);

  return 0;
}
