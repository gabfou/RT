/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 21:03:02 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/27 21:03:04 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_sphere(t_env *env, t_list **tokens)
{
	t_item		*item;

	item = new_t_item(env);
	item->sp = new_t_sphere(0, 0, 0, 0);
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			item->sp->c.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			item->sp->c.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			item->sp->c.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rad") == 0)
			item->sp->ray = token_to_float(tokens);
		else
			initmat(tokens, item);
		next_elem(tokens);
	}
	//env->nb_obj++;
	itemadator(env, item);
}

void		init_plane(t_env *env, t_list **tokens)
{
	t_item		*item;

	item = new_t_item(env);
	item->pl = t_plane_creator(new_t_vec(0, 0, 0), new_t_vec(1, 0, 0), 0);
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			item->pl->pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			item->pl->pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			item->pl->pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rad") == 0)
			item->pl->ray = token_to_float(tokens);
		normform(tokens, &(item->pl->dir), item);
		next_elem(tokens);
	}
	normalizator(&(item->pl->dir));
	env->infitem++;
	itemadator(env, item);
}

void		init_cone(t_env *env, t_list **tokens)
{
	t_item		*item;

	item = new_t_item(env);
	item->con = t_con_creator(new_t_vec(0, 0, 0), new_t_vec(0, 0, 1), 0);
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			item->con->pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			item->con->pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			item->con->pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "angle") == 0)
			item->con->ang = token_to_float(tokens) / 180 * M_PI;
		normform(tokens, &(item->con->dir), item);
		next_elem(tokens);
	}
	normalizator(&(item->con->dir));
	env->infitem++;
	itemadator(env, item);
}

void		init_cyl(t_env *env, t_list **tokens)
{
	t_item		*item;

	item = new_t_item(env);
	item->cyl = t_cyl_creator(new_t_vec(0, 0, 0), new_t_vec(0, 0, 1), 1);
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			item->cyl->pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			item->cyl->pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			item->cyl->pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rad") == 0)
			item->cyl->ray = token_to_float(tokens);
		normform(tokens, &(item->cyl->dir), item);
		next_elem(tokens);
	}
	normalizator(&(item->cyl->dir));
	env->infitem++;
	itemadator(env, item);
}

void	init_tr(t_env *env, t_list **tokens)
{
	t_item		*item;

	item = new_t_item(env);
	item->tr = new_t_triangle();
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x1") == 0)
			item->tr->p1.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y1") == 0)
			item->tr->p1.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z1") == 0)
			item->tr->p1.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "x2") == 0)
			item->tr->p2.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y2") == 0)
			item->tr->p2.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z2") == 0)
			item->tr->p2.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "x3") == 0)
			item->tr->p3.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y3") == 0)
			item->tr->p3.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z3") == 0)
			item->tr->p3.z = token_to_float(tokens);
		else
			initmat(tokens, item);
		next_elem(tokens);
	}
	set_triangle(item->tr);
	itemadator(env, item);
}

void	init_obj(t_env *env, t_list **tokens)
{
	t_item		*item;
	t_item		*tmp;
	t_vec		vec;

	item = new_t_item(env);
	vec = new_t_vec(0, 0, 0);
	item->obj = initobj(item->obj);
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "obj") == 0)
		{
			next_elem(tokens);
			item->obj = objreader(get_token(tokens)->lexeme, item->obj, env);
		}
		else if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			vec.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			vec.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			vec.z = token_to_float(tokens);
		next_elem(tokens);
	}
	tmp = item->obj->tr;
	while(tmp)
	{
		tmp->tr->p1 = add_vec(tmp->tr->p1, vec);
		tmp->tr->p2 = add_vec(tmp->tr->p2, vec);
		tmp->tr->p3 = add_vec(tmp->tr->p3, vec);
		tmp = tmp->next;
	}
	itemadator(env, item);
}
