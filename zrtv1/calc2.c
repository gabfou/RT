/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 23:09:38 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/15 23:09:42 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline FLOAT_SIZE	dot_prod(const t_vec v1, const t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline t_vec		vector_proj_vector(const t_vec v1, const t_vec v2)
{
	t_vec	ret;

	ret = vec_mult(v2, dot_prod(v1, v2) / dot_prod(v2, v2));
	return (ret);
}

inline FLOAT_SIZE	ft_min(const FLOAT_SIZE a, const FLOAT_SIZE b)
{
	if (a > b)
		return (b);
	return (a);
}

t_vec				normalizator_ret(t_vec vec)
{
	long double	lenght;

	lenght = sqrt(carre(vec.x) + carre(vec.y) + carre(vec.z));
	if (lenght == 0.0)
		ft_putendl("i just saved the universe!");
	vec.x = vec.x / lenght;
	vec.y = vec.y / lenght;
	vec.z = vec.z / lenght;
	return (vec);
}

void				normalizator(t_vec *vec)
{
	long double	lenght;

	lenght = sqrt(carre(vec->x) + carre(vec->y) + carre(vec->z));
	if (lenght == 0.0)
		ft_putendl("i just saved the universe!");
	vec->x = vec->x / lenght;
	vec->y = vec->y / lenght;
	vec->z = vec->z / lenght;
}
