/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:08:51 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/06 05:25:25 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	t_uchar		cc;
	char		*str1;
	const char	*str2;
	size_t		i;

	cc = (t_uchar)c;
	str1 = (char *)s1;
	str2 = (const char *)s2;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i++] == cc)
			return (&str1[i]);
	}
	return (0);
}
