#include "so_long.h"

int main(int argc, char *argv[])
{
	w_mlx *mlx;

	mlx = ft_mlx_init(mlx, 1344, 832);

	printf("x_spwn = %d | y_spwn = %d \n", mlx->x_spwn, mlx->y_spwn);
	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, DOWN_IMG, IMG_SIZE * 2, IMG_SIZE * 1);

	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_loop(mlx->mlx);
}