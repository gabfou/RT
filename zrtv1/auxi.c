/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 18:37:33 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/19 18:37:34 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
}

void		print_vec(t_vec vec)
{
	(void)vec;
	printf("x = [%f]\n", vec.x);
	printf("y = [%f]\n", vec.y);
	printf("z = [%f]\n\n", vec.z);
}

FLOAT_SIZE	carre(FLOAT_SIZE x)
{
	return (x * x);
}

void		swapniark(FLOAT_SIZE *a, FLOAT_SIZE *b)
{
	FLOAT_SIZE c;

	c = *a;
	*a = *b;
	*b = c;
}

int			check_t(t_inter *inter, FLOAT_SIZE t,
	t_pd *s, t_item *item)
{
	// t_trans	*tmp;
	//ft_putendl("check t");
//	printf("IUHIPUHGIUO%f %f\n", inter->t, t);
	t_vec	pos;

	pos = add_vec(s->pos, vec_mult(s->dir, t));
	if (pos.x > item->mat.max.x || pos.x < item->mat.min.x
		|| pos.y > item->mat.max.y || pos.y < item->mat.min.y
		|| pos.z > item->mat.max.z || pos.z < item->mat.min.z)
		return (0);
	if ((inter->t > t && t > 0) || inter->t < 0)
	{
		inter->t = t;
		inter->ref = item->mat.ref;
		inter->diff = item->mat.diff;
		inter->trans = item->mat.trans;
		inter->pos = pos;
		return (1);
	}
	return (0);
}
