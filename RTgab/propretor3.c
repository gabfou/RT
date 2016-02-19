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

inline t_v 			ps(t_v a, long double b)
{
	t_v v;

	v.x = a.x * b;
	v.y = a.y * b;
	v.z = a.z * b;
	return (v);
}


inline long double	ddp(t_v d, t_v v, t_v p)
{
	return (normecalculator(pv(vsv(p, d), v)) / normecalculator(v));
}

inline long double	svwaza(t_v a, t_v b)
{ 
	return (vwaza(a, b) + vwaza(b, a));
}
