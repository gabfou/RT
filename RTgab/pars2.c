/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 17:36:31 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/30 17:36:33 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"


// t_item			*new_t_item()
// {
// 	t_item	*item;

// 	item = malloc(sizeof(t_item));
// 	item->pl = NULL;
// 	item->sp = NULL;
// 	item->next = NULL;
// 	return(item);
// }

// t_item			*fill_t_item(char **t, t_item *item)
// {
// 	if (strcmp(t[0], "sphere") == 0)
// 	{
// 		item->sp = new_t_sphere(ft_fatoi(t[1]), ft_fatoi(t[2]),
// 		ft_fatoi(t[3]), ft_fatoi(t[4]));
// 		item->mat = new_t_mat(t[5]);
// 		item->mat->diff = new_t_color(1, 1, 1);
// 		item->pl = NULL;
// 	}
// 	if (strcmp(t[0], "plane") == 0)
// 	{
// 		item->pl = t_plane_creator(ft_fatoi(t[1]), ft_fatoi(t[2]),
// 		ft_fatoi(t[3]), ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]));
// 		item->mat = new_t_mat(t[8]);
// 		item->mat->diff = new_t_color(1, 1, 1);
// 		item->sp  = NULL;
// 	}
// 	return (item);
// }

// t_screen		*set_screen(t_cam cam)
// {
// 	t_screen	*screen;
// 	long double		x;
// 	long double		y;
// 	long double		z;

// 	screen = malloc(sizeof(t_screen));
// 	normalisator(cam.dir);
// 	normalisator(cam.up);
// 	normalisator(cam.right);
// 	x = cam.dir.x * SCR_DIST + cam.up.x * SCR_H - cam.right.x * SCR_L;
// 	y = cam.dir.y * SCR_DIST + cam.up.y * SCR_H - cam.right.y * SCR_L;
// 	z = cam.dir.z * SCR_DIST + cam.up.z * SCR_H - cam.right.z * SCR_L;
// 	screen->upleft = new_t_vec(x, y, z);
// 	return (screen);
// }

// void			matrix_printator(long double **mat, int i, int j)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < i)
// 	{
// 		x = 0;
// 		while (x < j)
// 		{
// 			printf("%f", mat[y][x]);
// 			if (x != j - 1)
// 				printf(",");
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }



