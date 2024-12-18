#include "so_long.h"

w_mlx *ft_mlx_init()
{
	w_mlx *mlx;

	mlx = malloc(sizeof(w_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1080, 970, "so_long");
	mlx->player = ft_mov(mlx, 200, 300);

	return(mlx);
}
