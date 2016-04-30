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
	t_item	*lst;
	int		cnb[200];

	idciator(env, *pd, cnb);
	lst = f->item;
	while (lst != NULL)
	{
		if (lst->cnb == NULL || checkcarre(cnb, lst->cnb))
		{
			if (lst->sp != NULL)
				check_sphere(lst, pd, inter);
			else if (lst->pl != NULL)
				check_plane(lst, pd, inter);
			else if (lst->cyl != NULL)
				check_cyl(lst, pd, inter);
			else if (lst->con != NULL)
				check_con(lst, pd, inter);
			else if (lst->tr != NULL)
				check_triangle(lst, pd, inter);
		}
		lst = lst->next;
	}
}

void		t_inter_set(t_inter *inter)
{
	inter->norm.x = 0;
	inter->norm.y = 0;
	inter->norm.z = 0;
	inter->pos.x = 0;
	inter->pos.y = 0;
	inter->pos.z = 0;
	inter->t = -1;
	inter->trans = NULL;
	inter->diff = new_t_color(1, 1, 1);
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

void		creator(t_cor *c)
{
	double		x;
	double		y;
	t_pd		*pd;
	t_thr		*f;
	int			l;

	f = new_t_thr(c);
	l = 0;
	pd = new_t_pd();
	pd->dir = new_t_vec(0, 0, 0);
	f->inter = new_t_inter();
	f->liginter = new_t_inter();
	while (f->env->nbr > f->done)
	{
		while (f->cam != NULL)
		{
			y = f->miny;
			while (y++ < f->maxy)
			{
				x = f->minx;
				while (x++ < f->maxx)
				{
					pd->pos = f->cam->pos;
					f->fcolor = 0x000000;
					t_inter_set(&(f->inter));
					calc_dir(&(pd->dir), x, y, f);
					impactor(f->env, pd, f, &(f->inter));
					c->env->mircount = 0;
					if (f->inter.ref > 0 && c->env->mircount++ < 8)
						ref(f, c, pd);
					set_inter_pos(&(f->inter), pd);
					luminator(f->env, f);
					pixel_to_image(x, y, f->fcolor, f->limg);
					f->limg->l++;
				}
			}
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
