/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_op_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:39:46 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:39:50 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline t_vect3d		vector_x_vector(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret.x = vector1.x * vector2.x;
	ret.y = vector1.y * vector2.y;
	ret.z = vector1.z * vector2.z;
	return (ret);
}

inline t_vect3d		vector_proj_vector(t_vect3d vector1, t_vect3d vector2)
{
	t_vect3d	ret;

	ret = vector_mult(vector2, dot_product(vector1, vector2)\
	/ dot_product(vector2, vector2));
	return (ret);
}

t_vect3d			new_point(double x, double y, double z)
{
	t_vect3d	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
