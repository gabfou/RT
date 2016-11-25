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
	int				i;
	pthread_t		thread_ecran[800];
	static t_cor	tab[NBTHREAD];

	i = -1;
	while (++i < NBTHREAD)
	{
		tab[i].minx = i * (env->screen.l / NBTHREAD);
		tab[i].maxx = (i + 1) * (env->screen.l / NBTHREAD) + 1;
		tab[i].miny = 0;
		tab[i].maxy = env->screen.h;
		tab[i].env = env;
		if (pthread_create(&(thread_ecran[i]), NULL,
			(void*)&(creator), &tab[i]) != 0)
			ft_error("creation de thread rate");
	}
	return (0);
}
