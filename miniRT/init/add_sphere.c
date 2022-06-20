/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:49:58 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/16 18:51:13 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	add_sphere(t_obj **objs, t_in_object *in_obj, void *mlx_ptr)
{
	int		i;
	t_obj	*new;

	i = -1;
	while (++i < in_obj->sp_size)
	{
		new = object(SP, sphere(&in_obj->sp[i], mlx_ptr), in_obj->sp[i].rgb);
		obj_add(objs, new);
	}
}
