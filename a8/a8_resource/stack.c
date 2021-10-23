#include <stdio.h>

typedef struct stack{
  int stack[5];//kStackSize];
  int head;
} Stack;

//typedef struct stack Stack; 

const int kStackSize = 5;

void push(Stack *s, int n) {
  if ((*s).head < kStackSize) {
    s->stack[s->head++] = n;
  }
  //  return s; // No more call by value, so not returning. 
}

int pop(struct stack s) {
  if (s.head > 0) {
    return s.stack[--s.head];
  }
  return -1; // sentinel value
}

int peek(struct stack s) {
  if (s.head > 0) {
    return s.stack[s.head - 1];
  }
  return -1; // Stack is empty
}

void PrintStack(struct stack s){
printf("%p\n", &s);
  for (int i = 0; i < kStackSize; i++) {
    printf("stack[%d]: %d\n", i, s.stack[i]);
  }
}

int main() {

  printf("%d\n", sizeof(Stack));


  printf("%d\n", sizeof(int));

  struct stack s1;
  s1.head = 0; 


  printf("%p\n", &s1);
  PrintStack(s1); 
  //  s1 = push(s1, 1);
  push(&s1, 1);
  PrintStack(s1); 
  //  s1 = push(s1, 2); // no more call by value
  push(&s1, 2);
  printf("Peek: %d\n", peek(s1));
  printf("Popped: %d\n",pop(s1));
  printf("Peek: %d\n", peek(s1));
  PrintStack(s1); 
}
