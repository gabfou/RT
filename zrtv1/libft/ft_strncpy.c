/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:42:36 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/30 23:59:18 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)

{
	char *s;

	s = dst;
	while (n > 0 && *src != '\0')
	{
		*dst++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*dst++ = '\0';
		--n;
	}
	return (dst);
}
