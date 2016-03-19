/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:18:43 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/03/14 23:52:14 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// void		initktc(t_env *e)
// {
// 	char *tab;

// 	//(void)(e);
// 	tab = malloc(1000);
// 	//ft_bzero((tab), 1000);
// 	e->ktc = ft_strdup("test");
// 	ft_putendl(e->ktc);
// }

void	print_tokens(t_list *tokens)
{
	// UNUSED(tokens);
	// printf("lol\n");
	while (tokens)
	{
		ft_putendl(get_token(&tokens)->lexeme);
		next_elem(&tokens);
	}
}

int			access_file(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		fatal_error(RAYTRACER, ERR_TOO_FEW_ARGS, 0);
	if (argc > 2)
		fatal_error(RAYTRACER, ERR_TOO_MANY_ARGS, 0);
	if (access(argv[1], F_OK))
		fatal_error(RAYTRACER, ERR_NO_DIR, 0);
	if (access(argv[1], R_OK))
		fatal_error(RAYTRACER, ERR_PERMISSION_DENIED, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fatal_error(RAYTRACER, ERR_INACCESSIBLE, 0);
	return (fd);
}

t_list		*get_tokens(int fd)
{
	int		line_number;
	char	*line;
	t_list	*tokens;

	line_number = 1;
	tokens = 0;
	while (get_next_line(fd, &line))
	{
		// WRITE(1, "lol\n");
		if (line[0] != '#')
			ft_lstappend(&tokens, tokenize(line, line_number));
		line_number++;
		free(line);
	}
	return (tokens);

}

void	delete_symbols(t_list **tokens)
{
	t_list	*save;

	save = *tokens;
	while ((*tokens)->next)
	{
		if (!terminal(&(*tokens)->next, WORD) && !terminal(&(*tokens)->next, CLOSING_BRACKET))
		{
			if ((*tokens)->next->next)
				(*tokens)->next = (*tokens)->next->next;
			else
				(*tokens)->next = NULL;
		}
		if ((*tokens)->next)
			next_elem(tokens);
		else
			break ;
	}
	(*tokens) = save;
}

void	print_params(t_env env)
{
	t_light	*light;
	t_item	*item;

	light = env.light;
	item = env.item;

	printf("pos x = %f\npos y = %f\npos z = %f\n", env.cam->pos->x, env.cam->pos->y, env.cam->pos->z);
	while (light)
	{
		printf("Light : x = %f; y = %f; z = %f; color = %d;\n", light->pos->x,
														   light->pos->y,
														   light->pos->z,
														   light->color);

		light = light->next;
	}
	while (item)
	{
		if (item->sp)
			printf("Sphere : x = %f; y = %f; z = %f;\n", item->sp->c->x,
															   item->sp->c->y,
															   item->sp->c->z);
		if (item->pl)
			printf("Plane : x = %f; y = %f; z = %f;\n", item->pl->pos->x,
															   item->pl->pos->y,
															   item->pl->pos->z);
		if (item->con)
			printf("Cone : x = %f; y = %f; z = %f;\n", item->con->pos->x,
															   item->con->pos->y,
															   item->con->pos->z);
		if (item->cyl)
			printf("Cyl : x = %f; y = %f; z = %f;\n", item->cyl->pos->x,
															   item->cyl->pos->y,
															   item->cyl->pos->z);

		item = item->next;
	}
}

float		token_to_float(t_list **tokens)
{
	next_elem(tokens);
	return (ft_fatoi(get_token(tokens)->lexeme));
}

t_vec		*set_screen(t_cam *cam)
{
	float		x;
	float		y;
	float		z;

	x = cam->dir->x * SCR_DIST - cam->up->x * SCR_H - cam->right->x * SCR_L;
	y = cam->dir->y * SCR_DIST - cam->up->y * SCR_H - cam->right->y * SCR_L;
	z = cam->dir->z * SCR_DIST - cam->up->z * SCR_H - cam->right->z * SCR_L;
	return (new_t_vec(x, y, z));
	// print_vec(screen->upleft);
}

void		init_camera(t_env *env, t_list **tokens)
{
	t_cam	*cam;
	t_vec	pos;
	t_vec	dir;
	float	rot;
	t_cam	*copy;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	rot = 0;
	ft_putendl("CAM CREATE1");
	cam = (t_cam*)malloc(sizeof(t_cam));
	next_elem(tokens);
	ft_putendl("CAM CREATE1.2");
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
			dir.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
			dir.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
			dir.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rot") == 0)
			rot = token_to_float(tokens);
		next_elem(tokens);
	}
	ft_putendl("CAM CREATE1.5");
	cam->pos = new_t_vec(pos.x, pos.y, pos.z);
	cam->dir = new_t_vec(dir.x, dir.y, dir.z);
	ft_putendl("CAM CREATE1.8");
	normalizator(cam->dir);
	cam->angle = rot;
	ft_putendl("CAM CREATE2");
	cam->up = new_t_vec(0, 1, 0);
	cam->right = prod_vector(cam->dir, cam->up);
	ft_putendl("CAM CREATE2.1");
	normalizator(cam->right);
	cam->up = prod_vector(cam->dir, cam->right);
	ft_putendl("CAM CREATE2.5");
	normalizator(cam->up);
	ft_putendl("CAM CREATE2.8");
	cam->upleft = set_screen(cam);
	ft_putendl("CAM CREATE3");
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

// void		init_camera(t_env *env, t_list **tokens)
// {
// 	t_cam	*cam;
// 	t_vec	pos;
// 	t_vec	dir;
// 	float	rot;

// 	pos.x = 0;
// 	pos.y = 0;
// 	pos.z = 0;
// 	dir.x = 0;
// 	dir.y = 0;
// 	dir.z = 0;
// 	rot = 0;
// 	cam = (t_cam*)malloc(sizeof(t_cam));
// 	next_elem(tokens);
// 	while (!terminal(&(*tokens), CLOSING_BRACKET))
// 	{
// 		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
// 			pos.x = token_to_float(tokens);
// 		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
// 			pos.y = token_to_float(tokens);
// 		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
// 			pos.z = token_to_float(tokens);
// 		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
// 			dir.x = token_to_float(tokens);
// 		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
// 			dir.y = token_to_float(tokens);
// 		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
// 			dir.z = token_to_float(tokens);
// 		else if (ft_strcmp(get_token(tokens)->lexeme, "rot") == 0)
// 			rot = token_to_float(tokens);
// 		next_elem(tokens);
// 	}
// 	cam->pos = new_t_vec(pos.x, pos.y, pos.z);
// 	cam->dir = new_t_vec(dir.x, dir.y, dir.z);
// 	normalizator(cam->dir);
// 	cam->angle = rot;
// 	cam->up = new_t_vec(0, 1, 0);
// 	cam->right = prod_vector(cam->dir, cam->up);
// 	normalizator(cam->right);
// 	cam->up = prod_vector(cam->dir, cam->right);
// 	env->cam = cam;
// 	env->screen = set_screen(env->cam);

// }

void		init_light(t_env *env, t_list **tokens)
{
	UNUSED(env);
	t_light	*light;
	t_light	*copy;
	t_vec	pos;
	t_color	rgb;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	light = (t_light*)malloc(sizeof(t_light));
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			rgb.r = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			rgb.g = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			rgb.b = token_to_float(tokens);
		next_elem(tokens);
	}
	light->pos = new_t_vec(pos.x, pos.y, pos.z);
	light->color = get_color(rgb.r, rgb.g, rgb.b);
	light->next = NULL;
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

void		init_sphere(t_env *env, t_list **tokens)
{
	UNUSED(env);
	t_item		*item;
	t_vec		pos;
	t_color		rgb;
	float		rad;
	t_mat		*mat;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	rad = 0;
	item = (t_item*)malloc(sizeof(t_item));
	mat = (t_mat*)malloc(sizeof(t_mat));
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			rgb.r = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			rgb.g = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			rgb.b = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rad") == 0)
			rad = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "mat") == 0)
		{
			next_elem(tokens);
			mat = new_t_mat(get_token(tokens)->lexeme);
		}
		next_elem(tokens);
	}
	item->sp = new_t_sphere(pos.x, pos.y, pos.z, rad);
	item->mat = mat;
	item->mat->diff = new_t_color(1, 1, 1);
	itemadator(env, item);
}

