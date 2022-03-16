/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:19:12 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:07:50 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_flag *f, int d)
{
	int		len_d;

	len_d = get_len_int(d);
	if (f->dot == T && f->precision >= 0)
	{
		f->zero = F;
		if (f->precision == 0 && d == 0)
			len_d = 0;
	}
	if (d < 0 && f->precision > 0)
		f->precision++;
	if (f->minus == T)
		case_left_sort_int(d, len_d, f);
	else
		case_right_sort_int(d, len_d, f);
}

void	case_right_sort_int(int d, int len_d, t_flag *f)
{
	if (d < 0)
	{
		case_right_sort_neg_int(d, len_d, f);
		return ;
	}
	if ((f->width > f->precision) && (f->precision >= len_d))
	{
		write_n_count(' ', f->width - f->precision, f);
		write_n_count('0', f->precision - len_d, f);
	}
	else if ((f->width > len_d) && (len_d > f->precision))
	{
		if (f->zero == T)
			write_n_count('0', f->width - len_d, f);
		else
			write_n_count(' ', f->width - len_d, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_d)
		&& (f->precision != 0 || f->width != 0))
		write_n_count('0', f->precision - len_d, f);
	ft_putnbr_rec(d, f);
}

void	case_right_sort_neg_int(int d, int len_d, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_d))
		print_int_surplus(d, len_d, f);
	else if ((f->width > len_d) && (len_d > f->precision))
	{
		if (f->zero == T)
		{
			write_n_count('-', 1, f);
			write_n_count('0', f->width - len_d, f);
			ft_putnbr_rec(-d, f);
		}
		else
		{
			write_n_count(' ', f->width - len_d, f);
			ft_putnbr_rec(d, f);
		}
	}
	else if ((f->precision >= f->width || f->precision >= len_d)
		&& (f->precision != 0 || f->width != 0))
	{
		write_n_count('-', 1, f);
		write_n_count('0', f->precision - len_d, f);
		ft_putnbr_rec(-d, f);
	}
	else
		ft_putnbr_rec(d, f);
}

void	case_left_sort_int(int d, int len_d, t_flag *f)
{
	if (d < 0)
	{
		case_left_sort_neg_int(d, len_d, f);
		return ;
	}
	if ((f->width > f->precision) && (f->precision >= len_d))
	{
		write_n_count('0', f->precision - len_d, f);
		ft_putnbr_rec(d, f);
		write_n_count(' ', f->width - f->precision, f);
	}
	else if ((f->width > len_d) && (len_d > f->precision))
	{
		ft_putnbr_rec(d, f);
		write_n_count(' ', f->width - len_d, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_d)
		&& (f->precision != 0 || f->width != 0))
	{
		write_n_count('0', f->precision - len_d, f);
		ft_putnbr_rec(d, f);
	}
	else
		ft_putnbr_rec(d, f);
}

void	case_left_sort_neg_int(int d, int len_d, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_d))
	{
		write_n_count('-', 1, f);
		write_n_count('0', f->precision - len_d, f);
		ft_putnbr_rec(-d, f);
		write_n_count(' ', f->width - f->precision, f);
	}
	else if ((f->width > len_d) && (len_d > f->precision))
	{
		ft_putnbr_rec(d, f);
		write_n_count(' ', f->width - len_d, f);
	}
	else if ((f->precision >= f->width || f->precision >= len_d)
		&& (f->precision != 0 || f->width != 0))
	{
		write_n_count('-', 1, f);
		write_n_count('0', f->precision - len_d, f);
		ft_putnbr_rec(-d, f);
	}
	else
		ft_putnbr_rec(d, f);
}
