/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlpanelator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:24:37 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/17 23:24:46 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	*imgcptor(t_leviatenv *levia)
{
	static t_limg	*limg = NULL;

	if (limg == NULL)
	{
		limg = malloc(sizeof(t_limg));
		limg->image = mlx_new_image(levia->mlx, L_SIZEC,
			levia->lenv->screen.h);
		limg->img = mlx_get_data_addr(limg->image, &limg->bpp,
			&limg->sline, &limg->k);
		limg->prev = NULL;
		limg->next = NULL;
		printmusicator(limg);
	}
	mlx_put_image_to_window(levia->mlx, levia->win, limg->image,
		levia->lenv->screen.l, 0);
	mlx_string_put(levia->mlx, levia->win, levia->lenv->screen.l
		+ 151, 165, 0xFFFFFF, levia->fmod.listmusic->name);
	return (NULL);
}
