/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:14:58 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:14:59 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlcpy(char *src, char *target, int len)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		target[i] = src[i];
		++i;
	}
	target[i] = '\0';
	return (i);
}

int	ft_strcpy(char *src, char *target)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		target[i] = src[i];
		++i;
	}
	target[i] = '\0';
	return (i);
}
