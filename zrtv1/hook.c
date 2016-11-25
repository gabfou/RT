/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:04:59 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 21:59:43 by ibuchwal         ###   ########.fr       */
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
	comander(-3, levia);
	return (0);
}

t_vec	calc_dir2(t_screen screen, FLOAT_SIZE x, FLOAT_SIZE y, t_cam *cam)
{
	t_vec dir;

	dir.x = (cam->upleft.x +
		(cam->up.x * screen.scrh * y / screen.resh)
		+ (cam->right.x * screen.scrl * x / screen.resl));
	dir.y = (cam->upleft.y +
		(cam->up.y * screen.scrh * y / screen.resh)
		+ (cam->right.y * screen.scrl * x / screen.resl));
	dir.z = (cam->upleft.z +
		(cam->up.z * screen.scrh * y / screen.resh)
		+ (cam->right.z * screen.scrl * x / screen.resl));
	return (normalizator_ret(dir));
}

int		mouse_hook(int button, int x, int y, t_leviatenv *levia)
{
	t_pd	pd;
	t_inter	inter;

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
	if (button == 1 && levia && levia->lenv && levia->lenv->limg
		&& levia->lenv->limg->cam)
	{
		pd.pos = levia->lenv->limg->cam->pos;
		t_inter_set(&(inter));
		pd.dir = calc_dir2(levia->lenv->screen, x, y, levia->lenv->limg->cam);
		impactoralancienne(&pd, levia->lenv->item, &inter);
		levia->current = inter.item;
	}
	return (0);
}

void	changesize(t_leviatenv *levia)
{
	mlx_destroy_window(levia->mlx, levia->win);
	levia->win = (levia->lenv->ft++ % 2 == 0) ?
	mlx_new_window(levia->mlx, levia->lenv->screen.l + L_SIZEC,
	levia->lenv->screen.h, "RT") :
	mlx_new_window(levia->mlx, levia->lenv->screen.l,
	levia->lenv->screen.h, "RT");
	mlx_put_image_to_window(levia->mlx, levia->win,
	levia->lenv->limg->image, 0, 0);
	imgcptor(levia);
	mlx_mouse_hook(levia->win, mouse_hook, levia);
	mlx_hook(levia->win, 2, 1, key_down_hook, levia);
}

int		key_down_hook(int keycode, t_leviatenv *levia)
{
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
