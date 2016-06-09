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
	e->item = new_t_item(env);
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
			e->item->next = new_t_item(env);
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
}



// typedef	struct		s_screen
// {
// 	t_vec			upleft;
// }					t_screen;

// typedef	struct		s_cam
// {
// 	t_vec			pos;
// 	t_vec			dir;
// 	t_vec			up;
// 	t_vec			right;
// 	FLOAT_SIZE			angle;
// }					t_cam;

// typedef	struct		s_thr
// {
// 	FLOAT_SIZE			minx;
// 	FLOAT_SIZE			maxx;
// 	FLOAT_SIZE			miny;
// 	FLOAT_SIZE			maxy;
// 	unsigned int	fcolor;
// 	t_inter			inter;
// 	t_item			*item;
// 	t_light			*light;
// }				t_thr;

// typedef	struct		s_env
// {
// 	void			*mlx;
// 	void			*win;
// 	void			*image;
// 	char			*img;
// 	int				**t;
// 	int				bpp;
// 	int				endiant;
// 	int				sline;

// 	t_cam			*cam;
// 	t_screen		*screen;
// 	t_item			*item;
// 	t_light			*light;
// 	t_inter			inter;
// 	unsigned int	fcolor;
// 	int				done;
// 	int				l;
// 	int				i;
	
// }		
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
// 	e->item = new_t_item(env);
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
// 			e->item->next = new_t_item(env);
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
	e->item = new_t_item(env);
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
			e->item->next = new_t_item(env);
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

	// void		parser_test(t_env *env)
// {
// 	t_item *lst;
// 	t_light *lum;
// 	int		i;

// 	i = 0;
// 	lum = env->light;
// 	lst = env->item;
// 	printf("CAM posx %f posy %f posz %f\n", env->cam->pos->x, env->cam->pos->y, env->cam->pos->z);
// 	printf("CAM dirx %f diry %f dirz %f\n", env->cam->dir->x, env->cam->dir->y, env->cam->dir->z);
// 	while (lst != NULL)
// 	{
// 		i++;
// 		ft_putnbr(i);
// 		if (lst->sp != NULL)
// 			printf("%d SP posx %f posy %f posz %f ray %f\n", i, lst->sp->c->x, lst->sp->c->y, lst->sp->c->z, lst->sp->ray);
// 		if (lst->pl != NULL)
// 		{
// 			printf("%d PL posx %f posy %f posz %f\n", i, lst->pl->pos->x, lst->pl->pos->y, lst->pl->pos->z);
// 			printf("%d PL dirx %f diry %f dirz %f\n", i, lst->pl->dir->x, lst->pl->dir->y, lst->pl->dir->z);
// 		}
// 		lst = lst->next;
// 	}
// 	while (lum != NULL)
// 	{
// 		i++;
// 		ft_putnbr(i);
// 		printf("%d LUM posx %f posy %f posz %f\n", i, lum->pos->x, lum->pos->y, lum->pos->z);
// 		lum = lum->next;
// 	}
// 	ft_putendl("parser_test fin");
// }
	/*

inline long FLOAT_SIZE	cotestor(t_vec v, t_env *e, t_vec dir, t_con *s)
{
	register long FLOAT_SIZE	a;
	register long FLOAT_SIZE	b;
	register long FLOAT_SIZE 	c;
	register long FLOAT_SIZE	d;
	t_vec						l;

	(void)l;
	l = sub_vec(v, s->p);

	a = dot_prod(dir, dir) - (1.0 + tan(s->a) * tan(s->a)) * (dot_prod(dir, s->v) *  dot_prod(dir, s->v));

	b = 2 * (dot_prod(dir, l) - (1.0 + tan(s->a) * tan(s->a)) * (dot_prod(dir, s->v) * dot_prod(l, s->v)));

	c = dot_prod(l, l) - (1.0 + tan(s->a) * tan(s->a)) * (dot_prod(l, s->v) * dot_prod(l, s->v));

	if ((d = (b * b - 4.0 * a * c)) < 0)
		return (-1);

	d = ft_min(((-b + sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));

	if (d < 0 || d > e->d)
		return (-1);

	l = vav(v, ps(dir, d));

	// if (s->h != -1 && normecalculator(sub_vec(l, s->p)) > s->h)
	// 	return (-1);

	// e->d = d;

	if (!e->testor)
		return (d);

	v = normalisator(sub_vec(vector_proj_vector(normalisator(sub_vec(s->p, l)), s->v), normalisator(sub_vec(s->p, l))));
	e->pixelmirror = 0;
	e->vl = v;
	e->pl = l;
	e->c2 = s->color;
	return (d);
}
*/

