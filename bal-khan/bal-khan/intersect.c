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

// double	m, n, o, p, q;
// 
// m = dot_product(ray.direct, ray.direct);
// n = dot_product(ray.direct, (vector_sub(ray.origin, torus->center)));
// o = dot_product((vector_sub(ray.origin, torus->center)), (vector_sub(ray.origin, torus->center)));
// p = dot_product(ray.direct, torus->axis);
// q = dot_product((vector_sub(ray.origin, torus->center)), torus->axis);

// printf("m = %lf, n = %lf, o = %lf, p = %lf, q = %lf\n", m, n, o, p, q);

	// double	k1;
	// k1 = dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->torus_r, 2) - pow(torus->circl_r, 2);
	// double	k2;
	// k2 = dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct);

	// a = pow(m, 2);

	// b = 4.0 * m * n;

	// c = 4.0 * pow(m, 2) + 2.0 * m * o - 2.0 * (pow(torus->torus_r, 2) + pow(torus->circl_r, 2)) * m + 4.0 * pow(torus->torus_r, 2) * pow(p, 2);

	// d = 4.0 * n * o - 4.0 * (pow(torus->torus_r, 2) + pow(torus->circl_r, 2)) * n + 8.0 * pow(torus->torus_r, 2) * p * q;

	// e = pow(o, 2) - 2.0 * (pow(torus->torus_r, 2) + pow(torus->circl_r, 2)) * o + 4.0 * pow(torus->torus_r, 2) * pow(q, 2) + pow((pow(torus->torus_r, 2) - pow(torus->circl_r, 2)), 2);

// printf("a = %lf, b = %lf, c = %lf, d = %lf, e = %lf\n", a, b, c, d, e);

	double	root;

	// a = pow(m, 2);

	// b = 4.0 * m * dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct);

	// c = 4.0 * pow(dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct), 2) + 2.0 * m * (dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->circl_r, 2) - pow(torus->torus_r, 2)) + 4.0 * pow(torus->torus_r, 2) * pow(dot_product(ray.direct, torus->axis), 2);

	// d = 4.0 * dot_product(normalizator(vector_sub(ray.origin, torus->center)), ray.direct) * (dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->circl_r, 2) - pow(torus->torus_r, 2)) + 8.0 * pow(torus->torus_r, 2) * dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) * dot_product(ray.direct, torus->axis);

	// e = pow((dot_product(normalizator(vector_sub(ray.origin, torus->center)), normalizator(vector_sub(ray.origin, torus->center))) - pow(torus->circl_r, 2) - pow(torus->torus_r, 2)), 2) + 4.0 * pow(torus->torus_r, 2) * pow(ray.origin.z, 2) - 4.0 * pow(torus->torus_r, 2) * pow(torus->circl_r, 2);

// http://stackoverflow.com/questions/31100965/numerical-bug-in-intersecting-the-equation-of-ray-and-torus-when-the-camera-is-f
  // double a4 = sqr(dot(Dir, Dir));
  // double a3 = 4 * dot(Dir, Dir) * dot(O, Dir);
  // double a2 = 4 * sqr(dot(O, Dir)) + 2 * dot(Dir, Dir) * (dot(O, O) - r2 - R2) + 4 * R2 * sqr(Dir.z);
  // double a1 = 4 * dot(O, Dir) * (dot(O, O) - r2 - R2) + 8 * R2 * O.z * Dir.z;
  // double a0 = sqr(dot(O, O) - r2 - R2) + 4 * R2 * sqr(O.z) - 4 * R2 * r2;

	// b = 4.0 * m * n;

	// c = 4.0 * pow(n, 2) + 2.0 * m * (o - pow(torus->torus_r, 2) - pow(torus->circl_r, 2)) + 4.0 * pow(torus->torus_r, 2) * pow(ray.direct.z, 2);

	// d = 4.0 * n * (o - pow(torus->torus_r, 2) - pow(torus->circl_r, 2)) + 8.0 * pow(torus->torus_r, 2) * normalizator(vector_sub(ray.origin, torus->center)).z * ray.direct.z;

	// e = pow((o - pow(torus->torus_r, 2) - pow(torus->circl_r, 2)), 2) + 4.0 * pow(torus->torus_r, 2) * pow(normalizator(vector_sub(ray.origin, torus->center)).z, 2) - 4.0 * pow(torus->torus_r, 2) * pow(torus->circl_r, 2);

	t_vect3d	Q;
	Q = vector_sub(ray.origin, torus->center);
	double		u;
	double		v;
	u = dot_product(torus->axis, Q);
	v = dot_product(torus->axis, ray.direct);

