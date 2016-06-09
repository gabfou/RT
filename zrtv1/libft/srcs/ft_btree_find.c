/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 12:51:39 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/19 12:55:18 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btree_find(t_btree *node, void *n, size_t s, t_comparator cmp)
{
	int		cmp_value;

	if (node)
	{
		cmp_value = cmp(node->content, node->content_size, n, s);
		if (!cmp_value)
			return (node);
		if (cmp_value > 0)
			return (ft_btree_find(node->right, n, s, cmp));
		return (ft_btree_find(node->left, n, s, cmp));
	}
	return (0);
}
