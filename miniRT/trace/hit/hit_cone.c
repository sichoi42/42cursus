/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:28:25 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:28:57 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"

void	get_cone_uv(t_hit_record *rec, t_cone *co)
{
	double	theta;
	double	height;
	t_vec3	ph;

	set_uv_map(co->n, &rec->u_vec, &rec->v_vec);
	ph = vminus(rec->p, co->p);
	theta
		= atan2(-1 * vdot(ph, rec->v_vec), vdot(ph, rec->u_vec)) + M_PI;
	height = vdot(ph, co->n);
	rec->u = theta * M_1_PI * 0.5;
	rec->v = ft_fmod_abs(fmod(height, 1), 1);
}

double	hit_cone_cap(t_cone *co, t_ray *ray, t_hit_record *rec)
{
	t_vec3		op;
	t_point3	h;
	t_vec3		hp;
	double		root;
	double		denom;

	denom = vdot(ray->dir, co->n);
	if (denom == 0)
		return (INFINITY);
	op = vminus(co->p, ray->orig);
	root = vdot(op, co->n) / denom;
	h = ray_at(ray, root);
	hp = vminus(co->p, h);
	if (vlength2(hp) > co->r * co->r)
		return (INFINITY);
	if (root < rec->t_min || root > rec->t_max)
		return (INFINITY);
	return (root);
}

void	input_co_rec(t_obj *obj, t_hit_record *rec, double t[], t_ray *ray)
{
	t_cone	*co;

	co = (t_cone *)obj->element;
	if (t[0] < t[1])
	{
		rec->t = t[0];
		rec->p = ray_at(ray, t[0]);
		cone_side_normal(co, &rec);
		set_face_normal(ray, rec);
		get_cone_uv(rec, co);
	}
	else
	{
		rec->t = t[1];
		rec->p = ray_at(ray, t[1]);
		rec->normal = co->n;
		set_face_normal(ray, rec);
		get_plane_uv(rec);
	}
	rec->texture = co->texture;
	hit_color_select(rec, obj);
}

t_bool	hit_cone(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_cone	*co;
	double	t[2];

	co = (t_cone *)obj->element;
	t[0] = hit_cone_side(co, ray, rec);
	t[1] = INFINITY;
	t[1] = hit_cone_cap(co, ray, rec);
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (FALSE);
	input_co_rec(obj, rec, t, ray);
	return (TRUE);
}
