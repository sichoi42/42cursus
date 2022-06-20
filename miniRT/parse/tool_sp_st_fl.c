/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_sp_st_fl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:34:08 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:51:13 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

void	pass_space(int fd, char *buf, char *space)
{
	int	size;
	int	i;

	size = ft_read(fd, buf, 1);
	while (size == 1)
	{
		i = -1;
		while (space[++i] != '\0')
		{
			if (*buf == space[i])
			{
				size = ft_read(fd, buf, 1);
				break ;
			}
		}
		if (space[i] == '\0')
			return ;
	}
	if (size == 0)
		*buf = '\0';
}

static void	check_str(char *str, int no_ck)
{
	int	dot;

	if (ft_strcmp(str, "rgb") == 0 || ft_strcmp(str, "bp") == 0 || no_ck == 1)
		return ;
	dot = 0;
	if (*str == '+' || *str == '-' || *str == '.')
		if (*(++str) == '\0' || *str == '.')
			print_error("Wrong input: not correct number\n");
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			++str;
		else if (*str == '.')
		{
			if (dot == 0)
				dot = 1;
			else
				print_error("Wrong input: dot only one\n");
			++str;
		}
		else
			print_error("Wrong input: wrong char\n");
	}
}

char	*read_to_str(int fd, char *buf, int no_ck)
{
	char	*str;
	int		size;
	int		i;
	int		capa;

	pass_space(fd, buf, " ,\t");
	capa = STR_SIZE;
	str = malloc_array(sizeof(char), capa);
	i = 0;
	str[i++] = *buf;
	size = ft_read(fd, buf, 1);
	while (size == 1 && *buf != ' ' && *buf != ',' && *buf != '\n')
	{
		if (i == capa - 1)
		{
			str = ft_realloc(str, capa, capa * 2);
			capa *= 2;
		}
		str[i++] = *buf;
		size = ft_read(fd, buf, 1);
	}
	str[i] = '\0';
	check_str(str, no_ck);
	return (str);
}

double	make_float(int fd, char *buf)
{
	long long	num;
	long long	decimal;
	char		*str;
	double		result;

	str = read_to_str(fd, buf, 0);
	num = stof_front(str);
	decimal = stof_behind(str);
	result = decimal;
	while (result >= 1.0)
		result /= 10.0;
	if (*str == '-')
		result *= -1;
	result += num;
	free(str);
	return (result);
}
