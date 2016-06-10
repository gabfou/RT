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

int			proto_counter(t_proto *protolis)
{
	int		i;
	t_proto	*tmp;

	i = 0;
	tmp = protolis;
	while (tmp != NULL)
	{
		tmp = tmp->droite;
		i++;
	}
	return (i);
}

void	proto_fill(t_inter *inter, t_proto *proto, t_color color)
{

	(void)color;
	//ft_putendl("filluuuuuu");
	proto->x = inter->pos.x;
	proto->y = inter->pos.y;
	proto->z = inter->pos.z;
	proto->color.r = color.r;
	proto->color.g = color.g; 
	proto->color.b = color.b;
	proto->droite = NULL;
	proto->gauche = NULL;
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
	//printf("proton nrb = %d\n", x);
	//ft_putendl("RANGE LE PROTN PLZ");
	pre = NULL;
	tmp = NULL;
	if (proto == NULL)
	{
		y++;
		//printf("proto null = %d\n", y);
	//	ft_putendl("LOOOOOOOOOOOOOL");
		return (protolis);
	}
	if (protolis == NULL)
	{
		z++;
	//	printf("protolis NULL = %d\n", z);
	//	ft_putendl("LAAAAAAAAAA");
		protolis = proto;
		return (protolis);
	}

	tmp = protolis;
	//ft_putendl("AVANT");
	while (comp(proto, tmp) == 1)
	{
	//	ft_putendl("BOUCLE COMP");
		pre = tmp;
		tmp = tmp->droite;
	}
	//ft_putendl("apres la boucle");
	if (pre != NULL)
	{
		pre->droite = proto;
		proto->droite = tmp;
		return (protolis);
	}
	else
	{
		proto->droite = tmp;
		return (proto);
	}
	//ft_putendl("toutalafin");
}

t_proto		*protocopieur(t_proto *protolis)
{
	t_proto	*proto;

	proto = malloc(sizeof(t_proto));
	proto->x = protolis->x;
	proto->y = protolis->y;
	proto->z = protolis->z;
	proto->color = protolis->color;
	proto->droite = NULL;
	proto->gauche = NULL;
	return (proto);
}

t_proto		*photoinsertor(t_proto *list, int (*comptr)(t_proto *, t_proto *))
{
	t_proto	*ret;
	t_proto	*tmp;

	tmp = list;
	ret = NULL;
	//ft_putendl("\ndebut sertor");
//	print_proto_list(list);
//	ft_putendl("\n milieu");
	while (tmp != NULL)
	{
		ret = range_proton(ret, protocopieur(tmp), comptr);
	//	ft_putendl("boucle");
	//	print_proto_list(ret);
		tmp = tmp->droite;
	}
	// ft_putendl("\nle GRAND FINALEEE");
//	 print_proto_list(ret);
	// ft_putendl("finsertor");
	return (ret);
}

t_proto		*photon_branch(t_proto *protolis, int prof, int (**comptr)(t_proto *, t_proto *))
{
	t_proto	*start;
	t_proto	*tmp;
	t_proto	*pre;
	t_proto *tree;
	int		profmod;
	int		count;

	//ft_putendl("\nBRAMCH BRANCH");
	
	start = NULL;
	tmp = NULL;
	pre = NULL;
	

	profmod = prof % 3;
	//printf("prof mod = %d\n", profmod);

	tmp = photoinsertor(protolis, comptr[profmod]);

	count = proto_counter(tmp) / 2;	
//	printf("count = %d\n", count);
	
	start = tmp;
	while (count > 0)
	{
		//ft_putendl("count boucle");
		pre = tmp;
		tmp = tmp->droite;
		count--;
	}
	// ft_putendl("laaa1");
	tree = protocopieur(tmp);
	// ft_putendl("laaa2");
	pre->droite = NULL;
	// ft_putendl("laaa3");
	tmp = tmp->droite;
	// ft_putendl("laaa4");
	if (start && start->droite != NULL)
	{
		// ft_putendl("laaa5");
		tree->gauche = photon_branch(start, profmod + 1, comptr);
		// ft_putendl("laaa6");
	}
	else
	{
		// ft_putendl("laaa7");
		tree->gauche = start;
		// ft_putendl("laaa8");
	}
	if (tmp && tmp->droite != NULL)
	{
		// ft_putendl("laaa9");
		tree->droite = photon_branch(tmp, profmod + 1, comptr);
		// ft_putendl("laaa10");
	}
	else
	{
		// ft_putendl("laaa11");
		tree->droite = tmp;
		// ft_putendl("laaa12");
	}
	// ft_putendl("return tree");
	return (tree);
}

// t_proto		*photon_branch(t_proto *protolis, int prof, int i, int (**comptr)(t_proto *, t_proto *))
// {
// 	t_proto	*start;
// 	t_proto	*tmp;
// 	t_proto	*pre;
// 	t_proto *tree;
// 	int		profmod;
// 	int		count;

