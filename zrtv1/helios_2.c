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
# define PHOTOSTACK 100
# define PHOTONBR 50
# define PHOTODIV 1 / PHOTOSTACK
# define PHOTONBRDIV 1 / PHOTONBR

# define COLORSTACK 50

t_color		gimme_da_color(t_phcol *tab)
{
	t_color		color;
	t_phcol			*tmp;
	int				i;

	color = new_t_color(0, 0, 0);
	if (tab == NULL)
	{
	//	ft_putendl("gimme null");
		return (color);
	}
	i = da_color_lenght(tab);
	//printf("%d\n", i);
//	print_phcol(tab);
		//ft_error("tab NULL");
	tmp = tab;
	
	//printf("gimme = %d\n", get_color(tmp->color.r, tmp->color.g, tmp->color.b));
	while (tmp != NULL)
	{
		color.r += tab->color.r / i;
		color.g += tab->color.g / i;
		color.b += tab->color.b / i;
		tmp = tmp->next;
	}
	return (color);
}

void		free_phcol(t_phcol *tmp)
{
	t_phcol *pre;

	pre = NULL;
	while (tmp != NULL)
	{
		ft_putendl("free");
		pre = tmp;
		tmp = tmp->next;
	//	free(pre);
	}
}



t_phcol		*trimlast(t_phcol *tab)
{
	t_phcol	*tmp;
	t_phcol	*pre;
	int		i;

	i = 0;
	pre = NULL;
	tmp = tab;
	while (tmp && tmp->next != NULL && i < PHOTOSTACK)
	{
		pre = tmp;
		tmp = tmp->next;
		i++;
	}
	if (i > PHOTOSTACK)
	{
		//free_phcol(pre->next);
		pre->next = NULL;
	}
	return (tab);
}

t_phcol		*range_in_pile(t_phcol *tab, t_phcol *ins)
{
	t_phcol	*tmp;
	t_phcol	*pre;

//	ft_putendl("RANGE TA CHAMBRE");
	pre = NULL;
	tmp = tab;
	if (tab == NULL)
	{
	//	ft_putendl("RANGE TA NULLLLLLLLLLLLLL");
		return (ins);
	}
	while(tmp != NULL)
	{
	//	printf("distins %f\n",ins->dist);
	//	printf("disttmp %f\n",tmp->dist);
		if (tmp && ins && ins->dist <= tmp->dist)
		{
			if (pre == NULL)
			{
				ins->next = tmp;
				//print_phcol(tab);
				//return (trimlast(ins));
				return (ins);
			}
			pre->next = ins;
			ins->next = tmp;
			//print_phcol(tab);
			//return (trimlast(tab)); 
			return (tab); 
		}
		pre = tmp;
		tmp = tmp->next;
	}
	//ft_putendl("LIST");
	//print_phcol(tab);
	return (tab);
}

FLOAT_SIZE	get_node_dist(t_vec ph_pos, t_vec pos, int profmod)
{
	if (profmod == 0)
		return (ph_pos.x - pos.x);
	else if (profmod == 1)
		return (ph_pos.y - pos.y);
	return (ph_pos.z - pos.z);
}

t_color		el_luminor(t_proto *rtmp, t_vec pos)
{
	t_vec		dpos;
	t_vec		gpos;
	FLOAT_SIZE	ddist;
	FLOAT_SIZE	gdist;
	FLOAT_SIZE	dist;
	t_color		color;
	t_proto		*tmp;
	t_phcol		*list;
	t_phcol		*ins;
	int			i;

	i = 0;
	color = new_t_color(0, 0, 0);
	gdist = 0;
	ddist = 0;
	dist = 1000000;
	tmp = NULL;
	list = NULL;
	ins = NULL;
	if (rtmp == NULL)
		ft_error("no tree");
//	printf("%s\n", "NIARK");
//	printf("%s\n", "NIARK2");
//	printf("distNODe %f\n",nodedist);
	tmp = rtmp;
	while (tmp && tmp->gauche && tmp->gauche)
	{
		if(tmp->gauche)
			gpos = new_t_vec(tmp->gauche->x, tmp->gauche->y, tmp->gauche->z);
		if(tmp->droite)
			dpos = new_t_vec(tmp->droite->x, tmp->droite->y, tmp->droite->z);
		gdist = get_sqr_dist(gpos, pos);
		ddist = get_sqr_dist(dpos, pos);
		if (gdist < ddist && gdist < dist)
		{
			dist = gdist;
			tmp = tmp->gauche;
			color = new_t_color(tmp->color.r, tmp->color.g, tmp->color.b);
			ins = new_phcol(color, dist);
			list = range_in_pile(list, ins);
			continue;
		}
		else if (ddist < dist)
		{
			dist = ddist;
			tmp = tmp->droite;
			color = new_t_color(tmp->color.r, tmp->color.g, tmp->color.b);
			ins = new_phcol(color, dist);
			list = range_in_pile(list, ins);
			continue;
		}
		else //if (i > 60)
		 	return (gimme_da_color(list));
	i++;
	}
	return (gimme_da_color(list));
	// while (realtmp)
	// {	
	// 	ph_pos = new_t_vec(tmp->x, tmp->y, tmp->z);
	// 	nodedist = get_node_dist(ph_pos, pos, profmod);
	// 	dist = get_sqr_dist(ph_pos, pos);
	// 	if (tmp && nodedist < 0)
	// 	{
	// 	//	ft_putendl("GAUCHE");
	// 		pile = el_luminor(tmp->gauche, pos, prof + 1, pile);
	// 		if (carre(nodedist) < PHOTODIST)
	// 			pile = el_luminor(tmp->droite, pos, prof + 1, pile);
	// 	}
	// 	else if (tmp && nodedist >= 0)
	// 	{
	// 	//	ft_putendl("DROITE");
	// 		pile = el_luminor(tmp->droite, pos, prof + 1, pile);
	// 		if (carre(nodedist) < PHOTODIST)
	// 			pile = el_luminor(tmp->gauche, pos, prof + 1, pile);
	// 	}
	// 	if (dist < PHOTODIST)
	// 	{
	// 	//	ft_putendl("ADDEMENT");
	// 		ins = new_phcol(tmp->color, dist);
	// 		pile = range_in_pile(pile, ins);
	// 		if (pile == NULL)
	// 			ft_error("sortie NULL");
	// 	}
	// }
	// return (pile);

}

