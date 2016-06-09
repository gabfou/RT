/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:16:43 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/28 23:44:26 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		set_texture_sphere(t_inter *inter, t_item *item)
{
	int	tu;
	int	tv;

	tu = (int)(((inter->norm.x + 1) / 2)
		* item->texture->i) * item->texture->bpp / 8;
	tv = (int)(((1 - inter->norm.y) / 2)
		* item->texture->l) * item->texture->sline;
	inter->diff.b = (unsigned char)item->texture->img[(tv + tu)] / 255.0;
	inter->diff.g = (unsigned char)item->texture->img[(tv + tu) + 1] / 255.0;
	inter->diff.r = (unsigned char)item->texture->img[(tv + tu) + 2] / 255.0;
}

int			new_sphere(t_env *env)
{
	t_item	*item;

	item = new_t_item(env);
	item->sp = new_t_sphere(100, 0, 0, 3);
	item->next = NULL;
	itemadator(env, item);
	return (0);
}

void		set_normal_sphere(t_inter *inter, t_item *item)
{
	inter->norm.x = inter->pos.x - item->sp->c.x;
	inter->norm.y = inter->pos.y - item->sp->c.y;
	inter->norm.z = inter->pos.z - item->sp->c.z;
	normalizator(&(inter->norm));
}

t_sphere	*new_t_sphere(FLOAT_SIZE x, FLOAT_SIZE y,
	FLOAT_SIZE z, FLOAT_SIZE r)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->c = new_t_vec(x, y, z);
	sphere->ray = r;
	return (sphere);
}

void		check_sphere(t_item *item, t_pd *s, t_inter *inter, int impactmod)
{
	FLOAT_SIZE	a;
	FLOAT_SIZE	b;
	FLOAT_SIZE	c;
	FLOAT_SIZE	del;
	FLOAT_SIZE	t;

	a = carre(s->dir.x) + carre(s->dir.y) + carre(s->dir.z);
	b = 2 * (s->dir.x * (s->pos.x - item->sp->c.x) + s->dir.y
	* (s->pos.y - item->sp->c.y) + s->dir.z * (s->pos.z - item->sp->c.z));
	c = (carre(s->pos.x - item->sp->c.x) + carre(s->pos.y - item->sp->c.y) +
		carre(s->pos.z - item->sp->c.z)) - carre(item->sp->ray);
	del = carre(b) - (4 * a * c);
	if (del > 0)
	{
		t = ((-b + sqrt(del)) / (2 * a) > (-b - sqrt(del)) / (2 * a)) ?
		(-b - sqrt(del)) / (2 * a) : (-b + sqrt(del)) / (2 * a);
		if (check_t(inter, t, s, item) == 1 && impactmod)
		{
			set_normal_sphere(inter, item);
			if (item->texture)
				set_texture_sphere(inter, item);
		}
	}
	return ;
}
