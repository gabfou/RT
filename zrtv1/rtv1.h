/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:25:40 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/28 22:36:57 by ibuchwal         ###   ########.fr       */
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

# define L_SIZEC	400
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
# define FLOAT_SIZE double

typedef	struct		s_color
{
	FLOAT_SIZE		r;
	FLOAT_SIZE		g;
	FLOAT_SIZE		b;
}					t_color;

typedef	struct		s_mat
{
	char			*name;
	t_color			spec;
	t_color			diff;
	t_color			amb;
	t_color			selfi;
	FLOAT_SIZE		shiny;
	FLOAT_SIZE		shinystr;
	FLOAT_SIZE		trans;
	FLOAT_SIZE		ref;
}					t_mat;

typedef	struct		s_vec
{
	FLOAT_SIZE		x;
	FLOAT_SIZE		y;
	FLOAT_SIZE		z;
}					t_vec;

typedef	struct		s_sphere
{
	t_vec			c;
	FLOAT_SIZE		ray;
}					t_sphere;

typedef	struct		s_cyl
{
	t_vec			pos;
	t_vec			dir;
	FLOAT_SIZE		ray;
}					t_cyl;

typedef	struct		s_con
{
	t_vec			pos;
	t_vec			dir;
	FLOAT_SIZE		ang;
}					t_con;

typedef	struct		s_light
{
	t_vec			pos;
	unsigned int	color;
	struct s_light	*next;
}					t_light;

typedef	struct		s_pd
{
	t_vec			pos;
	t_vec			dir;
	FLOAT_SIZE		ray;
}					t_pd;

typedef	struct		s_item
{
	t_sphere		*sp;
	t_pd			*pl;
	t_cyl			*cyl;
	t_con			*con;
	t_mat			mat;
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
	FLOAT_SIZE		colabs;
	FLOAT_SIZE		t;
	struct		s_trans			*next;
}					t_trans;

typedef	struct		s_inter
{
	double			t;
	t_vec			norm;
	t_vec			pos;
	t_trans			*trans;
	t_color			diff;
	FLOAT_SIZE		ref;
}					t_inter;

// typedef	struct		s_screen
// {
// 	t_vec			upleft;
// }					t_screen;

// typedef	struct		s_cam
// {
// 	t_vec			pos;
// 	t_vec			dir;
// 	t_vec			up;
// 	t_vec			right;
// 	FLOAT_SIZE			angle;
// }					t_cam;

// typedef	struct		s_thr
// {
// 	FLOAT_SIZE			minx;
// 	FLOAT_SIZE			maxx;
// 	FLOAT_SIZE			miny;
// 	FLOAT_SIZE			maxy;
// 	unsigned int	fcolor;
// 	t_inter			inter;
// 	t_item			*item;
// 	t_light			*light;
// }				t_thr;

// typedef	struct		s_env
// {
// 	void			*mlx;
// 	void			*win;
// 	void			*image;
// 	char			*img;
// 	int				**t;
// 	int				bpp;
// 	int				endiant;
// 	int				sline;

// 	t_cam			*cam;
// 	t_screen		*screen;
// 	t_item			*item;
// 	t_light			*light;
// 	t_inter			inter;
// 	unsigned int	fcolor;
// 	int				done;
// 	int				l;
// 	int				i;
	
// }					t_env

typedef	struct			s_limg
{
	void			*image;
	char			*img;
	int				bpp;
	int				sline;
	int				i;
	int				l;
	int				k;
	struct	s_limg	*prev;
	struct	s_limg	*next;
}					t_limg;

typedef	struct			s_cam
{
	t_vec			pos;
	t_vec			dir;
	t_vec			up;
	t_vec			right;
	FLOAT_SIZE		angle;
	t_vec			upleft;
	struct	s_cam	*next;
	// struct	s_cam	*prev;
}					t_cam;

typedef	struct		s_env
{
	void			*image;
	int				**t;
	int				endiant;
	t_limg			*limg;

	t_cam			*cam;
	t_item			*item;
	t_light			*light;
	t_inter			inter;
	unsigned int	fcolor;
	int				done;
	int				nbr;
	int				ft;
	int				mircount;
	struct	s_env	*prev;
	struct	s_env	*next;
}					t_env;

typedef	struct		s_thr
{
	t_env			*env;
	FLOAT_SIZE		minx;
	FLOAT_SIZE		maxx;
	FLOAT_SIZE		miny;
	FLOAT_SIZE		maxy;
	int				done;
	unsigned int	fcolor;
	t_inter			inter;
	t_inter			liginter;
	t_item			*item;
	t_light			*light;
	t_limg			*limg;
	t_cam			*cam;
}					t_thr;

typedef struct		s_cor
{
	int				minx;
	int				maxx;
	int				miny;
	int				maxy;
	t_env			*env;
}					t_cor;

typedef	struct		s_leviatenv
{
	void			*mlx;
	void			*win;
	t_env			*lenv;
}					t_leviatenv;

