#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int srcFD,destFD,nbread;
	char* buffer[1024];
	srcFD = open(argv[1],O_RDONLY);
	destFD = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	while((nbread = read(srcFD, buffer, 1024)) > 0)
	{
    if(write(destFD, buffer, nbread) != nbread)
			printf("\nError in writing data to %s\n",argv[2]);
	}

return 0;
}
