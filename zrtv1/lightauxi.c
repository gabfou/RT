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

// void			colorcalculator(t_thr *f, t_pd lvec, FLOAT_SIZE *trans)
// {
// 	FLOAT_SIZE angle;
// 	FLOAT_SIZE angle2;

// 	luminatorstupid(f, &lvec);
// 	angle2 = pow(dot_prod(lvec.dir, f->inter.norm), 50);
// 	angle = M_PI_2 - acos(dot_prod(lvec.dir, f->inter.norm));
// 	angle = (angle > 0) ? angle : -angle;
// 	angle2 = (angle2 > 0) ? angle2 : -angle2;
// 	*trans = 0;
// 	if (f->liginter.trans != NULL)
// 		*trans = trans_calculator(f->liginter.trans, f->liginter.t);
// 	f->fcolor = get_color(
// 		(((angle / 4 * ((f->light->rcolor >> 0) & 0xFF) * 2 / M_PI)
// 		* f->liginter.diff.r
// 		+ (angle2 / 4 * ((f->light->rcolor >> 0) & 0xFF) * 2 / M_PI))
// 		+ ((f->fcolor >> 0) & 0xFF)),
// 		(((angle / 4 * ((f->light->rcolor >> 8) & 0xFF) * 2 / M_PI)
// 		* f->liginter.diff.g
// 		+ (angle2 / 4 * ((f->light->rcolor >> 8) & 0xFF) * 2 / M_PI))
// 		+ ((f->fcolor >> 8) & 0xFF)),
// 		(((angle / 4 * ((f->light->rcolor >> 16) & 0xFF) * 2 / M_PI)
// 		* f->liginter.diff.b
// 		+ (angle2 / 4 * ((f->light->rcolor >> 16) & 0xFF) * 2 / M_PI))
// 		+ ((f->fcolor >> 16) & 0xFF)));
// }

unsigned int	get_color(int r, int g, int b)
{
	r = (255 < r) ? 255 : r;
	g = (255 < g) ? 255 : g;
	b = (255 < b) ? 255 : b;
	return ((r & 0xff) + ((g & 0xff) << 8) + ((b & 0xff) << 16));
}
