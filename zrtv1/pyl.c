/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:17:03 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:17:04 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cyl	*t_cyl_creator(double x, double y, double z, double x1, double y1, double z1, double ray)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	cyl->pos = new_t_vec(x, y, z);
	cyl->dir = normalizator_ret(new_t_vec(x1, y1, z1));
	cyl->ray = ray;
	return (cyl);
}

void		check_cyl(t_item *item, t_pd *s, t_inter *inter)
{
	(void)item;
	(void)s;
	(void)inter;
}