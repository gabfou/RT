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

void		impactor(t_env *env, t_pd *pd, t_thr *f, t_inter *inter)
{
	t_item	*lst;

	(void)env;
	lst = f->item;
	while (f->item != NULL)
	{
		if (f->item->sp != NULL)
		{
			check_sphere(f->item, pd, inter);
		}
		else if (f->item->pl != NULL)
		{
			check_plane(f->item, pd, inter);
		}
		else if (f->item->cyl != NULL)
		{
			check_cyl(f->item, pd, inter);
		}
		else if (f->item->con != NULL)
		{
			check_con(f->item, pd, inter);
		}
		f->item = f->item->next;
	}
	f->item = lst;
}

void		t_inter_set(t_inter *inter)
{
	inter->norm.x = 0;
	inter->norm.y = 0;
	inter->norm.z = 0;
	inter->pos.x = 0;
	inter->pos.y = 0;
	inter->pos.z = 0;
	inter->t = -1;
	inter->trans = NULL;
	inter->diff = new_t_color(1, 1, 1);
}

// void		calc_dir(t_env *env, t_vec *dir, FLOAT_SIZE x, FLOAT_SIZE y)
// {
// 	//ft_putendl("calc dir");
// 	// printf("cdx = %f cdy = %f cdz = %f\n", env->cam->dir.x, env->cam->dir.y, env->cam->dir.z);
// 	// printf("cux = %f cuy = %f cuz = %f\n", env->cam->up.x, env->cam->up.y, env->cam->up.z);
// 	// printf("crx = %f cry = %f crz = %f\n\n", env->cam->right.x, env->cam->right.y, env->cam->right.z);
// 	//ft_putendl("qwerqwer");
// 	dir.x = (env->screen->upleft.x + (env->cam->up.x * SCR_H * y /H_RES) + (env->cam->right.x * SCR_L * x /L_RES))/* - env->cam->pos.x*/;
// 	dir.y = (env->screen->upleft->y + (env->cam->up.y * SCR_H * y /H_RES) + (env->cam->right.y * SCR_L * x /L_RES))/* - env->cam->pos.y*/;
// 	dir.z = (env->screen->upleft->z + (env->cam->up.z * SCR_H * y /H_RES) + (env->cam->right.z * SCR_L * x /L_RES))/* - env->cam->pos.z*/;
// // 	dir.x = (env->cam->dir.x * SCR_DIST) + (env->cam->up.x * SCR_H * y /480) + (env->cam->right.x * SCR_L * x /480);
// // 	//ft_putendl("calc dir2");
// // 	dir.y = (env->cam->dir.y * SCR_DIST) + (env->cam->up.y * SCR_H * y /480) + (env->cam->right.y * SCR_L * x /480);
// // 	//ft_putendl("calc dir3");
// // 	dir.z = (env->cam->dir.z * SCR_DIST) + (env->cam->up.z * SCR_H * y /480) + (env->cam->right.z * SCR_L * x /480);
// // 	//ft_putendl("calc dir4");
// // //	printf("cdx = %f cdy = %f cdz = %f\n", dir.x, dir.y, dir.z);
// 	normalizator (dir);
// }

void		calc_dir(t_vec *dir, FLOAT_SIZE x, FLOAT_SIZE y, t_cam *cam)
{
	dir->x = (cam->upleft.x + (cam->up.x * SCR_H * y /H_RES) + (cam->right.x * SCR_L * x /L_RES));
	dir->y = (cam->upleft.y + (cam->up.y * SCR_H * y /H_RES) + (cam->right.y * SCR_L * x /L_RES));
	dir->z = (cam->upleft.z + (cam->up.z * SCR_H * y /H_RES) + (cam->right.z * SCR_L * x /L_RES));
	normalizator(dir);
}

void		ft_check(t_env *env)
{
	if(env->item == NULL)
		ft_putendl("NULLLLLL");
	if(env->item->sp == NULL && env->item->pl == NULL)
		ft_putendl(" SP NULLLLLL");

//	ft_putendl("cam pos");
	print_vec(env->cam->pos);
//	ft_putendl("cam dir");
	print_vec(env->cam->dir);

//	ft_putendl("cam up");
	print_vec(env->cam->up);

//	ft_putendl("cam right");
	print_vec(env->cam->right);
//	printf("LUM px=%f py=%f pz=%f\n", env->light->pos.x, env->light->pos.y, env->light->pos.z);
//	printf("SP px=%f py=%f pz=%f\n", env->item->sp->c.x, env->item->sp->c.y, env->item->sp->c.z);
//	ft_putendl("CHECK FINITO");
}

void		nextcam(t_thr *f)
{
	if (f)
	{
		f->cam = f->cam->next;
		f->limg->i++;
		f->limg = f->limg->next;
	}
}

void		inquisitorArckmann(t_thr *f)
{
	// t_light	*tmp;
	// t_cam	*tmp2;
	// t_item	*tmp3;
	t_env		*tmp4;

	if (f && f->env && f->env->done == NBTHREAD)
	{
		write(1, "C\n", 2);
		f->done++;
		tmp4 = f->env;
		f->env = f->env->next;
		write(1, "A\n", 2);
		// free(tmp4);
		write(1, "B\n", 2);
	}
	else if (f && f->env)
	{
		f->done++;
		f->env = f->env->next;
	}
}
// if (e->d < 0xf0000 && e->pixelmirror == 1 && e->testor == 1)
	// {
	// 	e->c.x = 0;
	// 	e->c.y = 0;
	// 	e->c.z = 0;
	// 	e->pl.x += -e->vl.x * 1.0;
	// 	e->pl.y += -e->vl.y * 1.0;
	// 	e->pl.z += -e->vl.z * 1.0;
	// 	e->d = 0xf0000;
	// 	e->pixelmirror = 0;
	// 	return (testall(1, e->pl, e, ps(e->vl, -1)/*miroiratorvcalculator(dir, ps(e->vl, -1))*/));
	// }

