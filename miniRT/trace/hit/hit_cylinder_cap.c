/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:06:36 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 17:08:56 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"

double	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec3	ot;
	t_vec3	ob;
	double	denom;
	double	tt;
	double	bt;

	denom = vdot(ray->dir, cy->normal);
	if (denom == 0)
		return (INFINITY);
	ot = vminus(cy->tc, ray->orig);
	tt = vdot(ot, cy->normal) / denom;
	if (vlength2(vminus(ray_at(ray, tt), cy->tc)) > cy->radius * cy->radius)
		tt = INFINITY;
	ob = vminus(cy->bc, ray->orig);
	bt = vdot(ob, cy->normal) / denom;
	if (vlength2(vminus(ray_at(ray, bt), cy->bc)) > cy->radius * cy->radius)
		bt = INFINITY;
	if (tt < rec->t_min || tt > rec->t_max)
		tt = INFINITY;
	if (bt < rec->t_min || bt > rec->t_max)
		bt = INFINITY;
	if (tt < bt)
		return (tt);
	return (bt);
}
