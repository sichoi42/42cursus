/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:26:25 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:27:32 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"
# include "parsing.h"

// =============================================================================
// canvas.c, camera.c
// =============================================================================
t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_in_camera *in_cam);

// =============================================================================
// object_create.c
// =============================================================================
void		close_fds(int fd[]);
t_obj		*object(t_obj_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_in_sphere *in_sp, void *mlx_ptr);
t_plane		*plane(t_in_plane *in_pl, void *mlx_ptr);
t_cylinder	*cylinder(t_in_cylinder *in_cl, void *mlx_ptr);
t_cone		*cone(t_in_cone *in_co, void *mlx_ptr);
t_light		*point_light(t_in_light *in_light);

#endif
