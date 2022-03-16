/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:36:07 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 00:04:59 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	if (src == 0)
		return (0);
	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && dstsize != 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
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

long long	ft_atoi(const char *s)
{
	long long	num;
	long long	sign;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	sign = 1;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	num = 0;
	while (*s - '0' >= 0 && *s - '0' <= 9)
	{
		num *= 10;
		num += *s - '0';
		s++;
	}
	return (num * sign);
}
