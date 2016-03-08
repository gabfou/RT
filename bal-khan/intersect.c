/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:40:47 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:40:49 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline t_vect3d	inter_plane_point(t_list *plane, t_ray ray)
{
	t_vect3d	a;
	double		b;
	double		c;
	t_vect3d	ret;

	a = vector_sub(plane->center, ray.origin);
	b = dot_product(a, plane->orient);
	c = dot_product(ray.direct, plane->orient);
	if (!c)
	{
		ret.inter = 0;
		return (ret);
	}
	ret.t = b / c;
	if (ret.t < 0.000000001)
	{
		ret.inter = 0;
		return (ret);
	}
	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;
	ret.inter = 1;
	return (ret);
}

inline t_vect3d	inter_sphere_point(t_list *sphere, t_ray ray, t_env *e)
{
	double		a;
	double		b;
	double		c;
	t_vect3d	ret;
	double		delta;

	e->dist = vector_sub(ray.origin, sphere->center);
	a = dot_product(ray.direct, ray.direct);
	b = 2.0 * dot_product(ray.direct, e->dist);
	c = dot_product(e->dist, e->dist) - 2.0\
	* (sphere->radiangle * sphere->radiangle);
	delta = b * b - 4.0 * (a * c);
	ret.t = (((-b + sqrt(delta)) / (2.0 * a)) >\
	((-b - sqrt(delta)) / (2.0 * a)))
	? ((-b - sqrt(delta)) / (2.0 * a)) : ((-b + sqrt(delta)) / (2.0 * a));
	ret.inter = (!(delta < 0 || ret.t <= 0));
	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;
	return (ret);
}

inline t_vect3d	inter_cylinder_point(t_list *cylinder, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_vect3d	ret;

	a = dot_product(ray.direct, ray.direct) - (dot_product(ray.direct,\
		cylinder->orient) * dot_product(ray.direct, cylinder->orient));
	b = dot_product(ray.direct, vector_sub(ray.origin, cylinder->center)) -\
	(dot_product(ray.direct, cylinder->orient) * dot_product(vector_sub(\
		ray.origin, cylinder->center), cylinder->orient));
	b = 2.0 * b;
	c = dot_product(vector_sub(ray.origin, cylinder->center), vector_sub(\
	ray.origin, cylinder->center)) - (dot_product(vector_sub(ray.origin,\
	cylinder->center), cylinder->orient) * dot_product(vector_sub(ray.origin,\
	cylinder->center), cylinder->orient));
	c = c - cylinder->radiangle * cylinder->radiangle;
	d = b * b - (4.0 * a * c);
	ret.t = (((-b + sqrt(d)) / (2.0 * a)) > ((-b - sqrt(d)) / (2.0 * a)))
	? ((-b - sqrt(d)) / (2.0 * a)) : ((-b + sqrt(d)) / (2.0 * a));
	ret.inter = (!(d < 0 || ret.t <= 0));
	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;
	return (ret);
}

inline t_vect3d	inter_cone_point(t_list *cy, t_ray ray)
{
	t_vect3d	ret;
	double		a;
	double		b;
	double		c;
	double		d;

	a = dot_product(ray.direct, ray.direct) - (1.0 + tan(cy->radiangle) * tan(\
	cy->radiangle)) * (dot_product(ray.direct, cy->orient) * dot_product(\
	ray.direct, cy->orient));
	b = dot_product(ray.direct, vector_sub(ray.origin, cy->center)) - (1.0 +\
	tan(cy->radiangle) * tan(cy->radiangle)) * (dot_product(ray.direct,\
	cy->orient) * dot_product(vector_sub(ray.origin, cy->center), cy->orient));
	b = 2.0 * b;
	c = dot_product(vector_sub(ray.origin, cy->center), vector_sub(ray.origin,\
	cy->center)) - (1.0 + tan(cy->radiangle) * tan(cy->radiangle)) * (\
	dot_product(vector_sub(ray.origin, cy->center), cy->orient) * dot_product(\
	vector_sub(ray.origin, cy->center), cy->orient));
	d = b * b - (4.0 * a * c);
	ret.t = (((-b + sqrt(d)) / (2.0 * a)) > ((-b - sqrt(d)) / (2.0 * a)))
	? ((-b - sqrt(d)) / (2.0 * a)) : ((-b + sqrt(d)) / (2.0 * a));
	ret.inter = (!(d < 0 || ret.t <= 0));
	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;
	return (ret);
}
#include <stdio.h>
	inline t_vect3d	inter_spine_in_brine(t_torus *torus, t_ray ray)
{
torus->axis = normalizator(torus->axis);
t_vect3d	ret;
double a, b, c, d, e;

double	m, n, o, p, q;

m = dot_product(ray.direct, ray.direct);
n = dot_product(ray.direct, normalizator(vector_sub(ray.origin, torus->center)));
o = dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center)));
p = dot_product(ray.direct, torus->axis);
q = dot_product(normalizator(vector_sub(ray.origin, torus->center)), torus->axis);

