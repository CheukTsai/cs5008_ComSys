#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0

int state[N];
int phil[N] = { 0, 1, 2 , 3, 4 };
int forks[N];

sem_t fork_ids[N];
sem_t cur_fork;

int eat_times[N] = {0};

int get_left_fork(int phnum) {
  return (phnum - 1) % N;
}

int get_right_fork(int phnum) {
  return (phnum + 1) % N;
}

void eat(int phnum) {
  state[phnum] = EATING;
  printf("Philosopher %d is eating! \n", phnum);
  sleep(5);
}

void take_forks(int phnum) {
  state[phnum] = HUNGRY;

  printf("Philosopher %d is hungry! \n", phnum);
  int left_fork = get_left_fork(phnum);

  printf("This is left fork\n");
//   while (1) {
    // if (forks[left_fork] == -1) {
  sem_wait(&cur_fork);
  printf("Philosopher %d is taking %d fork (left)! \n", phnum, left_fork);
  forks[left_fork] = phnum;
//       break;
//     } else {
//       printf("Someone else has this fork!\n");
//     }
//     sleep(1);
//   }

  int right_fork = get_right_fork(phnum);
  printf("This is right fork\n");
//   while (1) {
//     if (forks[right_fork] == -1) {
      sem_wait(&cur_fork);
      printf("Philosopher %d is taking %d fork (right)! \n", phnum, right_fork);
      forks[right_fork] = phnum;
//       break;
//     } else {
//       printf("Someone else has this fork!\n");
//     }
//     sleep(1);
//   }
}

void put_forks(int phnum) {
  printf("Philosopher %d putting left fork %d\n",
   phnum, get_left_fork(phnum));
  forks[get_left_fork(phnum)] = -1;
  sem_post(&cur_fork);
  printf("Philosopher %d putting right fork %d\n",
   phnum, get_right_fork(phnum));
  forks[get_right_fork(phnum)] = -1;
  sem_post(&cur_fork);
  printf("Philosopher %d is thinking! \n", phnum);
  state[phnum] = THINKING;
}

void* philosopher(void* num) {
  while (1) {
    int* i = num;
    sleep(1);
    take_forks(*i);
    sleep(0);
    eat(*i);
    sleep(0);
    put_forks(*i);
    printf("Philosopher %d eat times: %d \n", *i, eat_times[*i]);
  }
}

int main(){
  int i;
  pthread_t thread_id[N];

  for (i = 0; i < N; i++) {
    sem_init(&fork_ids[i], 0, i);
    forks[i] = -1;
  }

  sem_init(&cur_fork, 0, N);

  for (i = 0; i < N; i++) {
    pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);

    printf("Philosopher %d is thinking! \n", i + 1);
  }

  for (i = 0; i < N; i++) {
    pthread_join(thread_id[i], NULL);
  }
}