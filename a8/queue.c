#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue* CreateQueue() {
  Queue* newQueue = (Queue*)malloc(sizeof(Queue));
  newQueue->head = SIZE - 1;
  newQueue->tail = SIZE - 1;
  int i;
  for (i = 0; i < SIZE; i++) {
      newQueue -> items[i] = NULL;
  }

  return newQueue;
}

TreeNode* Dequeue(Queue* queue) {
  return (queue->items[queue->head--]);
}

void Enqueue(Queue* queue, TreeNode* treeNode) {
  if (queue->tail == 0) {
    return;
  } else {
    if (!treeNode) return;
    queue->items[--queue->tail] = treeNode;
  }
}

void DestroyQueue(Queue* queue) {
  TreeNode* head = NULL;

  int i;
  for (i = SIZE - 1; i >= 0; i--) {
    head = queue -> items[i];
    if (head == NULL) continue;
    head = NULL;
  }
  free(queue);
}
