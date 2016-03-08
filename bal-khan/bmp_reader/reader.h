

typedef struct	__attribute__((__packed__)) s_header
{
	unsigned char	fileMarker1;
	unsigned char	fileMarker2;
	unsigned int	bfSize;
	short			unused1;
	short			unused2;
	unsigned int	imageDataOffset;
}               t_header;

typedef struct	__attribute__((__packed__)) s_header_info
{
	unsigned int	biSize;
	int				width;
	int				height;
	short			planes;
	short			bitPix;
	unsigned int	biCompression;
	unsigned int	biSizeImage;
	int				biXPelsPerMeter;
	int				biYPelsPerMeter;
	unsigned int	biClrUsed;
	unsigned int	biClrImportant;
}				t_header_info;

typedef struct	__attribute__((__packed__)) s_image
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}				t_image;
