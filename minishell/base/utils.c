/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:15:59 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 01:12:38 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	dst = malloc(ft_strlen(src) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			++i;
		}
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strndup(char *src, int len)
{
	char	*dst;
	int		i;

	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	if (src)
	{
		while (src[i] && i < len)
		{
			dst[i] = src[i];
			++i;
		}
	}
	dst[i] = 0;
	return (dst);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n)
		i++;
	if (i == n)
		return ((int)str1[i - 1] - (int)str2[i - 1]);
	else
		return ((int)str1[i] - (int)str2[i]);
}
