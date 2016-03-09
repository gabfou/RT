/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:47 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 14:42:55 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_foreach(t_dlist *list, t_functor functor, void *data)
{
	t_dlist	*it;

	it = list;
	if (it)
	{
		while (it->next != list)
		{
			functor(it->content, it->content_size, data);
			it = it->next;
		}
		functor(it->content, it->content_size, data);
	}
}
