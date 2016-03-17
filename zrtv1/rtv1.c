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

void		pixel_to_image(t_env *s, int x, int y, unsigned int color)
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
	off = y * s->sline + x * s->bpp / 8;
	if (x < 0 || y < 0 || y > H_SIZE || x > L_SIZE)
		return ;
	s->img[off] = color >> 0;
	s->img[off + 1] = color >> 8;
	s->img[off + 2] = color >> 16;
}

int			expose_hook(t_env *env)
{
	int i;
	/*if (env->done == 0)
	{
		creator(env);
		ft_putendl("fini");
	}*/
	//ft_putendl("print");
	if (env->i == NBTHREAD + 1)
	{
		i = -1;
		while (++i < 0)
			antialiasing(env);
		env->i++;
	}
	if (env->i > NBTHREAD + 1 && env->i < NBTHREAD + 15)
	{
		env->i++;
		mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
	}
	if (env->i <= NBTHREAD + 1)
	{
		// printf("env->l = %d\n", env->l);
		loadator(H_SIZE, L_SIZE, env, env->l);
	}
	//env->done = 1;
	return (0);
}

int			key_down_hook(int keycode, t_env *env)
{
	(void)env;
	// printf("keycode = %d\n", keycode);
	if ((int)keycode == 53)
		exit (0);
	// ft_putchar(keytochar(keycode));
	comander(keycode, env);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		i;

	// if (argc != 2)
	// 	ft_error("probleme d'argument");
	// i = ft_strlen(argv[1]) - 4;
	// if (!(i > 0 && argv[1][i++] == '.' && argv[1][i++] == 'b' && argv[1][i++] == 'm' && argv[1][i++] == 'p'))
	// 	recuperator(&env, argv[1]);
	init(&env, argc, argv);
	print_params(env);
	init_env(&env);
	// init(&env);
	// ft_putendl(env.ktc);
	i = ft_strlen(argv[1]) - 4;
	if (!(i > 0 && argv[1][i++] == '.' && argv[1][i++] == 'b' && argv[1][i++] == 'm' && argv[1][i++] == 'p'))
		thread_master(&env);
	else
		readerbmp32(argv[1], &env);
	// ft_putendl("TOUTAETECREE TRAKIL");
	// ft_bzero(env.img, H_SIZE * L_SIZE * 4);
	// ft_putendl("post5");
	mlx_hook(env.win, 2, 1, key_down_hook, &env);
	// ft_putendl("post6");
	mlx_loop_hook(env.mlx, expose_hook, &env);
	// ft_putendl("post7");
	mlx_loop(env.mlx);
	// ft_putendl("post8");
	return (0);
}
