#include "so_long.h"

w_mlx	*ft_mlx_init(w_mlx *mlx, int with, int height)
{
	int fd;
	
	fd = open("maps/map.ber", O_RDWR);
	mlx = malloc(sizeof(w_mlx));

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, with, height, "so_long");
	mlx->map  = ft_get_map(fd);
	mlx->x_spwn = ft_getcoordinates(mlx->map, 'P', 'x');
	mlx->y_spwn = ft_getcoordinates(mlx->map, 'P', 'y');

	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, DOWN_IMG, mlx->x_spwn, mlx->y_spwn);
	return (mlx);
}

void ft_mlx_print_img(w_mlx *mlx, char *path, int x, int y)
{
	int width, height;
	void *img;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	if (img == NULL)
 		return;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * IMG_SIZE, y * IMG_SIZE);
}
