#include "so_long.h"

int ft_close_window(w_mlx *mlx)
{	
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	ft_exit(mlx);
	return (0);
}

int main(int argc, char *argv[])
{
	w_mlx *mlx;

	mlx = ft_mlx_init();

	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_hook(mlx->win, 17, 0, ft_close_window, mlx);
	mlx_loop(mlx->mlx);
}