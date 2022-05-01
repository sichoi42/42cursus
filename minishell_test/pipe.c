#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int	pipes[2];

void	parent_proc()
{
	char	*buf;
	char	*data;
	ssize_t	s;
	size_t	len;
	ssize_t	sent;

	len = 0;
	sent = 0;
	buf = 0;
	close(pipes[0]);
	while (1)
	{
		s = getline(&buf, &len, stdin);
		if (s == -1)
			break ;
		buf[s - 1] = 0;
		data = buf;
		while (sent < s)
			sent += write(pipes[1], buf + sent, s - sent);
		free(buf);
		buf = 0;
		len = 0;
	}
	close(pipes[1]);
}

void	child_proc()
{
	char	buf[32];
	ssize_t	s;

	close(pipes[1]);
	while ((s = read(pipes[0], buf, 31)) > 0)
	{
		buf[s + 1] = 0;
		printf(">%s\n", buf);
	}
	exit(0);
}

int	main(void)
{
	pid_t	child_pid;
	int		exit_code;

	if (pipe(pipes) != 0)
	{
		perror("Error");
		exit(1);
	}
	printf("%d %d\n", pipes[0], pipes[1]);
	child_pid = fork();
	if (child_pid == 0)
		child_proc();
	else
		parent_proc();
	wait(&exit_code);
	return (0);
}
