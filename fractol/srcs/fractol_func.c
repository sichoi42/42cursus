/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:08:32 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 20:01:46 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	iterating_mandelbrot(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	z2;
	int			iter_count;

	f->c.re = f->min.re + x * f->factor.re;
	f->c.im = f->min.im + y * f->factor.im;
	iter_count = 0;
	z.re = 0;
	z.im = 0;
	z2 = z;
	while ((z2.re + z2.im) <= 4 && iter_count < f->max_iteration)
	{
		z.im = 2 * z.re * z.im + f->c.im;
		z.re = z2.re - z2.im + f->c.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		iter_count++;
	}
	return (iter_count);
}

int	iterating_julia(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	tmp;
	int			iter_count;

	iter_count = 0;
	z.re = f->min.re + x * f->factor.re;
	z.im = f->min.im + y * f->factor.im;
	while (z.re * z.re + z.im * z.im <= 4 && iter_count < f->max_iteration)
	{
		tmp.re = z.re;
		z.re = z.re * z.re - z.im * z.im + f->c.re;
		z.im = 2 * tmp.re * z.im + f->c.im;
		iter_count++;
	}
	return (iter_count);
}

int	iterating_burning_ship(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	tmp;
	int			iter_count;

	f->c.re = f->min.re + x * f->factor.re;
	f->c.im = f->min.im + y * f->factor.im;
	z.re = 0;
	z.im = 0;
	iter_count = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter_count < f->max_iteration)
	{
		tmp.re = z.re;
		z.re = z.re * z.re - z.im * z.im + f->c.re;
		if (2 * tmp.re * z.im < 0)
			z.im = 2 * tmp.re * z.im * (-1) + f->c.im;
		else
			z.im = 2 * tmp.re * z.im + f->c.im;
		iter_count++;
	}
	return (iter_count);
}
