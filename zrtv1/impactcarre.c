/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impactcarre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:31:15 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/04 19:31:33 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		carre_pd(t_carre *b, t_pd r)
{
	double tx1;
	double tx2;
	double ty1;
	double ty2;
	double tz1;
	double tz2;

	tx1 = (b->pos.x - r.pos.x) * -1 * r.dir.x;
	tx2 = (b->pos.x + b->size - r.pos.x) * -1 * r.dir.x;
	ty1 = (b->pos.y - r.pos.y) * -1 * r.dir.y;
	ty2 = (b->pos.y + b->size - r.pos.y) * -1 * r.dir.y;
	tz1 = (b->pos.z - r.pos.z) * -1 * r.dir.z;
	tz2 = (b->pos.z + b->size - r.pos.z) * -1 * r.dir.z;
	return (fmax(fmin(tx1, tx2), fmax(fmin(ty1, ty2), fmin(tz1, tz2)))
		<= 0 + fmin(fmax(tx1, tx2), fmin(fmax(ty1, ty2), fmax(tz1, tz2))));
}

void swapniark(FLOAT_SIZE *a, FLOAT_SIZE *b)
{
	FLOAT_SIZE c;

	c = *a;
	*a = *b;
	*b = c;
}

void	idciator(t_env *env, t_pd pd, int *niark)
{
	t_carre	*tmp;
	int		i;

	tmp = env->carre;
	i = 0;
	if (tmp == NULL)
		ft_putendl("dafuq3");
	while (tmp && i < 200)
	{
		if (carre_pd(tmp, pd) == 1)
			niark[i++] = tmp->cnb;
		// else
		// 	ft_putendl("dafuq4");
		tmp = tmp->next;
	}
	niark[i] = 0;
}

void	addcnb(t_item *item, t_cnb *cnb)
{	
	t_cnb	*copy;

	if (!item->cnb)
		item->cnb = cnb;
	else
	{
		copy = item->cnb;
		while (copy->next)
			copy = copy->next;
		copy->next = cnb;
	}
}

int		carre_sphere(t_carre *c, t_item *item)
{
	if (c->pos.x < item->sp->c.x + item->sp->ray
		&& c->pos.y < item->sp->c.y + item->sp->ray
		&& c->pos.z < item->sp->c.z + item->sp->ray
		&& c->pos.x + c->size > item->sp->c.x - item->sp->ray
		&& c->pos.y + c->size > item->sp->c.y - item->sp->ray
		&& c->pos.z + c->size > item->sp->c.z - item->sp->ray)
	{
		addcnb(item, new_t_cnb(c->cnb));
		return (1);
	}
	return (0);
}

int		impactcarre(t_carre *c, t_env *env)
{
	t_item	*lst;
	int		i;

	(void)env;
	i = 0;
	lst = env->item;
	while (env->item != NULL)
	{
		if (env->item->sp != NULL)
		{
			i += carre_sphere(c, env->item);
		}
		// else if (env->item->pl != NULL)
		// {
		// 	check_plane(env->item, pd, inter);
		// }
		// else if (env->item->cyl != NULL)
		// {
		// 	check_cyl(env->item, pd, inter);
		// }
		// else if (env->item->con != NULL)
		// {
		// 	check_con(env->item, pd, inter);
		// }
		env->item = env->item->next;
	}
	env->item = lst;
	return (i);
}
