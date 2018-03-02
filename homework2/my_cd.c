#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  char buffer[1024];
  char *path = realpath(argv[1], buffer);

  chdir(path);
  getwd(buffer);
  int bufferLength = strlen(buffer);
  buffer[bufferLength] = '\n';
  buffer[bufferLength+1] = '\0';
  write(1, buffer, bufferLength);
}
