/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:29:22 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:48:56 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*tmp;

	tmp = ft_memalloc(n);
	tmp = ft_memcpy(tmp, src, n);
	dst = ft_memcpy(dst, tmp, n);
	return (dst);
}
