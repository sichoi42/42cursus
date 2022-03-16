/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:04:51 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/07 18:07:15 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_flag *f)
{
	f->minus = F;
	f->zero = F;
	f->star = F;
	f->star_after_dot = F;
	f->dot = F;
	f->s_exist = T;
	f->num = 0;
	f->num_after_dot = 0;
	f->width = 0;
	f->precision = 0;
}

void	find_flag(char flag, t_flag *f)
{
	if (flag == '-')
	{
		if (f->zero == T)
			f->zero = F;
		f->minus = T;
	}
	if (flag == '0')
	{
		if (f->minus == F && f->dot == F)
			f->zero = T;
	}
	if (flag == '.')
		f->dot = T;
}

t_bool	get_width_with_star(const char *s, t_flag *f, va_list *ap)
{
	if (*s == '*' && f->dot == F)
	{
		if (f->num == T)
			return (ERR);
		f->star = T;
		f->width = va_arg(*ap, int);
	}
	if (*s == '*' && f->dot == T)
	{
		if (f->num_after_dot == T)
			return (ERR);
		f->star_after_dot = T;
		f->precision = va_arg(*ap, int);
	}
	if (f->width < 0)
	{
		f->minus = T;
		f->width = ft_abs(f->width);
	}
	return (T);
}

t_bool	get_width(const char *s, int *idx, t_flag *f, va_list *ap)
{
	if (get_width_with_star(s, f, ap) == ERR)
		return (ERR);
	if ((*s >= '1' && *s <= '9') && f->dot == F)
	{
		if (f->star == T)
			return (ERR);
		f->width = ft_atoi(s, idx);
	}
	if ((*s >= '1' && *s <= '9') && f->dot == T)
	{
		if (f->star_after_dot == T)
			return (ERR);
		f->precision = ft_atoi(s, idx);
	}
	return (T);
}

t_bool	find_specifier(char specifier, t_flag *f, va_list *ap)
{
	if (specifier == 'c' || specifier == '%')
		print_c(f, va_arg(*ap, int), specifier);
	else if (specifier == 's')
		print_s(f, va_arg(*ap, char *));
	else if (specifier == 'p')
		print_p(f, va_arg(*ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		print_int(f, va_arg(*ap, int));
	else if (specifier == 'u')
		print_u(f, va_arg(*ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		print_hex(f, va_arg(*ap, unsigned int), specifier);
	else
		return (F);
	return (T);
}
