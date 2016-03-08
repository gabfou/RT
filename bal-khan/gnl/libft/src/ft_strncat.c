/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:21:00 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 07:56:45 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	int a;
	int b;

	a = 0;
	b = -1;
	while (*(s1 + a) != '\0')
		a++;
	while ((size_t)++b < n && *(s2 + b) != '\0')
	{
		*(s1 + a) = *(s2 + b);
		a++;
	}
	*(s1 + a) = '\0';
	return (s1);
}
