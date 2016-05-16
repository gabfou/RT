/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 20:28:25 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/30 20:28:27 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define LIMIT 200000

#define ISWHITESPACE (*line == '\v' || *line == '\t'  || *line == '\r' \
 || *line == '\f' || *line == ' ')

t_vec	newobjvect(char *line)
{
	t_vec v;

	while(ISWHITESPACE)
		line++;
	v.x = ft_fatoi(line);
	while(!(ISWHITESPACE || *line == '\0'))
		line++;
	while(ISWHITESPACE)
		line++;
	v.y = ft_fatoi(line);
	while(!(ISWHITESPACE || *line == '\0'))
		line++;
	while(ISWHITESPACE)
		line++;
	v.z = ft_fatoi(line);
	return (v);
}

void	additem(t_obj *obj, t_item *item)
{
	t_item		*copy;

	if (!(obj->tr))
		obj->tr = item;
	else
	{
		copy = obj->tr;
		while (copy->next)
			copy = copy->next;
		copy->next = item;
	}
}

void	newtriangleobj(t_obj *obj, char *line, t_vec *v)
{
	int		i;
	t_item	*tr;

	tr = new_t_item();
	tr->tr = new_t_triangle();
	while(ISWHITESPACE)
		line++;
	if((i = ft_fatoi(line)) > 0 && i < LIMIT)
		tr->tr->p1 = v[i];
	while(!(ISWHITESPACE || *line == '\0'))
		line++;
	while(ISWHITESPACE)
		line++;
	if((i = ft_fatoi(line)) > 0 && i < LIMIT)
		tr->tr->p2 = v[i];
	while(!(ISWHITESPACE || *line == '\0'))
		line++;
	while(ISWHITESPACE)
		line++;
	if((i = ft_fatoi(line)) > 0 && i < LIMIT)
		tr->tr->p3 = v[i];
	i = 0;
	set_triangle(tr->tr);
	additem(obj, tr);
}

t_obj	*initobj(t_obj *obj)
{
	obj = malloc(sizeof(obj));
	obj->tr = NULL;
	return (obj);
}

t_obj	*objreader(char *name, t_obj *obj)
{
	int		fd;
	char	*line;
	t_vec	*v;
	int		i;

	fd = open(name, O_RDONLY);
	v = malloc(sizeof(v) * (LIMIT + 1));
	if (fd == -1)
		ft_error("pas de .obj");
	line = NULL;
	i = 1;
	while(get_next_line(fd, &line) > 0 && i < LIMIT)
	{
		if (line[0] != 'v' && line[0] != 'f')
		{
			free(line);
			continue ;
		}
		if (line[0] == 'v' && line[1] == ' ')
			v[i++] = newobjvect(&line[1]);
		else if (line[0] == 'f' && line[1] == ' ')
			newtriangleobj(obj, &line[1], v);
		free(line);
	}
	// t_item *tmp;
	// tmp = obj->tr;
	// while(tmp)
	// {
	// 	printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", tmp->tr->p1.x, tmp->tr->p1.y, tmp->tr->p1.z, tmp->tr->p2.x, tmp->tr->p2.y, tmp->tr->p2.z, tmp->tr->p3.x, tmp->tr->p3.y, tmp->tr->p3.z);
	// 	tmp = tmp->next;
	// }
	free(v);
	return(obj);
}
