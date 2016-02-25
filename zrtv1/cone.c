/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:16:52 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:16:54 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_con	*t_con_creator(double x, double y, double z, double x1, double y1, double z1, double ang)
{
	t_con	*con;

	con = malloc(sizeof(t_con));
	con->pos = new_t_vec(x, y, z);
	con->dir = normalizator_ret(new_t_vec(x1, y1, z1));
	con->ang = ang / 180 * M_PI;
	return (con);
}

void	set_normal_con(t_con *con, t_inter *inter)
{
	inter->norm = normalizator_ret(sub_vec(vector_proj_vector(normalizator_ret(sub_vec(con->pos, inter->pos)), con->dir),
	 normalizator_ret(sub_vec(con->pos, inter->pos))));
}

void		check_con(t_con *con, t_pd *s, t_inter *inter)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	double					t;
	t_vec					*l;

 	//ft_putendl("CONE START");
	l = sub_vec(s->pos, con->pos);

	a = dot_prod(s->dir, s->dir) - (1.0 + tan(con->ang) * tan(con->ang)) * (dot_prod(s->dir, con->dir) *  dot_prod(s->dir, con->dir));

	b = 2 * (dot_prod(s->dir, l) - (1.0 + tan(con->ang) * tan(con->ang)) * (dot_prod(s->dir, con->dir) * dot_prod(l, con->dir)));

	c = dot_prod(l, l) - (1.0 + tan(con->ang) * tan(con->ang)) * (dot_prod(l, con->dir) * dot_prod(l, con->dir));

	if ((t = (b * b - 4.0 * a * c)) <= 0)
		return ;

	t = ft_min(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a)));

	if (check_t(inter, t) == 1)
	{
		set_inter_pos(inter, s);
		set_normal_con(con, inter);
	}
	//ft_putendl("CONE FINITO");
	return ;
}

/*

inline long double	cotestor(t_vec v, t_env *e, t_vec dir, t_con *s)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	register long double	d;
	t_vec						l;

	(void)l;
	l = sub_vec(v, s->p);

	a = dot_prod(dir, dir) - (1.0 + tan(s->a) * tan(s->a)) * (dot_prod(dir, s->v) *  dot_prod(dir, s->v));

	b = 2 * (dot_prod(dir, l) - (1.0 + tan(s->a) * tan(s->a)) * (dot_prod(dir, s->v) * dot_prod(l, s->v)));

	c = dot_prod(l, l) - (1.0 + tan(s->a) * tan(s->a)) * (dot_prod(l, s->v) * dot_prod(l, s->v));

	if ((d = (b * b - 4.0 * a * c)) < 0)
		return (-1);

	d = ft_min(((-b + sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));

	if (d < 0 || d > e->d)
		return (-1);

	l = vav(v, ps(dir, d));

	// if (s->h != -1 && normecalculator(sub_vec(l, s->p)) > s->h)
	// 	return (-1);

	// e->d = d;

	if (!e->testor)
		return (d);

	v = normalisator(sub_vec(vector_proj_vector(normalisator(sub_vec(s->p, l)), s->v), normalisator(sub_vec(s->p, l))));
	e->pixelmirror = 0;
	e->vl = v;
	e->pl = l;
	e->c2 = s->color;
	return (d);
}
*/