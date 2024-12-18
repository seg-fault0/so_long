#include "so_long.h"

w_mlx *ft_mlx_init()
{
	w_mlx *mlx;
// allocate for mlx
	mlx = malloc(sizeof(w_mlx));

//	make the window
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1275, 648, "so_long");

// 	render the map then the player
	mlx->map_img = mlx_print_image(mlx, "assets/map.xpm", 0, 0, NULL);
	mlx->player = ft_mov(mlx, 200, 300);

	return(mlx);
}
