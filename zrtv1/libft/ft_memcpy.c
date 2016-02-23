/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:30:10 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/07 16:11:44 by jromagna         ###   ########.fr       */
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
