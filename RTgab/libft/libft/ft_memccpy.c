/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:32:57 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/09 16:53:40 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s1;
	char		*s2;
	int			i;

	s1 = src;
	s2 = dst;
	i = 0;
	while (n != 0)
	{
		s2[i] = s1[i];
		if (s1[i] == c)
			return ((char*)&s2[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
