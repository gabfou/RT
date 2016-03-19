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
	register unsigned char	color1[5];
	register unsigned char	color2[5];
	register unsigned char	color3[5];
	register int			img_size;

	img_size = L_SIZE * H_SIZE * e->limg->bpp / 8;
	if (x < 1 || y < 1 || y * e->limg->sline + x * e->limg->bpp / 8 > img_size - 1
	|| x >= e->limg->sline / (e->limg->bpp / 8) || y >= img_size / e->limg->sline - 1)
		return ;
	color1[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8];
	color2[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8 + 1];
	color3[0] = e->limg->img[(y + 1) * e->limg->sline + x * e->limg->bpp / 8 + 2];
	color1[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8];
	color2[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8 + 1];
	color3[1] = e->limg->img[(y - 1) * e->limg->sline + x * e->limg->bpp / 8 + 2];
	color1[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8];
	color2[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8 + 1];
	color3[2] = e->limg->img[y * e->limg->sline + (x - 1) * e->limg->bpp / 8 + 2];
	color1[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8];
	color2[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8 + 1];
	color3[3] = e->limg->img[y * e->limg->sline + (x + 1) * e->limg->bpp / 8 + 2];
	color1[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8];
	color2[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 1];
	color3[4] = e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 2];
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8] = (color1[0] + color1[1] + color1[2] + color1[3] + color1[4]) / 5;
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 1] = (color2[0] + color2[1] + color2[2] + color2[3] + color2[4]) / 5;
	e->limg->img[y * e->limg->sline + x * e->limg->bpp / 8 + 2] = (color3[0] + color3[1] + color3[2] + color3[3] + color3[4]) / 5;
}

void antialiasing(t_env *e)
{
	register int x;
	register int y;

	y = -1;
	while(++y < H_SIZE)
	{
		x = -1;
		while(++x < L_SIZE)
			put_pixelantialiaser(e, x, y);
	}
}
