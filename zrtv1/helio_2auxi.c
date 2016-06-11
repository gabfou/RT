/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helio_2auxi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 04:55:13 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 04:55:15 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_phcol		*range_in_pile(t_phcol *tab, t_phcol *ins)
{
	t_phcol	*tmp;
	t_phcol	*pre;

	pre = NULL;
	tmp = tab;
	if (tab == NULL)
		return (ins);
	while(tmp != NULL)
	{
		if (tmp && ins && ins->dist <= tmp->dist)
		{
			if (pre == NULL)
			{
				ins->next = tmp;
				return (ins);
			}
			pre->next = ins;
			ins->next = tmp;
			return (tab); 
		}
		pre = tmp;
		tmp = tmp->next;
	}
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

t_color		gimme_da_color(t_phcol *tab)
{
	t_color		color;
	t_phcol		*tmp;
	t_phcol		*tmp2;
	int			i;

	color = new_t_color(0, 0, 0);
	if (tab == NULL)
		return (color);
	i = da_color_lenght(tab);
	tmp = tab;
	while (tmp != NULL)
	{
		color.r += tab->color.r / i;
		color.g += tab->color.g / i;
		color.b += tab->color.b / i;
		tmp = tmp->next;
	}
	tmp = tab;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
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
		pre->next = NULL;
	return (tab);
}
