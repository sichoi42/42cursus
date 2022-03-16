/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:04:44 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:07:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(t_flag *f, unsigned int u, char specifier)
{
	int		len_hex;

	len_hex = get_len_hex(u);
	if (f->dot == T && f->precision >= 0)
	{
		f->zero = F;
		if (f->precision == 0 && u == 0)
			len_hex = 0;
	}
	if (f->minus == T)
		case_left_sort_hex(u, len_hex, f, specifier);
	else
		case_right_sort_hex(u, len_hex, f, specifier);
}

int	get_len_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	case_right_sort_hex(int u, int len_hex, t_flag *f, char specifier)
{
	if ((f->width > f->precision) && (f->precision >= len_hex))
	{
		write_n_count(' ', f->width - f->precision, f);
		write_n_count('0', f->precision - len_hex, f);
	}
	else if ((f->width > len_hex) && (len_hex > f->precision))
	{
		if (f->zero == T)
			write_n_count('0', f->width - len_hex, f);
		else
			write_n_count(' ', f->width - len_hex, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_hex)
		&& (f->precision != 0 || f->width != 0))
		write_n_count('0', f->precision - len_hex, f);
	ft_putnbr_hex_rec(u, f, specifier);
}

void	case_left_sort_hex(int u, int len_hex, t_flag *f, char specifier)
{
	if ((f->width > f->precision) && (f->precision >= len_hex))
	{
		write_n_count('0', f->precision - len_hex, f);
		ft_putnbr_hex_rec(u, f, specifier);
		write_n_count(' ', f->width - f->precision, f);
	}
	else if ((f->width > len_hex) && (len_hex > f->precision))
	{
		ft_putnbr_hex_rec(u, f, specifier);
		write_n_count(' ', f->width - len_hex, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_hex)
		&& (f->precision != 0 || f->width != 0))
	{
		write_n_count('0', f->precision - len_hex, f);
		ft_putnbr_hex_rec(u, f, specifier);
	}
	else
		ft_putnbr_hex_rec(u, f, specifier);
}
