/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:14:32 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:14:33 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * 왼쪽이 더 크면 양수
 * 오른쪽이 더 크면 음수
 * 같으면 0
 */

int	ft_strcmp(char *l, char *r)
{
	while (*l != '\0')
	{
		if (*l != *r)
			break ;
		++l;
		++r;
	}
	return (*l - *r);
}

int	ft_strlcmp(char *l, char *r, int len)
{
	int	i;

	i = -1;
	while (*l != '\0' && ++i < len)
	{
		if (*l != *r)
			break ;
		++l;
		++r;
	}
	if (i == len)
		return (OK);
	return (*l - *r);
}
