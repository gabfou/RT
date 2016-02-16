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

inline long double	vm(t_v a, t_v b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline long double	vd(t_v a, t_v b)
{
	return (a.x / b.x + a.y / b.y + a.z / b.z);
}

inline long double 	vs(t_v a, t_v b)
{
	return (a.x - b.x + a.y - b.y + a.z - b.z);
}

inline long double	va(t_v a, t_v b)
{
	return (a.x + b.x + a.y + b.y + a.z + b.z);
}

inline long double	vwaza(t_v a, t_v b)
{
	return (a.x * b.y + a.y * b.z + a.x * b.z);
}