/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:24:49 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:31:23 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"

void	handle_cone_range(t_cone *co, t_point3 *h, double *t, t_ray *ray)
{
	t_vec3		ph;
	t_vec3		pt;

	*h = ray_at(ray, *t);
	ph = vminus(*h, co->p);
	pt = vminus(co->t, co->p);
	if (vdot(co->n, ph) < 0)
		*t = INFINITY;
	if (vlength2(ph) > vlength2(pt))
		*t = INFINITY;
}

double	hit_cone_side(t_cone *co, t_ray *ray, t_hit_record *rec)
{
	t_discrim	d;
	double		t[2];
	t_vec3		h[2];
	t_vec3		to;

	to = vminus(ray->orig, co->t);
	co->c1 = vdot(ray->dir, co->n);
	co->c2 = vdot(to, co->n);
	d.a = vdot(ray->dir, ray->dir) - (co->c1 * co->c1) / co->cos2;
	d.half_b = vdot(ray->dir, to) - (co->c1 * co->c2) / co->cos2;
	d.c = vdot(to, to) - (co->c2 * co->c2) / co->cos2;
	d.discriminant = d.half_b * d.half_b - d.a * d.c;
	if (d.discriminant < EPSILON)
		return (INFINITY);
	d.sqrt_d = sqrt(d.discriminant);
	if (check_root(t, rec, d) == FALSE)
		return (INFINITY);
	handle_cone_range(co, &h[0], &t[0], ray);
	handle_cone_range(co, &h[1], &t[1], ray);
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (INFINITY);
	return (fmin(t[0], t[1]));
}

void	cone_side_normal(t_cone *co, t_hit_record **rec)
{
	t_vec3		th;
	t_point3	q;
	t_vec3		qh;
	double		h_prime;
	double		r_prime;

	th = vminus((*rec)->p, co->t);
	h_prime = vlength(th) * co->cos;
	r_prime = vlength(th) * co->sin;
	q = vplus(co->t, vmult(co->flip_n, h_prime));
	qh = vminus((*rec)->p, q);
	(*rec)->normal = vunit(vplus(vmult(vmult(co->n, h_prime), r_prime), \
														vmult(qh, h_prime)));
}
