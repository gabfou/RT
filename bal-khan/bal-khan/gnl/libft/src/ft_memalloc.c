/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:37:55 by bal-khan          #+#    #+#             */
/*   Updated: 2015/11/12 20:46:15 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*block;

	block = (void*)malloc(sizeof(void*) * size);
	if (block == NULL)
	{
		ft_putendl("allocation failed");
		return (NULL);
	}
	else
	{
		ft_bzero(block, size);
		return (block);
	}
}
