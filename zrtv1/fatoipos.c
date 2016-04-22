/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatoipos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 23:17:38 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/15 23:17:40 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		set_new_pos(t_vec dir, t_vec pos, FLOAT_SIZE dist)
{
	return (new_t_vec(pos.x + (dir.x * dist),
		pos.y + (dir.y * dist), pos.z + (dir.z * dist)));
}

void		set_inter_pos(t_inter *inter, t_pd *pd)
{
	inter->pos.x = (pd->pos.x + (pd->dir.x * inter->t));
	inter->pos.y = (pd->pos.y + (pd->dir.y * inter->t));
	inter->pos.z = (pd->pos.z + (pd->dir.z * inter->t));
}

FLOAT_SIZE	fatoi_aux(char *str, FLOAT_SIZE *si, FLOAT_SIZE *di)
{
	int			i;
	FLOAT_SIZE	k;

	i = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (*si == 0)
			*si = (str[i] == '-') ? -1 : 1;
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	else
		*si = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	*di = i;
	return (k);
}

// FLOAT_SIZE	fatoi_aux(char *str, FLOAT_SIZE *si, FLOAT_SIZE *di)
// {
// 	int			i;
// 	FLOAT_SIZE	k;

// 	i = 0;
// 	k = 0;
// 	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
// 			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
// 		i++;
// 	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
// 		return (0);
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		i++;
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 	}
// 	if (*si == 0)
// 		*si = (str[i - 1] == '-') ? -1 : 1;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		k = k * 10 + str[i] - '0';
// 		i++;
// 	}
// 	*di = i;
// 	return (k);
// }

FLOAT_SIZE	ft_fatoi(char *s)
{
	FLOAT_SIZE	d1;
	FLOAT_SIZE	d2;
	int			i;
	FLOAT_SIZE	si;
	FLOAT_SIZE	di;

	i = 0;
	d2 = 0;
	si = 0;
	d1 = fatoi_aux(s, &si, &di);
	while (s[i] && s[i] != '.')
		i++;
	di = 0;
	if (s[i] && s[i] == '.')
		d2 = fatoi_aux(&s[i + 1], &si, &di);
	while (di > 0)
	{
		d2 = d2 / 10;
		di--;
	}
	return (si * (d1 + d2));
}
