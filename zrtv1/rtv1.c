/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:07:13 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/14 23:49:26 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parser_test(t_env *env)
{
	t_item *lst;
	t_light *lum;
	int		i;

	i = 0;
	lum = env->light;
	lst = env->item;
	printf("CAM posx %f posy %f posz %f\n", env->cam->pos->x, env->cam->pos->y, env->cam->pos->z);
	printf("CAM dirx %f diry %f dirz %f\n", env->cam->dir->x, env->cam->dir->y, env->cam->dir->z);
	while (lst != NULL)
	{
		i++;
		ft_putnbr(i);
		if (lst->sp != NULL)
			printf("%d SP posx %f posy %f posz %f ray %f\n", i, lst->sp->c->x, lst->sp->c->y, lst->sp->c->z, lst->sp->ray);
		if (lst->pl != NULL)
		{
			printf("%d PL posx %f posy %f posz %f\n", i, lst->pl->pos->x, lst->pl->pos->y, lst->pl->pos->z);
			printf("%d PL dirx %f diry %f dirz %f\n", i, lst->pl->dir->x, lst->pl->dir->y, lst->pl->dir->z);
		}
		lst = lst->next;
	}
	while (lum != NULL)
	{
		i++;
		ft_putnbr(i);
		printf("%d LUM posx %f posy %f posz %f\n", i, lum->pos->x, lum->pos->y, lum->pos->z);
		lum = lum->next;
	}
	ft_putendl("parser_test fin");
}

// void		pixel_to_image(t_env *s, int x, int y, unsigned int color)
// {
// 	unsigned int	off;
// 	int r;
// 	int g;
// 	int b;

// 	r = (color >> 16) & 0xFF;
// 	g = (color >> 8) & 0xFF;
// 	b = (color >> 0) & 0xFF;
// 	r = (r > 255)? 255: r;
// 	g = (g > 255)? 255: g;
// 	b = (b > 255)? 255: b;
// 	off = y * s->sline + x * s->bpp / 8;
// 	if (x < 0 || y < 0 || y > H_SIZE || x > L_SIZE)
// 		return ;
// 	s->img[off] = color >> 0;
// 	s->img[off + 1] = color >> 8;
// 	s->img[off + 2] = color >> 16;
// }

void		pixel_to_image(int x, int y, unsigned int color , t_limg *limg)
{
	unsigned int	off;
	int r;
	int g;
	int b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	r = (r > 255)? 255: r;
	g = (g > 255)? 255: g;
	b = (b > 255)? 255: b;
	off = y * limg->sline + x * limg->bpp / 8;
	if (x < 0 || y < 0 || y > H_SIZE || x > L_SIZE)
		return ;
	limg->img[off] = color >> 0;
	limg->img[off + 1] = color >> 8;
	limg->img[off + 2] = color >> 16;
}

int			expose_hook(t_leviatenv *levia)
{
	//int i;
	// if (env->done == 0)
	// {
	// 	creator(env);
	// 	// ft_putendl("fini");
	// }
	//ft_putendl("print");
	//if (!levia || !levia->lenv)
	//	ft_error("pas levialenv");
	// if (levia->lenv->i == NBTHREAD + 1)
	// {
	// 	i = -1;
	// 	while (++i < 0)
	// 		antialiasing(levia->lenv);
	// 	levia->lenv->i++;
	// }
	if (levia->lenv->i > NBTHREAD /* && lenv->i < NBTHREAD + 15*/)
	{
		levia->lenv->i++;
		mlx_put_image_to_window(levia->mlx, levia->win, levia->lenv->limg->image, 0, 0);
	}
	// if (levia->lenv->i <= NBTHREAD + 1)
	// {
	// 	// printf("lenv->l = %d\n", lenv->l);
	// 	loadator(H_SIZE, L_SIZE, levia, levia->lenv->l);
	// }
	//lenv->done = 1;
	return (0);
}

