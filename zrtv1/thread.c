/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:41:25 by jromagna          #+#    #+#             */
/*   Updated: 2016/02/28 19:41:26 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int			thread_master(t_env *env)
{
	int			x;
	int			y;
	int			py;
	int			i;
	pthread_t	thread_ecran[800];
	static t_cor		tab[8];

	y = 0;
	i = 0;
	py = env->screen.h / NBTHREAD;
	while (y < env->screen.h)
	{
		x = 0;
		while (x < env->screen.l)
		{
			tab[i].minx = x;
			tab[i].maxx = x + env->screen.l;
			tab[i].miny = y;
			tab[i].maxy = y + py;
			tab[i].env = env;
			if (pthread_create(&(thread_ecran[i]), NULL, (void*)&(creator), &tab[i]) != 0)
				ft_error("creation de thread rate");
			x = x + env->screen.l;
			i++;
		}
		y = y + py;
	}
	return (0);
}