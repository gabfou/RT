/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:16:43 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/28 23:44:26 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			new_sphere(t_env *env)
{
	t_item	*item;

	item = new_t_item();
	item->sp = new_t_sphere(100, 0, 0, 3);
	// item->mat.diff = new_t_color(1, 1, 1);
	item->next = NULL;
	return (itemadator(env, item));
}

// int		modif_sphere(t_env *env, int i)
// {
// 	t_item		*item;
// 	static int niark = 0;

// 	niark++;
// 	if (i == -2)
// 	{
// 		item = new_t_item();
// 		item->sp = new_t_sphere(100, 0, 0, 3);
// 		item->mat.diff = new_t_color(1, 1, 1);
// 		item->next = NULL; 
// 		// itemadator(env, item);
// 		return (itemadator(env, item));
// 	}
// 	item = env->item;
// 	while(item && i-- > 0)
// 		item = item->next;
// 	if (line[0] == 'x' && line[1] == ' ')
// 		item->sp->c.x = ft_fatoi(&line[2]);
// 	else if (line[0] == 'y' && line[1] == ' ')
// 		item->sp->c.y = ft_fatoi(&line[2]);
// 	else if (line[0] == 'z' && line[1] == ' ')
// 		item->sp->c.z = ft_fatoi(&line[2]);
// 	// else if (ft_strcmp(line, "r") == 0)
// 	// 	rgb.r = token_to_float(tokens);
// 	// else if (ft_strcmp(line, "g") == 0)
// 	// 	rgb.g = token_to_float(tokens);
// 	// else if (ft_strcmp(line, "b") == 0)
// 	// 	rgb.b = token_to_float(tokens);
// 	else if (line[0] == 'r' && line[1] == 'a' && line[2] == 'd' && line[3] == ' ')
// 		item->sp->ray = ft_fatoi(&line[4]);
// 	// else if (ft_strcmp(line, "mat") == 0)
// 	// {
// 	// 	next_elem(tokens);
// 	// 	mat = new_t_mat(get_token(tokens)->lexeme);
// 	// }
// 	return (-1);
// }

void	set_normal_sphere(t_inter *inter, t_item *item)
{
	inter->norm.x = inter->pos.x - item->sp->c.x;
	inter->norm.y = inter->pos.y - item->sp->c.y;
	inter->norm.z = inter->pos.z - item->sp->c.z;
	normalizator(&(inter->norm));
}

t_sphere	*new_t_sphere(FLOAT_SIZE x, FLOAT_SIZE y, FLOAT_SIZE z, FLOAT_SIZE r)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->c = new_t_vec(x, y, z);
	sphere->ray = r;
	return (sphere);
}

void		check_sphere(t_item *item, t_pd *s, t_inter *inter)
{
	FLOAT_SIZE	a;
	FLOAT_SIZE	b;
	FLOAT_SIZE	c;
	FLOAT_SIZE	del;
	FLOAT_SIZE	t;

	// ft_putendl("pre calcul");
	// print_vec(s->dir);
	// print_vec(s->pos);
	// print_vec(item->sp->c);
	a = carre(s->dir.x) + carre(s->dir.y) + carre(s->dir.z);
	b = 2 * (s->dir.x * (s->pos.x - item->sp->c.x) + s->dir.y
	* (s->pos.y - item->sp->c.y) + s->dir.z * (s->pos.z - item->sp->c.z));
//	ft_putendl("pre calcul B");
	c = (carre(s->pos.x - item->sp->c.x) + carre(s->pos.y - item->sp->c.y) +
		carre(s->pos.z - item->sp->c.z)) - carre(item->sp->ray);
	del = carre(b) - (4 * a * c);
//	ft_putendl("post calcul");
	if (del > 0)
	{
		t = ((-b + sqrt(del)) / (2 * a) > (-b - sqrt(del)) / (2 * a))?
		(-b - sqrt(del)) / (2 * a) : (-b + sqrt(del)) / (2 * a);
		if (check_t(inter, t, item->mat.trans, item) == 1)
		{
			set_inter_pos(inter, s);
			set_normal_sphere(inter, item);
		}
	}
//	ft_putendl("post tout ");
	return ;
}
