/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlpanelator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:24:37 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/17 23:24:46 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// t_limg		*new_t_limg2()
// {
// 	t_limg	*ret;

// 	ret = malloc(sizeof(t_limg));
// 	ret->image = NULL;
// 	ret->img = NULL;
// 	ret->prev = NULL;
// 	ret->next = NULL;
// 	return (ret);
// }

inline void	*imgcptor(t_env *env)
{
	static t_limg	*limg = NULL;

	(void)env;(void)limg;
	// if (limg == NULL)
	// {
	// 	limg = malloc(sizeof(t_limg));
	// 	limg->image = mlx_new_image(env->mlx, env->screen.l, env->screen.h);;
	// 	limg->img = mlx_get_data_addr(limg->image, &limg->bpp, &limg->sline, &env->endiant);
	// 	limg->prev = NULL;
	// 	limg->next = NULL;
	// 	printmusicator(limg, env);
	// }
// 	if (env->ft % 2 == 1)
// 		mlx_put_image_to_window(env->mlx, env->win, limg->image, env->screen.l, 0);
	return (NULL);
}
