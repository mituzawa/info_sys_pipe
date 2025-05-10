#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *argv[2];

	argv[0] = "/usr/bin/cat";
	argv[1] = NULL;

	if (fork() == 0) {
		close(0);
		open("./redirect_fd0.c", O_RDONLY);
		execvp(argv[0], argv);
	}
}
