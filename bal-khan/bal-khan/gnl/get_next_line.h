/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:49:00 by bal-khan          #+#    #+#             */
/*   Updated: 2015/11/12 17:25:29 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# define BUFFER 10

int		get_next_line(int fd, char **line);
int		ft_read(int const fd, char *buff_rd, char *full[fd]);

#endif
