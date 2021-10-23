#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg_num, char** args){
  if(arg_num != 2){
    printf("Please put an argument in this format: ");
    printf("./[executable file] \"[text to parse]\"\n");
    exit(0);
  }
  
  char* rest = args[1];
  const char* delim = " ";
  
  char* token = strtok_r(args[1], delim, &rest);
  
  while (token != NULL){
    printf("%s\n", token);
    token = strtok_r(NULL, delim, &rest);
  }
  
  return (0);
}