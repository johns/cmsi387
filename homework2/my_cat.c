#include <fcntl.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    char abspath[PATH_MAX];
    realpath(argv[i], abspath);
    int fd = open(abspath, O_RDONLY);
    char buffer[1024];
    while(read(fd, buffer, 1024) > 0) {
      write(1, buffer, 1024);
    }
  }
  return 0;
}
