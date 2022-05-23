/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:34:37 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 12:02:35 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <stdio.h>

static int	len_n(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*tr_str(int n, char *s, int len)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (n > 0)
	{
		s[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	s[len] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		s = ft_strdup("-2147483648");
	else if (n > 0)
	{
		s = malloc(sizeof(char) * len_n(n) + 1);
		s = tr_str(n, s, len_n(n));
	}
	else if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		s[0] = 0 + '0';
		s[1] = 0;
	}
	else
	{
		s = malloc(sizeof(char) * len_n(-n) + 2);
		s[0] = '-';
		tr_str(-n, s + 1, len_n(-n));
	}
	return (s);
}
