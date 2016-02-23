/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:10:49 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/12 18:10:50 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		impactor(t_env *env, t_pd *pd, t_inter *inter)
{
	t_item	*lst;

	lst = env->item;
	while (env->item != NULL)
	{
		if (env->item->sp != NULL)
		{
			check_sphere(env->item, pd, inter);
		}
		else if (env->item->pl != NULL)
		{
			check_plane(env->item, pd, inter);
		}
		/*else if (env->item->cyl != NULL)
		{
			check_cyl(env->item, pd, inter);
		}*/
		else if (env->item->con != NULL)
		{
			check_con(env->item->con, pd, inter);
		}
		env->item = env->item->next;
	}
	env->item = lst;
}

void		t_inter_set(t_inter *inter)
{
	inter->norm->x = 0;
	inter->norm->y = 0;
	inter->norm->z = 0;
	inter->pos->x = 0;
	inter->pos->y = 0;
	inter->pos->z = 0;
}

void		calc_dir(t_env *env, t_vec *dir, float x, float y)
{
	//ft_putendl("calc dir");
	// printf("cdx = %f cdy = %f cdz = %f\n", env->cam->dir->x, env->cam->dir->y, env->cam->dir->z);
	// printf("cux = %f cuy = %f cuz = %f\n", env->cam->up->x, env->cam->up->y, env->cam->up->z);
	// printf("crx = %f cry = %f crz = %f\n\n", env->cam->right->x, env->cam->right->y, env->cam->right->z);
	//ft_putendl("qwerqwer");
	dir->x = (env->screen->upleft->x + (env->cam->up->x * SCR_H * y /H_RES) + (env->cam->right->x * SCR_L * x /L_RES))/* - env->cam->pos->x*/;
	dir->y = (env->screen->upleft->y + (env->cam->up->y * SCR_H * y /H_RES) + (env->cam->right->y * SCR_L * x /L_RES))/* - env->cam->pos->y*/;
	dir->z = (env->screen->upleft->z + (env->cam->up->z * SCR_H * y /H_RES) + (env->cam->right->z * SCR_L * x /L_RES))/* - env->cam->pos->z*/;
// 	dir->x = (env->cam->dir->x * SCR_DIST) + (env->cam->up->x * SCR_H * y /480) + (env->cam->right->x * SCR_L * x /480);
// 	//ft_putendl("calc dir2");
// 	dir->y = (env->cam->dir->y * SCR_DIST) + (env->cam->up->y * SCR_H * y /480) + (env->cam->right->y * SCR_L * x /480);
// 	//ft_putendl("calc dir3");
// 	dir->z = (env->cam->dir->z * SCR_DIST) + (env->cam->up->z * SCR_H * y /480) + (env->cam->right->z * SCR_L * x /480);
// 	//ft_putendl("calc dir4");
// //	printf("cdx = %f cdy = %f cdz = %f\n", dir->x, dir->y, dir->z);
	normalizator (dir);
}

void		ft_check(t_env *env)
{
	if(env->item == NULL)
		ft_putendl("NULLLLLL");
	if(env->item->sp == NULL && env->item->pl == NULL)
		ft_putendl(" SP NULLLLLL");

	ft_putendl("cam pos");
	print_vec(env->cam->pos);
	ft_putendl("cam dir");
	print_vec(env->cam->dir);

	ft_putendl("cam up");
	print_vec(env->cam->up);

	ft_putendl("cam right");
	print_vec(env->cam->right);
	printf("LUM px=%f py=%f pz=%f\n", env->light->pos->x, env->light->pos->y, env->light->pos->z);
	printf("SP px=%f py=%f pz=%f\n", env->item->sp->c->x, env->item->sp->c->y, env->item->sp->c->z);
	ft_putendl("CHECK FINITO");
}

void		creator(t_env *env)
{
	double		x;
	double		y;
	t_pd	*pd;

	ft_putendl("creator");
	ft_check(env);
	y = 0;
	pd = new_t_pd();
	pd->pos = env->cam->pos;
	pd->dir = new_t_vec(0,0,0);
	while (y < H_SIZE)
	{
		x = 0;
		while (x < L_SIZE)
		{
			pd->pos = env->cam->pos;
			env->fcolor = 0x000000;
			env->inter = new_t_inter();
			t_inter_set(env->inter);
			calc_dir(env, pd->dir, x, y);
			//printf("\nx = %f y = %f", x, y );
			//if (x == 1 && ((int)y % 100 == 0))
				//print_vec(pd->dir);
			//print_vec(pd->pos);
			impactor(env, pd, env->inter);
			set_inter_pos(env->inter, pd);
			luminator(env);
			pixel_to_image(env, x, y, env->fcolor);
			x += 1;
		}
		y += 1;
	}
}
