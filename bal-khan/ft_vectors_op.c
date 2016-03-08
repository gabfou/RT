/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:40:08 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:40:10 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline double		vector_len(t_vect3d vector)
{
	double	ret;

	ret = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	return (ret);
}

inline double		dot_product(t_vect3d vector1, t_vect3d vector2)
{
	double	ret;

	ret = vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	return (ret);
}

inline t_vect3d		dot_vector(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret.x = vector1.x * vector2.x;
	ret.y = vector1.y * vector2.y;
	ret.z = vector1.z * vector2.z;
	return (ret);
}

inline t_vect3d		cross_product(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret.x = vector1.y * vector2.z - vector1.z * vector2.y;
	ret.y = vector1.z * vector2.x - vector1.x * vector2.z;
	ret.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return (ret);
}

inline t_vect3d		normalizator(t_vect3d vector1)
{
	t_vect3d	ret;
	double		len;

	len = vector_len(vector1);
	ret.x = vector1.x / len;
	ret.y = vector1.y / len;
	ret.z = vector1.z / len;
	return (ret);
}
