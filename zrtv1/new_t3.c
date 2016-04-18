/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 02:08:29 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/16 02:08:30 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_limg		*new_t_limg(t_leviatenv *env)
{
	t_limg	*ret;

	ret = malloc(sizeof(t_limg));
	ret->image = mlx_new_image(env->mlx,
		env->lenv->screen.l, env->lenv->screen.h);
	ret->img = mlx_get_data_addr(ret->image, &ret->bpp,
		&ret->sline, &env->lenv->endiant);
	ret->i = 1;
	ret->l = 0;
	ret->k = 1;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

t_trans		*new_t_trans(FLOAT_SIZE t, FLOAT_SIZE colabs)
{
	t_trans	*trans;

	trans = (t_trans *)malloc(sizeof(t_trans));
	trans->t = t;
	trans->colabs = colabs;
	trans->next = NULL;
	return (trans);
}
