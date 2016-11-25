/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifitem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:40:07 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/06/11 22:47:40 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		modif_dirz(t_item *item, const float z)
{
	if (item->pl != NULL)
		item->pl->dir.z = z;
	else if (item->cyl != NULL)
		item->cyl->dir.z = z;
	else if (item->con != NULL)
		item->con->dir.z = z;
}

void		modif_ray(t_item *item, const float ray)
{
	if (item->sp != NULL)
		item->sp->ray = ray;
	else if (item->pl != NULL)
		item->pl->ray = ray;
	else if (item->cyl != NULL)
		item->cyl->ray = ray;
	else if (item->con != NULL)
		return ;
}

void		modif_angle(t_item *item, const float angle)
{
	if (item->sp != NULL)
		return ;
	else if (item->pl != NULL)
		return ;
	else if (item->cyl != NULL)
		return ;
	else if (item->con != NULL)
		item->con->ang = angle;
}

void		modif_item(t_item *current, char **split)
{
	if (!current)
		return ;
	if (ft_strcmp(split[1], "x") == 0)
		modif_x(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "y") == 0)
		modif_y(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "z") == 0)
		modif_z(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "dirx") == 0)
		modif_dirx(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "diry") == 0)
		modif_diry(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "dirz") == 0)
		modif_dirz(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "ray") == 0)
		modif_ray(current, ft_fatoi(split[2]));
	else if (ft_strcmp(split[1], "angle") == 0)
		modif_angle(current, ft_fatoi(split[2]));
}
