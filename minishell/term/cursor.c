/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:36:50 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 00:54:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <term.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#define CURPOS "\033[6n"

int	ft_sichoi_atoi(const char *str)
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
	num = 0;
	while (*str - '0' >= 0 && *str - '0' <= 9)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * sign);
}

void	get_position(int *col, int *row)
{
	int		i;
	int		ret;
	char	buf[1024];

	write(STDOUT_FILENO, CURPOS, ft_strlen(CURPOS));
	ret = read(STDIN_FILENO, buf, 1024);
	buf[ret] = 0;
	i = 0;
	while (!is_digit(buf[i]))
		++i;
	*row = (int)ft_sichoi_atoi(&buf[i]) - 1;
	while (is_digit(buf[i]))
		++i;
	while (!is_digit(buf[i]))
		++i;
	*col = (int)ft_sichoi_atoi(&buf[i]) - 1;
}

int	ft_putchar(int c)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (0);
	return (1);
}

void	init_query(const char **cm)
{
	tgetent(NULL, "xterm");
	*cm = tgetstr("cm", NULL);
}

void	move_cursor(int col, int row)
{
	const char		*cm;
	struct winsize	size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == -1)
		return ;
	init_query(&cm);
	if (row == size.ws_row - 1)
		--row;
	tputs(tgoto(cm, col % size.ws_col, row), 2, ft_putchar);
}
