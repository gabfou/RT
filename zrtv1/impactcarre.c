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

int carre_pd(t_carre b, t_pd r)
{
	double	tmin = -INFINITY;
	double	tmax = INFINITY;
	double	t1;
	double	t2;

	tmin = -INFINITY;
	tmax = INFINITY;
	if (r.dir.x != 0.0)
	{
		t1 = (b.pos.x - r.pos.x) / r.dir.x;
		t2 = (b.pos.x + b.size - r.pos.x) / r.dir.x;
		tmin = fmax(tmin, fmin(t1, t2));
		tmax = fmin(tmax, fmax(t1, t2));
	}
	if (r.dir.y != 0.0)
	{
		t1 = (b.pos.y - r.pos.y) / r.dir.y;
		t2 = (b.pos.y + b.size - r.pos.y) / r.dir.y;
		tmin = fmax(tmin, fmin(t1, t2));
		tmax = fmin(tmax, fmax(t1, t2));
	}
	return tmax >= tmin;
}

void	idciator(t_env *env, t_pd pd, t_item **niark, int *use)
{
	t_carre	*tmp;
	int		i;
	t_cnb	*tmp2;

	tmp = env->carre;
	i = env->infitem;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		if (carre_pd(*tmp, pd) == 1)
		{
			tmp2 = tmp->cnb;
			while (tmp2)
			{
				if (use[tmp2->item->nb] == 0)
				{
					niark[i++] = tmp2->item;
					use[tmp2->item->nb] = 1;
				}
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->next;
	}
	niark[i] = NULL;
}

void	addcnb(t_carre *carre, t_cnb *cnb)
{
	t_cnb	*copy;

	if (!carre->cnb)
		carre->cnb = cnb;
	else
	{
		copy = carre->cnb;
		while (copy->next)
			copy = copy->next;
		copy->next = cnb;
	}
}

int		carre_sphere(t_carre *c, t_item *item, int n)
{
	if (c->pos.x < item->sp->c.x + item->sp->ray
		&& c->pos.y < item->sp->c.y + item->sp->ray
		&& c->pos.z < item->sp->c.z + item->sp->ray
		&& c->pos.x + c->size > item->sp->c.x - item->sp->ray
		&& c->pos.y + c->size > item->sp->c.y - item->sp->ray
		&& c->pos.z + c->size > item->sp->c.z - item->sp->ray)
	{
		if (n)
			addcnb(c, new_t_cnb(item));
		return (1);
	}
	return (0);
}

int		carre_triangle(t_carre *c, t_item *item, int n)
{
	t_vec		min;
	t_vec		max;

	min.x = fmin(fmin(item->tr->p1.x, item->tr->p2.x), item->tr->p3.x);
	min.y = fmin(fmin(item->tr->p1.y, item->tr->p2.y), item->tr->p3.y);
	min.z = fmin(fmin(item->tr->p1.z, item->tr->p2.z), item->tr->p3.z);
	max.x = fmax(fmax(item->tr->p1.x, item->tr->p2.x), item->tr->p3.x);
	max.y = fmax(fmax(item->tr->p1.y, item->tr->p2.y), item->tr->p3.y);
	max.z = fmax(fmax(item->tr->p1.z, item->tr->p2.z), item->tr->p3.z);
	if (c->pos.x > max.x
		|| c->pos.y > max.y
		|| c->pos.z > max.z
		|| c->pos.x + c->size < min.x
		|| c->pos.y + c->size < min.y
		|| c->pos.z + c->size < min.z)
		return (0);
	else
	{
		if (n)
			addcnb(c, new_t_cnb(item));
		return (1);
	}
	return (0);
}

int		carre_obj(t_carre *c, t_item *item, int n)
{
	t_item	*tmp;
	int		i;

	i = 0;
	tmp = item->obj->tr;
	while (tmp)
	{
		i += carre_triangle(c, tmp, n);
		tmp = tmp->next;
	}
	return (i);
}

int		impactcarre(t_carre *c, t_env *env, int n)
{
	t_item	*lst;
	int		i;

	(void)env;
	i = 0;
	lst = env->item;
	while (lst != NULL)
	{
		if (lst->sp != NULL)
			i += carre_sphere(c, lst, n);
		else if (lst->tr != NULL)
			i += carre_triangle(c, lst, n);
		else if (lst->obj != NULL)
			i += carre_obj(c, lst, n);
		lst = lst->next;
	}
	if (n == 1)
	{
		ft_putnbr(i);
		ft_putendl ("");
	}
	return (i);
}
