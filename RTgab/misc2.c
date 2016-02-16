/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 20:50:57 by gfournie          #+#    #+#             */
/*   Updated: 2015/10/05 20:51:01 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

static int	ft_strlen2(const char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

static char	*init(long int *a, int *b, const char *str)
{
	*a = 0;
	*b = 1;
	while ((*str == ' ') || (*str == '\n')
		|| (*str == '\t') || (*str == '\v')
		|| (*str == '\r') || (*str == '\f'))
		str++;
	return ((char*)str);
}

int			ft_atoi2(const char *str)
{
	long int	res;
	int			sign;

	if (str == NULL || ft_strlen2(str) > 11)
		return (-1);
	str = init(&res, &sign, str);
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while ((str)[0] != '\0' && (str)[0] != ' ')
	{
		if (str[0] >= '0' && str[0] <= '9')
			res = res * 10 + str[0] - '0';
		else
			return (-1);
		str++;
	}
	if (res > 2147483647)
		return (-1);
	return (sign * res);
}

void		error(char *s)
{
	ft_putendl(s);
	exit(0);
}

t_v			perpendiculator(t_v v)
{
	t_v r;

	r.x = 0;
	r.y = v.z;
	r.z = v.y;
	return (normalisator(v));
}
