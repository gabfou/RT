/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:22:45 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 16:28:15 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btree_pre_foreach(t_btree *root, t_functor functor, void *data)
{
	if (root)
	{
		functor(root->content, root->content_size, data);
		ft_btree_pre_foreach(root->left, functor, data);
		ft_btree_pre_foreach(root->right, functor, data);
	}
}

void		ft_btree_inf_foreach(t_btree *root, t_functor functor, void *data)
{
	if (root)
	{
		ft_btree_inf_foreach(root->left, functor, data);
		functor(root->content, root->content_size, data);
		ft_btree_inf_foreach(root->right, functor, data);
	}
}

void		ft_btree_post_foreach(t_btree *root, t_functor functor, void *data)
{
	if (root)
	{
		ft_btree_post_foreach(root->left, functor, data);
		ft_btree_post_foreach(root->right, functor, data);
		functor(root->content, root->content_size, data);
	}
}
