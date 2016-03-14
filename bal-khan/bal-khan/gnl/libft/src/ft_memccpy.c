/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:38:05 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 03:01:51 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*ptrdst;
	const char	*ptrsrc;
	size_t		i;

	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		if (ptrdst[i] == (char)c)
			return (ptrdst + i + 1);
		i++;
	}
	return (NULL);
}
