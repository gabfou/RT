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
		printf("%d\n", str);
		//write(1, &str[i], 1);
		i = i + 4;
	}
}

void		enregistrator(t_env *env)
{
	(void)env;
	int	size;
	unsigned char bmp[100000];
	int i;

	//unsigned char bmppad[3] = {0,0,0};
	ft_putendl("ENREGISTRATOR");
	size = L_SIZE * H_SIZE * 4;
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)(size);
	bmp[3] = (unsigned char)(size>> 8);
	bmp[4] = (unsigned char)(size>>16);
	bmp[5] = (unsigned char)(size>>24);
	i = 5;
	while (++i < 14)
		bmp[i] = 0;
	// bmp[6] = 0;
	// bmp[7] = 0;
	// bmp[8] = 0;
	// bmp[9] = 0;
	// bmp[10] = 0;
	// bmp[11] = 0;
	// bmp[12] = 0;
	// bmp[13] = 0;

	bmp[14] = 40;
	bmp[15] = 0;
	bmp[16] = 0;
	bmp[17] = 0;
	bmp[18] = (unsigned char)(L_SIZE);
	bmp[19] = (unsigned char)(L_SIZE>> 8);
	bmp[20] = (unsigned char)(L_SIZE>>16);
	bmp[21] = (unsigned char)(L_SIZE>>24);
	bmp[22] = (unsigned char)(H_SIZE);
	bmp[23] = (unsigned char)(H_SIZE>> 8);
	bmp[24] = (unsigned char)(H_SIZE>>16);
	bmp[25] = (unsigned char)(H_SIZE>>24);
	bmp[26] = 1;
	bmp[27] = 0;
	bmp[28] = 32;
	bmp[29] = 0;
	i = 29;
	while (++i < 50)
		bmp[i] = 0;
	ft_putstr_l(env->img, 2000);
}
