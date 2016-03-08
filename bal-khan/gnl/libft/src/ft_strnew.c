/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:39:02 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:21:05 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*latent;
	int		a;

	a = -1;
	latent = (char*)malloc(sizeof(char) * (size + 1));
	if (latent == NULL)
		return (NULL);
	while ((size_t)++a <= size)
	{
		*(latent + a) = '\0';
	}
	*(latent + a) = '\0';
	return (latent);
}
