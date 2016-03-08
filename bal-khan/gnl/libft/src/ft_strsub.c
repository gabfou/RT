/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:26:32 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 04:32:22 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (len == 0)
	{
		ret = ft_strnew(1);
		*ret = '\0';
		return (ret);
	}
	if (!s || !len || (int)len < 0)
		return (0);
	ret = ft_strnew(len + 1);
	ret = ft_strncpy(ret, (s + start), len);
	return (ret);
}
