/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatorauxi2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:43:16 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 22:58:38 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		t_inter_set(t_inter *inter)
{
	inter->norm.x = 0;
	inter->norm.y = 0;
	inter->norm.z = 0;
	inter->pos.x = 0;
	inter->pos.y = 0;
	inter->pos.z = 0;
	inter->t = -1;
	inter->trans = 0;
	inter->ref = 0;
	inter->item = NULL;
	inter->diff = new_t_color(1, 1, 1);
}
