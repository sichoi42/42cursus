/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:10:42 by sichoi            #+#    #+#             */
/*   Updated: 2021/07/23 17:06:36 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define ESC	53
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x00000FF
# define WHITE 0x00FFFFFF
# define BLACK 0
# define KEYPRESS	2
# define KEYRELEASE	3
# define ZOOM_IN	5
# define ZOOM_OUT	4
# define WIDTH		1280
# define HEIGHT		720

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_col
{
	int	red;
	int	green;
	int	blue;
}	t_col;

typedef struct s_fractol
{
	int			(*func)(struct s_fractol *f, int x, int y);
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	int			max_iteration;
	t_col		col;
	int			color_flag;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
}	t_fractol;

/*fractol.c*/
int		check_argv(char *name, char **argv);
void	init(t_fractol *f, char *name, int flag, char **argv);
void	setting_default(t_fractol *f);
void	show_argv_list(void);
/*------------*/
/*key_events.c*/
void	ft_exit(int param);
int		key_press(int key, t_fractol *f);
void	color_channel(int key, t_fractol *f);
void	move(int key, t_fractol *f);
/*-------------*/
/*mouse_events.c*/
int		zoom(int button, int x, int y, t_fractol *f);
void	reset_min_max(t_complex mouse_point, double zoom_rate, t_fractol *f);
/*--------------*/
/*fractol_func.c*/
int		iterating_mandelbrot(t_fractol *f, int x, int y);
int		iterating_julia(t_fractol *f, int x, int y);
int		iterating_burning_ship(t_fractol *f, int x, int y);
/*---------*/
/*palette.c*/
void	choose_color(int iter, t_fractol *f);
/*------*/
/*draw.c*/
void	pixel_put_color(t_fractol *f, int x, int y);
int		put_texture(t_fractol *f);
int		ft_draw(t_fractol *f);
/*----------*/
/*ft_tools.c*/
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
double	string_to_double(const char *s);
double	after_dot(const char *s, double lf);
/*----------*/
/*ft_itoa.c*/
int		len_n(int n);
char	*tr_str(int n, char *s, int len);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);
#endif
