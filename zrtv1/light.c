/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 23:08:44 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 23:08:45 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*fill_t_light(char **t, t_light *light)
{
	light->pos = new_t_vec(ft_fatoi(t[1]), ft_fatoi(t[2]), ft_fatoi(t[3]));
	light->rcolor.r = ft_fatoi(t[4]);
	light->rcolor.g = ft_fatoi(t[5]);
	light->rcolor.b = ft_fatoi(t[6]);
	light->next = NULL;
	return (light);
}

int			comparator_pos(const t_inter *inter, const t_inter *einter)
{
	if ((inter->pos.x > einter->pos.x - 0.00001
		&& inter->pos.x < einter->pos.x + 0.00001)
		&& (inter->pos.y > einter->pos.y - 0.00001
			&& inter->pos.y < einter->pos.y + 0.00001)
		&& (inter->pos.z > einter->pos.z - 0.00001
			&& inter->pos.z < einter->pos.z + 0.00001))
	{
		return (1);
	}
	return (0);
}

t_color		lumi_calc(t_thr *f, t_pd *lvec,
	t_color color, t_inter inter)
{
	FLOAT_SIZE		angle[2];

	luminatorstupid(f, lvec);
	angle[0] = M_PI_2 - acos(dot_prod(lvec->dir, inter.norm));
	angle[1] = pow(dot_prod(lvec->dir, inter.norm), 50);
	angle[0] = (angle[0] > 0) ? angle[0] : -angle[0];
	angle[1] = (angle[1] > 0) ? angle[1] : -angle[1];
	color.r = ((angle[0] / 4 * ((f->light->rcolor.r)) * 2 / M_PI) +
	(angle[1] / 4 * ((f->light->rcolor.r)) * 2 / M_PI))
	* f->liginter.diff.r + (color.r);
	color.g = ((angle[0] / 4 * ((f->light->rcolor.g)) * 2 / M_PI)
		+ (angle[1] / 4 * ((f->light->rcolor.g)) * 2 / M_PI))
		* f->liginter.diff.g + (color.g);
	color.b = ((angle[0] / 4 * ((f->light->rcolor.b)) * 2 / M_PI)
		+ (angle[1] / 4 * ((f->light->rcolor.b)) * 2 / M_PI))
		* f->liginter.diff.b + (color.b);
	return (color);
}

void		lumi_auxi(t_thr *f, t_pd *lvec, t_inter inter)
{
	t_inter_set(&f->liginter);
	lvec->pos = f->light->pos;
	lvec->dir = new_t_vec(inter.pos.x - f->light->pos.x, inter.pos.y
	- f->light->pos.y, inter.pos.z - f->light->pos.z);
	normalizator(&lvec->dir);
	impactor(f->env, lvec, f, &f->liginter);
	set_inter_pos(&f->liginter, lvec);
}

t_color		luminator(t_thr *f, t_inter *inter)
{
	t_pd			lvec;
	t_light			*ltmp;
	t_color			retcolor;

	ltmp = f->light;
	retcolor = new_t_color(0, 0, 0);
	f->impactmod = 0;
	if (inter->t <= 0 || f->light == NULL)
		return (retcolor);
	while (f->light != NULL)
	{
		lumi_auxi(f, &lvec, *inter);
		if (comparator_pos(&(f->liginter), (inter)) == 0)
		{
			f->light = f->light->next;
			continue;
		}
		retcolor = lumi_calc(f, &lvec, retcolor, *inter);
		f->light = f->light->next;
	}
	f->impactmod = 1;
	f->light = ltmp;
	return (retcolor);
}
