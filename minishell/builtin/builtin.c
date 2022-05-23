/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:36:55 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 19:43:47 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int	check_echo_option(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		while (arg[++i] == 'n')
			;
		if (arg[i] == '\0')
			return (OK);
	}
	return (1);
}

int	ft_echo(t_oper *o)
{
	int	i;
	int	first;
	int	option;

	option = 0;
	i = 0;
	while (o->opers[++i] != NULL)
		if (check_echo_option(o->opers[i]) != OK)
			break ;
	else if (option == 0)
			option = 1;
	first = 1;
	while (o->opers[i] != NULL)
	{
		if (first++ != 1)
			printf(" ");
		write(STDOUT_FILENO, o->opers[i], ft_strlen(o->opers[i]));
		++i;
	}
	if (option == 0)
		printf("\n");
	return (OK);
}

static int	set_pwd(t_envs *e, char *pwd)
{
	free(e->old_pwd);
	e->old_pwd = e->pwd;
	e->pwd = malloc_array(sizeof(char), ft_strlen(pwd) + 1);
	ft_strcpy(pwd, e->pwd);
	if (search_env(e, "PWD") != -1)
		insert_env(e, "PWD", pwd);
	if (search_env(e, "OLDPWD") != -1)
		insert_env(e, "OLDPWD", e->old_pwd);
	return (OK);
}

int	ft_cd(t_oper *o, t_envs *e)
{
	char	*temp;

	if (o->opers[1] != NULL && *(o->opers[1]) != '\0')
	{
		if (chdir(o->opers[1]) != OK)
		{
			print_error("minishell", "cd", o->opers[1], strerror(errno));
			return (ERROR);
		}
		return (set_pwd(e, o->opers[1]));
	}
	temp = get_env_value(e, "HOME");
	if (temp == NULL)
	{
		print_error("minishell", "cd", "HOME not set", NULL);
		return (ERROR);
	}
	if (chdir(temp) != OK)
	{
		print_error("minishell", "cd", o->opers[1], strerror(errno));
		return (ERROR);
	}
	return (set_pwd(e, temp));
}

int	built_in_check(t_oper *o, t_envs *e, t_ast *node)
{
	int	rtn;

	if (ft_strcmp("export", o->opers[0]) == 0)
		rtn = (ft_export(o, e));
	else if (ft_strcmp("unset", o->opers[0]) == 0)
		rtn = (ft_unset(o, e));
	else if (ft_strcmp("exit", o->opers[0]) == 0)
		rtn = (ft_exit(o, node));
	else
	{
		ft_tolower(&(o->opers[0]));
		if (ft_strcmp("echo", o->opers[0]) == 0)
			rtn = (ft_echo(o));
		else if (ft_strcmp("cd", o->opers[0]) == 0)
			rtn = (ft_cd(o, e));
		else if (ft_strcmp("pwd", o->opers[0]) == 0)
			rtn = (ft_pwd());
		else if (ft_strcmp("env", o->opers[0]) == 0)
			rtn = (ft_env(e));
		else
			rtn = (-1);
	}
	g_exit_code = rtn;
	return (rtn);
}
