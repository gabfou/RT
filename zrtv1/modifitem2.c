/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifitem2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:15:18 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/23 17:15:20 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		modif_x(t_item *item, const float x)
{
	if (item->sp != NULL)
		item->sp->c.x = x;
	else if (item->pl != NULL)
		item->pl->pos.x = x;
	else if (item->cyl != NULL)
		item->cyl->pos.x = x;
	else if (item->con != NULL)
		item->con->pos.x = x;
}

void		modif_y(t_item *item, const float y)
{
	if (item->sp != NULL)
		item->sp->c.y = y;
	else if (item->pl != NULL)
		item->pl->pos.y = y;
	else if (item->cyl != NULL)
		item->cyl->pos.y = y;
	else if (item->con != NULL)
		item->con->pos.y = y;
}

void		modif_z(t_item *item, const float z)
{
	if (item->sp != NULL)
		item->sp->c.z = z;
	else if (item->pl != NULL)
		item->pl->pos.z = z;
	else if (item->cyl != NULL)
		item->cyl->pos.z = z;
	else if (item->con != NULL)
		item->con->pos.z = z;
}

void		modif_dirx(t_item *item, const float x)
{
	if (item->pl != NULL)
		item->pl->dir.x = x;
	else if (item->cyl != NULL)
		item->cyl->dir.x = x;
	else if (item->con != NULL)
		item->con->dir.x = x;
}

void		modif_diry(t_item *item, const float y)
{
	if (item->pl != NULL)
		item->pl->dir.y = y;
	else if (item->cyl != NULL)
		item->cyl->dir.y = y;
	else if (item->con != NULL)
		item->con->dir.y = y;
}
