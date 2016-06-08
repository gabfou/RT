/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatorauxi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 00:38:07 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/16 00:38:08 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_check(t_env *env)
{
	if (env->item == NULL)
		ft_putendl("NULLLLLL");
	if (env->item->sp == NULL && env->item->pl == NULL)
		ft_putendl(" SP NULLLLLL");
	print_vec(env->cam->pos);
	print_vec(env->cam->dir);
	print_vec(env->cam->up);
	print_vec(env->cam->right);
}

void		nextcam(t_thr *f)
{
	if (f)
	{
		f->cam = f->cam->next;
		f->limg->i++;
		f->limg = f->limg->next;
	}
}

void		setthrcnb(t_thr *f)
{
	t_item		*item;
	int			i;

	f->cnb = malloc(sizeof(t_item*) * (f->env->nb_obj + 2));
	f->use = malloc(sizeof(int) * (f->env->nb_obj + 2));
	i = -1;
	while (++i < f->env->nb_obj + 2)
		f->use[i] = 0;
	item = f->item;
	i = -1;
	while (item)
	{
		if (item->pl != NULL)
			f->cnb[++i] = item;
		else if (item->cyl != NULL)
			f->cnb[++i] = item;
		else if (item->con != NULL)
			f->cnb[++i] = item;
		item = item->next;
	}
	f->cnb[++i] = NULL;
}

t_thr		*new_t_thr(t_cor *c)
{
	t_thr		*f;

	f = malloc(sizeof(t_thr));
	f->done = 0;
	f->env = c->env;
	f->minx = c->minx;
	f->maxx = c->maxx;
	f->miny = c->miny;
	f->maxy = c->maxy;
	f->item = f->env->item;
	f->light = f->env->light;
	f->cam = f->env->cam;
	f->limg = f->env->limg;
	f->impactmod = 1;
	setthrcnb(f);
	return (f);
}

t_thr		*set_again_t_thr(t_thr *f)
{
	free(f->cnb);
	free(f->use);
	f->item = f->env->item;
	f->light = f->env->light;
	f->cam = f->env->cam;
	f->limg = f->env->limg;
	setthrcnb(f);
	return (f);
}
