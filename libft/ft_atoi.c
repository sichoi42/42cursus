/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:40:07 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 15:54:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	over_long_long(const char *str, int sign)
{
	int			i;

	i = 0;
	while (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		i++;
	if (i >= 20 && sign == -1)
		return (0);
	else if (i >= 20 && sign == 1)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			num;
	int			sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	if (over_long_long(str, sign) == 0)
		return (0);
	else if (over_long_long(str, sign) == -1)
		return (-1);
	num = 0;
	while (*str - '0' >= 0 && *str - '0' <= 9)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * sign);
}
