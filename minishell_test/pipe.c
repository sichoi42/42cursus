#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define READ 0
#define WRITE 1

void	command(void)
{
	int		ret;
	char	buf[BUFSIZ];

	ret = read(STDIN_FILENO, buf, BUFSIZ);
	buf[ret] = 0;
	write(STDOUT_FILENO, buf, ft_strlen(buf));
}

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	// printf("read fd: %d\n", fd[READ]);
	// printf("write fd: %d\n", fd[WRITE]);
	pid = fork();
	if (pid == 0)
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
		char buf[BUFSIZ];
		int ret = read(STDIN_FILENO, buf, BUFSIZ);
		buf[ret] = 0;
		printf("command you wrote: %s\n", buf);
		char **cmd = ft_split(buf, ' ');
		cmd[argc - 1] = 0;
		char *s = ft_strjoin("/bin/", cmd[0]);
		execve(s, cmd, NULL);
	}
	close(fd[READ]);
	for (int i=1;i<argc;i++)
	{
		char c = ' ';
		write(fd[WRITE], argv[i], ft_strlen(argv[i]));
		write(fd[WRITE], &c, 1);
	}
	close(fd[WRITE]);
	int status;
	pid_t wpid = waitpid(pid, &status, 0);
	if (wpid == pid)
	{
		printf("can reach here?\n");
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
	}
	else
		return (-1);
}
