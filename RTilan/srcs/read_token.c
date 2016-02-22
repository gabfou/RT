/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:13:05 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/06 23:36:15 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#define DEBUG	ft_putendl(__func__);

static int	is_word_char(char c)
{
	return (ft_isalnum(c) || ft_strchr(WORD_CHARS, c));
}

static int			read_symbol(char **stream, t_token *token)
{
	size_t				i;
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



static int			read_word(char **stream, t_token *token)
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

int			read_token(char **stream, t_token *token, int line_number)
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
	while (i < sizeof(stream_readers) / sizeof(t_stream_reader))
	{
		if (stream_readers[i](stream, token))
		{
			token->line = line_number;
			return (1);
		}
		++i;
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
		ft_putstr_fd("Syntax error near : '", 2);
		if (token.lexeme)
			ft_putstr_fd(token.lexeme, 2);
		else
			ft_putstr_fd("Start", 2);
		ft_putstr_fd("' line ", 2);
		ft_putnbr_fd(token.line, 2);
		ft_putchar_fd('\n', 2);
		exit (0);
	}
	return (tokens);
}
