#include "so_long.h"

void ft_leaks()
{
	system("leaks exe");
}

int main()
{
	atexit(ft_leaks);
	w_mlx	*mlx;

	mlx = malloc(sizeof(w_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1080, 970, "so_long");
	mlx->player = ft_player(mlx, 200, 300);

	mlx_hook(mlx->win,  2, 1L << 0, ft_input, mlx);
	mlx_loop(mlx->mlx);

	return (0);
}