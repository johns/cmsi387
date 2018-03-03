#include <dirent.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
	char* newPath;
	char currentPath[PATH_MAX];
	newPath = getcwd(currentPath, PATH_MAX);

	if (argc == 1) {
		chdir(getenv("HOME"));
	} else {
		strcat(newPath, "/");
		strcat(newPath, argv[1]);
		chdir(newPath);
	}

	newPath = getcwd(currentPath, PATH_MAX);
	strcat(newPath, "\n");
	write(1, newPath, strlen(newPath));

	return 0;
}
