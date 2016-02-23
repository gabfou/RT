/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:34:45 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/05 16:30:51 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s1;
	size_t		i;
	int			j;
	unsigned	k;

	k = len;
	if (len == 0)
		return ("");
	if (s == NULL || k > 2147483647)
		return (NULL);
	i = start;
	j = 0;
	s1 = ft_strnew(len);
	if (!s1)
		return (NULL);
	while (i < (start + len))
	{
		s1[j] = s[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
