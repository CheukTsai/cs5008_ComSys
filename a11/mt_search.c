#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>
#include <time.h>


// ****************************
// This code is provided as an *optional* framework to use to
// write your multi-threaded search code for Assignment 11.
//
// Feel free to change anything you want to in this.
// ****************************

// ===================================================
// Global Variables
// ===================================================

#define MAX_NUM_RESULTS 100
#define MAXARGS 5
#define MAXLINE 8192
#define MAXDIGITS 5

int num_data_points;
int section_size;

int num_lines;
char* filename;

// Array of numbers to search
int* data;

// Number to be found
int target;

// Array of indices of target number
int results[MAX_NUM_RESULTS];
// Number of results we have so far
int num_results = 0;


// Used for synchronization.
// I encourage you to rename this something more meaningful.
pthread_mutex_t lock;
sem_t semaphore;

// All the threads (an array)
pthread_t* threads;
int num_threads;
int next_value_to_check = 0;
int* numbers;

// ===================================================
// Functions
// ===================================================

// The function that each thread will run
// to look for the target value in the array.
// The argument provided is a pointer to the array
// where this thread should start looking for the target.
// (This can be either the index OR the address. Your choice.)
// Each thread will look at a max of section_size elements.
// Wrapper of fgets. Checks and quits on Unix error.

void *DoSearch(void *arg) {
  int indent = next_value_to_check;
  next_value_to_check++;

  sem_wait(&semaphore);
  pthread_mutex_lock(&lock);
  printf("i'm thread %d\n", indent + 1);
  int last = section_size * (indent + 1);
  if (last >= num_lines) last = num_lines;
  int i = 0;
  for (i = section_size * indent; i < last; i++) {
  // Do something.
    if (numbers[i] == target) {
      results[num_results] = i;
      num_results++;
      printf("Found in Line %d.\n", i+1);
    }
  }
  pthread_mutex_unlock(&lock);
  return NULL;
}

// Creates all the threads and starts them running.
// Makes sure the thread IDs are stored in the global threads array.
void MakeThreads(int num_threads) {
  threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
  int args[num_threads];
  int i;
  printf("About to spawn threads\n");
  for (i = 0; i < num_threads; i++) {
    printf("Starting thread %d\n", i+1);
    args[i] = i;
    pthread_create(&threads[i], NULL, DoSearch, &args[i]);
  }
}

// Opens the file called filename.
// Reads line by line, adding each number to the
// global data array.
char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

void ReadFile(char* filename) {
  FILE *stream = fopen(filename, "r");
  char line[MAXDIGITS];
  numbers = malloc(sizeof(int) * num_lines);
  int i;
  for (i = 0; i < num_lines; i++) {
    Fgets(line, MAXDIGITS, stream);
    numbers[i] = atoi(line);
  }
  fclose(stream);
}

// Prints out the results, stored in the
// global "results" array.
void PrintResults() {
  int i;
  for (i = 0; i < MAX_NUM_RESULTS; i++) {
    if (results[i]) {
      printf("Result found in line %d\n", results[i]+1);
    }
  }
}

void Work() {
  int i = 0;
  for (i = 0; i < num_threads; i++) {
    sem_post(&semaphore);
  }

  for (i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("Threads have joined\n");
}

void receive_input(char** argv) {
  printf("start : %s\n", argv[0]);

  filename = argv[1];
  printf("filename : %s\n", filename);

  target = atoi(argv[2]);
  printf("target : %d\n", target);

  num_threads = atoi(argv[3]);
  printf("num_threads : %d\n", num_threads);

  num_lines = atoi(argv[4]) - 1;
  printf("num_lines : %d\n", num_lines);

  if (num_lines % num_threads == 0) {
    section_size = num_lines/num_threads;
  } else {
    section_size = num_lines/num_threads + 1;
  }
}

int main(int argc, char* argv[]) {
  // START HERE
  // Read in the arguments and populate global variables.
  receive_input(argv);
  // Create the threads
  sem_init(&semaphore, 0, 0);
  pthread_mutex_init(&lock, NULL);
  // Read the file
  MakeThreads(num_threads);
  ReadFile(filename);
  // Wait for threads to finish doing their job
  Work();
  // Print out the results
  PrintResults();
  // Clean up everything!
  // Free everything you malloc'd.
  // Don't forget to destroy the semaphore and mutex, which
  // get malloc'd when you create them.
  free(numbers);
  free(threads);
  sem_destroy(&semaphore);
  pthread_mutex_destroy(&lock);
  exit(0);
}
