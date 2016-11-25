/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:07:13 by jromagna          #+#    #+#             */
/*   Updated: 2016/06/11 22:06:19 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
}

void		gpatrouverdnom(t_leviatenv *env, int argc, char *argv)
{
	static int x = 0;

	init(env->lenv, argc, argv);
	checkcamscreen(env->lenv);
	setcamuplef(env->lenv);
	if (x == 0)
	{
		env->win = mlx_new_window(env->mlx,
			env->lenv->screen.l, env->lenv->screen.h, "RT");
		x++;
	}
	t_limg_initator(env);
	if (env->lenv->screen.map > 0)
		env->lenv->prototree = helios(env->lenv->light, env->lenv);
}

void		filllevia(t_leviatenv *levia, char **argv, t_env *first, int argc)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (!levia->lenv)
		{
			levia->lenv = new_t_env();
			levia->lenv->nbr = i;
			first = levia->lenv;
		}
		else
		{
			levia->lenv->next = new_t_env();
			levia->lenv->next->nbr = i;
			levia->lenv->next->prev = levia->lenv;
			levia->lenv = levia->lenv->next;
		}
		gpatrouverdnom(levia, i, argv[i]);
	}
	levia->lenv->next = first;
	first->prev = levia->lenv;
	levia->lenv = first;
}

int			main(int argc, char **argv)
{
	t_leviatenv	levia;
	t_env		*first;
	int			i;

	if (argc == 1)
		ft_error("no argument");
	initfmod(&levia);
	first = NULL;
	ft_puttab(argv);
	init_env(&levia);
	filllevia(&levia, argv, first, argc);
	while (levia.lenv->prev->nbr < levia.lenv->nbr)
	{
		ft_putstr("nbr = ");
		ft_putnbr(levia.lenv->nbr);
		ft_putendl(" ;");
		levia.lenv = levia.lenv->prev;
	}
	i = ft_strlen(argv[1]) - 4;
	thread_master(levia.lenv);
	mlx_mouse_hook(levia.win, mouse_hook, &levia);
	mlx_hook(levia.win, 2, 1, key_down_hook, &levia);
	mlx_loop_hook(levia.mlx, expose_hook, &levia);
	mlx_loop(levia.mlx);
	return (0);
}
