/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:36:24 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:25:25 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

void	get_sphere_uv(t_hit_record *rec)
{
	double	theta;
	double	phi;

	set_uv_map(rec->normal, &rec->u_vec, &rec->v_vec);
	theta = acos(-1 * rec->normal.y);
	phi = atan2(-1 * rec->normal.z, rec->normal.x) + M_PI;
	rec->u = phi * M_1_PI * 0.5;
	rec->v = theta * M_1_PI;
}

t_bool	cutting_sphere(double *t, t_vec3 h[], t_point3 center, int flag)
{
	if (flag == HALF)
	{
		if (t[0] != INFINITY && vdot(vec3(0, 1, 0), vminus(h[0], center)) < 0)
			t[0] = INFINITY;
		if (t[1] != INFINITY && vdot(vec3(0, 1, 0), vminus(h[1], center)) < 0)
			t[1] = INFINITY;
		if (t[0] == INFINITY && t[1] == INFINITY)
			return (FALSE);
	}
	return (TRUE);
}

void	input_sp_rec(t_obj *obj, t_hit_record *rec, double root, t_ray *ray)
{
	t_sphere	*sp;

	sp = (t_sphere *)obj->element;
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(vdivide(vminus(rec->p, sp->center), sp->radius));
	rec->texture = sp->texture;
	set_face_normal(ray, rec);
	get_sphere_uv(rec);
	hit_color_select(rec, obj);
}

t_bool	hit_sphere(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_vec3		oc;
	t_sphere	*sp;
	t_discrim	d;
	double		t[2];
	t_point3	h[2];

	sp = (t_sphere *)obj->element;
	oc = vminus(ray->orig, sp->center);
	d.a = vlength2(ray->dir);
	d.half_b = vdot(oc, ray->dir);
	d.c = vlength2(oc) - sp->radius2;
	d.discriminant = d.half_b * d.half_b - d.a * d.c;
	if (d.discriminant < EPSILON)
		return (FALSE);
	d.sqrt_d = sqrt(d.discriminant);
	if (check_root(t, rec, d) == FALSE)
		return (FALSE);
	h[0] = ray_at(ray, t[0]);
	h[1] = ray_at(ray, t[1]);
	if (cutting_sphere(t, h, sp->center, sp->flag) == FALSE)
		return (FALSE);
	input_sp_rec(obj, rec, fmin(t[0], t[1]), ray);
	return (TRUE);
}
