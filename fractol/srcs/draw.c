/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:12:50 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 18:19:49 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	pixel_put_color(t_fractol *f, int x, int y)
{
	int	pixel;

	pixel = f->bits_per_pixel / 8;
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		f->addr[(x * pixel) + (y * f->line_length) + 2] = f->col.red;
		f->addr[(x * pixel) + (y * f->line_length) + 1] = f->col.green;
		f->addr[(x * pixel) + (y * f->line_length)] = f->col.blue;
	}
}

int	put_texture(t_fractol *f)
{
	char	*s;
	int		col;

	if (f->color_flag == 1)
		col = RED;
	else if (f->color_flag == 2)
		col = WHITE;
	else
		col = BLACK;
	s = ft_itoa(f->max_iteration);
	if (s == 0)
		return (-1);
	mlx_string_put(f->mlx, f->mlx_win, 10, 10, col, "iteration: ");
	mlx_string_put(f->mlx, f->mlx_win, 120, 10, col, s);
	free(s);
	return (0);
}

int	ft_draw(t_fractol *f)
{
	int		iter;
	int		x;
	int		y;

	f->factor.re = (f->max.re - f->min.re) / WIDTH;
	f->factor.im = (f->max.im - f->min.im) / HEIGHT;
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			iter = f->func(f, x, y);
			choose_color(iter, f);
			pixel_put_color(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	put_texture(f);
	return (0);
}
