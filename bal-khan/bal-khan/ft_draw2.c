/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:29:47 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:29:51 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			put_pix_img(t_env *e, int x, int y, unsigned long color)
{
	unsigned int	place;
	int				r;
	int				g;
	int				b;

	r = (color & 0xFFFFFF) >> 16;
	g = (color & 0xFFFF) >> 8;
	b = (color & 0xFF);
	if (x >= 0 && x < e->s_x * 4)
	{
		place = y * e->s_x * 4;
		place += x * 4;
		if (place < (size_t)((e->s_x * e->s_y) * 4))
		{
			e->data[place] = r;
			e->data[place + 1] = g;
			e->data[place + 2] = b;
		}
	}
}

int				draw(t_env *e)
{
	ray_trace(e);
	return (0);
}
