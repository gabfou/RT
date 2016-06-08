/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparencator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:59:42 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/12 20:59:44 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// FLOAT_SIZE	transparencator(unsigned int color, FLOAT_SIZE trans)
// {
// 	return (get_color(((color >> 0) & 0xFF)  * (trans / 100),
// 	 					((color >> 8) & 0xFF)  * (trans / 100),
// 	 					((color >> 16) & 0xFF)  * (trans / 100)));
// }

// FLOAT_SIZE	trans_calculator(t_trans *trans, FLOAT_SIZE	t)
// {
// 	FLOAT_SIZE	ret;
// 	t_trans	*tmp;

// 	ret = 100;
// 	tmp = trans;
// 	while (tmp != NULL)
// 	{
// 		// ft_putendl("boucle");
// 		// printf("tmp->t = %f\n", tmp->t);
// 		// printf("tmp->t = %f\n", tmp->t);
// 		// ft_putendl("boucle1.2");
// 		if (tmp->t < t)
// 			ret = ret * (1 - (tmp->colabs / 100));
// 		// ft_putendl("boucle2");
// 		tmp = tmp->next;
// 	}
// 	// ft_putendl("fin trans calc");
// 	 //printf("ret = %f\n", ret);
// 	return (ret);
// // }


// void	trans_calculator(t_thr *f, t_cor *c, t_pd *pd)
// {
// 	FLOAT_SIZE	scalc;
// 	FLOAT_SIZE	angle;
// 	t_vec		t;

// 	t.x = 0;
// 	t.y = 0;
// 	t.z = 0;
// 	angle = 0;
// 	scalc = 0;
// 	//t_inter_set(&(f->inter));
// 	// ft_putendl("trans calc");
// 	//set_inter_pos(&(f->inter), pd);
// 	angle = M_PI_2 - acos(dot_prod(pd->dir, f->inter.norm));
// 	// ft_putendl("trans calc 1.1 ");
// 	angle = (angle > 0) ? -angle : angle;
// 	// ft_putendl("trans calc1.2");
// 	//printf("%f\n", angle);
// 	// ft_putendl("pre if");
// 	if (sin(angle) > (AIR_INCI / GLASS_INCI))
// 		return ;
// 	// ft_putendl("post if");
// 	scalc = carre(AIR_INCI / GLASS_INCI) * carre(1 - carre(cos(angle)));
// 	// ft_putendl("post if");
// 	t.x = ((AIR_INCI / GLASS_INCI) * pd->dir.x) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  f->inter.norm.x;
// 	t.y = ((AIR_INCI / GLASS_INCI) * pd->dir.y) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  f->inter.norm.y;
// 	t.z = ((AIR_INCI / GLASS_INCI) * pd->dir.z) + ((AIR_INCI / GLASS_INCI) * cos(angle) - fabs(1 - scalc)) *  f->inter.norm.z;
// 	// ft_putendl("post xyz");
// 	// print_vec(t);
// 	pd->dir = /*normalizator_ret(sub_vec(*/normalizator_ret(t)/*, f->inter.pos))*/;
// 	pd->pos = f->inter.pos;
	
// 	f->fcolor = 0x000000;
// 	f->inter = new_t_inter();
// 	t_inter_set(&(f->inter));
// 	impactor(pd, f, &(f->inter));				
// 	if (f->inter.trans > 0 && ++f->inter.nbr_rec < REC_MAX)
// 	{
// 		ft_putendl("trans calc comeback");
// 		trans_calculator(f, pd);
// 	}
// }