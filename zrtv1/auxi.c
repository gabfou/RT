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

t_vec		*vec_mult(t_vec *v1, double x)
{
	return (new_t_vec(v1->x * x , v1->y * x, v1->z * x));
}

t_vec		*prod_vector(t_vec *v1, t_vec *v2)
{
	return (new_t_vec(v1->y * v2->z - v1->z * v2->y, v1->z * v2->x - v1->x * v2->z,  v1->x * v2->y - v1->y * v2->x));
}

t_vec		*sub_vec(t_vec *v1, t_vec *v2)
{
	return (new_t_vec(v1->x - v2->x , v1->y - v2->y, v1->z - v2->z));
}

double		dot_prod(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec		*vector_proj_vector(t_vec *v1, t_vec *v2) // project vector 1 in vector 2
{
	t_vec	*ret;

	ret = vec_mult(v2, dot_prod(v1, v2) / dot_prod(v2, v2));
	return (ret);
}

double		ft_min(double a, double b)
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

void		print_vec(t_vec *vec)
{
	printf("x = [%f]\n", vec->x);
	printf("y = [%f]\n", vec->y);
	printf("z = [%f]\n\n", vec->z);
}

double	fatoi_aux(char *str, double *si, double *di)
{
	int	i;
	double	k;

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
	printf("di =%f\n", *di);
	return (k);
}

double	ft_fatoi(char *s)
{
	double	d1;
	double	d2;
	int		i;
	double	si;
	double	di;

	i = 0;
	d2 = 0;
	si = 0;
	d1 = fatoi_aux(s, &si, &di);
	while(s[i] && s[i] != '.')
		i++;
	di = 0;
	if (s[i] && s[i] == '.')
		d2 = fatoi_aux(&s[i + 1], &si, &di);
	printf("s = %f d1 = %f d2 = %f\n",si, d1 ,d2);
	printf("di =%f\n", di);
	while (di > 0)
	{
		d2 = d2 / 10;
		di--;
	}
	printf("s = %f d1 = %f d2 = %f\n",si, d1 ,d2);
	printf("fatoi = %f\n", si * (d1 + d2));
	return (si * (d1 + d2));
}

double	carre(double x)
{
	return (x * x);
}

void	set_inter_pos(t_inter *inter, t_pd *pd)
{
	inter->pos->x = (pd->pos->x + (pd->dir->x * inter->t));
	inter->pos->y = (pd->pos->y + (pd->dir->y * inter->t));
	inter->pos->z = (pd->pos->z + (pd->dir->z * inter->t));
}

int		check_t(t_inter *inter, double t)
{

	//ft_putendl("check t");
//	printf("IUHIPUHGIUO%f %f\n", inter->t, t);
	//ft_putendl("check t");
	if ((inter->t > t && t > 0) || inter->t < 0)
	{
		inter->t = t;
		//ft_putstr(".");
		//printf("%f\n", inter->t);
		return (1);
	}
	//ft_putendl("pas contact");
	return (0);
}
