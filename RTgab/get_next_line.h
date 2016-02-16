/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 20:58:42 by gfournie          #+#    #+#             */
/*   Updated: 2015/08/17 20:58:48 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# include <stdlib.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int const fd, char **line);
int		retournator(char **str, char **line);
int		ft_gnl_len(char *str);

#endif
