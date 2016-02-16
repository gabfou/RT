/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_endl_in_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:14:51 by gfournie          #+#    #+#             */
/*   Updated: 2015/06/05 16:14:53 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

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
