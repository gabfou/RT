/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:15:15 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/07 15:29:09 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++len;
		while (*s && *s != c)
			++s;
		if (*s)
			++s;
	}
	return (len);
}

static size_t	word_length(const char *s, char c)
{
	const char	*is;

	is = s;
	while (*is && *is != c)
		++is;
	return (is - s);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t		word_len;
	char		**splitted;
	char		**isplitted;

	if (!s)
		return (0);
	splitted = (char**)malloc(sizeof(char*) * (word_count(s, c) + 1));
	if (splitted)
	{
		isplitted = splitted;
		while (*s)
		{
			word_len = word_length(s, c);
			if (word_len)
			{
				*isplitted++ = ft_strsub(s, 0, word_len);
				s += word_len;
			}
			if (*s)
				++s;
		}
		*isplitted = 0;
	}
	return (splitted);
}
