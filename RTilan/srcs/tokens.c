/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:12:17 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/06 22:21:15 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	ignore_whitespaces(char **stream)
{
	while (is_whitespace(**stream))
		++(*stream);
}

int			terminal(t_list **tokens, t_token_type type)
{
	if (*tokens)
		return (get_token(tokens)->type == type);
	return (0);
}

t_token		*get_token(t_list **tokens)
{
	t_token	*token;

	token = (t_token *)((*tokens)->content);
	return (token);
}

void		free_token(void *p_token, size_t size)
{
	t_token	*token;

	UNUSED(size);
	token = (t_token *)p_token;
	free(token->lexeme);
	free(token);
}
