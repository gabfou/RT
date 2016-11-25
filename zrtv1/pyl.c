/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:17:03 by jromagna          #+#    #+#             */
/*   Updated: 2016/06/11 19:23:22 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cyl		*t_cyl_creator(t_vec v, t_vec vd, FLOAT_SIZE ray)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	cyl->pos = v;
	cyl->dir = normalizator_ret(vd);
	cyl->ray = ray;
	return (cyl);
}

void		set_normal_cyl(t_cyl *cyl, t_inter *inter)
{
	inter->norm = normalizator_ret(sub_vec(vector_proj_vector(
		normalizator_ret(sub_vec(cyl->pos, inter->pos)), cyl->dir),
	normalizator_ret(sub_vec(cyl->pos, inter->pos))));
}

t_item		*new_cyl(t_env *env)
{
	t_item	*item;

	item = new_t_item(env);
	item->cyl = t_cyl_creator(new_t_vec(0, 0, 0), new_t_vec(1, 0, 0), 3);
	item->next = NULL;
	itemadator(env, item);
	return (item);
}

void		check_cyl(t_item *item, t_pd *s, t_inter *inter, int impactmod)
{
	FLOAT_SIZE	a;
	FLOAT_SIZE	b;
	FLOAT_SIZE	c;
	FLOAT_SIZE	t;
	t_vec		l;

	l = sub_vec(s->pos, item->cyl->pos);
	a = dot_prod(s->dir, s->dir) - (dot_prod(s->dir,
		item->cyl->dir) * dot_prod(s->dir, item->cyl->dir));
	b = 2 * (dot_prod(s->dir, l) - (dot_prod(s->dir,
		item->cyl->dir) * dot_prod(l, item->cyl->dir)));
	c = dot_prod(l, l) - (dot_prod(l, item->cyl->dir)
		* dot_prod(l, item->cyl->dir)) - item->cyl->ray * item->cyl->ray;
	if ((t = (b * b - 4.0 * a * c)) <= 0)
		return ;
	t = ft_minspe(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a)));
	if (check_t(inter, t, s, item) == 1 && impactmod)
		set_normal_cyl(item->cyl, inter);
	return ;
}
