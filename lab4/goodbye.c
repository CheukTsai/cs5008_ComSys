#include <stdio.h>
#include "user.h"

void InformalGoodbye(User *user) {
  printf("See ya later %s!\n", user->first_name);
}

void FormalGoodbye(User *user) {
  printf("Good bye, ID: %d\n", user->id);
  printf("%s, %s\n", user->last_name, user->first_name);
}
