#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>

#include "tree.h"

TreeNode* CreateTreeNode(char* path, char* name) {
  TreeNode* treeNode = (TreeNode*)malloc(sizeof(TreeNode));
  treeNode->path = path;
  treeNode->name = name;
  treeNode->children = NULL;
  treeNode->siblings = NULL;
  treeNode->level = 0;
}

void AddChild(TreeNode* root, char* path, char* name) {
  TreeNode* child = NULL;
  child = CreateTreeNode(path, name);
  child -> level = root -> level + 1;
  TreeNode* tmp = NULL;
  tmp = root -> children;
  if (tmp == NULL) {
    root -> children = child;
    return;} else {
    TreeNode* sibling = NULL;
    sibling = tmp -> siblings;

    if (sibling == NULL) {
      tmp->siblings = child;
      return;
    }
    while (sibling -> siblings != NULL) {
      sibling = sibling -> siblings;
    }
    sibling -> siblings = child;
  }
}

void DestroyTreeNode(TreeNode* treeNode) {
  if (treeNode == NULL) return;
  if (treeNode -> children) {
    TreeNode* tmp2 = treeNode -> children;
    DestroyTreeNode(tmp2);
  }
  if (treeNode -> siblings) {
    TreeNode* tmp1 = treeNode -> siblings;
    DestroyTreeNode(tmp1);
  }
  TreeNode* tmp = NULL;
  tmp = treeNode;
  free(tmp);
  treeNode = NULL;
}
