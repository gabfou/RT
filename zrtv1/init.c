/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:18:43 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/03/24 17:45:41 by ibuchwal         ###   ########.fr       */
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

		item = item->next;
	}
}

void		setcam(t_env *env, t_cam *cam)
{
	t_cam	*copy;

	normalizator(&(cam->dir));
	if (cam->dir.x == 0 && cam->dir.z == 0 && (cam->dir.y == 1 || cam->dir.y == -1))
		cam->up = new_t_vec(1, 0, 0);
	else
		cam->up = new_t_vec(0, 1, 0);
	cam->right = prod_vector(cam->dir, cam->up);
	normalizator(&(cam->right));
	cam->up = prod_vector(cam->dir, cam->right);
	normalizator(&(cam->up));
	cam->upleft = set_screen(cam);
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
		next_elem(tokens);
	}
	setcam(env, cam);
}

void		init_light(t_env *env, t_list **tokens)
{
	t_light	*light;
	t_color	rgb;

	rgb.r = 0;
	rgb.b = 0;
	rgb.g = 0;
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
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			rgb.r = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			rgb.g = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			rgb.b = token_to_float(tokens);
		next_elem(tokens);
	}
	light->color = get_color(rgb.r, rgb.g, rgb.b);
	
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

void		t_limg_initator(t_leviatenv *levia)
{
	t_limg	*first;
	t_limg	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	first = NULL;
	i = get_t_cam_lenght(levia->lenv->cam);
	while (i-- > 0)
	{
		if (!tmp)
		{
			tmp = new_t_limg(levia);
			first = tmp;
		}
		else
		{
			tmp->next = new_t_limg(levia);
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
	}
	tmp->next = first;
	tmp->next->prev = tmp;
	levia->lenv->limg = first;
}

void		init_all(t_env *env, t_list *tokens)
{
	t_list	*copy;

	copy = tokens;
	while (copy)
	{
		if (ft_strcmp(get_token(&copy)->lexeme, "cam") == 0)
			init_camera(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "lum") == 0)
			init_light(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "sphere") == 0)
			init_sphere(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "plane") == 0)
			init_plane(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "cone") == 0)
			init_cone(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "cyl") == 0)
			init_cyl(env, &copy);
		else
			next_elem(&copy);
	}
}

void		init(t_env *env, int argc, char *argv)
{
	int		fd;
	t_list	*tokens;
	t_list	*save;

	env->cam = NULL;
	env->light = NULL;
	env->item = NULL;
	fd = access_file(argc, argv);
	tokens = get_tokens(fd);
	save = tokens;
	if (parse_exp(&tokens, env) && tokens == NULL)
		WRITE(STDOUT, "PARSE WIN\n");
	else
	{
		WRITE(STDERR, "Parse fail near : '");
		ft_putstr_fd(get_token(&tokens)->lexeme, STDERR);
		WRITE(STDERR, "' at line ");
		ft_putnbr_fd(get_token(&tokens)->line, STDERR);
		WRITE(STDERR, "\n");
		exit(0);
	}
	delete_symbols(&save);
	init_all(env, save);
}
