/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 23:08:44 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 23:08:45 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned int	get_color(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

t_light			*new_t_light()
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->pos = NULL;
	light->color = 0;
	light->next = NULL;
	return (light);
}

t_light			*fill_t_light(char **t, t_light *light)
{
	light->pos = new_t_vec(ft_fatoi(t[1]), ft_fatoi(t[2]), ft_fatoi(t[3]));
	light->color = get_color(ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]));
	light->next = NULL;
	return (light);
}

t_vec	*normalizator_ret(t_vec *vec)
{
	double	lenght;

	lenght = sqrt(carre(vec->x) + carre(vec->y) + carre(vec->z));
	if (lenght == 0)
		ft_error("i just saved the universe!");
	vec->x = vec->x / lenght;
	vec->y = vec->y / lenght;
	vec->z = vec->z / lenght;
	return (vec);
}

void	normalizator(t_vec *vec)
{
	double	lenght;

	lenght = sqrt(carre(vec->x) + carre(vec->y) + carre(vec->z));
	if (lenght == 0)
		ft_error("i just saved the universe!");
	vec->x = vec->x / lenght;
	vec->y = vec->y / lenght;
	vec->z = vec->z / lenght;
}

double	l_color(double i, double a)
{
	return (i * (a / 255));
//	printf("i = %f a = %f\n",i, a);
	if ((i - a) > 0)
		return (i - a);
	return (0);
}

int		comparator_pos(t_inter *inter, t_inter *einter)
{
	if ((inter->pos->x > einter->pos->x - 0.0000001 && inter->pos->x < einter->pos->x + 0.0000001) 
		&& (inter->pos->y > einter->pos->y - 0.0000001 && inter->pos->y < einter->pos->y + 0.0000001) 
		&& (inter->pos->z > einter->pos->z - 0.0000001 && inter->pos->z < einter->pos->z + 0.0000001))
	{
		return (1);
	}
	return (0);
}

void		luminator(t_env *e)
{
	t_pd			*lvec;
	float			angle;
	t_inter			*inter;
	t_light			*ltmp;

	ltmp = e->light;
	if (e->inter->t <= 0)
	{
		e->fcolor = 0x000000;
		return ;
	}
	while (e->light != NULL)
	{
		inter = new_t_inter();
		lvec = new_t_pd();
		lvec->pos = e->light->pos;
		lvec->dir = new_t_vec(e->inter->pos->x - e->light->pos->x, e->inter->pos->y - e->light->pos->y, e->inter->pos->z - e->light->pos->z);
		normalizator(lvec->dir);
		impactor(e, lvec, inter);
		set_inter_pos(inter, lvec);
		if (comparator_pos(inter, e->inter) == 0)
		{
			e->light = e->light->next;
			//e->fcolor = 0xFF0000;
			continue;
		}
		normalizator(inter->norm);
			angle = M_PI_2 - acos(dot_prod(lvec->dir, e->inter->norm));
			angle = (angle > 0) ? angle : -angle;
			e->fcolor += get_color(angle / 4 * ((e->light->color >> 0) & 0xFF) * 2 / M_PI,
								   angle / 4 * ((e->light->color >> 8) & 0xFF) * 2 / M_PI,
								   angle / 4 * ((e->light->color >> 16) & 0xFF) * 2 / M_PI);
		e->light = e->light->next;
	}
	e->light = ltmp;
	return ;
}
