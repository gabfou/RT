/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:30:10 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/07 16:11:44 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		n--;
		i++;
	}
	return (dst);
}
