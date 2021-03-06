/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:03:56 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/07 15:23:30 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*idst;

	idst = dst;
	while (*src)
		*idst++ = *src++;
	*idst = '\0';
	return (dst);
}
