/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:50:36 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:12:51 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	add_light(t_obj **light, t_in_object *in_obj)
{
	int		i;
	t_obj	*new;

	i = -1;
	while (++i < in_obj->l_size)
	{
		new = object(POINT_LIGHT, point_light(&in_obj->l[i]), in_obj->l[i].rgb);
		obj_add(light, new);
	}
}
