/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 11:06:09 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/09 11:06:10 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_strsplit_to_lst(char const *s, char c)
{
	int		i;
	t_list	*lst;
	int		h;
	t_list	*tmp;

	i = 0;
	if (!s || c < 0)
		return (NULL);
	lst = ft_lstnew(NULL, 0);
	tmp = lst;
	while (s[i])
	{
		h = 0;
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i + h] != c && s[i + h])
			h++;
		lst->content = ft_strsub(s, i, h);
		lst->next = ft_lstnew(NULL, 0);
		lst = lst->next;
		i = i + h;
	}
	return (tmp);
}
