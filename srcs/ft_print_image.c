#include "so_long.h"

void *mlx_print_image(w_mlx *mlx, char *file_name, int x, int y)
{
	int 	size;
	void	*image;
	
	image = mlx_xpm_file_to_image(mlx->mlx, file_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map_img, x, y);

	return (image);
}