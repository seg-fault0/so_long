#include "so_long.h"

int main(int argc, char *argv[])
{
	w_mlx *mlx;
	int fd = open("maps/map.ber", O_RDWR);

	mlx = ft_mlx_init(mlx, 1344, 832);
	mlx->map  = ft_get_map(fd);

	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, DOWN_IMG, 64 * 2, 64);

	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_loop(mlx->mlx);
}