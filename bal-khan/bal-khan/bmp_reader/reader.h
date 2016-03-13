/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 05:58:33 by bal-khan          #+#    #+#             */
/*   Updated: 2016/03/11 05:58:38 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../rtv1.h"

typedef struct		s_header
{
	unsigned char	file_marker1;
	unsigned char	file_marker2;
	unsigned int	bf_size;
	short			unused1;
	short			unused2;
	unsigned int	image_data_offset;
	unsigned int	bi_size;
	int				width;
	int				height;
	short			planes;
	short			bit_pix;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_xpels_per_meter;
	int				bi_ypels_per_meter;
	unsigned int	bi_clrused;
	unsigned int	bi_clr_important;
}					t_header;

void    write_header(int fd, t_env *e);
void    init_image(int *fd, t_env *e);

#endif
