/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:35:07 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 17:53:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

int	token_block(char *line, t_token **token_header, t_envs *e)
{
	char	*s;

	init_token_header(token_header);
	s = tokenizing(line, *token_header, e);
	g_exit_code = 0;
	if (s != PASS)
	{
		g_exit_code = 258;
		print_error("minishell", s, NULL, NULL);
		free_token(*token_header);
		return (WRONG_ACTION);
	}
	return (OK);
}

int	parsing_block(t_ast **tree, t_token *token_header)
{
	char	*s;

	init_tree(tree);
	s = parsing(*tree, token_header);
	if (s != PASS)
	{
		if (ft_strcmp(s, SYNTAX_ERROR) == 0)
			g_exit_code = 258;
		else
			g_exit_code = 1;
		print_error("minishell", s, NULL, NULL);
		free_token(token_header);
		free_tree(*tree);
		return (WRONG_ACTION);
	}
	return (OK);
}

void	readline_check(char **line, t_envs *e)
{
	int	row;
	int	col;

	turn_off_echoctl();
	disable_canonical();
	get_position(&col, &row);
	enable_canonical();
	*line = readline("minishell$ ");
	if (!(*line))
	{
		free_envs(e);
		eof_exit(col, row);
		exit(0);
	}
}

void	put_std_fd_in_root(t_ast *tree)
{
	dup_check(tree->root->std_fd[0], STDIN_FILENO);
	dup_check(tree->root->std_fd[1], STDOUT_FILENO);
	close(tree->root->std_fd[0]);
	close(tree->root->std_fd[1]);
}

void	loop(t_envs *e)
{
	char			*line;
	t_token			*token_header;
	t_ast			*tree;

	while (1)
	{
		readline_check(&line, e);
		if (token_block(line, &token_header, e) == OK)
		{
			if (parsing_block(&tree, token_header) == OK)
			{
				signal(SIGINT, handler_no_redisplay);
				tree_searching(tree, e);
				wait_child(tree->root->pid);
				put_std_fd_in_root(tree);
				free_token(token_header);
				free_tree(tree);
			}
		}
		add_history(line);
		free(line);
		signal(SIGINT, handler);
	}
}
