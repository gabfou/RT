/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:04:59 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/23 16:05:00 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose_hook(t_leviatenv *levia)
{
	if (levia->lenv->limg->i > NBTHREAD)
	{
		levia->lenv->limg->i++;
		mlx_put_image_to_window(levia->mlx,
			levia->win, levia->lenv->limg->image, 0, 0);
	}
	if (levia->lenv->limg->i <= NBTHREAD)
	{
		loadator(levia->lenv->screen.h, levia->lenv->screen.l,
			levia, levia->lenv->limg->l);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_leviatenv *levia)
{
	printf("x = %d, y = %d, button = %d\n", x, y, button);
	if (button == 1 && (x > 1085 && x < 1112 && y > 150 && y < 200))
	{
		nextrack(levia, 0, NULL);
		comander(-3, levia);
	}
	if (button == 1 && (x > 1260 && x < 1290 && y > 150 && y < 200))
	{
		nextrack(levia, 0, NULL);
		comander(-3, levia);
	}
	return (0);
}

void	changesize(t_leviatenv *levia)
{
	mlx_destroy_window(levia->mlx, levia->win);
	levia->win = (levia->lenv->ft++ % 2 == 0) ?
		mlx_new_window(levia->mlx, levia->lenv->screen.l + L_SIZEC,
		levia->lenv->screen.h, "RTV1") :
		mlx_new_window(levia->mlx, levia->lenv->screen.l,
		levia->lenv->screen.h, "RTV1");
	mlx_put_image_to_window(levia->mlx, levia->win,
		levia->lenv->limg->image, 0, 0);
	imgcptor(levia);
	mlx_mouse_hook(levia->win, mouse_hook, levia);
	mlx_hook(levia->win, 2, 1, key_down_hook, levia);
}

int		key_down_hook(int keycode, t_leviatenv *levia)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 124)
		levia->lenv->limg = levia->lenv->limg->next;
	if (keycode == 123)
		levia->lenv->limg = levia->lenv->limg->prev;
	if (keycode == 43 && levia->lenv->prev->limg != NULL)
		levia->lenv = levia->lenv->prev;
	if (keycode == 47 && levia->lenv->next->limg != NULL)
		levia->lenv = levia->lenv->next;
	if (keycode == 86)
		nextrack(levia, 0, NULL);
	if (keycode == 88)
		nextrack(levia, 1, NULL);
	if ((int)keycode == 53)
		exit(0);
	if (keycode == 50)
		changesize(levia);
	comander(keycode, levia);
	return (0);
}
