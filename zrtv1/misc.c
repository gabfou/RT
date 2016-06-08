/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 20:33:02 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/15 20:33:03 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	pixel_to_image(int x, int y, unsigned int color, t_limg *limg)
{
	unsigned int	off;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	off = y * limg->sline + x * limg->bpp / 8;
	if (x < 0 || y < 0
		|| off > (unsigned int)(959 * limg->sline + 959 * limg->bpp / 8 - 2))
		return ;
	limg->img[off] = (r > 255) ? 255 : r;
	limg->img[off + 1] = (g > 255) ? 255 : g;
	limg->img[off + 2] = (b > 255) ? 255 : b;
}

void	itemadator(t_env *env, t_item *item)
{
	t_item		*copy;

	if (item->nega == 0)
	{
		if (!env->item)
			env->item = item;
		else
		{
			copy = env->item;
			while (copy->next)
				copy = copy->next;
			copy->next = item;
		}
		return ;
	}
	if (!env->item)
		ft_error("object negatif no parrent");
	else
	{
		copy = env->item;
		while (copy->next)
			copy = copy->next;
		item->next = copy->negal;
		copy->negal = item;
	}
}

void	next_elem(t_list **elems)
{
	*elems = (*elems)->next;
}

void	rotationator(t_vec *vec, double angle)
{
	t_vec tmp;

	if (angle == 0)
		return ;
	tmp.x = vec->z;
	tmp.y = vec->y;
	vec->z = cos(angle) * tmp.x - sin(angle) * tmp.y;
	vec->y = sin(angle) * tmp.x + cos(angle) * tmp.y;
}
