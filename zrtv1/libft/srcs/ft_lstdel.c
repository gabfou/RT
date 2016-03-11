/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:15:15 by gudepard          #+#    #+#             */
/*   Updated: 2014/01/07 12:49:58 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, t_deleter del)
{
	t_list	*it;
	t_list	*temp;

	if (alst)
	{
		it = *alst;
		while (it)
		{
			del(it->content, it->content_size);
			temp = it;
			it = it->next;
			free(temp);
		}
		*alst = 0;
	}
}
