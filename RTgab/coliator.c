/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coliator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 22:49:23 by gfournie          #+#    #+#             */
/*   Updated: 2015/10/02 22:49:24 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

// (x2 + y2 + z2 + R2 - r2)(x2 + y2 + z2 + R2 - r2) - 4 * R2 * (x2 + y2) = 0
// (x4 + y4 + z4 + R4 + r4 + 2y2x2 + 2x2z2 + 2x2R2 - 2x2r2 + 2y2z2 + 2y2R2 - 2y2r2 + 2z2R2 - 2z2r2 - 2R2r2) - 4R2x2  4R2y2 = 0
//
//
//

inline long double	planetestor(t_v v, t_env *e, t_v dir, t_p *p)
{
	register long double	d;
	t_v						l;
	t_v						t;

	if (p == NULL)
		return (-2);
	d = -((p->v.x * (v.x - p->p.x) + p->v.y * (v.y - p->p.y) + p->v.z * (v.z - p->p.z)) /
		(p->v.x * dir.x + p->v.y * dir.y + p->v.z * dir.z));
	if (d < 0 || d > e->d)
		return (-1);
	e->d = d;
	if (!e->testor)
		return (d);
	l = vav(v, ps(dir, d));
	e->c2 = p->color;
	t.x = p->v.x;
	t.y = p->v.y;
	t.z = p->v.z;
	e->test3 = 0;
	e->pixelmirror = 0;
	e->vl = t;
	// printf("%Lf\n", e->vl.z);
	e->pl = l;
	return (d);
}

inline long double	spheretestor(t_v v, t_env *e, t_v dir, t_s *s)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	t_v						l;

	if (s == NULL)
		return (-2);
	l = vsv(v, s->p);
	a = vm(dir, dir);
	b = 2 * vm(dir, l);
	c = (vm(l, l) - s->r * s->r);
	if ((c = (b * b - 4.0 * a * c)) < 0)
		return (-1);
	c = ft_min(((-b + sqrt(c)) / (2 * a)), ((-b - sqrt(c)) / (2 * a)));
	if (c < 0 || c > e->d)
		return (-1);
	e->d = c;
	if (!e->testor)
		return (c);
	l = vav(v, ps(dir, c));
	v = vdc(vsv(s->p, l), s->r);
	e->pixelmirror = 0;
	e->vl = v;
	e->pl = l;
	e->c2 = s->color;
	return (c);
}

//ax + y
//po + ud -p1 - ((po * p3 + ud * p3 - p1 * p3) / (p3 * p3)) * p3 - r * r = 0

t_v tvb(t_v i, t_v dir, t_v pos, long double r)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	register long double	d;
	t_v						l;

	a = vm(dir, dir);;
	b = 2 * vm(dir, vsv(pos, i));
	c = vm(vsv(pos, i), vsv(pos, i)) - r * r;
	if ((d = (b * b - 4.0 * a * c)) >= 0)
	{
		d = ft_min(((-b + sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));
		l = vav(pos, ps(dir, d));
		return (l);
	}
	ft_putendl("tvb fail");
	// exit (-1);
	return (l);
}

 t_v		vector_proj_vector(t_v vector1, t_v vector2) // project vector 1 in vector 2
{
	t_v	ret;

	ret = ps(vector2, vm(vector1, vector2) / vm(vector2, vector2));
	return (ret);	
}

// ((px + vxt) * dx + (py + vyt) * dy + (pz + vzt) * dz) * ((px + vxt) * dx + (py + vyt) * dy + (pz + vzt) * dz) - (dx2 + dy2 + dz2) * ((px + vxt)2 + (py + vyt)2 + (pz + vzt)2) * 0//cos(truc)2

// ((px + vxt) * dx + (py + vyt) * dy + (pz + vzt) * dz) * ((px + vxt) * dx + (py + vyt) * dy + (pz + vzt) * dz)

// (pxdx + dxvxt + pydy + dyvyt + pzdz + dzvzt) * (pxdx + dxvxt + pydy + dyvyt + pzdz + dzvzt)


//- (dx2 + dy2 + dz2) * ((px + vxt)2 + (py + vyt)2 + (pz + vzt)2) * cos(a)2

//-dx2 * (px2 + 2pxvxt + vx2t2) - dy2 * (px2 + 2pxvxt + vx2t2) - dz2 * (px2 + 2pxvxt + vx2t2)) * cos(a)2
//-dx2 * (py2 + 2pyvyt + vy2t2) - dy2 * (py2 + 2pyvyt + vy2t2) - dz2 * (py2 + 2pyvyt + vy2t2)) * cos(a)2
//-dx2 * (pz2 + 2pzvzt + vz2t2) - dy2 * (pz2 + 2pzvzt + vz2t2) - dz2 * (pz2 + 2pzvzt + vz2t2)) * cos(a)2

// a = dx2vx2 + dy2vy2 + dz2vz2 + 2 * (dxvxdyvy + dxvxvzdz + dyvyvzdz) - cos(a)2 * (dx2vx2 + dy2vy2 + dz2vz2 + dx2vy2 + dx2vz2 + dy2vx2 + dy2vz2 + dz2vx2 + dz2vy2)
// b = 2 * (pxdx2vx + pydy2vy + pzdz2vz + pxdxvydy + pxdxvzdz + pydyvxdx + pydyvzdz + pzdzvxdx + pzvzvydy) - 2 * cos(a) * (dx2pxvx + dy2pyvy + dzpzvz + dx2pyvy + dx2pzvz + dy2pxvx + dy2pzvz + dz2pxvx + dz2pyvy)
// c = dx2px2 + dy2py2 + dz2pz2 + 2 * (dxpxdypy + dxpxpzdz + dypypzdz) - cos(a)2 * (dx2px2 + dy2py2 + dz2pz2 + dx2py2 + dx2pz2 + dy2px2 + dy2pz2 + dz2px2 + dz2py2)

//(x + vxt)

// racine(((x + vxt) − xA)2 + ((y + vyt) − yA)2 + ((z + vzt) − zA)2)

	// a = vm(vmv(s->v, dir), vmv(s->v, dir))
	// 	+ 2 * vwaza(vmv(s->v, dir), vmv(s->v, dir))
	// 	- pow(cos(s->a), 2) * (vm(vmv(s->v, s->v), vmv(dir, dir))
	// 	+ svwaza(vmv(dir, dir), vmv(s->v, s->v)));
	// b = 2 * (vm(vmv(dir, s->v), vmv(l, s->v))
	// 	+ svwaza(vmv(l, s->v), vmv(dir, s->v)))
	// 	- pow(cos(s->a), 2) * 2 * (vm(vmv(s->v, s->v), vmv(l, dir))
	// 	+ svwaza(vmv(s->v, s->v), vmv(l, dir)));
	// c = vm(vmv(s->v, l), vmv(s->v, l))
	// 	+ 2 * vwaza(vmv(s->v, l), vmv(s->v, l))
	// 	- pow(cos(s->a), 2) * (vm(vmv(s->v, s->v), vmv(l, l))
	// 	+ svwaza(vmv(l, l), vmv(s->v, s->v)));

inline long double	cotestor(t_v v, t_env *e, t_v dir, t_co *s)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	register long double	d;
	t_v						l;

	if (s == NULL)
		return (-2);
	l = vsv(v, s->p);
	a = vm(dir, dir) - (1.0 + tan(s->a) * tan(s->a)) * (vm(dir, s->v) *  vm(dir, s->v));
	b = 2 * (vm(dir, l) - (1.0 + tan(s->a) * tan(s->a)) * (vm(dir, s->v) * vm(l, s->v)));
	c = vm(l, l) - (1.0 + tan(s->a) * tan(s->a)) * (vm(l, s->v) * vm(l, s->v));
	if ((d = (b * b - 4.0 * a * c)) < 0)
		return (-1);
	d = ft_min(((-b + sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));
	if (d < 0 || d > e->d)
		return (-1);
	l = vav(v, ps(dir, d));
	if (s->h != -1 && normecalculator(vsv(l, s->p)) > s->h)
		return (-1);
	e->d = d;
	if (!e->testor)
		return (d);
	e->pixelmirror = 0;
	e->vl = normalisator(vsv(vector_proj_vector(normalisator(vsv(s->p, l)), s->v), normalisator(vsv(s->p, l))));
	e->pl = l;
	e->c2 = s->color;
	return (d);
}

// a = vdp(vmv(dir, dir))
// 	- vdp(vmv(vmv(s->v, s->v), vmv(dir, dir))) / vdp(vmv(s->v, s->v))
// 	- 2 * vwaza(vmv(s->v, dir), vmv(s->v, dir)) / vdp(vmv(s->v, s->v));
// b = 2 * (vm(dir, l)) - 2 * (vm(vmv(s->v, s->v), vmv(l, dir))
// 	+ svwaza(vmv(s->v, l), vmv(s->v, dir))) / d;
// c = (vm(l, l) - s->r * s->r) - (vm(vmv(s->v, s->v), vmv(l, l))
// 	+ 2 * (vwaza(vmv(s->v, l), vmv(s->v, l)))) / d;

inline long double	cytestor(t_v v, t_env *e, t_v dir, t_cy *s)
{
	register long double	a;
	register long double	b;
	register long double 	c;
	register long double	d;
	t_v						l;
	t_v						z;
	double dist;

	if (s == NULL)
		return (-2);
	d = vm(s->v, s->v);
	l = vsv(v, s->p);
	a = vm(dir, dir) - (vm(dir, s->v) *  vm(dir, s->v));
	b = 2 * (vm(dir, l) - (vm(dir, s->v) * vm(l, s->v)));
	c = vm(l, l) - (vm(l, s->v) * vm(l, s->v)) - s->r * s->r;
	if ((d = (b * b - 4.0 * a * c)) < 0)
		return (-1);
	d = ft_min(((-b + sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));
	if (d < 0 || d > e->d)
		return (-1);
	l = vav(v, ps(dir, d));
	if (s->h != -1 && normecalculator(vsv(l, s->p)) > s->h)
		return (-1);
	e->d = d;
	if (!e->testor)
		return(d);
	// z = tvb(l, s->v, s->p, s->r + 0.00001);
	// v = vsv(z, l);
	// v = normalisator(v);
	// v = normalisator(vsv((vsv(ps(dir, e->d), s->p)),
	// 	(ps(s->v, vm(dir, s->v) * e->d + vm(vsv(v, s->p), s->v)))));
	a = normecalculator(vsv(s->p, l));
	dist = sqrt(pow(a, 2) - pow(s->r, 2));
	z = vav(s->p, ps(s->v, dist));
	v = vsv(z, l);
	if (!((a = normecalculator(v)) > s->r - 0.00000001 && a < s->r + 0.00000001))
	{
		z = vav(s->p, ps(s->v, -dist));
		v = vsv(z, l);
	}
	v = normalisator(v);
	e->pixelmirror = 0;
	e->vl = v;
	e->pl = l;
	e->c2 = s->color;
	return (d);
}

inline long double	testall(register int i, t_v p, t_env *e, t_v dir)
{
	register int			j;
	register long double	tmp;

	e->testor = i;
	j = 1;
	e->d = 0xf0000;
	while ((tmp = spheretestor(p, e, dir, sphereguardator(NULL, j))) != -2)
		j++;
	j = 1;
	while ((tmp = planetestor(p, e, dir, planeguardator(NULL, j))) != -2)
		j++;
	j = 1;
	while ((tmp = cytestor(p, e, dir, cyguardator(NULL, j))) != -2)
		j++;
	j = 1;
	while ((tmp = cotestor(p, e, dir, coguardator(NULL, j))) != -2)
		j++;
	if (e->d < 0xf0000 && e->pixelmirror == 1 && e->testor == 1)
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
	if (e->d < 0xf0000 && e->testor)
	{
		e->testor = 0;
		j = 1;
		while (lumierator(lightguardator(NULL, j), e, e->vl, e->pl))
			j++;
 	}
	return (e->d);
}
