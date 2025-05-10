#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	if(fork() == 0) {
		write(1, "hello ", 6);
	} else {
		(void) wait(NULL);
		write(1, "world\n", 6);
	}
}
