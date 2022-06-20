/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:50:06 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/16 18:51:31 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	add_plane(t_obj **objs, t_in_object *in_obj, void *mlx_ptr)
{
	int		i;
	t_obj	*new;

	i = -1;
	while (++i < in_obj->pl_size)
	{
		new = object(PL, plane(&in_obj->pl[i], mlx_ptr), in_obj->pl[i].rgb);
		obj_add(objs, new);
	}
}
