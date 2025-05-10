#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd;

	fd = dup(1);
	printf("fd: %d\n", fd);
	write(1, "hello ", 6);
	write(fd, "world\n", 6);
}
