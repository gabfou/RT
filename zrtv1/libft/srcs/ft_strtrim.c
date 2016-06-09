/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:15:15 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/30 19:52:23 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	size_t	size;

	if (!s)
		return (0);
	while (*s && is_whitespace(*s))
		++s;
	if (!*s)
		return (ft_strnew(0));
	size = ft_strlen(s);
	while (is_whitespace(s[size - 1]))
		--size;
	return (ft_strsub(s, 0, size));
}
