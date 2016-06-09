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
