/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exit_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:37:03 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 19:43:38 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		print_error("minishell", "pwd", strerror(errno), NULL);
		return (ERROR);
	}
	else
		printf("%s\n", path);
	free(path);
	return (OK);
}

int	ft_exit(t_oper *o, t_ast *node)
{
	unsigned long long	num;

	if (o->opers[1] != NULL)
	{
		num = ft_atoi(o->opers[1]);
		if (node->root->pipe_cnt == -1)
			print_error("exit", NULL, NULL, NULL);
		if (num == OVER_LONG_NUM)
		{
			print_error("minishell", "exit", o->opers[1], NUMERIC_ERROR);
			exit(255);
		}
		if (o->opers[2] != NULL)
		{
			print_error("minishell", "exit", ARG_NUM_ERROR, NULL);
			return (1);
		}
		exit(num % 256);
	}
	if (node->root->pipe_cnt == -1)
		print_error("exit", NULL, NULL, NULL);
	exit(OK);
}

int	ft_env(t_envs *e)
{
	insert_env(e, "_", "/usr/bin/env");
	print_env(e);
	return (OK);
}
