/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:50:35 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:53:38 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach(t_list *lst, t_functor functor, void *data)
{
	while (lst)
	{
		functor(lst->content, lst->content_size, data);
		lst = lst->next;
	}
}
