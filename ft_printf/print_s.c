/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:37:02 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/15 16:57:59 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_flag *f, char *s)
{
	char	nul[7];

	nul[0] = '(';
	nul[1] = 'n';
	nul[2] = 'u';
	nul[3] = 'l';
	nul[4] = 'l';
	nul[5] = ')';
	nul[6] = 0;
	if (s == 0)
	{
		if (f->minus == T)
			left_sort_s(f, nul);
		else
			right_sort_s(f, nul);
		return ;
	}
	if (f->minus == T)
		left_sort_s(f, s);
	else
		right_sort_s(f, s);
}

void	right_sort_s(t_flag *f, char *s)
{
	int	len;

	len = 0;
	if (f->dot == T && ft_strlen(s) > f->precision && f->precision >= 0)
		len = f->precision;
	else
		len = ft_strlen(s);
	if (f->zero == T)
	{
		if (f->width > len)
			write_n_count('0', f->width - len, f);
	}
	else
	{
		if (f->width > len)
			write_n_count(' ', f->width - len, f);
	}
	write_count(s, len, f);
}

void	left_sort_s(t_flag *f, char *s)
{
	int	len;

	len = 0;
	if (f->dot == T && ft_strlen(s) > f->precision && f->precision >= 0)
		len = f->precision;
	else
		len = ft_strlen(s);
	write_count(s, len, f);
	if (f->width > len)
		write_n_count(' ', f->width - len, f);
}
