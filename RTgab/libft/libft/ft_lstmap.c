/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:30:02 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/11 15:47:18 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*r;

	r = NULL;
	if (lst && f)
	{
		r = ft_lstnew(f(lst)->content, f(lst)->content_size);
		lst = lst->next;
		new = r;
		while (lst && lst->next)
		{
			new->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
			lst = lst->next;
			new = new->next;
		}
		new->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
	}
	return (r);
}
