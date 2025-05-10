#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	char *cmd1[3];
	cmd1[0] = "/usr/bin/echo";
	cmd1[1] = "hello world";
	cmd1[2] = NULL;

	char *cmd2[2];
	cmd2[0] = "/usr/bin/wc";
	cmd2[1] = NULL;

	int fd[2];
	pipe(fd);

	pid_t pid1 = fork();
	if (pid1 == 0) {
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execvp(cmd1[0], cmd1);
	}

	pid_t pid2 = fork();
	if (pid2 == 0) {
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		execvp(cmd2[0], cmd2);
	}

	close(fd[0]);
	close(fd[1]);

	wait(NULL);
	wait(NULL);
}
