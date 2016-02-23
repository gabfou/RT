/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:08:14 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/12 22:11:28 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (ft_strcmp(s2, "") == 0)
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			k = i;
			while (s1[k] == s2[j] && k < n)
			{
				j++;
				k++;
				if (s2[j] == '\0')
					return ((char*)&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
