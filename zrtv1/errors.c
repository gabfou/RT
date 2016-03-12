/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:31:23 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/02/25 21:33:59 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	WRITE(STDERR, "\n");
	exit(0);
}
