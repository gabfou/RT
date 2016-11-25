/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lance_soleil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:10:49 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 00:10:58 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			lance_soleilauxi(t_inter *inter, t_pd *pd,
	t_proto *protolis, t_color licolor)
{
	t_proto			*proto;

	proto = new_t_proto();
	if (inter->trans == 0)
	{
		proto = new_t_proto();
		proto_fill(inter, proto, licolor);
		protolis = range_proton(protolis, proto, &compx);
		pd->pos = inter->pos;
		pd->dir =
		normalizator_ret(conseiller_d_orientation_protonique_alcolique());
	}
	else if (inter->trans > 0)
	{
		pd->dir = trans_calculator_ret(inter, pd);
		pd->pos = inter->pos;
	}
}

float			lance_soleilauxi2(t_inter *inter,
	t_pd *pd, t_thr *f, float *bang)
{
	t_inter_set(inter);
	impactor(f->env, pd, f, inter);
	set_inter_pos(inter, pd);
	*bang = ((float)rand() / (float)(RAND_MAX));
	return (get_color_str(&inter->diff));
}

void			lance_soleilauxiset_pd(t_inter *inter, t_pd *pd)
{
	pd->dir = ref_ret(inter, pd);
	pd->pos = inter->pos;
}

t_proto			*lance_soleilauxinit(float *diffpow, int *i,
	float *bang)
{
	*diffpow = 0;
	*i = -1;
	*bang = ((float)rand() / (float)(RAND_MAX));
	return (NULL);
}

t_proto			*lance_soleil(t_pd *pd, t_proto *protolis,
	t_thr *f, t_color licolor)
{
	t_inter			inter;
	float			bang;
	int				i;
	float			diffpow;
	t_proto			*proto;

	proto = lance_soleilauxinit(&diffpow, &i, &bang);
	while (++i <= 8)
	{
		diffpow = lance_soleilauxi2(&inter, pd, f, &bang);
		if (bang <= diffpow)
			lance_soleilauxi(&inter, pd, protolis, licolor);
		else if (bang > diffpow && bang < inter.ref + diffpow)
			lance_soleilauxiset_pd(&inter, pd);
		else if (inter.ref == 0 && inter.trans == 0)
		{
			proto = new_t_proto();
			proto_fill(&inter, proto, licolor);
			protolis = range_proton(protolis, proto, &compx);
			return (protolis);
		}
		else
			return (protolis);
	}
	return (protolis);
}
