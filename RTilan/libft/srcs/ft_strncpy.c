/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:03:10 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/07 15:34:11 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*idst;

	idst = dst;
	while (*src && n)
	{
		*idst++ = *src++;
		--n;
	}
	while (n--)
		*idst++ = '\0';
	return (dst);
}
