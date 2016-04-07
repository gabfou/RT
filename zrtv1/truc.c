/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:15:18 by jromagna          #+#    #+#             */
/*   Updated: 2016/02/16 17:15:19 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void			matrix_printator(FLOAT_SIZE **mat, int i, int j)
{
	int	x;
	int	y;

	y = 0;
	while (y < i)
	{
		x = 0;
		while (x < j)
		{
			printf("%f", mat[y][x]);
			if (x != j - 1)
				printf(",");
			x++;
		}
		printf("\n");
		y++;
	}
}



FLOAT_SIZE			**mat_inversator(FLOAT_SIZE **m)
{
	FLOAT_SIZE	det;
	FLOAT_SIZE	**m2;
	int		i;

	i = 0;
	m2 = (FLOAT_SIZE**)malloc(sizeof(FLOAT_SIZE*) * 3);
	while (i < 3)
	{
		m2[i] = (FLOAT_SIZE*)malloc(sizeof(FLOAT_SIZE) * 3);
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
	 det = m[0][0] * m[1][1] * m[2][1]
	 + m[0][1] * m[1][2] * m[2][0]
	 + m[0][2] * m[1][0] * m[2][2]
	 - m[0][2] * m[1][1] * m[2][0]
	 - m[1][2] * m[2][2] * m[0][0] 
	 - m[2][1] * m[0][1] * m[1][0];
	m2[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
	m2[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
	m2[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
	m2[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
	m2[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
	m2[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
	m2[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
	m2[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
	m2[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
	printf("DET = %f\n", det);
	ft_putendl("MAT A LENDROIT");
	matrix_printator(m, 3, 3);
	ft_putendl("MAT A LENVERS");
	matrix_printator(m2, 3, 3);
	return (m2);
}

FLOAT_SIZE		**eulerator(t_cam *cam)
{
	FLOAT_SIZE	alpha;
	FLOAT_SIZE	beta;
	FLOAT_SIZE	gamma;
	FLOAT_SIZE	**mat;
	FLOAT_SIZE	**mat2;
	int		i;

	i = -1;
	printf("EULERATOR\n");
	mat = (FLOAT_SIZE**)malloc(sizeof(FLOAT_SIZE*) * 3);
	while (++i < 3)
		mat[i] = (FLOAT_SIZE*)malloc(sizeof(FLOAT_SIZE) * 3);
	i = -1;
	alpha = atan(cam->dir->x / cam->dir->z);
	beta = cam->angle;
	gamma = asin(cam->dir->y / sqrt(carre(cam->dir->x) / carre(cam->dir->z)));
	mat[0][0] = cos(gamma) * cos(alpha) - sin(alpha) * cos(beta) * sin(gamma);
	mat[0][1] = cos(gamma) * sin(alpha) + sin(gamma) * cos(beta) * cos(alpha);
	mat[0][2] = sin(gamma) * sin(beta);
	mat[1][0] = -sin(gamma) * cos(alpha) - cos(gamma) * cos (beta) * cos(alpha);
	mat[1][1] = -sin(gamma) * sin(alpha) - cos(gamma) * cos(beta) * cos(alpha);
	mat[1][2] = cos(gamma) * sin(beta);
	mat[2][0] = sin(beta) * sin(alpha);
	mat[2][1] = -sin(beta) * cos(alpha);
	mat[2][2] = cos(beta);
	ft_putendl("MAT A LENDROIT");
	matrix_printator(mat, 3, 3);
	mat2 = mat_inversator(mat);
	return (mat2);
}

FLOAT_SIZE			**mat_33_31_mult(FLOAT_SIZE **m1, FLOAT_SIZE **m2)
{
	FLOAT_SIZE		**m3;
	int			i;

	i = -1;
	m3 = (FLOAT_SIZE**)malloc(sizeof(FLOAT_SIZE*) * 3);
	while (++i < 3)
		m3[i] = (FLOAT_SIZE*)malloc(sizeof(FLOAT_SIZE));
	m3[0][0] = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]);
	m3[1][0] = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]);
	m3[2][0] = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]);
	return (m3);
}

t_vec			*set_cam_up(FLOAT_SIZE **mat)
{
	FLOAT_SIZE	**m2;
	FLOAT_SIZE	**m3;
	int		i;

	i = -1;
	m2 = (FLOAT_SIZE**)malloc(sizeof(FLOAT_SIZE*) * 3);
	while (++i < 3)
		m2[i] = (FLOAT_SIZE*)malloc(sizeof(FLOAT_SIZE));
	m2[0][0] = 0;
	m2[1][0] = 1;
	m2[2][0] = 0;
	m3 = mat_33_31_mult(mat, m2);
	ft_putendl("MAT UP");
	matrix_printator(m3, 3, 1);
	return (new_t_vec(m3[0][0], m3[1][0], m3[2][0]));
}

t_vec			*set_cam_right(FLOAT_SIZE **mat)
{
	FLOAT_SIZE	**m2;
	FLOAT_SIZE	**m3;
	int		i;

	i = -1;
	m2 = (FLOAT_SIZE**)malloc(sizeof(FLOAT_SIZE*) * 3);
	while (++i < 3)
		m2[i] = (FLOAT_SIZE*)malloc(sizeof(FLOAT_SIZE));
	m2[0][0] = 0;
	m2[1][0] = 0;
	m2[2][0] = 1;
	m3 = mat_33_31_mult(mat, m2);
	ft_putendl("MAT RIGHT");
	matrix_printator(m3, 3, 1);
	return (new_t_vec(m3[0][0], m3[1][0], m3[2][0]));
}


void			get_file(t_env *e, char *name)
{
	char	**t;
	int		fd;
	t_check	check;
	t_item	*item;
	t_light	*light;
	int		ret;
	int		i;
	int		j;
	char	b[16000];
	char	*tmp;
	char	**file;


	i = 0;
	j = 0;
	ret = 0;
	tmp = NULL;
	check.cam = 0;
	check.item = 0;
	check.light = 0;
	e->item = new_t_item();
	item = e->item;
	e->light = new_t_light();
	light = e->light;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, b, sizeof(b))) > 0)
	{
		tmp = ft_strjoin(tmp, b);
	}
	file = ft_strsplit(b, '\n');
	while (j < ret)
	{
		printf("ligne gnl%d = %s\n", i, file[j]);
		t = ft_strsplit(file[j], ' ');
		ft_puttab(t);
		if (strcmp(t[0], "cam") == 0)
		{
			ft_putendl("CAM");
			if (tlen(t) != 8)
				ft_error("mauvais format de fichier1");
			e->cam = set_cam(t);
			e->screen = set_screen(e->cam);
			check.cam++;
		}
		else if (strcmp(t[0], "sphere") == 0 || strcmp(t[0], "plane") == 0)
		{
			ft_putendl("ITEM");
			if (strcmp(t[0], "sphere") == 0 && tlen(t) != 6)
				ft_error("mauvais format de fichier2");
			if (strcmp(t[0], "plane") == 0 && tlen(t) != 8)
				ft_error("mauvais format de fichier3");
			check.item++;
			if (e->item->next != NULL)
				e->item = e->item->next;
			e->item = fill_t_item(t, e->item);
			e->item->next = new_t_item();
		}
		else if (strcmp(t[0], "lum") == 0)
		{
			ft_putendl("LIGHT");
			if (tlen(t) != 7)
				ft_error("mauvais format de fichier4");
			check.light++;
			if (e->light->next != NULL)
				e->light = e->light->next;
			e->light = fill_t_light(t, e->light);
			e->light->next = new_t_light();
		}
		else
		{
			printf(" ERROR ligne gnl%d = %s\n", i, file[j]);
			ft_error("mauvais format de fichier5");
		}
		i++;
		j++;
	}
	e->light->next = NULL;
	e->item->next = NULL;
	e->light = light;
	e->item = item;
	check_check(check);
}*/

