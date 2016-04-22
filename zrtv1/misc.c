/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 20:33:02 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/15 20:33:03 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		itemadator(t_env *env, t_item *item)
{
	t_item		*copy;
	int			i;

	i = 1;
	if (!env->item)
		env->item = item;
	else
	{
		copy = env->item;
		while (copy->next)
		{
			i++;
			copy = copy->next;
		}
		copy->next = item;
	}
	return (i);
}

void		next_elem(t_list **elems)
{
	*elems = (*elems)->next;
}
