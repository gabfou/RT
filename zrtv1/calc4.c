/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:43:14 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/10 01:43:16 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline t_color			t_color_add(t_color c1, t_color c2)
{
	int	r;
	int	g;
	int	b;

	r = c1.r + c2.r;
	g = c1.g + c2.g;
	b = c1.b + c2.b;
	return(new_t_color(r, g, b));
}

inline t_color			t_color_mult(t_color c1, FLOAT_SIZE i)
{
	return(new_t_color(c1.r * i, c1.g * i, c1.b * i));
}
