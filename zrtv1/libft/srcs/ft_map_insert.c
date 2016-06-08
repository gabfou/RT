/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:39:45 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/21 16:06:05 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	insert_cmp(void *c, size_t c_s, void *n, size_t n_s)
{
	t_map_entry	*c_entry;
	t_map_entry	*n_entry;

	UNUSED(c_s);
	UNUSED(n_s);
	c_entry = (t_map_entry *)c;
	n_entry = (t_map_entry *)n;
	return (c_entry->_hash - n_entry->_hash);
}

void		ft_map_insert(t_map map, t_map_entry entry, t_simple_hash_func h_f)
{
	t_btree	*node;

	entry._hash = h_f(entry.key);
	node = ft_btree_new(&entry, sizeof(t_map_entry));
	ft_btree_insert(&map[entry._hash % MAP_TREE_SIZE], node, insert_cmp);
}

