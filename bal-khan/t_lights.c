/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lights.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:40:22 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:40:25 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	*recur_lights_build(int fd, t_list *prev)
{
	char		*line;
	t_list		*ret;
	int			check;

	(void)prev;
	line = NULL;
	check = 0;
	ret = NULL;
	if ((check = get_next_line(fd, &line)) == 0)
		exit(0);
	if (line[0] == 'l')
	{
		ret = node_constructor(line);
		ret->prev = NULL;
	}
	while (((check = get_next_line(fd, &line))) || ft_strlen(line))
	{
		ret = norminator(line, ret);
	}
	if (!ret)
		exit(0);
	ret->next = NULL;
	while (ret->prev)
		ret = ret->prev;
	return (ret);
}

t_list	*norminator(char *line, t_list *ret)
{
	if (line[0] == 'l' && !ret)
	{
		ret = node_constructor(line);
		ret->prev = NULL;
	}
	else if (line[0] == 'l' && ret)
	{
		ret->next = node_constructor(line);
		ret->next->prev = ret;
		ret = ret->next;
	}
	return (ret);
}
