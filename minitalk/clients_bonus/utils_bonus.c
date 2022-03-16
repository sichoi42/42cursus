/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:40:07 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/13 15:46:22 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(const char *s)
{
	int	i;

	i = ft_strlen(s);
	write(1, s, i);
}

int	ft_atoi(const char *s)
{
	int	num;
	int	sign;

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
