#include "gtest/gtest.h"
extern "C"
{
#include "Anagram.h"
#include "Hashtable.h"
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct wordNode {
  const char* word; 
  WordNode* next_word;
};

WordNode* CreateWordNode(const char* word) {
  WordNode* wordNode = (WordNode *)malloc(sizeof(WordNode));
  // wordNode -> word = malloc(sizeof(char) * strlen(word) + 1);
  wordNode -> word = word;
  wordNode -> next_word = NULL;
  return wordNode;
}

TEST(Anagram, CreateWordNode){
  WordNode *node = CreateWordNode("boy");
  EXPECT_EQ(strcmp(node -> word, "boy"), 0);
  EXPECT_TRUE(node -> next_word == NULL);
  free(node);
}

TEST(Hashtable, Put){
  Hashtable hashtable = CreateHashtable(15);
  const char* key = "abc";
  Anagram* anagram = CreateAnagram((char*)"a");
  Put(hashtable, key, anagram);
  EXPECT_EQ(hashtable -> num_elements, 1);
  EXPECT_EQ(hashtable -> num_buckets, 15);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}