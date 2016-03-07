/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:16:43 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:16:45 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_normal_sphere(t_inter *inter, t_item *item)
{
	inter->norm->x = inter->pos->x - item->sp->c->x;
	inter->norm->y = inter->pos->y - item->sp->c->y;
	inter->norm->z = inter->pos->z - item->sp->c->z;
	normalizator(inter->norm);
}

t_sphere	*new_t_sphere(float x, float y, float z, float r)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->c = new_t_vec(x, y, z);
	sphere->ray = r;
	return (sphere);
}

void		check_sphere(t_item *item, t_pd *s, t_inter *inter)
{
	float	a;
	float	b;
	float	c;
	float	del;
	float	t;

	// ft_putendl("pre calcul");
	// print_vec(s->dir);
	// print_vec(s->pos);
	// print_vec(item->sp->c);
	a = carre(s->dir->x) + carre(s->dir->y) + carre(s->dir->z);
	b = 2 * (s->dir->x * (s->pos->x - item->sp->c->x) + s->dir->y
	* (s->pos->y - item->sp->c->y) + s->dir->z * (s->pos->z - item->sp->c->z));
//	ft_putendl("pre calcul B");
	c = (carre(s->pos->x - item->sp->c->x) + carre(s->pos->y - item->sp->c->y) +
		carre(s->pos->z - item->sp->c->z)) - carre(item->sp->ray);
	del = carre(b) - (4 * a * c);
//	ft_putendl("post calcul");
	if (del > 0)
	{
		t = ((-b + sqrt(del)) / (2 * a) > (-b - sqrt(del)) / (2 * a))?
		(-b - sqrt(del)) / (2 * a) : (-b + sqrt(del)) / (2 * a);
		if (check_t(inter, t) == 1)
		{
			set_inter_pos(inter, s);
			set_normal_sphere(inter, item);
		}
	}
//	ft_putendl("post tout ");
	return ;
}