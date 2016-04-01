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
	void		*pointf;
	int			x;
	int			y;
	int			px;
	int			py;
	int			i;
	pthread_t	thread_ecran[800];
	static t_cor		tab[8];

	y = 0;
	i = 0;
	px = env->screen.l;
	py = env->screen.h / NBTHREAD;
	pointf = &(creator);
	while (y < env->screen.h)
	{
		// printf("y = %d\n", y);
		x = 0;
		while (x < env->screen.l)
		{
			tab[i].minx = x;
			tab[i].maxx = x + px;
			tab[i].miny = y;
			tab[i].maxy = y + py;
			tab[i].env = env;
			//printf("i =%d xmin = %f xmax = %f ymin = %f ymax = %f\n", i, env->xmin, env->xmax, env->ymin, env->ymax );
			if (pthread_create(&(thread_ecran[i]), NULL, pointf, &tab[i]) != 0)
				ft_error("creation de thread rate");
			// ft_putendl("THREAD CREE");
			//sleep(10);
			x = x + px;
			i++;
		}
		y = y + py;
	}
	return (0);
}