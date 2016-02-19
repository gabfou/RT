/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:06:57 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/13 21:02:16 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (ft_strcmp(s2, "") == 0)
		return ((char*)s1);
	while (s1[++i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			k = i;
			while (s1[k] == s2[j] && s1[k])
			{
				j++;
				k++;
				if (s2[j] == '\0')
					return ((char*)&s1[i]);
			}
		}
	}
	return (NULL);
}
