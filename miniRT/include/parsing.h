/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:48:31 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:49:12 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "structures.h"

# define OVER_LONG_NUM 9223372036854775808UL
# define OVER_INT_NUM 2147483648
# define MAX_PRECISION 1000000000UL
# define STR_SIZE 512;

typedef struct s_in_window {
	int	width;
	int	height;
}	t_in_window;

/* ==================================================================
 * ratio [0.0, 1.0]
 * rgb [0, 255]
 * ================================================================== */
typedef struct s_in_ambient {
	double		ratio;
	t_color3	rgb;
}	t_in_ambient;

/* ==================================================================
 * org_vec [-1, 1]
 * fov (0, 180)
 * ================================================================== */
typedef struct s_in_camera {
	t_point3	org;
	t_vec3		org_vec;
	double		fov;
}	t_in_camera;

/* ==================================================================
 * ratio [0.0, 1.0]
 * rgb [0, 255]
 * ================================================================== */
typedef struct s_in_light {
	t_point3	org;
	double		ratio;
	t_color3	rgb;
}	t_in_light;

/* ==================================================================
 * rgb [0, 255]
 * flag (0:basic, 1:half)
 * ================================================================== */
typedef struct s_in_sphere {
	t_point3	org;
	double		r;
	t_color3	rgb;
	int			flag;
	int			texture;
	char		**bp;
}	t_in_sphere;

/* ==================================================================
 * org_vec [-1, 1]
 * rgb [0, 255]
 * ================================================================== */
typedef struct s_in_plane {
	t_point3	org;
	t_vec3		org_vec;
	t_color3	rgb;
	int			texture;
	char		**bp;
}	t_in_plane;

/* ==================================================================
 * org_vec [-1, 1]
 * rgb [0, 255]
 * flag (0:basic, 1:half)
 * ================================================================== */
typedef struct s_in_cylinder {
	t_point3	org;
	t_vec3		org_vec;
	double		r;
	double		h;
	t_color3	rgb;
	int			flag;
	int			texture;
	char		**bp;
}	t_in_cylinder;

/* ==================================================================
 * org_vec [-1, 1]
 * a (0.0, 90.0)
 * rgb [0, 255]
 * ================================================================== */
typedef struct s_in_cone {
	t_point3	org;
	t_vec3		org_vec;
	double		h;
	double		a;
	t_color3	rgb;
	int			texture;
	char		**bp;
}	t_in_cone;

typedef struct s_in_object {
	t_in_window		*w;
	t_in_ambient	*a;
	t_in_camera		*c;
	t_in_light		*l;
	t_in_sphere		*sp;
	t_in_plane		*pl;
	t_in_cylinder	*cy;
	t_in_cone		*co;
	int				l_size;
	int				sp_size;
	int				pl_size;
	int				cy_size;
	int				co_size;
}	t_in_object;

/* base */
void				ft_memset(void *target, unsigned int size, int input);
void				print_error(char *message);
int					ft_strlen(char *s);
int					ft_strcmp(char *l, char *r);
void				*malloc_array(int size, int len);
void				*ft_realloc(void *ptr, int ptr_size, int new_size);
int					ft_read(int fd, char *buf, int size);
unsigned long long	stof_front(char *str);
unsigned long long	stof_behind(char *str);
int					stoi_rgb(char *str);
int					ft_stoi(char *str);

/* parse */
void				next_line(int fd, char *buf);

void				check_half(int fd, char *buf, int *flag);
void				check_texture(int fd, char *buf, int *texture);

double				input_ratio(int fd, char *buf);
void				input_ambient(int fd, t_in_object *obj);
void				input_camera(int fd, t_in_object *obj);
void				input_light(int fd, t_in_object *obj);

void				input_sphere(int fd, t_in_object *obj, char *buf);
void				input_plane(int fd, t_in_object *obj, char *buf);
void				input_cone(int fd, t_in_object *obj, char *buf);
void				input_cylinder(int fd, t_in_object *obj, char *buf);
void				input_window(int fd, t_in_object *obj);

void				pass_space(int fd, char *buf, char *space);
char				*read_to_str(int fd, char *buf, int no_ck);
double				make_float(int fd, char *buf);

void				input_color3(int fd, t_color3 *rgb, char ***bp, char *buf);
void				input_xyz(int fd, t_point3 *org, char *buf);
void				input_vec(int fd, t_vec3 *vec, char *buf);

#endif
