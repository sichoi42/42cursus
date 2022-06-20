/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:50:16 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/16 18:51:53 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	add_cone(t_obj **objs, t_in_object *in_obj, void *mlx_ptr)
{
	int		i;
	t_obj	*new;

	i = -1;
	while (++i < in_obj->co_size)
	{
		new = object(CO, cone(&in_obj->co[i], mlx_ptr), in_obj->co[i].rgb);
		obj_add(objs, new);
	}
}
