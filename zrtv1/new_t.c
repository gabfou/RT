/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:07:27 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:07:28 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_item			*new_t_item()
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->pl = NULL;
	item->sp = NULL;
	item->cyl = NULL;
	item->con = NULL;
	item->next = NULL;
	item->cnb = NULL;
	item->texture = NULL;
	item->mat = new_t_mat("niark");
	return(item);
}

t_cam		*new_t_cam()
{
	t_cam	*cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->pos.x = 0;
	cam->pos.y = 0;
	cam->pos.z = 0;
	cam->dir.x = 0;
	cam->dir.y = 0;
	cam->dir.z = 1;
	cam->angle = 0;
	cam->next = NULL;
	return (cam);
}

t_cnb		*new_t_cnb(int i)
{
	t_cnb	*cnb;

	cnb = (t_cnb*)malloc(sizeof(t_cnb));
	cnb->i = i;
	cnb->next = NULL;
	return (cnb);
}

// t_carre		*new_t_carre()
// {
// 	t_carre	*carre;

// 	carre = (t_carre*)malloc(sizeof(t_carre));
// 	carre->pos.x = 0;
// 	carre->pos.y = 0;
// 	carre->pos.z = 0;
// 	carre->dir.x = 0;
// 	carre->dir.y = 0;
// 	carre->dir.z = 1;
// 	carre->angle = 0;
// 	carre->next = NULL;
// 	return (carre);
// }


t_screen		new_t_screen()
{
	t_screen	screen;

	screen.h = H_SIZE;
	screen.l = L_SIZE;
	screen.scrl = SCR_L;
	screen.scrh = SCR_H;
	screen.scrd = SCR_DIST;
	screen.li = SCR_L / L_RES;
	screen.hi =  SCR_H / H_RES;
	screen.resl =  L_RES;
	screen.resh =  H_RES;
	return (screen);
}

t_limg		*new_t_limg(t_leviatenv *env)
{
	t_limg	*ret;

	ret = malloc(sizeof(t_limg));
	ret->image = mlx_new_image(env->mlx, env->lenv->screen.l, env->lenv->screen.h);
	ret->img = mlx_get_data_addr(ret->image, &ret->bpp, &ret->sline, &env->lenv->endiant);
	ret->i = 1;
	ret->l = 0;
	ret->k = 1;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

t_trans			*new_t_trans(FLOAT_SIZE t, FLOAT_SIZE colabs)
{
	t_trans	*trans;

	trans = (t_trans *)malloc(sizeof(t_trans));
	trans->t = t;
	trans->colabs = colabs;
	trans->next = NULL;
	return (trans);
}

t_vec		new_t_vec(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z)
{
	t_vec		pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}

t_pd		*new_t_pd()
{
	t_pd		*cam;

	cam = malloc(sizeof(t_pd));
	return (cam);
}

t_color		new_t_color(FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_mat		new_t_mat(char *name)
{
	t_mat	mat;

	mat.name = ft_strdup(name);
	mat.shiny = 0;
	mat.shinystr = 0;
	mat.trans = 0;
	mat.ref = -1;
	mat.diff = new_t_color(1, 1, 1);
	return (mat);
}

t_inter		new_t_inter()
{
	t_inter	inter;

	inter.t = -1;
	inter.norm = new_t_vec(0, 0, 0);
	inter.pos = new_t_vec(0, 0, 0);
	inter.trans = NULL;
	inter.ref = -1;
	inter.diff = new_t_color(1, 1, 1);
	return (inter);
}
