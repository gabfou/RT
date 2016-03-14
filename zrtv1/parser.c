/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:19:21 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/03/14 23:38:08 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		parse_return(t_list **tokens, t_list *save)
{
	(*tokens) = save;
	return (0);
}

int		parse_properties(t_list **tokens, t_env *par)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0)
		return (parse_return(tokens, save));
	next_elem(tokens);
	if (terminal(tokens, COLON) == 0)
		return (parse_return(tokens, save));
	next_elem(tokens);
	if (terminal(tokens, WORD) == 0)
		return (parse_return(tokens, save));
	next_elem(tokens);
	if (terminal(tokens, COMMA))
	{
		next_elem(tokens);
		parse_properties(tokens, par);
	}
	return (1);
}

int		parse_shape(t_list	**tokens, t_env *par)
{
	t_list	*save;

	save = *tokens;
	if (terminal(tokens, WORD) == 0)
		return (parse_return(tokens, save));
	next_elem(tokens);
	if (terminal(tokens, OPENING_BRACKET) == 0)
		return (0);
	next_elem(tokens);
	if (parse_properties(tokens, par) == 0)
		return (0);
	if (terminal(tokens, CLOSING_BRACKET) == 0)
		return (0);
	next_elem(tokens);
	return (1);
}

int		parse_exp(t_list **tokens, t_env *par)
{
	while (parse_shape(tokens, par))
		continue ;
	return (1);
}
