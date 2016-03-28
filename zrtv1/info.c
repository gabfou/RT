/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:20:30 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/28 00:20:32 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_params(t_env env)
{
	t_light	*light;
	t_item	*item;

	light = env.light;
	item = env.item;
	printf("pos x = %f\npos y = %f\npos z = %f\n",
		env.cam->pos.x, env.cam->pos.y, env.cam->pos.z);
	while (light)
	{
		printf("Light : x = %f; y = %f; z = %f; color = %d;\n",
			light->pos.x, light->pos.y, light->pos.z, light->color);
		light = light->next;
	}
	while (item)
	{
		if (item->sp)
			printf("Sphere : x = %f; y = %f; z = %f;\n",
				item->sp->c.x, item->sp->c.y, item->sp->c.z);
		if (item->pl)
			printf("Plane : x = %f; y = %f; z = %f;\n",
				item->pl->pos.x, item->pl->pos.y, item->pl->pos.z);
		if (item->con)
			printf("Cone : x = %f; y = %f; z = %f;\n",
				item->con->pos.x, item->con->pos.y, item->con->pos.z);
		if (item->cyl)
			printf("Cyl : x = %f; y = %f; z = %f;\n",
				item->cyl->pos.x, item->cyl->pos.y, item->cyl->pos.z);
		printf("Color : r = %f; g = %f; b = %f;\n",
				item->mat.diff.r, item->mat.diff.g, item->mat.diff.b);
		item = item->next;
	}
}
