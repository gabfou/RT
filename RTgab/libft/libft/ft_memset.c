/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:35:58 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 16:50:21 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s1;
	int				i;

	s1 = b;
	i = 0;
	while (len != 0)
	{
		s1[i] = c;
		i++;
		len--;
	}
	return (b);
}
