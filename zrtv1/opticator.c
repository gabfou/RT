/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opticator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 00:28:29 by gfournie          #+#    #+#             */
/*   Updated: 2016/02/23 00:28:37 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "le.h"

inline t_v	miroiratorvcalculator(t_v ray, t_v norm)
{

	return (normalisator(vav(norm, normalisator(vav(ray, norm)))));
}


void	miroir();
{
	e->c.x = 0;
	e->c.y = 0;
	e->c.z = 0;
	e->pl.x += -e->vl.x * 1.0;
	e->pl.y += -e->vl.y * 1.0;
	e->pl.z += -e->vl.z * 1.0;
	e->d = 0xf0000;
	e->pixelmirror = 0;
	return (testall(1, e->pl, e, ps(e->vl, -1)/*miroiratorvcalculator(dir, ps(e->vl, -1))*/));
}