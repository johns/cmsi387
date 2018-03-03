#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDWR | O_CREAT, 0666);
		close(fd);
	}
	return 0;
}
