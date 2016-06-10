/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opticator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 00:28:29 by gfournie          #+#    #+#             */
/*   Updated: 2016/02/23 00:28:37 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned int	color_mult(unsigned int color, FLOAT_SIZE r, FLOAT_SIZE g, FLOAT_SIZE b)
{
	return (get_color(((color >> 16) & 0xFF)  * r,
	 					((color >> 8) & 0xFF)  * g,
	 					((color >> 0) & 0xFF)  * b));
}

double 	trans_calculator(t_thr *f, t_inter *inter, t_inter *transinter, t_pd *pd, t_pd	*transpd)
{
	FLOAT_SIZE	scalc;
	FLOAT_SIZE	angle;
	t_vec		t;

	t.x = 0;
	t.y = 0;
	t.z = 0;
	angle = 0;
	scalc = 0;
	//t_inter_set(&(f->inter));
	//set_inter_pos(&(f->inter), pd);
	angle = M_PI_2 - acos(dot_prod(pd->dir, inter->norm));
	angle = (angle > 0) ? -angle : angle;
	if (sin(angle) > (AIR_INCI / GLASS_INCI))
		return (1);
	scalc = carre(AIR_INCI / GLASS_INCI) * carre(1 - carre(cos(angle)));
	t.x = ((AIR_INCI / GLASS_INCI) * pd->dir.x) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  inter->norm.x;
	t.y = ((AIR_INCI / GLASS_INCI) * pd->dir.y) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  inter->norm.y;
	t.z = ((AIR_INCI / GLASS_INCI) * pd->dir.z) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  inter->norm.z;
	transpd->dir = /*normalizator_ret(sub_vec(*/normalizator_ret(t)/*, inter->pos))*/;
	transpd->pos = inter->pos;
	impactor(f->env, transpd, f, transinter);
	return (0);
}

t_vec	miroiratorvcalculator(t_vec ray, t_vec norm)
{
	return (normalizator_ret(add_vec(norm,
		normalizator_ret(add_vec(ray, norm)))));
}

void	ref(t_thr *f, t_inter *inter, t_transroi *n, t_pd *pd)
{
	set_inter_pos(inter, pd);
	n->mirpd.dir = normalizator_ret(miroiratorvcalculator(pd->dir, inter->norm));
	n->mirpd.pos = inter->pos;
	impactor(f->env, &n->mirpd, f, &n->mirinter);
	return ;
}

double			get_schlick(t_pd *pd, t_inter *inter)
{
	double 	ro;
	double	cosi;
	double	cost;

	ro = carre (AIR_INCI - GLASS_INCI / AIR_INCI + GLASS_INCI);
	cosi = dot_prod(vec_mult(pd->dir, -1), inter->norm);
	cost = fabs(1 - (carre(AIR_INCI / GLASS_INCI) * (1 - carre(cosi))));
	if (AIR_INCI <= GLASS_INCI)
		return (ro + (1 - ro) * pow(1 - cosi, 5));
	else if (AIR_INCI > GLASS_INCI)
		return (ro + (1 - ro) * pow(1 - cost, 5));
	else
		return (1);

}

unsigned int	transroitor(t_inter *inter, t_thr *f, t_pd *pd, int p)
{
	t_transroi	n;

	n.schlick = 0;
	n.tmpcolor = 0x000000;
	n.mircolor = 0x000000;
	n.transcolor = 0x000000;
	t_inter_set(&n.transinter);
	t_inter_set(&n.mirinter);
	if (inter->ref > 0 && p < 8)
	{
		ref(f, inter, &n, pd);
		n.mircolor = transroitor(&n.mirinter, f, &n.mirpd, p + 1);
		if ((n.i = trans_calculator(f, inter, &n.transinter, pd, &n.transpd)) == 0)
			n.transcolor = transroitor(&n.transinter, f, &n.transpd, p + 1);
		// n.schlick = get_schlick(pd, inter);
	//	printf("sch = %f\n", n.schlick);
		n.schlick = 1;
		n.tmpcolor = color_mult(n.mircolor , n.schlick, n.schlick, n.schlick)
		+ color_mult(n.transcolor , 1 - n.schlick, 1 - n.schlick, 1 - n.schlick);
	}
	else
		n.tmpcolor = amaterasu(f, inter);
//	printf("%d\n", p);
	return (n.tmpcolor);
}
