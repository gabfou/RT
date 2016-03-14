/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:31:57 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:06:09 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*pdst;
	const char	*psrc;
	size_t		n;
	size_t		dlen;

	pdst = dst;
	psrc = src;
	n = size;
	while (n-- != 0 && *pdst != '\0')
		pdst++;
	dlen = pdst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + strlen(psrc));
	while (*psrc)
	{
		if (n != 1)
		{
			*pdst++ = *psrc;
			n--;
		}
		psrc++;
	}
	*pdst = '\0';
	return (dlen + (psrc - src));
}
