/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helioscalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:39:07 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/10 01:39:09 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline int			compx(t_proto *proto1, t_proto *proto2)
{
	if (!proto1 || !proto2)
		return (0);
	if (proto1->x > proto2->x )
		return (1);
	return (0);
}

inline int			compy(t_proto *proto1, t_proto *proto2)
{
	if (!proto1 || !proto2)
		return (2);
	if (proto1->y > proto2->y)
		return (1);
	return (0);
}

inline int			compz(t_proto *proto1, t_proto *proto2)
{
	if (!proto1 || !proto2)
		return (2);
	if (proto1->z > proto2->z)
		return (1);
	return (0);
}

inline FLOAT_SIZE	get_sqr_dist(t_vec v1, t_vec v2)
{
	return (carre(v2.x - v1.x) + carre(v2.y - v1.y) + carre(v2.z - v1.z));
}
