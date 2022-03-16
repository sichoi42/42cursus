/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:09:19 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 20:22:32 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_exit(int param)
{
	exit(param);
}

int	key_press(int key, t_fractol *f)
{
	if (key == ESC)
		ft_exit(0);
	else if (key == 18 || key == 19 || key == 20)
		color_channel(key, f);
	else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		move(key, f);
	else if (key == 15)
	{
		setting_default(f);
		mlx_clear_window(f->mlx, f->mlx_win);
		if (ft_draw(f) == -1)
			ft_exit(1);
	}
	return (0);
}

void	color_channel(int key, t_fractol *f)
{
	if (key == 18)
		f->color_flag = 1;
	else if (key == 19)
		f->color_flag = 2;
	else if (key == 20)
		f->color_flag = 3;
	mlx_clear_window(f->mlx, f->mlx_win);
	if (ft_draw(f) == -1)
		ft_exit(1);
}

void	move(int key, t_fractol *f)
{
	if (key == UP)
	{
		f->min.im -= 0.1 * f->zoom;
		f->max.im -= 0.1 * f->zoom;
	}
	if (key == DOWN)
	{
		f->min.im += 0.1 * f->zoom;
		f->max.im += 0.1 * f->zoom;
	}
	if (key == RIGHT)
	{
		f->min.re += 0.1 * f->zoom;
		f->max.re += 0.1 * f->zoom;
	}
	if (key == LEFT)
	{
		f->min.re -= 0.1 * f->zoom;
		f->max.re -= 0.1 * f->zoom;
	}
	mlx_clear_window(f->mlx, f->mlx_win);
	if (ft_draw(f) == -1)
		ft_exit(1);
}
