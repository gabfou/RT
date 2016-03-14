/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 05:58:23 by bal-khan          #+#    #+#             */
/*   Updated: 2016/03/11 05:58:28 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	write_header(int fd, t_env *e)
{
	int						filesize;
	static unsigned char	header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
	54, 0, 0, 0};
	static unsigned char	infoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 32, 0};

	filesize = 54 + 4 * e->s_x * e->s_y;
	header[2] = (unsigned char)(filesize);
	header[3] = (unsigned char)(filesize >> 8);
	header[4] = (unsigned char)(filesize >> 16);
	header[5] = (unsigned char)(filesize >> 24);
	infoheader[4] = (unsigned char)(e->s_x);
	infoheader[5] = (unsigned char)(e->s_x >> 8);
	infoheader[6] = (unsigned char)(e->s_x >> 16);
	infoheader[7] = (unsigned char)(e->s_x >> 24);
	infoheader[8] = (unsigned char)(e->s_y);
	infoheader[9] = (unsigned char)(e->s_y >> 8);
	infoheader[10] = (unsigned char)(e->s_y >> 16);
	infoheader[11] = (unsigned char)(e->s_y >> 24);
	write(fd, header, 14);
	write(fd, infoheader, 40);
}

void	init_image(int *fd, t_env *e)
{
	unsigned int	r;
	char			*path_img;

	r = -1;
	path_img = "./image_bmp.bmp";
	*fd = open(path_img, O_RDWR | O_CREAT, 0755);
	if (*fd < 0)
		exit(0);
	write_header(*fd, e);
}
