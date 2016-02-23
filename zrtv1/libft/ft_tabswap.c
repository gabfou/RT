/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:30:04 by jromagna          #+#    #+#             */
/*   Updated: 2014/12/12 18:50:24 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabswap(char **tab, int i, int j)
{
	char	*dup;

	dup = ft_strdup(tab[j]);
	tab[j] = ft_strdup(tab[i]);
	tab[i] = ft_strdup(dup);
	return (tab);
}
