/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 18:37:33 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/19 18:37:34 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline FLOAT_SIZE		get_dist(t_vec v1, t_vec v2)
{
	return (sqrt(carre(v2.x - v1.x) + carre(v2.y - v1.y) + carre(v2.z - v1.z)));
}

inline t_vec		vec_mult(t_vec v1, FLOAT_SIZE x)
{
	return (new_t_vec(v1.x * x , v1.y * x, v1.z * x));
}

inline t_vec		prod_vector(t_vec v1, t_vec v2)
{
	return (new_t_vec(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,  v1.x * v2.y - v1.y * v2.x));
}

inline t_vec		sub_vec(t_vec v1, t_vec v2)
{
	return (new_t_vec(v1.x - v2.x , v1.y - v2.y, v1.z - v2.z));
}

inline t_vec		add_vec(t_vec v1, t_vec v2)
{
	return (new_t_vec(v1.x + v2.x , v1.y + v2.y, v1.z + v2.z));
}

inline FLOAT_SIZE		dot_prod(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline t_vec		vector_proj_vector(t_vec v1, t_vec v2) // project vector 1 in vector 2
{
	t_vec	ret;

	ret = vec_mult(v2, dot_prod(v1, v2) / dot_prod(v2, v2));
	return (ret);
}

inline FLOAT_SIZE		ft_min(FLOAT_SIZE a, FLOAT_SIZE b)
{
	if (a > b)
		return (b);
	return (a);
}

void		ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
}

void		print_vec(t_vec vec)
{
	(void)vec;
	// printf("x = [%f]\n", vec.x);
	// printf("y = [%f]\n", vec.y);
	// printf("z = [%f]\n\n", vec.z);
}

FLOAT_SIZE	fatoi_aux(char *str, FLOAT_SIZE *si, FLOAT_SIZE *di)
{
	int	i;
	FLOAT_SIZE	k;

	i = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (*si == 0)
		*si = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	*di = i;
	// printf("di =%f\n", *di);
	return (k);
}

FLOAT_SIZE	ft_fatoi(char *s)
{
	FLOAT_SIZE	d1;
	FLOAT_SIZE	d2;
	int		i;
	FLOAT_SIZE	si;
	FLOAT_SIZE	di;

	i = 0;
	d2 = 0;
	si = 0;
	d1 = fatoi_aux(s, &si, &di);
	while(s[i] && s[i] != '.')
		i++;
	di = 0;
	if (s[i] && s[i] == '.')
		d2 = fatoi_aux(&s[i + 1], &si, &di);
	// printf("s = %f d1 = %f d2 = %f\n",si, d1 ,d2);
	// printf("di =%f\n", di);
	while (di > 0)
	{
		d2 = d2 / 10;
		di--;
	}
	// printf("s = %f d1 = %f d2 = %f\n",si, d1 ,d2);
	// printf("fatoi = %f\n", si * (d1 + d2));
	return (si * (d1 + d2));
}

FLOAT_SIZE	carre(FLOAT_SIZE x)
{
	return (x * x);
}

t_vec	set_new_pos(t_vec dir, t_vec pos, FLOAT_SIZE dist)
{
	return (new_t_vec(pos.x + (dir.x * dist), pos.y + (dir.y * dist), pos.z + (dir.z * dist)));
}

void	set_inter_pos(t_inter *inter, t_pd *pd)
{
	inter->pos.x = (pd->pos.x + (pd->dir.x * inter->t));
	inter->pos.y = (pd->pos.y + (pd->dir.y * inter->t));
	inter->pos.z = (pd->pos.z + (pd->dir.z * inter->t));
}

int		check_t(t_inter *inter, FLOAT_SIZE t, FLOAT_SIZE trans, t_item *item)
{
	t_trans	*tmp;
	//ft_putendl("check t");
//	printf("IUHIPUHGIUO%f %f\n", inter->t, t);
	if (trans > 0)
	{
	//	ft_putendl("check trans");
		tmp = inter->trans;
		if (inter->trans == NULL)
		{
			inter->trans = new_t_trans(t, trans);
	//		ft_putendl("FIN 1");
			return (0);
		}
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_t_trans(t, trans);
		//ft_putendl("FIN 2");
		return (0);
	}
	if ((inter->t > t && t > 0) || inter->t < 0)
	{
		inter->t = t;
		inter->ref = item->mat.ref;
		inter->diff = item->mat.diff;
		// printf("%f\n", item->mat.diff.r);
		//ft_putstr(".");
		//printf("%f\n", inter->t);
	//	ft_putendl("FIN 3");
		return (1);
	}
	//ft_putendl("pas contact");
//	ft_putendl("FIN 4");
	return (0);
}
