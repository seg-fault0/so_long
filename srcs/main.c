#include "so_long.h"

int main(int argc, char *argv[])
{
	w_mlx *mlx;
	int		height;
	int 	with;

	mlx = ft_mlx_init();
	height = ft_get_win_size(mlx->map, 'h');
	with = ft_get_win_size(mlx->map, 'w');

	mlx->win = mlx_new_window(mlx->mlx, with * IMG_SIZE, height * IMG_SIZE, "so_long");
	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, DOWN_IMG, mlx->cord.x_spwn, mlx->cord.y_spwn);

	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_loop(mlx->mlx);
}