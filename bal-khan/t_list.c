/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:40:34 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:40:36 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	*node_constructor(char *line)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (!ret)
		exit(0);
	parsor(line, &ret);
	return (ret);
}

t_list	*recur_list_build(int fd, t_list *prev)
{
	char		*line;
	t_list		*ret;
	int			check;

	(void)prev;
	line = NULL;
	check = 0;
	if ((check = get_next_line(fd, &line)) == 0)
		exit(0);
	ret = node_constructor(line);
	ret->prev = NULL;
	while (((check = get_next_line(fd, &line))) || ft_strlen(line))
	{
		ret->next = node_constructor(line);
		ret->next->prev = ret;
		ret = ret->next;
	}
	ret->next = NULL;
	while (ret->prev)
		ret = ret->prev;
	return (ret);
}

int		ft_array_len(char **des_ints)
{
	int	ret;

	ret = 0;
	while (des_ints[ret])
	{
		ret++;
	}
	return (ret);
}

void	fill_with_tab(char **des_ints, t_list **ret)
{
	int	len_tab;

	len_tab = ft_array_len(des_ints);
	if ((6 != len_tab) && (7 != len_tab))
	{
		ft_putendl("bad number of args");
		exit(0);
	}
	(*ret)->center.x = ft_atoi(des_ints[0]);
	(*ret)->center.y = ft_atoi(des_ints[1]);
	(*ret)->center.z = ft_atoi(des_ints[2]);
	(*ret)->orient.x = ft_atoi(des_ints[3]);
	(*ret)->orient.y = ft_atoi(des_ints[4]);
	(*ret)->orient.z = ft_atoi(des_ints[5]);
	(*ret)->orient = normalizator((*ret)->orient);
	(*ret)->radiangle = (len_tab == 7) ? (ft_atoi(des_ints[6])) : (0);
}

void	parsor(char *line, t_list **ret)
{
	char	**des_ints;
	char	*to_free;

	if (('a' != line[0]) && ('b' != line[0]) && ('c' != line[0])
		&& ('d' != line[0]) && ('l' != line[0]))
	{
		ft_putendl("invalid file");
		exit(0);
	}
	else
	{
		(*ret)->type = line[0];
		to_free = ft_strdup(line);
		line = ft_strsub(to_free, 2, ft_strlen(to_free) - 1);
		des_ints = ft_strsplit(line, ' ');
		free(line);
		free(to_free);
		fill_with_tab(des_ints, ret);
	}
}