int			key_down_hook(int keycode, t_leviatenv *levia)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 124)
	{
		levia->lenv->limg = levia->lenv->limg->next;
		return (0);
	}
	if (keycode == 123)
	{
		levia->lenv->limg = levia->lenv->limg->prev;
		return (0);
	}
	if (keycode == 43)
	{
		levia->lenv = levia->lenv->prev;
		return (0);
	}
	if (keycode == 47)
	{
		levia->lenv = levia->lenv->next;
		return (0);
	}
	if ((int)keycode == 53)
		exit (0);
	if (keycode == 50)
	{
		mlx_destroy_window(levia->mlx, levia->win);
		levia->win = (levia->lenv->ft++ % 2 == 0) ? mlx_new_window(levia->mlx, L_SIZE + L_SIZEC, H_SIZE, "RTV1") :
		mlx_new_window(levia->mlx, L_SIZE, H_SIZE, "RTV1");
		mlx_put_image_to_window(levia->mlx, levia->win, levia->lenv->limg->image, 0, 0);
		//imgcptor(env);
		mlx_hook(levia->win, 2, 1, key_down_hook, levia);
	}
	// ft_putchar(keytochar(keycode));
	comander(keycode, levia);
	return (0);
}

t_env		*new_t_env()
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->image = NULL;
	env->t = NULL;
	env->endiant = 0;
	env->limg = NULL;

	env->cam = NULL;
	env->item = NULL;
	env->light = NULL;
	env->inter = NULL;
	env->fcolor = 0;
	env->done = 0;
	env->l = 0;
	env->i = 0;
	env->ft = 0;
	env->prev = NULL;
	env->next = NULL;
	return (env);
}

void		gpatrouverdnom(t_leviatenv *env,int argc,char *argv)
{	
	// ft_putendl("choix 1 1");

	init(env->lenv, argc, argv);

	// ft_putendl("choix 1 1");

	init_env(env);

	// ft_putendl("choix 1 1");
}

int			main(int argc, char **argv)
{
	t_leviatenv	levia;
	t_env		*first;
	int			i;

	//ft_putendl("post1");
	// if (argc != 2)
	// 	ft_error("probleme d'argument");
	// i = ft_strlen(argv[1]) - 4;
	// if (!(i > 0 && argv[1][i++] == '.' && argv[1][i++] == 'b' && argv[1][i++] == 'm' && argv[1][i++] == 'p'))
	// 	recuperator(&env, argv[1]);
	i = 1;
//	ft_putnbr(argc);
	while (i < argc)
	{
	//	ft_putendl("post2");
		if (!levia.lenv)
		{
	//		 ft_putendl("choix 1 1");
			levia.lenv = new_t_env();
			// ft_putendl("choix 1 2");
			gpatrouverdnom(&levia, argc, argv[i]);
			// ft_putendl("choix 1 3");
			first = levia.lenv;
	//		 ft_putendl("choix 1 4");
		}
		else
		{
	//		 ft_putendl("choix 2 1");
			levia.lenv->next = new_t_env();
			// ft_putendl("choix 2 2");
			gpatrouverdnom(&levia, argc, argv[i]);
			// ft_putendl("choix 2 3");
			levia.lenv->next->prev = levia.lenv;
			// ft_putendl("choix 2 4");
			levia.lenv  = levia.lenv->next;
	//		 ft_putendl("choix 2 5");
		}
		i++;
	}
	levia.lenv = first;
	//ft_putendl("post3");
	// print_params(env);
	// init(&env);
	// ft_putendl(env.ktc);
	//ft_putendl("LLLAALALLALALALALALAL");
	i = ft_strlen(argv[1]) - 4;
	if (!(i > 0 && argv[1][i++] == '.' && argv[1][i++] == 'b' && argv[1][i++] == 'm' && argv[1][i++] == 'p'))
		thread_master(levia.lenv);
	else
		readerbmp32(argv[1], &levia);
	// ft_putendl("TOUTAETECREE TRAKIL");
	// ft_bzero(env.img, H_SIZE * L_SIZE * 4);
	// ft_putendl("post5");
	mlx_hook(levia.win, 2, 1, key_down_hook, &levia);
//	 ft_putendl("post6");
	mlx_loop_hook(levia.mlx, expose_hook, &levia);
	// ft_putendl("post7");
	mlx_loop(levia.mlx);
	return (0);
}