// t_item			*fill_t_item(char **t, t_item *item)
// {
// 	if (ft_strcmp(t[0], "sphere") == 0)
// 	{
// 		// ft_putendl("CECI EST UNE SPHERE");
// 		item->sp = new_t_sphere(ft_fatoi(t[1]), ft_fatoi(t[2]),
// 		ft_fatoi(t[3]), ft_fatoi(t[4]));
// 		item->mat = new_t_mat(t[5]);
// 		item->mat->diff = new_t_color(1, 1, 1);
// 		item->mat->trans = 50;
// 	}
// 	if (ft_strcmp(t[0], "plane") == 0)
// 	{
// 		// ft_putendl("cECI EST UNE PLAN");
// 		item->pl = t_plane_creator(ft_fatoi(t[1]), ft_fatoi(t[2]),
// 		ft_fatoi(t[3]), ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]));
// 		item->mat = new_t_mat(t[7]);
// 		item->mat->diff = new_t_color(1, 1, 1);
// 	}
// 	if (ft_strcmp(t[0], "cyl") == 0)
// 	{
// 		// ft_putendl("cECI EST UN CYLINDRE");
// 		item->cyl = t_cyl_creator(ft_fatoi(t[1]), ft_fatoi(t[2]),
// 		ft_fatoi(t[3]), ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]), ft_fatoi(t[7]));
// 		item->mat = new_t_mat(t[8]);
// 		item->mat->diff = new_t_color(1, 1, 1);
// 	}
// 	if (ft_strcmp(t[0], "cone") == 0)
// 	{
// 		// ft_putendl("cECI EST UN CONE");
// 		item->con = t_con_creator(ft_fatoi(t[1]), ft_fatoi(t[2]),
// 		ft_fatoi(t[3]), ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]), ft_fatoi(t[7]));
// 		item->mat = new_t_mat(t[8]);
// 		item->mat->diff = new_t_color(1, 1, 1);
// 	}
// 	return (item);
// }

