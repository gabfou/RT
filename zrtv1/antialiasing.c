/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:42:39 by gfournie          #+#    #+#             */
/*   Updated: 2016/02/25 18:42:46 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		put_pixelantialiaserauxi(t_env *e, unsigned char *c,
	register int x, register int y)
{
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8] =
	(c[0] + c[1] + c[2] + c[3] + c[4]) / 5;
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 1] =
	(c[5] + c[6] + c[7] + c[8] + c[9]) / 5;
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 2] =
	(c[10] + c[11] + c[12] + c[13] + c[14]) / 5;
}

void		put_pixelantialiaser(t_env *e, register int x, register int y)
{
	register unsigned char	c[15];
	register int			img_size;

	img_size = e->screen.l * e->screen.h * e->limg->bpp / 8;
	if (x < 1 || y < 1
	|| y * e->limg->sline + x * e->limg->bpp / 8 > img_size - 1
	|| x >= e->limg->sline / (e->limg->bpp / 8)
	|| y >= img_size / e->limg->sline - 1)
		return ;
	c[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8];
	c[5] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8 + 1];
	c[10] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8 + 2];
	c[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8];
	c[6] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8 + 1];
	c[11] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8 + 2];
	c[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8];
	c[7] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8 + 1];
	c[12] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8 + 2];
	c[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8];
	c[8] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8 + 1];
	c[13] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8 + 2];
	c[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8];
	c[9] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 1];
	c[14] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 2];
}

void		antialiasing(t_env *e)
{
	register int x;
	register int y;

	y = -1;
	while (++y < e->screen.h)
	{
		x = -1;
		while (++x < e->screen.l)
			put_pixelantialiaser(e, x, y);
	}
}
