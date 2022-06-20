/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:04 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:57:05 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>

static void	check_minus(char *str, size_t *index, int *is_minus)
{
	size_t	temp;

	temp = *index;
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
	if (temp != *index && *str == '.')
		print_error("Wrong input\n");
}

unsigned long long	stof_front(char *str)
{
	size_t				i;
	int					is_minus;
	unsigned long long	num;

	i = 0;
	check_minus(str, &i, &is_minus);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		if (num >= OVER_LONG_NUM)
			print_error("Wrong input\n");
		++i;
	}
	if (is_minus == 1 && num > OVER_LONG_NUM)
		print_error("Wrong input\n");
	else if (is_minus == 1)
		num *= -1;
	return (num);
}

unsigned long long	stof_behind(char *str)
{
	unsigned long long	num;

	num = 0;
	while (*str != '.' && *str != '\0')
		++str;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			if (num >= MAX_PRECISION)
				print_error("So long decimal\n");
			num = (num * 10) + *str - '0';
			++str;
		}
	}
	return (num);
}

int	stoi_rgb(char *str)
{
	int	num;

	if (*str == '+')
		++str;
	num = 0;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			print_error("Wrong input\n");
		num = (num * 10) + *str - '0';
		if (num > 255)
			print_error("Wrong input\n");
		++str;
	}
	return (num);
}

int	ft_stoi(char *str)
{
	long	num;
	int		is_minus;
	size_t	i;

	i = 0;
	check_minus(str, &i, &is_minus);
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			print_error("Wrong input\n");
		num = (num * 10) + str[i] - '0';
		if (num >= OVER_INT_NUM)
			print_error("Wrong input\n");
		++i;
	}
	if (is_minus == 1 && num > OVER_INT_NUM)
		print_error("Wrong input\n");
	if (is_minus == 1)
		num *= -1;
	return (num);
}
