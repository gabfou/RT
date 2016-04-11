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

// void		parser_test(t_env *env)
// {
// 	t_item *lst;
// 	t_light *lum;
// 	int		i;

// 	i = 0;
// 	lum = env->light;
// 	lst = env->item;
// 	printf("CAM posx %f posy %f posz %f\n", env->cam->pos->x, env->cam->pos->y, env->cam->pos->z);
// 	printf("CAM dirx %f diry %f dirz %f\n", env->cam->dir->x, env->cam->dir->y, env->cam->dir->z);
// 	while (lst != NULL)
// 	{
// 		i++;
// 		ft_putnbr(i);
// 		if (lst->sp != NULL)
// 			printf("%d SP posx %f posy %f posz %f ray %f\n", i, lst->sp->c->x, lst->sp->c->y, lst->sp->c->z, lst->sp->ray);
// 		if (lst->pl != NULL)
// 		{
// 			printf("%d PL posx %f posy %f posz %f\n", i, lst->pl->pos->x, lst->pl->pos->y, lst->pl->pos->z);
// 			printf("%d PL dirx %f diry %f dirz %f\n", i, lst->pl->dir->x, lst->pl->dir->y, lst->pl->dir->z);
// 		}
// 		lst = lst->next;
// 	}
// 	while (lum != NULL)
// 	{
// 		i++;
// 		ft_putnbr(i);
// 		printf("%d LUM posx %f posy %f posz %f\n", i, lum->pos->x, lum->pos->y, lum->pos->z);
// 		lum = lum->next;
// 	}
// 	ft_putendl("parser_test fin");
// }

void		pixel_to_image(int x, int y, unsigned int color , t_limg *limg)
{
	unsigned int	off;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	off = y * limg->sline + x * limg->bpp / 8;
	if (x < 0 || y < 0)
		return ;
	limg->img[off] = (r > 255)? 255: r;
	limg->img[off + 1] = (g > 255)? 255: g;
	limg->img[off + 2] = (b > 255)? 255: b;
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
	if (levia->lenv->limg->i > NBTHREAD /* && lenv->i < NBTHREAD + 15*/)
	{
		levia->lenv->limg->i++;
		mlx_put_image_to_window(levia->mlx, levia->win, levia->lenv->limg->image, 0, 0);
	}
	if (levia->lenv->limg->i <= NBTHREAD)
	{
		// printf("lenv->l = %d\n", lenv->l);
		loadator(levia->lenv->screen.h, levia->lenv->screen.l, levia, levia->lenv->limg->l);
	}
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
	if (keycode == 43 && levia->lenv->prev->limg != NULL)
	{
		levia->lenv = levia->lenv->prev;
		return (0);
	}
	if (keycode == 47 && levia->lenv->next->limg != NULL)
	{
		levia->lenv = levia->lenv->next;
		return (0);
	}
	if ((int)keycode == 53)
		exit (0);
	if (keycode == 50)
	{
		mlx_destroy_window(levia->mlx, levia->win);
		levia->win = (levia->lenv->ft++ % 2 == 0) ? mlx_new_window(levia->mlx, levia->lenv->screen.l + L_SIZEC, levia->lenv->screen.h, "RTV1") :
		mlx_new_window(levia->mlx, levia->lenv->screen.l, levia->lenv->screen.h, "RTV1");
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
	env->screen = new_t_screen();
	env->image = NULL;
	env->t = NULL;
	env->endiant = 0;

	env->limg = NULL;
	env->cam = NULL;
	env->item = NULL;
	env->light = NULL;
	env->fcolor = 0;
	env->done = 0;
	env->ft = 0;
	env->nbr = 0;
	env->prev = NULL;
	env->next = NULL;
	return (env);
}

void		setcamuplef(t_env *env)
{
	t_cam *cam;

	cam = env->cam;
	while (cam)
	{
		cam->upleft = set_screen(cam, env->screen);
		cam = cam->next;
	}
}

void		checkcamscreen(t_env *env)
{
	if (!(env->cam))
		setcam(env, new_t_cam());
	// if (!(env->screen))
	// 	env->screen = new_t_screen();
}

void		gpatrouverdnom(t_leviatenv *env, int argc, char *argv)
{	
	// ft_putendl("pastrouvednom 1 1");

	ft_putendl(argv);
	
	init(env->lenv, argc, argv);
	checkcamscreen(env->lenv);
	setcamuplef(env->lenv);
	// ft_putendl("pastrouvednom 1 2");
	env->win = mlx_new_window(env->mlx, env->lenv->screen.l, env->lenv->screen.h, "RTV1");
	t_limg_initator(env);
	// ft_putendl("pastrouvednom 1 3");
}

int			main(int argc, char **argv)
{
	t_leviatenv	levia;
	//t_env		*tmp;
	t_env		*first;
	int			i;

	i = 1;
	//tmp = NULL;
	first = NULL;
//	ft_putnbr(argc);
	// if (argc == 1)
	// 	exit(0);
	ft_puttab(argv);
	init_env(&levia);
	while (i < argc)
	{
	//	ft_putendl("post2");
		if (!levia.lenv)
		{
			ft_putendl("choix 1 1");
			levia.lenv = new_t_env();
			levia.lenv->nbr = i;
		//	levia.lenv = tmp;
			first = levia.lenv;
		//	 ft_putendl("choix 1 2");
			gpatrouverdnom(&levia, i, argv[i]);
		//	 ft_putendl("choix 1 3");
			
	//		 ft_putendl("choix 1 4");
		}
		else
		{
			ft_putendl("choix 2 1");
			levia.lenv->next = new_t_env();
			levia.lenv->next->nbr = i;
			levia.lenv->next->prev = levia.lenv;
			levia.lenv = levia.lenv->next;
		//	 ft_putendl("choix 2 2");
			gpatrouverdnom(&levia, i, argv[i]);
		//	 ft_putendl("choix 2 3");
			
			// ft_putendl("choix 2 4");
			
	//		 ft_putendl("choix 2 5");
		}
		i++;
	}
	//ft_putendl("choix finito");
	levia.lenv->next = first;
	first->prev = levia.lenv;
	levia.lenv = first;
	while (levia.lenv->prev->nbr < levia.lenv->nbr)
	{
		ft_putstr("nbr = ");
		ft_putnbr(levia.lenv->nbr);
		ft_putendl(" ;");
		levia.lenv = levia.lenv->prev;
	}
	//ft_putendl("post3");
	// print_params(env);
	// init(&env);
	// ft_putendl(env.ktc);
	//ft_putendl("LLLAALALLALALALALALAL");
	i = ft_strlen(argv[1]) - 4;
	// if (!(i > 0 && argv[1][i++] == '.' && argv[1][i++] == 'b' && argv[1][i++] == 'm' && argv[1][i++] == 'p'))
		thread_master(levia.lenv);
	// else
	// 	readerbmp32(argv[1], &levia);
	// ft_putendl("TOUTAETECREE TRAKIL");
	// ft_bzero(env.img, levia->lenv->screen.h * levia->lenv->screen.l * 4);
	// ft_putendl("post5");
	mlx_hook(levia.win, 2, 1, key_down_hook, &levia);
//	 ft_putendl("post6");
	mlx_loop_hook(levia.mlx, expose_hook, &levia);
	// ft_putendl("post7");
	mlx_loop(levia.mlx);
	return (0);
}
