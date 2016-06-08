/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:09:00 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 16:38:58 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_insert(t_btree *node, t_btree *n, t_comparator cmp)
{
	if (cmp(node->content, node->content_size, n->content, n->content_size) < 0)
	{
		if (!node->left)
			node->left = n;
		else
			recurse_insert(node->left, n, cmp);
	}
	else
	{
		if (!node->right)
			node->right = n;
		else
			recurse_insert(node->right, n, cmp);
	}
}

void		ft_btree_insert(t_btree **r, t_btree *n, t_comparator cmp)
{
	if (!*r)
		*r = n;
	else
		recurse_insert(*r, n, cmp);
}
