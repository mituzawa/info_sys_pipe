
all: fd1_dup fd_1_2_3 parent_fd1_child_fd1 pipe_dup pipe_dup2 redirect_fd0

clean:
	rm -f fd1_dup fd_1_2_3 parent_fd1_child_fd1 pipe_dup pipe_dup2 redirect_fd0

fd1_dup: fd1_dup.c
	gcc -o fd1_dup fd1_dup.c -Wall

fd_1_2_3: fd_1_2_3.c
	gcc -o fd_1_2_3 fd_1_2_3.c -Wall

parent_fd1_child_fd1: parent_fd1_child_fd1.c
	gcc -o parent_fd1_child_fd1 parent_fd1_child_fd1.c -Wall

pipe_dup: pipe_dup.c
	gcc -o pipe_dup pipe_dup.c

pipe_dup2: pipe_dup2.c
	gcc -o pipe_dup2 pipe_dup2.c

redirect_fd0:
	gcc -o redirect_fd0 redirect_fd0.c -Wall

