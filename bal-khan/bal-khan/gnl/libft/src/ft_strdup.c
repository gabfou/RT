/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:30:26 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/12 08:43:55 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*latent;

	a = 0;
	latent = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (latent == NULL)
	{
		return (NULL);
	}
	else
	{
		while (*(s1 + a) != '\0')
		{
			*(latent + a) = *(s1 + a);
			a++;
		}
		*(latent + a) = '\0';
		return (latent);
	}
	return (NULL);
}
