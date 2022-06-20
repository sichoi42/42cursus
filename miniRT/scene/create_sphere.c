/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:19:26 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:23:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parsing.h"
#include "utils.h"
#include "init.h"
#include <stdlib.h>
#include <fcntl.h>

void	get_sphere_bmp(t_sphere **sp, t_in_sphere *in_sp, void *mlx_ptr)
{
	int	fd[2];

	fd[0] = open(in_sp->bp[0], O_RDONLY);
	fd[1] = open(in_sp->bp[1], O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0)
		print_error("no such file\n");
	close_fds(fd);
	(*sp)->texture = BUMP_MAP;
	(*sp)->bumpmap->texture_img = get_xpm_img(in_sp->bp[0], mlx_ptr);
	(*sp)->bumpmap->bump_img = get_xpm_img(in_sp->bp[1], mlx_ptr);
}

t_sphere	*sphere(t_in_sphere *in_sp, void *mlx_ptr)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	if (sp == NULL)
		exit(1);
	sp->center = in_sp->org;
	sp->radius = in_sp->r;
	sp->radius2 = sp->radius * sp->radius;
	sp->flag = in_sp->flag;
	sp->texture = in_sp->texture;
	sp->bumpmap = malloc(sizeof(t_bumpmap));
	if (sp->bumpmap == NULL)
		exit(1);
	if (in_sp->bp)
		get_sphere_bmp(&sp, in_sp, mlx_ptr);
	return (sp);
}
