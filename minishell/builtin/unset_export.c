/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:37:22 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 19:43:56 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int	check_key(char *key)
{
	if (*key >= '0' && *key <= '9')
		return (ERROR);
	while (*key != '\0')
	{
		if (*key == '_')
			;
		else if (*key >= 'a' && *key <= 'z')
			;
		else if (*key >= 'A' && *key <= 'Z')
			;
		else if (*key >= '0' && *key <= '9')
			;
		else
			return (ERROR);
		++key;
	}
	return (OK);
}

static int	error_key(char *oper, char *arg)
{
	int		len;
	char	*err_arg;

	len = ft_strlen(arg);
	err_arg = malloc_array(sizeof(char), len + 3);
	err_arg[0] = '`';
	ft_strcat(arg, err_arg);
	ft_strcat("\'", err_arg);
	print_error("minishell", oper, err_arg, NOT_VALID_ERROR);
	return (ERROR);
}

int	ft_unset(t_oper *o, t_envs *e)
{
	int		i;
	int		rtn;

	i = 0;
	rtn = OK;
	while (o->opers[++i] != NULL)
	{
		if (check_key(o->opers[i]) == ERROR)
			rtn = error_key("unset", o->opers[i]);
		else
		{
			delete_env(e, o->opers[i]);
			if (ft_strcmp(o->opers[i], "PWD") == 0)
				e->pwd[0] = '\0';
		}
	}
	return (rtn);
}

static void	make_key_value(char *arg, char **key, char **value)
{
	int	i;
	int	k_len;
	int	v_len;

	k_len = ft_strlen_c(arg, '=');
	*key = malloc_array(sizeof(char), k_len + 1);
	ft_strlcpy(arg, *key, k_len);
	i = -1;
	while (arg[++i] != '\0')
		if (arg[i] == '=')
			break ;
	if (arg[i] != '\0')
	{
		v_len = ft_strlen(arg + k_len + 1);
		*value = malloc_array(sizeof(char), v_len + 1);
		ft_strcpy(arg + k_len + 1, *value);
		return ;
	}
	v_len = -1;
	*value = NULL;
}

int	ft_export(t_oper *o, t_envs *e)
{
	int		i;
	int		rtn;
	char	*key;
	char	*value;

	rtn = OK;
	i = 0;
	key = NULL;
	value = NULL;
	while (o->opers[++i] != NULL)
	{
		make_key_value(o->opers[i], &key, &value);
		if (check_key(key) == ERROR)
			rtn = error_key("export", o->opers[i]);
		else
			insert_env(e, key, value);
	}
	if (i == 1)
		print_export(e);
	free(key);
	free(value);
	return (rtn);
}
