/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recuperatoraux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 19:08:05 by gfournie          #+#    #+#             */
/*   Updated: 2015/10/05 19:08:07 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

int 	sphererecuperator(char *l, t_env *e)
{
	int	i;
	int	j;
	t_s	s;

	j = 0;
	i = -1;
	(void)e;
	ft_putendl("dsdf");
	s.color.x = 1;
	s.color.y = 1;
	s.color.z = 1;
	while (l[++i])
		if (l[i] == ' ' && l[i + 1] != ' ' && l[i + 1])
			j++;
	if (j != 7)
		error("pb d argument sphere");
	i = 0;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	ft_putendl(&l[i + 1]);
	s.p.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	s.p.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	s.p.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	s.r = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	s.color.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	s.color.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	s.color.z = (float)ft_atoi2(&l[++i]) / 1000;
	sphereguardator(&s, -1);
	ft_putendl("dsdf2");
	return (0);
}

int 	planrecuperator(char *l, t_env *e)
{
	int	i;
	int	j;
	t_p	p;

	j = 0;
	i = -1;
	(void)e;
	while (l[++i])
		if (l[i] == ' ' && l[i + 1] != ' ' && l[i + 1])
			j++;
	if (j != 9)
		error("pb d argument plan");
	i = 0;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	ft_putendl(&l[i + 1]);
	p.p.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.x = (float)ft_atoi2(&l[++i]) / 1000;
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.z = (float)ft_atoi2(&l[++i]) / 1000;
	p.v = normalisator(p.v);
	planeguardator(&p, -1);
	return (0);
}

int 	cyrecuperator(char *l, t_env *e)
{
	int		i;
	int		j;
	t_cy	p;

	j = 0;
	i = -1;
	(void)e;
	while (l[++i])
		if (l[i] == ' ' && l[i + 1] != ' ' && l[i + 1])
			j++;
	if (j != 10 && j != 12)
		error("pb d argument cy");
	i = 0;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	ft_putendl(&l[i + 1]);
	p.p.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.x = (float)ft_atoi2(&l[++i]) / 1000;
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.r = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.z = (float)ft_atoi2(&l[++i]) / 1000;
	if (j == 12)
	{
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
			i++;
		p.h = (float)ft_atoi2(&l[++i]) / 1000;
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
			i++;
		p.b = (float)ft_atoi2(&l[++i]) / 1000;
	}
	else
	{
		p.h = -1;
		p.b = -1;
	}
	p.v = normalisator(p.v);
	cyguardator(&p, -1);
	return (0);
}

int 	corecuperator(char *l, t_env *e)
{
	int		i;
	int		j;
	t_co	p;

	j = 0;
	i = -1;
	(void)e;
	while (l[++i])
		if (l[i] == ' ' && l[i + 1] != ' ' && l[i + 1])
			j++;
	if (j != 10 && j != 12)
		error("pb d argument co");
	i = 0;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	ft_putendl(&l[i + 1]);
	p.p.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.x = (float)ft_atoi2(&l[++i]) / 1000;
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.v.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.a = (float)ft_atoi2(&l[++i]) / 1000 * M_PI;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.z = (float)ft_atoi2(&l[++i]) / 1000;
	if (j == 12)
	{
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
			i++;
		p.h = (float)ft_atoi2(&l[++i]) / 1000;
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
			i++;
		p.b = (float)ft_atoi2(&l[++i]) / 1000;
	}
	else
	{
		p.h = -1;
		p.b = -1;
	}
	p.v = normalisator(p.v);
	coguardator(&p, -1);
	return (0);
}

int 	lightrecuperator(char *l, t_env *e)
{
	int	i;
	int	j;
	t_l	p;

	j = 0;
	i = -1;
	(void)e;
	while (l[++i])
		if (l[i] == ' ' && l[i + 1] != ' ' && l[i + 1])
			j++;
	if (j != 6)
		error("pb d argument light");
	i = 0;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	ft_putendl(&l[i + 1]);
	p.p.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.p.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	p.color.z = (float)ft_atoi2(&l[++i]) / 1000;
	lightguardator(&p, -1);
	return (0);
}

int 	camrecuperator(char *l, t_env *e)
{
	int	i;
	int	j;
	t_p	p;

	j = 0;
	i = -1;
	(void)e;
	while (l[++i])
		if (l[i] == ' ' && l[i + 1] != ' ' && l[i + 1])
			j++;
	if (j != 6)
		error("pb d argument cam");
	i = 0;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	ft_putendl(&l[i + 1]);
	e->o.pos.x = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	e->o.pos.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	e->o.pos.z = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	e->o.dir.x = (float)ft_atoi2(&l[++i]) / 1000;
		while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	e->o.dir.y = (float)ft_atoi2(&l[++i]) / 1000;
	while (!(l[i] == ' ' && l[i + 1] != ' ' && l[i + 1]))
		i++;
	e->o.dir.z = (float)ft_atoi2(&l[++i]) / 1000;
	e->o.dir = normalisator(e->o.dir);
	return (0);
}

int		superparsator(t_env *e)
{
	char *l;

	l = NULL;
	(void)e;
	while (get_next_line(0, &l) > 0)
	{
		ft_putendl("dsd");
		if (!l || l[0] == 0)
			break ;
		else if (l[0] == '#')
			(void)l;
		else if (l[0] == 's' && l[1] == 'p' && l[2] == 'h' && l[3] == 'e' && l[4] == 'r' && l[5] == 'e')
		{
			if (sphererecuperator(l, e))
				break ;
		}
		else if (l[0] == 'p' && l[1] == 'l' && l[2] == 'a' && l[3] == 'n')
		{
			if (planrecuperator(l, e))
				break ;
		}
		else if (l[0] == 'l' && l[1] == 'i' && l[2] == 'g' && l[3] == 'h' && l[4] == 't')
		{
			e->l += 1;
			if (lightrecuperator(l, e))
				break ;
		}
		else if (l[0] == 'c' && l[1] == 'y')
		{
			if (cyrecuperator(l, e))
				break ;
		}
		else if (l[0] == 'c' && l[1] == 'o')
		{
			if (corecuperator(l, e))
				break ;
		}
		else if (l[0] == 'c' && l[1] == 'a' && l[2] == 'm')
		{
			if (camrecuperator(l, e))
				break ;
		}
		else
		{
			break ;
		}
		ft_putendl(l);
		ft_strdel(&l);
		ft_putendl("dsd4");
	}
	ft_putendl("dsd5");
	return (0);
}