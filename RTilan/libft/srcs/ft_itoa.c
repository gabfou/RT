/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:35:04 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/21 20:21:27 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	ln;
	int			len;
	long int	p10;
	char		*str;
	char		*istr;

	ln = n;
	len = 1;
	p10 = 1;
	while (n / (p10 *= 10))
		++len;
	str = (char*)malloc(sizeof(char) * (len + (n < 0) + 1));
	if (str)
	{
		istr = str;
		if (n < 0)
			*istr++ = '-';
		while ((p10 /= 10) > 0)
			*istr++ = '0' + ABS(ln / p10) % 10;
		*istr = '\0';
	}
	return (str);
}
