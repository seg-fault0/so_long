#include "so_long.h"

void	ft_exit(w_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
}