/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:25:07 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:23:04 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parsing.h"
#include "utils.h"
#include "init.h"
#include <stdlib.h>
#include <fcntl.h>

void	get_cone_bmp(t_cone **co, t_in_cone *in_co, void *mlx_ptr)
{
	int	fd[2];

	fd[0] = open(in_co->bp[0], O_RDONLY);
	fd[1] = open(in_co->bp[1], O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0)
		print_error("no such file\n");
	close_fds(fd);
	(*co)->texture = BUMP_MAP;
	(*co)->bumpmap->texture_img = get_xpm_img(in_co->bp[0], mlx_ptr);
	(*co)->bumpmap->bump_img = get_xpm_img(in_co->bp[1], mlx_ptr);
}

t_cone	*cone(t_in_cone *in_co, void *mlx_ptr)
{
	t_cone	*co;

	co = malloc(sizeof(t_cone));
	if (co == NULL)
		exit(1);
	co->a = degree_to_radian(in_co->a);
	co->cos = cos(co->a);
	co->sin = sin(co->a);
	co->cos2 = co->cos * co->cos;
	co->sin2 = 1 - co->cos2;
	co->h = in_co->h;
	co->r = co->h * (co->sin / co->cos);
	co->p = in_co->org;
	co->n = vunit(in_co->org_vec);
	co->flip_n = vflip(co->n);
	co->t = vplus(co->p, vmult(co->n, co->h));
	co->texture = in_co->texture;
	co->bumpmap = malloc(sizeof(t_bumpmap));
	if (co->bumpmap == NULL)
		exit(1);
	if (in_co->bp)
		get_cone_bmp(&co, in_co, mlx_ptr);
	return (co);
}
