/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:33:24 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:57:10 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	check_root(double t[], t_hit_record *rec, t_discrim d)
{
	t[0] = (-d.half_b - d.sqrt_d) / d.a;
	t[1] = (-d.half_b + d.sqrt_d) / d.a;
	if (t[0] < rec->t_min || t[0] > rec->t_max)
		t[0] = INFINITY;
	if (t[1] < rec->t_min || t[1] > rec->t_max)
		t[1] = INFINITY;
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (FALSE);
	return (TRUE);
}

double	validate_root(t_discrim d, t_hit_record *rec)
{
	double	root;

	root = (-d.half_b - d.sqrt_d) / d.a;
	if (root < rec->t_min || root > rec->t_max)
	{
		root = (-d.half_b + d.sqrt_d) / d.a;
		if (root < rec->t_min || root > rec->t_max)
			return (INFINITY);
	}
	return (root);
}

t_bool	hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (obj->type == SP)
		hit_result = hit_sphere(obj, ray, rec);
	else if (obj->type == PL)
		hit_result = hit_plane(obj, ray, rec);
	else if (obj->type == CY)
		hit_result = hit_cylinder(obj, ray, rec);
	else if (obj->type == CO)
		hit_result = hit_cone(obj, ray, rec);
	return (hit_result);
}

t_bool	hit(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_bool			is_hit;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	is_hit = FALSE;
	while (obj)
	{
		if (hit_obj(obj, ray, &temp_rec))
		{
			is_hit = TRUE;
			temp_rec.t_max = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (is_hit);
}
