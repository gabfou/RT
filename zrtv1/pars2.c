/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 17:36:31 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/09 20:53:49 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


t_item			*new_t_item()
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->pl = NULL;
	item->sp = NULL;
	item->cyl = NULL;
	item->con = NULL;
	item->next = NULL;
	item->idc = 1;
	item->cnb = NULL;
	item->mat = new_t_mat("niark");
	return(item);
}

void			check_check(t_check check)
{
	if (check.cam == 0)
		ft_error("ray charles");
	if (check.item == 0)
		ft_error("no toy");
	if (check.light == 0)
		ft_error("the sun is broken");
}

int				tlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char			**file_to_tab(char *name)
{
	int		fd;
	int		ret;
	char	**file;
	char	*tmp;
	char	b[1024];

	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	tmp = ft_strdup("");
	ft_bzero(b, sizeof(b));
	while ((ret = read(fd, b, sizeof(b))) > 0)
	{
		b[ret] = '\n';
		tmp = ft_strjoin(tmp, b);
		ft_bzero(b, sizeof(b));
	}
	file = ft_strsplit(tmp, '\n');
	return (file);
}
