/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:25:40 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/09 20:54:57 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RTV1_H
# define RTV1_H
# include <mlx.h>
# include "libft/libft.h"
# include "parser.h"
// # include "libft/get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>

# define L_SIZE		960
# define H_SIZE		960
# define L_RES		480
# define H_RES		480

# define SCR_L		1
# define SCR_H		1
# define SCR_DIST	2
# define L_IND		SCR_L / L_RES
# define H_IND		SCR_H / H_RES
# define NBTHREAD	4

typedef	struct		s_color
{
	float				r;
	float				g;
	float				b;
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
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef	struct		s_sphere
{
	t_vec			*c;
	float			ray;
}					t_sphere;

typedef	struct		s_cyl
{
	t_vec			*pos;
	t_vec			*dir;
	float			ray;
}					t_cyl;

typedef	struct		s_con
{
	t_vec			*pos;
	t_vec			*dir;
	float			ang;
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

typedef struct		s_trans
{
	float			colabs;
	float			t;
	struct		s_trans			*next;
}					t_trans;

typedef	struct		s_inter
{
	float			t;
	t_vec			*norm;
	t_vec			*pos;
	t_trans			*trans;
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
	float			angle;
}					t_cam;

typedef	struct		s_thr
{
	float			minx;
	float			maxx;
	float			miny;
	float			maxy;
	unsigned int	fcolor;
	t_inter			*inter;
	t_item			*item;
	t_light			*light;
}					t_thr;

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
	int				l;
	int				i;
	
}					t_env;

typedef struct		s_cor
{
	int				minx;
	int				maxx;
	int				miny;
	int				maxy;
	t_env			*env;
}					t_cor;

void			recuperator(t_env *e, char *name);
void			mega_initiator(t_env *e, char *name);
void			pixel_to_image(t_env *s, int x, int y, unsigned int color);
int				expose_hook(t_env *env);
int				key_down_hook(int keycode, t_env *env);
int				main(int argc, char **argv);
t_pd			*new_t_pd();
t_color			*new_t_color(float r, float g, float b);
t_mat			*new_t_mat(char *name);
t_pd			*t_plane_creator(float x, float y, float z, float dx, float dy, float dz);
t_sphere		*new_t_sphere(float x, float y, float z, float r);
unsigned int	get_color(int r, int g, int b);
t_light			*new_t_light();
t_vec			*new_t_vec(float x, float y, float z);
void			creator(t_cor *c);
t_inter			*new_t_inter();
float			carre(float x);
void			set_inter_pos(t_inter *inter, t_pd *pd);

int				check_t(t_inter *inter, float t, float trans);

void			check_sphere(t_item *item, t_pd *s, t_inter *inter);
void			check_plane(t_item *item, t_pd *s, t_inter *inter);
void			normalizator(t_vec *vec);
t_vec			*normalizator_ret(t_vec *vec);
float			ft_fatoi(char *s);

void			impactor(t_env *env, t_pd *pd, t_thr *f, t_inter *inter);

void			luminator(t_env *e, t_thr *f);

t_light			*fill_t_light(char **t, t_light *light);
void			print_vec(t_vec *vec);
void			ft_puttab(char **tab);
t_vec			*prod_vector(t_vec *v1, t_vec *v2);
t_cyl			*t_cyl_creator(float x, float y, float z, float x1, float y1, float z1, float ray);
t_con			*t_con_creator(float x, float y, float z, float x1, float y1, float z1, float ang);
t_vec			*sub_vec(t_vec *v1, t_vec *v2);
t_vec			*add_vec(t_vec *v1, t_vec *v2);
float			dot_prod(t_vec *v1, t_vec *v2);
float			ft_min(float a, float b);
t_vec			*vec_mult(t_vec *v1, float x);
t_vec			*vector_proj_vector(t_vec *v1, t_vec *v2);

void			check_con(t_item *item, t_pd *s, t_inter *inter);

void			loadator(int h, int l, t_env *e, int nb);
void			antialiasing(t_env *s);
float			get_dist(t_vec *v1, t_vec *v2);
t_vec			*set_new_pos(t_vec *dir, t_vec *pos, float dist);

void			check_cyl(t_item *item, t_pd *s, t_inter *inter);

void			enregistrator(t_env *env);
int				thread_master(t_env *env);

t_trans			*new_t_trans(float t, float colabs);
float			transparencator(unsigned int color, float trans);
float			trans_calculator(t_trans *trans, float	t);
#endif
