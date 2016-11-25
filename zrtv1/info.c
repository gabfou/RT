/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:20:30 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 21:24:06 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	printitem(t_item *item)
{
	if (!item)
		return ;
	if (item->sp)
		printsphere(item->sp);
	if (item->pl)
		printpl(item->pl);
	if (item->con)
		printcon(item->con);
	if (item->cyl)
		printcyl(item->cyl);
	if (item->obj)
		WRITE(1, "obj:\n");
	ft_putstr("id :");
	ft_putnbr(item->nb);
	ft_putendl("\n");
}

void	print_params(t_env env)
{
	t_item	*item;

	item = env.item;
	while (item)
	{
		printitem(item);
		item = item->next;
	}
}

void	print_carre(t_env env)
{
	t_carre	*carre;

	carre = env.carre;
	while (carre)
		carre = carre->next;
}
