/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:32:16 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 07:55:33 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int a;

	a = 0;
	while (*(s + a) != '\0')
	{
		if (*(s + a) == (char)c)
			return ((char*)(s + a));
		a++;
	}
	if ((char)c == '\0')
		return ((char*)(s + a));
	else
		return (NULL);
}
