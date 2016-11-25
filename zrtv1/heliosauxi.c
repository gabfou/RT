/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heliosauxi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:15:57 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 00:15:58 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		proto_fill(t_inter *inter, t_proto *proto, t_color color)
{
	(void)color;
	proto->x = inter->pos.x;
	proto->y = inter->pos.y;
	proto->z = inter->pos.z;
	proto->color.r = color.r;
	proto->color.g = color.g;
	proto->color.b = color.b;
	proto->droite = NULL;
	proto->gauche = NULL;
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
	while (tmp != NULL)
	{
		ret = range_proton(ret, protocopieur(tmp), comptr);
		tmp = tmp->droite;
	}
	return (ret);
}

t_proto		*photosynthetisator_spatial(t_proto *protolis)
{
	t_proto	*prototree;
	int		(*comptr[3])(t_proto *, t_proto *);

	ft_putendl("GROW PLZ TREE");
	prototree = NULL;
	comptr[0] = compx;
	comptr[1] = compy;
	comptr[2] = compz;
	prototree = photon_branch(protolis, 0, comptr);
	ft_putendl("HELIOS IS FINISHED");
	return (prototree);
}