long double			**mat_inversator(long double **m)
{
	long double	det;
	long double	**m2;
	int		i;

	i = 0;
	m2 = (long double**)malloc(sizeof(long double*) * 3);
	while (i < 3)
	{
		m2[i] = (long double*)malloc(sizeof(long double) * 3);
		i++;
	}
	det = m[0][0] * m[1][1] * m[2][2] 
	+ m[0][1] * m[1][2] * m[2][0]
	+ m[0][2] * m[1][0] * m[2][1]
	- m[0][2] * m[1][1] * m[2][0]
	- m[1][2] * m[2][1] * m[0][0]
	- i * m[0][1] * m[1][0];
	det = (m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1]))
	- (m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]))) 
	+ (m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0]))));
	/* det = m[0][0] * m[1][1] * m[2][1]
	 + m[0][1] * m[1][2] * m[2][0]
	 + m[0][2] * m[1][0] * m[2][2]
	 - m[0][2] * m[1][1] * m[2][0]
	 - m[1][2] * m[2][2] * m[0][0] 
	 - m[2][1] * m[0][1] * m[1][0];*/
	m2[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
	m2[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
	m2[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
	m2[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
	m2[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
	m2[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
	m2[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
	m2[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
	m2[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
	// printf("DET = %f\n", det);
	// ft_putendl("MAT A LENDROIT");
	//matrix_printator(m, 3, 3);
	// ft_putendl("MAT A LENVERS");
	//matrix_printator(m2, 3, 3);
	return (m2);
}

long double		**eulerator(t_cam cam)
{
	double	alpha;
	double	beta;
	double	gamma;
	long double	**mat;
	long double	**mat2;
	int		i;

	i = -1;
	// printf("EULERATOR\n");
	mat = (long double**)malloc(sizeof(long double*) * 3);
	while (++i < 3)
		mat[i] = (long double*)malloc(sizeof(long double) * 3);
	i = -1;
	alpha = atan(cam.dir.x / cam.dir.y);
	beta = 0;//cam.angle;
	gamma = asin(cam.dir.z / sqrt(cam.dir.x * cam.dir.x / cam.dir.y * cam.dir.y));
	mat[0][0] = cos(gamma) * cos(alpha) - sin(alpha) * cos(beta) * sin(gamma);
	mat[0][1] = cos(gamma) * sin(alpha) + sin(gamma) * cos(beta) * cos(alpha);
	mat[0][2] = sin(gamma) * sin(beta);
	mat[1][0] = -sin(gamma) * cos(alpha) - cos(gamma) * cos (beta) * cos(alpha);
	mat[1][1] = -sin(gamma) * sin(alpha) - cos(gamma) * cos(beta) * cos(alpha);
	mat[1][2] = cos(gamma) * sin(beta);
	mat[2][0] = sin(beta) * sin(alpha);
	mat[2][1] = -sin(beta) * cos(alpha);
	mat[2][2] = cos(beta);
	// ft_putendl("MAT A LENDROIT");
	//matrix_printator(mat, 3, 3);
	mat2 = mat_inversator(mat);
	return (mat2);
}

t_v			mat_33_31_mult(long double **m1, t_v v)
{
	t_v			m3;

	m3.x = (m1[0][0] * v.x) + (m1[0][1] * v.y) + (m1[0][2] * v.z);
	m3.y = (m1[1][0] * v.x) + (m1[1][1] * v.y) + (m1[1][2] * v.z);
	m3.z = (m1[2][0] * v.x) + (m1[2][1] * v.y) + (m1[2][2] * v.z);
	return (m3);
}

// t_vec			*set_cam_up(long double **mat)
// {
// 	long double	**m2;
// 	long double	**m3;
// 	int		i;

// 	i = -1;
// 	m2 = (long double**)malloc(sizeof(long double*) * 3);
// 	while (++i < 3)
// 		m2[i] = (long double*)malloc(sizeof(long double));
// 	m2[0][0] = 0;
// 	m2[1][0] = 1;
// 	m2[2][0] = 0;
// 	m3 = mat_33_31_mult(mat, m2);
	// ft_putendl("MAT UP");
// 	matrix_printator(m3, 3, 1);
// 	return (new_t_vec(m3[0][0], m3[1][0], m3[2][0]));
// }

// t_vec			*set_cam_right(long double **mat)
// {
// 	long double	**m2;
// 	long double	**m3;
// 	int		i;

// 	i = -1;
// 	m2 = (long double**)malloc(sizeof(long double*) * 3);
// 	while (++i < 3)
// 		m2[i] = (long double*)malloc(sizeof(long double));
// 	m2[0][0] = 0;
// 	m2[1][0] = 0;
// 	m2[2][0] = 1;
// 	m3 = mat_33_31_mult(mat, m2);
	// ft_putendl("MAT RIGHT");
// 	matrix_printator(m3, 3, 1);
// 	return (new_t_vec(m3[0][0], m3[1][0], m3[2][0]));
// }

// t_cam			*set_cam(char **t)
// {
// 	t_cam	cam;
// 	long double	**mat;

// 	cam = malloc(sizeof(t_cam));
// 	cam.pos = new_t_vec(ft_fatoi(t[1]), ft_fatoi(t[2]), ft_fatoi(t[3]));
// 	cam.dir = new_t_vec(ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]));
// 	cam.angle = ft_fatoi(t[7]);
// 	mat = eulerator(cam);
// 	cam.up = set_cam_up(mat);
// 	cam.right = set_cam_right(mat);
// 	return (cam);
// }

// void			check_check(t_check check)
// {
// 	if (check.cam == 0)
// 		ft_error("ray charles");
// 	if (check.item == 0)
// 		ft_error("no toy");
// 	if (check.light == 0)
// 		ft_error("the sun is broken");
// }

// int				tlen(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 		i++;
// 	return (i);
// }

// void			get_file(t_env *e, char *name)
// {
// 	char	*line;
// 	char	**t;
// 	int		fd;
// 	t_check	check;
// 	t_item	*item;
// 	t_light	*light;
// 	int		i;


// 	i = 0;
// 	check.cam = 0;
// 	check.item = 0;
// 	check.light = 0;
// 	e->item = new_t_item();
// 	item = e->item;
// 	e->light = new_t_light();
// 	light = e->light;
// 	if ((fd = open(name, O_RDONLY)) == -1)
// 		ft_error("error");
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		printf("ligne gnl%d = %s\n", i, line);
// 		i++;
// 		t = ft_strsplit(line, ' ');
// 		if (strcmp(t[0], "cam") == 0)
// 		{
// 			if (tlen(t) != 8)
// 				ft_error("mauvais format de fichier1");
// 			e->cam = set_cam(t);
// 			e->screen = set_screen(e->cam);
// 			check.cam++;
// 		}
// 		else if (strcmp(t[0], "sphere") == 0 || strcmp(t[0], "plane") == 0)
// 		{
			// ft_putendl("ITEM");
// 			if (strcmp(t[0], "sphere") == 0 && tlen(t) != 6)
// 				ft_error("mauvais format de fichier2");
// 			if (strcmp(t[0], "plane") == 0 && tlen(t) != 8)
// 				ft_error("mauvais format de fichier3");
// 			check.item++;
// 			if (e->item->next != NULL)
// 				e->item = e->item->next;
// 			e->item = fill_t_item(t, e->item);
// 			e->item->next = new_t_item();
// 		}
// 		else if (strcmp(t[0], "lum") == 0)
// 		{
			// ft_putendl("LIGHT");
// 			if (tlen(t) != 7)
// 				ft_error("mauvais format de fichier4");
// 			check.light++;
// 			if (e->light->next != NULL)
// 				e->light = e->light->next;
// 			e->light = fill_t_light(t, e->light);
// 			e->light->next = new_t_light();
// 		}
// 		else
// 			ft_error("mauvais format de fichier5");
// 	}
// 	e->light->next = NULL;
// 	e->item->next = NULL;
// 	e->light = light;
// 	e->item = item;
// 	check_check(check);
// }
