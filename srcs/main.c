#include "so_long.h"

int main(int argc, char *argv[])
{
	w_mlx *mlx;

	mlx = ft_mlx_init(mlx, 1344, 832);

	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_loop(mlx->mlx);
}