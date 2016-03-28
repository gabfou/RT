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

t_vec	miroiratorvcalculator(t_vec ray, t_vec norm)
{

	return (normalizator_ret(add_vec(norm, normalizator_ret(add_vec(ray, norm)))));
}

void	ref(t_thr *f, t_cor *c, t_pd *pd)
{
	// ft_putendl("niark");
	set_inter_pos(f->inter, pd);
	pd->dir = normalizator_ret(miroiratorvcalculator(pd->dir, f->inter->norm));
	// pd->dir = normalizator_ret(f->inter->norm);
	pd->pos = f->inter->pos;
	// pd->pos = add_vec(f->inter->pos, vec_mult(pd->dir, -1));
	f->fcolor = 0x000000;
	f->inter = new_t_inter();
	t_inter_set(f->inter);
	impactor(c->env, pd, f, f->inter);
}