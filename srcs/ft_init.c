#include "so_long.h"

w_mlx *ft_mlx_init()
{
	w_mlx *mlx;

	mlx = malloc(sizeof(w_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1275, 648, "so_long");
	mlx->player = ft_mov(mlx, 200, 300);
	mlx->map_img = mlx_print_image(mlx, "assets/map.xpm", 0, 0);
	return(mlx);
}
