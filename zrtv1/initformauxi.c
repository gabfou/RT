/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initauxi4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 22:16:24 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/29 22:16:26 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define NORMEIA4 item->obj = initobj(item->obj);item->mat = new_t_mat("niark")

void	normform(t_list **tokens, t_vec *dir, t_item *item)
{
	if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
		dir->x = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
		dir->y = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
		dir->z = token_to_float(tokens);
	else
		initmat(tokens, item);
}

void	init_obj_aux(t_item *item, t_vec vec, t_env *env)
{
	t_item *tmp;

	tmp = item->obj->tr;
	while (tmp)
	{
		tmp->tr->p1 = add_vec(tmp->tr->p1, vec);
		tmp->tr->p2 = add_vec(tmp->tr->p2, vec);
		tmp->tr->p3 = add_vec(tmp->tr->p3, vec);
		tmp->mat = item->mat;
		tmp = tmp->next;
	}
	itemadator(env, item);
}

void	init_obj(t_env *env, t_list **tokens)
{
	t_item		*item;
	t_vec		vec;

	item = new_t_item(env);
	vec = new_t_vec(0, 0, 0);
	NORMEIA4;
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
		else
			initmat(tokens, item);
		next_elem(tokens);
	}
	init_obj_aux(item, vec, env);
}

void	init_tr_aux(t_list **tokens, t_item *item)
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
}

void	init_tr(t_env *env, t_list **tokens)
{
	t_item		*item;

	item = new_t_item(env);
	item->tr = new_t_triangle();
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		init_tr_aux(tokens, item);
		next_elem(tokens);
	}
	set_triangle(item->tr);
	itemadator(env, item);
}
