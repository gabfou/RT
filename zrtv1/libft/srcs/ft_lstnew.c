/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:32:04 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/22 21:36:54 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element)
	{
		element->content_size = (content ? content_size : 0);
		element->content = (content ? malloc(content_size) : 0);
		if (element->content)
			ft_memcpy(element->content, content, content_size);
		element->next = 0;
	}
	return (element);
}
