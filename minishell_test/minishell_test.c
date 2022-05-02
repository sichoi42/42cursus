#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>
#include <termios.h>
#include "libft.h"

#define READ 0
#define WRITE 1

void	handler(int signum)
{
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

int	get_argc(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		++i;
	return (i);
}

void	child_proc(int *fd)
{
	char	buf[BUFSIZ];
	char	**cmd;
	int		argc;
	char	*s;
	int		ret;

	close(fd[WRITE]);
	dup2(fd[READ], STDIN_FILENO);
	close(fd[READ]);
	ret = read(STDIN_FILENO, buf, BUFSIZ);
	buf[ret] = 0;
	// printf("command to child: %s\n", buf);
	cmd = ft_split(buf, ' ');
	argc = get_argc(cmd);
	cmd[argc] = 0;
	s = ft_strjoin("/bin/", cmd[0]);
	execve(s, cmd, NULL);
	free(s);
	exit(0);
}

int	parent_proc(int *fd, char *line, pid_t pid)
{
	char	**cmd;
	int		argc;

	close(fd[READ]);
	cmd = ft_split(line, ' ');
	argc = get_argc(cmd);
	printf("command from parent: ");
	for (int i=0;i<argc;i++)
	{
		char c = ' ';
		write(fd[WRITE], cmd[i], ft_strlen(cmd[i]));
		write(fd[WRITE], &c, 1);
		printf("%s ", cmd[i]);
	}
	printf("\n");
	close(fd[WRITE]);
	// int status;
	waitpid(pid, NULL, 0);
	// pid_t wpid = waitpid(pid, &status, 0);
	// if (wpid == pid)
	// {
	// 	printf("can reach here?\n");
	// 	if (WIFEXITED(status))
	// 		return WEXITSTATUS(status);
	// }
	// else
	// 	return (-1);
	return (0);
}

int	parsing(char *line)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	// printf("read fd: %d\n", fd[READ]);
	// printf("write fd: %d\n", fd[WRITE]);
	pid = fork();
	if (pid == 0)
		child_proc(fd);
	if (parent_proc(fd, line, pid) == -1)
		return (1);
	return (0);
}

int	main(void)
{
	char	*line;
	struct	termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	while (true)
	{
		line = readline("minishell> ");
		// printf("command you write: %s\n", line);
		if (line)
		{
			parsing(line);
			add_history(line);
			free(line);
			line = NULL;
		}
		else
		{
			// printf("|%s|\n", line);
			printf("\033[1A");
			printf("\033[11C");
			printf("exit\n");
			return (1);
		}
	}
	return (0);
}
