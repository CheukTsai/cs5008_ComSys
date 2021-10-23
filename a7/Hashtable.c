/*
 *  Adrienne Slaughter
 *  5008 Summer 2021
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  See <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#include "Hashtable.h"
#include "Anagram.h"
#include "Assert007.h"

// Private Prototypes
// These are prototypes for functions that should not be used
// by anything except Hashtable.c.

void ResizeHashtable(Hashtable ht);

int HashKeyToBucketNum(Hashtable ht, const char* key);


Hashtable CreateHashtable(int num_buckets) {
  if (num_buckets <= 0) {
    return NULL;
  }
  Hashtable hashtable = (Hashtable)malloc(sizeof(struct hashtableInfo));
  hashtable -> num_buckets = num_buckets;
  hashtable -> buckets = (Anagram**)malloc(num_buckets*sizeof(Anagram*));
  int i;
  for (i = 0; i< num_buckets; i++) {
    hashtable -> buckets[i] = NULL;
  }
  hashtable -> num_elements = 0;
  return hashtable;
}


void DestroyHashtable(Hashtable ht) {
  int i;
  Anagram* head = NULL;
  for (i = 0; i < ht -> num_buckets; i++) {
    head = ht -> buckets[i];
    Anagram* temp = NULL;
    while (head != NULL) {
      temp = head;
      head = head -> next_anagram;
      DestroyAnagram(temp);
      temp = NULL;
    }
    head = NULL;
  }

  // Anagram** tmp = NULL;
  // tmp = ht -> buckets;
  // free(tmp);
  free(ht -> buckets);

  // Anagram* des = NULL;
  // for (i = 0; i < ht -> num_buckets; i++) {  // test
  //   des = ht -> buckets[i];
  //   free(des);
  //   des = NULL;
  // }

  // printf("successfully destoryed Hashtable\n");
}


int HashKeyToBucketNum(Hashtable ht, const char* key) {
  int val = 0;
  int i;
  for (i = 0; i < strlen(key); i++) {
    val += key[i];
  }
  return val % ht->num_buckets;
}

Anagram* Get(Hashtable ht, const char* key) {
  // Determine which bucket the key is in
  // Get the list in the bucket
  int hash_key = HashKeyToBucketNum(ht, key);

  // Iterate through the list to find an Anagram with the specified key
  Anagram* cur_anagram = ht -> buckets[hash_key];
  while (cur_anagram != NULL) {
    if (cur_anagram -> anagram_key != NULL) {
    if (strcmp(cur_anagram -> anagram_key, key) == 0) {
      return cur_anagram;
    }
    cur_anagram = cur_anagram -> next_anagram;
    }
  }

  return NULL;
}

void Put(Hashtable ht, const char* key, Anagram* anagram) {
  // Check if the Hashtable needs to be resized
  ResizeHashtable(ht);

  // Determine which bucket we're inserting into,
  int num = HashKeyToBucketNum(ht, key);
  // Get the list
  // Hashtable hashtable = (Hashtable)malloc(sizeof(struct hashtableInfo));
  // hashtable = ht;
  if (ht -> buckets[num] == NULL) {
    ht -> buckets[num] = anagram;
    // ht -> num_elements++;
  } else {
  // Add the new Anagram to the list in that bucket
    Anagram* temp = ht -> buckets[num];
    while (temp -> next_anagram != NULL) {
      temp = temp -> next_anagram;
    }
    temp -> next_anagram = anagram;
    // ht -> num_elements++;
  }
  ht -> num_elements++;
}

int NumElemsInHashtable(Hashtable ht) {
  return ht->num_elements;
}


Anagram* RemoveFromHashtable(Hashtable ht, const char* key) {
  // Find the Anagram with given key.
  Anagram* anagram = Get(ht, key);
  // Remove it from the list it is in.
  if (anagram) {
    Anagram* cur_anagram = *(ht -> buckets) + (HashKeyToBucketNum(ht, key));
    while (cur_anagram -> anagram_key != key) {
      Put(ht, key, cur_anagram);
      cur_anagram = cur_anagram -> next_anagram;
    }
    Put(ht, key, cur_anagram -> next_anagram);
  }

  // Return it.
  return NULL;
}

void Put2(Hashtable ht, const char* key, Anagram* anagram) {
  // Determine which bucket we're inserting into,
  int num = HashKeyToBucketNum(ht, key);
  // Get the list
  if (ht -> buckets[num] == NULL) {
    ht -> buckets[num] = anagram;
    // ht -> num_elements++;
  } else {
  // Add the new Anagram to the list in that bucket
    Anagram* temp = ht -> buckets[num];
<<<<<<< HEAD
    while(temp -> next_anagram != NULL){
=======
    while (temp -> next_anagram != NULL) {
>>>>>>> 99b5820b0ffffe944e48438935cfc43ce465ce92
      temp = temp -> next_anagram;
    }
    temp -> next_anagram = anagram;
  }
  ht -> num_elements++;
}

void ResizeHashtable(Hashtable ht) {
  Assert007(ht != NULL);
  // Resize if the load factor is > 3.
  if (ht->num_elements < 3 * ht->num_buckets)
    return;
  // This is the resize case.  Allocate a new hashtable.
  Hashtable newht = CreateHashtable(ht->num_buckets * 9);
  // Give up if out of memory.
  if (newht == NULL)
    return;

  // For every element in the Hashtable,
  // Put it in the new Hashtable.
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
<<<<<<< HEAD
    
    if(ht -> buckets[i] == NULL) continue;
    Anagram* head = ht -> buckets[i];
    
=======
    if (ht -> buckets[i] == NULL) continue;
    Anagram* head = ht -> buckets[i];

>>>>>>> 99b5820b0ffffe944e48438935cfc43ce465ce92
    Anagram* tmp = NULL;
    while (head != NULL) {
      // int hash_key = HashKeyToBucketNum(newht, head -> anagram_key);
      tmp = head;
      head = head -> next_anagram;
      tmp -> next_anagram = NULL;
      Put2(newht, tmp -> anagram_key, tmp);
      tmp = NULL;
    }
  }
  // Sneaky: swap the structures, then free the new table,
  // and we're done.
  { struct hashtableInfo tmp;
    tmp = *ht;
    *ht = *newht;
    *newht = tmp;
    // This is destroying what *was* the old HT.
  }
    free(newht -> buckets);
    Hashtable temp = NULL;
    temp = newht;
    free(temp);
<<<<<<< HEAD
  
=======

>>>>>>> 99b5820b0ffffe944e48438935cfc43ce465ce92

  return;
}

void PrintAnagrams(Hashtable ht, int threshold) {
  // Iterate through all Anagrams in the hashtable.
  // If the Anagram contains more than the specified
  // number of words, print it.
  int i;
  Anagram* cur_anagram = NULL;
  for (i = 0; i < ht -> num_buckets; i++) {
    cur_anagram = ht -> buckets[i];
    printf("bucket[%d]:", i);
    if (cur_anagram == NULL) {
      printf("\n");
      continue;
    }
<<<<<<< HEAD
    
=======

>>>>>>> 99b5820b0ffffe944e48438935cfc43ce465ce92
    while (cur_anagram != NULL) {
      if (cur_anagram -> num_words > threshold) {
        PrintAnagram(cur_anagram);
      }
      cur_anagram = cur_anagram -> next_anagram;
    }
    cur_anagram = NULL;
    printf("\n");
  }
}
