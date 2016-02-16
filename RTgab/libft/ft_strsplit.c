/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 23:08:47 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/12 23:34:45 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		ti;
	char	**tab;
	int		h;

	i = 0;
	ti = 0;
	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char *) * (ft_strlen(s) / 2));
	while (s[i])
	{
		h = 0;
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i + h] != c && s[i + h])
			h++;
		tab[ti] = ft_strsub(s, i, h);
		i = i + h;
		ti++;
	}
	tab[ti] = (NULL);
	return (tab);
}
