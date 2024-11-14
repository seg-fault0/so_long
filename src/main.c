#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 900, "Hello world!");
	

	int	height = 1200, with = 600;
	void *img = mlx_xpm_file_to_image(mlx, "assets/images/player.xpm", &height, &with);	
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_loop(mlx);

	return (0);
}

