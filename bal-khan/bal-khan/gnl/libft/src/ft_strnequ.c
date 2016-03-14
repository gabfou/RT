/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:40:33 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:14:57 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int a;

	a = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*(s1 + a) != '\0' && *(s2 + a) != '\0' && (size_t)a < n)
	{
		if (*(s1 + a) == *(s2 + a))
			a++;
		else
			return (0);
	}
	if (*(s1 + a) == '\0' && *(s2 + a) == '\0')
		return (1);
	else if ((size_t)a >= n && *(s1 + a - 1) == *(s2 + a - 1))
		return (1);
	else
		return (0);
}
