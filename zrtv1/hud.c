/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:45:26 by gfournie          #+#    #+#             */
/*   Updated: 2016/02/24 14:45:32 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	loadatorprovisoirauxi(int k, int l, int h, t_leviatenv *e)
{
	int i;
	int l2;

	i = 0;
	l2 = l / 2;
	while (++i <= k)
	{
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3, h - h / 10, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3, h - h / 10 + 1, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3, h - h / 10 + 2, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3, h - h / 10 + 3, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3, h - h / 10 + 4, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 1, h - h / 10, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 1, h - h / 10 + 1, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 1, h - h / 10 + 2, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 1, h - h / 10 + 3, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 1, h - h / 10 + 4, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 2, h - h / 10, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 2, h - h / 10 + 1, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 2, h - h / 10 + 2, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 2, h - h / 10 + 3, B);
		mlx_pixel_put(e->mlx, e->win, l2 - 150 + i * 3 + 2, h - h / 10 + 4, B);
	}
}

void	loadator(int h, int l, t_leviatenv *e, int nb)
{
	char r[4];

	if (h == -1)
	{
		e->lenv->limg->k = 1;
		return ;
	}
	if (nb > ((int)(h * l) / 100) * e->lenv->limg->k
		&& e->lenv->limg->i != NBTHREAD + 1)
	{
		while (nb > ((int)(h * l) / 100) * e->lenv->limg->k)
			e->lenv->limg->k++;
		mlx_clear_window(e->mlx, e->win);
		loadatorprovisoirauxi(e->lenv->limg->k, l, h, e);
		r[0] = (e->lenv->limg->k / 10) % 10 + '0';
		r[1] = e->lenv->limg->k % 10 + '0';
		r[2] = '%';
		r[3] = 0;
		mlx_string_put(e->mlx, e->win, l / 2 - 130, h - h / 10 + 5, B, r);
		mlx_do_sync(e->mlx);
	}
}
