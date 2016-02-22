/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:03:02 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/06 21:34:31 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			access_file(char *file)
{
	int	fd;

	if (access(file, F_OK))
		fatal_error(RAYTRACER, ERR_NO_DIR, 0);
	if (access(file, R_OK))
		fatal_error(RAYTRACER, ERR_PERMISSION_DENIED, 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		fatal_error(RAYTRACER, ERR_INACCESSIBLE, 0);
	return (fd);
}

int			main(int argc, char **argv)
{
	int		line_number;
	int		fd;
	char	*line;
	t_list	*tokens;

	if (argc < 2)
		fatal_error(RAYTRACER, ERR_TOO_FEW_ARGS, 0);
	if (argc > 2)
		fatal_error(RAYTRACER, ERR_TOO_MANY_ARGS, 0);
	line_number = 1;
	fd = access_file(argv[1]);
	while (get_next_line(fd, &line))
	{
		ft_lstappend(&tokens, tokenize(line, line_number));
		line_number++;
		free(line);
	}
	if (parse_exp(&tokens) && tokens == NULL)
		ft_putendl("PARSE WIN");
	else
	{
		WRITE(2, "Parse fail near : '");
		ft_putstr_fd(get_token(&tokens)->lexeme, 2);
		WRITE(2, "' at line ");
		ft_putnbr_fd(get_token(&tokens)->line, 2);
		ft_putchar('\n');
	}
	return (0);
}
