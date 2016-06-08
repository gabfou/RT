/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:29 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:28:58 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_new(void *content, size_t content_size)
{
	t_dlist	*element;

	element = (t_dlist *)malloc(sizeof(t_dlist));
	if (element)
	{
		element->content_size = (content ? content_size : 0);
		element->content = (content ? malloc(content_size) : 0);
		if (element->content)
			ft_memcpy(element->content, content, content_size);
		element->next = 0;
		element->previous = 0;
	}
	return (element);
}
