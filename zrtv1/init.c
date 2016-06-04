/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:18:43 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/04/06 23:31:25 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

void		init_screen(t_env *env, t_list **tokens)
{
	next_elem(tokens);
	while (!terminal(&(*tokens), CLOSING_BRACKET))
	{
		if (ft_strcmp(get_token(tokens)->lexeme, "h") == 0)
			env->screen.h = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "l") == 0)
			env->screen.l = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "scr_l") == 0)
			env->screen.scrl = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "scr_h") == 0)
			env->screen.scrh = token_to_float(tokens);
		else if (ft_strcmp(get_token(tokens)->lexeme, "scr_d") == 0)
			env->screen.scrd = token_to_float(tokens);
		next_elem(tokens);
	}
	env->screen.resh = env->screen.h / 2;
	env->screen.resl = env->screen.l / 2;
	env->screen.li = env->screen.scrl / env->screen.resl;
	env->screen.hi = env->screen.scrh / env->screen.resl;
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
		else if (ft_strcmp(get_token(&copy)->lexeme, "screen") == 0)
			init_screen(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "triangle") == 0)
			init_tr(env, &copy);
		else if (ft_strcmp(get_token(&copy)->lexeme, "obj") == 0)
			init_obj(env, &copy);
		else
			next_elem(&copy);
	}
}

void		init(t_env *env, int argc, char *argv)
{
	int			fd;
	t_list		*tokens;
	t_list		*save;
	// pthread_t	t;


	env->nb_obj = 0;
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
	// pthread_create(&t, NULL, (void*)&(carresisator), env);
	carresisator(env);
	free_tokens(&save);
}
