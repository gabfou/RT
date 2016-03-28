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

t_cam		*new_t_cam()
{
	t_cam	*cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->pos.x = 0;
	cam->pos.y = 0;
	cam->pos.z = 0;
	cam->dir.x = 1;
	cam->dir.y = 0;
	cam->dir.z = 0;
	cam->angle = 0;
	return (cam);
}

t_limg		*new_t_limg(t_leviatenv *env)
{
	t_limg	*ret;

	ret = malloc(sizeof(t_limg));
	ret->image = mlx_new_image(env->mlx, L_SIZE, H_SIZE);
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

t_inter		*new_t_inter()
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	inter->t = -1;
	inter->norm = new_t_vec(0, 0, 0);
	inter->pos = new_t_vec(0, 0, 0);
	inter->trans = NULL;
	inter->ref = -1;
	inter->diff = new_t_color(1, 1, 1);
	return (inter);
}