/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:18:43 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/02/25 21:34:14 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// void		initktc(t_env *e)
// {
// 	char *tab;

// 	//(void)(e);
// 	tab = malloc(1000);
// 	//ft_bzero((tab), 1000);
// 	e->ktc = ft_strdup("test");
// 	ft_putendl(e->ktc);
// }

void		init(t_env *env)
{
	env->l = 0;
	env->done = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, L_SIZE, H_SIZE, "RTV1");
	env->image = mlx_new_image(env->mlx, L_SIZE, H_SIZE);
	env->img = mlx_get_data_addr(env->image, &env->bpp, &env->sline, &env->endiant);
	env->i = 1;
	// initktc(env);
	ft_putendl("ASFGDSHBSHSRRSH");
}
