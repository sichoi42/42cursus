/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:27:39 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:09:18 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_flag *f, void *ptr)
{
	unsigned long long	p;
	int					len_p;

	p = (unsigned long long)ptr;
	len_p = 2 + get_len_p(p);
	if (f->dot == T && f->precision >= 0)
	{
		f->zero = F;
		if (f->precision == 0 && p == 0)
			len_p = 2;
	}
	if (f->minus == T)
	{
		write_count("0x", 2, f);
		case_left_sort_p(p, len_p, f);
	}
	else
	{
		if (f->precision > 0)
			f->precision += 2;
		else if (f->precision <= 0 && len_p == 3 && f->dot == T)
			len_p = 2;
		case_right_sort_p(p, len_p, f);
	}
}

int	get_len_p(unsigned long long n)
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

void	case_right_sort_p(unsigned long long p, int len_p, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_p))
		print_p_surplus(p, len_p, f);
	else if ((f->width > len_p) && (len_p > f->precision))
	{
		if (f->zero == T)
		{
			write_count("0x", 2, f);
			write_n_count('0', f->width - len_p, f);
		}
		else
		{
			write_n_count(' ', f->width - len_p, f);
			write_count("0x", 2, f);
		}
	}
	else if ((f->precision >= f->width || f->precision >= len_p)
		&& (f->precision != 0 || f->width != 0))
	{
		write_count("0x", 2, f);
		write_n_count('0', f->precision - len_p, f);
	}
	else
		write_count("0x", 2, f);
	ft_putnbr_p_rec(p, f);
}

void	case_left_sort_p(unsigned long long p, int len_p, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_p))
	{
		write_n_count('0', f->precision - len_p, f);
		ft_putnbr_p_rec(p, f);
		write_n_count(' ', f->width - f->precision, f);
	}
	else if ((f->width > len_p) && (len_p > f->precision))
	{
		ft_putnbr_p_rec(p, f);
		write_n_count(' ', f->width - len_p, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_p)
		&& (f->precision != 0 || f->width != 0))
	{
		write_n_count('0', f->precision - len_p, f);
		ft_putnbr_p_rec(p, f);
	}
	else
		ft_putnbr_p_rec(p, f);
}

void	ft_putnbr_p_rec(unsigned long long nb, t_flag *f)
{
	if (f->precision == 0 && f->dot == T && nb == 0)
		return ;
	else
		ft_putnbr_p(nb, f);
}
