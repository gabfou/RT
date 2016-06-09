/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carreform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 22:33:45 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/08 22:34:18 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
