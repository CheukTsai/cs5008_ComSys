#ifndef SCORE_H

#define SCORE_H

typedef struct{ 
  char* name; 
  int score;
  int age;
} Score; 


Score* CreateScore(char* name, int score, int age);

void DestroyScore(Score* score);

void PrintScore(void* sc1);

int CompareScore(void* first, void* second);

void* CreateScoreFromName(char* name);

void** CreateArray(char* filename, int num_lines, void* (*create)(char*));

void DestroyArray(void** data, int num_elems, void (*Destroy)(void*));

void DestroyScoreWrapper(void* score);

#endif // SCORE_H