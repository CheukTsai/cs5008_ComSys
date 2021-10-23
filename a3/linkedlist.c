#include <stdio.h>
#include "linkedlist.h"

LinkedListPtr CreateLinkedList(){
	LinkedListPtr newPtr = (LinkedListPtr)malloc(sizeof(LinkedListPtr));
	newPtr->num_elements = 0;
	newPtr->head = NULL;
	newPtr->tail = NULL;
	return newPtr;
}

void DestroyLinkedList(LinkedListPtr list){
  if (list == NULL){
    return;
  }
  
  list->num_elements = 0;
  LinkedListNodePtr current = list->head;
  list->head = NULL;
  
  while (current != NULL){
    LinkedListNodePtr temp = current;
    current = current->next;
    free(temp);
  }
  
  free(list);
  list = NULL;
}

int NumElementsInLinkedList(LinkedListPtr list) {
	int result = (int)list->num_elements;
  return result;
}

void InsertLinkedList(LinkedListPtr list, int val) {
  LinkedListNodePtr node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  node->data = val;
  node->next = NULL;
  node->prev = NULL;
  
  if(list->head==NULL) {
    list->head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    list->head = node;
    
    if(list->tail == NULL){
      list->tail = (LinkedListNode *)malloc(sizeof(LinkedListNode));
      list->tail = node;
    } 
  }
  else{
    list->head->prev = node;
    node->next = list->head;
    list->head = node;
  }
  
  list->num_elements++;
}

void AppendLinkedList(LinkedListPtr list, int val) {
  LinkedListNodePtr node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  node->data = val;
  node->next = NULL;
  node->prev = NULL;
  
  if(list->tail==NULL) {
    list->tail = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    list->tail = node;
    if(list->head==NULL) {
      list->head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
      list->head = node;
    }
  } 
  
  else{
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
  }
  
  list->num_elements++;
}

void PrintLinkedList(LinkedListPtr list) {
  LinkedListNodePtr ptr = list->head;
  while(ptr != NULL){
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
}

LinkedListNodePtr CreateLinkedListNode(int val) {
  LinkedListNodePtr ptr = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  ptr->data = val;
  ptr->next = NULL;
  ptr->prev = NULL;
  return ptr;
}

void DestroyLinkedListNode(LinkedListNodePtr ptr) {
  free(ptr);
}

int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr) {
  LinkedListNodePtr temp = list->head;
  while(temp!=NULL && temp!=ptr) {
    temp = temp->next;
  }
  
  if(temp!=NULL) {
    if(temp->prev!=NULL){
      temp->prev->next = temp->next;
    }
  
    if(temp->next!=NULL){
      temp->next->prev = temp->prev;
    }
  }
  free(temp);
  return 0;
}