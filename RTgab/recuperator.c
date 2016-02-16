/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recuperator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 22:48:12 by gfournie          #+#    #+#             */
/*   Updated: 2015/10/02 22:48:14 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

t_s		*sphereguardator(void *var, int i)
{
	static t_list	*l = NULL;
	t_list			*tmp;

	if (i == -1)
		ft_lstadd(&l, (ft_lstnew(var, sizeof(t_s))));
	if (i > 0)
	{
		tmp = l;
		while (--i > 0 && tmp)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		return (tmp->content);
	}
	return (NULL);
}

t_p		*planeguardator(void *var, int i)
{
	static t_list	*l = NULL;
	t_list			*tmp;

	if (i == -1)
		ft_lstadd(&l, (ft_lstnew(var, sizeof(t_p))));
	if (i > 0)
	{
		tmp = l;
		while (--i > 0 && tmp)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		return (tmp->content);
	}
	return (NULL);
}

t_l		*lightguardator(void *var, int i)
{
	static t_list	*l = NULL;
	t_list			*tmp;

	if (i == -1)
		ft_lstadd(&l, (ft_lstnew(var, sizeof(t_l))));
	if (i > 0)
	{
		tmp = l;
		while (--i > 0 && tmp)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		return (tmp->content);
	}
	return (NULL);
}

t_cy		*cyguardator(void *var, int i)
{
	static t_list	*l = NULL;
	t_list			*tmp;

	if (i == -1)
		ft_lstadd(&l, (ft_lstnew(var, sizeof(t_cy))));
	if (i > 0)
	{
		tmp = l;
		while (--i > 0 && tmp)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		return (tmp->content);
	}
	return (NULL);
}

t_co		*coguardator(void *var, int i)
{
	static t_list	*l = NULL;
	t_list			*tmp;

	if (i == -1)
		ft_lstadd(&l, (ft_lstnew(var, sizeof(t_co))));
	if (i > 0)
	{
		tmp = l;
		while (--i > 0 && tmp)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		return (tmp->content);
	}
	return (NULL);
}

t_p	planerecuperator()
{
	t_p p;

	p.p.x = 0;
	p.p.y = 0;
	p.p.z = 2.1;
	p.v.x = 3;
	p.v.y = 0;
	p.v.z = 1;
	p.v = normalisator(p.v);
	return (p);
}

// t_v			lightrecuperator()
// {
// 	t_v l;

// 	l.x = -1;
// 	l.y = 2;
// 	l.z = 0;
// 	return (l);
// }