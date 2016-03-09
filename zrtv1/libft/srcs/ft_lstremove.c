/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:50:17 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/10 21:57:45 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove(t_list **alst, void *elem, size_t size, t_comparator cmp)
{
	t_list	*it;
	t_list	*previous;

	it = *alst;
	previous = 0;
	while (it)
	{
		if (cmp(it->content, it->content_size, elem, size))
		{
			if (!previous)
				*alst = it->next;
			else
				previous->next = it->next;
			return (it);
		}
		previous = it;
		it = it->next;
	}
	return (0);
}
