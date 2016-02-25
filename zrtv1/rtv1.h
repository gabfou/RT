/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:25:40 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:25:42 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RTV1_H
# define RTV1_H
# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

# define L_SIZE		960
# define H_SIZE		960
# define L_RES		480
# define H_RES		480

# define SCR_L		1
# define SCR_H		1
# define SCR_DIST	2
# define L_IND		SCR_L / L_RES
# define H_IND		SCR_H / H_RES

typedef	struct		s_color
{
	double				r;
	double				g;
	double				b;
}					t_color;

typedef	struct		s_mat
{
	char			*name;
	t_color			*spec;
	t_color			*diff;
	t_color			*amb;
	t_color			*selfi;
	float			shiny;
	float			shinystr;
	float			trans;
	float			ref;
}					t_mat;

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef	struct		s_sphere
{
	t_vec			*c;
	double			ray;
}					t_sphere;

typedef	struct		s_cyl
{
	t_vec			*pos;
	t_vec			*dir;
	double			ray;
}					t_cyl;

typedef	struct		s_con
{
	t_vec			*pos;
	t_vec			*dir;
	double			ang;
}					t_con;

typedef	struct		s_light
{
	t_vec			*pos;
	unsigned int	color;
	struct s_light	*next;
}					t_light;

typedef	struct		s_pd
{
	t_vec			*pos;
	t_vec			*dir;
}					t_pd;

typedef	struct		s_item
{
	t_sphere		*sp;
	t_pd			*pl;
	t_cyl			*cyl;
	t_con			*con;
	t_mat			*mat;
	struct s_item	*next;
}					t_item;

typedef	struct		s_check
{
	int				item;
	int				cam;
	int				light;
}					t_check;

typedef	struct		s_inter
{
	double			t;
	t_vec			*norm;
	t_vec			*pos;
}					t_inter;

typedef	struct		s_screen
{
	t_vec			*upleft;
}					t_screen;

typedef	struct		s_cam
{
	t_vec			*pos;
	t_vec			*dir;
	t_vec			*up;
	t_vec			*right;
	double			angle;
}					t_cam;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	void			*image;
	char			*img;
	int				**t;
	int				bpp;
	int				endiant;
	int				sline;

	t_cam			*cam;
	t_screen		*screen;
	t_item			*item;
	t_light			*light;
	t_inter			*inter;
	unsigned int	fcolor;
	int				done;
}					t_env;

void			recuperator(t_env *e, char *name);
void			mega_initiator(t_env *e, char *name);
void			pixel_to_image(t_env *s, int x, int y, unsigned int color);
int				expose_hook(t_env *env);
int				key_down_hook(int keycode, t_env *env);
int				main(int argc, char **argv);
t_pd			*new_t_pd();
t_color			*new_t_color(double r, double g, double b);
t_mat			*new_t_mat(char *name);
t_pd			*t_plane_creator(double x, double y, double z, double dx, double dy, double dz);
t_sphere		*new_t_sphere(double x, double y, double z, double r);
unsigned int	get_color(int r, int g, int b);
t_light			*new_t_light();
t_vec			*new_t_vec(double x, double y, double z);
void			creator(t_env *env);
t_inter			*new_t_inter();
double			carre(double x);
void			set_inter_pos(t_inter *inter, t_pd *pd);
int				check_t(t_inter *inter, double t);
void			check_sphere(t_item *item, t_pd *s, t_inter *inter);
void			check_plane(t_item *item, t_pd *s, t_inter *inter);
void			normalizator(t_vec *vec);
t_vec			*normalizator_ret(t_vec *vec);
double			ft_fatoi(char *s);
void			impactor(t_env *env, t_pd *pd, t_inter *inter);
void			luminator(t_env *e);
t_light			*fill_t_light(char **t, t_light *light);
void			print_vec(t_vec *vec);
void			ft_puttab(char **tab);
t_vec			*prod_vector(t_vec *v1, t_vec *v2);
t_cyl			*t_cyl_creator(double x, double y, double z, double x1, double y1, double z1, double ray);
t_con			*t_con_creator(double x, double y, double z, double x1, double y1, double z1, double ang);
t_vec			*sub_vec(t_vec *v1, t_vec *v2);
double			dot_prod(t_vec *v1, t_vec *v2);
double			ft_min(double a, double b);
t_vec			*vec_mult(t_vec *v1, double x);
t_vec			*vector_proj_vector(t_vec *v1, t_vec *v2);
void			check_con(t_con *con, t_pd *s, t_inter *inter);
void			loadator(int h, int l, t_env *e, int nb);

#endif
