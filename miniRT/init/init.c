/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:21:29 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/18 16:38:42 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_xpm_image	*get_xpm_img(char *file_name, void *mlx_ptr)
{
	t_xpm_image	*xpm_img;

	xpm_img = malloc(sizeof(t_xpm_image));
	if (xpm_img == NULL)
		exit(1);
	xpm_img->img.img = mlx_xpm_file_to_image(mlx_ptr, file_name, \
	&xpm_img->width, &xpm_img->height);
	xpm_img->img.addr = mlx_get_data_addr(xpm_img->img.img, \
	&xpm_img->img.bits_per_pixel, \
	&xpm_img->img.line_length, \
	&xpm_img->img.endian);
	return (xpm_img);
}

void	free_in_object(t_in_object *o)
{
	free(o->w);
	free(o->a);
	free(o->c);
	free(o->l);
	free(o->sp);
	free(o->pl);
	free(o->co);
}

t_obj	*adding_objects(t_in_object *in_obj, t_obj **light, void *mlx_ptr)
{
	t_obj	*objs;

	objs = NULL;
	if (in_obj->sp_size > 0)
		add_sphere(&objs, in_obj, mlx_ptr);
	if (in_obj->pl_size > 0)
		add_plane(&objs, in_obj, mlx_ptr);
	if (in_obj->cy_size > 0)
		add_cylinder(&objs, in_obj, mlx_ptr);
	if (in_obj->co_size > 0)
		add_cone(&objs, in_obj, mlx_ptr);
	if (in_obj->l_size > 0)
		add_light(light, in_obj);
	return (objs);
}

void	init(t_scene *scene, t_mlx *mlx, t_in_object *in_obj)
{
	if (in_obj->w == NULL)
		scene->canvas = canvas(DEFAULT_WINDOW_W, DEFAULT_WINDOW_H);
	else
		scene->canvas = canvas(in_obj->w->width, in_obj->w->height);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
	scene->canvas.width, scene->canvas.height, "miniRT");
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, scene->canvas.width, \
	scene->canvas.height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
	&mlx->img.line_length, &mlx->img.endian);
	scene->ambient = vmult(in_obj->a->rgb, in_obj->a->ratio);
	scene->camera = camera(&scene->canvas, in_obj->c);
	scene->light = NULL;
	scene->objs = adding_objects(in_obj, &scene->light, mlx->mlx_ptr);
	scene->mlx = mlx;
}
