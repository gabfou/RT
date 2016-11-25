/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initauxi4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:35:13 by gfournie          #+#    #+#             */
/*   Updated: 2016/06/07 12:35:15 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void			initmatauxi(t_list **tokens, t_item *item)
{
	if (ft_strcmp(get_token(tokens)->lexeme, "xmax") == 0)
		item->mat.max.x = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "xmin") == 0)
		item->mat.min.x = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "ymax") == 0)
		item->mat.max.y = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "ymin") == 0)
		item->mat.min.y = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "zmax") == 0)
		item->mat.max.z = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "zmin") == 0)
		item->mat.min.z = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "nega") == 0)
		item->nega = token_to_float(tokens);
	else if (ft_strcmp(get_token(tokens)->lexeme, "texture") == 0)
	{
		next_elem(tokens);
		item->texture = readerxpm(get_token(tokens)->lexeme);
	}
}
