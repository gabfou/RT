/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:34:28 by gudepard          #+#    #+#             */
/*   Updated: 2013/12/07 15:24:31 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char		cc;
	const char	*last_occurence;

	cc = (char)c;
	last_occurence = 0;
	while (*s)
	{
		if (*s == cc)
			last_occurence = s;
		++s;
	}
	if (*s == cc)
		last_occurence = s;
	return ((char*)last_occurence);
}
