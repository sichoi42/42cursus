/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_make_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:00:11 by swi               #+#    #+#             */
/*   Updated: 2022/05/21 01:07:49 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

static char	*make_oper_path(char *oper_path, char *path, char *oper)
{
	char	*temp;

	temp = oper_path;
	while (*path != '\0')
		*(temp++) = *(path++);
	*(temp++) = '/';
	while (*oper != '\0')
		*(temp++) = *(oper++);
	*(temp) = '\0';
	return (oper_path);
}

static int	check_right_path(char **o_path, char **paths, char *oper)
{
	struct stat		s;
	int				i;
	int				rtn;
	unsigned char	exit_code;

	exit_code = 0;
	i = -1;
	while (1)
	{
		if (paths[++i] != NULL)
			*o_path = make_oper_path(*o_path, paths[i], oper);
		else
			ft_strcpy(oper, *o_path);
		rtn = stat(*o_path, &s);
		if (rtn != -1 && s.st_mode & S_IXUSR)
			return (OK);
		else if (!(s.st_mode & S_IXUSR))
			exit_code = 126;
		else
			if (exit_code != 126)
				exit_code = 127;
		if (paths[i] == NULL)
			break ;
	}
	return (exit_code);
}

char	*make_oper(char **opers, int max_path, char **paths)
{
	char		*oper_path;
	int			max_oper;

	max_oper = ft_strlen(opers[0]);
	oper_path = malloc_array(sizeof(char), max_path + max_oper + 1);
	if (check_right_path(&oper_path, paths, opers[0]) != OK)
	{
		free(oper_path);
		oper_path = NULL;
	}
	return (oper_path);
}

void	exe_oper(t_oper *o, t_ast *node, t_envs *e)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (node->root->pipe_cnt > 0)
			close_pipe(node->root->pipe_fd);
		if (built_in_check(o, e, node) == -1)
		{
			execve(o->oper_path, o->opers, e->env);
			print_error("minishell", o->opers[0], COMMAND_ERROR, NULL);
			exit(1);
		}
		exit(g_exit_code);
	}
	else if (pid == -1)
		exit(1);
	else
		node->root->pid = pid;
	if (node->root->pipe_cnt > 0)
		dup_check(node->root->pipe_fd[0], STDIN_FILENO);
	else if (node->root->pipe_cnt == 0)
		close(STDIN_FILENO);
	if (node->root->pipe_cnt > 0)
		close_pipe(node->root->pipe_fd);
}

void	exe_command(t_ast *node, t_envs *e)
{
	t_oper	o;
	t_paths	p;
	t_token	*t;
	int		i;

	o.opers = malloc_array(sizeof(char *), node->argc + 1);
	o.opers[node->argc] = NULL;
	i = -1;
	t = node->token;
	while (t)
	{
		o.opers[++i] = malloc_array(sizeof(char), ft_strlen(t->s) + 1);
		ft_strcpy(t->s, o.opers[i]);
		t = t->next;
	}
	find_path(&(p.paths), &(p.max_len), e);
	o.oper_path = make_oper(o.opers, p.max_len, p.paths);
	if (node->root->pipe_cnt <= -1 && built_in_check(&o, e, node) == -1)
		exe_oper(&o, node, e);
	else if (node->root->pipe_cnt >= 0)
		exe_oper(&o, node, e);
	free(o.oper_path);
	free_double_char(o.opers);
	free_double_char(p.paths);
}
