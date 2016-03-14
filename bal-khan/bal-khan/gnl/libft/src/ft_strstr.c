/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:34:05 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 08:01:18 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *str;
	const char *strfind;

	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	while (*s1 != '\0')
	{
		str = s1;
		strfind = s2;
		while (*str == *strfind && *str != '\0' && strfind != '\0')
		{
			str++;
			strfind++;
		}
		if (*strfind == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
