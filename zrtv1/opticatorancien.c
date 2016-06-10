/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opticatorancien.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 21:43:58 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/09 21:43:59 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	miroiratorvcalculator2(t_vec ray, t_vec norm)
{
	return (normalizator_ret(add_vec(norm,
		normalizator_ret(add_vec(ray, norm)))));
}

void	ref2(t_thr *f, t_pd *pd)
{
	set_inter_pos(&(f->inter), pd);
	pd->dir = normalizator_ret(miroiratorvcalculator2(pd->dir, f->inter.norm));
	pd->pos = f->inter.pos;
	f->fcolor = 0x000000;
	f->inter = new_t_inter();
	t_inter_set(&(f->inter));
	impactor(f->env, pd, f, &(f->inter));
}
