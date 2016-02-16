/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:26:55 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 23:33:13 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*s;
	unsigned	k;

	k = size;
	if (k > 2147483647 || size == 0)
		return (NULL);
	s = malloc(sizeof(void) * (size + 1));
	if (s == NULL)
		return (NULL);
	ft_bzero (s, size);
	return (s);
}
