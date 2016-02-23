/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:07:13 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:07:14 by jromagna         ###   ########.fr       */
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
	if (env->done == 0)
	{
		creator(env);
		ft_putendl("fini");
	}
	mlx_put_image_to_window (env->mlx, env->win, env->image, 0, 0);
	env->done = 1;
	return (0);
}

int			key_down_hook(int keycode, t_env *env)
{
	(void)env;
	if ((int)keycode == 53)
		exit (0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
		ft_error("probleme d'argument");
	recuperator(&env, argv[1]);
	parser_test(&env);
	env.done = 0;
	ft_putendl("post recup");
	env.mlx = mlx_init();
	ft_putendl("post1");
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, "RTV1");
	ft_putendl("post2");
	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	ft_putendl("post3");
	env.img = mlx_get_data_addr(env.image, &env.bpp, &env.sline, &env.endiant);
	 ft_putendl("post4");
	ft_bzero(env.img, H_SIZE * L_SIZE * 4);
	ft_putendl("post5");
	mlx_hook(env.win, 2, 1, key_down_hook, &env);
	ft_putendl("post6");
	mlx_loop_hook(env.mlx, expose_hook, &env);
	ft_putendl("post7");
	mlx_loop(env.mlx);
	ft_putendl("post8");
	return (0);
}