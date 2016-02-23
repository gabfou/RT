/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:07:05 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/12 20:30:41 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;

	t = (t_list*)malloc(sizeof(t_list));
	if (t == NULL)
		return (NULL);
	if (content == NULL)
	{
		t->content = NULL;
		t->content_size = 0;
		t->next = NULL;
		return (t);
	}
	t->content = (void*)content;
	t->content_size = content_size;
	t->next = NULL;
	return (t);
}
