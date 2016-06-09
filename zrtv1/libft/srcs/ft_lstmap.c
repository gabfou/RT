/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:57:23 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/25 20:10:49 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*it;
	t_list	*mapped;
	t_list	*res;

	it = lst;
	mapped = 0;
	while (it)
	{
		res = f(it);
		ft_lstappend(&mapped, ft_lstnew(res->content, res->content_size));
		it = it->next;
	}
	return (mapped);
}
