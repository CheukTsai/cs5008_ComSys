#ifndef A2_H
#define A2_H


/*
 * Ask on Piazza with any other questions!
 */

// A Name consists of first, last, and
// and an OPTIONAL middle name.
struct Name {
  char *first;
  char *middle;
  char *last;
  int age;
};

typedef struct Name Name;


// Copy the string <first> <middle> <last> to the destination array. 
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Ivan Bitdiddle".
//
//  If the middle name is NULL, then print:
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name
// dest: the destination array/string
void Big(Name *name, char* dest);

// Copy the string <last>, <first> to the destination array. 
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
// dest: the destination array/string
void Last(Name *name, char* dest);

// Copy the string <first> <last> to the destination array. 
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
// dest: the destination array/string
void Reg(Name *name, char* dest);

// Copy the string <first> <middle-initial>. <last> 
//  to the destination array. 
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then the output array will have:
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, copy:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
// dest: the destination array/string
void Mid(Name *name, char* dest);

// Copy the first name only to the destination string.
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben".
//
// name: a pointer to a Name
// dest: the destination array/string
void Small(Name *name, char* dest);

// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
void FormatName(Name *name, char format);

// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest);


#endif