void		init_plane(t_env *env, t_list **tokens)
{
	UNUSED(env);
	t_item		*item;
	t_vec		pos;
	t_vec		dir;
	t_color		rgb;
	t_mat		*mat;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	item = (t_item*)malloc(sizeof(t_item));
	mat = (t_mat*)malloc(sizeof(t_mat));
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			rgb.r = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			rgb.g = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			rgb.b = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
			dir.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
			dir.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
			dir.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "mat") == 0)
		{
			next_elem(tokens);
			mat = new_t_mat(get_token(tokens)->lexeme);
		}
		next_elem(tokens);
	}
	item->pl = t_plane_creator(pos.x, pos.y, pos.z, dir.x, dir.y, dir.z);
	item->mat = mat;
	item->mat->diff = new_t_color(1, 1, 1);
	itemadator(env, item);
}

void		init_cone(t_env *env, t_list **tokens)
{
	UNUSED(env);
	t_item		*item;
	t_vec		pos;
	t_vec		dir;
	t_color		rgb;
	t_mat		*mat;
	float		angle;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	angle = 0;
	item = (t_item*)malloc(sizeof(t_item));
	mat = (t_mat*)malloc(sizeof(t_mat));
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			rgb.r = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			rgb.g = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			rgb.b = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
			dir.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
			dir.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
			dir.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "angle") == 0)
			angle = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "mat") == 0)
		{
			next_elem(tokens);
			mat = new_t_mat(get_token(tokens)->lexeme);
		}
		next_elem(tokens);
	}
	item->con = t_con_creator(pos.x, pos.y, pos.z, dir.x, dir.y, dir.z, angle);
	item->mat = mat;
	item->mat->diff = new_t_color(1, 1, 1);
	itemadator(env, item);
}

