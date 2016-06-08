/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:09:16 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/07 15:33:19 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = (char *)s1;
	str2 = (const char *)s2;
	while (n--)
		str1[n] = str2[n];
	return (s1);
}
