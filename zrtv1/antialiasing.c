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

void		put_pixelantialiaser(t_env *e, register int x, register int y)
{
	register unsigned char	c1[5];
	register unsigned char	c2[5];
	register unsigned char	c3[5];
	register int			img_size;

	img_size = e->screen.l * e->screen.h * e->limg->bpp / 8;
	if (x < 1 || y < 1 || y * e->limg->sline + x * e->limg->bpp / 8 > img_size - 1
	|| x >= e->limg->sline / (e->limg->bpp / 8) || y >= img_size / e->limg->sline - 1)
		return ;
	c1[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8];
	c2[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8 + 1];
	c3[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8 + 2];
	c1[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8];
	c2[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8 + 1];
	c3[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8 + 2];
	c1[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8];
	c2[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8 + 1];
	c3[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8 + 2];
	c1[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8];
	c2[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8 + 1];
	c3[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8 + 2];
	c1[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8];
	c2[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 1];
	c3[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 2];
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8] = (c1[0] + c1[1] + c1[2] + c1[3] + c1[4]) / 5;
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 1] = (c2[0] + c2[1] + c2[2] + c2[3] + c2[4]) / 5;
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 2] = (c3[0] + c3[1] + c3[2] + c3[3] + c3[4]) / 5;
}

void antialiasing(t_env *e)
{
	register int x;
	register int y;

	y = -1;
	while(++y < e->screen.h)
	{
		x = -1;
		while(++x < e->screen.l)
			put_pixelantialiaser(e, x, y);
	}
}
