/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:18:09 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 16:38:49 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_free(t_btree *node, t_deleter del)
{
	if (node)
	{
		recurse_free(node->left, del);
		recurse_free(node->right, del);
		del(node->content, node->content_size);
		free(node);
	}
}

void		ft_btree_delete(t_btree **root, t_deleter del)
{
	t_btree	*top;

	top = *root;
	if (top)
	{
		recurse_free(top, del);
		*root = 0;
	}
}
