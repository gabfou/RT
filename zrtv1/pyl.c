/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:17:03 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:17:04 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cyl	*t_cyl_creator(double x, double y, double z, double x1, double y1, double z1, double ray)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	cyl->pos = new_t_vec(x, y, z);
	cyl->dir = normalizator_ret(new_t_vec(x1, y1, z1));
	cyl->ray = ray;
	return (cyl);
}

void		set_normal_cyl(t_cyl *cyl, t_inter *inter)
{
	double		dist1;
	double		dist2;
	t_vec		*center;

	dist1 = get_dist(cyl->pos, inter->pos);
	dist2 = sqrt(carre(dist1) - carre(cyl->ray));
	center = set_new_pos(cyl->pos, cyl->dir, dist2);
	dist1 = get_dist(center, inter->pos);
	if (dist1 >= cyl->ray - 0.00001 && dist1 <= cyl->ray + 0.00001)
	{
		inter->norm = normalizator_ret(sub_vec(inter->pos, center));
		return ;
	}
	center = set_new_pos(cyl->pos, cyl->dir, -dist2);
	dist1 = get_dist(center, inter->pos);
	inter->norm = normalizator_ret(sub_vec(inter->pos, center));
	return ;
}

void		check_cyl(t_cyl *cyl, t_pd *s, t_inter *inter)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	double					t;
	t_vec					*l;


	//d = dot_prod(cyl->dir, cyl->dir);

	l = sub_vec(s->pos, cyl->pos);

	a = dot_prod(s->dir, s->dir) - (dot_prod(s->dir, cyl->dir) *  dot_prod(s->dir, cyl->dir));

	b = 2 * (dot_prod(s->dir, l) - (dot_prod(s->dir, cyl->dir) * dot_prod(l, cyl->dir)));

	c = dot_prod(l, l) - (dot_prod(l, cyl->dir) * dot_prod(l, cyl->dir)) - cyl->ray * cyl->ray;

	if ((t = (b * b - 4.0 * a * c)) <= 0)
		return ;

	t = ft_min(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a)));
	if (check_t(inter, t) == 1)
	{
		set_inter_pos(inter, s);
		set_normal_cyl(cyl, inter);
	}
	return ;
}
/*
vm = dot_prod;
vsv = sub_vec;

v = s->pos;
dir = s->dir;

s->v = cyl->dir;
s->p = cyl->pos;
s->r = cyl->ray;
*/
/*
inline long double	cytestor(t_v v, t_env *e, t_v dir, t_cy *s)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	register long double	d;
	t_v						l;
	t_v						z;
	double dist;

	if (s == NULL)
		return (-2);

	d = vm(s->v, s->v);
	l = vsv(v, s->p);
	a = vm(dir, dir) - (vm(dir, s->v) *  vm(dir, s->v));

	b = 2 * (vm(dir, l) - (vm(dir, s->v) * vm(l, s->v)));

	c = vm(l, l) - (vm(l, s->v) * vm(l, s->v)) - s->r * s->r;

	if ((d = (b * b - 4.0 * a * c)) < 0)
		return (-1);

	d = ft_min(((-b + sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));

	if (d < 0 || d > e->d)
		return (-1);

	l = vav(v, ps(dir, d));

	if (s->h != -1 && normecalculator(vsv(l, s->p)) > s->h)
		return (-1);

	e->d = d;
	if (!e->testor)
		return(d);
	// z = tvb(l, s->v, s->p, s->r + 0.00001);
	// v = vsv(z, l);
	// v = normalisator(v);
	// v = normalisator(vsv((vsv(ps(dir, e->d), s->p)),
	// 	(ps(s->v, vm(dir, s->v) * e->d + vm(vsv(v, s->p), s->v)))));
	a = normecalculator(vsv(s->p, l));
	dist = sqrt(pow(a, 2) - pow(s->r, 2));
	z = vav(s->p, ps(s->v, dist));
	v = vsv(z, l);
	if (!((a = normecalculator(v)) > s->r - 0.00000001 && a < s->r + 0.00000001))
	{
		z = vav(s->p, ps(s->v, -dist));
		v = vsv(z, l);
	}
	v = normalisator(v);
	e->pixelmirror = 0;
	e->vl = v;
	e->pl = l;
	e->c2 = s->color;
	return (d);
}*/