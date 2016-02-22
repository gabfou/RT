/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niark.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 11:51:46 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/17 19:57:43 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		NIARK_H
# define	NIARK_H

# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <stdio.h>

typedef unsigned	int				t_uint32;
typedef struct		s_params		t_params;
typedef struct		s_image			t_image;

struct			s_image
{
	void		*mlx_ptr;
	void		*mlx_img;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
};

struct s_params
{
	void	*mlx;
	void	*win;
	t_image	*frame;
};

t_uint32	swap_endian(t_uint32 in);
t_image		*image_new(void *mlx, int width, int height);
void		image_delete(t_image *image);
t_uint32	true_color(void *mlx, int endian, int rgb);
void		image_pixel_put(t_image *image, int x, int y, t_uint32 color);

#endif		/* !NIARK_H */
