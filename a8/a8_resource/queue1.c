#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Defining a queue based on an array.

struct queueOfCustomers{
  char* customers[SIZE];
  int front;
  int rear;
};

typedef struct queueOfCustomers QueueOfCustomers;


// ===============================
// Queue Operation Prototypes
// ===============================


char* dequeue(QueueOfCustomers*);

void enqueue(char* newBook, QueueOfCustomers*);

char* front(QueueOfCustomers*);

char* back(QueueOfCustomers*);

QueueOfCustomers* create();

void destroy(QueueOfCustomers*);

// ===============================
// Queue Operation Implementation
// ===============================

char* dequeue(QueueOfCustomers* queue){
  //  queue->front;
  return (queue->customers[queue->front--]);
}

void enqueue(char* newBook, QueueOfCustomers* queue){
  if (queue->rear == 0){
    // Queue is full!!!
    printf("Can't add another customer-- the queue is full!");
  }
  else{
    //    queue->rear--;
    queue->customers[--queue->rear] = newBook;
  }
  
}

int size(QueueOfCustomers* queue){
  return(queue->front - queue->rear );
}

char* front(QueueOfCustomers* queue){
  
}

char* back(QueueOfCustomers* queue){

}

QueueOfCustomers* create(){
  // Allocate space on the heap
  QueueOfCustomers* newQueue =
      (QueueOfCustomers*)malloc(sizeof(QueueOfCustomers));
  
  // Initialize anything
  newQueue->front = SIZE-1;
  newQueue->rear = SIZE-1;
  
  // For purposes of demo, I'm doing this here. It's not always necessary:
  int i=0;
  for (i=0; i<SIZE; i++){
    newQueue->customers[i] = "";
  }
  
  // Return pointer to new queue
  return newQueue;
}

void destroy(QueueOfCustomers* queue){
  
}


void printQueue(QueueOfCustomers* customers){
  printf("Printing the queue of customers: \n");
  int i;
  for (i=SIZE; i>=0; i--){
    if (i == customers->front ){
      printf("F------>");
    }
    if (i < SIZE){
      printf("\t[%d: %25s ]", i, customers->customers[i]);
    }
    if (i == customers->rear){
      printf("<------R");
    }
    printf("\n");
  }
}

int main(){
  QueueOfCustomers *queue = create();

  printQueue(queue);

  printf("\n\n");

  enqueue("Harry Potter", queue);
  enqueue("War and Peace", queue);
  enqueue("Hunger Games", queue);
  enqueue("There's a Right Way", queue);

  printQueue(queue);

  printf("\nThe next customer we're helping: %s\n", dequeue(queue));

  printf("\n\n");
  printQueue(queue);

  printf("\nThe next customer we're helping: %s\n", dequeue(queue));

  printf("\n\n");
  printQueue(queue);

  enqueue("Diary of a Wimpy Kid", queue);
  printQueue(queue);

  printQueue(queue);

  enqueue("The Goldfinch", queue);

  printf("\n\n The size of the queue: %d\n\n", size(queue));


  destroy(queue);

}
