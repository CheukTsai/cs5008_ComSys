#include <stdio.h>

#ifndef ANAGRAM_H
#define ANAGRAM_H


// See Anagram.c to see the WordNode struct
typedef struct wordNode WordNode;

typedef struct anagram Anagram;

struct anagram {
  char* anagram_key;
  int num_words;
  WordNode* words;
  Anagram* next_anagram;
};

Anagram* CreateAnagram(char* key);

void DestroyAnagram(Anagram* anagram);

void AddWordToAnagram(Anagram* anagram, const char* new_anagram);

void PrintAnagram(Anagram* anagram);

#endif  // ANAGRAM_H
