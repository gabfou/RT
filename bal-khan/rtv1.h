/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTV1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:02:41 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 20:03:01 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include <math.h>
# include <time.h>

typedef struct	s_point3d
{
	double	x;
	double	y;
	double	z;

}				t_point3d;

typedef struct	s_vect3d
{
	double	x;
	double	y;
	double	z;
	int		inter;
	double	t;
}				t_vect3d;

typedef struct	s_ray
{
	t_vect3d	direct;
	t_vect3d	origin;
}				t_ray;

typedef struct	s_list
{
	char			type;
	struct s_list	*prev;
	struct s_list	*next;
	t_vect3d		center;
	t_vect3d		orient;
	double			radiangle;
}				t_list;

typedef struct	s_torus
{
	t_vect3d	center;
	t_vect3d	axis;
	double		torus_r;
	double		circl_r;
}				t_torus;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bbp;
	int				bbbp;
	int				size_line;
	int				endian;
	t_vect3d		cam;
	t_vect3d		cam_dir;
	t_vect3d		cam_up;
	t_vect3d		cam_right;
	double			cam_angle;
	t_vect3d		upleft;
	t_list			*lights;
	t_list			*list;
	t_ray			ray;
	t_point3d		p;
	t_vect3d		dist;
	int				s_x;
	int				s_y;
	unsigned long	color;
}				t_env;

t_list			*get_nearest(t_env	*e, unsigned long *color);
t_vect3d		inter_point(t_list *list, t_ray ray, t_env *e);
unsigned long	colorizator(t_list *ret, t_vect3d inter, t_env *e);
void			color_divide_two(unsigned long *color);
void			parsor(char *line, t_list **ret);
t_list			*node_constructor(char *line);
t_list			*recur_list_build(int fd, t_list *prev);
int				ft_array_len(char **des_ints);
void			fill_with_tab(char **des_ints, t_list **ret);
t_list			*recur_lights_build(int fd, t_list *prev);
void			encounter_item(t_env *e, t_vect3d inter, t_list *ret,\
				unsigned long *color);
t_vect3d		new_vector(t_vect3d origin, t_vect3d destination);
double			vector_len(t_vect3d vector);
double			dot_product(t_vect3d vector1, t_vect3d vector2);
t_vect3d		dot_vector(t_vect3d vector1, t_vect3d vector2);
t_vect3d		vector_sub(t_vect3d vector1, t_vect3d vector2);
t_vect3d		cross_product(t_vect3d vector1, t_vect3d vector2);
t_vect3d		vector_x_vector(t_vect3d vector1, t_vect3d vector2);
t_vect3d		vector_mult(t_vect3d vector1, double mult);
t_vect3d		vector_add(t_vect3d vector1, t_vect3d vector2);
t_vect3d		vector_proj_vector(t_vect3d vector1, t_vect3d vector2);
t_vect3d		vector_div_vector(t_vect3d vector1, t_vect3d vector2);
t_vect3d		vector_div(t_vect3d vector1, double a);
t_vect3d		normzor(t_vect3d vector);
double			vector_a_shit(t_vect3d vector);
t_vect3d		normalizator(t_vect3d vector1);
t_vect3d		inter_sphere_point(t_list *sphere, t_ray ray, t_env *e);
t_vect3d		inter_cylinder_point(t_list *cylinder, t_ray ray);
t_vect3d		inter_plane_point(t_list *plane, t_ray ray);
t_vect3d		inter_cone_point(t_list *cone, t_ray ray);
unsigned long	color_at(t_env *e, t_vect3d inter);
unsigned long	color_at_p(t_env *e, t_vect3d inter);
unsigned long	color_at_c(t_env *e, t_vect3d inter);
unsigned long	color_at_cone(t_env *e, t_vect3d inter);
double			moitie_prod(t_vect3d a, t_vect3d b);
double			cubic_root(double x);
double			*big_formula(double a, double b, double c, double d, double e);
void			ft_reducer(t_env *e);
int				key_hook(int key, t_env *e);
void			ft_exit(int ret, t_env *e);
int				draw(t_env *e);
int				expose_hook(t_env *e);
void			put_pix_img(t_env *e, int x, int y, unsigned long color);
t_env			init_mlx(int s_x, int s_y);
void			init_env(t_env *e);
t_vect3d		new_point(double x, double y, double z);
void			set_screen(t_env *e);
void			set_cam(t_env *e);
void			calc_dir(t_env *e, double x, double y);
void			ray_trace(t_env *e);
t_list			*norminator(char *line, t_list *ret);
void			loadator(int h, int l, t_env *e, int nb);

t_torus			torus_creator();
double			resolver_cardan(double p, double q);
double			solve_cardan(double a, double b, double c, double d);
double			solve_quartic(double a, double b, double c, double d, double e);
t_vect3d		inter_spine_in_brine(t_torus *torus, t_ray ray);
#endif
