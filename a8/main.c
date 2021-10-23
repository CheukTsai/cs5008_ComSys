#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>

#include "stack.h"
#include "tree.h"
#include "queue.h"


void explore(Queue* queue, TreeNode* root) {
  char* dir = root -> path;
  struct stat s;
  struct dirent **namelist;
  int num_files;

  num_files = scandir(dir, &namelist, 0, alphasort);
  if (num_files < 0) {
    return;
  } else {
    int i = 0;
    while (i < num_files) {
      if (namelist[i]->d_name[0] == '.') {
        free(namelist[i]);
        i++;
        continue;
      }
      char *directory;
      int length = strlen(dir) + strlen(namelist[i]->d_name);
      directory = (char*) malloc(((length + 3)*sizeof(char)));

      if (directory == NULL) {
        printf("Couldn't malloc for filecrawler.directory\n");
        root = NULL;
        return;
      }
      snprintf(directory, length + 3, "%s/%s", dir, namelist[i]->d_name);
      if (0 == stat(directory, &s)) {
        int j;
        for (j = 0; j < root -> level; j++) {
          printf(" ");
        }
        TreeNode* child = CreateTreeNode(directory, directory);
        child -> level = root -> level + 1;
        if (S_ISDIR(s.st_mode)) {
          Enqueue(queue, child);
        }
        AddChild(root, directory, directory);
        printf("%lc%lc", 0x251c, 0x2500);
        printf(" %s\n", namelist[i]->d_name);
        explore(queue, child);
        DestroyTreeNode(child);
      }
      free(directory);
      free(namelist[i]);
      i++;
    }
    free(namelist);
    dfs_stack(root);
  }
}

int main() {
  TreeNode* root = CreateTreeNode("..", "root_dir");
  setlocale(LC_ALL, "");
  Queue* queue = CreateQueue();
  explore(queue, root);
  TreeNode* node = Dequeue(queue);
  while (node) {
    node = Dequeue(queue);
    dfs_stack(node);
  }
  DestroyTreeNode(root);
  DestroyQueue(queue);
  return 0;
}
