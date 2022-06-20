/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:50:38 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/16 18:51:46 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	add_cylinder(t_obj **objs, t_in_object *in_obj, void *mlx_ptr)
{
	int		i;
	t_obj	*new;

	i = -1;
	while (++i < in_obj->cy_size)
	{
		new = object(CY, cylinder(&in_obj->cy[i], mlx_ptr), in_obj->cy[i].rgb);
		obj_add(objs, new);
	}
}
