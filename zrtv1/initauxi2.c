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

t_limg				*readerxpm(char *name)
{
	static void	*sar = NULL;
	t_limg		*ret;
	// int			i = 5000;
	// int			j = 5000;
	int k;

	if (sar == NULL)
		sar = mlx_init();
	ret = malloc(sizeof(t_limg));
	ret->image = mlx_xpm_file_to_image(sar, name, &ret->i, &ret->l);
	if (ret->image == NULL)
		ft_error("texture pas bien");
	// ft_putnbr(i);
	ft_putendl("niark");
	ret->img = mlx_get_data_addr(ret->image, &ret->bpp, &ret->sline, &k);
	ft_putendl("niark3");
	ret->k = 1;
	ret->prev = NULL;
	ret->next = NULL;
	ft_putendl("niark2");
	void *niark = mlx_new_window(sar, ret->i, ret->l, name);
	mlx_put_image_to_window(sar, niark, ret->image, 0, 0);
	mlx_do_sync(sar);
	// sleep(10);
	return (ret);
}


inline t_vec		set_screen(t_cam *cam, t_screen screen)
{
	FLOAT_SIZE		x;
	FLOAT_SIZE		y;
	FLOAT_SIZE		z;

	x = cam->dir.x * screen.scrd - cam->up.x * screen.scrl - cam->right.x * screen.scrh;
	y = cam->dir.y * screen.scrd - cam->up.y * screen.scrl - cam->right.y * screen.scrh;
	z = cam->dir.z * screen.scrd - cam->up.z * screen.scrl - cam->right.z * screen.scrh;
	return (new_t_vec(x, y, z));
}

inline void			initmat(t_list **tokens, t_item *item)
{

	if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
		item->mat.diff.r = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
		item->mat.diff.g = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
		item->mat.diff.b = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "mat") == 0)
	{
		next_elem(tokens);
		item->mat = new_t_mat(get_token(tokens)->lexeme);
	}
	else if (ft_strcmp(get_token(tokens)->lexeme, "ref") == 0)
		item->mat.ref = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "trans") == 0)
		item->mat.trans = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "texture") == 0)
	{
		next_elem(tokens);
		item->texture = readerxpm(get_token(tokens)->lexeme);
	}
	item->mat.diff.r = (item->mat.diff.r > 1) ? 1 : item->mat.diff.r;
	item->mat.diff.g = (item->mat.diff.g > 1) ? 1 : item->mat.diff.g;
	item->mat.diff.b = (item->mat.diff.b > 1) ? 1 : item->mat.diff.b;
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
	levia->lenv = NULL;
}
