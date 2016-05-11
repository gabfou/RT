/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initauxi4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 22:16:24 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/29 22:16:26 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		normform(t_list **tokens, t_vec *dir, t_item *item)
{
	if (ft_strcmp(get_token(tokens)->lexeme, "dir_x") == 0)
		dir->x = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "dir_y") == 0)
		dir->y = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "dir_z") == 0)
		dir->z = token_to_float(tokens);
	else
		initmat(tokens, item);
}
