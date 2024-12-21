#include "so_long.h"

w_mlx	*ft_mlx_init()
{
	int fd;
	w_mlx *mlx;

	fd = open("maps/map.ber", O_RDWR);
	mlx = malloc(sizeof(w_mlx));

	mlx->mlx = mlx_init();
	mlx->map  = ft_get_map(fd);
	mlx->cord.x_spwn = ft_getcoordinates(mlx->map, 'P', 'x');
	mlx->cord.y_spwn = ft_getcoordinates(mlx->map, 'P', 'y');
	mlx->cord.x_key = ft_getcoordinates(mlx->map, 'C', 'x');
	mlx->cord.y_key = ft_getcoordinates(mlx->map, 'C', 'y');
	mlx->cord.x_door = ft_getcoordinates(mlx->map, 'E','x');
	mlx->cord.y_door = ft_getcoordinates(mlx->map, 'E', 'y');
	mlx->collected = 0;


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
