#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "a2.h"

// Function helps to capitalize the first letter
// and make the rest into lower cases
char* CapAndSmall(char* word){
  int wordLength = strlen(word);
  char* wordNew = (char*)malloc(sizeof(*wordNew) * (wordLength + 1));
  int i;
  wordNew[0] = toupper(word[0]);
  for(i = 1; i< wordLength; i++){
    wordNew[i]  = tolower(word[i]);
  }
  wordNew[wordLength+1] = '\0';
  return wordNew;
}

// YOUR CODE GOES HERE
// See a2.h for function specifications.

//  name: a pointer to a Name
//  dest: the destination array/string
void Big(Name *name, char* dest) {
  char *firstOrigin = name -> first;
  char *middleOrigin = name -> middle;
  char *lastOrigin = name -> last;
  char* first = CapAndSmall(firstOrigin);
  char* last = CapAndSmall(lastOrigin);
  if(middleOrigin != NULL){
    char* middle = CapAndSmall(middleOrigin);
    sprintf(dest, "%s %s %s", first, middle, last);
    free(middle);
  }
  else{
    sprintf(dest, "%s %s", first, last);
  }
  free(first);
  free(last);
}

// name: a pointer to a Name
// dest: the destination array/string
void Last(Name *name, char* dest) {
  char *firstOrigin = name -> first;
  char *lastOrigin = name -> last;
  char* first = CapAndSmall(firstOrigin);
  char* last = CapAndSmall(lastOrigin);
  sprintf(dest, "%s, %s",last, first);
  free(first);
  free(last);
}

// name: a pointer to a Name
// dest: the destination array/string
void Reg(Name *name, char* dest) {
  char *firstOrigin = name -> first;
  char *lastOrigin = name -> last;
  char* first = CapAndSmall(firstOrigin);
  char* last = CapAndSmall(lastOrigin);
  sprintf(dest, "%s %s", first, last);
  free(first);
  free(last);
}

// name: a pointer to a Name
void Mid(Name *name, char* dest) {
  char *firstOrigin = name -> first;
  char *middleOrigin = name -> middle;
  char *lastOrigin = name -> last;
  char* first = CapAndSmall(firstOrigin);
  char* last = CapAndSmall(lastOrigin);
  if(middleOrigin != NULL){
    char init[2];
    char* middle = CapAndSmall(middleOrigin);
    snprintf(init, 2, "%s", middle);
    sprintf(dest, "%s %s. %s",first, init, last);
    free(middle);
  }
  else{
    sprintf(dest, "%s %s", first, last);
    free(first);
    free(last);
  }
}

// name: a pointer to a Name
// dest: the destination array/string
void Small(Name *name, char* dest){
  char *firstOrigin = name -> first;
  char* first = CapAndSmall(firstOrigin);
  sprintf(dest, "%s", first);
  free(first);
}

// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)

void FormatName(Name *name, char format){
  char dest[100] = {};
  if(format == 'b' || format == 'B'){
    Big(name, dest);
  }
  if(format == 'l' || format == 'L'){
    Last(name, dest);
  }
  if(format == 'r' || format == 'R'){
    Reg(name, dest);
  }
  if(format == 'm' || format == 'M'){
    Mid(name, dest);
  }
  if(format == 's' || format == 'S'){
    Small(name, dest);
  }
  printf("%s", dest);
}

// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest) {
  if(format == 'b' || format == 'B'){
    Big(name, dest);
  }
  if(format == 'l' || format == 'L'){
    Last(name, dest);
  }
  if(format == 'r' || format == 'R'){
    Reg(name, dest);
  }
  if(format == 'm' || format == 'M'){
    Mid(name, dest);
  }
  if(format == 's' || format == 'S'){
    Small(name, dest);
  }
}

