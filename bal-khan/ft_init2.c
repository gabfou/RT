/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 12:46:35 by bal-khan          #+#    #+#             */
/*   Updated: 2016/01/03 12:46:37 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_reducer(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_bzero(e->data, e->s_x * e->s_y * 4);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
