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

// int			new_triangle(t_env *env)
// {
// 	t_item	*item;

// 	item = new_t_item(env);
// 	item->tr = new_t_triangle(100, 0, 0, 3);
// 	item->next = NULL;
// 	return (itemadator(env, item));
// }

inline t_vec		set_dist_pos(FLOAT_SIZE dist, t_vec dir, t_vec o)
{
	t_vec r;

	r.x = (o.x + (dir.x * dist));
	r.y = (o.y + (dir.y * dist));
	r.z = (o.z + (dir.z * dist));
	return (r);
}

inline void		set_normal_triangle(t_inter *inter, t_triangle *tr)
{
	inter->norm = tr->n;
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
	tr->D = tr->uv * tr->uv - tr->uu * tr->vv;
	tr->n = normalizator_ret(prod_vector(tr->u, tr->v));
}

void		check_triangle(t_item *item, t_pd *s, t_inter *inter, t_thr *f)
{
	t_vec		n;
	FLOAT_SIZE	c;
	FLOAT_SIZE	a;
	FLOAT_SIZE	b;
	FLOAT_SIZE	t;

	// ft_putendl("niark");
	n = (prod_vector(item->tr->u, item->tr->v));
	a = -dot_prod(n, sub_vec(s->pos, item->tr->p1));
	b = dot_prod(n, s->dir);
	if (fabs(b) > 0 && (t = a / b) >= 0)
	{
		n = sub_vec(set_dist_pos(t, s->dir, s->pos), item->tr->p1);
		a = dot_prod(n, item->tr->u);
		b = dot_prod(n, item->tr->v);
		c = (b * item->tr->uv - item->tr->vv * a) / item->tr->D;
		b = (item->tr->uv * a - item->tr->uu * b) / item->tr->D;
		if (c < 0.0 || c > 1.0 || b < 0.0 || (b + c) > 1.0)
			return ;
		if (check_t(inter, t, item->mat.trans, item) == 1 && f->impactmod)
		{
			set_inter_pos(inter, s);
			set_normal_triangle(inter, item->tr);
			// if (texture)
			// 	set_texture_triangle(inter, item);
		}
	}
	return ;
}