// t_vec		*set_screen(t_cam *cam)
// {
// 	float		x;
// 	float		y;
// 	float		z;

// 	x = cam->dir->x * SCR_DIST - cam->up->x * SCR_H - cam->right->x * SCR_L;
// 	y = cam->dir->y * SCR_DIST - cam->up->y * SCR_H - cam->right->y * SCR_L;
// 	z = cam->dir->z * SCR_DIST - cam->up->z * SCR_H - cam->right->z * SCR_L;
// 	return (new_t_vec(x, y, z));
// 	// print_vec(screen->upleft);
// }

// t_screen		*set_screen(t_cam *cam)
// {
// 	t_screen	*screen;
// 	float		x;
// 	float		y;
// 	float		z;

// 	screen = malloc(sizeof(t_screen));
// 	normalizator(cam->dir);
// 	normalizator(cam->up);
// 	normalizator(cam->right);
// 	x = cam->dir->x * SCR_DIST - cam->up->x * SCR_H - cam->right->x * SCR_L;
// 	y = cam->dir->y * SCR_DIST - cam->up->y * SCR_H - cam->right->y * SCR_L;
// 	z = cam->dir->z * SCR_DIST - cam->up->z * SCR_H - cam->right->z * SCR_L;
// 	screen->upleft = new_t_vec(x, y, z) ;
// 	// print_vec(screen->upleft);
// 	return (screen);
// }

// t_cam			*set_cam(char **t)
// {
// 	t_cam	*cam;

// 	cam = malloc(sizeof(t_cam));
// 	cam->pos = new_t_vec(ft_fatoi(t[1]), ft_fatoi(t[2]), ft_fatoi(t[3]));
// 	cam->dir = (new_t_vec(ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6])));
// 	cam->angle = ft_fatoi(t[7]);
// 	normalizator(cam->dir);
// 	if (cam->dir->x == 0 && cam->dir->z == 0 && (cam->dir->y == 1 || cam->dir->y == -1))
// 		cam->up = new_t_vec(1, 0, 0);
// 	else
// 		cam->up = new_t_vec(0, 1, 0);
// 	cam->right = prod_vector(cam->dir, cam->up);
// 	// ft_putendl("right");
// 	normalizator(cam->right);
// 	// print_vec(cam->right);
// 	cam->up = prod_vector(cam->dir, cam->right);
// 	// ft_putendl("up");
// 	// print_vec(cam->up);
// 	return (cam);
// }

// void			mega_initiator(t_env *e, char *name)
// {
// 	t_item	*item;
// 	t_light	*light;
// 	char	**t;
// 	t_check	check;
// 	int		i;
// 	char	**line;

