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

long double ifpos(long double x)
{
	return ((x > 0) ? x : -x);

}

inline int		lumierator(t_l *l, t_env *e, t_v v, t_v p)
{
	t_v						vl;
	register double long	tmp;
	register double long	tmp2;
	t_v						l2;

	if (!l)
		return (0);
	(void)tmp;
	vl.x = p.x - l->x;
	vl.y = p.y - l->y;
	vl.z = p.z - l->z;
	tmp2 = vl.x * vl.x + vl.y * vl.y + vl.z * vl.z;
	vl = normalisator(vl);
	l2.x = l->x;
	l2.y = l->y;
	l2.z = l->z;
	e->test2 = 0;
	tmp = testall(0, l2, e, vl);
//	e->test2 = 1;
	if (!(tmp * tmp < tmp2 - 0.000001))
	{
		e->r += ifpos(M_PI_2 - acos(v.x * vl.x + v.y * vl.y + v.z * vl.z)) / e->l * l->color.x * 2;
		e->g += ifpos(M_PI_2 - acos(v.x * vl.x + v.y * vl.y + v.z * vl.z)) / e->l * l->color.y * 2;
		e->b += ifpos(M_PI_2 - acos(v.x * vl.x + v.y * vl.y + v.z * vl.z)) / e->l * l->color.z * 2;
	}
	return (1);
}

t_p	planenrecuperatorormator()
{
	t_p p;

	p.p.x = 0;
	p.p.y = 0;
	p.p.z = 2.2;
	p.v.x = 0;
	p.v.y = 0;
	p.v.z = 1;
	p.v = normalisator(p.v);
	return (p);
}

void	rayonator(t_env *e, int x, int y)
{
	t_v		i;

	(void)i;
	e->r = 0;
	e->g = 0;
	e->b = 0;
	e->r3 = 0;
	e->g3 = 0;
	e->b3 = 0;
	e->d = 0xf0000;
	testall(1, pixelpos(e->o, x, y, e), e, e->o.dir);
	e->r *= e->r2;
	e->g *= e->g2;
	e->b *= e->b2;
	put_pixel(e, x, y, 0x000000);
}

void	panoramiquator(t_env *e)
{
	register int	i;
	register int	j;

	i = -1;
	while (++i < TH)
	{
		j = -1;
		while (++j < TV)
			rayonator(e, j, i);
	}
	ft_putendl("100%");
}
