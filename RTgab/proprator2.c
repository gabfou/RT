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

inline t_v 			vsv(t_v a, t_v b)
{
	t_v v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

inline t_v 			vmv(t_v a, t_v b)
{
	t_v v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	return (v);
}

inline t_v 			vdv(t_v a, t_v b)
{
	t_v v;

	v.x = a.x / b.x;
	v.y = a.y / b.y;
	v.z = a.z / b.z;
	return (v);
}

inline t_v 			vav(t_v a, t_v b)
{
	t_v v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

inline t_v 			pv(t_v a, t_v b)
{
	t_v v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

inline long double	vdp(t_v a)
{
	return (a.x + a.y + a.z);
}
