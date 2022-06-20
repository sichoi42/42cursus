/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:36:12 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:27:37 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"

void	get_cylinder_uv(t_hit_record *rec, t_cylinder *cy)
{
	double	theta;
	double	height;
	t_vec3	ph;

	set_uv_map(cy->normal, &rec->u_vec, &rec->v_vec);
	ph = vminus(rec->p, cy->p);
	theta = atan2(-1 * vdot(ph, rec->v_vec), vdot(ph, rec->u_vec)) + M_PI;
	height = vdot(ph, cy->normal);
	rec->u = theta * M_1_PI * 0.5;
	rec->v = ft_fmod_abs(fmod(height, 1), 1);
}

t_bool	handle_side_range(t_cylinder *cy, t_point3 h[], double t[])
{
	if (vdot(cy->normal, vminus(h[0], cy->tc)) > 0)
		t[0] = INFINITY;
	if (vdot(cy->normal, vminus(h[0], cy->bc)) < 0)
		t[0] = INFINITY;
	if (vdot(cy->normal, vminus(h[1], cy->tc)) > 0)
		t[1] = INFINITY;
	if (vdot(cy->normal, vminus(h[1], cy->bc)) < 0)
		t[1] = INFINITY;
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (FALSE);
	return (TRUE);
}

double	hit_cylinder_side(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_discrim	d;
	double		t[2];
	t_vec3		po;
	t_point3	h[2];

	po = vminus(ray->orig, cy->p);
	d.a = vlength2(vcross(ray->dir, cy->normal));
	d.half_b = vdot(vcross(ray->dir, cy->normal), vcross(po, cy->normal));
	d.c = vlength2(vcross(po, cy->normal)) - cy->radius * cy->radius;
	d.discriminant = d.half_b * d.half_b - d.a * d.c;
	if (d.discriminant < EPSILON)
		return (INFINITY);
	d.sqrt_d = sqrt(d.discriminant);
	if (check_root(t, rec, d) == FALSE)
		return (INFINITY);
	h[0] = ray_at(ray, t[0]);
	h[1] = ray_at(ray, t[1]);
	if (handle_side_range(cy, h, t) == FALSE)
		return (INFINITY);
	return (fmin(t[0], t[1]));
}

void	input_cy_rec(t_obj *obj, t_hit_record *rec, double t[], t_ray *ray)
{
	t_vec3		ph;
	t_cylinder	*cy;

	cy = (t_cylinder *)obj->element;
	if (t[0] < t[1])
	{
		rec->t = t[0];
		rec->p = ray_at(ray, t[0]);
		ph = vminus(rec->p, cy->p);
		rec->normal = vunit(vminus(ph, vmult(cy->normal, \
													vdot(cy->normal, ph))));
		set_face_normal(ray, rec);
		get_cylinder_uv(rec, cy);
	}
	else
	{
		rec->t = t[1];
		rec->p = ray_at(ray, t[1]);
		rec->normal = cy->normal;
		set_face_normal(ray, rec);
		get_plane_uv(rec);
	}
	rec->texture = cy->texture;
	hit_color_select(rec, obj);
}

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	double		t[2];

	cy = (t_cylinder *)obj->element;
	t[0] = hit_cylinder_side(cy, ray, rec);
	t[1] = INFINITY;
	if (cy->flag != CY_NO_CAP)
		t[1] = hit_cylinder_cap(cy, ray, rec);
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (FALSE);
	input_cy_rec(obj, rec, t, ray);
	return (TRUE);
}
