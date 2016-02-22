/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 12:39:59 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/19 13:40:48 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rebuild_tree(t_btree *n, t_btree *i, t_btree **r, t_comparator cmp)
{
	if (n)
	{
		if (n != i)
			ft_btree_insert(r, n, cmp);
		rebuild_tree(n->left, i, r, cmp);
		rebuild_tree(n->right, i, r, cmp);
	}
}

t_btree		*ft_btree_remove(t_btree **r, void *n, size_t s, t_comparator cmp)
{
	t_btree	*removed;
	t_btree	*new_tree;

	new_tree = 0;
	removed = ft_btree_find(*r, n, s, cmp);
	rebuild_tree(*r, removed, &new_tree, cmp);
	*r = new_tree;
	return (removed);
}
