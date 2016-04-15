/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initauxi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:53:34 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/06 23:31:34 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		print_tokens(t_list *tokens)
{
	while (tokens)
	{
		ft_putendl(get_token(&tokens)->lexeme);
		next_elem(&tokens);
	}
}

int			access_file(int argc, char *argv)
{
	int	fd;

	(void)argc;
	if (access(argv, F_OK))
		fatal_error(RAYTRACER, ERR_NO_DIR, 0);
	if (access(argv, R_OK))
		fatal_error(RAYTRACER, ERR_PERMISSION_DENIED, 0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		fatal_error(RAYTRACER, ERR_INACCESSIBLE, 0);
	return (fd);
}

t_list		*get_tokens(int fd)
{
	int		line_number;
	char	*line;
	t_list	*tokens;

	line_number = 1;
	tokens = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
			ft_lstappend(&tokens, tokenize(line, line_number));
		line_number++;
		free(line);
	}
	return (tokens);
}

void		delete_symbols(t_list **tokens)
{
	t_list	*copy;
	t_list	*tmp;

	copy = *tokens;
	while (copy->next)
	{
		if (!terminal(&copy->next, WORD)
			&& !terminal(&copy->next, CLOSING_BRACKET))
		{
			tmp = copy->next;
			if (copy->next->next)
				copy->next = copy->next->next;
			else
				copy->next = NULL;
			free(get_token(&tmp)->lexeme);
			free(tmp->content);
			free(tmp);
		}
		if (copy->next)
			next_elem(&copy);
		else
			break ;
	}
}

FLOAT_SIZE	token_to_float(t_list **tokens)
{
	next_elem(tokens);
	return (ft_fatoi(get_token(tokens)->lexeme));
}
