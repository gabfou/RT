/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:15:15 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/30 18:25:13 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(size_t, char))
{
	char	*mapped;
	size_t	i;

	if (!s)
		return (0);
	mapped = ft_strnew(ft_strlen(s));
	if (mapped)
	{
		i = 0;
		while (*s)
		{
			mapped[i] = f(i, *s++);
			++i;
		}
	}
	return (mapped);
}
