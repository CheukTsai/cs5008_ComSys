#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

int main()
{
  // Depth-First search (recursive)
  printf("\n------------- Depth-first search (recursive) results-------------------\n");
  TreeNode *nodeDog = createNode("2");
  BinaryTree *tree = createTree(nodeDog);
  TreeNode *nodeCat = createNode("1");
  TreeNode *nodePig = createNode("3");
  addChild(nodeDog, nodeCat, 1);
  addChild(nodeDog, nodePig, 0);
  dfs(tree);
  free(tree);
  printf("-------------------------------------------------------------\n");
  
  //  Depth-first search (iterative)
  printf("\n------------- Depth-first search (iterative) results---------------------\n");
  TreeNode *nodeRed = createNode("2");
  BinaryTree *tree2 = createTree(nodeRed);
  TreeNode *nodeBlue = createNode("1");
  TreeNode *nodeGreen = createNode("3");
  addChild(nodeRed, nodeBlue, 1);
  addChild(nodeRed, nodeGreen, 0);
  dfs_stack(tree2);
  free(tree2);
  printf("-------------------------------------------------------------\n");

  // Breadth-First search
  printf("\n------------- Breadth-first search results-------------------\n");
  TreeNode *node4 = createNode("2");
  BinaryTree *tree_bfs = createTree(node4);
  TreeNode *node5 = createNode("1");
  TreeNode *node6 = createNode("3");
  addChild(node4, node5, 1);
  addChild(node4, node6, 0);
  bfs(tree_bfs);
  free(tree_bfs);
  printf("-------------------------------------------------------------\n");

  return 0;
}
