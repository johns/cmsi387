#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
	const int BUFFER_MAX = 1024;
	int fd = open(argv[1], O_RDONLY, 0000);
	char buffer[BUFFER_MAX];

	int currentReadByte = read(fd, buffer, BUFFER_MAX);
	int lineCount = 0;
	int wordCount = 0;
	int byteCount = 0;

	while (currentReadByte > 0) {
		for (int i = 0; i < currentReadByte; i++) {
			if (isspace(buffer[i]) && !isspace(buffer[i+1])) {
				wordCount++;
			}
			if (buffer[i] == '\n') {
				lineCount++;
			}
		}
		byteCount += currentReadByte;
		currentReadByte = read(fd, buffer, BUFFER_MAX);
	}
	close(fd);

	char printedString[BUFFER_MAX];
	sprintf(printedString, "%i %i %i %s \n", lineCount, wordCount, byteCount, argv[1]);

	write(1, printedString, strlen(printedString));
	return 0;
}
