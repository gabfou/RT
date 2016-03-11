/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 05:25:54 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/16 05:26:26 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_umin(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
