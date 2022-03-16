/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:13:53 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 20:23:30 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*mouse_point == update f->factor*/
void	reset_min_max(t_complex mouse_point, double zoom_rate, t_fractol *f)
{
	f->min.re = mouse_point.re + (f->min.re - mouse_point.re) * zoom_rate;
	f->max.re = mouse_point.re + (f->max.re - mouse_point.re) * zoom_rate;
	f->min.im = mouse_point.im + (f->min.im - mouse_point.im) * zoom_rate;
	f->max.im = mouse_point.im + (f->max.im - mouse_point.im) * zoom_rate;
}

int	zoom(int button, int x, int y, t_fractol *f)
{
	t_complex	mouse_point;
	double		zoom_rate;

	if ((button == ZOOM_IN) || button == ZOOM_OUT && f->zoom <= 3)
	{
		mouse_point.re = x * f->factor.re + f->min.re;
		mouse_point.im = y * f->factor.im + f->min.im;
		if (button == ZOOM_IN)
		{
			zoom_rate = 0.8;
			f->max_iteration += 5;
		}
		else
		{
			zoom_rate = 1.25;
			f->max_iteration -= 5;
		}
		f->zoom *= zoom_rate;
		reset_min_max(mouse_point, zoom_rate, f);
		mlx_clear_window(f->mlx, f->mlx_win);
		if (ft_draw(f) == -1)
			ft_exit(1);
	}
	return (0);
}
