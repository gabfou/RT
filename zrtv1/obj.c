/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 20:24:06 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/30 20:24:08 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		check_obj(t_item *item, t_pd *s, t_inter *inter, t_thr *f)
{
	t_item *tmp;

	tmp = item->obj->tr;
	while(tmp)
	{
		if (tmp->cnb)
			check_triangle(tmp, s, inter, f);
		tmp = tmp->next;
	}
}
