/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:36:09 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/21 17:14:16 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		remove_cmp(void *c, size_t c_s, void *n, size_t n_s)
{
	t_map_entry	*c_entry;
	t_map_entry	*n_entry;

	UNUSED(c_s);
	UNUSED(n_s);
	c_entry = (t_map_entry *)c;
	n_entry = (t_map_entry *)n;
	return (c_entry->_hash - n_entry->_hash);
}

void			ft_map_remove(t_map map, void *key, t_simple_hash_func f,
								t_map_deleter del)
{
	t_btree		*removed;
	t_map_entry	entry;
	t_map_entry	*removed_entry;
	t_uint64	tree_idx;

	entry.key = key;
	entry._hash = f(key);
	tree_idx = entry._hash % MAP_TREE_SIZE;
	removed = ft_btree_remove(map + tree_idx, &entry, 0, remove_cmp);
	if (removed)
	{
		removed_entry = (t_map_entry *)removed->content;
		del(removed_entry->key, removed_entry->value);
		free(removed_entry);
		free(removed);
	}
}
