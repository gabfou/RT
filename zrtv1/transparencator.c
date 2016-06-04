/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparencator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:59:42 by jromagna          #+#    #+#             */
/*   Updated: 2016/03/12 20:59:44 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

FLOAT_SIZE	transparencator(unsigned int color, FLOAT_SIZE trans)
{
	return (get_color(((color >> 0) & 0xFF)  * (trans / 100),
	 					((color >> 8) & 0xFF)  * (trans / 100),
	 					((color >> 16) & 0xFF)  * (trans / 100)));
}

FLOAT_SIZE	trans_calculator(t_trans *trans, FLOAT_SIZE	t)
{
	FLOAT_SIZE	ret;
	t_trans	*tmp;

	ret = 100;
	tmp = trans;
	while (tmp != NULL)
	{
		// ft_putendl("boucle");
		// printf("tmp->t = %f\n", tmp->t);
		// printf("tmp->t = %f\n", tmp->t);
		// ft_putendl("boucle1.2");
		if (tmp->t < t)
			ret = ret * (1 - (tmp->colabs / 100));
		// ft_putendl("boucle2");
		tmp = tmp->next;
	}
	// ft_putendl("fin trans calc");
	// printf("ret = %f\n", ret);
	return (ret);
}