/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:18:43 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/02/25 22:45:10 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		next_elem(t_list **elems)
{
	*elems = (*elems)->next;
}

static int	is_word_char(char c)
{
	return (ft_isalnum(c) || ft_strchr(WORD_CHARS, c));
}

static int	read_symbol(char **stream, t_token *token)
{
	size_t			i;
	static t_symbol	symbols[] = {
					{OPENING_BRACKET, '{'},
					{CLOSING_BRACKET, '}'},
					{COMMA, ','},
					{COLON, ':'}
	};

	i = 0;
	while (i < sizeof(symbols) / sizeof(t_symbol))
	{
		if (**stream == symbols[i].c)
		{
			(*stream)++;
			token->type = symbols[i].type;
			token->lexeme = ft_strsub((*stream) - 1, 0, 1);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	read_word(char **stream, t_token *token)
{
	char	*save;

	save = *stream;
	while (**stream && is_word_char(**stream))
		++(*stream);
	if ((*stream - save) == 0)
	{
		*stream = save;
		return (0);
	}
	token->type = WORD;
	token->lexeme = ft_strsub(save, 0, (*stream) - save);
	return (1);
}

static int	read_token(char **stream, t_token *token, int line_number)
{
	size_t					i;
	static t_stream_reader	stream_readers[] =
	{
		read_symbol,
		read_word
	};

	ignore_whitespaces(stream);
	if (!**stream)
		return (0);
	i = 0;
	token->line = line_number;
	while (i < sizeof(stream_readers) / sizeof(t_stream_reader))
	{
		if (stream_readers[i](stream, token))
			return (1);
		i++;
	}
	return (-1);
}

t_list		*tokenize(char *string, int line_number)
{
	t_list	*tokens;
	t_token	token;
	int		ret;

	tokens = 0;
	while ((ret = read_token(&string, &token, line_number)) == 1)
		ft_lstappend(&tokens, ft_lstnew(&token, sizeof(t_token)));
	if (ret == -1)
	{
		ft_putstr_fd("Syntax error near : '", STDERR);
		if (token.lexeme)
			ft_putstr_fd(token.lexeme, STDERR);
		else
			ft_putstr_fd("Start", STDERR);
		ft_putstr_fd("' line ", STDERR);
		ft_putnbr_fd(token.line, STDERR);
		WRITE(STDERR, "\n");
		exit (0);
	}
	return (tokens);
}
