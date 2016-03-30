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
	return ((r & 0xff) + ((g & 0xff) << 8) + ((b & 0xff) << 16));
}

t_light			*new_t_light()
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
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

t_vec	normalizator_ret(t_vec vec)
{
	long double	lenght;

	lenght = sqrt(carre(vec.x) + carre(vec.y) + carre(vec.z));
	// if (lenght == 0)
	// 	ft_error("i just saved the universe!");
	if (lenght == 0.0)
		ft_putendl("i just saved the universe!");
	vec.x = vec.x / lenght;
	vec.y = vec.y / lenght;
	vec.z = vec.z / lenght;
	return (vec);
}

void	normalizator(t_vec *vec)
{
	long double	lenght;

	lenght = sqrt(carre(vec->x) + carre(vec->y) + carre(vec->z));
	// if (lenght == 0)
	// 	ft_error("i just saved the universe!");
	if (lenght == 0.0)
		ft_putendl("i just saved the universe!");
	vec->x = vec->x / lenght;
	vec->y = vec->y / lenght;
	vec->z = vec->z / lenght;
}

FLOAT_SIZE	l_color(FLOAT_SIZE i, FLOAT_SIZE a)
{
	return (i * (a / 255));
//	printf("i = %f a = %f\n",i, a);
	if ((i - a) > 0)
		return (i - a);
	return (0);
}

int		comparator_pos(t_inter *inter, t_inter *einter)
{
	if ((inter->pos.x > einter->pos.x - 0.00001 && inter->pos.x < einter->pos.x + 0.00001) 
		&& (inter->pos.y > einter->pos.y - 0.00001 && inter->pos.y < einter->pos.y + 0.00001) 
		&& (inter->pos.z > einter->pos.z - 0.00001 && inter->pos.z < einter->pos.z + 0.00001))
	{
		return (1);
	}
	return (0);
}

void		luminator(t_env *e, t_thr *f)
{
	t_pd			*lvec;
	FLOAT_SIZE		angle;
	// t_inter			inter;
	t_light			*ltmp;
	FLOAT_SIZE		trans;

	//ft_putendl("light");
	ltmp = f->light;
	if (f->inter.t <= 0)
	{
		f->fcolor = 0x000000;
		return ;
	}
	while (f->light != NULL)
	{
	//	ft_putendl("light");
		t_inter_set(&(f->liginter));
		lvec = new_t_pd();
		lvec->pos = f->light->pos;
		lvec->dir = new_t_vec(f->inter.pos.x - f->light->pos.x, f->inter.pos.y - f->light->pos.y, f->inter.pos.z - f->light->pos.z);
		normalizator(&(lvec->dir));
		impactor(e, lvec, f, &(f->liginter));
		//ft_putendl("light 2");
		set_inter_pos(&(f->liginter), lvec);
		if (comparator_pos(&(f->liginter), &(f->inter)) == 0)
		{
			f->light = f->light->next;
			continue;
		}
		//ft_putendl("light 3");
		normalizator(&(f->liginter.norm));
		angle = M_PI_2 - acos(dot_prod(lvec->dir, f->inter.norm));
		angle = (angle > 0) ? angle : -angle;
		//ft_putendl("light 4");
		//printf("%f\n", angle);
		// if (angle > 1.35)
		// {
		// 	//ft_putendl("doublement");
		// 	angle = angle * 1.5;
		// }
		trans = 0;
		if (f->liginter.trans != NULL)
		{
			trans = trans_calculator(f->liginter.trans, f->liginter.t);
		//	f->light->color = transparencator(f->light->color, trans);
		}
		f->fcolor += get_color((angle / 4 * ((f->light->color >> 0) & 0xFF) * 2 / M_PI) * f->liginter.diff.r,
							(angle / 4 * ((f->light->color >> 8) & 0xFF) * 2 / M_PI) * f->liginter.diff.g,
							(angle / 4 * ((f->light->color >> 16) & 0xFF) * 2 / M_PI) * f->liginter.diff.b);
		f->light = f->light->next;
	}
	f->light = ltmp;
	trans = 0;
	if (f->inter.trans != NULL)
	{
		trans = trans_calculator(f->inter.trans, f->inter.t);
		f->fcolor = transparencator(f->fcolor, trans);
	}
		// f->fcolor = get_color(((f->fcolor >> 0) & 0xFF)  * f->inter.colorabs->r / 100,
		// 					((f->fcolor >> 8) & 0xFF)  * f->inter.colorabs->g / 100,
	// 						((f->fcolor >> 16) & 0xFF)  * f->inter.colorabs->b / 100);
	//printf("%d\n", f->fcolor);
	return ;
}
