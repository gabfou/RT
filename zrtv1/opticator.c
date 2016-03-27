/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opticator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 00:28:29 by gfournie          #+#    #+#             */
/*   Updated: 2016/02/23 00:28:37 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

// inline t_v	miroiratorvcalculator(t_v ray, t_v norm)
// {

// 	return (normalisator(vav(norm, normalisator(vav(ray, norm)))));
// }

void	ref(t_thr *f, t_cor *c, t_pd *pd)
{
	// ft_putendl("niark");
	set_inter_pos(f->inter, pd);
	pd->dir = normalizator_ret(f->inter->norm);
	pd->pos = f->inter->pos;
	// pd->pos = add_vec(f->inter->pos, vec_mult(pd->dir, -1));
	f->fcolor = 0x000000;
	f->inter = new_t_inter();
	t_inter_set(f->inter);
	impactor(c->env, pd, f, f->inter);
}