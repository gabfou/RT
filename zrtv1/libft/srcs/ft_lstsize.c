/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 04:40:30 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:54:58 by gudepard         ###   ########.fr       */
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

size_t		ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	ft_lstforeach(lst, inc, &size);
	return (size);
}
