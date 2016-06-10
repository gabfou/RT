 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:10:49 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/12 18:10:50 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		impactor(t_env *env, t_pd *pd, t_thr *f, t_inter *inter)
{
	int				i;

	idciator(env, *pd, f->cnb, f->use);
	i = -1;
	while (f->cnb[++i])
	{
		if (f->cnb[i]->sp != NULL)
			check_sphere(f->cnb[i], pd, inter, f->impactmod);
		else if (f->cnb[i]->tr != NULL)
			check_triangle(f->cnb[i], pd, inter, f);
		else if (f->cnb[i]->pl != NULL)
			check_plane(f->cnb[i], pd, inter, f->impactmod);
		else if (f->cnb[i]->cyl != NULL)
			check_cyl(f->cnb[i], pd, inter, f->impactmod);
		else if (f->cnb[i]->con != NULL)
			check_con(f->cnb[i], pd, inter, f->impactmod);
		f->use[f->cnb[i]->nb] = 0;
	}
}

void		calc_dir(t_vec *dir, FLOAT_SIZE x, FLOAT_SIZE y, t_thr *f)
{
	dir->x = (f->cam->upleft.x +
		(f->cam->up.x * f->env->screen.scrh * y / f->env->screen.resh)
		+ (f->cam->right.x * f->env->screen.scrl * x / f->env->screen.resl));
	dir->y = (f->cam->upleft.y +
		(f->cam->up.y * f->env->screen.scrh * y / f->env->screen.resh)
		+ (f->cam->right.y * f->env->screen.scrl * x / f->env->screen.resl));
	dir->z = (f->cam->upleft.z +
		(f->cam->up.z * f->env->screen.scrh * y / f->env->screen.resh)
		+ (f->cam->right.z * f->env->screen.scrl * x / f->env->screen.resl));
	normalizator(dir);
}

void		pixelator(t_thr *f, t_pd *pd, int x, int y)
{
	pd->pos = f->cam->pos;
	f->fcolor = 0x000000;
	t_inter_set(&(f->inter));
	calc_dir(&(pd->dir), x, y, f);
	impactor(f->env, pd, f, &(f->inter));
	set_inter_pos(&(f->inter), pd);
	if (f->inter.ref > 0)
		f->fcolor = transroitor(&(f->inter), f, pd, 0);
	else
		f->fcolor = amaterasu(f, &f->inter);
	pixel_to_image(x, y, f->fcolor, f->limg);
	f->limg->l++;
}

void		panoramiquator(t_thr *f)
{
	double		x;
	double		y;
	t_pd		pd;

	y = f->miny;
	while (y++ < f->maxy)
	{
		x = f->minx;
		while (x++ < f->maxx)
			pixelator(f, &pd, x, y);
	}
}

void		creator(t_cor *c)
{
	t_thr		*f;
	int			l;

	f = new_t_thr(c);
	l = 0;
	f->inter = new_t_inter();
	f->liginter = new_t_inter();
	while (f->env->nbr > f->done)
	{
		while (f->cam != NULL)
		{
			panoramiquator(f);
			nextcam(f);
			ft_putstr("NEXTEUH");
		}
		ft_putendl("next env");
		f->env->done++;
		f->done++;
		f->env = f->env->next;
		f = set_again_t_thr(f);
	}
	free(f);
	pthread_exit(NULL);
}
