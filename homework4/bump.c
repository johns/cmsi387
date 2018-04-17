// C Program to design a shell in Linux
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

#define BUMP_RL_BUFSIZE 1024
#define BUMP_TOK_BUFSIZE 64
#define BUMP_TOK_DELIM " \t\r\n\a"

/*
  Function Declarations for builtin shell commands:
 */
int bump_cd(char** args);
int bump_help(char** args);
int bump_sup(char** args);
int bump_exit(char** args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char* builtin_str[] = {
  "cd",
  "help",
  "sup",
  "exit"
};

int (*builtin_func[]) (char**) = {
  &bump_cd,
  &bump_help,
  &bump_sup,
  &bump_exit
};

int bump_num_builtins() {
  return sizeof(builtin_str) / sizeof(char*);
}

/*
  Builtin function implementations.
*/
int bump_cd(char** args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "bump: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("bump");
    }
  }
  return 1;
}

int bump_help(char** args)
{
  int i;
  printf("John Scott's BUMP\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < bump_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int bump_sup(char **args)
{
  return 0;
}

int bump_exit(char **args)
{
  return 0;
}

int bump_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("bump");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("bump");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

char *bump_read_line(void)
{
  char *line = NULL;
  size_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}

char** bump_split_line(char *line)
{
  int bufsize = BUMP_TOK_BUFSIZE, position = 0;
  char** tokens = malloc(bufsize* sizeof(char*));
  char* token;

  if (!tokens) {
    fprintf(stderr, "bump: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, BUMP_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += BUMP_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "bump: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, BUMP_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int bump_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < bump_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return bump_launch(args);
}

void bump_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = bump_read_line();
    args = bump_split_line(line);
    status = bump_execute(args);

    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  bump_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