// printf("m = %lf, n = %lf, o = %lf, p = %lf, q = %lf\n", m, n, o, p, q);

// a = pow(m, 2);

// b = 4.0 * m * n;

// c = 4.0 * pow(m, 2) + 2.0 * m * o - 2.0 * (pow(torus->torus_r, 2) + pow(torus->circl_r, 2)) * m + 4.0 * pow(torus->torus_r, 2) * pow(p, 2);

// d = 4.0 * n * o - 4.0 * (pow(torus->torus_r, 2) + pow(torus->circl_r, 2)) * n + 8.0 * pow(torus->torus_r, 2) * p * q;

// e = pow(o, 2) - 2.0 * (pow(torus->torus_r, 2) + pow(torus->circl_r, 2)) * o + 4.0 * pow(torus->torus_r, 2) * pow(q, 2) + pow((pow(torus->torus_r, 2) - pow(torus->circl_r, 2)), 2);

// printf("a = %lf, b = %lf, c = %lf, d = %lf, e = %lf\n", a, b, c, d, e);

// a = dot_product(ray.direct, ray.direct) * dot_product(ray.direct, ray.direct);

// b = 4.0 * dot_product(ray.direct, ray.direct) * dot_product(ray.direct, normalizator(vector_sub(ray.origin, torus->center)));

// c = 4.0 * dot_product(ray.direct, ray.direct) * dot_product(ray.direct, ray.direct) 
//   + 2.0 * dot_product(ray.direct, ray.direct) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) 
//   - 2.0 * (torus->torus_r * torus->torus_r + torus->circl_r * torus->circl_r) * dot_product(ray.direct, ray.direct) 
//   + 4.0 * torus->torus_r * torus->torus_r * dot_product(ray.direct, torus->axis) * dot_product(ray.direct, torus->axis);

// d = 4.0 * dot_product(ray.direct, normalizator(vector_sub(ray.origin, torus->center))) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center)))
//   - 4.0 * (torus->torus_r * torus->torus_r + torus->circl_r * torus->circl_r) * dot_product(ray.direct, normalizator(vector_sub(ray.origin, torus->center)))
//   + 8.0 * torus->torus_r * torus->torus_r * dot_product(ray.direct, torus->axis) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), torus->axis);

// e = dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) 
//   * dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) 
//   - 2.0 * (torus->torus_r * torus->torus_r + torus->circl_r * torus->circl_r) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) 
//   + 4.0 * (torus->torus_r * torus->torus_r) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), torus->axis) 
//   * dot_product(normalizator(vector_sub(ray.origin, torus->center)), torus->axis) 
//   + (torus->torus_r * torus->torus_r - torus->circl_r * torus->circl_r) * (torus->torus_r * torus->torus_r - torus->circl_r * torus->circl_r);

	double	root;

	a = pow(m, 2);

	b = 4.0 * m * dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct);

	c = 4.0 * pow(dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct), 2) + 2.0 * m * (dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->circl_r, 2) - pow(torus->torus_r, 2)) + 4.0 * pow(torus->torus_r, 2) * pow(dot_product(ray.direct, torus->axis), 2);

	d = 4.0 * dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct) * (dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->circl_r, 2) - pow(torus->torus_r, 2)) + 8.0 * pow(torus->torus_r, 2) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) * dot_product(ray.direct, torus->axis);

	e = pow((dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->circl_r, 2) - pow(torus->torus_r, 2)), 2) + 4.0 * pow(torus->torus_r, 2) * pow(ray.origin.z, 2) - 4.0 * pow(torus->torus_r, 2) * pow(torus->circl_r, 2);

	root = solve_quartic(a/a-b/4.0, b/a-b/4.0, c/a-b/4.0, d/a-b/4.0, e/a-b/4.0);
	ret.t = root;

	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;

if (root && ret.t > 0)
	ret.inter = 1;
else
	ret.inter = 0;
(void)ret;(void)ray;
	return (ret);
}

t_torus		torus_creator()
{
t_torus		torus;
torus.center.x = 0;//1;
torus.center.y = 0;//1500;
torus.center.z = 9999999990;//100000;//10000;//-7000;//-10;//10;//-900;
torus.axis.x = 10;//10;//10;//10;
torus.axis.y = -5;//10;//10;
torus.axis.z = 10;//10;//10;
torus.torus_r = 3.0;
torus.circl_r = 2.8;
return (torus);
}
