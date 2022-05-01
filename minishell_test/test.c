#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}
// TODO:
// need to termios func for ctrl-c, d

int	main(void)
{
	char	*line;
	pid_t	pid;
	int		fd[2];

	signal(SIGINT, handler);
	while (1)
	{
		line = readline("minishell> ");
		if (strcmp(line, "ls") == 0)
		{
			if (pipe(fd) == -1)
				return (1);
			pid = fork();
			if (pid < 0)
				return (1);
			else if (pid == 0)
			{
				execv("bin/ls", NULL);
				return (0);
			}
		}
	}
	return (0);
}
