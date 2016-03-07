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



void			matrix_printator(float **mat, int i, int j)
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



float			**mat_inversator(float **m)
{
	float	det;
	float	**m2;
	int		i;

	i = 0;
	m2 = (float**)malloc(sizeof(float*) * 3);
	while (i < 3)
	{
		m2[i] = (float*)malloc(sizeof(float) * 3);
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

float		**eulerator(t_cam *cam)
{
	float	alpha;
	float	beta;
	float	gamma;
	float	**mat;
	float	**mat2;
	int		i;

	i = -1;
	printf("EULERATOR\n");
	mat = (float**)malloc(sizeof(float*) * 3);
	while (++i < 3)
		mat[i] = (float*)malloc(sizeof(float) * 3);
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

float			**mat_33_31_mult(float **m1, float **m2)
{
	float		**m3;
	int			i;

	i = -1;
	m3 = (float**)malloc(sizeof(float*) * 3);
	while (++i < 3)
		m3[i] = (float*)malloc(sizeof(float));
	m3[0][0] = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]);
	m3[1][0] = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]);
	m3[2][0] = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]);
	return (m3);
}

t_vec			*set_cam_up(float **mat)
{
	float	**m2;
	float	**m3;
	int		i;

	i = -1;
	m2 = (float**)malloc(sizeof(float*) * 3);
	while (++i < 3)
		m2[i] = (float*)malloc(sizeof(float));
	m2[0][0] = 0;
	m2[1][0] = 1;
	m2[2][0] = 0;
	m3 = mat_33_31_mult(mat, m2);
	ft_putendl("MAT UP");
	matrix_printator(m3, 3, 1);
	return (new_t_vec(m3[0][0], m3[1][0], m3[2][0]));
}

t_vec			*set_cam_right(float **mat)
{
	float	**m2;
	float	**m3;
	int		i;

	i = -1;
	m2 = (float**)malloc(sizeof(float*) * 3);
	while (++i < 3)
		m2[i] = (float*)malloc(sizeof(float));
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
