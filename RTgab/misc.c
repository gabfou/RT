/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 19:14:45 by gfournie          #+#    #+#             */
/*   Updated: 2015/09/22 19:14:49 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

inline void		put_pixel(t_env *e, register int x, register int y, int color)
{
	register unsigned char	color1;
	register unsigned char	color2;
	register unsigned char	color3;
	register int			img_size;

	img_size = TV * TH * e->bpp / 8;
	if (x < 0 || y < 0 || y * e->sizel + x * e->bpp / 8 > img_size
	|| x >= e->sizel / (e->bpp / 8) || y >= img_size / e->sizel)
		return ;
	color1 = color >> 0;
	color2 = color >> 8;
	color3 = color >> 16;
	color1 += (e->c.z) * 255 / M_PI;
	color2 += (e->c.y) * 255 / M_PI;
	color3 += (e->c.x) * 255 / M_PI;
	e->addr[y * e->sizel + x * e->bpp / 8] = color1;
	e->addr[y * e->sizel + x * e->bpp / 8 + 1] = color2;
	e->addr[y * e->sizel + x * e->bpp / 8 + 2] = color3;
}

inline t_v		vpulcalculator(t_cam c)
{
	t_v	r;

	r.x = c.pos.x + ((c.dir.x * c.d) + (c.up.x * (c.h / 2))) - (c.right.x * (c.l / 2));
	r.y = c.pos.y + ((c.dir.y * c.d) + (c.up.y * (c.h / 2))) - (c.right.y * (c.l / 2));
	r.z = c.pos.z + ((c.dir.z * c.d) + (c.up.z * (c.h / 2))) - (c.right.z * (c.l / 2));
	return (r);
}

inline t_v		pixelpos(t_cam c, long double x, long double y, t_env *e)
{
	t_v	r;

	r.x = c.vpul.x + c.right.x * (c.l / TV) * x - c.up.x * (c.h / TH) * y;
	r.y = c.vpul.y + c.right.y * (c.l / TV) * x - c.up.y * (c.h / TH) * y;
	r.z = c.vpul.z + c.right.z * (c.l / TV) * x - c.up.z * (c.h / TH) * y;
	e->o.dir.x = r.x - c.pos.x + c.dir.x;
	e->o.dir.y = r.y - c.pos.y + c.dir.y;
	e->o.dir.z = r.z - c.pos.z + c.dir.z;
	e->o.dir = normalisator(e->o.dir);
	return (r);
}

inline t_v		normalisator(t_v v)
{
	register long double n;

	n = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (n == 0)
		error("vecteur nul");
	v.x /= n;
	v.y /= n;
	v.z /= n;
	return (v);
}

inline long double	ft_min(const register long double a, const register long double b)
{
	return (a < b ? a : b);
}

inline long double	normecalculator(t_v v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
