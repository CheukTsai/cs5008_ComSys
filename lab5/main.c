#include <stdio.h>
#include "sort.h"
#include "linkedlist.h"


int main() {
  const int MIN = 1;
  const int MAX = 100;
  const int TOTAL_NUMBER = 50;
  
  srand(time(0));
  
  LinkedListPtr list = CreateLinkedList();
  int i; 
  for (i = 0; i < TOTAL_NUMBER; i++){
  	int randomNumber =  MIN + rand() % MAX;
      AppendLinkedList(list, randomNumber);
  }
  
  printf("\nRandom Unsorted Linked List:\n");
  PrintLinkedList(list);
  printf("\n");
  
  printf("\nAfter Sorted:\n");
  Sort(list);
  PrintLinkedList(list);
  printf("\n");
  
  DestroyLinkedList(list);
  
  return 0;
}