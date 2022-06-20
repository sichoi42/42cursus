/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:34:13 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:34:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = (vdot(ray->dir, rec->normal) < 0);
	if (rec->front_face == FALSE)
		rec->normal = vflip(rec->normal);
}
