/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:25:04 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:25:05 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

void	free_envs(t_envs *e)
{
	int	i;

	i = -1;
	while (++i < e->size)
	{
		free(e->envs[i]->key);
		free(e->envs[i]->value);
		free(e->envs[i]);
		free(e->env[i]);
	}
	free(e->envs);
	free(e->env);
	free(e->pwd);
	free(e->old_pwd);
}

void	free_double_char(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		++i;
	}
	free(dptr);
}
