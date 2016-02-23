/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:59:12 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/13 20:56:57 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list*elem))
{
	t_list	*shepard;

	if (!lst || !f)
		return ;
	shepard = lst;
	while (lst->next != NULL)
	{
		shepard = lst->next;
		f(lst);
		lst = shepard;
	}
	f(lst);
}
