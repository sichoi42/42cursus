/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:00:46 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 20:22:47 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;
	int			flag;

	if (argc > 1)
		flag = check_argv(argv[1], argv);
	if (argc >= 2 && flag > 0)
	{
		init(&f, argv[1], flag, argv);
		if (ft_draw(&f) == -1)
			ft_exit(1);
		mlx_hook(f.mlx_win, KEYPRESS, 0, key_press, &f);
		mlx_hook(f.mlx_win, 17, 0, ft_exit, 0);
		mlx_mouse_hook(f.mlx_win, zoom, &f);
		mlx_loop(f.mlx);
	}
	else
		show_argv_list();
	return (0);
}

int	check_argv(char *name, char **argv)
{
	if (ft_strncmp(name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
		return (1);
	else if (ft_strncmp(name, "julia", ft_strlen("julia")) == 0)
	{
		if (argv[2] == 0 || argv[3] == 0)
		{
			printf("Input C value by giving parameter.\n");
			return (0);
		}
		return (2);
	}
	else if (ft_strncmp(name, "burning_ship", ft_strlen("burning_ship")) == 0)
		return (3);
	return (0);
}

void	init(t_fractol *f, char *name, int flag, char **argv)
{
	f->mlx = mlx_init();
	f->mlx_win = mlx_new_window(f->mlx, WIDTH, HEIGHT, name);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
	setting_default(f);
	if (flag == 1)
		f->func = iterating_mandelbrot;
	else if (flag == 2)
	{
		f->c.re = string_to_double(argv[2]);
		f->c.im = string_to_double(argv[3]);
		f->func = iterating_julia;
	}
	else if (flag == 3)
		f->func = iterating_burning_ship;
}

void	setting_default(t_fractol *f)
{
	f->max_iteration = 50;
	f->min.re = -2.5;
	f->max.re = 1.0;
	f->min.im = -1.0;
	f->max.im = 1.0;
	f->zoom = 1.0;
	f->color_flag = 1;
}

void	show_argv_list(void)
{
	printf("Fractal list what can you see\n");
	printf("-----------------------------\n");
	printf("mandelbrot\n");
	printf("julia(You need to give parameter, ex) julia -0.79 0.15)\n");
	printf("burning_ship\n");
	printf("-----------------------------\n");
}
