#include "so_long.h"

w_mlx	*ft_mlx_init(w_mlx *mlx, int with, int height)
{
	mlx = malloc(sizeof(w_mlx));

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, with, height, "so_long");

	return (mlx);
}

void ft_mlx_print_img(w_mlx *mlx, char *path, int x, int y)
{
	int width, height;
	void *img;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	if (img == NULL)
 		return;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
}
