/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 23:03:55 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/15 23:03:57 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline FLOAT_SIZE	get_dist(const t_vec v1, const t_vec v2)
{
	return (sqrt(carre(v2.x - v1.x) + carre(v2.y - v1.y) + carre(v2.z - v1.z)));
}

inline t_vec		vec_mult(const t_vec v1, const FLOAT_SIZE x)
{
	return (new_t_vec(v1.x * x, v1.y * x, v1.z * x));
}

inline t_vec		prod_vector(const t_vec v1, const t_vec v2)
{
	return (new_t_vec(v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x));
}

inline t_vec		sub_vec(const t_vec v1, const t_vec v2)
{
	return (new_t_vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

inline t_vec		add_vec(const t_vec v1, const t_vec v2)
{
	return (new_t_vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}
