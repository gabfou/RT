/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:25:18 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/11 19:20:36 by ibuchwal         ###   ########.fr       */
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

t_item		*change_current(t_env *lenv, int id)
{
	t_item	*item;
	int		i;

	i = 0;
	item = lenv->item;
	while (i < lenv->nb_obj && item && item->nb != id)
	{
		item = item->next;
		i++;
	}
	return (item);
}

void		comadatorauxi(char *line, t_leviatenv *env)
{
	char		**split;

	if (ft_strcmp(line, "newplane") == 0)
		env->current = new_plane(env->lenv);
	if (ft_strcmp(line, "newcone") == 0)
		env->current = new_cone(env->lenv);
	if (ft_strcmp(line, "printparam") == 0)
		print_params(*env->lenv);
	if (ft_strcmp(line, "printcarre") == 0)
		print_carre(*env->lenv);
	if (ft_strcmp(line, "printcurrent") == 0)
		printitem(env->current);
	split = ft_strsplit(line, ' ');
	if (ft_strcmp(split[0], "changecurrent") == 0 && tlen(split) == 2)
		env->current = change_current(env->lenv, ft_atoi(split[1]));
	if (ft_strcmp(split[0], "modifitem") == 0 && tlen(split) == 3)
		modif_item(env->current, split);
}

void		comadator(char *line, t_leviatenv *env)
{
	static char last[10000];

	if (!line || !line[0])
		return ;
	if (ft_strcmp(line, "reset") == 0)
		ft_strcpy(last, "reset");
	if (ft_strcmp(line, "printlast") == 0)
		ft_putendl(last);
	if (ft_strcmp(line, "refresh") == 0)
		refresh(env);
	if (ft_strcmp(line, "s") == 0)
		enregistrator(env->lenv);
	if (ft_strcmp(line, "newsphere") == 0)
		env->current = new_sphere(env->lenv);
	if (ft_strcmp(line, "newcyl") == 0)
		env->current = new_cyl(env->lenv);
	comadatorauxi(line, env);
}
