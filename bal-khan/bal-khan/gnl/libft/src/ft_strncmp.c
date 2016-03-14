/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:53:17 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 08:46:41 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char*)s1;
	source = (unsigned char*)s2;
	if (!dest && !source)
		return (0);
	i = 0;
	while ((i < n) && (dest[i] == source[i] && dest[i]))
		i++;
	if (i < n)
		return (dest[i] - source[i]);
	return (0);
}
