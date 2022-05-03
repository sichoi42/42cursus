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

enum Token
{
	PIPE = '|',
	QUOTE = '\'',
	DQUOTE = '\"',
	GREATER = '>',
	LOWER = '<',
	SPACE = ' ',
	BACKSLSH = '\\',
	SEMI_COL = ';',
};
typedef struct	s_token
{
	char			*s;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

void	handler(int signum)
{
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

// void	tokenizing(char *line)
// {
// 	char	**cmd = ft_split()
// }

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
			tokenizing(line);
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
