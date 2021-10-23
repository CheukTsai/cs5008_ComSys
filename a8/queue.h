#ifndef _QUEUE_H
#define _QUEUE_H


#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

#define SIZE 200


typedef struct queue {
  TreeNode* items[SIZE];
  int head;
  int tail;
}Queue;

Queue* CreateQueue();

void Enqueue(Queue* queue, TreeNode* treeNode);

TreeNode* Dequeue(Queue* queue);

void DestroyQueue(Queue* queue);

#endif
