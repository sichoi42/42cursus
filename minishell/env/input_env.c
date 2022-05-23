/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:44:23 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:44:27 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int	envs_alloc(void **ptr, int size, int i, int max)
{
	if (i == max)
		return (OK);
	ptr[i] = malloc_array(size, 1);
	envs_alloc(ptr, size, i + 1, max);
	return (OK);
}

static int	envs_element_alloc(t_envs *e, int i, int max)
{
	if (i == max)
		return (OK);
	e->envs[i]->k_len = ft_strlen_c(e->env[i], '=');
	e->envs[i]->v_len = ft_strlen(e->env[i] + e->envs[i]->k_len + 1);
	e->envs[i]->key = malloc_array(sizeof(char), e->envs[i]->k_len + 1);
	e->envs[i]->value = malloc_array(sizeof(char), e->envs[i]->v_len + 1);
	if (ft_strcmp(e->envs[i]->key, "OLDPWD") == 0)
	{
		free(e->envs[i]->value);
		e->envs[i]->v_len = -1;
	}
	envs_element_alloc(e, i + 1, max);
	return (OK);
}

static void	init_envs(t_envs *e)
{
	int	i;

	i = -1;
	while (++i < e->size)
	{
		ft_strlcpy(e->env[i], e->envs[i]->key, e->envs[i]->k_len);
		set_env_lr(e, e->envs[i]->key, i);
		if (e->envs[i]->v_len != -1)
			ft_strlcpy(e->env[i] + e->envs[i]->k_len + 1,
				e->envs[i]->value, e->envs[i]->v_len);
	}
}

static void	ft_envcpy(t_envs *e, char *env[])
{
	int	i;
	int	len;

	e->env = malloc_array(sizeof(char *), (e->size + 1));
	e->env[e->size] = NULL;
	i = -1;
	while (env[++i] != NULL)
	{
		len = ft_strlen(env[i]);
		e->env[i] = malloc_array(sizeof(char), len + 1);
		ft_strcpy(env[i], e->env[i]);
	}
}

int	input_env(t_envs *e, char *env[])
{
	e->size = -1;
	while (env[++(e->size)] != NULL)
		;
	ft_envcpy(e, env);
	e->capa = SIZE;
	while (e->capa <= e->size)
		e->capa *= 2;
	e->envs = malloc(sizeof(t_env *) * e->capa);
	if (e->envs == NULL)
		return (1);
	if (envs_alloc((void **)e->envs, sizeof(t_env), 0, e->size) == 1)
		return (1);
	if (envs_element_alloc(e, 0, e->size) == 1)
		return (1);
	init_envs(e);
	e->old_pwd = NULL;
	e->pwd = getcwd(NULL, 0);
	if (e->pwd == NULL)
	{
		print_error("minishell", strerror(errno), NULL, NULL);
		return (1);
	}
	return (0);
}
