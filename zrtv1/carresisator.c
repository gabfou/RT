/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carresisator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 22:26:28 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/02 22:26:29 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// nmap c cool

inline int	checkcarre(int *tab, t_cnb *cnb)
{
	int		i;
	t_cnb	*tmp;

	i = -1;
	while (tab[++i] && i < NB_CARRE)
	{
		tmp = cnb;
		while (tmp)
		{
			if (tmp->i == tab[i])
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

t_carre		*new_t_carrespe(FLOAT_SIZE size, t_vec pos)
{
	static int	cnb = 1;
	t_carre		*carre;

	carre = (t_carre*)malloc(sizeof(t_carre));
	if (size == 0)
		ft_putendl("dafuq?");
	carre->pos = pos;
	carre->dir.x = 0;
	carre->dir.y = 0;
	carre->dir.z = 1;
	carre->up.x = 0;
	carre->up.y = 1;
	carre->up.z = 0;
	carre->right.x = 1;
	carre->right.y = 0;
	carre->right.z = 0;
	carre->angle = 0;
	carre->size = size;
	carre->next = NULL;
	carre->cnb = cnb;
	cnb++;
	return (carre);
}

t_carre		*divisecarrerisatorauxi(t_carre *tmp, t_carre *c2)
{
	FLOAT_SIZE	size;

	size = c2->size / 2.0;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + (size), c2->pos.y, c2->pos.z));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x, c2->pos.y + (size), c2->pos.z));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + (size), c2->pos.y + (size), c2->pos.z));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x, c2->pos.y, c2->pos.z + size));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + (size), c2->pos.y, c2->pos.z + size));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x, c2->pos.y + (size), c2->pos.z + size));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + (size), c2->pos.y + (size), c2->pos.z + size));
	return (tmp->next);

}

t_carre		*divisecarrerisator(t_carre *c2, t_env *env)
{
	t_carre	*c;
	int		i;
	t_carre	*tmp;

	i = -1;
	tmp = env->carre;
	c = new_t_carrespe(c2->size / 2.0,
		new_t_vec(c2->pos.x, c2->pos.y, c2->pos.z));
	if (env->carre == c2)
	{
		env->carre = c;
		tmp = c;
	}
	else
	{
		while (tmp && tmp->next != c2)
			tmp = tmp->next;
		tmp->next = c;
	}
	// if (tmp->next)
	// 	tmp = tmp->next;
	tmp = divisecarrerisatorauxi(tmp, c2);
	tmp->next = c2->next;
	free(c2);
	return (c);
}

void		carresisator(t_env *env)
{
	t_carre	*c;
	int		i;

	i = -1;
	env->carre = new_t_carrespe(4000, new_t_vec(-2000, -2000, -2000));
	c = env->carre;
	while (c && i < NB_CARRE)
	{
		if (impactcarre(c, env) > 30 && c->size > 0.001)
		{
			if (i >= NB_CARRE)
				break;
			i++;
			c = divisecarrerisator(c, env);
		}
		else
			c = c->next;
	}
	print_carre(*env);
}
