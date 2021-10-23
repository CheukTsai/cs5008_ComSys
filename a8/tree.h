#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>

#ifndef _TREE_H
#define _TREE_H

typedef struct treeNode {
    char* path;
    char* name;
    struct treeNode* children;
    struct treeNode* siblings;
    int level;
}TreeNode;

TreeNode* CreateTreeNode(char* path, char* name);

void AddChild(TreeNode* root, char* path, char* name);

void DestroyTreeNode(TreeNode* treeNode);

#endif
