/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 20:43:34 by gfournie          #+#    #+#             */
/*   Updated: 2015/08/17 20:43:36 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		retournator(char **str, char **line)
{
	char	*tmp;
	char	*tmp2;

	tmp = *str;
	tmp2 = ft_strsub(*str, 0, ft_gnl_len(*str));
	*line = ft_strdup(tmp2);
	*str = ft_strdup(*str + ft_gnl_len(*str) + 1);
	//ft_strdel(&tmp);
	//ft_strdel(&tmp2);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *str[256];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (line == NULL)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	while (1)
	{
		if (ft_strchr(str[fd], '\n'))
			return (retournator(&str[fd], line));
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = str[fd];
		str[fd] = (ret >= 0) ? ft_strjoin(str[fd], buf) : str[fd];
		ft_strdel(&tmp);
		if (ret <= 0)
		{
			*line = ft_strdup(str[fd]);
			ft_strdel(&str[fd]);
			return (ret);
		}
	}
}
