/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 05:10:41 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/16 05:12:25 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_umax(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
