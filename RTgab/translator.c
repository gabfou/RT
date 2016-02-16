/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recuperatoraux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 19:08:05 by gfournie          #+#    #+#             */
/*   Updated: 2015/10/05 19:08:07 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

t_t		mtranslator(t_v pos, t_v dir)
{
	t_t t;


	t.pos.x = pos.x;
	t.pos.y = pos.y;
	t.pos.z = pos.z;
	t.dir.x = dir.x;
	t.dir.y = dir.y;
	t.dir.z = dir.z;
	if (t.dir.x != 0)
	{
		t.right.x =  t.dir.z / t.dir.x;
		t.right.y = 0;
		t.right.z = 1;
		t.right = normalisator(t.right);
	}
	else
	{
		t.right.x = 1;
		t.right.y = 0;
		t.right.z = 0;
	}
	if (t.dir.x != 0)
	{
		t.up.x =  t.right.z / t.right.x;
		t.up.y = (t.dir.x * t.up.x + t.dir.z) / t.right.x;
		t.up.z = 1;
		t.up = normalisator(t.up);
	}
	else
	{
		t.up.x = 0;
		t.up.y = 1;
		t.up.z = 0;
	}
	return (t);
}

t_t		inversator(t_t t)
{
	t_t			r;
	long double	det;

	det = t.right.x * t.up.y * t.dir.z
	+ t.right.y * t.up.z * t.dir.x
	+ t.right.z * t.up.x * t.dir.y
	- t.right.z * t.up.y * t.dir.x
	- t.right.x * t.up.z * t.dir.y
	- t.right.y * t.up.x * t.dir.z;

	r.right.x = (t.up.y * t.dir.z - t.up.z * t.dir.y) / det;
	r.right.y = (t.right.z * t.dir.y - t.right.y * t.dir.z) / det;
	r.right.z = (t.right.y * t.up.z - t.right.z * t.up.y) / det;
	r.up.x = (t.up.z * t.dir.x - t.up.x * t.dir.z) / det;
	r.up.y = (t.right.x * t.dir.z - t.right.z * t.dir.x) / det;
	r.up.z = (t.right.z * t.up.x - t.up.z * t.right.x) / det;
	r.dir.x = (t.up.x * t.dir.y - t.up.y * t.dir.x) / det;
	r.dir.y = (t.right.y * t.dir.x - t.right.x * t.dir.y) / det;
	r.dir.z = (t.right.x * t.up.y - t.right.y * t.up.x) / det;
	return (r);
}

t_v		vtranslator(t_v v, t_t t)
{
	t_v r;


	r.x = t.right.x * v.x + t.right.y * v.y + t.right.z * v.z;
	r.y = t.up.x * v.x + t.up.y * v.y + t.up.z * v.z;
	r.z = t.dir.x * v.x + t.dir.y * v.y + t.dir.z * v.z;
	return (r);
}

t_v		ptranslator(t_v p, t_t t)
{
	long double	d;
	t_v			v;

	d = sqrt((t.pos.x - p.x) * (t.pos.x - p.x) + (t.pos.y - p.y) * (t.pos.y - p.y) + (t.pos.z - p.z) * (t.pos.z - p.z));
	v.x = (t.pos.x - p.x);
	v.y = (t.pos.y - p.y);
	v.z = (t.pos.z - p.z);
	v = normalisator(v);
	v = vtranslator(v, t);
	v.x = t.pos.x + v.x * d;
	v.y = t.pos.y + v.y * d;
	v.z = t.pos.z + v.z * d;
	return (v);
}
