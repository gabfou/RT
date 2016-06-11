/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:57:17 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/10 09:57:18 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_proto		*new_t_proto()
{
	t_proto	*proto;

	proto = malloc(sizeof(t_proto));
	proto->x = 0;
	proto->y = 0;
	proto->z = 0;
	proto->color = new_t_color(0, 0, 0);
	proto->droite = NULL;
	proto->gauche = NULL;
	return (proto);
}

t_phcol		*new_phcol(t_color color, FLOAT_SIZE dist)
{
	t_phcol	*tmp;

	//printf("color =%d\n", get_color(color.r, color.g, color.b));
//	printf("dist =%f\n\n", dist);
	tmp = malloc(sizeof(t_phcol));
	tmp->color = new_t_color(color.r, color.g, color.b);
	tmp->dist = dist;
	tmp->next = NULL;
	return (tmp);
}

t_thr		new_t_thr_spec(t_env *env)
{
	t_thr		f;

	f.done = 0;
	f.env = env;
	f.minx = 0;
	f.maxx = 0;
	f.miny = 0;
	f.maxy = 0;
	f.item = env->item;
	f.light = env->light;
	f.cam = env->cam;
	f.limg = env->limg;
	f.impactmod = 1;
	setthrcnb(&f);
	return (f);
}
