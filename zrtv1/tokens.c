/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:20:47 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/04/06 23:31:29 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	ignore_whitespaces(char **stream)
{
	while (is_whitespace(**stream))
		++(*stream);
}

int		terminal(t_list **tokens, t_token_type type)
{
	if (*tokens)
		return (get_token(tokens)->type == type);
	return (0);
}

t_token	*get_token(t_list **tokens)
{
	t_token	*token;

	token = (t_token*)((*tokens)->content);
	return (token);
}

void	free_tokens(t_list **tokens)
{
	t_list	*copy;
	t_list	*tmp;

	copy = *tokens;
	while (copy)
	{
		free(get_token(&copy)->lexeme);
		free(copy->content);
		tmp = copy;
		next_elem(&copy);
		free(tmp);
	}
	*tokens = NULL;
}
