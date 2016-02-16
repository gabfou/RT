/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 16:01:54 by gfournie          #+#    #+#             */
/*   Updated: 2015/06/12 18:48:50 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char c, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (s3 == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		s3[i] = s1[j];
		i++;
		j++;
	}
	s3[i++] = c;
	j = -1;
	while (s2[++j] != '\0')
	{
		s3[i] = s2[j];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}