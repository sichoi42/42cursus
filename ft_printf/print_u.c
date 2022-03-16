/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:41:53 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:10:48 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(t_flag *f, unsigned int u)
{
	int		len_u;

	len_u = get_len_u(u);
	if (f->dot == T && f->precision >= 0)
	{
		f->zero = F;
		if (f->precision == 0 && u == 0)
			len_u = 0;
	}
	if (f->minus == T)
		case_left_sort_u(u, len_u, f);
	else
		case_right_sort_u(u, len_u, f);
}

int	get_len_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	case_right_sort_u(unsigned int u, int len_u, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_u))
	{
		write_n_count(' ', f->width - f->precision, f);
		write_n_count('0', f->precision - len_u, f);
	}
	else if ((f->width > len_u) && (len_u > f->precision))
	{
		if (f->zero == T)
			write_n_count('0', f->width - len_u, f);
		else
			write_n_count(' ', f->width - len_u, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_u)
		&& (f->precision != 0 || f->width != 0))
		write_n_count('0', f->precision - len_u, f);
	ft_putnbr_u_rec(u, f);
}

void	case_left_sort_u(unsigned int u, int len_u, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_u))
	{
		write_n_count('0', f->precision - len_u, f);
		ft_putnbr_u_rec(u, f);
		write_n_count(' ', f->width - f->precision, f);
	}
	else if ((f->width > len_u) && (len_u > f->precision))
	{
		ft_putnbr_u_rec(u, f);
		write_n_count(' ', f->width - len_u, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_u)
		&& (f->precision != 0 || f->width != 0))
	{
		write_n_count('0', f->precision - len_u, f);
		ft_putnbr_u_rec(u, f);
	}
	else
		ft_putnbr_u_rec(u, f);
}

void	ft_putnbr_u_rec(unsigned int nb, t_flag *f)
{
	if (f->precision == 0 && f->dot == T && nb == 0)
		return ;
	else
		ft_putnbr_u(nb, f);
}
