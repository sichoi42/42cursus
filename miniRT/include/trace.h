/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:06:32 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:29:59 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"
// =============================================================================
// In Ray Folder
// =============================================================================

// =============================================================================
//ray.c
// =============================================================================
t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);

// =============================================================================
// phong_ligting.c
// =============================================================================
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_bool		in_shadow(t_obj *obj, t_ray light_ray, double light_len);
t_color3	get_point_light(t_scene *scene, t_light *light);
t_color3	phong_lighting(t_scene *scene);

// =============================================================================
// texture.c
// =============================================================================
void		checkerboard(t_hit_record *rec);
void		set_uv_map(t_vec3 n, t_vec3 *u, t_vec3 *v);
int			rgb_extract(int mlx_color, t_color_mask type);
t_color3	pixel_to_color3(int mlx_color);
int			xpm_pixel_get(t_xpm_image *img, int x, int y);
t_color3	mapping_texture_img(double u, double v, t_xpm_image *img);
t_vec3		mapping_bump_img(t_hit_record *rec, t_xpm_image *img);
void		bump_mapping(t_hit_record *rec, t_obj *obj);
void		hit_color_select(t_hit_record *rec, t_obj *obj);

// =============================================================================
// In Hit Folder
// =============================================================================

// =============================================================================
// hit.c
// =============================================================================
t_bool		check_root(double t[], t_hit_record *rec, t_discrim d);
double		validate_root(t_discrim d, t_hit_record *rec);
t_bool		hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec);

// =============================================================================
// hit_sphere.c
// =============================================================================
void		get_sphere_uv(t_hit_record *rec);
t_bool		hit_sphere(t_obj *obj, t_ray *ray, t_hit_record *rec);

// =============================================================================
// hit_plane.c
// =============================================================================
void		get_plane_uv(t_hit_record *rec);
t_bool		hit_plane(t_obj *obj, t_ray *ray, t_hit_record *rec);

// =============================================================================
// hit_cylinder.c
// =============================================================================
void		get_cylinder_uv(t_hit_record *rec, t_cylinder *cy);
double		hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec);

// =============================================================================
// hit_cone.c
// =============================================================================
void		get_cone_uv(t_hit_record *rec, t_cone *co);
double		hit_cone_cap(t_cone *co, t_ray *ray, t_hit_record *rec);
t_bool		hit_cone(t_obj *obj, t_ray *ray, t_hit_record *rec);

// =============================================================================
// hit_cone_side.c
// =============================================================================
double		hit_cone_side(t_cone *co, t_ray *ray, t_hit_record *rec);
void		cone_side_normal(t_cone *co, t_hit_record **rec);

// =============================================================================
// normal.c
// =============================================================================
void		set_face_normal(t_ray *ray, t_hit_record *rec);

#endif
