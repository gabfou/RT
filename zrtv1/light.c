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
	light->color = get_color(ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]));
	light->next = NULL;
	return (light);
}

FLOAT_SIZE	l_color(const FLOAT_SIZE i, const FLOAT_SIZE a)
{
	return (i * (a / 255));
	if ((i - a) > 0)
		return (i - a);
	return (0);
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

void		luminator(t_env *e, t_thr *f)
{
	t_pd			lvec;
	t_light			*ltmp;
	FLOAT_SIZE		trans;

	ltmp = f->light;
	f->impactmod = 0;
	while (f->light)
	{
		t_inter_set(&(f->liginter));
		lvec.pos = f->light->pos;
		lvec.dir = normalizator_ret(new_t_vec(f->inter.pos.x - f->light->pos.x,
		f->inter.pos.y - f->light->pos.y, f->inter.pos.z - f->light->pos.z));
		impactor(e, &lvec, f, &(f->liginter));
		set_inter_pos(&(f->liginter), &lvec);
		if (comparator_pos(&(f->liginter), &(f->inter)) == 0)
		{
			f->light = f->light->next;
			continue;
		}
		colorcalculator(f, lvec, &trans);
		f->light = f->light->next;
	}
	f->impactmod = 1;
	f->light = ltmp;
	trans = 0;
	if (f->inter.trans != NULL)
	{
		trans = trans_calculator(f->inter.trans, f->inter.t);
		f->fcolor = transparencator(f->fcolor, trans);
	}
}
