/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:13:04 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:12:06 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "utils.h"

int	rgb_extract(int mlx_color, t_color_mask type)
{
	return ((mlx_color >> type) & 0xFF);
}

t_color3	pixel_to_color3(int mlx_color)
{
	double	r;
	double	g;
	double	b;

	r = (double)rgb_extract(mlx_color, RED) / 256;
	g = (double)rgb_extract(mlx_color, GREEN) / 256;
	b = (double)rgb_extract(mlx_color, BLUE) / 256;
	return (color3(r, g, b));
}

void	ft_mlx_pixel_put(t_scene *scene, t_color3 *pixel_color, int x, int y)
{
	int		pixel;
	int		r;
	int		g;
	int		b;
	t_image	*img;

	img = &scene->mlx->img;
	pixel = img->bits_per_pixel / 8;
	r = (int)(255.999 * sqrt(pixel_color->x));
	g = (int)(255.999 * sqrt(pixel_color->y));
	b = (int)(255.999 * sqrt(pixel_color->z));
	img->addr[(x * pixel) + (y * img->line_length) + 2] = r;
	img->addr[(x * pixel) + (y * img->line_length) + 1] = g;
	img->addr[(x * pixel) + (y * img->line_length)] = b;
}

int	xpm_pixel_get(t_xpm_image *img, int x, int y)
{
	char	*dst;

	x = clamp(x, 0, img->width - 1);
	y = clamp(y, 0, img->height - 1);
	dst = img->img.addr + (y * img->img.line_length + \
											x * (img->img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
