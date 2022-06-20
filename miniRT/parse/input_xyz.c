/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_xyz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:38:07 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:39:47 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

static void	input_bp(int fd, char ***bp, char *buf)
{
	char	*str;
	int		len;

	*bp = malloc_array(sizeof(char *), 2);
	str = read_to_str(fd, buf, 1);
	(*bp)[0] = str;
	len = ft_strlen(str);
	if (ft_strcmp(str + len - 4, ".xpm") != 0)
		print_error("Wrong input: xpm format error\n");
	str = read_to_str(fd, buf, 1);
	(*bp)[1] = str;
	len = ft_strlen(str);
	if (ft_strcmp(str + len - 4, ".xpm") != 0)
		print_error("Wrong input: xpm format error\n");
}

void	input_color3(int fd, t_color3 *rgb, char ***bp, char *buf)
{
	char	*str;

	if (bp != NULL)
		*bp = NULL;
	str = read_to_str(fd, buf, 0);
	if (ft_strcmp(str, "rgb") == 0)
	{
		free(str);
		str = read_to_str(fd, buf, 0);
		rgb->x = (unsigned char)stoi_rgb(str) / 255.999;
		free(str);
		str = read_to_str(fd, buf, 0);
		rgb->y = (unsigned char)stoi_rgb(str) / 255.999;
		free(str);
		str = read_to_str(fd, buf, 0);
		rgb->z = (unsigned char)stoi_rgb(str) / 255.999;
		free(str);
		return ;
	}
	else if (ft_strcmp(str, "bp") != 0 || bp == NULL)
		print_error("Wrong input: color word\n");
	free(str);
	ft_memset(rgb, sizeof(t_color3), 0);
	input_bp(fd, bp, buf);
}

void	input_xyz(int fd, t_point3 *org, char *buf)
{
	org->x = make_float(fd, buf);
	org->y = make_float(fd, buf);
	org->z = make_float(fd, buf);
}

void	input_vec(int fd, t_vec3 *vec, char *buf)
{
	vec->x = make_float(fd, buf);
	if (vec->x < -1.0 || vec->x > 1.0)
		print_error("Wrong input: vec range\n");
	vec->y = make_float(fd, buf);
	if (vec->y < -1.0 || vec->y > 1.0)
		print_error("Wrong input: vec range\n");
	vec->z = make_float(fd, buf);
	if (vec->z < -1.0 || vec->z > 1.0)
		print_error("Wrong input: vec range\n");
}
