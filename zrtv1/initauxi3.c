/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initauxi3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:22:03 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/28 00:22:04 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		setcam(t_env *env, t_cam *cam)
{
	t_cam	*copy;

	cam->angle = cam->angle * M_PI / 180;
	normalizator(&(cam->dir));
	if (cam->dir.x == 0 && cam->dir.z == 0
		&& (cam->dir.y == 1 || cam->dir.y == -1))
		cam->up = new_t_vec(cam->dir.y, 0, 0);
	else
		cam->up = new_t_vec(0, 1, 0);
	rotationator(&(cam->up), cam->angle);
	cam->right = prod_vector(cam->dir, cam->up);
	normalizator(&(cam->right));
	cam->up = prod_vector(cam->dir, cam->right);
	normalizator(&(cam->up));
	cam->next = NULL;
	if (!env->cam)
		env->cam = cam;
	else
	{
		copy = env->cam;
		while (copy->next)
			copy = copy->next;
		copy->next = cam;
	}
}

void		camstupid(t_cam *cam, t_list **tokens)
{
	if (ft_strcmp(get_token(tokens)->lexeme, "zebre") == 0)
		cam->zebre = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "rfu") == 0)
		cam->rfu = token_to_float(tokens);
}

void		init_camera(t_env *env, t_list **tokens)
{
	t_cam	*cam;

	cam = new_t_cam();
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			cam->pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			cam->pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			cam->pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
			cam->dir.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
			cam->dir.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
			cam->dir.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rot") == 0)
			cam->angle = token_to_float(tokens);
		else
			camstupid(cam, tokens);
		next_elem(tokens);
	}
	setcam(env, cam);
}

void		addlight(t_env *env, t_light *light)
{
	t_light	*copy;

	if (!env->light)
		env->light = light;
	else
	{
		copy = env->light;
		while (copy->next)
			copy = copy->next;
		copy->next = light;
	}
}

void		init_light(t_env *env, t_list **tokens)
{
	t_light	*light;

	light = new_t_light();
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			light->pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			light->pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			light->pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "photon") == 0)
			light->photon = (int)token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			light->rcolor.r = (int)token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			light->rcolor.g = (int)token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			light->rcolor.b = (int)token_to_float(tokens);
		next_elem(tokens);
	}
	printf("%f  %f  %f\n", light->rcolor.r, light->rcolor.g, light->rcolor.b);
	printf("%d\n", get_color(light->rcolor.r, light->rcolor.g, light->rcolor.b));
	addlight(env, light);
}
