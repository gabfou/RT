/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:24:39 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:45:53 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isblanc(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static	int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;

	if (!s)
		return (0);
	i = 0;
	while (ft_isblanc(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len && ft_isspace(s[len]))
		len--;
	if (len < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - (size_t)i + 1));
}
