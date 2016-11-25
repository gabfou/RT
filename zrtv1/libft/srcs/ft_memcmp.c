/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 03:58:04 by gudepard          #+#    #+#             */
/*   Updated: 2016/06/11 21:12:53 by ibuchwal         ###   ########.fr       */
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
			return ((t_uchar)(*is1) - (t_uchar)(*is2));
		++is1;
		++is2;
	}
	return (0);
}
