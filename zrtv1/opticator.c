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

void	ref(t_thr *f, t_inter *inter, t_inter *mirinter, t_pd *pd, t_pd	*mirpd)
{
	// ft_putendl("niark");
	set_inter_pos(inter, pd);
	mirpd->dir = normalizator_ret(miroiratorvcalculator(pd->dir, inter->norm));
	// pd->dir = normalizator_ret(inter.norm);
	mirpd->pos = inter->pos;
	// pd->pos = add_vec(inter.pos, vec_mult(pd->dir, -1));

	impactor(f->env, mirpd, f, mirinter);
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

unsigned int	transroitor(t_inter *inter, t_thr *f, t_pd *pd)
{
	static int		p = 0;
	unsigned int	tmpcolor;
	t_inter			mirinter;
	t_inter			transinter;
	t_pd			mirpd;
	t_pd			transpd;
	unsigned int	mircolor;
	unsigned int	transcolor;
	double			schlick;
	int				i;

	p++;
	schlick = 0;
	tmpcolor = 0x000000;
	mircolor = 0x000000;
	transcolor = 0x000000;
	t_inter_set(&transinter);
	t_inter_set(&mirinter);
	if (inter->ref > 0 && p < 5000)
	{
		ref(f, inter, &mirinter, pd, &mirpd);
		mircolor = transroitor(&mirinter, f, &mirpd);
		if ((i = trans_calculator(f, inter, &transinter, pd, &mirpd)) == 0)
			transcolor = transroitor(&transinter, f, &transpd);
		schlick = get_schlick(pd, inter);
	//	printf("sch = %f\n", schlick);
		schlick = 0.5;
		tmpcolor = color_mult(mircolor , schlick, schlick, schlick) + color_mult(transcolor , 1 - schlick, 1 - schlick, 1 - schlick);
	}
	else
	{
		tmpcolor = amaterasu(f, inter);
	}
//	printf("%d\n", p);
	p--;
	return (tmpcolor);
}
