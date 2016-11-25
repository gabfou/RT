/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:19:40 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 19:13:57 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	printsphere(t_sphere *sp)
{
	ft_putendl("sphere:");
	ft_putstr("pos : ");
	print_vec(sp->c);
	ft_putstr("ray :");
	ft_putnbr(sp->ray);
	ft_putendl("");
}

void	printcon(t_con *con)
{
	ft_putendl("cone:");
	ft_putstr("pos : ");
	print_vec(con->pos);
	ft_putstr("dir : ");
	print_vec(con->dir);
	ft_putstr("angle :");
	ft_putnbr(con->ang);
	ft_putendl("");
}

void	printcyl(t_cyl *cyl)
{
	ft_putendl("cylindre:");
	ft_putstr("pos : ");
	print_vec(cyl->pos);
	ft_putstr("dir : ");
	print_vec(cyl->dir);
	ft_putstr("ray :");
	ft_putnbr(cyl->ray);
	ft_putendl("");
}

void	printpl(t_pd *pl)
{
	ft_putendl("plane:");
	ft_putstr("pos : ");
	print_vec(pl->pos);
	ft_putstr("dir : ");
	print_vec(pl->dir);
}
