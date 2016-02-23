/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:17:11 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:17:12 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_normal_plane(t_item *item, t_inter *inter)
{
	inter->norm->x = item->pl->dir->x;
	inter->norm->y = item->pl->dir->y;
	inter->norm->z = item->pl->dir->z;
}

t_pd	*t_plane_creator(double x, double y, double z, double dx, double dy, double dz)
{
	t_pd		*plane;

	plane = malloc(sizeof(t_pd));
	plane->pos = new_t_vec(x, y, z);
	plane->dir = new_t_vec(dx, dy, dz);
	return (plane);
}

void		check_plane(t_item *item, t_pd *s, t_inter *inter)
{
	double	t;
	double	x;
	double	y;
	double	z;

	x = s->pos->x - item->pl->pos->x;
	y = s->pos->y - item->pl->pos->y;
	z = s->pos->z - item->pl->pos->z;
	t = -((item->pl->dir->x * x + item->pl->dir->y * y + item->pl->dir->z * z)
		/ (item->pl->dir->x * s->dir->x + item->pl->dir->y
			* s->dir->y + item->pl->dir->z * s->dir->z));
	if (check_t(inter, t) == 1)
	{
		set_normal_plane(item, inter);
		set_inter_pos(inter, s);
	}
	return ;
}