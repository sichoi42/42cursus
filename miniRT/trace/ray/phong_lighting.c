/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:45:57 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:31:43 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

typedef struct s_light_var
{
	t_vec3		dir;
	double		len;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
}	t_light_var;

t_bool	in_shadow(t_obj *obj, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.t_min = 0;
	rec.t_max = light_len;
	if (hit(obj, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	get_diffuse_light(t_light *light, t_light_var *lv, t_vec3 n)
{
	t_color3	diffuse;
	double		kd;

	lv->dir = vunit(lv->dir);
	kd = fmax(vdot(lv->dir, n), 0.0);
	diffuse = vmult(light->light_color, kd);
	return (diffuse);
}

t_color3	get_specular_light(t_light *light, t_light_var *lv, t_scene *scene)
{
	double		spec;
	double		ksn;
	double		ks;
	t_color3	specular;

	lv->view_dir = vunit(vflip(scene->ray.dir));
	lv->reflect_dir = reflect(vflip(lv->dir), scene->rec.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(vdot(lv->view_dir, lv->reflect_dir), 0.0), ksn);
	specular = vmult(light->light_color, ks * spec);
	return (specular);
}

// add color value by diffuse, specular light
// ksn = 64; // shininess value, 이 값이 작을수록 주변으로 퍼짐.
// ks = 0.5; // specular strength, 이 값이 1에 가까울수록 specular로 인한 효과가 커짐.
t_color3	get_point_light(t_scene *scene, t_light *light)
{
	t_light_var	lv;
	t_color3	diffuse;
	t_color3	specular;
	double		brightness;
	t_ray		light_ray;

	lv.dir = vminus(light->orig, scene->rec.p);
	lv.len = vlength(lv.dir);
	light_ray = ray(vplus(scene->rec.p, \
							vmult(scene->rec.normal, EPSILON)), lv.dir);
	if (in_shadow(scene->objs, light_ray, lv.len))
		return (color3(0, 0, 0));
	diffuse = get_diffuse_light(light, &lv, scene->rec.normal);
	specular = get_specular_light(light, &lv, scene);
	brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(diffuse, specular), brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_obj		*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == POINT_LIGHT)
			light_color = vplus(light_color, \
								get_point_light(scene, lights->element));
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
