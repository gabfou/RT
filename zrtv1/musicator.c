/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   musicator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:20:18 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/17 23:20:21 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*printmusicator(t_limg *limg, t_env *env)
{
	int i;
	int j;
	int k;

	(void)k;
	(void)env;
	if (limg)
	{
		k = 0;
		j = 300;
		while (++j < 350)
		{
			i = 200 - k;
			while (--i > 150 + k)
				pixel_to_image(j, i, 0xFFFFFF , limg);
			k++;
		}
		j = 100;
		k = 0;
		while (++j < 150)
		{
			i = 200 - k;
			while (++i < 150 + k)
				pixel_to_image(j, i, 0xFFFFFF , limg);
			k++;
		}
	}
	return (NULL);
}

void	nextrack(t_env *env, int sens)
{
	(void)env;
	if (sens)
		write(1, "1\n", 2);
	else
		write(1, "2\n", 2);
}
