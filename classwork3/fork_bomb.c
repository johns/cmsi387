#include <unistd.h>

  int main() {
      while(1) {
          fork();
          int* i = malloc(1000);
      }
  }
