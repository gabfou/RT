/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helios.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:59:53 by jromagna          #+#    #+#             */
/*   Updated: 2016/04/11 16:59:54 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
//photonic_yolo_director


void		impactoralancienne(t_pd *pd, t_item *item, t_inter *inter)
{
	t_item	*lst;

	lst = item;
	while (item != NULL)
	{
		if (item->sp != NULL)
		{
			check_sphere(item, pd, inter, 1);
		}
		else if (item->pl != NULL)
		{
			check_plane(item, pd, inter, 1);
		}
		else if (item->cyl != NULL)
		{
			check_cyl(item, pd, inter, 1);
		}
		else if (item->con != NULL)
		{
			check_con(item, pd, inter, 1);
		}
		item = item->next;
	}
	item = lst;
}

t_vec		conseiller_d_orientation_protonique_alcolique()
{
	return (new_t_vec(((((float)rand()/(float)(RAND_MAX)) * 2) - 1),
	   ((((float)rand()/(float)(RAND_MAX)) * 2) - 1),
	  ((((float)rand()/(float)(RAND_MAX)) * 2) - 1)));
}

t_proto		*range_proton(t_proto *protolis, t_proto *proto, int (*comp)(t_proto *, t_proto *))
{
	t_proto *tmp;
	t_proto	*pre;
	static int x = 0;
	static int y = 0;
	static int z = 0;

	x++;
	pre = NULL;
	tmp = NULL;
	if (proto == NULL)
	{
		y++;
		return (protolis);
	}
	if (protolis == NULL)
	{
		z++;
		protolis = proto;
		return (protolis);
	}
	tmp = protolis;
	while (comp(proto, tmp) == 1)
	{
		pre = tmp;
		tmp = tmp->droite;
	}
	if (pre != NULL)
	{
		pre->droite = proto;
		proto->droite = tmp;
		return (protolis);
	}
	proto->droite = tmp;
	return (proto);
}


t_proto		*photon_branch(t_proto *protolis, int prof, int (**comptr)(t_proto *, t_proto *))
{
	t_proto	*start;
	t_proto	*tmp;
	t_proto	*pre;
	t_proto *tree;
	int		profmod;
	int		count;

	start = NULL;
	tmp = NULL;
	pre = NULL;
	profmod = prof % 3;
	tmp = photoinsertor(protolis, comptr[profmod]);
	count = proto_counter(tmp) / 2;	
	start = tmp;
	while (count > 0)
	{
		pre = tmp;
		tmp = tmp->droite;
		count--;
	}
	tree = protocopieur(tmp);
	pre->droite = NULL;
	tmp = tmp->droite;
	if (start && start->droite != NULL)
		tree->gauche = photon_branch(start, profmod + 1, comptr);
	else
		tree->gauche = start;
	if (tmp && tmp->droite != NULL)
		tree->droite = photon_branch(tmp, profmod + 1, comptr);
	else
		tree->droite = tmp;
	return (tree);
}



t_vec 	trans_calculator_ret(t_inter *inter, t_pd *pd)
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
	// if (sin(angle) > (AIR_INCI / GLASS_INCI))
	// 	return (NULL);
	scalc = carre(AIR_INCI / GLASS_INCI) * carre(1 - carre(cos(angle)));
	t.x = ((AIR_INCI / GLASS_INCI) * pd->dir.x) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  inter->norm.x;
	t.y = ((AIR_INCI / GLASS_INCI) * pd->dir.y) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  inter->norm.y;
	t.z = ((AIR_INCI / GLASS_INCI) * pd->dir.z) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  inter->norm.z;
	return (normalizator_ret(t));
}

t_proto		*helios(t_light *light, t_proto *prototree, t_env *env)
{
	int		photon;
	t_pd	pd;
	t_proto	*protolis;
	t_thr	f;

	ft_putendl("PRAISE THE SUUUUUUUN !!");
	f = new_t_thr_spec(env);
	protolis = NULL;
	srand(time(NULL));
	while (light != NULL)
	{
		ft_putendl("BOUCLE");
		photon = 0;
		while (photon < light->photon)
		{
			pd.pos = light->pos;
			pd.dir = normalizator_ret(conseiller_d_orientation_protonique_alcolique());
			protolis = lance_soleil(&pd, protolis, &f, light->rcolor);
			photon++;
		}
		light = light->next;
	}
	if (protolis == NULL)
		return (NULL);
	ft_putendl("GROW PLZ TREE");
	prototree = photosynthetisator_spatial(protolis);
	ft_putendl("HELIOS IS FINISHED");
	return (prototree);
}