// void		creator(t_cor *c)
// {
// 	double		x;
// 	double		y;
// 	t_pd		*pd;
// 	t_thr		*f;
// 	int			l;

// 	// ft_check(env);
// 	f = malloc(sizeof(t_thr));
// 	f->minx = c->minx;
// 	f->maxx = c->maxx;
// 	f->miny = c->miny;
// 	f->maxy = c->maxy;
// 	f->item = c->env->item;
// 	f->light = c->env->light;
// 	printf("xmin = %f xmax = %f ymin = %f ymax = %f\n", f->minx, f->maxx, f->miny, f->maxy);
// 	usleep(10000);
// 	// ft_putendl("thread check");
// 	// printf("xmin = %f xmax = %f ymin = %f ymax = %f\n",f->minx, f->maxx, f->miny, f->maxy);
// 	// ft_putendl("DEBUUUT");
// 	l = 0;
// 	y = f->miny;
// 	pd = new_t_pd();
// 	//pd->pos = c->env->cam->pos;
// 	pd->dir = new_t_vec(0,0,0);
// 	// ft_putendl("LAAAAAAAAA");
// 	while (y < f->maxy)
// 	{
// 		x = f->minx;
// 		while (x < f->maxx)
// 		{
// 			//ft_putendl("boucle");
// 			pd->pos = c->env->cam->pos;
// 			f->fcolor = 0x000000;
// 			f->inter = new_t_inter();
// 			t_inter_set(f->inter);
// 			calc_dir(c->env, pd->dir, x, y);
// 			// printf("\nx = %f y = %f", x, y );
// 			//if (x == 1 && ((int)y % 100 == 0))
// 				//print_vec(pd->dir);
// 			//print_vec(pd->pos);
// 			impactor(c->env, pd, f, f->inter);
// 			set_inter_pos(f->inter, pd);
// 			luminator(c->env, f);
// 			//if (f-> inter.t > 0 )
// 			//	pixel_to_image(c->env, x, y, 0xFF0000); 
// 			pixel_to_image(c->env, x, y, f->fcolor);
// 			//if (f->fcolor == 0)
// 			//	printf("\nx = %f y = %f", x, y );
// 			// if (x == f->minx && y == f->miny)
// 			// 	printf("color = %d\n", f->fcolor);


// 			// if (f->minx == 0 && f->miny == 0)
// 			// { 
// 			// 	ft_putendl("pre");
// 			// 	loadator(H_SIZE, L_SIZE, c->env, l++);
// 			// 	ft_putendl("post");
// 			// }
// 			c->env->l++;
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// 	//antialiasing(env);
// 	c->env->i++;
// 	pthread_exit(NULL);
// }

// void		calc_dir(t_env *env, t_vec *dir, FLOAT_SIZE x, FLOAT_SIZE y)
// {
// 	//ft_putendl("calc dir");
// 	// printf("cdx = %f cdy = %f cdz = %f\n", env->cam->dir.x, env->cam->dir.y, env->cam->dir.z);
// 	// printf("cux = %f cuy = %f cuz = %f\n", env->cam->up.x, env->cam->up.y, env->cam->up.z);
// 	// printf("crx = %f cry = %f crz = %f\n\n", env->cam->right.x, env->cam->right.y, env->cam->right.z);
// 	//ft_putendl("qwerqwer");
// 	dir.x = (env->screen->upleft.x + (env->cam->up.x * f->env->screen.scrh * y / f->env->screen.resh) + (env->cam->right.x * f->env->screen.scrl * x / f->env->screen.resl))/* - env->cam->pos.x*/;
// 	dir.y = (env->screen->upleft->y + (env->cam->up.y * f->env->screen.scrh * y / f->env->screen.resh) + (env->cam->right.y * f->env->screen.scrl * x / f->env->screen.resl))/* - env->cam->pos.y*/;
// 	dir.z = (env->screen->upleft->z + (env->cam->up.z * f->env->screen.scrh * y / f->env->screen.resh) + (env->cam->right.z * f->env->screen.scrl * x / f->env->screen.resl))/* - env->cam->pos.z*/;
// // 	dir.x = (env->cam->dir.x * SCR_DIST) + (env->cam->up.x * f->env->screen.scrh * y /480) + (env->cam->right.x * f->env->screen.scrl * x /480);
// // 	//ft_putendl("calc dir2");
// // 	dir.y = (env->cam->dir.y * SCR_DIST) + (env->cam->up.y * f->env->screen.scrh * y /480) + (env->cam->right.y * f->env->screen.scrl * x /480);
// // 	//ft_putendl("calc dir3");
// // 	dir.z = (env->cam->dir.z * SCR_DIST) + (env->cam->up.z * f->env->screen.scrh * y /480) + (env->cam->right.z * f->env->screen.scrl * x /480);
// // 	//ft_putendl("calc dir4");
// // //	printf("cdx = %f cdy = %f cdz = %f\n", dir.x, dir.y, dir.z);
// 	normalizator (dir);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 22:16:26 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/23 22:16:27 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_bzero(char *b, int i)
{
	while (i >= 0)
	{
		if (b[i] == '\0')
			return (1);
		i--;
	}
	return (0);
}