void			recuperator(t_env *e, char *name);
// void			mega_initiator(t_env *e, char *name);
//void			pixel_to_image(t_env *s, int x, int y, unsigned int color);
void			pixel_to_image(int x, int y, unsigned int color , t_limg *limg);

int				expose_hook(t_leviatenv *levia);

int				key_down_hook(int keycode, t_leviatenv *levia);

int				main(int argc, char **argv);
t_pd			*new_t_pd();
t_color			new_t_color(FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b);
t_mat			new_t_mat(char *name);
t_pd			*t_plane_creator(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z, FLOAT_SIZE dx, FLOAT_SIZE dy, FLOAT_SIZE dz, FLOAT_SIZE ray);
t_sphere		*new_t_sphere(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z, FLOAT_SIZE r);
unsigned int	get_color(const int r, const int g, const int b);
t_light			*new_t_light();
t_vec			new_t_vec(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z);
void			creator(t_cor *c);
t_inter			new_t_inter();
FLOAT_SIZE		carre(FLOAT_SIZE x);
void			set_inter_pos(t_inter *inter, t_pd *pd);
int				itemadator(t_env *env, t_item *item);
t_item			*new_t_item();
t_cam			*new_t_cam();

int				check_t(t_inter *inter, FLOAT_SIZE t, FLOAT_SIZE trans, t_item *item);

void			check_sphere(t_item *item, t_pd *s, t_inter *inter);
void			check_plane(t_item *item, t_pd *s, t_inter *inter);
void			normalizator(t_vec *vec);
t_vec			normalizator_ret(t_vec vec);
FLOAT_SIZE		ft_fatoi(char *s);

void			impactor(t_env *env, t_pd *pd, t_thr *f, t_inter *inter);

void			luminator(t_env *e, t_thr *f);

t_light			*fill_t_light(char **t, t_light *light);
void			print_vec(t_vec vec);
void			ft_puttab(char **tab);
t_vec			prod_vector(t_vec v1, t_vec v2);
t_cyl			*t_cyl_creator(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z, FLOAT_SIZE x1, FLOAT_SIZE y1, FLOAT_SIZE z1, FLOAT_SIZE ray);
t_con			*t_con_creator(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z, FLOAT_SIZE x1, FLOAT_SIZE y1, FLOAT_SIZE z1, FLOAT_SIZE ang);
t_vec			sub_vec(t_vec v1, t_vec v2);
t_vec			add_vec(t_vec v1, t_vec v2);
FLOAT_SIZE		dot_prod(t_vec v1, t_vec v2);
FLOAT_SIZE		ft_min(FLOAT_SIZE a, FLOAT_SIZE b);
t_vec			vec_mult(t_vec v1, FLOAT_SIZE x);
t_vec			vector_proj_vector(t_vec v1, t_vec v2);

void			check_con(t_item *item, t_pd *s, t_inter *inter);

void			loadator(int h, int l, t_leviatenv *e, int nb);
void			antialiasing(t_env *s);
FLOAT_SIZE		get_dist(t_vec v1, t_vec v2);
t_vec			set_new_pos(t_vec dir, t_vec pos, FLOAT_SIZE dist);

void			check_cyl(t_item *item, t_pd *s, t_inter *inter);

void			readerbmp32(char *name, t_leviatenv *e);
void			enregistrator(t_env *env);
int				thread_master(t_env *env);

t_trans			*new_t_trans(FLOAT_SIZE t, FLOAT_SIZE colabs);
FLOAT_SIZE		transparencator(unsigned int color, FLOAT_SIZE trans);
FLOAT_SIZE		trans_calculator(t_trans *trans, FLOAT_SIZE	t);

int				tlen(char **tab);

void			print_params(t_env env);
int				parse_exp(t_list **tokens, t_env *par);
void			init(t_env *env, int argc, char *argv);
void			init_env(t_leviatenv *env);
//t_screen		*set_screen(t_cam *cam);

char			keytochar(int key);
void			comander(int key, t_leviatenv *env);
int				new_sphere(t_env *env);
void			modif_item(t_env *env, int i, char **split);
void			*imgcptor(t_env *env);
void			*printmusicator(t_limg *addr, t_env *env);

t_limg          *new_t_limg(t_leviatenv *env);
void			print_tokens(t_list *tokens);
int				access_file(int argc, char *argv);
t_list			*get_tokens(int fd);
void			delete_symbols(t_list **tokens);
FLOAT_SIZE		token_to_float(t_list **tokens);
void			t_inter_set(t_inter *inter);
void			t_limg_initator(t_leviatenv *levia);
t_vec			set_screen(t_cam *cam);
void			initmat(t_list	**tokens, t_item *item);
int				get_t_cam_lenght(t_cam *cam);
void			init_env(t_leviatenv *levia);
void			ref(t_thr *f, t_cor *c, t_pd *pd);

void			init_sphere(t_env *env, t_list **tokens);
void			init_plane(t_env *env, t_list **tokens);
void			init_cone(t_env *env, t_list **tokens);
void			init_cyl(t_env *env, t_list **tokens);
void			init_camera(t_env *env, t_list **tokens);
void			init_light(t_env *env, t_list **tokens);


#endif
