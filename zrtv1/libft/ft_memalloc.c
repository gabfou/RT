/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:26:55 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/12 23:33:13 by jromagna         ###   ########.fr       */
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
