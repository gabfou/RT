/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:12:52 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/06 05:25:23 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_uchar	*ib;
	t_uchar	cc;

	cc = (t_uchar)c;
	ib = (t_uchar *)b;
	while (len--)
		ib[len] = cc;
	return (b);
}
