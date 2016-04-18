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

t_vec		new_t_vec(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z)
{
	t_vec		pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}

t_pd		*new_t_pd(void)
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

t_inter		new_t_inter(void)
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
