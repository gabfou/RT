/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:11:10 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 16:57:23 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		s3[i] = s1[j];
		i++;
		j++;
	}
	j = -1;
	while (s2[++j] != '\0')
	{
		s3[i] = s2[j];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
