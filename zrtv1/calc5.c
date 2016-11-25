/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:18:22 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 00:18:23 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ref_ret(t_inter *inter, t_pd *pd)
{
	return (normalizator_ret(miroiratorvcalculator(pd->dir, inter->norm)));
}

int		da_color_lenght(t_phcol *tab)
{
	t_phcol	*tmp;
	int		i;

	i = 0;
	tmp = tab;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_vec	trans_calculator_ret(t_inter *inter, t_pd *pd)
{
	FLOAT_SIZE	scalc;
	FLOAT_SIZE	angle;
	t_vec		t;

	t.x = 0;
	t.y = 0;
	t.z = 0;
	angle = 0;
	scalc = 0;
	angle = M_PI_2 - acos(dot_prod(pd->dir, inter->norm));
	angle = (angle > 0) ? -angle : angle;
	scalc = carre(AIR_INCI / GLASS_INCI) * carre(1 - carre(cos(angle)));
	t.x = ((AIR_INCI / GLASS_INCI) * pd->dir.x) + ((AIR_INCI / GLASS_INCI)
		* cos(angle) - fabs(1 - scalc)) * inter->norm.x;
	t.y = ((AIR_INCI / GLASS_INCI) * pd->dir.y) + ((AIR_INCI / GLASS_INCI)
		* cos(angle) - fabs(1 - scalc)) * inter->norm.y;
	t.z = ((AIR_INCI / GLASS_INCI) * pd->dir.z) + ((AIR_INCI / GLASS_INCI)
		* cos(angle) - fabs(1 - scalc)) * inter->norm.z;
	return (normalizator_ret(t));
}
