/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:50 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:49:30 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_delete(t_dlist **head, t_deleter del)
{
	t_dlist	*it;
	t_dlist	*tmp;

	if (*head)
	{
		it = (*head)->previous;
		if (it)
		{
			while (it != *head)
			{
				tmp = it->previous;
				del(it->content, it->content_size);
				free(it);
				it = tmp;
			}
			del(it->content, it->content_size);
			free(it);
		}
		*head = 0;
	}
}
