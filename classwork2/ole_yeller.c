//Classwork 2: C-Lions Unite
//Sam Chami, Sam Savini, and John Scott

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Compiled and Tested on Mac.

char* yell (char* whisper) {
  char shout[strlen(whisper)];
  for(int i = 0; i < (int) strlen(whisper); i++){
    shout[i] = (char) toupper((int)whisper[i]);
  }
  strcat(shout, "!");
  char* s = shout;
  return s;
}

int main(int argc, char *argv[]) {
    char sentence[argc];

    for(int i = 1; i < argc; i++) {
        strcat(sentence, " ");
        strcat(sentence, argv[i]);
    }

    char* result = yell(sentence);
    printf("%s\n", result);
    return 0;
}
