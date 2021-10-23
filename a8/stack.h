#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include "tree.h"

#define SIZE 200

typedef struct stack {
    TreeNode* items[SIZE];
    int head;
}Stack;

Stack* CreateStack();

void Push(Stack* stack, TreeNode* treeNode);

TreeNode* Pop(Stack* stack);

void DestroyStack(Stack* stack);

void dfs_stack(TreeNode *root);

#endif
