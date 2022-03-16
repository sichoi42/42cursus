/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:50:11 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:10:15 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_flag *f, char c, char specifier)
{
	if (f->minus == T)
	{
		if (specifier == '%')
			write_n_count('%', 1, f);
		else
			write_n_count(c, 1, f);
		write_n_count(' ', f->width - 1, f);
	}
	else
	{
		if (f->zero == T)
			write_n_count('0', f->width - 1, f);
		else
			write_n_count(' ', f->width - 1, f);
		if (specifier == '%')
			write_n_count('%', 1, f);
		else
			write_n_count(c, 1, f);
	}
}
