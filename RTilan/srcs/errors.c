/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:08:51 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/06 21:26:05 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fatal_error(const char *name, const char *error, const char *info)
{
	ft_putstr_fd(name, STDERR);
	WRITE(STDERR, ERR_SEPARATOR);
	ft_putstr_fd(error, STDERR);
	if (info)
	{
		WRITE(STDERR, ERR_SEPARATOR);
		ft_putstr_fd(info, STDERR);
	}
	ft_putchar_fd('\n', STDERR);
	exit(0);
}
