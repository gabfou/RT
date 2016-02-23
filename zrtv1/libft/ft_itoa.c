/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:46:33 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/12 19:55:33 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getlen(int i)
{
	int		h;

	if (i == 0)
		return (1);
	h = 0;
	if (i < 0)
	{
		i = -i;
		h++;
	}
	while (i != 0)
	{
		i = i / 10;
		h++;
	}
	return (h);
}

char			*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = getlen(n);
	if ((s = ft_strnew(i)) == NULL)
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		i--;
		s[i] = n % 10 + '0';
		n = n / 10;
	}
	if (s[0] == '\0')
		s[0] = '-';
	return (s);
}