int		la_magicienne(char *name)
{
	int		fd;
	char	b[16000];
	int		ret;
	int		i;
	int		l;

	errno = 0;
	l = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, b, sizeof(b))) > 0)
	{
		if (check_bzero(b, ret - 1) == 1)
			ft_error("yameteee!");
		i = -1;
		while (++i <= ret)
		{
			if (b[i] == '\n')
				l++;
		}
		b[ret] = '\0';
	}
	close(fd);
	return (l);
}

void		put_endl_in_file(char *name)
{
	int		fd;
	int		errno;
	char	buf[9];
	int		ret;

	errno = 0;
	if ((fd = open(name, O_RDWR | O_APPEND)) == -1)
		ft_error("error");
	while ((ret = read(fd, buf, 8)) > 0)
		buf[ret] = '\0';
	ret = ft_strlen(buf);
	if (buf[ret - 1] != '\n')
		ft_putstr_fd("\n", fd);
}

void			recuperator(t_env *e, char *name)
{
	int		l;
	(void)e;

	put_endl_in_file(name);
	l = la_magicienne(name);
	//mega_initiator(e, name);
}

t_limg	*readerbmp32(char *name)
{
	t_header		fh;
	t_header_info	ih;
	int				i;
	int				j;
	int				k;
	t_limg			*ret;
	int				fd_img;
	char			*image;

	ft_putendl(name);
	fd_img = open(name, O_RDONLY);
	read(fd_img, &fh, sizeof(t_header));
	read(fd_img, &ih, sizeof(t_header_info));
	printf("fM1 = %c, fM2 = %c, bfS = %u, un1 = %hu, un2 = %hu, iDO = %u\n",
		fh.fileMarker1, fh.fileMarker2, fh.bfSize, fh.unused1, fh.unused2, fh.imageDataOffset);
	printf("w = %d, h = %d, bsi = %d\n", ih.width, ih.height, ih.bitPix);
	image = (char*)malloc(sizeof(char) * (fh.bfSize + 1));
	ret = malloc(sizeof(t_limg));
	ret->image = NULL;
	ret->img = (char*)malloc(sizeof(char) * (fh.bfSize + 1));
	ret->sline = ih.width;
	ret->bpp = 4;
	ret->prev = NULL;
	ret->next = NULL;
	read(fd_img, image, fh.bfSize);
	i = -1;
	j = -1;
	while (++j < ih.width && i < (int)fh.bfSize)
	{
		k = -1;
		while (++k < ih.height && i < (int)fh.bfSize)
		{
			ret->img[(ih.width - j) * ret->sline + k * ret->bpp / 8 + 3] = image[++i];
			ret->img[(ih.width - j) * ret->sline + k * ret->bpp / 8 + 2] = image[++i];
			ret->img[(ih.width - j) * ret->sline + k * ret->bpp / 8 + 1] = image[++i];
			ret->img[(ih.width - j) * ret->sline + k * ret->bpp / 8 + 0] = image[++i];
		}
	}
	return (ret);
}


// FLOAT_SIZE	fatoi_aux(char *str, FLOAT_SIZE *si, FLOAT_SIZE *di)
// {
// 	int			i;
// 	FLOAT_SIZE	k;

// 	i = 0;
// 	k = 0;
// 	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
// 			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
// 		i++;
// 	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
// 		return (0);
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		i++;
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 	}
// 	if (*si == 0)
// 		*si = (str[i - 1] == '-') ? -1 : 1;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		k = k * 10 + str[i] - '0';
// 		i++;
// 	}
// 	*di = i;
// 	return (k);
// }
