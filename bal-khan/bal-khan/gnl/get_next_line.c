/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:48:47 by bal-khan          #+#    #+#             */
/*   Updated: 2015/07/28 15:48:53 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char	*full[256];
	char		*buff_rd;
	char		*temp_rd;
	int			read_ret;

	buff_rd = ft_strnew(BUFFER);
	if (fd < 0 || line == NULL || buff_rd == NULL)
		return (-1);
	if (full[fd] == NULL)
		full[fd] = ft_strnew(1);
	read_ret = ft_read(fd, buff_rd, full);
	if (read_ret == -1)
		return (-1);
	if (read_ret == 0)
	{
		*line = full[fd];
		full[fd] = NULL;
		return (0);
	}
	*line = ft_strsub(full[fd], 0, (ft_strchr(full[fd], '\n')) - full[fd]);
	temp_rd = full[fd];
	full[fd] = ft_strdup(ft_strchr(full[fd], '\n') + 1);
	ft_strdel(&temp_rd);
	return (1);
}

int				ft_read(int const fd, char *buff_rd, char *full[fd])
{
	char		*temp_rd;
	char		*latent;
	int			read_ret;

	read_ret = 0;
	while (!(latent = ft_strchr(full[fd], '\n'))
			&& (read_ret = read(fd, buff_rd, BUFFER)) > 0)
	{
		buff_rd[read_ret] = '\0';
		temp_rd = full[fd];
		full[fd] = ft_strjoin(temp_rd, buff_rd);
		ft_strdel(&temp_rd);
	}
	ft_strdel(&buff_rd);
	free(buff_rd);
	if (read_ret < 0)
		return (-1);
	if (read_ret == 0 && !latent)
		return (0);
	return (1);
}
