/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:25:18 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/23 16:25:19 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		refresh(t_leviatenv *env)
{
	env->lenv->limg->l = 0;
	env->lenv->limg->i = 1;
	env->lenv->done = 0;
	thread_master(env->lenv);
}

void		comadator(char *line, t_leviatenv *env)
{
	static char last[10000];
	static int	i = -1;
	char		**split;

	if (ft_strcmp(line, "reset") == 0)
		ft_strcpy(last, "reset");
	if (ft_strcmp(line, "printlast") == 0)
		ft_putendl(last);
	if (ft_strcmp(line, "refresh") == 0)
		refresh(env);
	if (ft_strcmp(line, "s") == 0)
		enregistrator(env->lenv);
	if (ft_strcmp(line, "newsphere") == 0)
		i = new_sphere(env->lenv);
	if (ft_strcmp(line, "clear") == 0)
		mlx_clear_window(env->mlx, env->win);
	if (ft_strcmp(line, "printparam") == 0)
		print_params(*env->lenv);
	if (ft_strcmp(line, "printcarre") == 0)
		print_carre(*env->lenv);
	split = ft_strsplit(line, ' ');
	if (ft_strcmp(split[0], "modifitem") == 0 && tlen(split) == 4)
		modif_item(env->lenv, ft_atoi(split[1]), split);
}
