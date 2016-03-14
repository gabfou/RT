/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:26:58 by bal-khan          #+#    #+#             */
/*   Updated: 2016/02/26 18:27:02 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			set_screen(t_env *e)
{
	float		x;
	float		y;
	float		z;

	e->cam_dir = normalizator(e->cam_dir);
	e->cam_up = normalizator(e->cam_up);
	e->cam_right = normalizator(e->cam_right);
	x = e->cam_dir.x * 1.0 - e->cam_up.x * 0.5 - e->cam_right.x * 0.5;
	y = e->cam_dir.y * 1.0 - e->cam_up.y * 0.5 - e->cam_right.y * 0.5;
	z = e->cam_dir.z * 1.0 - e->cam_up.z * 0.5 - e->cam_right.z * 0.5;
	e->upleft = new_point(x, y, z);
}

void			set_cam(t_env *e)
{
	e->cam.x = -000;//-2000;
	e->cam.y = -000;//-4000;//-5000;
	e->cam.z = -9000;//1400;//1000;//-70000.0;
	e->cam_dir = (new_point(0, 1, 4));;//(new_point(2000, -1000, 10));// z= 10 avec normalizator
	e->cam_angle = 0;
	e->cam_dir = normalizator(e->cam_dir);
	e->cam_up = new_point(0, -1, 0);
	e->cam_right = cross_product(e->cam_dir, e->cam_up);
	e->cam_right = normalizator(e->cam_right);
	e->cam_up = cross_product(e->cam_dir, e->cam_right);
}

void			calc_dir(t_env *e, double x, double y)
{
	e->ray.direct.x = (e->upleft.x + (e->cam_up.x * 1.0 * y / e->s_x)\
	+ (e->cam_right.x * 1.0 * x / e->s_y));
	e->ray.direct.y = (e->upleft.y + (e->cam_up.y * 1.0 * y / e->s_x)\
	+ (e->cam_right.y * 1.0 * x / e->s_y));
	e->ray.direct.z = (e->upleft.z + (e->cam_up.z * 1.0 * y / e->s_x)\
	+ (e->cam_right.z * 1.0 * x / e->s_y));
	e->ray.direct = normalizator(e->ray.direct);
}
