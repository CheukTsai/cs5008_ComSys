int main(){
  long a = 1;
  long b = 2;
  printf("before swapping,\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  
  long temp;
  temp = a;
  b = a;
  a = temp;
  printf("after swapping,\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return 0;
}