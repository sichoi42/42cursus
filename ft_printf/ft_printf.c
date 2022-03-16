/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:35:40 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:04:51 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_flag	*f;
	int		result;

	f = malloc(sizeof(t_flag));
	if (f == 0)
		return (-1);
	f->print_len = 0;
	if (s)
	{
		va_start(ap, s);
		if (find_percent(s, f, &ap) == ERR)
			return (ERR);
		va_end(ap);
	}
	result = f->print_len;
	free(f);
	return (result);
}

t_bool	find_percent(const char *s, t_flag *f, va_list *ap)
{
	int	i;

	i = 0;
	while (*s)
	{
		init_struct(f);
		if (*s == '%' && *(s + 1))
		{
			i = parsing(s + 1, f, ap);
			if (i == ERR)
				return (ERR);
			s += i;
		}
		else
		{
			write_n_count(*s, 1, f);
			s++;
		}
	}
	return (T);
}

int	parsing(const char *s, t_flag *f, va_list *ap)
{
	int	i;

	i = 0;
	if (s[i] == '%')
	{
		write_n_count(*s, 1, f);
		return (2);
	}
	while (s[i])
	{
		find_flag(*(s + i), f);
		if (get_width(s + i, &i, f, ap) == ERR)
			return (ERR);
		f->s_exist = find_specifier(*(s + i), f, ap);
		i++;
		if (f->s_exist == T)
		{
			i++;
			break ;
		}
	}
	if (f->s_exist == F)
		return (ERR);
	return (i);
}
