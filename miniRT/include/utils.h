/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:07:15 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:10:56 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "structures.h"

// =============================================================================
// math_utils.c
// =============================================================================
double		degree_to_radian(double degree);
double		radian_to_degree(double radian);
double		ft_fmod_abs(double x, double mod);
int			clamp(int x, int min, int max);

// =============================================================================
// mlx_event.c
// =============================================================================
int			key_exit(int param);
int			key_esc(int key);

// =============================================================================
// vec3_calc.c
// =============================================================================
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec, double t);
t_vec3		vmult_(t_vec3 vec, t_vec3 vec2);
t_vec3		vdivide(t_vec3 vec, double t);

// =============================================================================
// vec3_calc2.c
// =============================================================================
double		vlength2(t_vec3 vec);
double		vlength(t_vec3 vec);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		reflect(t_vec3 v, t_vec3 n);

// =============================================================================
// vec3_init.c
// =============================================================================
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);

// =============================================================================
// vec3_utils.c
// =============================================================================
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec, t_vec3 vec2);
t_bool		is_same_vec(t_vec3 vec, t_vec3 vec2);
t_vec3		get_v_up(t_vec3 vec);
t_vec3		vflip(t_vec3 vec);

// =============================================================================
// obj_utils.c
// =============================================================================
void		obj_add(t_obj **lst, t_obj *new);
t_obj		*obj_last(t_obj *lst);

#endif
