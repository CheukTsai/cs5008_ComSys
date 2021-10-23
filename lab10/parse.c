#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg_num, char** args){
//  if(arg_num != 2){
//    printf("Please put an argument in this format: ");
//    printf("./[executable file] \"[text to parse]\"\n");
//    exit(0);
//  }
//  
//  char* rest = args[1];
  const char* delim = " ";
  
  const int buffSize = 150;
  char buffer[buffSize];
  
  while(1){
    printf("Enter your command > ");
    fgets(buffer, buffSize, stdin);
    
    printf("Input was: %s\n", buffer);
    
    char * rest = buffer;
    
    char* token = strtok_r(buffer, delim, &rest);
    
    while (token != NULL){
      printf("token: %s\n", token);
      printf("rest: %s\n", rest);
      token = strtok_r(NULL, delim, &rest);
    }
  }
  return (0);
}