/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:07:18 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 15:55:47 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *s, int *idx)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		num *= 10;
		num += s[i] - '0';
		i++;
	}
	(*idx) += i - 1;
	return (num);
}

void	ft_putnbr_rec(int nb, t_flag *f)
{
	if (f->precision == 0 && f->dot == T && nb == 0)
		return ;
	else
		ft_putnbr(nb, f);
}

void	ft_putnbr(int nb, t_flag *f)
{
	if (nb == -2147483648)
	{
		write_n_count('-', 1, f);
		write_n_count('2', 1, f);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write_n_count('-', 1, f);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, f);
		ft_putnbr(nb % 10, f);
	}
	else
		write_n_count(nb + '0', 1, f);
}

void	ft_putnbr_hex_rec(unsigned int nb, t_flag *f, char specifier)
{
	if (f->precision == 0 && f->dot == T && nb == 0)
		return ;
	else
		ft_putnbr_hex(nb, f, specifier);
}

void	ft_putnbr_hex(unsigned int nb, t_flag *f, char specifier)
{
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16, f, specifier);
		ft_putnbr_hex(nb % 16, f, specifier);
	}
	else
	{
		if (nb < 10)
			write_n_count(nb + '0', 1, f);
		else
		{
			if (specifier == 'X')
				write_n_count(nb - 10 + 'A', 1, f);
			else
				write_n_count(nb - 10 + 'a', 1, f);
		}
	}
}
