/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:14:15 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/04 04:43:01 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_open(void)
{
	int	fd;

	fd = open("./test_parse", O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("done goof'd\n");
		exit(0);
	}
	return (fd);
}

int		main(void)
{
	t_env	e;
	int		fd;
	t_ray	ray;

	e = init_mlx(1000, 1022);
	init_env(&e);
	ray.origin = e.cam;
	fd = ft_open();
	e.list = recur_list_build(fd, NULL);
	close(fd);
	fd = ft_open();
	e.lights = recur_lights_build(fd, NULL);
	close(fd);
	e.ray = ray;
	mlx_do_key_autorepeaton(e.mlx);
	mlx_hook(e.win, 2, 1L << 0, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

int		expose_hook(t_env *e)
{
	ft_reducer(e);
	return (1);
}

int		key_hook(int key, t_env *e)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		e->cam.x += 1;
	if (key == 124)
		e->cam.x -= 1;
	if (key == 125)
		e->cam.y += 1;
	if (key == 126)
		e->cam.y -= 1;
	return (0);
}
