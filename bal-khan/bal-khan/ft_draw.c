/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:29:34 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:29:12 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned long	color_torus(t_env *e, t_vect3d inter, t_torus *torus)
{
	unsigned long	color;
	double			r;
	t_vect3d		normal;
	t_vect3d		light_prim;

	double		k;
	t_vect3d	A;
	double		m;

	k = dot_product(normalizator(vector_sub(inter, torus->center)), torus->axis);
	A = normalizator(vector_sub(inter, vector_mult(torus->axis, k)));
	m = sqrt(pow(torus->circl_r, 2) - pow(k, 2));

	normal = vector_sub(normalizator(vector_sub(inter, A)), normalizator(vector_mult(normalizator(vector_sub(torus->center, A)), (m / (torus->torus_r + m)))));
	normal = normalizator(normal);
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product(light_prim, normal);
	if (r >= 0)
		r = 1;
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	color = ((int)r << 0 | (int)r / 2 << 8 | (int)r / 2 << 16 | (0 << 24));//color=0xFF0000;
	return (color);
}

void			ray_trace(t_env *e)
{
	double			x;
	double			y;
	unsigned long	color;
	int				fd;

	x = -1;
	y = -1;
	e->ray.origin = e->cam;
	// t_torus			torus;
	// torus = torus_creator();
	init_image(&fd, e);
	while (++x < e->s_x)
	{
		y = -1;
		while (++y < e->s_y)
		{
			// unsigned long	real_color;
			// int	inter_moy;

			// inter_moy = 0;
			// real_color = 0x000000;
			// calc_dir(e, x, y);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x - 1.0, y - 1.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x + 1.0, y - 1.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x - 1.0, y + 1.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x + 1.0, y + 1.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x - 1.0, y + 0.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x + 1.0, y + 0.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x + 0.0, y + 1.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// calc_dir(e, x + 0.0, y - 1.0);
			// e->ray.direct = normalizator((e->ray.direct));
			// color = 0;
			// if (get_nearest(e, &color))
			// {
			// 	inter_moy++;
			// 	color_add(&real_color, color);
			// 	color_divide(&real_color, 2);
			// }
			// if (inter_moy && get_nearest(e, &color))
			// {
			// 	// color_divide(&real_color, inter_moy);
			// 	put_pix_img(e, x, y, real_color);
			// }
			calc_dir(e, x, y);
			e->ray.direct = normalizator((e->ray.direct));
			color = 0;
			if (get_nearest(e, &color))
			{
				put_pix_img(e, x, y, color);
			}

			// if (inter_spine_in_brine(&torus, e->ray).inter)
			// 	put_pix_img(e, x, y, color_torus(e, inter_spine_in_brine(&torus, e->ray), &torus));
		}
	}
	write(fd, e->data, e->s_y * e->s_x * 4);
	close(fd);
	ft_putendl("finish vernish polish");
}

t_vect3d		inter_point(t_list *list, t_ray ray, t_env *e)
{
	t_vect3d	ret;

	if (list->type == 'a')
	{
		ret = inter_sphere_point(list, ray, e);
	}
	if (list->type == 'b')
	{
		ret = inter_plane_point(list, ray);
	}
	if (list->type == 'c')
	{
		ret = inter_cylinder_point(list, ray);
	}
	if (list->type == 'd')
	{
		ret = inter_cone_point(list, ray);
	}
	return (ret);
}

t_list			*get_nearest(t_env *e, unsigned long *color)
{
	t_list		*ret;
	t_list		**begin;
	t_vect3d	temp_t;
	t_vect3d	i;

	begin = (t_list**)malloc(sizeof(t_list*));
	(*begin) = e->list;
	ret = NULL;
	temp_t.t = 9999999999;
	while (e->list)
	{
		if (e->list->type != 'l' && (i = inter_point(e->list, e->ray, e)).inter
			&& i.t < temp_t.t)
		{
			temp_t = i;
			ret = e->list;
			*color = colorizator(ret, i, e);
		}
		e->list = e->list->next;
	}
	e->list = (*begin);
	free(begin);
	if (ret)
		encounter_item(e, temp_t, ret, color);
	return (ret);
}

void			encounter_item(t_env *e, t_vect3d inter, t_list *ret,\
								unsigned long *color)
{
	t_list		**begin;
	t_ray		new_ray;
	t_vect3d	something_in_the_way;

	begin = (t_list**)malloc(sizeof(t_list*));
	(*begin) = e->list;
	new_ray.origin = inter;
	new_ray.direct = normalizator(vector_sub(e->lights->center, inter));
	while (e->list)
	{
		if (e->list->type != 'l' && e->list != ret)
		{
			something_in_the_way = inter_point(e->list, new_ray, e);
			if (something_in_the_way.inter && vector_len(vector_sub(\
				e->lights->center, something_in_the_way)) < vector_len(\
				vector_sub(e->lights->center, inter)) - 0.000001)
				color_divide_two(color);
		}
		e->list = e->list->next;
	}
	e->list = (*begin);
	free(begin);
}

void			color_divide_two(unsigned long *color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (*color & 0xFF);
	g = (*color & 0xFF00) >> 8;
	r = (*color & 0xFF0000) >> 16;
	r = (r / (2));
	g = (g / (2));
	b = (b / (2));
	(*color) = (r << 16) | (g << 8) | (b);
	(*color) = 0;
}

void			color_divide(unsigned long *color, int divider)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (*color & 0xFF);
	g = (*color & 0xFF00) >> 8;
	r = (*color & 0xFF0000) >> 16;
	r = (r / (divider));
	g = (g / (divider));
	b = (b / (divider));
	(*color) = (r << 16) | (g << 8) | (b);
}

void		color_add(unsigned long *color1, unsigned long color2)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (*color1 & 0xFF) + (color2 & 0xFF);
	g = ((*color1 & 0xFF00) >> 8) + ((color2 & 0xFF00) >> 8);
	r = ((*color1 & 0xFF0000) >> 16) + ((color2 & 0xFF0000) >> 16);
	(*color1) = ((r << 16) | (g << 8) | (b));
}