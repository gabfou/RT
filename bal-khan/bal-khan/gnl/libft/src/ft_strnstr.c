/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:34:19 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 08:46:04 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	char	*dest;
	char	*source;
	int		len;

	if (*s2 == '\0')
		return ((char *)s1);
	dest = (char*)s1;
	source = (char*)s2;
	len = ft_strlen(source);
	a = 0;
	while (*(dest + a) != '\0' && (a + len) <= n)
	{
		if (ft_strncmp(s1 + a, s2, len) == 0)
		{
			return (dest + a);
		}
		a++;
	}
	return (NULL);
}
