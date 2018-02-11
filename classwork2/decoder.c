//Classwork 2: C-Lions Unite
//Sam Chami, Sam Savini, and John Scott

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Compiled and Tested on Linux.

int main(int argc, char** argv) {
	char result[argc];
	for (int i = 1; i < argc; i++) {
		long intValue = strtol(argv[i], NULL, 10);
		char valueInASC = (char)((int)intValue);
		strncat(result, &valueInASC, 1);
	}
	printf("%s\n", result);
	return 0;
}
