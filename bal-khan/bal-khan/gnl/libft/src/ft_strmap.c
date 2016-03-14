/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:40:05 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:12:29 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*latent;
	int		a;

	if (s == NULL || f == NULL)
		return (0);
	latent = (char*)malloc(sizeof(s));
	a = 0;
	while (*(s + a) != '\0')
	{
		*(latent + a) = f(*(s + a));
		a++;
	}
	*(latent + a) = '\0';
	return (latent);
}
