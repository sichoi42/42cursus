#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define READ 0
#define WRITE 1

int main(int argc, char **argv)
{
	int 	fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
		char buf[BUFSIZ];
		int ret = read(STDIN_FILENO, buf, BUFSIZ);
		buf[ret] = 0;
		printf("%s\n", buf);
		char **cmd = ft_split(buf, ' ');
		cmd[argc - 1] = 0;
		execve("/bin/ls", cmd, NULL);
	}
	pid_t wpid = waitpid(pid, NULL, 0);
	close(fd[READ]);
	for (int i=1;i<=argc;i++)
		dprintf(fd[WRITE], "%s ", argv[i]);
	close(fd[WRITE]);
	// int status;
	// pid_t wpid = waitpid(pid, &status, 0);
	// if (wpid == pid)
	// {
	// 	printf("can reach here?\n");
	// 	if (WIFEXITED(status))
	// 		return WEXITSTATUS(status);
	// }
	// else
	// 	return (-1);
}
