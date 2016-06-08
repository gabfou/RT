/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 12:04:24 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/21 17:07:34 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	map_foreach(t_btree *root, t_simple_functor functor, void *data)
{
	if (root)
	{
		functor(root->content, data);
		map_foreach(root->left, functor, data);
		map_foreach(root->right, functor, data);
	}
}

void		ft_map_foreach(t_map map, t_simple_functor functor, void *data)
{
	size_t	i;

	i = 0;
	while (i < MAP_TREE_SIZE)
		map_foreach(map[i++], functor, data);
}
