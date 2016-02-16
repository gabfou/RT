/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:05:46 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 17:32:46 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s));
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
