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

int		itemadator(t_env *env, t_item *item)
{
	t_item		*copy;
	int			i;

	i = 1;
	if (!env->item)
		env->item = item;
	else
	{
		copy = env->item;
		while (copy->next)
		{
			i++;
			copy = copy->next;
		}
		copy->next = item;
	}
	return (i);
}

void	next_elem(t_list **elems)
{
	*elems = (*elems)->next;
}
