#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define P_READ 0
#define P_WRITE 1
#define BUFSIZE 4096

void	command(void)
{
	int		ret;
	char	buf[BUFSIZE];

	ret = read(STDIN_FILENO, buf, BUFSIZE);
	buf[ret] = 0;
	write(STDOUT_FILENO, buf, strlen(buf));
}

void	child_proc(int pipe[2])
{
	int	fd;
	int	r_fd;
	int	w_fd;


	printf("Child: I'm going to close fd for Read\n");
	close(pipe[P_READ]);
	printf("Child: I'm going to connect STDOUT to fd for Write\n");
	w_fd = dup2(pipe[P_WRITE], STDOUT_FILENO); // pipe write substitude stdout
	close(pipe[P_WRITE]);
	if (w_fd == -1)
		exit(1);
	printf("Child: I'm going to connect STDIN to fd from a file\n"); // to pipe write
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
	r_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (r_fd == -1)
		exit(1);
	printf("Child: Eventually I'll read from STDIN(file) and write to STDOUT(pipe)\n");
	command();
}

void	parent_proc(int pipe[2], pid_t pid)
{
	int	fd;
	int	r_fd;
	int	w_fd;

	printf("Parent: I'm going to close fd for Write\n");
	close(pipe[P_WRITE]);
	printf("Parent: I'm going to connect STDIN to fd for Read\n");
	r_fd = dup2(pipe[P_READ], STDIN_FILENO);
	close(pipe[P_READ]);
	if (r_fd == -1)
		exit(1);
	printf("Parent: I'm going to connect STDOUT to fd from a file\n");
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, STDOUT_FILENO);
	printf("Parent: Eventually I'll read from STDIN(pipe) and write to STDOUT(file)\n");
	close(fd);
	if (w_fd == -1)
		exit(1);
	if (waitpid(pid, NULL, 0) == -1)
		exit(1);
	command();
}

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (1);
	printf("Parent: fd for Read is %d, fd for Write %d\n", fd[P_READ], fd[P_WRITE]);
	pid = fork();
	if (pid == -1)
	{
		close(fd[P_READ]);
		close(fd[P_WRITE]);
		return (1);
	}
	else if (pid == 0)
		child_proc(fd);
	else
		parent_proc(fd, pid);
	return (0);
}
