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

#include <stdint.h>

#include "Anagram.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H


struct hashtableInfo {
  int num_buckets;
  int num_elements;
  Anagram** buckets;
};

typedef struct hashtableInfo* Hashtable;


// Allocates and returns a new Hashtable.
//
// INPUT:
//   numBuckets: The number of buckets this hashtable will start with.
//
// Returns NULL if the hashtable was unable to be malloc'd, or
// the hashtable.
Hashtable CreateHashtable(int num_buckets);

// Destroys and Frees the hashtable.
//
// Input:
//   ht: the table to be free'd. It is unsafe to use the
//    hashtable after this is called.
void DestroyHashtable(Hashtable ht);

// Puts the given key value pair into the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
void Put(Hashtable ht, const char* key, Anagram* value);

// Looks up the given key in the hashtable.
// Returns the Anagram with the gieven key.
//
// INPUT:
//   ht: the hashtable to lookup in
//   key: the key to lookup
//
// Returns the Anagram with the specified key, or NULL if it does not exist.
Anagram* Get(Hashtable ht, const char* key);

// Gets the number of elements in the hashtable.
//
// INPUT:
//   ht: the Hashtable
//
// Returns the number of elements in the hashtable.
int NumElemsInHashtable(Hashtable ht);

// Removes the HTKeyValue with the given key from the
//  hashtable.
//
// INPUT:
//   ht: the hashtable
//   key: the key to remove
//
// Returns the Anagram containing the given key, and it is no longer in the HT.
// Returns NULL if the Anagram with the given key is not in the HT.
Anagram* RemoveFromHashtable(Hashtable ht, const char* key);

// Prints all the Anagrams in the Hashtable that contain
// at least the given threshold of words.
//
// That is: If the threshold is 3, an anagram that has 3 words
// will be printed, but an Anagram with 1 or 2 words will NOT
// be printed.
void PrintAnagrams(Hashtable ht, int threshold);

// Returns the load factor for this Hashtable.
double GetAlpha(Hashtable *hashtable);

#endif  // HASHTABLE_H

