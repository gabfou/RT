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
	unsigned char bmp[ L_SIZE * H_SIZE * 4 + 1000];
	int i;
	// int j;

	//unsigned char bmppad[3] = {0,0,0};
	ft_putendl("ENREGISTRATOR");
	size = L_SIZE * H_SIZE * 4;
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)(size);
	bmp[3] = (unsigned char)(size >>  8);
	bmp[4] = (unsigned char)(size >> 16);
	bmp[5] = (unsigned char)(size >> 24);
	i = 5;
	// while (++i < 14)
	// 	bmp[i] = 0;
	bmp[6] = 0;
	bmp[7] = 0;
	bmp[8] = 0;
	bmp[9] = 0;
	bmp[10] = 55;
	bmp[11] = 0;
	bmp[12] = 0;
	bmp[13] = 0;
	bmp[14] = 0;
	bmp[15] = 28;
	bmp[16] = 0;
	bmp[17] = 0;
	bmp[18] = (unsigned char)(L_SIZE);
	bmp[19] = (unsigned char)(L_SIZE >>  8);
	bmp[20] = (unsigned char)(L_SIZE >> 16);
	bmp[21] = (unsigned char)(L_SIZE >> 24);
	bmp[22] = (unsigned char)(H_SIZE);
	bmp[23] = (unsigned char)(H_SIZE >>  8);
	bmp[24] = (unsigned char)(H_SIZE >> 16);
	bmp[25] = (unsigned char)(H_SIZE >> 24);
	bmp[26] = 1;
	bmp[27] = 0;
	bmp[28] = 32;
	bmp[29] = 0;
	i = 29;
	while (++i < 54)
		bmp[i] = 0;
	while (++i - 55 < size)
	{	// write(1, &(env->img[i]), 1);
		bmp[i] = env->img[i - 55];
		// i = i + 4;
	}
	i = open("niark.bmp", O_CREAT | O_WRONLY);
	// j = -1;
	// while (++j < H_SIZE)
	write(i, bmp, size + 55);
	// ft_putstr_l(env->img, 51);
}

// #include "reader.h"
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// void	enregistrator(t_env *e)
// {
// 	t_header		fh;
// 	t_header_info	ih;

// 	int	fd_img;

// 	fd_img = open("./mickey.bmp", O_RDONLY);

// 	read(fd_img, &fh, sizeof(t_header));
// 	read(fd_img, &ih, sizeof(t_header_info));

// 	printf("fM1 = %c, fM2 = %c, bfS = %u, un1 = %hu, un2 = %hu, iDO = %u\n", fh.fileMarker1, fh.fileMarker2, fh.bfSize, fh.unused1, fh.unused2, fh.imageDataOffset);                                                                         
//     printf("w = %d, h = %d\n", ih.width, ih.height);

//     char	*image;

//     image = (char *)malloc(sizeof(char) * (fh.bfSize + 1));

//     read(fd_img, image, fh.bfSize);

//     int		fd;
//     fd = open("./my_micky.bmp", O_RDWR | O_CREAT);

//     write(fd, &fh, sizeof(t_header));
//     write(fd, &ih, sizeof(t_header_info));
//     write(fd, image, fh.bfSize);

// 	return (0);
// }
