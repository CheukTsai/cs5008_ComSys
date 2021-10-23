
#ifndef _TREE_H
#define _TREE_H

typedef struct treeNode{
    char* data;
    struct treeNode* parent;
    struct treeNode* leftChild;
    struct treeNode* rightChild;
    int visited;
}TreeNode;

typedef struct binaryTree{
    TreeNode* root;
}BinaryTree;

typedef struct linkedListNode{
    TreeNode* treeNode;
    struct linkedListNode* next;
}LinkedListNode;

typedef struct queue{
    LinkedListNode* head;
    LinkedListNode* tail;
    size_t numOfNodes;
}Queue;

typedef struct stack{
    LinkedListNode* top;
    size_t numOfNodes;
}Stack;

// Create a node.
TreeNode* createNode(char* data);

// Create a tree
BinaryTree* createTree(TreeNode* node);


// addd child to a node
void addChild(TreeNode* node, TreeNode* child, int leftChild);

// print a treenode value
void printTreeNode(TreeNode* node);

// Bread-first search
void bfs(BinaryTree* binaryTree);

// Depth-first search using recursive method.
void dfs(BinaryTree* binaryTree);

// Helper function to recursive traversal tree.
void recursive_dfs(TreeNode* root);

// Depth-first traversal using iterative algorithm
void dfs_stack(BinaryTree* binaryTree);

// Create a linked list node
LinkedListNode* createListNode(TreeNode* treeNode);

// Create an empty stack
Stack* createStack();

// stack push
void stackPush(Stack* stack, TreeNode* treeNode);

// stack pop
// will free treeNode after it finish pop in the main function.
TreeNode* stackPop(Stack* stack);

// free stack and its nodes if it has.
void freeStack(Stack* stack);

// free linkedlist node, including free its treeNode.
// Might not use in our case.
void free_listNode(LinkedListNode* listNode);

// Create an empty queue
Queue* createQueue();

// enqueue a treeNode to the queue
void enqueue(Queue* queue, TreeNode* treeNode);

// dequeue head treenode from the queue.
TreeNode* dequeue(Queue* queue);

// Free queue
void freeQueue(Queue* queue);

#endif