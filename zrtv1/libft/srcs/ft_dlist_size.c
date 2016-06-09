/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:55 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:31:27 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	inc(void *elem, size_t size, void *data)
{
	size_t	*i;

	(void)elem;
	(void)size;
	i = (size_t *)data;
	++(*i);
}

size_t		ft_dlist_size(t_dlist *list)
{
	size_t	size;

	size = 0;
	ft_dlist_foreach(list, inc, &size);
	return (size);
}
