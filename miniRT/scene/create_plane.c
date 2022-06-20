/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:22:09 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:23:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parsing.h"
#include "utils.h"
#include "init.h"
#include <stdlib.h>
#include <fcntl.h>

void	get_plane_bmp(t_plane **pl, t_in_plane *in_pl, void *mlx_ptr)
{
	int	fd[2];

	fd[0] = open(in_pl->bp[0], O_RDONLY);
	fd[1] = open(in_pl->bp[1], O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0)
		print_error("no such file\n");
	close_fds(fd);
	(*pl)->texture = BUMP_MAP;
	(*pl)->bumpmap->texture_img = get_xpm_img(in_pl->bp[0], mlx_ptr);
	(*pl)->bumpmap->bump_img = get_xpm_img(in_pl->bp[1], mlx_ptr);
}

t_plane	*plane(t_in_plane *in_pl, void *mlx_ptr)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (pl == NULL)
		exit(1);
	pl->p = in_pl->org;
	pl->normal = vunit(in_pl->org_vec);
	pl->texture = in_pl->texture;
	pl->bumpmap = malloc(sizeof(t_bumpmap));
	if (pl->bumpmap == NULL)
		exit(1);
	if (in_pl->bp)
		get_plane_bmp(&pl, in_pl, mlx_ptr);
	return (pl);
}
