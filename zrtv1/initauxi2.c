/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initauxi2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 22:13:46 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/24 22:13:47 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline t_vec		set_screen(t_cam *cam)
{
	float		x;
	float		y;
	float		z;

	x = cam->dir.x * SCR_DIST - cam->up.x * SCR_H - cam->right.x * SCR_L;
	y = cam->dir.y * SCR_DIST - cam->up.y * SCR_H - cam->right.y * SCR_L;
	z = cam->dir.z * SCR_DIST - cam->up.z * SCR_H - cam->right.z * SCR_L;
	return (new_t_vec(x, y, z));
}

inline void			initmat(t_list **tokens, t_item *item)
{
	t_color	rgb;

	rgb.r = 1;
	rgb.g = 1;
	rgb.b = 1;
	if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
		rgb.r = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
		rgb.g = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
		rgb.b = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "mat") == 0)
	{
		next_elem(tokens);
		item->mat = new_t_mat(get_token(tokens)->lexeme);
	}
	else if (ft_strcmp(get_token(tokens)->lexeme, "ref") == 0)
		item->mat.ref = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "trans") == 0)
		item->mat.trans = token_to_float(tokens);
	item->mat.diff = new_t_color(rgb.r, rgb.g, rgb.b);
}

inline int			get_t_cam_lenght(t_cam *cam)
{
	t_cam	*tmp;
	int		i;

	i = 0;
	tmp = cam;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

inline void			init_env(t_leviatenv *levia)
{
	levia->mlx = mlx_init();
	levia->win = mlx_new_window(levia->mlx, L_SIZE, H_SIZE, "RTV1");
	levia->lenv = NULL;
}
