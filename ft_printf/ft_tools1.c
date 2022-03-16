/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:57:03 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:05:30 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int	ft_abs(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

void	write_count(char *s, int n, t_flag *f)
{
	if (n <= 0)
		return ;
	if (n >= ft_strlen(s))
		n = ft_strlen(s);
	write(1, s, n);
	f->print_len += n;
}

void	write_n_count(char c, int n, t_flag *f)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		write(1, &c, 1);
		f->print_len++;
		i++;
	}
}

int	get_len_int(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
