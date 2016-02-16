/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:13:06 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/09 19:20:13 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
