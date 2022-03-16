/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:35:12 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 20:24:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	palette_tool(int iter)
{
	if (iter < 0)
		iter = 0;
	return (iter);
}

void	choose_color(int iter, t_fractol *f)
{
	iter = (double)iter / f->max_iteration * 100;
	if (iter == 100)
		f->col = (t_col){0, 0, 0};
	else
	{
		if (f->color_flag == 1)
		{
			f->col = (t_col){palette_tool(255 - iter * 2),
				palette_tool(255 - iter * 7), palette_tool(255 - iter * 1)};
		}
		else if (f->color_flag == 2)
		{
			f->col = (t_col){(iter * 7) % 255,
				(iter * 3) % 4, (iter * 2) % 70};
		}
		else if (f->color_flag == 3)
		{
			f->col = (t_col){palette_tool(255 - iter * 3),
				palette_tool(255 - iter * 1), palette_tool(255 - iter * 1)};
		}
	}
	if (iter == 100 && f->color_flag == 3)
		f->col = (t_col){255, 255, 255};
}
