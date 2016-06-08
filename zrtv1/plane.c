/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:17:11 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/24 17:45:25 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_normal_plane(t_item *item, t_inter *inter)
{
	inter->norm.x = item->pl->dir.x;
	inter->norm.y = item->pl->dir.y;
	inter->norm.z = item->pl->dir.z;
}

t_pd	*t_plane_creator(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z, FLOAT_SIZE dx, FLOAT_SIZE dy, FLOAT_SIZE dz, FLOAT_SIZE ray)
{
	t_pd		*plane;

	plane = malloc(sizeof(t_pd));
	plane->pos = new_t_vec(x, y, z);
	plane->dir = normalizator_ret(new_t_vec(dx, dy, dz));
	plane->ray = ray;
	return (plane);
}

void		check_plane(t_item *item, t_pd *s, t_inter *inter)
{
	FLOAT_SIZE	t;
	FLOAT_SIZE	x;
	FLOAT_SIZE	y;
	FLOAT_SIZE	z;

	x = s->pos.x - item->pl->pos.x;
	y = s->pos.y - item->pl->pos.y;
	z = s->pos.z - item->pl->pos.z;
	t = -((item->pl->dir.x * x + item->pl->dir.y * y + item->pl->dir.z * z)
		/ (item->pl->dir.x * s->dir.x + item->pl->dir.y
			* s->dir.y + item->pl->dir.z * s->dir.z));
	if (check_t(inter, t, item) == 1)
	{
		set_normal_plane(item, inter);
		set_inter_pos(inter, s);
	}
	return ;
}
