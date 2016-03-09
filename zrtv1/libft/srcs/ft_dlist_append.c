/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:36 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:28:39 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_append(t_dlist **head, t_dlist *new_elem)
{
	t_dlist	*last;

	if (!*head)
	{
		new_elem->next = new_elem;
		new_elem->previous = new_elem;
		*head = new_elem;
	}
	else
	{
		last = (*head)->previous;
		last->next = new_elem;
		new_elem->previous = last;
		new_elem->next = *head;
		(*head)->previous = new_elem;
	}
}
