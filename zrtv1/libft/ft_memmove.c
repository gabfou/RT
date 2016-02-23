/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:54:03 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/12 16:49:52 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s1;
	char		*s2;
	char		*s3;

	s1 = src;
	s2 = dst;
	s3 = malloc(sizeof(char) * ft_strlen(s1));
	ft_strcpy(s3, s1);
	ft_strncpy(s2, s3, len);
	return (dst);
}
