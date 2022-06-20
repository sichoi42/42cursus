/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_am_li_ca.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:27:26 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:50:49 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

double	input_ratio(int fd, char *buf)
{
	double	num;

	num = make_float(fd, buf);
	if (num < 0.0 || num > 1.0)
		print_error("Wrong input: ratio range\n");
	return (num);
}

void	input_ambient(int fd, t_in_object *obj)
{
	char	buf;

	if (obj->a == NULL)
		obj->a = malloc_array(sizeof(t_in_ambient), 1);
	else
		print_error("Wrong input: ambient only one\n");
	obj->a->ratio = input_ratio(fd, &buf);
	input_color3(fd, &(obj->a->rgb), NULL, &buf);
}

void	input_camera(int fd, t_in_object *obj)
{
	char	buf;

	if (obj->c == NULL)
		obj->c = malloc_array(sizeof(t_in_camera), 1);
	else
		print_error("Wrong input: camera only one\n");
	input_xyz(fd, &(obj->c->org), &buf);
	input_vec(fd, &(obj->c->org_vec), &buf);
	obj->c->fov = make_float(fd, &buf);
	if (obj->c->fov <= 0 || obj->c->fov >= 180)
		print_error("Wrong input: camera fov range\n");
}

void	input_light(int fd, t_in_object *obj)
{
	char	buf;

	if (obj->l == NULL)
		obj->l = malloc_array(sizeof(t_in_light), ++(obj->l_size));
	else
	{
		obj->l = ft_realloc(obj->l, sizeof(t_in_light) * (obj->l_size),
				sizeof(t_in_light) * (obj->l_size + 1));
		++(obj->l_size);
	}
	input_xyz(fd, &((obj->l)[obj->l_size - 1].org), &buf);
	(obj->l)[obj->l_size - 1].ratio = input_ratio(fd, &buf);
	input_color3(fd, &((obj->l)[obj->l_size - 1].rgb), NULL, &buf);
}
