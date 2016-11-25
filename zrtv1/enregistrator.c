/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enregistrator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 20:11:12 by jromagna          #+#    #+#             */
/*   Updated: 2016/06/11 21:21:46 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			bmpprepa(t_env *env, int size, unsigned char *bmp)
{
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)(size);
	bmp[3] = (unsigned char)(size >> 8);
	bmp[4] = (unsigned char)(size >> 16);
	bmp[5] = (unsigned char)(size >> 24);
	bmp[10] = 55;
	bmp[15] = 28;
	bmp[18] = (unsigned char)(env->screen.l);
	bmp[19] = (unsigned char)(env->screen.l >> 8);
	bmp[20] = (unsigned char)(env->screen.l >> 16);
	bmp[21] = (unsigned char)(env->screen.l >> 24);
	bmp[22] = (unsigned char)(env->screen.h);
	bmp[23] = (unsigned char)(env->screen.h >> 8);
	bmp[24] = (unsigned char)(env->screen.h >> 16);
	bmp[25] = (unsigned char)(env->screen.h >> 24);
	bmp[26] = 1;
	bmp[28] = 32;
	return (54);
}

void		enregistrator(t_env *env)
{
	int				size;
	unsigned char	bmp[env->screen.l * env->screen.h * 4 + 55];
	int				i;
	int				j;
	int				k;

	size = env->screen.l * env->screen.h * 4;
	ft_bzero(bmp, env->screen.l * env->screen.h * 4 + 55);
	i = bmpprepa(env, size, bmp);
	j = -1;
	while (++j < env->screen.h)
	{
		k = -1;
		while (++k < env->screen.l)
		{
			size = (env->screen.h - j)
				* env->limg->sline + k * env->limg->bpp / 8;
			bmp[++i] = env->limg->img[size];
			bmp[++i] = env->limg->img[size + 1];
			bmp[++i] = env->limg->img[size + 2];
			bmp[++i] = env->limg->img[size + 3];
		}
	}
	i = open("niark.bmp", O_CREAT | O_WRONLY);
	write(i, bmp, size + 55);
}
