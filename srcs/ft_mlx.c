#include "so_long.h"

w_mlx	*ft_mlx_init(w_mlx *mlx, int with, int height)
{
	mlx = malloc(sizeof(w_mlx));

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, with, height, "so_long");

	return (mlx);
}

#include "mlx.h"

void ft_mlx_print_img(w_mlx *mlx, char *path, int x, int y)
{
    int width, height;
    void *img;

    // Load the XPM image from the file at the given path
    img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
    if (img == NULL) {
        perror("Error loading XPM image");
        return;
    }

    // Put the image at position (x, y) in the window
    mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
}
