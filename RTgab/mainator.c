/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:53:27 by gfournie          #+#    #+#             */
/*   Updated: 2015/09/22 18:54:40 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

t_cam	initcam(t_cam c)
{

	if (c.dir.x != 0)
	{
		c.right.x =  c.dir.z / c.dir.x;
		c.right.y = 0;
		c.right.z = 1;
		c.right = normalisator(c.right);
	}
	else
	{
		c.right.x = 1;
		c.right.y = 0;
		c.right.z = 0;
	}
	if (c.dir.x != 0)
	{
		c.up.x =  c.right.z / c.right.x;
		c.up.y = (c.dir.x * c.up.x + c.dir.z) / c.right.x;
		c.up.z = 1;
		c.up = normalisator(c.up);
	}
	else
	{
		c.up.x = 0;
		c.up.y = 1;
		c.up.z = 0;
	}
	return (c);
}

void *niark(void *e)
{
	ft_putendl("niarkdebut");
	panoramiquator(e);
	ft_putendl("niarkfin");
	return (NULL);
}

void	init(t_env *e)
{
	e->l = 0;
	e->o.pos.x = 0;
	e->o.pos.y = 0;
	e->o.pos.z = 0;
	e->o.dir.x = 0;
	e->o.dir.y = 0;
	e->o.dir.z = 1;
	superparsator(e);
	e->o = initcam(e->o);
	if (e->l == 0)
		error("pas de lumiere");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, TV, TH, "RVT1");
	e->img = mlx_new_image(e->mlx, TV, TH);
	e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizel), &(e->endian));
	e->o.d = 1;
	e->o.h = 0.35;
	e->o.l = 0.5;
	e->o.vpul = vpulcalculator(e->o);
	e->c.x = 0;
	e->c.y = 0;
	e->c.z = 0;
	e->c2.x = 1;
	e->c2.y = 1;
	e->c2.z = 1;
	e->test2 = 0;
	// printf("vpulx = %f vpuly = %f vpulz = %f\n", (double)e->o.vpul.x, (double)e->o.vpul.y, (double)e->o.vpul.z);
}

static int	key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

static int	loop_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_do_sync(e->mlx);
	return (1);
}

int			main(void)
{
	t_env e;

	init(&e);
	panoramiquator(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, 2, 1, key_hook, &e);
	// pthread_create(&t, NULL, niark, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}