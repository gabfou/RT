/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:40 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:49:20 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_remove(t_dlist **head, t_dlist *elem, t_deleter del)
{
	t_dlist	*prev;
	t_dlist	*next;

	if (*head)
	{
		prev = elem->previous;
		next = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		if (*head == elem)
			*head = (elem == next ? 0 : next);
		prev->next = next;
		next->previous = prev;
	}
}