void		init_cyl(t_env *env, t_list **tokens)
{
	t_item		*item;
	t_vec		pos;
	t_vec		dir;
	t_color		rgb;
	t_mat		*mat;
	float		rad;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	rad = 0;
	item = (t_item*)malloc(sizeof(t_item));
	mat = (t_mat*)malloc(sizeof(t_mat));
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "x") == 0)
			pos.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "y") == 0)
			pos.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "z") == 0)
			pos.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "r") == 0)
			rgb.r = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "g") == 0)
			rgb.g = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "b") == 0)
			rgb.b = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
			dir.x = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
			dir.y = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
			dir.z = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "rad") == 0)
			rad = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "mat") == 0)
		{
			next_elem(tokens);
			mat = new_t_mat(get_token(tokens)->lexeme);
		}
		next_elem(tokens);
	}
	item->cyl = t_cyl_creator(pos.x, pos.y, pos.z, dir.x, dir.y, dir.z, rad);
	item->mat = mat;
	item->mat->diff = new_t_color(1, 1, 1);
	itemadator(env, item);
}

int			get_t_cam_lenght(t_cam *cam)
{
	t_cam	*tmp;
	int		i;

	i = 0;
	tmp = cam;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		t_limg_initator(t_env *env)
{
	t_limg	*first;
	t_limg	*tmp;
	int		i;

	i = get_t_cam_lenght(env->cam);
	ft_putnbr(i);
	while (i > 0)
	{
		if (!tmp)
		{
			tmp = new_t_limg(env);
			first = tmp;
		}
		else
		{
			tmp->next = new_t_limg(env);
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		i--;
	}
	tmp->next = first;
	first->prev = tmp;
	env->limg = first;
}

void		init_env(t_env *env)
{
	env->l = 0;
	env->done = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, L_SIZE, H_SIZE, "RTV1");
	t_limg_initator(env);
	// env->image = mlx_new_image(env->mlx, L_SIZE, H_SIZE);
	// env->img = mlx_get_data_addr(env->image, &env->bpp, &env->sline, &env->endiant);
	env->i = 1;
	// initktc(env);
	ft_putendl("ASFGDSHBSHSRRSH");
}

void		init_all(t_env *env, t_list *tokens)
{
	t_list	*copy;

	copy = tokens;
	while (copy)
	{
		ft_putendl("TeST2. BOUCLE ALL");
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

void		init(t_env *env, int argc, char **argv)
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
	ft_putendl("TeST1");
	delete_symbols(&save);
	ft_putendl("TeST2");
	init_all(env, save);
	ft_putendl("TeST3");
}