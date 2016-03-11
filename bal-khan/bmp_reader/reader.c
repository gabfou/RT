/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 05:58:23 by bal-khan          #+#    #+#             */
/*   Updated: 2016/03/11 05:58:28 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void            reader(t_header *fh)
{
    int fd_img;

    fd_img = open("./imaage.bmp", O_RDONLY);
    read(fd_img, &(fh->file_marker1), sizeof(unsigned char));
    read(fd_img, &(fh->file_marker2), sizeof(unsigned char));
    read(fd_img, &(fh->bf_size), sizeof(unsigned int));
    read(fd_img, &(fh->unused1), sizeof(short));
    read(fd_img, &(fh->unused2), sizeof(short));
    read(fd_img, &(fh->image_data_offset), sizeof(unsigned int));
    read(fd_img, &(fh->bi_size), sizeof(unsigned int));
    read(fd_img, &(fh->width), sizeof(int));
    read(fd_img, &(fh->height), sizeof(int));
    read(fd_img, &(fh->planes), sizeof(short));
    read(fd_img, &(fh->bit_pix), sizeof(short));
    read(fd_img, &(fh->bi_compression), sizeof(unsigned int));
    read(fd_img, &(fh->bi_size_image), sizeof(unsigned int));
    read(fd_img, &(fh->bi_xpels_per_meter), sizeof(int));
    read(fd_img, &(fh->bi_ypels_per_meter), sizeof(int));
    read(fd_img, &(fh->bi_clrused), sizeof(unsigned int));
    read(fd_img, &(fh->bi_clr_important), sizeof(unsigned int));
}

void            write_header(t_header *fh)
{
    int fd_img;

    fd_img = open("./my_micky.bmp", O_RDWR | O_CREAT);
    write(fd_img, "B", sizeof(unsigned char));
    write(fd_img, "M", sizeof(unsigned char));
    write(fd_img, "3066138", sizeof(unsigned int));
    write(fd_img, "0", sizeof(short));
    write(fd_img, "0", sizeof(short));
    write(fd_img, "138", sizeof(unsigned int));
    write(fd_img, "124", sizeof(unsigned int));
    write(fd_img, "1000", sizeof(int));
    write(fd_img, "1022", sizeof(int));
    write(fd_img, "1", sizeof(short));
    write(fd_img, "24", sizeof(short));
    write(fd_img, "0", sizeof(unsigned int));
    write(fd_img, "3066000", sizeof(unsigned int));
    write(fd_img, "0", sizeof(int));
    write(fd_img, "0", sizeof(int));
    write(fd_img, "0", sizeof(unsigned int));
    write(fd_img, "0", sizeof(unsigned int));
}

unsigned char   *init_image(t_header *fh, int *fd)
{
    unsigned char   *img;

    reader(*fh);
    image = (unsigned char *)malloc(sizeof(char) * fh.bf_size);
    *fd = open(path_img, O_RDWR | O_CREAT);
    if (*fd < 0)
        exit(0);
    return (img);
}

void            write_image(int r, int g, int b)
{
    static int      i;
    static int      fd = -1;
    t_header        fh;
    unsigned char   *img;

    if (fd <= 0)
        img = init_image(&fh, &fd);
    else
    {
        img[*i] = r;
        img[*i + 1] = g;
        img[*i + 2] = b;
    }
    update_i(&i);
    if (*i >= fh.bf_size)
    {
        write(fd, image, fh.bf_size);
        exit(0);
    }
}

void            update_i(int *i)
{
    if (*i < 0)
        *i = fh.image_data_offset;
    *i += 3;
}

// int	main(void)
// {
// 	t_header		fh;
//     unsigned char	*image;
//     int             fd;

//     reader(&fh);
//     image = (unsigned char *)malloc(sizeof(char) * (fh.bf_size));
//     fd = open("./my_micky.bmp", O_RDWR | O_CREAT);
//     int i;

//     i = -1;
//     while (++i < fh.bf_size - fh.image_data_offset)
//     {
//     	image[i] = r;
//         inage[i] = g;
//         image[i] = b;
//     }

// 	return (0);
// }

/* pour imprimer les valeurs de l'image si la taille change*/
    //printf("fM1 = %c, fM2 = %c, bfS = %u, un1 = %hu, un2 = %hu, iDO = %u, bit_pix = %u\n", fh.file_marker1, fh.file_marker2, fh.bf_size, fh.unused1, fh.unused2, fh.image_data_offset, fh.bit_pix);
    //printf("w = %d, h = %d\n", fh.width, fh.height);
    // printf("%c, %c, %u, %hd, %hd, %u, %u, %d, %d, %hd, %hd, %u, %u, %d, %d, %u, %u\n",
    //         fh.file_marker1, fh.file_marker2, fh.bf_size , fh.unused1 , fh.unused2 , fh.image_data_offset , fh.bi_size,
    //         fh.width , fh.height , fh.planes , fh.bit_pix , fh.bi_compression , fh.bi_size_image , fh.bi_xpels_per_meter,
    //         fh.bi_ypels_per_meter, fh.bi_clrused, fh.bi_clr_important);
// printf("%d\n%d\n%d\n", i, fh.width*fh.height, i / 3);