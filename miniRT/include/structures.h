/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:27:00 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:41:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// =============================================================================
// Defined for Express Boolean
// =============================================================================
# define TRUE 1
# define FALSE 0

// =============================================================================
// Defined Default WinSize
// =============================================================================
# define DEFAULT_WINDOW_W 1600
# define DEFAULT_WINDOW_H 900

// =============================================================================
// Defined for Objects Flag
// =============================================================================
# define SP 0
# define PL 1
# define CY 2
# define CO 3
# define POINT_LIGHT 4

// =============================================================================
// Defined for Object Input Type
// =============================================================================
# define BASIC 0
# define HALF 1
# define CY_NO_CAP 1

// =============================================================================
// Defined for Object Texture
// =============================================================================
# define DEFAULT 0
# define CHECKERBOARD 1
# define BUMP_MAP 2

// =============================================================================
// Defined for Calculate Color
// =============================================================================
typedef enum e_color_mask
{
	RED = 16,
	GREEN = 8,
	BLUE = 0,
}	t_color_mask;

// =============================================================================
// Defined for Hit Calulation
// =============================================================================
# define EPSILON 1e-6
# define LUMEN 3

// =============================================================================
// Defined for Mlx Key
// =============================================================================
# define KEYPRESS 2
# define DESTROY 17
# define ESC 53

// =============================================================================
// Typedef Structures
// =============================================================================
typedef int				t_bool;
typedef int				t_obj_type;
typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

// =============================================================================
// Defined for Ray from Camera Eye
// =============================================================================
typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

// =============================================================================
// Define for Camera Info
// t_point3		orig				->	Position of Camera
// double		viewport_h, w		->	Length of Viewport
// double		horizon, vertical	->	hori, verti Vector of Viewport
// t_point3		left_bottom			->	Left Bottom point of Viewport
// t_vec3		dir					->	Direction of Camera Eye
// t_vec3		u, v, w				->	New axises of Camera
// double		fov					->	Vertical Field of View
// =============================================================================
typedef struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	left_bottom;
	t_vec3		dir;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
	double		fov;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

// =============================================================================
// Defined for Image of Mlx
// =============================================================================
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

// =============================================================================
// Defined for Mlx
// =============================================================================
typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
}	t_mlx;

// =============================================================================
// Defined for Input Xpm Images
// =============================================================================
typedef struct s_xpm_image
{
	t_image		img;
	int			width;
	int			height;
}	t_xpm_image;

// =============================================================================
// Defined for Bumpmapping Xpm images
// =============================================================================
typedef struct s_bumpmap
{
	t_xpm_image	*texture_img;
	t_xpm_image	*bump_img;
}	t_bumpmap;

// =============================================================================
// Defined for Objs Info
// =============================================================================
typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
	int			flag;
	int			texture;
	t_bumpmap	*bumpmap;
}	t_sphere;

typedef struct s_plane
{
	t_point3	p;
	t_vec3		normal;
	int			texture;
	t_bumpmap	*bumpmap;
}	t_plane;

typedef struct s_cylinder
{
	t_point3	p;
	t_vec3		normal;
	double		radius;
	double		height;
	t_vec3		op;
	t_vec3		tc;
	t_vec3		bc;
	int			flag;
	int			texture;
	t_bumpmap	*bumpmap;
}	t_cylinder;

typedef struct s_cone
{
	double		a;
	double		h;
	double		r;
	double		cos;
	double		sin;
	double		cos2;
	double		sin2;
	t_point3	p;
	t_vec3		n;
	t_vec3		flip_n;
	t_point3	t;
	double		c1;
	double		c2;
	int			texture;
	t_bumpmap	*bumpmap;
}	t_cone;

typedef struct s_light
{
	t_point3	orig;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

typedef struct s_obj
{
	t_obj_type		type;
	void			*element;
	t_color3		albedo;
	struct s_obj	*next;
}	t_obj;

// =============================================================================
// Defined for Input Hit Record
// =============================================================================
typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		t_min;
	double		t_max;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
	int			texture;
	double		u;
	double		v;
	t_vec3		u_vec;
	t_vec3		v_vec;
}	t_hit_record;

// =============================================================================
// Defined for input Discrimination of Object Hit
// =============================================================================
typedef struct s_discrim
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrt_d;
}	t_discrim;

// =============================================================================
// Defined for Connecting All Structures
// =============================================================================
typedef struct s_scene
{
	t_mlx			*mlx;
	t_canvas		canvas;
	t_camera		camera;
	t_obj			*objs;
	t_obj			*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

#endif
