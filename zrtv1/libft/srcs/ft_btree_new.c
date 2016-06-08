/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:55:49 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:58:02 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_new(void *content, size_t content_size)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	if (node)
	{
		node->content_size = (content ? content_size : 0);
		node->content = (content ? malloc(content_size) : 0);
		if (node->content)
			ft_memcpy(node->content, content, content_size);
		node->left = 0;
		node->right = 0;
	}
	return (node);
}
