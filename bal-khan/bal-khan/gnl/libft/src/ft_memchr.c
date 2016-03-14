/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:38:17 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 08:42:13 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int a;

	a = -1;
	while ((size_t)++a < n)
	{
		if (*((unsigned char*)s + a) == (unsigned char)c)
			return ((void*)s + a);
	}
	return (NULL);
}
