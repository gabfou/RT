/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:52:30 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/29 18:52:31 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline t_vec	set_dist_pos(FLOAT_SIZE dist, t_vec dir, t_vec o)
{
	t_vec r;

	r.x = (o.x + (dir.x * dist));
	r.y = (o.y + (dir.y * dist));
	r.z = (o.z + (dir.z * dist));
	return (r);
}

t_triangle		*new_t_triangle(void)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	triangle->p1 = new_t_vec(1, -1, 0);
	triangle->p2 = new_t_vec(1, 0, 1);
	triangle->p3 = new_t_vec(1, 1, 0);
	return (triangle);
}

void			set_triangle(t_triangle *tr)
{
	tr->u = (sub_vec(tr->p2, tr->p1));
	tr->v = (sub_vec(tr->p3, tr->p1));
	tr->uu = dot_prod(tr->u, tr->u);
	tr->uv = dot_prod(tr->u, tr->v);
	tr->vv = dot_prod(tr->v, tr->v);
	tr->d = tr->uv * tr->uv - tr->uu * tr->vv;
	tr->n = normalizator_ret(prod_vector(tr->u, tr->v));
}

int				point_triangle(t_vec pos, t_triangle *p)
{
	FLOAT_SIZE	accumilator;
	t_vec		dot;
	t_vec		line1;
	t_vec		line2;

	accumilator = 0;
	line1 = normalizator_ret(sub_vec(p->p1, pos));
	line2 = normalizator_ret(sub_vec(p->p2, pos));
	dot.x = dot_prod(line1, line2);
	line1 = normalizator_ret(sub_vec(p->p2, pos));
	line2 = normalizator_ret(sub_vec(p->p3, pos));
	dot.y = dot_prod(line1, line2);
	line1 = normalizator_ret(sub_vec(p->p3, pos));
	line2 = normalizator_ret(sub_vec(p->p1, pos));
	dot.z = dot_prod(line1, line2);
	accumilator = acos(dot.x) + acos(dot.y) + acos(dot.z);
	if (accumilator < (359.9 * M_PI))
		return (0);
	else
		return (1);
}

void			check_triangle(t_item *item, t_pd *s, t_inter *inter, t_thr *f)
{
	t_vec		n;
	t_vec		a;
	FLOAT_SIZE	t;

	n = (prod_vector(item->tr->u, item->tr->v));
	a.x = -dot_prod(n, sub_vec(s->pos, item->tr->p1));
	a.y = dot_prod(n, s->dir);
	if (fabs(a.y) > 0 && (t = a.x / a.y) >= 0)
	{
		n = sub_vec(set_dist_pos(t, s->dir, s->pos), item->tr->p1);
		a.x = dot_prod(n, item->tr->u);
		a.y = dot_prod(n, item->tr->v);
		a.z = (a.y * item->tr->uv - item->tr->vv * a.x) / item->tr->d;
		a.y = (item->tr->uv * a.x - item->tr->uu * a.y) / item->tr->d;
		if (a.z < 0.0 || a.z > 1.0 || a.y < 0.0 || (a.y + a.z) > 1.0)
			return ;
		if (check_t(inter, t, s, item) == 1 && f->impactmod)
			inter->norm = item->tr->n;
	}
	return ;
}
