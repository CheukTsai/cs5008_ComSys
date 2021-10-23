#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>
#include <time.h>

#define MAXARGS 5
#define MAXLINE 8192
#define NUM_OF_COMMANDS 4
#define CHAR_LINE_CHANGE_MARK 10


// Wrapper of fgets. Checks and quits on Unix error.
char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

void processing_motivator() {
  printf("Checking your guess\n");
  sleep(1);
  int i;
  for (i = 0; i < 3; i++) {
    printf(".\n");
    sleep(1);
  }
}

void* cd(char* input) {
  // TODO: Implement cd
  if(!input) return;
  chdir(input);

}

void* help(char* input) {
  // TODO: Implement help
  printf("*******************************************\n\n");
  printf("K-SEA-SHELL, version 1.0, developed by Zhuocai Li.\n");
  printf("These shell commands are defined internally.  Type 'help' to see this list.\n\n");
  printf("*******************************************\n\n");
  printf("help - see all the built-in shell commands\n");
  printf("cd [dir] - move through your directory tree\n");
  printf("guess - have a fun game! guess a random number now!\n");
  printf("exit - terminate the shell\n\n");
  printf("*You may also try out other commands built in GNU bash.\n\n");
  printf("such as 'ls', 'mkdir [dir]', etc.\n\n");
  printf("--------------------------------------------------------------------\n");
}

// TODO: two more built-in functions

// 1. exit
void* exit_shell(char* input) {
  printf("Exit K-SEA-shell!\n");
  exit(0);
}

void* guessing_game(char* input) {
  char guess[MAXLINE];
  printf("******************************************\n\n");
  printf("Welcome to the guessing game!\n");
  printf("You will need to guess a random number!\n");
  printf("Please type in a non-negative integer to check if you are right!\n\n");
  printf("IMPORTANT: Range: [0, 100]\n\n");
  printf("******************************************\n");
  srand((unsigned)time(NULL));
  int target = rand() % 101;
  int flag = 0;
  while (flag != 1) {
    sleep(1);
    printf("Your guess > ");
    Fgets(guess, MAXLINE, stdin);
    printf("Your guess is %s", guess);
    processing_motivator();
    if (check_num(guess) == 1) {
      int num = atoi(guess);
      flag = guess_body(target, num);
    }
  }
}

int check_num(char array[]) {
  int i;
  for (i = 0; i < MAXLINE; i++){
    if (array[i] == CHAR_LINE_CHANGE_MARK) break;
    if (isdigit(array[i]) == 0) {
      printf("You must type in a non-negative integer!\n");
      return 0;
    }
  }
  return 1;
}

int guess_body(int target, int num) {
  if (num < target) {
    printf("Your guessing number is too small!\n");
    return 0;
  }
  if (num > target) {
    printf("Your guessing number is too large!\n");
    return 0;
  }
  printf("******************************************\n");
  printf("Congratulations! The random number is %d! You are right!\n", target);
  printf("End of guessing game...\n");
  printf("******************************************\n");
  return 1;
}

// TODO: Put your command names here
char* commands[] = {"cd", "help", "exit", "guess"};

// TODO: Put your command function pointers here
void* (*command_functions[])(char*) = {cd, help, exit_shell, guessing_game};

// Wrapper of fork(). Checks for fork errors, quits on error.
pid_t Fork(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
    exit(0);
  }
  return pid;
}

// Is the command one built into the shell?
// That is, that the *shell* has implemented?
// If so, execute it here
int builtin_command(char** argv) {
  // TODO: Loop through
  int i;
  
  for (i = 0; i < NUM_OF_COMMANDS; i++){
    int res = strcmp(commands[i], argv[0]);
    if (res == 0) {
      // call the right function.
      command_functions[i](argv[1]);  // some argument
      return i;
    }
  }

  return -1;
}

void REPL(char** argv, char* cmdline) {
    const char* delim = " \n";
    char* rest = cmdline;
    char* token = strtok_r(cmdline, delim, &rest);
    int i = 0;
    while (token != NULL) {
      argv[i] = token;
      token = strtok_r(NULL, delim, &rest);
      i++;
    }
}

void eval(char *cmdline) {

  char *argv[MAXARGS];  // Argument list execve()

  int k;
  for (k = 0; k < MAXARGS; k++){
    argv[k] = NULL;
  }
  char buf[MAXLINE];  // Holds modified command line
  pid_t pid;  // Process id
  strcpy(buf, cmdline);
  // Split buf into args
  REPL(argv, buf);
  if (argv[0] == NULL) {
    return;  // Ignore empty lines
  }
  
  if (builtin_command(argv) == -1) {
    // Check that the command/program exists in Unix (ie /bin/) OR (see below)
    // Create a child process
    // Run the program/command (execve...)
    // -- what is the result of exec if the command is bogus?
    pid = Fork();
    char path[100] = "/bin/";
    strcat(path, argv[0]);
    argv[0] = path;
    if(pid == 0) {
      int res = execve(argv[0], argv, NULL);  // see run_ls.c for an example
      if (res < 0) {
        // print error message
        printf("Command not found--Did you mean something else?\n");
      } 
    } else {
      // TODO: Be sure to wait for the child process to terminate
      wait(NULL);
    }
  }
}

int main() {
  char cmdline[MAXLINE]; 
   // command line buffer
  while (1) {
    
    // Print command prompt
    printf("k-sea-shell> ");
    // Read input from user
    Fgets(cmdline, MAXLINE, stdin);

    // If we get the eof, quit the program/shell
    if (feof(stdin)) {
      exit(0);
    }

    // Otherwise, evaluate the input and execute.
    eval(cmdline);
  }
}