#include "reader.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "rtv1.h"

void	readerbmp32(char *name, t_env *e)
{
	t_header		fh;
	t_header_info	ih;
	int				i;
	int				j;
	int				k;

	int	fd_img;

	e->i = NBTHREAD + 2;
	fd_img = open(name, O_RDONLY);

	read(fd_img, &fh, sizeof(t_header));
	read(fd_img, &ih, sizeof(t_header_info));

	printf("fM1 = %c, fM2 = %c, bfS = %u, un1 = %hu, un2 = %hu, iDO = %u\n", fh.fileMarker1, fh.fileMarker2, fh.bfSize, fh.unused1, fh.unused2, fh.imageDataOffset);
	printf("w = %d, h = %d\n, bsi = %d\n", ih.width, ih.height, ih.bitPix);
	if (ih.bitPix != 32)
		ft_error("fichier bmp non 32bit");

	char	*image;

	image = (char*)malloc(sizeof(char) * (fh.bfSize + 1));

	read(fd_img, image, fh.bfSize);
	i = -1;
	j = -1;
	while (++j < H_SIZE && i < (int)fh.bfSize)
	{
		k = -1;
		while (++k < L_SIZE && i < (int)fh.bfSize)
		{
			e->img[(H_SIZE - j) * e->sline + k * e->bpp / 8 + 3] = image[++i];
			e->img[(H_SIZE - j) * e->sline + k * e->bpp / 8 + 2] = image[++i];
			e->img[(H_SIZE - j) * e->sline + k * e->bpp / 8 + 1] = image[++i];
			e->img[(H_SIZE - j) * e->sline + k * e->bpp / 8 + 0] = image[++i];
		}
	}
	// write(fd, image, fh.bfSize);
}

char		*initkeytochar()
{
	char *tab;

	tab = malloc(1000);
	ft_bzero(tab, 1000);
	tab[12] = 'q';
	tab[13] = 'w';
	tab[14] = 'e';
	tab[15] = 'r';
	tab[17] = 't';
	tab[16] = 'y';
	tab[32] = 'u';
	tab[34] = 'i';
	tab[31] = 'o';
	tab[35] = 'p';
	tab[0] = 'a';
	tab[1] = 's';
	tab[2] = 'd';
	tab[3] = 'f';
	tab[5] = 'g';
	tab[4] = 'h';
	tab[38] = 'j';
	tab[40] = 'k';
	tab[37] = 'l';
	tab[6] = 'z';
	tab[7] = 'x';
	tab[8] = 'c';
	tab[9] = 'v';
	tab[11] = 'b';
	tab[45] = 'n';
	tab[46] = 'm';
	tab[18] = '1';
	tab[19] = '2';
	tab[20] = '3';
	tab[21] = '4';
	tab[23] = '5';
	tab[22] = '6';
	tab[26] = '7';
	tab[28] = '8';
	tab[25] = '9';
	tab[29] = '0';
	tab[83] = '1';
	tab[84] = '2';
	tab[85] = '3';
	tab[86] = '4';
	tab[87] = '5';
	tab[88] = '6';
	tab[89] = '7';
	tab[91] = '8';
	tab[92] = '9';
	tab[82] = '0';
	tab[36] = -1;
	tab[49] = ' ';
	return (tab);
}

char		keytochar(int key)
{
	static char *tab = NULL;

	if (!tab)
		tab = initkeytochar();
	return (tab[key]);
}

void	comander(int key)
{
	static char	stat[10000];
	char		keyret;
	static int	i = -1;

	keyret = keytochar(key);
	if (keyret == 0)
	{
		ft_putendl("what?");
		return;
	}
	if (i == -1)
		bzero(stat, 10000);
	if (i == -1)
		i = 0;
	if (keyret == -1)
	{
		write(1, "\nniark\n", 7);
		ft_putendl(stat);
		ft_bzero(stat);
	}
	else
		stat[i++] = keyret;
}
