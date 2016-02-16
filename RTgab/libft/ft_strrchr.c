/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:50:19 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 17:20:01 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			s1 = (char*)&s[i];
		i++;
	}
	if (s[i] == c)
		s1 = (char*)&s[i];
	return (s1);
}