// t_phcol		*el_luminor(t_proto *tmp, t_vec pos, int prof, t_phcol *pile)
// {
// 	t_vec		ph_pos;
// 	FLOAT_SIZE	nodedist;
// 	FLOAT_SIZE	dist;
// 	int			profmod;
// 	t_phcol		*ins;

// 	dist = 0;
// 	profmod = prof % 3;
// 	if (tmp == NULL)
// 		return (pile);
// //	printf("%s\n", "NIARK");
// 	ph_pos = new_t_vec(tmp->x, tmp->y, tmp->z);
// //	printf("%s\n", "NIARK2");
// 	nodedist = get_node_dist(ph_pos, pos, profmod);
// 	dist = get_sqr_dist(ph_pos, pos);
// //	printf("distNODe %f\n",nodedist);
// 	if (tmp && nodedist < 0)
// 	{
// 	//	ft_putendl("GAUCHE");
// 		pile = el_luminor(tmp->gauche, pos, prof + 1, pile);
// 		if (carre(nodedist) < PHOTODIST)
// 			pile = el_luminor(tmp->droite, pos, prof + 1, pile);
// 	}
// 	else if (tmp && nodedist >= 0)
// 	{
// 	//	ft_putendl("DROITE");
// 		pile = el_luminor(tmp->droite, pos, prof + 1, pile);
// 		if (carre(nodedist) < PHOTODIST)
// 			pile = el_luminor(tmp->gauche, pos, prof + 1, pile);
// 	}
// 	if (dist < PHOTODIST)
// 	{
// 	//	ft_putendl("ADDEMENT");
// 		ins = new_phcol(tmp->color, dist);
// 		pile = range_in_pile(pile, ins);
// 		if (pile == NULL)
// 			ft_error("sortie NULL");
// 	}
// 	return (pile);
// }


t_color		el_subluminor(t_vec pos, t_env *env)
{
	t_phcol	*tab;
//	int		i;
//	t_inter	inter;
	t_pd	pd;
	t_color	color;

//	i = 0;
	color = new_t_color(0, 0, 0);
	pd.pos = pos;
	tab = NULL;
	// while (i < PHOTOSTACK)
	// {
		// pd.dir = conseiller_d_orientation_protonique_alcolique();
		// t_inter_set(&inter);
		// impactor(&pd, env->item, &inter);
		// set_inter_pos(&inter, &pd);
		color = el_luminor(env->prototree, pos);
		//color += color_mult(gimme_da_color(tab) , PHOTONBRDIV, PHOTONBRDIV, PHOTONBRDIV);
	// 	i++;
	// }
//	printf("%d\n", i);
	return (color);
}


unsigned int	amaterasu(t_thr *f, t_inter *inter)
{
	t_color	ret;
	t_color		global_color;
	t_color		direct_color;
	FLOAT_SIZE		x;

	x = 0;
	ret = new_t_color(0, 0, 0);
	direct_color = new_t_color(0, 0, 0);
	global_color = new_t_color(0, 0, 0);
	direct_color = luminator(f, inter);
	if (x != 0)
		global_color = el_subluminor(inter->pos, f->env);
	 // printf("global c = %d\n", global_color);
	 // printf("dirsct c = %d\n", direct_color);
	//printf("\n%f %f %f\n", direct_color.r, direct_color.g, direct_color.b);
	ret = t_color_add(t_color_mult(global_color, x), t_color_mult(direct_color, 1 - x));
	return (get_color(ret.r, ret.g, ret.b));
}


