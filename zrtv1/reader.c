/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:18:29 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/23 16:18:32 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "rtv1.h"

void		initkeytocharnorm(char *tab)
{
	tab[45] = 'n';
	tab[46] = 'm';
	tab[18] = '1';
	tab[19] = '2';
	tab[20] = '3';
	tab[21] = '4';
	tab[23] = '5';
	tab[22] = '6';
	tab[26] = '7';
	tab[28] = '8';
	tab[25] = '9';
	tab[29] = '0';
	tab[83] = '1';
	tab[84] = '2';
	tab[85] = '3';
	tab[86] = '4';
	tab[87] = '5';
	tab[88] = '6';
	tab[89] = '7';
	tab[91] = '8';
	tab[92] = '9';
	tab[82] = '0';
	tab[36] = -1;
	tab[49] = ' ';
	tab[51] = -2;
}

char		*initkeytochar(void)
{
	char *tab;

	tab = malloc(1000);
	ft_bzero(tab, 1000);
	tab[12] = 'q';
	tab[13] = 'w';
	tab[14] = 'e';
	tab[15] = 'r';
	tab[17] = 't';
	tab[16] = 'y';
	tab[32] = 'u';
	tab[34] = 'i';
	tab[31] = 'o';
	tab[35] = 'p';
	tab[0] = 'a';
	tab[1] = 's';
	tab[2] = 'd';
	tab[3] = 'f';
	tab[5] = 'g';
	tab[4] = 'h';
	tab[38] = 'j';
	tab[40] = 'k';
	tab[37] = 'l';
	initkeytocharnorm(tab);
	return (tab);
}

char		keytochar(int key)
{
	static char *tab = NULL;

	if (!tab)
	{
		tab = initkeytochar();
		tab[6] = 'z';
		tab[7] = 'x';
		tab[8] = 'c';
		tab[9] = 'v';
		tab[11] = 'b';
	}
	return (tab[key]);
}

int			comanderauxi(char keyret, char *stat, t_leviatenv *env, int i)
{
	if (i == -1)
		ft_bzero(stat, 10000);
	if (i == -1)
		i = 0;
	if (keyret == 0 || i > 9998)
		ft_putendl("what?");
	else if (keyret == -1)
	{
		write(1, "\n", 1);
		comadator(stat, env);
		ft_bzero(stat, 10000);
		i = 0;
	}
	else if (keyret == -2 && i != 0)
		stat[--i] = 0;
	else
		stat[i++] = keyret;
	return (i);
}

void		comander(int key, t_leviatenv *env)
{
	static char	stat[10000];
	char		keyret;
	static int	i = -1;

	keyret = keytochar(key);
	if (key != -3)
		i = comanderauxi(keyret, stat, env, i);
	mlx_clear_window(env->mlx, env->win);
	if (env->lenv->ft % 2 == 1)
	{
		imgcptor(env);
		mlx_string_put(env->mlx, env->win, env->lenv->screen.l + 2,
			env->lenv->screen.h - 30, 0xFFFFFF, stat);
	}
}
