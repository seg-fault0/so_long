#include "so_long.h"

void *mlx_print_image(w_mlx *mlx, char *file_name, int x, int y)
{
	int 	size;
	void	*image;

//update the map generation
	free(mlx->map_img);
	mlx->map_img = mlx_xpm_file_to_image(mlx->mlx, "assets/map.xpm", &size, &size);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map_img, 0, 0);

//print the accual image
	image = mlx_xpm_file_to_image(mlx->mlx, file_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->win, image, x, y);

	return (image);
}