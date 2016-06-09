/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:15:15 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/07 15:27:57 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_atoi_ignored(char c)
{
	return (c == '\n'
			|| c == '\v'
			|| c == '\t'
			|| c == '\r'
			|| c == '\f'
			|| c == ' ');
}

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	int					is_neg;
	int					i;

	while (is_atoi_ignored(*str))
		++str;
	result = 0;
	is_neg = str && *str == '-';
	i = str && (*str == '-' || *str == '+');
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (is_neg)
		return (-result);
	return (result);
}
