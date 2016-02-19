/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 19:18:56 by gfournie          #+#    #+#             */
/*   Updated: 2015/09/22 19:19:00 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_H
# define LE_H

# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "math.h"
#include <stdio.h>


# define TV 1280
# define TH 800

typedef struct	s_v
{
	long double		x;
	long double		y;
	long double		z;
}				t_v;

typedef struct	s_l
{
	t_v				p;
	// long double		x;
	// long double		y;
	// long double		z;
	t_v				color;
}				t_l;

typedef struct	s_cy
{
	t_v				p;
	t_v				v;
	long double		r;
	long double		h;
	long double		b;
	t_v				color;
}				t_cy;

typedef struct	s_co
{
	t_v				p;
	t_v				v;
	long double		a;
	long double		h;
	long double		b;
	t_v				color;
}				t_co;

typedef struct	s_s
{
	t_v				p;
	long double		r;
	t_v				color;
}				t_s;

typedef struct	s_p
{
	t_v				color;
	t_v				p;
	t_v				v;
}				t_p;

typedef struct	s_t
{
	t_v				pos;
	t_v				dir;
	t_v				right;
	t_v				up;
}				t_t;

typedef struct	s_cam
{
	t_v				vpul;
	t_v				pos;
	t_v				dir;
	t_v				right;
	t_v				up;
	long double		h;
	long double		l;
	long double		d;
}				t_cam;

typedef struct	s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*addr;
	int				bpp;
	int				endian;
	int				sizel;
	long double		color;
	int				testor;
	long double		d;
	t_cam			o;
	t_cam			t;
	int				l;
	t_v				c;
	t_v				c2;
	int				test2;
	int				test3;
	t_v				pl;
	t_v				vl;
}				t_env;

t_v			vdc(t_v a, long double b);
long double	svwaza(t_v a, t_v b);
long double	ddp(t_v d, t_v v, t_v p);
t_cam		initcam(t_cam c);
long double	**eulerator(t_cam cam);
t_v			mat_33_31_mult(long double **m1, t_v v);
long double	**mat_inversator(long double **m);
void		error(char *s);
long double	vwaza(t_v a, t_v b);
t_v 		ps(t_v a, long double b);
long double	vm(t_v a, t_v b);
long double	va(t_v a, t_v b);
long double	vb(t_v a, t_v b);
long double	vs(t_v a, t_v b);
long double	vdp(t_v a);
t_v			vmv(t_v a, t_v b);
t_v			pv(t_v a, t_v b);
t_v			vav(t_v a, t_v b);
t_v			vdv(t_v a, t_v b);
t_v			vsv(t_v a, t_v b);
void		put_pixel(t_env *pos, register int x, register int y, int color);
long double	ft_min(const register long double a, const register long double b);
void		panoramiquator(t_env *e);
t_v			vpulcalculator(t_cam c);
t_v			pixelpos(t_cam c, long double x, long double y, t_env *e);
t_v			normalisator(t_v v);
int			lumierator(t_l *l, t_env *e, t_v v, t_v p);
long double	normecalculator(t_v v);
int			lightrecuperator();
t_p			planerecuperator();
int 		sphererecuperator(char *l, t_env *e);
t_s			*sphereguardator(void *var, int i);
long double	planetestor(t_v v, t_env *e, t_v dir, t_p *p);
long double	spheretestor(t_v v, t_env *e, t_v dir, t_s *s);
int			ft_atoi2(const char *str);
int			superparsator(t_env *e);
int 		planrecuperator(char *l, t_env *e);
t_p			*planeguardator(void *var, int i);
t_v			perpendiculator(t_v v);
t_l			*lightguardator(void *var, int i);
t_cy		*cyguardator(void *var, int i);
long double	testall(int i, t_v p, t_env *e, t_v dir);
long double	cytestor(t_v v, t_env *e, t_v dir, t_cy *s);
long double	cotestor(t_v v, t_env *e, t_v dir, t_co *s);
t_co		*coguardator(void *var, int i);
t_t			inversator(t_t t);
t_t			mtranslator(t_v pos, t_v dir);
t_v			vtranslator(t_v v, t_t t);
t_v			ptranslator(t_v p, t_t t);

#endif