t_list cyl;
cyl.type = 'c';
cyl.center.x = 0;
cyl.center.y = 0;
cyl.center.z = 0;
cyl.radiangle = 300;
cyl.orient.x = 10;
cyl.orient.y = 0;
cyl.orient.z = 1;
cyl.orient = normalizator(cyl.orient);
t_list	*cylinder;
cylinder = &cyl;

	double	axa;(void)axa;
	double	axb;(void)axb;
	double	axc;(void)axc;
	axa = dot_product(ray.direct, ray.direct) - (dot_product(ray.direct,\
		cylinder->orient) * dot_product(ray.direct, cylinder->orient));
	axb = dot_product(ray.direct, vector_sub(ray.origin, cylinder->center)) -\
	(dot_product(ray.direct, cylinder->orient) * dot_product(vector_sub(\
		ray.origin, cylinder->center), cylinder->orient));
	axb = 2.0 * axb;
	axc = dot_product(vector_sub(ray.origin, cylinder->center), vector_sub(\
	ray.origin, cylinder->center)) - (dot_product(vector_sub(ray.origin,\
	cylinder->center), cylinder->orient) * dot_product(vector_sub(ray.origin,\
	cylinder->center), cylinder->orient));
	axc = axc - cylinder->radiangle * cylinder->radiangle;

	a = 1;
	b = 4.0 * dot_product(Q, ray.direct);
	c = 2.0 * (dot_product(Q, Q) + pow(torus->torus_r, 2) - pow(torus->circl_r, 2)) + 4.0 * pow(dot_product(Q, ray.direct), 2) - 4.0 * pow(torus->torus_r, 2) * axa;
	d = 4.0 * (dot_product(Q, Q) + pow(torus->torus_r, 2) - pow(torus->circl_r, 2)) * dot_product(Q, ray.direct) - 4.0 * pow(torus->torus_r, 2) * axb;
	e = pow((dot_product(Q, Q) + pow(torus->torus_r, 2) - pow(torus->circl_r, 2)), 2) - 4.0 * pow(torus->torus_r, 2) * axc;

	// root = solve_quartic(a/a-b/4.0, b/a-b/4.0, c/a-b/4.0, d/a-b/4.0, e/a-b/4.0);
	root = solve_quartic(a, b, c, d, e);
	ret.t = root;

	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;

//https://books.google.fr/books?id=YPblYyLqBM4C&pg=PA87&lpg=PA87&dq=quadratics+equation+steiner+surface+ray+tracing&source=bl&ots=y_a8WHplOg&sig=B5mvN1qhh14rSV4lNQBX-w4FTb8&hl=fr&sa=X&ved=0ahUKEwjLhNOijKnLAhWJ1xoKHTc_CvwQ6AEIKDAA#v=onepage&q=quadratics%20equation%20steiner%20surface%20ray%20tracing&f=false
//http://www.realtimerendering.com/resources/GraphicsGems/gemsii/intersect/inttor.c
	// printf("root = %lf\n", root);

if (root > 0)//&& ret.t > 0)
	ret.inter = 1;
else
	ret.inter = 0;
(void)ret;(void)ray;
	return (ret);
}

t_torus		torus_creator()
{
t_torus		torus;
torus.center.x = 0;//1000;//1;
torus.center.y = 0;//4000;//1500;
torus.center.z = 0;//10000000;//100000;//10000;//-7000;//-10;//10;//-900;
torus.axis.x = 10;//10;//10;//10;
torus.axis.y = 0;//10;//10;
torus.axis.z = 1;//10;//10;
torus.torus_r = 200.0;
torus.circl_r = 20.0;
return (torus);
}
