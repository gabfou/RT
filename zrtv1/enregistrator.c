/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enregistator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 20:11:12 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/03 20:11:15 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_putstr_l(char *str, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		printf("i = %d = %d\n", i, str[i]);
		// write(1, &str[i], 1);
		i = i + 4;
	}
}

void		enregistrator(t_env *env)
{
	(void)env;
	int	size;
	unsigned char bmp[L_SIZE * H_SIZE * 4 + 55];
	int i;
	int j;
	int k;

	ft_putendl("ENREGISTRATOR");
	size = L_SIZE * H_SIZE * 4;
	ft_bzero(bmp, L_SIZE * H_SIZE * 4 + 55);
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)(size);
	bmp[3] = (unsigned char)(size >>  8);
	bmp[4] = (unsigned char)(size >> 16);
	bmp[5] = (unsigned char)(size >> 24);
	bmp[10] = 55;
	bmp[15] = 28;
	bmp[18] = (unsigned char)(L_SIZE);
	bmp[19] = (unsigned char)(L_SIZE >>  8);
	bmp[20] = (unsigned char)(L_SIZE >> 16);
	bmp[21] = (unsigned char)(L_SIZE >> 24);
	bmp[22] = (unsigned char)(H_SIZE);
	bmp[23] = (unsigned char)(H_SIZE >>  8);
	bmp[24] = (unsigned char)(H_SIZE >> 16);
	bmp[25] = (unsigned char)(H_SIZE >> 24);
	bmp[26] = 1;
	bmp[28] = 32;
	i = 54;
	j = -1;
	while (++j < H_SIZE)
	{
		k = -1;
		while (++k < L_SIZE)
		{
			bmp[++i] = env->img[(H_SIZE - j) * env->sline + k * env->bpp / 8];
			bmp[++i] = env->img[(H_SIZE - j) * env->sline + k * env->bpp / 8 + 1];
			bmp[++i] = env->img[(H_SIZE - j) * env->sline + k * env->bpp / 8 + 2];
			bmp[++i] = env->img[(H_SIZE - j) * env->sline + k * env->bpp / 8 + 3];
		}
	}
	// while (++i - 55 < size)
	// {
	// 	bmp[i] = env->img[i - 55];
	// }
	i = open("niark.bmp", O_CREAT | O_WRONLY);
	write(i, bmp, size + 55);
	// ft_putstr_l(env->img, 51);
}
