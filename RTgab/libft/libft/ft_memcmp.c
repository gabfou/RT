/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:10:33 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 17:02:01 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s3;
	char	*s4;
	int		i;

	s3 = (char*)s1;
	s4 = (char*)s2;
	i = 0;
	while (n != 0)
	{
		if (s3[i] != s4[i])
			return ((unsigned char)s3[i] - (unsigned char)s4[i]);
		i++;
		n--;
	}
	return (0);
}