// 	// ft_putendl("MEGA UNIT0");
// 	i = 0;
// 	e->item = new_t_item();
// 	item = e->item; 
// 	e->light = new_t_light();
// 	light = e->light;
// 	// ft_putendl("MEGA UNIT1");
// 	t = file_to_tab(name);
// 	// ft_putendl("MEGA UNIT 2");
// 	// ft_puttab(t);
// 	while (t[i] && t[i][0] != '\0')
// 	{
// 		// ft_putendl("line pre split");
// 		// ft_putendl(t[i]);
// 		line = ft_strsplit(t[i], ' ');
// 		if(line[0][0] == '#')
// 		{
// 			i++;
// 			continue;
// 		}
// 		// ft_putendl("la ligne est");
// 		// ft_puttab(line);
// 		if (ft_strcmp(line[0], "cam") == 0)
// 		{
// 			// ft_putendl("CAM");
// 			if (tlen(line) != 8)
// 				ft_error("mauvais format de fichier CAM");
// 			e->cam = set_cam(line);
// 			e->screen = set_screen(e->cam);
// 			check.cam++;
// 		}
// 		else if (ft_strcmp(line[0], "sphere") == 0 || ft_strcmp(line[0], "plane") == 0 || ft_strcmp(line[0], "cyl") == 0 || ft_strcmp(line[0], "cone") == 0)
// 		{
// 			// ft_putendl("ITEM");
// 			if (ft_strcmp(line[0], "sphere") == 0 && tlen(line) != 6)
// 				ft_error("mauvais format de fichier SPHERE");
// 			if (ft_strcmp(line[0], "plane") == 0 && tlen(line) != 8)
// 				ft_error("mauvais format de fichier PLAN");
// 			if (ft_strcmp(line[0], "cyl") == 0 && tlen(line) != 9)
// 				ft_error("mauvais format de fichier PLAN");
// 			if (ft_strcmp(line[0], "cone") == 0 && tlen(line) != 9)
// 				ft_error("mauvais format de fichier PLAN");
// 			check.item++;
// 			if (e->item->next != NULL)
// 				e->item = e->item->next;
// 			e->item = fill_t_item(line, e->item);
// 			e->item->next = new_t_item();
// 		}
// 		else if (ft_strcmp(line[0], "lum") == 0)
// 		{
// 			// ft_putendl("LIGHT");
// 			if (tlen(line) != 7)
// 				ft_error("mauvais format de fichier LUM");
// 			check.light++;
// 			if (e->light->next != NULL)
// 				e->light = e->light->next;
// 			e->light = fill_t_light(line, e->light);
// 			e->light->next = new_t_light();
// 		}
// 		else
// 		{
// 			printf(" ERROR ligne gnl%d = %s\n", i, line[0]);
// 			ft_error("mauvais format de fichier TOUT");
// 		}
// 		i++;
// 	}
// 	e->light->next = NULL;
// 	e->item->next = NULL;
// 	e->light = light;
// 	e->item = item;
// 	check_check(check);
// }
/*
void			get_file(t_env *e, char *name)
{
	char	**t;
	int		fd;
	t_check	check;
	t_item	*item;
	t_light	*light;
	int		ret;
	int		i;
	int		j;
	char	b[16000];
	char	*tmp;
	char	**file;


	i = 0;
	j = 0;
	ret = 0;
	tmp = NULL;
	check.cam = 0;
	check.item = 0;
	check.light = 0;
	e->item = new_t_item();
	item = e->item;
	e->light = new_t_light();
	light = e->light;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, b, sizeof(b))) > 0)
	{
		tmp = ft_strjoin(tmp, b);
	}
	file = ft_strsplit(b, '\n');
	while (j < ret)
	{
		printf("ligne gnl%d = %s\n", i, file[j]);
		t = ft_strsplit(file[j], ' ');
		ft_puttab(t);
		if (ft_strcmp(t[0], "cam") == 0)
		{
			ft_putendl("CAM");
			if (tlen(t) != 8)
				ft_error("mauvais format de fichier1");
			e->cam = set_cam(t);
			e->screen = set_screen(e->cam);
			check.cam++;
		}
		else if (ft_strcmp(t[0], "sphere") == 0 || ft_strcmp(t[0], "plane") == 0)
		{
			ft_putendl("ITEM");
			if (ft_strcmp(t[0], "sphere") == 0 && tlen(t) != 6)
				ft_error("mauvais format de fichier2");
			if (ft_strcmp(t[0], "plane") == 0 && tlen(t) != 8)
				ft_error("mauvais format de fichier3");
			check.item++;
			if (e->item->next != NULL)
				e->item = e->item->next;
			e->item = fill_t_item(t, e->item);
			e->item->next = new_t_item();
		}
		else if (ft_strcmp(t[0], "lum") == 0)
		{
			ft_putendl("LIGHT");
			if (tlen(t) != 7)
				ft_error("mauvais format de fichier4");
			check.light++;
			if (e->light->next != NULL)
				e->light = e->light->next;
			e->light = fill_t_light(t, e->light);
			e->light->next = new_t_light();
		}
		else
		{
			printf(" ERROR ligne gnl%d = %s\n", i, file[j]);
			ft_error("mauvais format de fichier5");
		}
		i++;
		j++;
	}
	e->light->next = NULL;
	e->item->next = NULL;
	e->light = light;
	e->item = item;
	check_check(check);
}*/
