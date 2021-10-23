#include <stdio.h>
#include "user.h"

void StandardGreeting(User *user) {
  printf("Hello, %s!\n", user->first_name);
}

void FormalGreeting(User *user) {
  printf("Greetings, ID: %d\n", user->id);
  printf("Name: %s, %s\n", user->last_name, user->first_name);
}