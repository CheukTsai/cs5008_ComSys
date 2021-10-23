#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tree.h"

struct wordNode {
  const char* word; 
  WordNode* next_word;
};

WordNode* CreateWordNode(const char* word);

void DestroyWordNode(WordNode*);

// Create a node.
TreeNode *createNode(char *data)
{
    TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->parent = NULL;
    treeNode->leftChild = NULL;
    treeNode->rightChild = NULL;
    treeNode->visited = 0;
    return treeNode;
}

// Create a tree
BinaryTree *createTree(TreeNode *node)
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->root = node;
    return tree;
}

// addd child to a node
// leftChild == 1, add left child. leftChild = 0, add right child.
void addChild(TreeNode *node, TreeNode *child, int leftChild)
{
    if (!node || !child)
    {
        return;
    }
    if (leftChild == 1)
    {
        node->leftChild = child;
    }
    else if (leftChild == 0)
    {
        node->rightChild = child;
    }
    else
    {
        return;
    }
}

// print a treenode value
void printTreeNode(TreeNode *node)
{
    if (node)
    {
        printf("The node is %s\n", node->data);
    }
}

// Create a linked list node
LinkedListNode *createListNode(TreeNode *treeNode)
{
    LinkedListNode *listNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    listNode->treeNode = treeNode;
    listNode->next = NULL;
    return listNode;
}

// Create an empty stack
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->numOfNodes = 0;
    return stack;
}

// stack push
void stackPush(Stack *stack, TreeNode *treeNode)
{
    if (!stack || !treeNode)
    {
        return;
    }
    LinkedListNode *listNode = createListNode(treeNode);
    if (stack->top == NULL)
    {
        stack->top = listNode;
    }
    else
    {
        listNode->next = stack->top;
        stack->top = listNode;
    }
    stack->numOfNodes += 1;
    // free_listNode(listNode);
}

// stack pop
TreeNode *stackPop(Stack *stack)
{
    if (!stack || !stack->top)
    {
        return NULL;
    }
    LinkedListNode *listNode = stack->top;
    TreeNode *treeNode = listNode->treeNode;
    stack->top = stack->top->next;
    stack->numOfNodes--;
    free(listNode);
    return treeNode;
}

// free stack and its nodes if it has.
void freeStack(Stack *stack)
{
    LinkedListNode *listNode = stack->top;
    while (listNode)
    {
        LinkedListNode *next = listNode->next;
        free_listNode(listNode);
        listNode = next;
    }
    free(stack);
}

// free linkedlist node, including free its treeNode.
void free_listNode(LinkedListNode *listNode)
{
    if (listNode)
    {
        if (listNode->treeNode)
        {
            free(listNode->treeNode);
        }
        free(listNode);
    }
}

// Create an empty queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->numOfNodes = 0;
    return queue;
}

// enqueue a treeNode to the queue
void enqueue(Queue *queue, TreeNode *treeNode)
{
    if (!queue || !treeNode)
    {
        return;
    }
    LinkedListNode *listNode = createListNode(treeNode);
    if (!queue->head)
    {
        queue->head = listNode;
        queue->tail = listNode;
    }
    else
    {
        queue->tail->next = listNode;
        queue->tail = queue->tail->next;
    }
    queue->numOfNodes++;
}

// dequeue head treenode from the queue.
TreeNode *dequeue(Queue *queue)
{
    if (!queue || !queue->head)
    {
        return NULL;
    }
    LinkedListNode *listNode = queue->head;
    TreeNode *treeNode = listNode->treeNode;
    queue->head = queue->head->next;
    if (!queue->head)
    {
        queue->tail = NULL;
    }
    queue->numOfNodes--;
    free(listNode);
    return treeNode;
}

// Free queue
void freeQueue(Queue *queue)
{
    LinkedListNode *listNode = queue->head;
    while (listNode)
    {
        LinkedListNode *next = listNode->next;
        free_listNode(listNode);
        listNode = next;
    }
    free(queue);
}

// Depth-first search using recursive algorithm
// STEP 3
// IMPORTANT: free nodes in main function
// Time comlexity O(n) / Space O(height)
void dfs(BinaryTree *binaryTree)
{
  if (binaryTree) {
    TreeNode* root = binaryTree -> root;
    recursive_dfs(root);
  }
}

// Helper for dfs
void recursive_dfs(TreeNode *root){
  if (root == NULL) {return;}
  
  printTreeNode(root);
  recursive_dfs(root -> leftChild);
  recursive_dfs(root -> rightChild);
}


// Depth-first traversal using iterative algorithm
// STEP 4
void dfs_stack(BinaryTree *binaryTree)
{
  if (!binaryTree) {
    return;
  }
  if (!binaryTree->root) {
    return;
  }
  TreeNode *root = binaryTree -> root;
  Stack *stack = createStack();
  stackPush(stack, root);
  TreeNode *node = stackPop(stack);
  while(node || stack -> numOfNodes > 0){

    
    stackPush(stack, node -> rightChild);
    stackPush(stack, node -> leftChild);
    printTreeNode(node);
    node = stackPop(stack);
  }
  freeStack(stack);
}

// Bread-first search
// STEP 5
void bfs(BinaryTree *binaryTree)
{
  if (!binaryTree) {
    return;
  }
  TreeNode *root = binaryTree -> root;
  Queue *queue = createQueue();
  enqueue(queue, root);
  TreeNode *node = dequeue(queue);
  while (node) {
    enqueue(queue, node -> leftChild);
    enqueue(queue, node -> rightChild);
    printTreeNode(node);
    node = dequeue(queue);
  }
  freeQueue(queue);
}