int testuniverse(t_vec vec)
{
	FLOAT_SIZE lenght;

	lenght = sqrt(carre(vec.x) + carre(vec.y) + carre(vec.z));
	if (lenght == 0)
		ft_putendl("dafuq universe");
	return (lenght = sqrt(carre(vec.x) + carre(vec.y) + carre(vec.z)));
}

t_thr		*new_t_thr(t_cor *c)
{
	t_thr		*f;

	f = malloc(sizeof(t_thr));
	f->done = 0;
	f->env = c->env;
	f->minx = c->minx;
	f->maxx = c->maxx;
	f->miny = c->miny;
	f->maxy = c->maxy;
	f->item = f->env->item;
	f->light = f->env->light;
	f->cam = f->env->cam;
	f->limg = f->env->limg;
	return (f);
}

t_thr		*set_again_t_thr(t_thr *f)
{
	f->item = f->env->item;
	f->light = f->env->light;
	f->cam = f->env->cam;
	f->limg = f->env->limg;
	return (f);
}

void		creator(t_cor *c)
{
	double		x;
	double		y;
	t_pd		*pd;
	t_thr		*f;
	int			l;

	f = new_t_thr(c);
//	usleep(10000);
	l = 0;
	pd = new_t_pd();
	pd->dir = new_t_vec(0,0,0);
	f->inter = new_t_inter();
	f->liginter = new_t_inter();
	while (/*f->env->done != NBTHREAD && */f->env->nbr > f->done)
	{
		while (f->cam != NULL)
		{
			y = f->miny;
			while (y < f->maxy)
			{
				x = f->minx;
				while (x < f->maxx)
				{
					pd->pos = f->cam->pos;
					f->fcolor = 0x000000;
					t_inter_set(&(f->inter));
					calc_dir(&(pd->dir), x, y, f->cam);
					impactor(f->env, pd, f, &(f->inter));
					c->env->mircount = 0;
					if (f->inter.ref > 0 && c->env->mircount++ < 8)
						ref(f, c, pd);
					set_inter_pos(&(f->inter), pd);
					luminator(f->env, f);
					pixel_to_image(x, y, f->fcolor, f->limg);
					f->limg->l++;
					//free(f->inter);
					x += 1;
				}
				y += 1;
			}
			nextcam(f);
			ft_putstr("NEXTEUH");
		}
		ft_putendl("next env");
		f->env->done++;
		// inquisitorArckmann(f);
		f->done++;
		f->env = f->env->next;
		f = set_again_t_thr(f);
	}
	//antialiasing(env);
	// inquisitorArckmann(f);
	free(f);
	pthread_exit(NULL);
}
// void		creator(t_cor *c)
// {
// 	double		x;
// 	double		y;
// 	t_pd		*pd;
// 	t_thr		*f;
// 	int			l;

// 	// ft_check(env);
// 	f = malloc(sizeof(t_thr));
// 	f->minx = c->minx;
// 	f->maxx = c->maxx;
// 	f->miny = c->miny;
// 	f->maxy = c->maxy;
// 	f->item = c->env->item;
// 	f->light = c->env->light;
// 	printf("xmin = %f xmax = %f ymin = %f ymax = %f\n", f->minx, f->maxx, f->miny, f->maxy);
// 	usleep(10000);
// 	// ft_putendl("thread check");
// 	// printf("xmin = %f xmax = %f ymin = %f ymax = %f\n",f->minx, f->maxx, f->miny, f->maxy);
// 	// ft_putendl("DEBUUUT");
// 	l = 0;
// 	y = f->miny;
// 	pd = new_t_pd();
// 	//pd->pos = c->env->cam->pos;
// 	pd->dir = new_t_vec(0,0,0);
// 	// ft_putendl("LAAAAAAAAA");
// 	while (y < f->maxy)
// 	{
// 		x = f->minx;
// 		while (x < f->maxx)
// 		{
// 			//ft_putendl("boucle");
// 			pd->pos = c->env->cam->pos;
// 			f->fcolor = 0x000000;
// 			f->inter = new_t_inter();
// 			t_inter_set(f->inter);
// 			calc_dir(c->env, pd->dir, x, y);
// 			// printf("\nx = %f y = %f", x, y );
// 			//if (x == 1 && ((int)y % 100 == 0))
// 				//print_vec(pd->dir);
// 			//print_vec(pd->pos);
// 			impactor(c->env, pd, f, f->inter);
// 			set_inter_pos(f->inter, pd);
// 			luminator(c->env, f);
// 			//if (f-> inter.t > 0 )
// 			//	pixel_to_image(c->env, x, y, 0xFF0000); 
// 			pixel_to_image(c->env, x, y, f->fcolor);
// 			//if (f->fcolor == 0)
// 			//	printf("\nx = %f y = %f", x, y );
// 			// if (x == f->minx && y == f->miny)
// 			// 	printf("color = %d\n", f->fcolor);


// 			// if (f->minx == 0 && f->miny == 0)
// 			// { 
// 			// 	ft_putendl("pre");
// 			// 	loadator(H_SIZE, L_SIZE, c->env, l++);
// 			// 	ft_putendl("post");
// 			// }
// 			c->env->l++;
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// 	//antialiasing(env);
// 	c->env->i++;
// 	pthread_exit(NULL);
// }
