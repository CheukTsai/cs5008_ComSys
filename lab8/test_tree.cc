#include "gtest/gtest.h"
extern "C"
{
#include "Tree.h"
}

#include <string.h>
#include <stdlib.h>

TEST(Tree, createNode)
{
  TreeNode *node = createNode("dog");
  EXPECT_EQ(strcmp(node->data, "dog"), 0);
  EXPECT_EQ(node->visited, 0);
  EXPECT_TRUE(node->parent == NULL);
  EXPECT_TRUE(node->leftChild == NULL);
  EXPECT_TRUE(node->rightChild == NULL);
  free(node);
}

TEST(Tree, createTree)
{
  TreeNode *node = createNode("dog");
  BinaryTree *tree = createTree(node);
  EXPECT_EQ(tree->root, node);
  free(node);
  free(tree);
}

TEST(Tree, addChild)
{
  TreeNode *node = createNode("dog");
  TreeNode *node1 = createNode("dog1");
  addChild(node, node1, 1);
  EXPECT_EQ(node->leftChild, node1);
  free(node);
  free(node1);
}

TEST(Tree, printTreeNode)
{
  TreeNode *node = createNode("dog");
  printTreeNode(node);
  free(node);
}

TEST(Tree, createListNode)
{
  TreeNode *node = createNode("dog");
  LinkedListNode *listNode = createListNode(node);
  EXPECT_EQ(listNode->treeNode, node);
  EXPECT_TRUE(listNode->next == NULL);
  free(node);
  free(listNode);
}

TEST(Tree, createStack)
{
  Stack *stack = createStack();
  EXPECT_EQ(stack->numOfNodes, 0);
  EXPECT_TRUE(stack->top == NULL);
  free(stack);
}

TEST(Tree, stackPush)
{
  Stack *stack = createStack();
  TreeNode *nodeDog = createNode("dog");
  TreeNode *nodeCat = createNode("cat");
  stackPush(stack, nodeDog);
  stackPush(stack, nodeCat);
  EXPECT_EQ(stack->top->treeNode, nodeDog);
  EXPECT_EQ(stack->numOfNodes, 2);
  freeStack(stack);
}

TEST(Tree, stackPop)
{
  Stack *stack = createStack();
  TreeNode *nodeDog = createNode("dog");
  TreeNode *nodeCat = createNode("cat");
  stackPush(stack, nodeDog);
  stackPush(stack, nodeCat);
  EXPECT_EQ(stack->top->treeNode, nodeDog);
  EXPECT_EQ(stack->numOfNodes, 2);
  TreeNode *popNode = stackPop(stack);
  EXPECT_EQ(popNode, nodeDog);
  EXPECT_EQ(stack->top->treeNode, nodeCat);
  EXPECT_EQ(stack->numOfNodes, 1);
  free(popNode);
  freeStack(stack);
}

TEST(Tree, createQueue)
{
  Queue *queue = createQueue();
  EXPECT_EQ(queue->numOfNodes, 0);
  EXPECT_TRUE(queue->head == NULL);
  EXPECT_TRUE(queue->tail == NULL);
  free(queue);
}

TEST(Tree, enqueue)
{
  Queue *queue = createQueue();
  TreeNode *nodeDog = createNode("dog");
  TreeNode *nodeCat = createNode("cat");
  enqueue(queue, nodeDog);
  enqueue(queue, nodeCat);
  EXPECT_EQ(queue->head->treeNode, nodeDog);
  EXPECT_EQ(queue->tail->treeNode, nodeCat);
  EXPECT_EQ(queue->numOfNodes, 2);
  freeQueue(queue);
}

TEST(Tree, dequeue)
{
  Queue *queue = createQueue();
  TreeNode *nodeDog = createNode("dog");
  TreeNode *nodeCat = createNode("cat");
  enqueue(queue, nodeDog);
  enqueue(queue, nodeCat);
  TreeNode *dequeueNode = dequeue(queue);
  EXPECT_EQ(nodeDog, dequeueNode);
  EXPECT_EQ(queue->head->treeNode, nodeCat);
  EXPECT_EQ(queue->tail->treeNode, nodeCat);
  EXPECT_EQ(queue->numOfNodes, 1);
  free(dequeueNode);
  freeQueue(queue);
}

TEST(Tree, bfs){
  TreeNode* node = createNode("dog");
  BinaryTree* tree = createTree(node);
  TreeNode* nodeCat = createNode("cat");
  TreeNode* nodePig = createNode("Pig");
  addChild(node, nodeCat, 1);
  addChild(node, nodePig, 0);
  bfs(tree);
  free(tree);
}

TEST(Tree, dfs){
  TreeNode* node = createNode("dog");
  BinaryTree* tree = createTree(node);
  TreeNode* nodeCat = createNode("cat");
  TreeNode* nodePig = createNode("Pig");
  addChild(node, nodeCat, 1);
  addChild(node, nodePig, 0);
  dfs(tree);
  free(tree);
  free(node);
  free(nodeCat);
  free(nodePig);
}

TEST(Tree, dfs_stack){
  TreeNode* node = createNode("dog");
  BinaryTree* tree = createTree(node);
  TreeNode* nodeCat = createNode("cat");
  TreeNode* nodePig = createNode("Pig");
  addChild(node, nodeCat, 1);
  addChild(node, nodePig, 0);
  dfs_stack(tree);
  free(tree);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
