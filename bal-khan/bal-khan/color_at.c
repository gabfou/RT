/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:27:12 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:27:15 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned long			colorizator(t_list *list, t_vect3d inter\
							, t_env *e)
{
	unsigned long	ret;

	if (list->type == 'a')
	{
		ret = color_at(e, inter);
	}
	if (list->type == 'b')
	{
		ret = color_at_p(e, inter);
	}
	if (list->type == 'c')
	{
		ret = color_at_c(e, inter);
	}
	if (list->type == 'd')
	{
		ret = color_at_cone(e, inter);
	}
	return (ret);
}

inline unsigned long	color_at(t_env *e, t_vect3d inter)
{
	unsigned long	color;
	double			r;
	t_vect3d		normal;
	t_vect3d		light_prim;

	normal = vector_sub(inter, e->list->center);
	normal = normalizator(normal);
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product(light_prim, normal);
	if (r >= 0)
		r = 1;
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	if ((r - ((int)inter.x | (int)inter.y | (int)inter.z)) < 0)
		r = ((int)inter.x | (int)inter.y | (int)inter.z) - r;
	else
		r -= (int)inter.x | (int)inter.y | (int)inter.z;
	color = ((int)r << 0 | (int)r / 2 << 8 | (int)r / 2 << 16 | (0 << 24));
	return (color);
}

inline unsigned long	color_at_p(t_env *e, t_vect3d inter)
{
	unsigned long	color;
	double			r;
	t_vect3d		normal;
	t_vect3d		light_prim;

	normal = e->list->orient;
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product(light_prim, normal);
	if (r >= 0)
		r = 1;
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	color = ((int)r << 0 | (int)r << 8 | (int)r << 16 | (0 << 24));
	return (color);
}

inline unsigned long	color_at_c(t_env *e, t_vect3d inter)
{
	unsigned long	color;
	double			r;
	t_vect3d		normal;
	t_vect3d		light_prim;

	normal = vector_sub(vector_proj_vector(normalizator(vector_sub(\
		e->list->center, inter)), e->list->orient), normalizator(\
	vector_sub(e->list->center, inter)));
	normal = normalizator(normal);
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product((light_prim), (normal));
	if (r >= 0)
		r = 1;
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	if ((r - ((int)inter.x | (int)inter.y | (int)inter.z)) < 0)
		r = ((int)inter.x | (int)inter.y | (int)inter.z) - r;
	else
		r -= (int)inter.x | (int)inter.y | (int)inter.z;
	color = ((int)r / 2 << 0 | (int)r << 8 | (int)r / 2 << 16 | (0 << 24));
	return (color);
}

inline unsigned long	color_at_cone(t_env *e, t_vect3d inter)
{
	unsigned long	color;
	double			r;
	t_vect3d		normal;
	t_vect3d		light_prim;

	normal = vector_sub(vector_proj_vector(normalizator(vector_sub(\
		e->list->center, inter)), e->list->orient), normalizator(vector_sub(\
		e->list->center, inter)));
	normal = normalizator(normal);
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product((light_prim), (normal));
	if (r >= 0)
		r = 1;
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	if ((r - ((int)inter.x ^ (int)inter.y)) < 0)
		r = ((int)inter.x ^ (int)inter.y) - r;
	else
		r -= (int)inter.x ^ (int)inter.y;
	color = ((int)r / 2 << 0 | (int)r / 2 << 8 | (int)r << 16 | (0 << 24));
	return (color);
}
