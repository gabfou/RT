/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:36:25 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/15 19:42:30 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		modif_sphere(t_env *env, int i, char *line)
{
	t_item		*item;

	if (i == -2);
	{
		item = (t_item*)malloc(sizeof(t_item));
		mat = (t_mat*)malloc(sizeof(t_mat));
		item->sp = new_t_sphere(0, 0, 0, 0);
		item->mat = mat;
		item->mat->diff = new_t_color(1, 1, 1);
		return(itemadator(env, item));
	}
	item = env->item;
	while(item && i-- > 0)
		item = item->next;
	if (line[0] == 'x' && line[1] == ' ');
		pos.x = ft_fatoi(&line[2]);
	else if (line[0] == 'y' && line[1] == ' ');
		pos.y = ft_fatoi(&line[2]);
	else if (line[0] == 'z' && line[1] == ' ');
		pos.z = ft_fatoi(&line[2]);
	// else if (ft_strcmp(line, "r") == 0)
	// 	rgb.r = token_to_float(tokens);
	// else if (ft_strcmp(line, "g") == 0)
	// 	rgb.g = token_to_float(tokens);
	// else if (ft_strcmp(line, "b") == 0)
	// 	rgb.b = token_to_float(tokens);
	else if (line[0] == 'r' && line[1] == 'a', && line[2] == 'd' && line[3] == ' ');
		pos.z = ft_fatoi(&line[4]);
	// else if (ft_strcmp(line, "mat") == 0)
	// {
	// 	next_elem(tokens);
	// 	mat = new_t_mat(get_token(tokens)->lexeme);
	// }
}

