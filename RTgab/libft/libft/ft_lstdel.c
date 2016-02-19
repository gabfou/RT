/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:07:22 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/11 15:48:52 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && del && alst[0])
	{
		temp = alst[0];
		while (alst[0]->next)
		{
			temp = alst[0]->next;
			ft_lstdelone(alst, del);
			alst[0] = temp;
		}
		ft_lstdelone(alst, del);
	}
	alst = NULL;
	temp = NULL;
}
