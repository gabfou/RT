/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:16:26 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:16:27 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_bzero(char *b, int i)
{
	while (i >= 0)
	{
		if (b[i] == '\0')
			return (1);
		i--;
	}
	return (0);
}

int		la_magicienne(char *name)
{
	int		fd;
	char	b[16000];
	int		ret;
	int		i;
	int		l;

	errno = 0;
	l = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, b, sizeof(b))) > 0)
	{
		if (check_bzero(b, ret - 1) == 1)
			ft_error("yameteee!");
		i = -1;
		while (++i <= ret)
		{
			if (b[i] == '\n')
				l++;
		}
		b[ret] = '\0';
	}
	close(fd);
	return (l);
}

void		put_endl_in_file(char *name)
{
	int		fd;
	int		errno;
	char	buf[9];
	int		ret;

	errno = 0;
	if ((fd = open(name, O_RDWR | O_APPEND)) == -1)
		ft_error("error");
	while ((ret = read(fd, buf, 8)) > 0)
		buf[ret] = '\0';
	ret = ft_strlen(buf);
	if (buf[ret - 1] != '\n')
		ft_putstr_fd("\n", fd);
}

void			recuperator(t_env *e, char *name)
{
	int		l;
	(void)e;

	put_endl_in_file(name);
	l = la_magicienne(name);
	//mega_initiator(e, name);
}
