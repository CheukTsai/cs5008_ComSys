#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Anagram.h"


// Private Prototypes
struct wordNode {
  const char* word;
  WordNode* next_word;
};

WordNode* CreateWordNode(const char* word);

void DestroyWordNode(WordNode* wordNode);


// Implementations
Anagram* CreateAnagram(char* key) {
  Anagram* anagram = (Anagram *)malloc(sizeof(Anagram));
  anagram -> anagram_key = malloc(sizeof(char)*strlen(key) + 1);
  strcpy(anagram -> anagram_key, key);
  // anagram -> anagram_key = key;
  anagram -> words = NULL;
  anagram -> num_words = 0;
  anagram -> next_anagram = NULL;
  return anagram;
}

void DestroyWordNode(WordNode* wordNode) {
  char* tmp = NULL;
  tmp = (char*)wordNode -> word;
  free(tmp);
  free(wordNode);
  // printf("successfully destoryed wordNode\n");
}

WordNode* CreateWordNode(const char* word) {
  WordNode* wordNode = (WordNode *)malloc(sizeof(WordNode));
  // wordNode -> word = malloc(sizeof(char) * strlen(word) + 1);
  char* cpValue = (char*)malloc(sizeof(char) * strlen(word) + 1);
  strcpy(cpValue, word);
  wordNode -> word = cpValue;
  wordNode -> next_word = NULL;
  // free(cpValue); // temp
  // char *tmp = NULL;
  // tmp = cpValue;
  // free(tmp);
  return wordNode;
}

void DestroyAnagram(Anagram* anagram) {
  WordNode* head = NULL;
  head = anagram -> words;
  if (anagram -> words == NULL) return;
  while (head != NULL) {
    WordNode* temp = head;
    head = head -> next_word;
    DestroyWordNode(temp);
  }
  char* des_key = NULL;
  des_key = anagram -> anagram_key;
  free(des_key);

  Anagram* tmp = NULL;
  tmp = anagram;
  free(tmp);
  // free(anagram -> anagram_key);
  // free(anagram);
}

void AddWordToAnagram(Anagram* anagram, const char* new_word) {
  WordNode* wordNode = CreateWordNode(new_word);
  if (anagram -> words == NULL) {
    anagram -> words = wordNode;
    anagram -> num_words++;
    return;
  }
  wordNode -> next_word = anagram -> words;
  anagram -> words = wordNode;
  anagram -> num_words++;
}

void PrintAnagram(Anagram* anagram) {
  // if (anagram == NULL) return;
  printf("key: %s| ", anagram -> anagram_key);
  printf("values: ");
  WordNode* cur_wordNode = NULL;
  cur_wordNode = anagram -> words;
  if (cur_wordNode == NULL) return;
  char* word = NULL;
  while (cur_wordNode != NULL) {
    if (cur_wordNode -> word != NULL) {
      word = (char*)cur_wordNode -> word;
      printf("%s ", word);}
      cur_wordNode = cur_wordNode -> next_word;
      word = NULL;
  }
  printf("; num: %d\n", anagram -> num_words);
}
