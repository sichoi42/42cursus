/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:36:17 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/18 17:25:06 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

void	get_plane_uv(t_hit_record *rec)
{
	set_uv_map(rec->normal, &rec->u_vec, &rec->v_vec);
	rec->u = ft_fmod_abs(fmod(vdot(rec->p, rec->u_vec), 1), 1);
	rec->v = ft_fmod_abs(fmod(vdot(rec->p, rec->v_vec), 1), 1);
}

t_bool	hit_plane(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	t_vec3	op;
	double	denominator;
	double	numerator;
	double	t;

	pl = (t_plane *)obj->element;
	denominator = vdot(pl->normal, ray->dir);
	op = vminus(pl->p, ray->orig);
	numerator = vdot(op, pl->normal);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	t = numerator / denominator;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->normal = vunit(pl->normal);
	rec->p = ray_at(ray, t);
	rec->p = vplus(rec->p, vmult(rec->normal, EPSILON));
	rec->texture = pl->texture;
	set_face_normal(ray, rec);
	get_plane_uv(rec);
	hit_color_select(rec, obj);
	return (TRUE);
}
