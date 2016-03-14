/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:30:34 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:30:36 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_env(t_env *e)
{
	e->p.x = -0.5;
	e->p.y = -0.5;
	e->p.z = 4.0;
	set_cam(e);
	set_screen(e);
	e->ray.origin = e->cam;
}

t_env	init_mlx(int s_x, int s_y)
{
	t_env	ep;
	t_env	*e;

	e = &ep;
	e->s_x = s_x;
	e->s_y = s_y;
	if (!(e->mlx = mlx_init()))
		exit(1);
	if (!(e->win = mlx_new_window(e->mlx, e->s_x, e->s_y, "RTV1")))
		exit(1);
	if (!(e->img = mlx_new_image(e->mlx, e->s_x, e->s_y)))
		exit(1);
	if (!(e->data = mlx_get_data_addr(e->img, &(e->bbp),
									&(e->size_line), &(e->endian))))
		exit(1);
	return (ep);
}
