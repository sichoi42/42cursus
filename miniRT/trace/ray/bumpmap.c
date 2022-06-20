/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:13:06 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/18 17:18:46 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_uv_map(t_vec3 n, t_vec3 *u, t_vec3 *v)
{
	t_vec3	v_up;

	v_up = get_v_up(n);
	*u = vunit(vcross(v_up, n));
	*v = vunit(vcross(n, *u));
}

t_color3	mapping_texture_img(double u, double v, t_xpm_image *img)
{
	int		int_u;
	int		int_v;
	int		mlx_color;

	int_u = (int)(u * img->width);
	int_v = (int)((1.0 - v) * img->height);
	mlx_color = xpm_pixel_get(img, int_u, int_v);
	return (pixel_to_color3(mlx_color));
}

t_vec3	mat_mult(t_vec3 t, t_vec3 b, t_vec3 n, t_vec3 n_color)
{
	double	x;
	double	y;
	double	z;

	x = t.x * n_color.x + b.x * n_color.y + n.x * n_color.z;
	y = t.y * n_color.x + b.y * n_color.y + n.y * n_color.z;
	z = t.z * n_color.x + b.z * n_color.y + n.z * n_color.z;
	return (vec3(x, y, z));
}

t_vec3	mapping_bump_img(t_hit_record *rec, t_xpm_image *img)
{
	int		int_u;
	int		int_v;
	int		mlx_color;
	t_vec3	normal_color;

	int_u = (int)(rec->u * img->width);
	int_v = (int)((1.0 - rec->v) * img->height);
	mlx_color = xpm_pixel_get(img, int_u, int_v);
	normal_color = pixel_to_color3(mlx_color);
	normal_color = vminus(vmult(normal_color, 2), vec3(1, 1, 1));
	return (mat_mult(rec->u_vec, rec->v_vec, rec->normal, normal_color));
}

void	bump_mapping(t_hit_record *rec, t_obj *obj)
{
	t_obj_type	type;
	t_bumpmap	*bmp;

	type = obj->type;
	if (type == SP)
		bmp = ((t_sphere *)obj->element)->bumpmap;
	else if (type == PL)
		bmp = ((t_plane *)obj->element)->bumpmap;
	else if (type == CY)
		bmp = ((t_cylinder *)obj->element)->bumpmap;
	else
		bmp = ((t_cone *)obj->element)->bumpmap;
	rec->albedo = mapping_texture_img(rec->u, rec->v, bmp->texture_img);
	rec->normal = vunit(mapping_bump_img(rec, bmp->bump_img));
}
