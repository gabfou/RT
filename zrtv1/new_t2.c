/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 02:07:55 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/16 02:07:56 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_item		*new_t_item(void)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->pl = NULL;
	item->sp = NULL;
	item->cyl = NULL;
	item->obj = NULL;
	item->tr = NULL;
	item->con = NULL;
	item->next = NULL;
	item->cnb = NULL;
	item->texture = NULL;
	item->mat = new_t_mat("niark");
	return (item);
}

t_cam		*new_t_cam(void)
{
	t_cam	*cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->pos.x = 0;
	cam->pos.y = 0;
	cam->pos.z = 0;
	cam->dir.x = 0;
	cam->dir.y = 0;
	cam->dir.z = 1;
	cam->angle = 0;
	cam->next = NULL;
	return (cam);
}

t_cnb		*new_t_cnb(int i)
{
	t_cnb	*cnb;

	cnb = (t_cnb*)malloc(sizeof(t_cnb));
	cnb->i = i;
	cnb->next = NULL;
	return (cnb);
}

t_carre		*new_t_carre(void)
{
	t_carre	*carre;

	carre = (t_carre*)malloc(sizeof(t_carre));
	carre->pos.x = 0;
	carre->pos.y = 0;
	carre->pos.z = 0;
	carre->dir.x = 0;
	carre->dir.y = 0;
	carre->dir.z = 1;
	carre->angle = 0;
	carre->next = NULL;
	return (carre);
}

t_screen	new_t_screen(void)
{
	t_screen	screen;

	screen.h = H_SIZE;
	screen.l = L_SIZE;
	screen.scrl = SCR_L;
	screen.scrh = SCR_H;
	screen.scrd = SCR_DIST;
	screen.li = SCR_L / L_RES;
	screen.hi = SCR_H / H_RES;
	screen.resl = L_RES;
	screen.resh = H_RES;
	return (screen);
}
