/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_op_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:39:39 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:39:41 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline t_vect3d		vector_sub(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret.x = vector1.x - vector2.x;
	ret.y = vector1.y - vector2.y;
	ret.z = vector1.z - vector2.z;
	return (ret);
}

inline t_vect3d		vector_add(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret.x = vector1.x + vector2.x;
	ret.y = vector1.y + vector2.y;
	ret.z = vector1.z + vector2.z;
	return (ret);
}

inline t_vect3d		vector_mult(t_vect3d vector1, double mult)
{
	t_vect3d	ret;

	ret.x = vector1.x * mult;
	ret.y = vector1.y * mult;
	ret.z = vector1.z * mult;
	return (ret);
}

inline t_vect3d		vector_div_vector(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret.x = vector1.x / vector2.x;
	ret.y = vector1.y / vector2.y;
	ret.z = vector1.z / vector2.z;
	return (ret);
}

inline t_vect3d		vector_div(t_vect3d vector1, double a)
{
	t_vect3d	ret;

	ret.x = vector1.x / a;
	ret.y = vector1.y / a;
	ret.z = vector1.z / a;
	return (ret);
}
