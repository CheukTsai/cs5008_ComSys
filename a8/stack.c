#include <stdio.h>

#include "stack.h"
#include "tree.h"

#define SIZE 200

Stack* CreateStack() {
  Stack* newStack = (Stack*)malloc(sizeof(Stack));
  newStack -> head = 0;

  int i;
  for (i = 0; i < SIZE; i++) {
      newStack -> items[i] = NULL;
  }

  return newStack;
}

void Push(Stack* stack, TreeNode* treeNode) {
  if (!treeNode) return;
  if (stack -> head < SIZE) {
    stack -> items[stack -> head++] = treeNode;
  }
}

TreeNode* Pop(Stack* stack) {
  if (stack -> head > 0) {
    return stack -> items[--stack->head];
  }
  return NULL;
}

void DestroyStack(Stack* stack) {
  TreeNode* head = NULL;

  int i;
  for (i = 0; i < SIZE; i++) {
    head = stack -> items[i];
    if (head == NULL) continue;
    head = NULL;
  }
  free(stack);
}

void dfs_stack(TreeNode *root) {
  if (!root) return;
  Stack *stack = CreateStack();
  Push(stack, root);

  TreeNode* node = Pop(stack);
  while (node || stack -> head > 0) {
    Push(stack, node -> siblings);
    Push(stack, node -> children);
    node = Pop(stack);
  }
  DestroyStack(stack);
}
