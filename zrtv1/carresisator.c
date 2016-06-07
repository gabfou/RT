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

t_carre		*new_t_carrespe(FLOAT_SIZE size, t_vec pos)
{
	// static int	cnb = 1;
	t_carre		*carre;

	carre = (t_carre*)malloc(sizeof(t_carre));
	if (size == 0)
		ft_putendl("dafuq?");
	carre->cnb = NULL;
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
	return (carre);
}

t_carre		*divisecarrerisatorauxi(t_carre *tmp, t_carre *c2)
{
	FLOAT_SIZE	size;

	size = c2->size / 2.0;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + size, c2->pos.y, c2->pos.z));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x, c2->pos.y + size, c2->pos.z));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + size, c2->pos.y + size, c2->pos.z));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x, c2->pos.y, c2->pos.z + size));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + size, c2->pos.y, c2->pos.z + size));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x, c2->pos.y + size, c2->pos.z + size));
	tmp = tmp->next;
	tmp->next = new_t_carrespe(size,
		new_t_vec(c2->pos.x + size, c2->pos.y + size, c2->pos.z + size));
	return (tmp->next);
}

t_carre		*divisecarrerisator(t_carre *c2, t_env *env)
{
	t_carre	*c;
	t_carre	*tmp;

	tmp = env->carre;
	c = new_t_carrespe(c2->size / 2.0,
		new_t_vec(c2->pos.x, c2->pos.y, c2->pos.z));
	if (env->carre == c2)
		env->carre = c;
	else
	{
		while (tmp && tmp->next != c2)
			tmp = tmp->next;
		tmp->next = c;
	}
	tmp = c;
	if (tmp == NULL)
		ft_putendl("dafuq3");
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
	int		test;
	int		test2;
	int		test3;
	t_carre	*tmp;

	ft_putendl("carresisator");
	// env->nb_obj = env->nb_obj / 100 + 30;
	i = -1;
	test3 = env->nb_obj * 1.5 + 5;
	test2 = env->nb_obj / 10 + 30;
	env->carre = new_t_carrespe(1000000, new_t_vec(-500000, -500000, -500000));
	c = env->carre;
	while (c && i < NB_CARRE - 17)
	{
		if ((test = impactcarre(c, env, 0)) > test2 && c->size > 1)
		{
			// if (!(test3 > test * 1.4))
			// {
			// 	test3 = env->nb_obj * 1.5 + 5;
			// 	c = c->next;
			// 	continue;
			// }
			i += 7;
			// printf("test = %d\n", test);
			c = divisecarrerisator(c, env);
			test3 = test;
			// break;
		}
		// else if (test > test2)
		// {
		// 	test2 = env->nb_obj * 1.5 + 5;
		// 	c = c->next;
		// }
		else
		{
			// if (c->next && c->size < c->next->size)
			// 	test3 = -1;
			// test2 = test;
			c = c->next;
		}
	}
	c = env->carre;
	tmp = NULL;
	env->nb_carre = 0;
	ft_putnbr(i);
	while (c)
	{
		impactcarre(c, env, 1);
		if (c->cnb == NULL && tmp)
		{
			tmp->next = c->next;
			free(c);
			c = tmp->next;
		}
		else
		{
			env->nb_carre++;
			tmp = c;
			c = c->next;
		}
	}
	print_carre(*env);
	ft_putnbr(env->nb_obj);
	ft_putendl("carresisatorfin");
}
