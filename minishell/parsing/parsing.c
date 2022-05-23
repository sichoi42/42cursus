/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:59:08 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 01:07:45 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

void	heredoc_loop(char *limit, int fd)
{
	int		col;
	int		row;
	char	*line;

	while (1)
	{
		disable_canonical();
		get_position(&col, &row);
		enable_canonical();
		line = readline("> ");
		if (!line)
			move_cursor(col + 2, row);
		if (!line || ft_strcmp(line, limit) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = NULL;
	}
}

char	*heredoc_input(char *limit)
{
	char		*s;
	char		*file_name;
	int			fd;
	static int	cnt;
	int			temp_stdin;

	s = ft_itoa(cnt);
	if (s == 0)
		exit(1);
	file_name = ft_strjoin(ft_strdup(TEMP_FILE), s);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		return (NULL);
	temp_stdin = dup(STDIN_FILENO);
	signal(SIGINT, handler_here_doc);
	heredoc_loop(limit, fd);
	close(fd);
	++cnt;
	dup_check(temp_stdin, STDIN_FILENO);
	signal(SIGINT, handler_no_redisplay);
	return (file_name);
}

char	*parsing(t_ast *tree, t_token *token_header)
{
	t_token	*p;

	p = token_header->next;
	if (p && p->type & PIPE)
		return (SYNTAX_ERROR);
	while (p)
	{
		if (p->next == NULL && p->type & PIPE)
			return (SYNTAX_ERROR);
		if (p->token & T_RE_HEREDOC)
		{
			p->file_name = heredoc_input(p->s);
			if (p->file_name == NULL)
				return (strerror(errno));
		}
		syntax_pipe(tree, p, tree->root);
		p = p->next;
	}
	return (PASS);
}

void	execute_bundle(t_ast *node, t_envs *e)
{
	t_token	*t;

	if (node->tree_type == TREE_BUNDLE)
	{
		if (node->root->pipe_cnt != -1)
			--(node->root->pipe_cnt);
		init_pipe(node->root->pipe_fd);
		dup_check(node->root->std_fd[1], STDOUT_FILENO);
		if (node->root->pipe_cnt > 0)
			make_pipe(node->root->pipe_fd);
	}
	if (node->token != NULL)
	{
		t = node->token;
		if (node->tree_type == TREE_CMD)
		{
			turn_on_echoctl();
			signal(SIGQUIT, handler);
			exe_command(node, e);
			signal(SIGQUIT, SIG_IGN);
		}
		else if (t->type == REDIRECT)
			red_open_file(t, t->s);
	}
}

// preorder로 트리를 탐색.
void	tree_searching(t_ast *node, t_envs *e)
{
	execute_bundle(node, e);
	if (node->left != NULL)
		tree_searching(node->left, e);
	if (node->right != NULL)
		tree_searching(node->right, e);
}
