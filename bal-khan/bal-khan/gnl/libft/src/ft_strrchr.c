/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:33:48 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 08:01:06 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)(s + a));
	while (a >= 0)
	{
		if (*(s + a) == (char)c)
			return ((char*)(s + a));
		a--;
	}
	return (NULL);
}
