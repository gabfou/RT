/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightauxi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 21:42:38 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/08 21:42:40 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			luminatorstupid(t_thr *f, t_pd *lvec)
{
	if (f->cam->zebre)
	{
		lvec->dir.x = lvec->dir.x * sin(f->inter.t);
		lvec->dir.y = lvec->dir.y * sin(f->inter.t);
		lvec->dir.z = lvec->dir.z * sin(f->inter.t);
	}
	if (f->cam->rfu)
	{
		f->liginter.diff.r = sin(f->inter.pos.x);
		f->liginter.diff.g = sin(f->inter.pos.y);
		f->liginter.diff.b = sin(f->inter.pos.z);
	}
}

unsigned int	get_color(int r, int g, int b)
{
	r = (255 < r) ? 255 : r;
	g = (255 < g) ? 255 : g;
	b = (255 < b) ? 255 : b;
	return ((r & 0xff) + ((g & 0xff) << 8) + ((b & 0xff) << 16));
}