// 	ft_putendl("\nBRAMCH BRANCH");
// 	printf("count = %d\n", i);
// 	start = NULL;
// 	tmp = NULL;
// 	pre = NULL;
// 	count = i / 2;
// 	profmod = prof % 3;
// 	printf("prof mod = %d\n", profmod);

// 	tmp = photoinsertor(protolis, comptr[profmod]);

// 	start = tmp;
// 	while (count > 0)
// 	{
// 		pre = tmp;
// 		tmp = tmp->droite;
// 		count--;
// 	}
// 	tree = protocopieur(tmp);
// 	pre->droite = NULL;
// 	tmp = tmp->droite;
// 	if (start->gauche != NULL)
// 		tree->gauche = photon_branch(start, profmod + 1, i / 2 , comptr);
// 	else
// 		tree->gauche = start;
// 	if (tmp->droite != NULL)
// 		tree->droite = photon_branch(tmp, profmod + 1, i / 2 , comptr);
// 	else
// 		tree->droite = tmp;
// 	ft_putendl("return tree");
// 	return (tree);
// }

t_proto		*photosynthetisator_spatial(t_proto *protolis)
{
	t_proto	*prototree;
	int 	(*comptr[3])(t_proto *, t_proto *);
	
	prototree = NULL;

	comptr[0] = compx;
	comptr[1] = compy;
	comptr[2] = compz;
	prototree = photon_branch(protolis, 0, comptr);
	return (prototree);
}

t_vec	ref_ret(t_inter *inter, t_pd *pd)
{
	return (normalizator_ret(miroiratorvcalculator(pd->dir, inter->norm)));
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

t_proto			*lance_soleil(t_pd *pd, t_proto	*protolis, t_thr *f, t_color licolor)
{
	static int		test = 0;
	t_inter			inter;
	float			bang;
	int				i;
	float			diffpow;
	t_proto			*proto;

	diffpow = 0;
	
	//printf("test = %d\n", test);
	i = 0;
	
	proto = NULL;
	bang = ((float)rand()/(float)(RAND_MAX));
	while (i <= 8)
	{
		test++;
		t_inter_set(&inter);
		impactor(f->env, pd, f , &inter);
		set_inter_pos(&inter, pd);
		bang = ((float)rand()/(float)(RAND_MAX));
	//	printf("bang = %f\n", bang);
		diffpow = get_color_str(&inter.diff);
		if (bang <= diffpow)
		{
			if (inter.trans == 0)
			{
				proto = new_t_proto();
				proto_fill(&inter, proto, licolor);
				protolis = range_proton(protolis, proto, &compx);
				// if (protolis == NULL)
				// 	ft_putendl("toujours NULL");
				// else
				// 	ft_putendl("sortie bien");
				pd->pos = inter.pos;
				pd->dir = normalizator_ret(conseiller_d_orientation_protonique_alcolique());
			}
			else if (inter.trans == 1)
			{
				pd->dir = trans_calculator_ret(&inter, pd);
				pd->pos = inter.pos;
			}
			continue ;
		}
		else if (bang > diffpow && bang < inter.ref + diffpow)
		{
			pd->dir = ref_ret(&inter, pd);
			pd->pos = inter.pos;
			continue ;
		}
		else if (inter.ref == 0 && inter.trans == 0)
		{
			proto = new_t_proto();
			proto_fill(&inter, proto, licolor);
			protolis = range_proton(protolis, proto, &compx);
			// if (protolis == NULL)
			// 	ft_putendl("toujours NULL");
			// else
			// 	ft_putendl("sortie bien");
			return (protolis);
		}
		else 
			return (protolis);
		i++;
	}
	return (protolis);
}

t_thr		new_t_thr_spec(t_env *env)
{
	t_thr		f;

	f.done = 0;
	f.env = env;
	f.minx = 0;
	f.maxx = 0;
	f.miny = 0;
	f.maxy = 0;
	f.item = env->item;
	f.light = env->light;
	f.cam = env->cam;
	f.limg = env->limg;
	f.impactmod = 1;
	setthrcnb(&f);
	return (f);
}

t_proto		*helios(t_item *item, t_light *light, t_proto *prototree, t_env *env)
{
	int		photon;
	t_pd	pd;
	t_proto	*protolis;
	t_thr	f;

	(void)item;
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
			//ft_putendl("BOUCLE2");
			pd.pos = light->pos;
			pd.dir = normalizator_ret(conseiller_d_orientation_protonique_alcolique());
			protolis = lance_soleil(&pd, protolis, &f, light->rcolor);
			photon++;
		}
		ft_putendl("BOUCLE fin");
		light = light->next;
	}
	
	//print_proto_list(protolis);

	if (protolis == NULL)
	{
		ft_putendl("NUUUUUUULLLLLLLLLL");
		return (NULL);
	}
	ft_putendl("GROW PLZ TREE");
	prototree = photosynthetisator_spatial(protolis);
	ft_putendl("HELIOS IS FINISHED");
//	print_tout_tree(prototree);
	return (prototree);
}




