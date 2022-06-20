/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:26:14 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:11:48 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include <math.h>
# include "structures.h"
# include "mlx.h"

int			rgb_extract(int mlx_color, t_color_mask type);
t_color3	pixel_to_color3(int mlx_color);
void		ft_mlx_pixel_put(t_scene *scene, t_color3 *pixel_color, \
																int x, int y);
int			xpm_pixel_get(t_xpm_image *img, int x, int y);

#endif
