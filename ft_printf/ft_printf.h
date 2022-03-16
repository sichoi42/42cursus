/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:35:42 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/08 16:11:08 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define T 1
# define F 0
# define ERR -1
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
typedef int	t_bool;
typedef struct s_flag
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	star;
	t_bool	star_after_dot;
	t_bool	num;
	t_bool	num_after_dot;
	t_bool	s_exist;
	int		width;
	int		precision;
	int		print_len;
}	t_flag;
/*
**ft_printf.c
*/
int		ft_printf(const char *s, ...);
t_bool	find_percent(const char *s, t_flag *f, va_list	*ap);
int		parsing(const char *s, t_flag *f, va_list *ap);
/*
**ft_printf_utils.c
*/
void	init_struct(t_flag *f);
void	find_flag(char flag, t_flag *f);
t_bool	get_width_with_star(const char *s, t_flag *f, va_list *ap);
t_bool	get_width(const char *s, int *idx, t_flag *f, va_list *ap);
t_bool	find_specifier(char specifier, t_flag *f, va_list *ap);
/*
**print_int.c
*/
void	print_int(t_flag *f, int d);
void	case_right_sort_int(int d, int len_d, t_flag *f);
void	case_right_sort_neg_int(int d, int len_d, t_flag *f);
void	case_left_sort_int(int d, int len_d, t_flag *f);
void	case_left_sort_neg_int(int d, int len_d, t_flag *f);
/*
**print_c.c
*/
void	print_c(t_flag *f, char c, char specifier);
/*
**print_s.c
*/
void	print_s(t_flag *f, char *s);
void	right_sort_s(t_flag *f, char *s);
void	left_sort_s(t_flag *f, char *s);
/*
**print_u.c
*/
void	print_u(t_flag *f, unsigned int u);
int		get_len_u(unsigned int n);
void	case_right_sort_u(unsigned int u, int len_u, t_flag *f);
void	case_left_sort_u(unsigned int u, int len_u, t_flag *f);
void	ft_putnbr_u_rec(unsigned int nb, t_flag *f);
/*
**print_hex.c
*/
void	print_hex(t_flag *f, unsigned int hex, char specifier);
int		get_len_hex(unsigned int n);
void	case_right_sort_hex(int u, int len_hex, t_flag *f, char specifier);
void	case_left_sort_hex(int u, int len_hex, t_flag *f, char specifier);
/*
**print_p.c
*/
void	print_p(t_flag *f, void *ptr);
int		get_len_p(unsigned long long n);
void	case_right_sort_p(unsigned long long p, int len_p, t_flag *f);
void	case_left_sort_p(unsigned long long p, int len_p, t_flag *f);
void	ft_putnbr_p_rec(unsigned long long nb, t_flag *f);
/*
**ft_tools1.c
*/
int		ft_strlen(char *s);
int		ft_abs(int i);
void	write_count(char *s, int n, t_flag *f);
void	write_n_count(char c, int n, t_flag *f);
int		get_len_int(int n);
/*
**ft_tools2.c
*/
int		ft_atoi(const char *s, int *idx);
void	ft_putnbr(int nb, t_flag *f);
void	ft_putnbr_rec(int nb, t_flag *f);
void	ft_putnbr_hex(unsigned int nb, t_flag *f, char specifier);
void	ft_putnbr_hex_rec(unsigned int nb, t_flag *f, char specifier);
/*
**ft_surplus.c
*/
void	print_int_surplus(int d, int len_d, t_flag *f);
void	print_p_surplus(unsigned long long p, int len_p, t_flag *f);
void	ft_putnbr_p(unsigned long long nb, t_flag *f);
void	ft_putnbr_u(unsigned int nb, t_flag *f);

#endif
