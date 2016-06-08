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
	unsigned int	ret;
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
//	printf("\n%d %d %d\n", r, g, b);
	ret = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
//	printf("%d\n", ret);
	return (ret);
}

t_light			*new_t_light()
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
	light->photon = 10000;
	light->rcolor = new_t_color(0, 0, 0);
	light->next = NULL;
	return (light);
}

t_light			*fill_t_light(char **t, t_light *light)
{
	light->pos = new_t_vec(ft_fatoi(t[1]), ft_fatoi(t[2]), ft_fatoi(t[3]));
	light->rcolor.r = ft_fatoi(t[4]);
	light->rcolor.g = ft_fatoi(t[5]);
	light->rcolor.b = ft_fatoi(t[6]);
	light->next = NULL;
	return (light);
}

FLOAT_SIZE	l_color(const FLOAT_SIZE i, const FLOAT_SIZE a)
{
	return (i * (a / 255));
//	printf("i = %f a = %f\n",i, a);
	// if ((i - a) > 0)
	// 	return (i - a);
	// return (0);
}

int		comparator_pos(const t_inter *inter, const t_inter *einter)
{
	if ((inter->pos.x > einter->pos.x - 0.00001 && inter->pos.x < einter->pos.x + 0.00001) 
		&& (inter->pos.y > einter->pos.y - 0.00001 && inter->pos.y < einter->pos.y + 0.00001) 
		&& (inter->pos.z > einter->pos.z - 0.00001 && inter->pos.z < einter->pos.z + 0.00001))
	{
		return (1);
	}
	return (0);
}

t_color		lumi_calc(t_thr *f, t_pd *lvec, FLOAT_SIZE angle[2], t_color color)
{
	angle[0] = M_PI_2 - acos(dot_prod(lvec->dir, f->inter.norm));
	angle[1] = pow(dot_prod(lvec->dir, f->inter.norm), 50);
	angle[0] = (angle[0] > 0) ? angle[0] : -angle[0];
	angle[1] = (angle[1] > 0) ? angle[1] : -angle[1];
	color.r = ((angle[0] / 4 * ((f->light->rcolor.r))* 2 / M_PI) +
	 (angle[1] / 4 * ((f->light->rcolor.r))* 2 / M_PI)) * f->liginter.diff.b + 
	(color.r),

	color.g =((angle[0] / 4 * ((f->light->rcolor.g))* 2 / M_PI) + (angle[1] / 4 * ((f->light->rcolor.g))* 2 / M_PI)) *
	 f->liginter.diff.g + (color.g),

	 color.b =((angle[0] / 4 * ((f->light->rcolor.b))* 2 / M_PI) + (angle[1] / 4 * 
	 	((f->light->rcolor.b))* 2 / M_PI)) * f->liginter.diff.r + (color.b);
	return (color);
}

void		lumi_auxi(t_thr *f, t_pd *lvec)
{
	t_inter_set(&f->liginter);
	lvec->pos = f->light->pos;
	lvec->dir = new_t_vec(f->inter.pos.x - f->light->pos.x, f->inter.pos.y
	- f->light->pos.y, f->inter.pos.z - f->light->pos.z);
	normalizator(&lvec->dir);
	impactor(lvec, f->item, &f->liginter);
	set_inter_pos(&f->liginter, lvec);
}

t_color			luminator(t_thr *f)
{
	t_pd			lvec;
	FLOAT_SIZE		angle[2];
	t_light			*ltmp;
	t_color			retcolor;

	ltmp = f->light;
	retcolor = new_t_color(0, 0, 0);
	//retcolor = new_t_color(0, 0, 0);
	if (f->inter.t <= 0)
	{
		return (retcolor);
	}
	while (f->light != NULL)
	{
		lumi_auxi(f, &lvec);
		if (comparator_pos(&(f->liginter), &(f->inter)) == 0)
		{
			f->light = f->light->next;
			continue;
		}
		retcolor = lumi_calc(f, &lvec, angle, retcolor);
		f->light = f->light->next;
	}
	f->light = ltmp;
	return (retcolor);
}



// unsigned int		luminator(t_thr *f, t_inter *inter)
// {
// 	t_pd			lvec;
// 	FLOAT_SIZE		angle;
// 	// t_inter			inter;
// 	t_light			*ltmp;
// //	FLOAT_SIZE		trans;
// 	t_color			retcolor;

// 	//ft_putendl("light");
// 	ltmp = f->light;
// 	retcolor = new_t_color(0, 0, 0);
// 	if (inter->t <= 0)
// 	{
// 		retcolor = new_t_color(0, 0, 0);
// 		return (get_color(retcolor.r, retcolor.g, retcolor.b));
// 	}
// 	while (f->light != NULL)
// 	{
// 	//	ft_putendl("light");
// 		t_inter_set(&(f->liginter));
// 		lvec.pos = f->light->pos;
// 		lvec.dir = new_t_vec(inter->pos.x - f->light->pos.x, inter->pos.y - f->light->pos.y, inter->pos.z - f->light->pos.z);
// 		normalizator(&(lvec.dir));
// 		impactor(&lvec, f->item, &(f->liginter));
// 		//ft_putendl("light 2");
// 		set_inter_pos(&(f->liginter), &lvec);
// 		if (comparator_pos(&(f->liginter), inter) == 0)
// 		{
// 			f->light = f->light->next;
// 			continue;
// 		}
// 		//ft_putendl("light 3");
// 		normalizator(&(f->liginter.norm));
// 		angle = M_PI_2 - acos(dot_prod(lvec.dir, inter->norm));
// 		angle = (angle > 0) ? angle : -angle;

// 		retcolor.r += (angle / 4) * (f->light->rcolor.r * 2 / M_PI) * f->liginter.diff.r;
// 		retcolor.g += (angle / 4) * (f->light->rcolor.g * 2 / M_PI) * f->liginter.diff.g;
// 		retcolor.b += (angle / 4) * (f->light->rcolor.b * 2 / M_PI) * f->liginter.diff.b;
// 		f->light = f->light->next;
// 	}
// 	f->light = ltmp;
// 	printf("%d\n", get_color(retcolor.r, retcolor.g, retcolor.b));
// 	return (get_color(retcolor.r, retcolor.g, retcolor.b));
// }
