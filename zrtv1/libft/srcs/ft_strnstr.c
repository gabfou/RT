/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:48:19 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/21 13:57:17 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;

	if (!*s2)
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	while (*s1 && n-- >= s2_len)
	{
		if (!ft_strncmp(s1, s2, s2_len))
			return ((char *)s1);
		++s1;
	}
	return (0);
}
