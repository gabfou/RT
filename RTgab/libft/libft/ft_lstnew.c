/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:47:41 by gfournie          #+#    #+#             */
/*   Updated: 2015/06/12 21:22:48 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*r;
	int		i;

	i = -1;
	r = malloc(sizeof(*r));
	if (!content)
		return (NULL);
	if (r)
	{
		r->content = malloc(content_size);
		if (!(r->content))
			return (NULL);
		while (++i <= (int)content_size)
			((char*)(r->content))[i] = ((char*)content)[i];
		r->content_size = content_size;
		r->next = NULL;
	}
	return (r);
}
