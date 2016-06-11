/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helios_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 22:25:00 by jromagna          #+#    #+#             */
/*   Updated: 2016/06/04 22:25:02 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

# define PHOTODIST 50

# define PHOTONBR 50
# define PHOTODIV 1 / PHOTOSTACK
# define PHOTONBRDIV 1 / PHOTONBR

void		init_el_luminor(t_ellumi *el, t_proto *rtmp)
{
	el->i = 0;
	el->color = new_t_color(0, 0, 0);
	el->gdist = 0;
	el->ddist = 0;
	el->dist = 1000000;
	el->tmp = NULL;
	el->list = NULL;
	el->ins = NULL;
	if (rtmp == NULL)
		ft_error("no tree");
	el->tmp = rtmp;
}

int		el_luminorauxi(t_ellumi *el)
{
	if (el->gdist < el->ddist && el->gdist < el->dist)
	{
		el->dist = el->gdist;
		el->tmp = el->tmp->gauche;
		el->color = new_t_color(el->tmp->color.r, el->tmp->color.g, el->tmp->color.b);
		el->ins = new_phcol(el->color, el->dist);
		el->list = range_in_pile(el->list, el->ins);
	}
	else if (el->ddist < el->dist)
	{
		el->dist = el->ddist;
		el->tmp = el->tmp->droite;
		el->color = new_t_color(el->tmp->color.r, el->tmp->color.g, el->tmp->color.b);
		el->ins = new_phcol(el->color, el->dist);
		el->list = range_in_pile(el->list, el->ins);
	}
	else
		return (1);
	return (0);
}

t_color		el_luminor(t_proto *rtmp, t_vec pos)
{
	t_ellumi	el;

	init_el_luminor(&el, rtmp);
	while (el.tmp && el.tmp->gauche && el.tmp->gauche)
	{
		if(el.tmp->gauche)
			el.gpos = new_t_vec(el.tmp->gauche->x, el.tmp->gauche->y, el.tmp->gauche->z);
		if(el.tmp->droite)
			el.dpos = new_t_vec(el.tmp->droite->x, el.tmp->droite->y, el.tmp->droite->z);
		el.gdist = get_sqr_dist(el.gpos, pos);
		el.ddist = get_sqr_dist(el.dpos, pos);
		if (el_luminorauxi(&el))
		 	break ;
		el.i++;
	}
	return (gimme_da_color(el.list));
}

t_color		el_subluminor(t_vec pos, t_thr *f)
{
	t_phcol	*tab;
	int		i;
	t_inter	inter;
	t_pd	pd;
	t_color	color;
	t_color	ret;

	i = 0;
	color = new_t_color(0, 0, 0);
	ret = new_t_color(0, 0, 0);
	pd.pos = pos;
	tab = NULL;
	while (i < PHOTOSTACK)
	{
		pd.dir = conseiller_d_orientation_protonique_alcolique();
		t_inter_set(&inter);
		impactor(f->env, &pd, f, &(inter));
		set_inter_pos(&inter, &pd);
		color = el_luminor(f->env->prototree, inter.pos);
		ret.r += color.r / PHOTOSTACK;
		ret.g += color.g / PHOTOSTACK;
		ret.b += color.b / PHOTOSTACK;
		i++;
	}
	return (ret);
}

unsigned int	amaterasu(t_thr *f, t_inter *inter, int i)
{
	t_color	ret;
	t_color		global_color;
	t_color		direct_color;
	FLOAT_SIZE		x;

	x = MAPPING;
	if (x > 1)
		x = 1;
	if (x < 0)
		x = 0;
	ret = new_t_color(0, 0, 0);
	direct_color = new_t_color(0, 0, 0);
	global_color = new_t_color(0, 0, 0);
	direct_color = luminator(f, inter);
	if (x > 0 && i == 1)
		global_color = el_subluminor(inter->pos, f);
	else
		return (get_color(direct_color.r, direct_color.g, direct_color.b));
	ret = t_color_add(t_color_mult(global_color, x), t_color_mult(direct_color, 1 - x));
	return (get_color(ret.r, ret.g, ret.b));
}


