/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:30:44 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:31:37 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

void	input_sphere(int fd, t_in_object *obj, char *buf)
{
	pass_space(fd, buf, "");
	if (*buf != 'p')
		print_error("Wrong input: symbol sphere\n");
	if (obj->sp == NULL)
		obj->sp = malloc_array(sizeof(t_in_sphere), ++(obj->sp_size));
	else
	{
		obj->sp = ft_realloc(obj->sp, sizeof(t_in_sphere) * (obj->sp_size),
				sizeof(t_in_sphere) * (obj->sp_size + 1));
		++(obj->sp_size);
	}
	check_half(fd, buf, &((obj->sp)[obj->sp_size - 1].flag));
	input_xyz(fd, &((obj->sp)[obj->sp_size - 1].org), buf);
	(obj->sp)[obj->sp_size - 1].r = make_float(fd, buf) / 2;
	input_color3(fd, &((obj->sp)[obj->sp_size - 1].rgb),
		&((obj->sp)[obj->sp_size - 1].bp), buf);
	check_texture(fd, buf, &((obj->sp)[obj->sp_size - 1].texture));
}

void	input_plane(int fd, t_in_object *obj, char *buf)
{
	pass_space(fd, buf, "");
	if (*buf != 'l')
		print_error("Wrong input: symbol plane\n");
	if (obj->pl == NULL)
		obj->pl = malloc_array(sizeof(t_in_plane), ++(obj->pl_size));
	else
	{
		obj->pl = ft_realloc(obj->pl, sizeof(t_in_plane) * (obj->pl_size),
				sizeof(t_in_plane) * (obj->pl_size + 1));
		++(obj->pl_size);
	}
	input_xyz(fd, &((obj->pl)[obj->pl_size - 1].org), buf);
	input_vec(fd, &((obj->pl)[obj->pl_size - 1].org_vec), buf);
	input_color3(fd, &((obj->pl)[obj->pl_size - 1].rgb),
		&((obj->pl)[obj->pl_size - 1].bp), buf);
	check_texture(fd, buf, &((obj->pl)[obj->pl_size - 1].texture));
}

void	input_cone(int fd, t_in_object *obj, char *buf)
{
	if (obj->co == NULL)
		obj->co = malloc_array(sizeof(t_in_cone), ++(obj->co_size));
	else
	{
		obj->co = ft_realloc(obj->co, sizeof(t_in_cone) * (obj->co_size),
				sizeof(t_in_cone) * (obj->co_size + 1));
		++(obj->co_size);
	}
	input_xyz(fd, &((obj->co)[obj->co_size - 1].org), buf);
	input_vec(fd, &((obj->co)[obj->co_size - 1].org_vec), buf);
	obj->co[obj->co_size - 1].h = make_float(fd, buf);
	obj->co[obj->co_size - 1].a = make_float(fd, buf);
	if (obj->co[obj->co_size - 1].a <= 0 || obj->co[obj->co_size - 1].a >= 90)
		print_error("Wrong input: angle 0~90\n");
	input_color3(fd, &((obj->co)[obj->co_size - 1].rgb),
		&((obj->co)[obj->co_size - 1].bp), buf);
	check_texture(fd, buf, &((obj->co)[obj->co_size - 1].texture));
}

void	input_cylinder(int fd, t_in_object *obj, char *buf)
{
	pass_space(fd, buf, "");
	if (*buf == 'o')
	{
		input_cone(fd, obj, buf);
		return ;
	}
	if (*buf != 'y')
		print_error("Wrong input: symbol cylinder\n");
	if (obj->cy == NULL)
		obj->cy = malloc_array(sizeof(t_in_cylinder), ++(obj->cy_size));
	else
	{
		obj->cy = ft_realloc(obj->cy, sizeof(t_in_cylinder) * (obj->cy_size),
				sizeof(t_in_cylinder) * (obj->cy_size + 1));
		++(obj->cy_size);
	}
	check_half(fd, buf, &((obj->cy)[obj->cy_size - 1].flag));
	input_xyz(fd, &((obj->cy)[obj->cy_size - 1].org), buf);
	input_vec(fd, &((obj->cy)[obj->cy_size - 1].org_vec), buf);
	obj->cy[obj->cy_size - 1].r = make_float(fd, buf) / 2;
	obj->cy[obj->cy_size - 1].h = make_float(fd, buf);
	input_color3(fd, &((obj->cy)[obj->cy_size - 1].rgb),
		&((obj->cy)[obj->cy_size - 1].bp), buf);
	check_texture(fd, buf, &((obj->cy)[obj->cy_size - 1].texture));
}

void	input_window(int fd, t_in_object *obj)
{
	char	buf;
	char	*str;

	if (obj->w == NULL)
		obj->w = malloc_array(sizeof(t_in_window), 1);
	else
		print_error("Wrong input: window only one\n");
	str = read_to_str(fd, &buf, 0);
	obj->w->width = ft_stoi(str);
	free(str);
	str = read_to_str(fd, &buf, 0);
	obj->w->height = ft_stoi(str);
	free(str);
}
