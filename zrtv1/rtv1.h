/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:25:40 by jromagna          #+#    #+#             */
/*   Updated: 2016/04/06 23:32:23 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include "libft/libft.h"
# include "parser.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>
# include <time.h>
# include <OpenCL/opencl.h>
# include <dlfcn.h>
# include "fmod/inc/fmod.h"
# include "fmod/inc/fmod_codec.h"
# include "fmod/inc/fmod_dsp.h"
# include "fmod/inc/fmod_errors.h"
# include "fmod/inc/fmod_common.h"
# include "fmod/inc/fmod_dsp_effects.h"
# include "fmod/inc/fmod_output.h"
# include <OpenCL/opencl.h>
// # include "norme.h"

# define L_SIZEC	400
# define L_SIZE		960
# define H_SIZE		960
# define L_RES		480
# define H_RES		480

# define SCR_L		1
# define SCR_H		1
# define SCR_DIST	2
# define NBTHREAD	4
# define FLOAT_SIZE double
# define B 0xFFFFFF
# define NB_CARRE 20000

# define AIR_INCI 1
# define GLASS_INCI 1.51

# define MAPPING 0.2
# define PHOTOSTACK 10
# define COLORSTACK 50


typedef	struct		s_color
{
	FLOAT_SIZE		r;
	FLOAT_SIZE		g;
	FLOAT_SIZE		b;
}					t_color;

typedef	struct		s_vec
{
	FLOAT_SIZE		x;
	FLOAT_SIZE		y;
	FLOAT_SIZE		z;
}					t_vec;

typedef	struct		s_mat
{
	char			*name;
	t_color			specular;
	t_color			diff;
	t_color			ambiant;
	t_color			selfillum;

	FLOAT_SIZE		shiny;
	FLOAT_SIZE		shinystr;

	FLOAT_SIZE		trans;
	FLOAT_SIZE		coefref;
	FLOAT_SIZE		coeftrans;
	FLOAT_SIZE		coefdiffuse;

	FLOAT_SIZE		ref;
	FLOAT_SIZE		idr;

	t_vec			min;
	t_vec			max;
}					t_mat;

typedef	struct		s_phcol
{
	t_color			color;
	FLOAT_SIZE		dist;
	struct s_phcol	*next;
}					t_phcol;

typedef	struct		s_sphere
{
	t_vec			c;
	FLOAT_SIZE		ray;
}					t_sphere;

typedef struct		s_triangle
{
	t_vec			p1;
	t_vec			p2;
	t_vec			p3;
	t_vec			u;
	t_vec			v;
	FLOAT_SIZE		d;
	FLOAT_SIZE		uu;
	FLOAT_SIZE		uv;
	FLOAT_SIZE		vv;
	t_vec			n;
}					t_triangle;

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
	t_color			rcolor;
	int				photon;
	struct s_light	*next;
}					t_light;

typedef	struct		s_pd
{
	t_vec			pos;
	t_vec			dir;
	FLOAT_SIZE		ray;
}					t_pd;

typedef	struct		s_cam
{
	t_vec			pos;
	t_vec			dir;
	t_vec			up;
	t_vec			right;
	FLOAT_SIZE		angle;
	t_vec			upleft;
	int				zebre;
	int				rfu;
	struct s_cam	*next;
}					t_cam;

typedef	struct		s_limg
{
	void			*image;
	char			*img;
	int				bpp;
	int				sline;
	int				i;
	int				l;
	int				k;
	t_cam			*cam;
	struct s_limg	*prev;
	struct s_limg	*next;
}					t_limg;

typedef	struct	s_item	t_item;

typedef	struct		s_obj
{
	t_item			*tr;
}					t_obj;

typedef	struct		s_item
{
	t_sphere		*sp;
	t_pd			*pl;
	t_cyl			*cyl;
	t_con			*con;
	t_triangle		*tr;
	t_obj			*obj;
	t_mat			mat;
	int				nb;
	struct s_item	*negal;
	int				nega;
	t_limg			*texture;
	struct s_item	*next;
}					t_item;

typedef	struct		s_cnb
{
	t_item			*item;
	struct s_cnb	*next;
}					t_cnb;

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
	struct s_trans	*next;
}					t_trans;

typedef struct		s_proto
{
	t_color			color;
	FLOAT_SIZE		x;
	FLOAT_SIZE		y;
	FLOAT_SIZE		z;
	t_vec			inc;
	struct s_proto	*droite;
	struct s_proto	*gauche;
}					t_proto;

typedef	struct		s_inter
{
	double			t;
	t_vec			norm;
	t_vec			pos;
	FLOAT_SIZE		trans;
	t_color			diff;
	FLOAT_SIZE		ref;
	t_item			*item;
	FLOAT_SIZE		preidr;
	FLOAT_SIZE		postidr;
}					t_inter;

typedef	struct		s_carre
{
	t_cnb			*cnb;
	t_vec			pos;
	t_vec			dir;
	t_vec			up;
	t_vec			right;
	FLOAT_SIZE		angle;
	FLOAT_SIZE		size;
	int				nb_obj;
	struct s_carre	*next;
}					t_carre;

typedef	struct		s_transroi
{
	unsigned int	tmpcolor;
	t_inter			mirinter;
	t_inter			transinter;
	t_pd			mirpd;
	t_pd			transpd;
	unsigned int	mircolor;
	unsigned int	transcolor;
	double			schlick;
	int				i;
	FLOAT_SIZE		nat;
}					t_transroi;

typedef	struct		s_screen
{
	int					h;
	int					l;
	FLOAT_SIZE			scrl;
	FLOAT_SIZE			scrh;
	FLOAT_SIZE			scrd;
	FLOAT_SIZE			li;
	FLOAT_SIZE			hi;
	FLOAT_SIZE			resl;
	FLOAT_SIZE			resh;
	t_color				color;
}					t_screen;

typedef	struct		s_env
{
	void			*image;
	int				**t;
	int				endiant;
	t_limg			*limg;

	t_screen		screen;
	t_cam			*cam;
	t_item			*item;
	t_item			*iteminf;
	t_light			*light;
	t_proto			*prototree;
	t_inter			inter;
	t_trans			*translist;
	t_carre			*carre;
	unsigned int	fcolor;
	int				done;
	int				nbr;
	int				ft;
	int				mircount;
	int				infitem;
	int				nb_obj;
	int				nb_carre;
	t_item			*nega;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

typedef	struct		s_thr
{
	t_env			*env;
	FLOAT_SIZE		minx;
	FLOAT_SIZE		maxx;
	FLOAT_SIZE		miny;
	FLOAT_SIZE		maxy;
	int				done;
	int				impactmod;
	unsigned int	fcolor;
	t_inter			inter;
	t_inter			liginter;
	t_item			*item;
	t_light			*light;
	t_limg			*limg;
	t_cam			*cam;
	t_item			**cnb;
	int				*use;
}					t_thr;

typedef struct		s_cor
{
	int				minx;
	int				maxx;
	int				miny;
	int				maxy;
	t_env			*env;
}					t_cor;

typedef struct		s_lm
{
	char			*name;
	struct s_lm		*next;
	struct s_lm		*previous;
}					t_lm;

typedef struct		s_fmod
{
	void			*handle;
	void			(*System_Create)(FMOD_SYSTEM**);
	void			(*System_Init)(FMOD_SYSTEM*, int, FMOD_INITFLAGS, void*);
	void			(*System_CreateSound)(FMOD_SYSTEM*, const char*, FMOD_MODE, FMOD_CREATESOUNDEXINFO*, FMOD_SOUND**);
	void			(*Sound_SetLoopCount)(FMOD_SOUND *, int);
	void			(*System_PlaySound)(FMOD_SYSTEM*, FMOD_SOUND*, void*, FMOD_BOOL, FMOD_CHANNEL**);
	t_lm			*listmusic;

}					t_fmod;

typedef	struct		s_leviatenv
{
	void			*mlx;
	void			*win;
	t_env			*lenv;
	t_item			*current;
	t_fmod			fmod;
}					t_leviatenv;

void			recuperator(t_env *e, char *name);
void			pixel_to_image(int x, int y,
	unsigned int color, t_limg *limg);

int				expose_hook(t_leviatenv *levia);

int				key_down_hook(int keycode, t_leviatenv *levia);

int				main(int argc, char **argv);
t_pd			*new_t_pd();
t_color			new_t_color(FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b);
t_mat			new_t_mat(char *name);
t_pd			*t_plane_creator(t_vec v, t_vec vd, FLOAT_SIZE ray);
t_sphere		*new_t_sphere(FLOAT_SIZE x, FLOAT_SIZE y,
	FLOAT_SIZE z, FLOAT_SIZE r);
unsigned int	get_color(const int r, const int g, const int b);
t_light			*new_t_light();
t_vec			new_t_vec(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z);
void			creator(t_cor *c);
t_inter			new_t_inter();
FLOAT_SIZE		carre(FLOAT_SIZE x);
void			set_inter_pos(t_inter *inter, t_pd *pd);
void			itemadator(t_env *env, t_item *item);
t_item			*new_t_item(t_env *env);
t_cam			*new_t_cam();
t_screen		new_t_screen();
void			calc_dir(t_vec *dir, FLOAT_SIZE x, FLOAT_SIZE y, t_thr *f);
void			impactoralancienne(t_pd *pd, t_item *item, t_inter *inter);

int				check_t(t_inter *inter, FLOAT_SIZE t,
	t_pd *s, t_item *item);

void			check_sphere(t_item *item, t_pd *s, t_inter *inter, int impactmod);
void			check_plane(t_item *item, t_pd *s, t_inter *inter, int impactmod);
void			normalizator(t_vec *vec);
t_vec			normalizator_ret(t_vec vec);
FLOAT_SIZE		ft_fatoi(char *s);

void			impactor(t_env *env, t_pd *pd, t_thr *f, t_inter *inter);

t_color			luminator(t_thr *f, t_inter *inter);

t_light			*fill_t_light(char **t, t_light *light);
void			print_vec(t_vec vec);
void			ft_puttab(char **tab);
t_vec			prod_vector(t_vec v1, t_vec v2);
t_cyl			*t_cyl_creator(t_vec v, t_vec vd, FLOAT_SIZE ray);
t_con			*t_con_creator(t_vec v, t_vec v1, FLOAT_SIZE ang);
t_vec			sub_vec(const t_vec v1, const t_vec v2);
t_vec			add_vec(const t_vec v1, const t_vec v2);
FLOAT_SIZE		dot_prod(const t_vec v1, const t_vec v2);
FLOAT_SIZE		ft_min(const FLOAT_SIZE a, const FLOAT_SIZE b);
t_vec			vec_mult(const t_vec v1, const FLOAT_SIZE x);
t_vec			vector_proj_vector(const t_vec v1, const t_vec v2);

void			check_con(t_item *item, t_pd *s, t_inter *inter, int impactmod);

void			loadator(int h, int l, t_leviatenv *e, int nb);
void			antialiasing(t_env *s);
FLOAT_SIZE		get_dist(t_vec v1, t_vec v2);
t_vec			set_new_pos(t_vec dir, t_vec pos, FLOAT_SIZE dist);

void			check_cyl(t_item *item, t_pd *s, t_inter *inter, int impactmod);

t_limg			*readerbmp32(char *name);
void			enregistrator(t_env *env);
int				thread_master(t_env *env);

t_trans			*new_t_trans(FLOAT_SIZE t, FLOAT_SIZE colabs);
FLOAT_SIZE		transparencator(unsigned int color, FLOAT_SIZE trans);

int				tlen(char **tab);

void			print_params(t_env env);
int				parse_exp(t_list **tokens, t_env *par);
void			init(t_env *env, int argc, char *argv);
void			init_env(t_leviatenv *env);
void			free_tokens(t_list **tokens);

char			keytochar(int key);
void			comander(int key, t_leviatenv *env);
int				new_sphere(t_env *env);
void			modif_item(t_item *current, char **split);
void			*imgcptor(t_leviatenv *env);
void			*printmusicator(t_limg *addr);

t_limg			*new_t_limg(t_leviatenv *env);
void			print_tokens(t_list *tokens);
int				access_file(int argc, char *argv);
t_list			*get_tokens(int fd);
void			delete_symbols(t_list **tokens);
FLOAT_SIZE		token_to_float(t_list **tokens);
void			t_inter_set(t_inter *inter);
void			t_limg_initator(t_leviatenv *levia);
t_vec			set_screen(t_cam *cam, t_screen screen);
void			initmat(t_list	**tokens, t_item *item);
int				get_t_cam_lenght(t_cam *cam);
void			init_env(t_leviatenv *levia);

void			init_sphere(t_env *env, t_list **tokens);
void			init_plane(t_env *env, t_list **tokens);
void			init_cone(t_env *env, t_list **tokens);
void			init_cyl(t_env *env, t_list **tokens);
void			init_camera(t_env *env, t_list **tokens);
void			init_light(t_env *env, t_list **tokens);
void			setcam(t_env *env, t_cam *cam);

t_vec			miroiratorvcalculator(t_vec ray, t_vec norm);
unsigned int	transroitor(t_inter *inter, t_thr *f, t_pd *pd, int p);
t_proto			*helios(t_light *light, t_proto *prototree, t_env *env);
unsigned int	amaterasu(t_thr *f, t_inter *inter);
unsigned int	color_mult(unsigned int color, FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b);
t_vec			conseiller_d_orientation_protonique_alcolique(void);
void			carresisator(t_env *env);
int				impactcarre(t_carre *c, t_env *env, int n);
void			idciator(t_env *env, t_pd pd, t_item **niark, int *use);
t_cnb			*new_t_cnb(t_item *item);
void			print_carre(t_env env);
int				checkcarre(int *tab, t_cnb *cnb);

t_thr			*new_t_thr(t_cor *c);
void			nextcam(t_thr *f);
t_thr			*set_again_t_thr(t_thr *f);
int				testuniverse(t_vec vec);
t_thr			*new_t_thr(t_cor *c);
void			swapniark(FLOAT_SIZE *a, FLOAT_SIZE *b);
void			nextrack(t_leviatenv *env, int sens, char *son);
void			initfmod(t_leviatenv *levia);
int				key_down_hook(int keycode, t_leviatenv *levia);
int				mouse_hook(int button, int x, int y, t_leviatenv *levia);
int				expose_hook(t_leviatenv *levia);
void			comadator(char *line, t_leviatenv *env);
t_env			*new_t_env(void);
void			modif_x(t_item *item, const float x);
void			modif_y(t_item *item, const float y);
void			modif_z(t_item *item, const float z);
void			modif_dirx(t_item *item, const float x);
void			modif_diry(t_item *item, const float y);
void			normform(t_list **tokens, t_vec *dir, t_item *item);
void			check_triangle(t_item *item, t_pd *s, t_inter *inter, t_thr *f);
void			set_triangle(t_triangle *tr);
t_triangle		*new_t_triangle(void);
void			set_triangle(t_triangle *tr);
void			init_tr(t_env *env, t_list **tokens);
t_obj			*objreader(char *name, t_obj *obj, t_env *env);
void			init_obj(t_env *env, t_list **tokens);
void			check_obj(t_item *item, t_pd *s, t_inter *inter,\
	t_thr *f);
t_obj			*initobj(t_obj *obj);
void			set_normal_triangle(t_inter *inter, t_triangle *tr);
t_vec			set_dist_pos(FLOAT_SIZE dist, t_vec dir, t_vec o);
void			initmatauxi(t_list **tokens, t_item *item);
void			colorcalculator(t_thr *f, t_pd lvec, FLOAT_SIZE *trans);
int				carre_sphere(t_carre *c, t_item *item, int n);
int				carre_triangle(t_carre *c, t_item *item, int n);
int				carre_obj(t_carre *c, t_item *item, int n);
void			addcnb(t_carre *carre, t_cnb *cnb);
void			rotationator(t_vec *vec, double angle);
t_carre			*new_t_carrespe(FLOAT_SIZE size, t_vec pos);
void			ref2(t_thr *f, t_pd *pd);
void			luminatorstupid(t_thr *f, t_pd *lvec);
int				compx(t_proto *proto1, t_proto *proto2);
int				compy(t_proto *proto1, t_proto *proto2);
int				compz(t_proto *proto1, t_proto *proto2);
FLOAT_SIZE		get_sqr_dist(t_vec v1, t_vec v2);
t_color			t_color_add(t_color c1, t_color c2);
t_color			t_color_mult(t_color c1, FLOAT_SIZE i);
unsigned int	color_mult(unsigned int color,\
	FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b);
void			print_tout_tree(t_proto *tmp);
void			print_proto(t_proto *tmp);
void			print_proto_list(t_proto *protolis);
t_proto			*new_t_proto();
float			get_color_str(t_color *color);
void			print_phcol(t_phcol *t);
t_phcol			*new_phcol(t_color color, FLOAT_SIZE dist);
int				da_color_lenght(t_phcol *tab);
FLOAT_SIZE		ft_minspe(const register FLOAT_SIZE a,\
	const register FLOAT_SIZE b);
unsigned int	color_add(unsigned int color,\
	FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b);
void			setthrcnb(t_thr *f);
t_proto			*lance_soleil(t_pd *pd, t_proto	*protolis,\
	t_thr *f, t_color licolor);
void			proto_fill(t_inter *inter, t_proto *proto,\
	t_color color);
t_proto			*range_proton(t_proto *protolis, t_proto *proto,\
	int (*comp)(t_proto *, t_proto *));
t_vec 			trans_calculator_ret(t_inter *inter, t_pd *pd);
t_vec			ref_ret(t_inter *inter, t_pd *pd);
int				proto_counter(t_proto *protolis);
t_proto			*protocopieur(t_proto *protolis);
t_proto			*photoinsertor(t_proto *list, int (*comptr)(t_proto *, t_proto *));
t_proto			*photosynthetisator_spatial(t_proto *protolis);
t_vec			ref_ret(t_inter *inter, t_pd *pd);
t_thr			new_t_thr_spec(t_env *env);
t_proto			*photon_branch(t_proto *protolis, int prof, int (**comptr)(t_proto *, t_proto *));

#endif
