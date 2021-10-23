#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crop_hi(int *arr, int len, int ceiling)
{
  /*
    A function to replace replace all numbers greater
    than ceiling in arr with ceiling
  */

  int i;
  for (i = 0; i < len; i++)
    {
      if (arr[i] > ceiling)
        {
	  arr[i] = ceiling;
        }
    }
}

void swap_mid_back(int *arr, int len)
{
  /*
    A function to swap the the last int 
    in arr with the middle element in arr.
  */

  if (len <= 0)
    {
      return;
    }
  int mid = (len - 1) / 2;
  int back = len - 1;
  int m = arr[mid];
  arr[mid] = arr[back];
  arr[back] = m;
}

void redact(char *str)
{
  /*
    A function to replace all digits 
    in a string with a '*'
  */

  if (strlen(str) <= 0)
    {
      return;
    }
  int i;
  for (i = 0; i < strlen(str); i++)
    {
      if (str[i] >= '0' && str[i] <= '9')
        {
	  str[i] = '*';
        }
    }
}

int main()
{
  /*
    Three examples in main function
  */

  printf("Example for crop_hi((1,2,3,4),4,2): \n");
  int num_arr[4] = {1, 2, 3, 4};
  crop_hi(num_arr, 4, 2);
  int i;
  printf("[%d", num_arr[0]);
  for (i = 1; i < 4; i++)
    {
      printf(" ,%d", num_arr[i]);
    }
  printf("]\n");

  printf("Example for swap_mid_back((-4,3,0,1),4): \n");
  int num_arr2[4] = {-4, 3, 0, 1};
  swap_mid_back(num_arr2, 4);
  int j;
  printf("[%d", num_arr2[0]);
  for (j = 1; j < 4; j++)
    {
      printf(" ,%d", num_arr2[j]);
    }
  printf("]\n");

  printf("Example for redact(\n");
  printf("'The part failed 58 percents of the time'):\n");
  char str[] = "The part failed 58 percents of the time";
  redact(str);
  printf("%s\n", str);
  return 0;
}
