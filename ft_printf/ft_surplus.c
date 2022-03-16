/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:39:18 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 15:59:07 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_surplus(int d, int len_d, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_d))
	{
		write_n_count(' ', f->width - f->precision, f);
		write_n_count('-', 1, f);
		write_n_count('0', f->precision - len_d, f);
		ft_putnbr(-d, f);
	}
}

void	print_p_surplus(unsigned long long p, int len_p, t_flag *f)
{
	if ((f->width > f->precision) && (f->precision >= len_p))
	{
		write_n_count(' ', f->width - f->precision, f);
		write_count("0x", 2, f);
		write_n_count('0', f->precision - len_p, f);
		ft_putnbr_p(p, f);
	}
}

void	ft_putnbr_p(unsigned long long nb, t_flag *f)
{
	if (nb >= 16)
	{
		ft_putnbr_p(nb / 16, f);
		ft_putnbr_p(nb % 16, f);
	}
	else
	{
		if (nb < 10)
			write_n_count(nb + '0', 1, f);
		else
			write_n_count(nb - 10 + 'a', 1, f);
	}
}

void	ft_putnbr_u(unsigned int nb, t_flag *f)
{
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10, f);
		ft_putnbr_u(nb % 10, f);
	}
	else
		write_n_count(nb + '0', 1, f);
}
