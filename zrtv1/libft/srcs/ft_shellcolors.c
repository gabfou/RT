/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellcolors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:23:12 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/06 05:25:22 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	setcolor(t_uchar color, const char *type)
{
	char	*color_str;

	color_str = ft_itoa(color);
	ft_putstr("\033[");
	ft_putstr(type);
	ft_putchar(';');
	ft_putstr(color_str);
	ft_putchar('m');
	free(color_str);
}

void		ft_setfgcolor(t_uchar color)
{
	setcolor(color, FG_COLOR_TYPE);
}

void		ft_setbgcolor(t_uchar color)
{
	setcolor(color, BG_COLOR_TYPE);
}

void		ft_resetcolor(void)
{
	ft_putstr("\033[0m");
}
