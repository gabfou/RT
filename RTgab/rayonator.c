/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayonator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 19:32:48 by gfournie          #+#    #+#             */
/*   Updated: 2015/09/22 19:32:57 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

inline t_v	vdc(t_v a, long double b)
{
	t_v v;

	v.x = a.x / b;
	v.y = a.y / b;
	v.z = a.z / b;
	return (v);
}

long double	ifpos(long double x, int i)
{
	if (i)
		return ((x > 0) ? x : -x);
	return ((x > 0) ? x : -x);
}

inline int		lumierator(t_l *l, t_env *e, t_v v, t_v p)
{
	t_v						vl;
	register double long	tmp;
	register double long	tmp2;
	t_v						l2;

	if (!l)
	{
		e->test3 = 1;
		return (0);
	}
	vl = vsv(p, l->p);
	tmp2 = vl.x * vl.x + vl.y * vl.y + vl.z * vl.z;
	vl = normalisator(vl);
	l2 = l->p;
	e->test3 = 0;
	tmp = testall(0, l2, e, vl);
	// tmp = e->d;
//	e->test2 = 1;
	if (!(tmp * tmp < tmp2 - 0.000001))
	{
		e->c.x += ifpos(M_PI_2 - acos(v.x * vl.x + v.y * vl.y + v.z * vl.z), e->test3) / e->l * l->color.x * 2;
		e->c.y += ifpos(M_PI_2 - acos(v.x * vl.x + v.y * vl.y + v.z * vl.z), e->test3) / e->l * l->color.y * 2;
		e->c.z += ifpos(M_PI_2 - acos(v.x * vl.x + v.y * vl.y + v.z * vl.z), e->test3) / e->l * l->color.z * 2;
	}
	e->test3 = 1;
	return (1);
}

void	rayonator(t_env *e, int x, int y)
{
	e->c.x = 0;
	e->c.y = 0;
	e->c.z = 0;
	e->d = 0xf0000;
	testall(1, pixelpos(e->o, x, y, e), e, e->o.dir);
	e->c.x *= e->c2.x;
	e->c.y *= e->c2.y;
	e->c.z *= e->c2.z;
	put_pixel(e, x, y, 0x000000);
}

void	panoramiquator(t_env *e)
{
	register int	i;
	register int	j;
	register int	k;
	register int	l;

	k = 1;
	i = -1;
	l = 0;
	while (++i < TH)
	{
		j = -1;
		while (++j < TV)
		{
			rayonator(e, j, i);
			loadator(TH, TV, e, l++);
		}
	}
	// exit(0);
	ft_putendl("100%");
}
