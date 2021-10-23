void swap(int a, int b){
  int temp;
  temp = a;
  b = a;
  a = temp;
}

int main(){
  int a = 1;
  int b = 2;
  printf("before swapping,\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  
  swap(a,b);
  printf("after swapping,\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return 0;
}