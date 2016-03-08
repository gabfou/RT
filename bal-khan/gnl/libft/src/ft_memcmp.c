/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:38:24 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 05:05:31 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		a;
	char	c;

	a = -1;
	while ((size_t)++a < n)
	{
		if ((*((char*)s2 + a)) == '\0')
			return (-(int)(*((char*)s1 + a)));
		if ((*((char*)s1 + a)) != (*((char*)s2 + a)))
		{
			c = (*((char*)s1 + a)) - (*((char*)s2 + a));
			return ((int)c);
		}
	}
	return (0);
}
