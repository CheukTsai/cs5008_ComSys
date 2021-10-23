struct user_info {
  char *first_name;
  char *last_name;
  int id;
};

typedef struct user_info User;

// Greetings and goodbyes
void StandardGreeting(User*);
void FormalGreeting(User*);
void InformalGoodbye(User*);
void FormalGoodbye(User*);