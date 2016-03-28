/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifitem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:40:07 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/03/28 23:40:41 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		modif_x(t_item *item, float x)
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

void		modif_y(t_item *item, float y)
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

void		modif_z(t_item *item, float z)
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

void		modif_dirx(t_item *item, float x)
{
	if (item->sp != NULL)
		return;
	else if (item->pl != NULL)
		item->pl->dir.x = x;
	else if (item->cyl != NULL)
		item->cyl->dir.x = x;
	else if (item->con != NULL)
		item->con->dir.x = x;
}

void		modif_diry(t_item *item, float y)
{
	if (item->sp != NULL)
		return;
	else if (item->pl != NULL)
		item->pl->dir.y = y;
	else if (item->cyl != NULL)
		item->cyl->dir.y = y;
	else if (item->con != NULL)
		item->con->dir.y = y;
}

void		modif_dirz(t_item *item, float z)
{
	if (item->sp != NULL)
		return;
	else if (item->pl != NULL)
		item->pl->dir.z = z;
	else if (item->cyl != NULL)
		item->cyl->dir.z = z;
	else if (item->con != NULL)
		item->con->dir.z = z;
}

void		modif_ray(t_item *item, float ray)
{
	if (item->sp != NULL)
		item->sp->ray = ray;
	else if (item->pl != NULL)
		item->pl->ray = ray;
	else if (item->cyl != NULL)
		item->cyl->ray = ray;
	else if (item->con != NULL)
		return;
}

void		modif_item(t_env *env, int i, char **split)
{
	t_item	*item;

	item = env->item;
	while (item && i-- > 0)
		item = item->next;
	if (ft_strcmp(split[2], "x") == 0)
		modif_x(item, ft_fatoi(split[3]));
	else if (ft_strcmp(split[2], "y") == 0)
		modif_y(item, ft_fatoi(split[3]));
	else if (ft_strcmp(split[2], "z") == 0)
		modif_z(item, ft_fatoi(split[3]));
	else if (ft_strcmp(split[2], "dirx") == 0)
		modif_dirx(item, ft_fatoi(split[3]));
	else if (ft_strcmp(split[2], "diry") == 0)
		modif_diry(item, ft_fatoi(split[3]));
	else if (ft_strcmp(split[2], "dirz") == 0)
		modif_dirz(item, ft_fatoi(split[3]));
	else if (ft_strcmp(split[2], "ray") == 0)
		modif_ray(item, ft_fatoi(split[3]));
}
