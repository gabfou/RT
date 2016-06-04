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

void		check_obj(t_item *item, t_pd *s, t_inter *inter, t_thr *f, int *cnb)
{
	t_item *tmp;
	(void)cnb;
	tmp = item->obj->tr;
	while(tmp)
	{
		// if ((tmp->cnb == NULL || checkcarre(cnb, tmp->cnb)))
		{
			// ft_putendl("niark");
			check_triangle(tmp, s, inter, f);
		}
		// else
		// {
		// 	t_cnb *tmp2 = tmp->cnb;
		// 	while(tmp2)
		// 	{
		// 		ft_putnbr(tmp2->i);
		// 		ft_putendl("");
		// 		tmp2 = tmp2->next;
		// 	}
		// }
		tmp = tmp->next;
	}
}
