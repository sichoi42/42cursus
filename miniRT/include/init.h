/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:55:35 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 15:25:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structures.h"
# include "parsing.h"
# include "scene.h"
# include "mlx.h"
# include "utils.h"

// =============================================================================
// add_{object}.c
// =============================================================================
void		add_sphere(t_obj **objs, t_in_object *in_obj, void *mlx_ptr);
void		add_plane(t_obj **objs, t_in_object *in_obj, void *mlx_ptr);
void		add_cylinder(t_obj **objs, t_in_object *in_obj, void *mlx_ptr);
void		add_cone(t_obj **objs, t_in_object *in_obj, void *mlx_ptr);
void		add_light(t_obj **objs, t_in_object *in_obj);

// =============================================================================
// init.c
// =============================================================================
t_xpm_image	*get_xpm_img(char *file_name, void *mlx_ptr);
void		free_in_object(t_in_object *o);
t_obj		*adding_objects(t_in_object *in_obj, t_obj **light, void *mlx_ptr);
void		init_scene(t_scene *scene, t_in_object *in_obj, void *mlx_ptr);
void		init(t_scene *scene, t_mlx *mlx, t_in_object *in_obj);

#endif
