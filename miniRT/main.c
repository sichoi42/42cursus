/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:03:21 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:20:44 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "draw.h"
#include <fcntl.h>
#include <unistd.h>

static void	input_check(int argc, char *argv[])
{
	int		len;

	if (argc != 2)
		print_error("Not correct argument\n");
	len = ft_strlen(argv[1]);
	if (ft_strcmp(".rt", argv[1] + len - 3) != 0)
		print_error("Need .rt file\n");
}

static int	file_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error(NULL);
	return (fd);
}

static void	init_input_obj2(int fd, t_in_object *obj, char *buf)
{
	if (*buf == 'W')
		input_window(fd, obj);
	else if (*buf == '#')
		next_line(fd, buf);
	else
		print_error("Wrong input: symbol\n");
}

static void	init_input_obj(int fd, t_in_object *obj)
{
	char	buf;

	ft_memset(obj, sizeof(t_in_object), 0);
	while (1)
	{
		pass_space(fd, &buf, " \t\n");
		if (buf == 'A')
			input_ambient(fd, obj);
		else if (buf == 'C')
			input_camera(fd, obj);
		else if (buf == 'L')
			input_light(fd, obj);
		else if (buf == 's')
			input_sphere(fd, obj, &buf);
		else if (buf == 'p')
			input_plane(fd, obj, &buf);
		else if (buf == 'c')
			input_cylinder(fd, obj, &buf);
		else if (buf == '\0')
			break ;
		else
			init_input_obj2(fd, obj, &buf);
	}
	if (obj->c == NULL || obj->a == NULL)
		print_error("Wrong input: not camera or ambient\n");
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_in_object	in_obj;

	input_check(argc, argv);
	fd = file_open(argv[1]);
	init_input_obj(fd, &in_obj);
	close(fd);
	draw(&in_obj);
	return (0);
}
