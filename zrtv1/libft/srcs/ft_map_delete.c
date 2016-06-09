/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:44:48 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/21 18:46:33 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_free(t_btree *node, t_map_deleter del)
{
	t_map_entry	*entry;

	if (node)
	{
		recurse_free(node->left, del);
		recurse_free(node->right, del);
		entry = (t_map_entry *)node->content;
		del(entry->key, entry->value);
		free(entry);
		free(node);
	}
}

void		ft_map_delete(t_map map, t_map_deleter del)
{
	size_t	i;

	i = 0;
	while (i < MAP_TREE_SIZE)
		recurse_free(map[i++], del);
	ft_bzero(map, sizeof(t_map));
}
