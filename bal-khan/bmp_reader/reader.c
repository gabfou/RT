#include "reader.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_header		fh;
	t_header_info	ih;

	int	fd_img;

	fd_img = open("./mickey.bmp", O_RDONLY);

	read(fd_img, &fh, sizeof(t_header));
	read(fd_img, &ih, sizeof(t_header_info));

	printf("fM1 = %c, fM2 = %c, bfS = %u, un1 = %hu, un2 = %hu, iDO = %u\n", fh.fileMarker1, fh.fileMarker2, fh.bfSize, fh.unused1, fh.unused2, fh.imageDataOffset);                                                                         
    printf("w = %d, h = %d\n", ih.width, ih.height);

    char	*image;

    image = (char *)malloc(sizeof(char) * (fh.bfSize + 1));

    read(fd_img, image, fh.bfSize);

    int		fd;
    fd = open("./my_micky.bmp", O_RDWR | O_CREAT);

    write(fd, &fh, sizeof(t_header));
    write(fd, &ih, sizeof(t_header_info));
    write(fd, image, fh.bfSize);

	return (0);
}
