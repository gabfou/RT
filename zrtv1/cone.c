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

t_con		*t_con_creator(t_vec v, t_vec v1, FLOAT_SIZE ang)
{
	t_con	*con;

	con = malloc(sizeof(t_con));
	con->pos = new_t_vec(v.x, v.y, v.z);
	con->dir = normalizator_ret(new_t_vec(v1.x, v1.y, v1.z));
	con->ang = ang / 180 * M_PI;
	return (con);
}

void		set_normal_con(t_con *con, t_inter *inter)
{
	inter->norm = normalizator_ret(sub_vec(vector_proj_vector(normalizator_ret(
		sub_vec(con->pos, inter->pos)), con->dir),
	normalizator_ret(sub_vec(con->pos, inter->pos))));
}

void		check_con(t_item *item, t_pd *s, t_inter *inter, t_thr *f)
{
	FLOAT_SIZE	a;
	FLOAT_SIZE	b;
	FLOAT_SIZE	c;
	FLOAT_SIZE	t;
	t_vec		l;

	l = sub_vec(s->pos, item->con->pos);
	a = dot_prod(s->dir, s->dir) - (1.0 + tan(item->con->ang)
		* tan(item->con->ang)) * (dot_prod(s->dir, item->con->dir)
		* dot_prod(s->dir, item->con->dir));
	b = 2 * (dot_prod(s->dir, l) - (1.0 + tan(item->con->ang)
		* tan(item->con->ang)) * (dot_prod(s->dir, item->con->dir)
		* dot_prod(l, item->con->dir)));
	c = dot_prod(l, l) - (1.0 + tan(item->con->ang) * tan(item->con->ang))
	* (dot_prod(l, item->con->dir) * dot_prod(l, item->con->dir));
	if ((t = (b * b - 4.0 * a * c)) <= 0)
		return ;
	t = ft_min(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a)));
	if (check_t(inter, t, item->mat.trans, item) == 1 && f->impactmod)
	{
		set_inter_pos(inter, s);
		set_normal_con(item->con, inter);
	}
	return ;
}
