/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:13:31 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:17:59 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>

static int	ft_isspace(int c)
{
	if ((c >= 0x09 && c <= 0x0d) || c == ' ')
		return (1);
	else
		return (0);
}

static void	check_minus(const char *str, size_t *index, int *is_minus)
{
	if (str[*index] == '-')
	{
		++(*index);
		*is_minus = 1;
	}
	else
	{
		if (str[*index] == '+')
			++(*index);
		*is_minus = 0;
	}
}

unsigned long long	ft_atoi(const char *str)
{
	size_t				i;
	int					is_minus;
	unsigned long long	num;

	i = 0;
	while (ft_isspace(str[i]) != 0)
		++i;
	check_minus(str, &i, &is_minus);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i++] - '0';
		if (num >= OVER_LONG_NUM)
			return (OVER_LONG_NUM);
	}
	if (is_minus == 1 && num > OVER_LONG_NUM)
		return (OVER_LONG_NUM);
	else if (is_minus == 1)
		num *= -1;
	while (ft_isspace(str[i]) != 0)
		++i;
	if (str[i] != '\0')
		return (OVER_LONG_NUM);
	return (num);
}
