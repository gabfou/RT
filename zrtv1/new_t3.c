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

t_env		*new_t_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->screen = new_t_screen();
	env->image = NULL;
	env->t = NULL;
	env->endiant = 0;
	env->limg = NULL;
	env->cam = NULL;
	env->item = NULL;
	env->light = NULL;
	env->fcolor = 0;
	env->done = 0;
	env->ft = 0;
	env->nbr = 0;
	env->prev = NULL;
	env->next = NULL;
	return (env);
}
