/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helios.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:59:53 by jromagna          #+#    #+#             */
/*   Updated: 2016/06/11 22:07:20 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		conseiller_d_orientation_protonique_alcolique(void)
{
	return (new_t_vec(((((float)rand() / (float)(RAND_MAX)) * 2) - 1),
		((((float)rand() / (float)(RAND_MAX)) * 2) - 1),
		((((float)rand() / (float)(RAND_MAX)) * 2) - 1)));
}

t_proto		*range_proton(t_proto *protolis, t_proto *proto,
	int (*comp)(t_proto *, t_proto *))
{
	t_proto		*tmp;
	t_proto		*pre;
	static int	x = 0;
	static int	y = 0;
	static int	z = 0;

	pre = NULL;
	if (++x && proto == NULL && ++y)
		return (protolis);
	if (protolis == NULL && ++z && (protolis = proto) == proto)
		return (protolis);
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

void		photon_branchauxi(t_proto **tmp, t_proto **pre)
{
	*pre = *tmp;
	*tmp = (*tmp)->droite;
}

t_proto		*photon_branch(t_proto *protolis, int prof,
	int (**comptr)(t_proto *, t_proto *))
{
	t_proto	*start;
	t_proto	*tmp;
	t_proto	*pre;
	t_proto *tree;
	int		profmod;

	pre = NULL;
	profmod = prof % 3;
	tmp = photoinsertor(protolis, comptr[profmod]);
	prof = proto_counter(tmp) / 2;
	start = tmp;
	while (prof-- > 0)
		photon_branchauxi(&tmp, &pre);
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

t_proto		*helios(t_light *light, t_env *env)
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
		photon = 0;
		while (photon++ < light->photon)
		{
			pd.pos = light->pos;
			pd.dir = normalizator_ret(
				conseiller_d_orientation_protonique_alcolique());
			protolis = lance_soleil(&pd, protolis, &f, light->rcolor);
		}
		light = light->next;
	}
	if (protolis == NULL)
		return (NULL);
	return (photosynthetisator_spatial(protolis));
}
