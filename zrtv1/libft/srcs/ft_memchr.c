/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:05:30 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/06 05:25:24 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar		cc;
	const char	*str;
	size_t		i;

	cc = (t_uchar)c;
	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return ((char*)&str[i]);
		++i;
	}
	return (0);
}
