
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Hashtable.h"
#include "Anagram.h"

#define NUM_WORDS_IN_FILE 150


void ReadFile(const char* filename, char** dest, int max_num_words) {
  FILE *cfPtr;

  if ((cfPtr = fopen(filename, "r")) == NULL) {
    printf("File could not be opened\n");
    return;
  } else {
    char* row = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    while ((read = getline(&row, &len, cfPtr)) != -1) {
    row[read - 1] = '\0';
      char* word_mem = (char*)malloc((sizeof(char) * strlen(row)) + 1);
      strcpy(word_mem, row);
      dest[i++] = word_mem;
      if (i > max_num_words) {
        // Too many words
        break;
      }
    }

    char* des = NULL;
    des = row;
    free(des);
    fclose(cfPtr);
    printf("Read %d rows \n", i);
  }
}


// Utilized by qsort in SortWord.
// negative if the first argument is “less” than the second,
// zero if they are “equal”, and
// positive if the first argument is “greater”.
int compare_chars(const void *a, const void *b) {
  const char *da = (const char*) a;
  const char *db = (const char*) b;

  return (*da > *db) - (*da < *db);
}

// Sorts a given word in place--
// After this method is called, the word is
// different than it was before.
// If it started as "apple", it is now "aelpp".
void SortWord(char* word) {
  qsort(word, strlen(word), sizeof(char), compare_chars);
}


void PutWordInHashtable(Hashtable ht, const char* word) {
  // Sort the word to get the key
  char* original_word = malloc(strlen(word)+1);
  strcpy(original_word, word);
  SortWord((char *)word);

  // Check to see if the sorted word is in the HT already.
  Anagram* existing = Get(ht, word);
  if (existing == NULL) {
    // If the Anagram/key doesn't yet exist, create a new Anagram
    // and put it in the Hashtable.
  Anagram* anagram = CreateAnagram((char *)word);
  AddWordToAnagram(anagram, original_word);
  Put(ht, word, anagram);
  // Add the new word to the Anagram
  // Be sure to implement AddWordToAnagram().
  } else {
    AddWordToAnagram(existing, original_word);
  }

  char* tmp = NULL;
  tmp = original_word;
  free(tmp);
}

int main() {
  // Create Hashtable
  // Be sure to implement CreateHashtable().
  Hashtable ht = CreateHashtable(15);

  //   Create place to store the words
  //   (malloc an array to hold all the words in the file)
  //   Utilize the NUM_WORDS_IN_FILE to do this.
  char** words;  // [...more goes here...]
  words = (char **)malloc(sizeof(char*) * NUM_WORDS_IN_FILE + 1);

  // Open and read file
  ReadFile("small_words.txt", words, NUM_WORDS_IN_FILE);

  int i;
  for (i = 0; i < NUM_WORDS_IN_FILE; i++) {  // test
    PutWordInHashtable(ht, words[i]);
  }
  printf("Looking for Anagrams...\n");

  PrintAnagrams(ht, 0);

  char* des = NULL;
  for (i = 0; i < NUM_WORDS_IN_FILE; i++) {  // test
    des = words[i];
    free(des);
    des = NULL;
  }

  char** des2 = NULL;
  des2 = words;
  free(words);


  char* des = NULL;
  for (i = 0; i < NUM_WORDS_IN_FILE; i++) {  // test
    des = words[i];
    free(des);
    des = NULL;
  }

  char** des2 = NULL;
  des2 = words;
  free(words);
  
  
  //   Be sure to implement DestroyHashtable().
  DestroyHashtable(ht);


  Hashtable a = NULL;
  a = ht;
  free(a);
}
