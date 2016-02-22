/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 18:49:26 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/13 21:39:36 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parse_return(t_list **tokens, t_list *save)
{
	(*tokens) = save;
	return (0);
}

int		parse_properties(t_list **tokens)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0)
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, COLON) == 0)
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, WORD) == 0)
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, COMMA))
	{
		(*tokens) = (*tokens)->next;
		parse_properties(tokens);
	}
	return (1);
}

int		parse_shape(t_list **tokens)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0)
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, OPENING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	if (parse_properties(tokens) == 0)
		return (0);
	if (terminal(tokens, CLOSING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	return (1);
}

int		parse_light(t_list **tokens)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0 || ft_strcmp(get_token(tokens)->lexeme, "light"))
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, OPENING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	if (parse_properties(tokens) == 0)
		return (0);
	if (terminal(tokens, CLOSING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	return (1);
}

int		parse_camera(t_list **tokens)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0 || ft_strcmp(get_token(tokens)->lexeme, "camera"))
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, OPENING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	if (parse_properties(tokens) == 0)
		return (0);
	if (terminal(tokens, CLOSING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	return (1);
}

int		parse_window(t_list **tokens)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0 || ft_strcmp(get_token(tokens)->lexeme, "window"))
	{
		(*tokens) = save;
		return (0);
	}
	(*tokens) = (*tokens)->next;
	if (terminal(tokens, OPENING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	if (parse_properties(tokens) == 0)
		return (0);
	if (terminal(tokens, CLOSING_BRACKET) == 0)
		return (0);
	(*tokens) = (*tokens)->next;
	return (1);
}


int		parse_object(t_list **tokens)
{
	while (parse_light(tokens))
		continue ;
	while (parse_shape(tokens))
		continue ;
	return (1);
}

int		parse_scene(t_list **tokens)
{
	if (parse_camera(tokens) == 0)
		return (0);
	if (parse_window(tokens) == 0)
		return (0);
	return (1);
}

int		parse_exp(t_list **tokens)
{
	if (parse_scene(tokens) == 0)
		return (0);
	if (parse_object(tokens) == 0)
		return (0);
	return (1);
}
