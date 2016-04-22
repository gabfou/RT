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

void		set_texture_plane(t_inter *inter, t_item *item)
{
	int	tu;
	int	tv;

	tu = (int)((int)(inter->pos.x - item->pl->pos.x)
		% (int)(item->texture->i)) * item->texture->bpp / 8;
	tv = (int)((int)(inter->pos.y - item->pl->pos.y)
		% (int)(item->texture->l)) * item->texture->sline;
	inter->diff.b = (unsigned char)item->texture->img[(tv + tu)] / 255.0;
	inter->diff.g = (unsigned char)item->texture->img[(tv + tu) + 1] / 255.0;
	inter->diff.r = (unsigned char)item->texture->img[(tv + tu) + 2] / 255.0;
}


void	set_normal_plane(t_item *item, t_inter *inter)
{
	inter->norm.x = item->pl->dir.x;
	inter->norm.y = item->pl->dir.y;
	inter->norm.z = item->pl->dir.z;
}

t_pd	*t_plane_creator(t_vec v, t_vec vd, FLOAT_SIZE ray)
{
	t_pd		*plane;

	plane = malloc(sizeof(t_pd));
	plane->pos = v;
	plane->dir = normalizator_ret(vd);
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
	if (check_t(inter, t, item->mat.trans, item) == 1)
	{
		set_normal_plane(item, inter);
		set_inter_pos(inter, s);
		if (item->texture)
				set_texture_plane(inter, item);
	}
	return ;
}
