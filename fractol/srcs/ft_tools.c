/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:27:07 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/22 19:13:52 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
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

double	after_dot(const char *s, double lf)
{
	int		tmp;
	int		level;

	level = 0;
	tmp = 0;
	while (*s)
	{
		tmp *= 10;
		tmp += *s - '0';
		level++;
		s++;
	}
	return (lf += (double)tmp * pow(0.1, level));
}

double	string_to_double(const char *s)
{
	int		sign;
	double	lf;

	lf = 0;
	sign = 1;
	while (*s)
	{
		if (*s == '.')
		{
			s++;
			break ;
		}
		if (*s == '-')
			sign = -1;
		else
		{
			lf *= 10;
			lf += *s - '0';
		}
		s++;
	}
	return (lf = sign * after_dot(s, lf));
}
