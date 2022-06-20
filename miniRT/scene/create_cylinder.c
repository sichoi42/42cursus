/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:23:40 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:23:09 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parsing.h"
#include "utils.h"
#include "init.h"
#include <stdlib.h>
#include <fcntl.h>

void	get_cylinder_bmp(t_cylinder **cy, t_in_cylinder *in_cy, void *mlx_ptr)
{
	int	fd[2];

	fd[0] = open(in_cy->bp[0], O_RDONLY);
	fd[1] = open(in_cy->bp[1], O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0)
		print_error("no such file\n");
	close_fds(fd);
	(*cy)->texture = BUMP_MAP;
	(*cy)->bumpmap->texture_img = get_xpm_img(in_cy->bp[0], mlx_ptr);
	(*cy)->bumpmap->bump_img = get_xpm_img(in_cy->bp[1], mlx_ptr);
}

t_cylinder	*cylinder(t_in_cylinder *in_cy, void *mlx_ptr)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (cy == NULL)
		exit(1);
	cy->p = in_cy->org;
	cy->normal = vunit(in_cy->org_vec);
	cy->radius = in_cy->r;
	cy->height = in_cy->h;
	cy->tc = vplus(cy->p, vmult(cy->normal, cy->height / 2));
	cy->bc = vplus(cy->p, vmult(cy->normal, -(cy->height) / 2));
	cy->flag = in_cy->flag;
	cy->texture = in_cy->texture;
	cy->bumpmap = malloc(sizeof(t_bumpmap));
	if (cy->bumpmap == NULL)
		exit(1);
	if (in_cy->bp)
		get_cylinder_bmp(&cy, in_cy, mlx_ptr);
	return (cy);
}
