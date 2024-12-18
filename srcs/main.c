#include "so_long.h"

void ft_leaks()
{
	system("leaks exe");
}

int main()
{
	atexit(ft_leaks);
	w_mlx	*mlx;

	mlx = ft_mlx_init();

	mlx_hook(mlx->win,  2, 1L << 0, ft_input, mlx);
	mlx_loop(mlx->mlx);

	return (0);
}