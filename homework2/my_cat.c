#include <fcntl.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  const int BUFFER_MAX = 1024;
  for (int i = 1; i < argc; i++) {
    char abspath[PATH_MAX];
    realpath(argv[i], abspath);
    int fd = open(abspath, O_RDONLY);
    char buffer[BUFFER_MAX];
    while(read(fd, buffer, BUFFER_MAX) > 0) {
      write(1, buffer, BUFFER_MAX);
    }
  }
  return 0;
}
