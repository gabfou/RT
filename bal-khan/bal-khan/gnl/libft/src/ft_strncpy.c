/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:30:58 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:39:08 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int a;

	a = -1;
	while ((size_t)++a < n && *(src + a) != '\0')
	{
		if (*(src + a) != '\0')
			*(dst + a) = *(src + a);
	}
	while ((size_t)a != n)
	{
		*(dst + a) = '\0';
		a++;
	}
	return (dst);
}
