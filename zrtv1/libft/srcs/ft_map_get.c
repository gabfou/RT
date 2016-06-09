/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:01:42 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/21 18:00:22 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_map_entry	*recurse_get(t_btree *node, t_uint64 hash)
{
	t_map_entry		*entry;

	if (!node)
		return (0);
	entry = (t_map_entry *)node->content;
	if (hash == entry->_hash)
		return (entry);
	else if (hash < entry->_hash)
		return (recurse_get(node->left, hash));
	return (recurse_get(node->right, hash));
}

void				*ft_map_get(t_map map, void *key, t_simple_hash_func h_f)
{
	t_map_entry		*entry;

	entry = ft_map_get_p(map, key, h_f);
	if (entry)
		return (entry->value);
	return (0);
}

t_map_entry			*ft_map_get_p(t_map map, void *key, t_simple_hash_func h_f)
{
	t_map_entry		*entry;
	t_uint64		hash;

	hash = h_f(key);
	entry = recurse_get(map[hash % MAP_TREE_SIZE], hash);
	return (entry);
}
