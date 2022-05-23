/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:13:29 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 20:15:16 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>

static void	insert_new_env(t_envs *e, char *key, char *value)
{
	int	k_len;
	int	v_len;

	e->envs[e->size] = malloc_array(sizeof(t_env), 1);
	e->envs[e->size]->k_len = ft_strlen(key);
	if (value == NULL)
		e->envs[e->size]->v_len = -1;
	else
		e->envs[e->size]->v_len = ft_strlen(value);
	k_len = e->envs[e->size]->k_len;
	v_len = e->envs[e->size]->v_len;
	e->envs[e->size]->key = malloc_array(sizeof(char), k_len + 1);
	ft_strcpy(key, e->envs[e->size]->key);
	set_env_lr(e, key, e->size);
	if (v_len != -1)
	{
		e->envs[e->size]->value = malloc_array(sizeof(char), v_len + 1);
		ft_strcpy(value, e->envs[e->size]->value);
	}
	else
		e->envs[e->size]->value = NULL;
	e->size += 1;
	e->envs[e->size] = NULL;
}

static void	insert_main_env(t_envs *e, int i)
{
	int	k_len;
	int	v_len;

	if (i == -1)
		i = e->size - 1;
	else
		free(e->env[i]);
	k_len = e->envs[i]->k_len;
	v_len = e->envs[i]->v_len;
	if (v_len != -1)
		e->env[i] = malloc_array(sizeof(char), k_len + v_len + 2);
	else
		e->env[i] = malloc_array(sizeof(char), k_len + 1);
	ft_strcpy(e->envs[i]->key, e->env[i]);
	if (v_len != -1)
	{
		e->env[i][k_len] = '=';
		ft_strcpy(e->envs[i]->value, e->env[i] + k_len + 1);
	}
	else
		e->env[i][k_len] = '\0';
	e->env[e->size] = NULL;
}

static void	change_exist_env(t_envs *e, int i, char *value)
{
	free(e->envs[i]->value);
	e->envs[i]->v_len = ft_strlen(value);
	e->envs[i]->value = malloc_array(sizeof(char), e->envs[i]->v_len + 1);
	ft_strcpy(value, e->envs[i]->value);
}

int	insert_env(t_envs *e, char *key, char *value)
{
	int	index;

	index = search_env(e, key);
	if (index == -1)
	{
		if (e->capa == e->size + 2)
		{
			e->capa *= 2;
			e->envs = (t_env **)ft_realloc(e->envs, sizeof(t_env *) * e->size,
					sizeof(t_env *) * e->capa);
			e->env = (char **)ft_realloc(e->env, sizeof(char *) * e->size,
					sizeof(char *) * e->capa);
		}
		insert_new_env(e, key, value);
	}
	else
	{
		if (value == NULL)
			return (0);
		change_exist_env(e, index, value);
	}
	insert_main_env(e, index);
	return (0);
}
