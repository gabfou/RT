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
