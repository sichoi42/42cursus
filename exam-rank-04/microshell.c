#include "microshell.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define PIPE_IN 1
#define PIPE_OUT 0

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_SEMI 2

typedef struct s_lst
{
	char			**args;
	int				argc;
	int				pipes[2];
	int				type;
	struct s_lst	*next;
	struct s_lst	*prev;

}	t_lst;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	print_error(char *s)
{
	write(STDERR, s, ft_strlen(s));
	return (1);
}

void	exit_fatal(void)
{
	print_error("error: fatal\n");
	exit(1);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	dst = malloc(ft_strlen(src) + 1);
	if (dst == NULL)
		exit_fatal();
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	return (dst);
}

void	add_arg(t_lst *cmd, char *arg)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (cmd->argc + 2));
	if (tmp == NULL)
		exit_fatal();
	i = 0;
	while (i < cmd->argc)
	{
		tmp[i] = cmd->args[i];
		++i;
	}
	if (cmd->argc > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->args[i] = ft_strdup(arg);
	cmd->args[++i] = 0;
	++(cmd->argc);
}

void	add_list(t_lst **cmds, char *arg)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new == NULL)
		exit_fatal();
	new->argc = 0;
	new->args = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->type = TYPE_END;
	if (*cmds)
	{
		(*cmds)->next = new;
		new->prev = *cmds;
	}
	*cmds = new;
	add_arg(new, arg);
}

void	parsing(t_lst **cmds, char *arg)
{
	int	is_semi;

	is_semi = (strcmp(arg, ";") == 0);
	if ((!is_semi && !*cmds) || (*cmds)->type == TYPE_END)
		add_list(cmds, arg);
	else if (strcmp(arg, "|") == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (is_semi)
		(*cmds)->type = TYPE_SEMI;
	else
		add_arg(*cmds, arg);
}

void	rewind_list(t_lst **cmds)
{
	while (*cmds && (*cmds)->prev)
		*cmds = (*cmds)->prev;
}

int	ft_cd(t_lst *cmd)
{
	int	ret;

	ret = 0;
	if (cmd->argc < 2)
		ret = print_error("error: cd: bad arguments\n");
	else if (chdir(cmd->args[1]) < 0)
	{
		ret = print_error("error: cd: cannot change directory to ");
		print_error(cmd->args[1]);
	}
	return (ret);
}

void	child_proc(t_lst *cmd, char **envp)
{
	int	ret;

	ret = 0;
	if (cmd->type == TYPE_PIPE)
	{
		if (dup2(cmd->pipes[PIPE_IN], STDOUT) < 0)
			exit_fatal();
	}
	if (cmd->prev && cmd->prev->type == TYPE_PIPE)
	{
		if (dup2(cmd->pipes[PIPE_OUT], STDIN) < 0)
			exit_fatal();
	}
	ret = execve(cmd->args[0], cmd->args, envp);
	if (ret < 0)
	{
		print_error("error: cannot execute ");
		print_error(cmd->args[0]);
		print_error("\n");
	}
	exit(ret);
}

int	parent_proc(t_lst *cmd, pid_t pid, int is_pipe_open)
{
	int	ret;
	int	status;

	ret = 0;
	waitpid(pid, &status, 0);
	if (is_pipe_open)
	{
		close(cmd->pipes[PIPE_IN]);
		if (cmd->type == TYPE_END || cmd->type == TYPE_SEMI)
			close(cmd->pipes[PIPE_OUT]);
	}
	if (cmd->prev && cmd->prev->type == TYPE_PIPE)
		close(cmd->pipes[PIPE_OUT]);
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	return (ret);
}

int	execute_cmd(t_lst *cmd, char **envp)
{
	int		ret;
	int		is_pipe_open;
	pid_t	pid;

	is_pipe_open = 0;
	ret = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		is_pipe_open = 1;
		if (pipe(cmd->pipes) < 0)
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
		child_proc(cmd, envp);
	else
		ret = parent_proc(cmd, pid, is_pipe_open);
	return (ret);
}

int	executing(t_lst **cmds, char **envp)
{
	t_lst	*p;
	int		ret;

	rewind_list(cmds);
	p = *cmds;
	ret = 0;
	while (p)
	{
		if (strcmp(p->args[0], "cd") == 0)
			ret = ft_cd(p);
		else
			ret = execute_cmd(p, envp);
		p = p->next;
	}
	return (ret);
}

void	clear_list(t_lst **cmds)
{
	t_lst	*tmp;
	int		i;

	rewind_list(cmds);
	while (*cmds)
	{
		tmp = (*cmds)->next;
		if ((*cmds)->args)
		{
			i = 0;
			while (i < (*cmds)->argc)
			{
				free((*cmds)->args[i]);
				++i;
			}
			free((*cmds)->args[i]);
			free((*cmds)->args);
		}
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_lst	*cmds;
	int		ret;
	int		i;

	cmds = NULL;
	i = 1;
	ret = 0;
	while (i < argc)
	{
		parsing(&cmds, argv[i]);
		++i;
	}
	if (cmds)
		ret = executing(&cmds, envp);
	clear_list(&cmds);
	return (ret);
}
