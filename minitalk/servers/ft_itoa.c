/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:13:23 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/12 20:18:08 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	len_n(int n)
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

char	*tr_str(int n, char *s, int len)
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

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == 0)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
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
