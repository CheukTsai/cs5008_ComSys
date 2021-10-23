#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "score.h"


Score* CreateScore(char* name, int score, int age) {
  Score* out = (Score*)malloc(sizeof(Score));
  int len = strlen(name);
  char* heap_name = (char*)malloc(sizeof(char) * len);
  strncpy(heap_name, name, len -1);
  out->name = heap_name; 
  out->score = score; 
  out->age = age; 
  return out;
}

void DestroyScore(Score* score) {
  free(score->name);
  free(score);
}

void DestroyScoreWrapper(void* score) {
  DestroyScore((Score*)score);
}

void PrintScore(void* sc1) {
  Score* score = (Score*) sc1;
  printf("Score: %s (%d) has score %d\n", score->name, score->age, score->score);
}

// Returns 0 if equal
// Neg val if first is smaller than second
// Pos val if first is bigger than second
int CompareScore(void* first, void* second) {
  Score* one = (Score*)first;
  Score* two = (Score*)second; 
  return(one->score - two->score);
}

void* CreateScoreFromName(char* name) {
  return (void*)CreateScore(name, 50 + (rand() % 50), 10 + (rand() % 30));
}

// Takes in a filename and a Create() function. 
// Creates an array of num_lines length
// Uses create() to create a void* to put in the array
// Returns the array
void** CreateArray(char* filename, int num_lines, void* (*create)(char*)) {
  void** out = malloc(sizeof(void*) * num_lines);
  int i = 0; 

  FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    for (i = 0; i < num_lines; i++) {
      read = getline(&line, &len, fp);
      if (read != -1) {
          out[i] = create(line);
      }
    }
    fclose(fp);
    if (line)
        free(line);
    return out;
}


// Takes in a filename and a Create() function. 
// Creates an array of num_lines length
// Uses create() to create a void* to put in the array
// Returns the array
void DestroyArray(void** data, int num_elems, void (*Destroy)(void*)) {  
  int i = 0; 

  for (i = 0; i < num_elems; i++) {
    Destroy(data[i]);
  }

  free(data);
}