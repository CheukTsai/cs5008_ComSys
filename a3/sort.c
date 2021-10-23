#include <stdio.h>

#include "linkedlist.h"


// Bubble Sort
void Sort(LinkedListPtr list) {
  if (list->head == NULL) {
    return;
  }

  int ifSwap = 1;
  LinkedListNodePtr currentListNode;
  LinkedListNodePtr head = list->head;
  LinkedListNodePtr last = NULL;

  while(ifSwap == 1){
    ifSwap = 0;
    currentListNode = head;
    
    while (currentListNode->next != last){
        if (currentListNode->data > currentListNode->next->data){
            int temp = currentListNode->data;
            currentListNode->data = currentListNode->next->data;
            currentListNode->next->data = temp;
            ifSwap = 1;
          }
        currentListNode = currentListNode->next;
      }
      last = currentListNode;
    } 
  }