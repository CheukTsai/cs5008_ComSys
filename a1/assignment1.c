#include <stdio.h>

void WarmUp(){

  /*
    This function is to print
    three lines of "Hello World!"
   */

  int i;
  for(i = 1; i <= 3; i++){
    printf("Hello World!\n");
  }
  printf("\n");
}

void PrintRectangle(int width, int height){

  /*
    This function is to print 
    a rectangle with
    given width and length
   */

  int i, j;
  for(i = 1; i <= height; i++){
    if(i == 1 || i == height){
      for(j = 1; j <= width; j++){
	  printf("-");
	}
      printf("\n");
    }
    else{
      for(j = 1; j <= width; j++){
	if(j != 1 && j != width){
	  printf(" ");
	} 
	else{
	  printf("-");
	}
      }
      printf("\n");
    }
  }
  printf("\n");
}

void PrintFancyRectangle(int width, int height, char symbol, int fill){

  /*
    This function is to print
    a rectangle with
    given width and length,
    can choose whether the
    rectangle is filled or not
   */ 

  int i, j;
  if(fill == 0){
    for(i = 1; i <= height; i++){
      if(i == 1 || i == height){
	for(j = 1; j <= width; j++){
	  printf("%c",symbol);
	}
	printf("\n");
      }
      else{
	for(j = 1; j <= width; j++){
	  if(j != 1 && j != width){
	    printf(" ");
	  }
	  else{
	    printf("%c",symbol);
	  }
	}
	printf("\n");
      }
    }
  }

  if(fill == 1){
    for(i = 1; i <= height; i++){
      for(j = 1; j <= width; j++){
	printf("%c",symbol);
      }
      printf("\n");
    }
  }
  printf("\n");
}

void main(){
  printf("Below is an example of WarmUp\n");
  WarmUp();

  printf("Below is an example of PrintRectangle\n");
  PrintRectangle(5,4);

  printf("Below is an example of PrintFancyRectangle (Filled)\n");
  PrintFancyRectangle(5,4,'+',1);

  printf("Below is an example of PrintFancyRectangle (Not filled)\n");
  PrintFancyRectangle(5,4,'+',0);
}
