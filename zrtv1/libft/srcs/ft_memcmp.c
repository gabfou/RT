/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 03:58:04 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/06 05:25:24 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*is1;
	const char	*is2;

	is1 = (const char *)s1;
	is2 = (const char *)s2;
	if (!s1 && !s2)
		return (0);
	while (n--)
	{
		if (*is1 != *is2)
			return ((t_uchar)*is1 - (t_uchar)*is2);
		++is1;
		++is2;
	}
	return (0);
}
