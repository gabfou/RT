/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impactcarre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:31:15 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/04 19:31:33 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		carre_pd(t_carre *b, t_pd r)
{
	double tx1;
	double tx2;
	double ty1;
	double ty2;
	double tz1;

	tx1 = (b->pos.x - r.pos.x) * -1 * r.dir.x;
	tx2 = (b->pos.x + b->size - r.pos.x) * -1 * r.dir.x;
	ty1 = (b->pos.y - r.pos.y) * -1 * r.dir.y;
	ty2 = (b->pos.y + b->size - r.pos.y) * -1 * r.dir.y;
	tz1 = (b->pos.z - r.pos.z) * -1 * r.dir.z;
	return (fmax(fmin(tx1, tx2), fmax(fmin(ty1, ty2),
		fmin(tz1, (b->pos.z + b->size - r.pos.z) * -1 * r.dir.z)))
		<= 0 + fmin(fmax(tx1, tx2), fmin(fmax(ty1, ty2),
		fmax(tz1, (b->pos.z + b->size - r.pos.z) * -1 * r.dir.z))));
}

void	idciator(t_env *env, t_pd pd, t_item **niark, int *use)
{
	t_carre	*tmp;
	int		i;
	t_cnb	*tmp2;

	// ft_bzero(niark, NB_CARRE);
	ft_bzero(use, env->nb_obj + 1);
	tmp = env->carre;
	i = env->infitem;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		if (carre_pd(tmp, pd) == 1)
		{
			tmp2 = tmp->cnb;
			while (tmp2)
			{
				if (use[tmp2->item->nb] == 0)
				{
					niark[i++] = tmp2->item;
					use[tmp2->item->nb] = 1;
				}
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->next;
	}
	niark[i] = NULL;
}

void	addcnb(t_carre *carre, t_cnb *cnb)
{
	t_cnb	*copy;

	if (!carre->cnb)
		carre->cnb = cnb;
	else
	{
		copy = carre->cnb;
		while (copy->next)
			copy = copy->next;
		copy->next = cnb;
	}
}

int		carre_sphere(t_carre *c, t_item *item, int n)
{
	if (c->pos.x < item->sp->c.x + item->sp->ray
		&& c->pos.y < item->sp->c.y + item->sp->ray
		&& c->pos.z < item->sp->c.z + item->sp->ray
		&& c->pos.x + c->size > item->sp->c.x - item->sp->ray
		&& c->pos.y + c->size > item->sp->c.y - item->sp->ray
		&& c->pos.z + c->size > item->sp->c.z - item->sp->ray)
	{
		if (n)
			addcnb(c, new_t_cnb(item));
		return (1);
	}
	return (0);
}

// #define X 0
// #define Y 1
// #define Z 2

// #define CROSS(dest,v1,v2) \
//           dest[0]=v1[1]*v2[2]-v1[2]*v2[1]; \
//           dest[1]=v1[2]*v2[0]-v1[0]*v2[2]; \
//           dest[2]=v1[0]*v2[1]-v1[1]*v2[0];

// #define FINDMINMAX(x0,x1,x2,min,max) \
//   min = max = x0;   \
//   if(x1<min) min=x1;\
//   if(x1>max) max=x1;\
//   if(x2<min) min=x2;\
//   if(x2>max) max=x2;

// int planeBoxOverlap(t_vec normal,float d, t_vec maxbox)
// {
// 	int q;
// 	float vmin.z
// 	float vmax.z;

// 	if(normal.x > 0.0f)
// 	{
// 		vmin.x = -maxbox.x;
// 		vmax.x = maxbox.x;
// 	}
// 	else
// 	{
// 		vmin.x = maxbox.x;
// 		vmax.x = -maxbox.x;
// 	}
// 	if(normal.y > 0.0f)
// 	{
// 		vmin.y = -maxbox.y;
// 		vmax.y = maxbox.y;
// 	}
// 	else
// 	{
// 		vmin.y = maxbox.y;
// 		vmax.y = -maxbox.y;
// 	}
// 	if(normal.z > 0.0f)
// 	{
// 		vmin.z = -maxbox.z;
// 		vmax.z = maxbox.z;
// 	}
// 	else
// 	{
// 		vmin.z = maxbox.z;
// 		vmax.z = -maxbox.z;
// 	}
// 	if(dot_prod(normal,vmin) + d > 0.0f)
// 		return 0;
// 	if(dot_prod(normal,vmax) + d >= 0.0f)
// 		return 1;
// 	return 0;
// }

int		carre_triangle(t_carre *c, t_item *item, int n)
{
	// FLOAT_SIZE	d;
	// FLOAT_SIZE	d2;
	t_vec		min;
	t_vec		max;
	// t_pd		pd;

	// d = get_dist(item->tr->p1, item->tr->p2);
	// d2 = get_dist(item->tr->p1, item->tr->p3);
	// d = (d > d2) ? d : d2;
	// pd.pos = item->tr->p1;
	// pd.dir  = normalizator_ret(sub_vec(item->tr->p1, item->tr->p2));
	// d2 = carre_pd(c, pd) - 0.1;
	// pd.dir  = normalizator_ret(sub_vec(item->tr->p1, item->tr->p3));
	// d2 += carre_pd(c, pd);
	// pd.pos = item->tr->p2;
	// pd.dir  = normalizator_ret(sub_vec(item->tr->p2, item->tr->p3));
	// d2 += carre_pd(c, pd);
	// if (d2 < 0)
	// 	return (0);
	// if ((c->pos.x < item->tr->p1.x + d
	// 	&& c->pos.y < item->tr->p1.y + d
	// 	&& c->pos.z < item->tr->p1.z + d
	// 	&& c->pos.x + c->size > item->tr->p1.x - d
	// 	&& c->pos.y + c->size > item->tr->p1.y - d
		// && c->pos.z + c->size > item->tr->p1.z - d))
	min.x = fmin(fmin(item->tr->p1.x, item->tr->p2.x), item->tr->p3.x);
	min.y = fmin(fmin(item->tr->p1.y, item->tr->p2.y), item->tr->p3.y);
	min.z = fmin(fmin(item->tr->p1.z, item->tr->p2.z), item->tr->p3.z);
	max.x = fmax(fmax(item->tr->p1.x, item->tr->p2.x), item->tr->p3.x);
	max.y = fmax(fmax(item->tr->p1.y, item->tr->p2.y), item->tr->p3.y);
	max.z = fmax(fmax(item->tr->p1.z, item->tr->p2.z), item->tr->p3.z);
	if (c->pos.x > max.x
		|| c->pos.y > max.y
		|| c->pos.z > max.z
		|| c->pos.x + c->size < min.x
		|| c->pos.y + c->size < min.y
		|| c->pos.z + c->size < min.z)
		return (0);
	else
	{
		if (n)
			addcnb(c, new_t_cnb(item));
		return (1);
	}
	return (0);
}

// int		carre_triangle(t_carre *c, t_item *item, int n)
// {
// 	FLOAT_SIZE d;
// 	FLOAT_SIZE d2;


// 	return (0);
// }


int		carre_obj(t_carre *c, t_item *item, int n)
{
	t_item	*tmp;
	int		i;

	i = 0;
	tmp = item->obj->tr;
	while (tmp)
	{
		i += carre_triangle(c, tmp, n);
		tmp = tmp->next;
	}
	return (i);
}

int		impactcarre(t_carre *c, t_env *env, int n)
{
	t_item	*lst;
	int		i;

	(void)env;
	i = 0;
	// ft_putendl("niark");
	lst = env->item;
	while (lst != NULL)
	{
		if (lst->sp != NULL)
			i += carre_sphere(c, lst, n);
		else if (lst->tr != NULL)
			i += carre_triangle(c, lst, n);
		else if (lst->obj != NULL)
			i += carre_obj(c, lst, n);
		lst = lst->next;
	}
	if (n == 1)
	{
		ft_putnbr(i);
		ft_putendl ("");
	}
	return (i);
}
