/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infohelios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:53:00 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/10 09:53:04 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		print_tout_tree(t_proto *tmp)
{
	static int x = -1;
	static int prof = 0;

	x++;
	printf("prof %d proto %d = %f] [y = %f] [z = %f]\n", prof, x, tmp->x , tmp->y, tmp->z);
	printf("color = %d\n", get_color(tmp->color.r, tmp->color.g, tmp->color.b));
	if (tmp->gauche)
	{
		prof++;
		print_tout_tree(tmp->gauche);
	}
	if (tmp->droite)
	{
		prof++;
		print_tout_tree(tmp->droite);
	}
	prof--;
}

void		print_proto(t_proto *tmp)
{
		ft_putstr("maillon protolis");
		printf("proto = x = %f] [y = %f] [z = %f]\n", tmp->x , tmp->y, tmp->z);
}

void		print_proto_list(t_proto *protolis)
{
	t_proto	*tmp;
	int		i;

	i = 0;
	tmp = protolis;
	ft_putstr("\n");
	while (tmp != NULL)
	{
		i++;
		ft_putstr("maillon protolis = ");
		printf("%d = [x = %f] [y = %f] [z = %f]\n", i, tmp->x , tmp->y, tmp->z);
		tmp = tmp->droite;
	}
}

void		print_phcol(t_phcol *t)
{
	t_phcol	*tmp;

	tmp = t;
	printf(" NEW LISTUH \n");
	while (tmp != NULL)
	{
		printf("dist = %f\n", tmp->dist);
		tmp = tmp->next;
	}
	ft_putendl("");
}
